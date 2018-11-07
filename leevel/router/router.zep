/*
 * This file is part of the ************************ package.
 * _____________                           _______________
 *  ______/     \__  _____  ____  ______  / /_  _________
 *   ____/ __   / / / / _ \/ __`\/ / __ \/ __ \/ __ \___
 *    __/ / /  / /_/ /  __/ /  \  / /_/ / / / / /_/ /__
 *      \_\ \_/\____/\___/_/   / / .___/_/ /_/ .___/
 *         \_\                /_/_/         /_/
 *
 * The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
 * (c) 2010-2018 http://queryphp.com All rights reserved.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Leevel\Router;

use Closure;
use Exception;
use RuntimeException;
use ReflectionMethod;
use ReflectionException;
use BadMethodCallException;
use InvalidArgumentException;
use Leevel\Http\IRequest;
use Leevel\Di\IContainer;
use Leevel\Http\Response;
use Leevel\Http\IResponse;
use Leevel\Support\IMacro;
use Leevel\Mvc\IController;
use Leevel\Mvc\IView;
use Leevel\Pipeline\Pipeline;

/**
 * 路由解析
 * 2018.04.10 开始进行一次重构系统路由架构
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.01.10
 * @version 1.0
 */
class Router implements IRouter, IMacro
{
    /**
     * IOC Container
     *
     * @var \Leevel\Di\IContainer
     */
    protected container;
    
    /**
     * http 请求
     *
     * @var \Leevel\Http\IRequest
     */
    protected request;
    
    /**
     * 路由匹配数据
     * 
     * @var array
     */
    protected matchedData;
    
    /**
     * 路由匹配初始化数据
     * 
     * @var array
     */
    protected static matcheDataInit = [
        "_app" : self::DEFAULT_APP, 
        "_prefix" : null, 
        "_c" : null, 
        "_a" : null, 
        "_bind" : null, 
        "_params" : null, 
        "_middlewares" : null, 
        "_vars" : null
    ];

    /**
     * 是否已经进行匹配.
     *
     * @var bool
     */
    protected isMatched;

    /**
     * 基础路径 
     *
     * @var array
     */
    protected basePaths = [];

    /**
     * 分组路径.
     *
     * @var array
     */
    protected groupPaths = [];
    
    /**
     * 分组
     *
     * @var array
     */
    protected groups = [];
    
    /**
     * 路由 
     *
     * @var array
     */
    protected routers = [];
    
    /**
     * 中间件分组 
     *
     * @var array
     */
    protected middlewareGroups = [];
    
    /**
     * 中间件别名 
     *
     * @var array
     */
    protected middlewareAlias = [];
    
    /**
     * 控制器相对目录
     * 
     * @var string
     */
    protected controllerDir = "App\\Controller";

    /**
     * 注册的动态扩展
     *
     * @var array
     */
    protected static macro = [];
    
    /**
     * 构造函数
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        let this->container = container;
    }
    
    /**
     * 分发请求到路由
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    public function dispatch(<IRequest> request) -> <IResponse>
    {
        let this->request = request;

        return this->dispatchToRoute(request);
    }
    
    /**
     * 初始化请求
     *
     * @return void
     */
    public function initRequest()
    {
        let this->matchedData = null;
    }
    
    /**
     * 设置匹配路由
     * 绕过路由解析，可以用于高性能 RPC 快速匹配资源
     *
     * @param array $matchedData
     * @return void
     */
    public function setMatchedData(array matchedData)
    {
        let this->matchedData = array_merge(self::matcheDataInit, matchedData);

        let this->isMatched = true;
    }
    
    /**
     * 穿越中间件
     *
     * @param \Leevel\Http\IRequest $passed
     * @param array $passedExtend
     * @return void
     */
    public function throughMiddleware(<IRequest> passed, array passedExtend = [])
    {
        var method, pipeline, middlewares;
    
        let method = empty passedExtend ? "handle" : "terminate";
        let middlewares = this->matchedMiddlewares();

        if !isset middlewares[method] || empty middlewares[method] {
            return;
        }

        let pipeline = new Pipeline(this->container);

        call_user_func([pipeline, "send"], [passed]);

        if ! empty passedExtend {
            call_user_func([pipeline, "send"], passedExtend);
        }

        call_user_func([pipeline, "through"], middlewares[method]);

        pipeline->then();
    }
    
    /**
     * 设置控制器相对目录
     *
     * @param string $controllerDir
     * @return void
     */
    public function setControllerDir(string controllerDir)
    {
        let controllerDir = str_replace("/", "\\", controllerDir);

        let this->controllerDir = controllerDir;
    }
    
    /**
     * 返回控制器相对目录
     *
     * @return void
     */
    public function getControllerDir() -> string
    {
        return this->controllerDir;
    }
    
    /**
     * 设置路由
     *
     * @param array $routers
     * @return void
     */
    public function setRouters(array routers)
    {
        let this->routers = routers;
    }
    
    /**
     * 取得当前路由
     *
     * @return array
     */
    public function getRouters() -> array
    {
        return this->routers;
    }
    
    /**
     * 设置基础路径
     *
     * @param array $basePaths
     * @return void
     */
    public function setBasePaths(array basePaths)
    {
        let this->basePaths = basePaths;
    }
    
    /**
     * 取得基础路径
     *
     * @return array
     */
    public function getBasePaths() -> array
    {
        return this->basePaths;
    }

    /**
     * 设置分组路径.
     *
     * @param array $groupPaths
     */
    public function setGroupPaths(array groupPaths)
    {
        let this->groupPaths = groupPaths;
    }

    /**
     * 取得分组路径.
     *
     * @return array
     */
    public function getGroupPaths() -> array
    {
        return this->groupPaths;
    }
    
    /**
     * 设置路由分组
     *
     * @param array $groups
     * @return void
     */
    public function setGroups(array groups)
    {
        let this->groups = groups;
    }

    /**
     * 取得路由分组
     *
     * @return array
     */
    public function getGroups() -> array
    {
        return this->groups;
    }
    
    /**
     * 设置中间件分组
     *
     * @param array $middlewareGroups
     * @return void
     */
    public function setMiddlewareGroups(array middlewareGroups)
    {
        let this->middlewareGroups = middlewareGroups;
    }
    
    /**
     * 取得中间件分组
     *
     * @return array
     */
    public function getMiddlewareGroups() -> array
    {
        return this->middlewareGroups;
    }
    
    /**
     * 设置中间件别名
     *
     * @param array $middlewareAlias
     * @return void
     */
    public function setMiddlewareAlias(array middlewareAlias)
    {
        let this->middlewareAlias = middlewareAlias;
    }
    
    /**
     * 取得中间件别名
     *
     * @return array
     */
    public function getMiddlewareAlias() -> array
    {
        return this->middlewareAlias;
    }

    /**
     * 注册一个扩展
     *
     * @param string $name
     * @param callable $macro
     * @return void
     */
    public static function macro(string name, var macro)
    {
        let self::macro[name] = macro;
    }
    
    /**
     * 判断一个扩展是否注册
     *
     * @param string $name
     * @return bool
     */
    public static function hasMacro(string name) -> boolean
    {
        return isset self::macro[name];
    }

    /**
     * __callStatic 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function callStaticMacro(string method, array args)
    {
        if self::hasMacro(method) {
            return call_user_func_array(self::macro[method], args);
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }

    /**
     * __call 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
     * 
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function callMacro(string method, array args)
    {
        if self::hasMacro(method) {
            if self::macro[method] instanceof Closure {
                return call_user_func_array(self::macro[method]->bindTo(this), args);
            } else {
                return call_user_func_array(self::macro[method], args);
            }
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }

    /**
     * 格式化前缀
     * 
     * @param array $paths
     * @return array
     */
    protected function normalizePrefix(array paths) -> array
    {
        array result = [];
        var item;

        for item in paths {
            if strpos(item, "_") !== false {
                let item = str_replace("_", " ", item);
                let item = str_replace(" ", "", ucwords(item));
            } else {
                let item = ucfirst(item);
            }

            let result[] = item;
        }

        return result;
    }

    /**
     * 路由匹配
     * 高效匹配，如果默认 PathInfo 路由能够匹配上则忽略 OpenApi 路由匹配.
     *
     * @return mixed|void
     */
    protected function matchRouter()
    {
        var dataPathInfo, bind;
    
        if true === this->isMatched && ! (is_null(this->matchedData)) {
            return this->findRouterBind();
        }

        this->initRequest();

        let dataPathInfo = this->normalizeMatchedData("PathInfo");
        this->resolveMatchedData(dataPathInfo);

        let bind = this->normalizeRouterBind();

        if bind === false {
            let bind = this->annotationRouterBind(dataPathInfo);
        }

        return bind;
    }
    
    /**
     * 注解路由绑定.
     *
     * @param array $dataPathInfo 
     * @return mixed
     */
    protected function annotationRouterBind(array dataPathInfo)
    {
        var data;
    
        let data = this->normalizeMatchedData("Annotation");

        if ! (data) {
            let data = dataPathInfo;
        } else {
            this->initRequest();
        }

        this->resolveMatchedData(data);

        return this->findRouterBind();
    }
    
    /**
     * 完成路由匹配数据
     *
     * @param array $data 
     * @return void
     */
    protected function resolveMatchedData(array data)
    {
        let this->matchedData = array_merge(self::matcheDataInit, data);
    }
    
    /**
     * 解析路由匹配数据
     *
     * @param string $matche
     * @return array
     */
    protected function normalizeMatchedData(string matche) -> array
    {
        let matche = "Leevel\\Router\\Match\\" . matche;

        return (new {matche}())->matche(this, this->request);
    }
    
    /**
     * 尝试获取路由绑定
     *
     * @return callable|void
     */
    protected function findRouterBind()
    {
        var bind;
    
        let bind = this->normalizeRouterBind();

        if bind === false {
            this->routerNotFound();
        }

        return bind;
    }
    
    /**
     * 解析路由绑定
     *
     * @return mixed
     */
    protected function normalizeRouterBind()
    {
        this->completeRequest();

        return this->parseMatchedBind();
    }
    
    /**
     * 发送路由并返回响应
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    protected function dispatchToRoute(<IRequest> request) -> <IResponse>
    {
        return this->runRoute(request, this->matchRouter());
    }
    
    /**
     * 运行路由
     * 
     * @param \Leevel\Http\IRequest $request
     * @param callable $bind
     * @return \Leevel\Http\IResponse
     */
    protected function runRoute(<IRequest> request, var bind) -> <IResponse>
    {
        var response, result;
    
        this->throughMiddleware(this->request);

        let response = this->container->call(bind, this->matchedVars());

        if ! (is_object(response) && response instanceof IResponse) {
            let result = new Response(response);
        } else {
            let result = response;
        }

        return result;
    }
    
    /**
     * 路由未找到异常.
     *
     * @return void
     */
    protected function routerNotFound()
    {
        var message;
    
        let message = sprintf("The router %s was not found.", this->makeRouterNode());

        throw new RouterNotFoundException(message);
    }
    
    /**
     * 生成路由节点资源.
     *
     * @return string
     */
    protected function makeRouterNode() -> string
    {
        var matchedBind;

        let matchedBind = this->matchedBind();

        if matchedBind {
            return matchedBind;
        }

        return this->matchedApp() . "\\" .
            this->parseControllerDir() . "\\" .
            this->matchedController() . "::" .
            this->matchedAction() . "()";
    }
    
    /**
     * 取得控制器命名空间目录
     *
     * @return string
     */
    protected function parseControllerDir() -> string
    {
        var result;
    
        let result = this->getControllerDir();

        if this->matchedPrefix() {
            let result .= "\\" . this->matchedPrefix();
        }

        return result;
    }
    
    /**
     * 完成请求
     *
     * @return void
     */
    protected function completeRequest()
    {
        this->pathinfoRestful();

        this->container->instance("app_name", this->matchedApp());

        this->request->params->replace(this->matchedParams());
    }
    
    /**
     * 智能 restful 解析
     * 路由匹配如果没有匹配上方法则系统会进入 restful 解析.
     */
    protected function pathinfoRestful()
    {
        if ! isset this->matchedData[self::ACTION] ||
            ! empty this->matchedData[self::ACTION] {
            return;
        }

        switch (this->request->getMethod()) {
            case "POST":
                let this->matchedData[self::ACTION] = self::RESTFUL_STORE;
                break;

            case "PUT":
                let this->matchedData[self::ACTION] = self::RESTFUL_UPDATE;
                break;

            case "DELETE":
                let this->matchedData[self::ACTION] = self::RESTFUL_DESTROY;
                break;

            case "GET":
            default:
                let this->matchedData[self::ACTION] = self::RESTFUL_SHOW;
                break;
        }
    }
    
    /**
     * 分析匹配绑定路由.
     *
     * @return false|callable
     */
    protected function parseMatchedBind()
    {
        var matchedApp, matchedController, matchedAction, controllerClass, method,
            matchedBind, tmpBind, bindClass, controller;

        let matchedBind = this->matchedBind();

        if matchedBind {
            if false !== strpos(matchedBind, "@") {
                let tmpBind = explode("@", matchedBind);
                let bindClass = tmpBind[0];
                let method = tmpBind[1];

                if !class_exists(bindClass) {
                    return false;
                }
                
                let controller = this->container->make(bindClass);
            } else {
                if !class_exists(matchedBind) {
                    return false;
                }

                let controller = this->container->make(matchedBind);
                let method = "handle";
            }
        } else {
            let matchedApp = this->matchedApp();
            let matchedController = this->matchedController();
            let matchedAction = this->matchedAction();

            // 尝试直接读取方法控制器类
            let controllerClass = matchedApp . "\\" . this->parseControllerDir() . "\\" .
                matchedController . "\\" . ucfirst(matchedAction);

            if class_exists(controllerClass) {
                let controller = this->container->make(controllerClass);
                let method = "handle";
            } else {
                let controllerClass = matchedApp . "\\" . this->parseControllerDir() . "\\" . matchedController;

                if ! (class_exists(controllerClass)) {
                    return false;
                }

                let controller = this->container->make(controllerClass);
                let method = matchedAction;
            }
        }
            
        if is_object(controller) && controller instanceof IController {
            controller->setView(this->container->make("Leevel\\Mvc\\IView"));
        }

        if ! (method_exists(controller, method)) {
            return false;
        }

        return [controller, method];
    }

    /**
     * 取回控制器前缀
     *
     * @return null|string
     */
    protected function matchedPrefix()
    {
        var prefix, v;
        array tmp = [];

        let prefix = this->matchedData[self::PREFIX];

        if !prefix || is_scalar(prefix) {
            return prefix;
        }

        for v in prefix {
            let tmp[] = this->convertMatched(ucfirst(v));
        }

        let this->matchedData[self::PREFIX] = implode("\\", tmp);

        return this->matchedData[self::PREFIX];
    }
    
    /**
     * 取回应用名
     *
     * @return string
     */
    protected function matchedApp() -> string
    {
        return ucfirst(this->matchedData[self::APP]);
    }
    
    /**
     * 取回控制器名
     *
     * @return string
     */
    protected function matchedController() -> string
    {
        return this->convertMatched(ucfirst(this->matchedData[self::CONTROLLER]));
    }
    
    /**
     * 取回方法名
     *
     * @return string
     */
    protected function matchedAction() -> string
    {
        return this->convertMatched(this->matchedData[self::ACTION]);
    }

    /**
     * 转换匹配资源.
     *
     * @param string $matched
     *
     * @return string
     */
    protected function convertMatched(string matched)
    {
        if false !== strpos(matched, "-") {
            let matched = str_replace("-", "_", matched);
        }

        if false !== strpos(matched, "_") {
            let matched = "_".str_replace("_", " ", matched);
            let matched = ltrim(str_replace(" ", "", ucwords(matched)), "_");
        }

        return matched;
    }

    /**
     * 取回绑定资源.
     *
     * @return null|string
     */
    protected function matchedBind()
    {
        return this->matchedData[self::BIND];
    }
    
    /**
     * 取回匹配参数
     *
     * @return array
     */
    protected function matchedParams() -> array
    {
        return ! is_null(this->matchedData[self::PARAMS]) ? this->matchedData[self::PARAMS] : [];
    }
    
    /**
     * 取回匹配中间件
     *
     * @return array
     */
    protected function matchedMiddlewares() -> array
    {
        return ! is_null(this->matchedData[self::MIDDLEWARES]) ?
            this->matchedData[self::MIDDLEWARES] : 
            ["handle" : [], "terminate" : []];
    }
    
    /**
     * 取回匹配变量
     *
     * @return array
     */
    protected function matchedVars() -> array
    {
        return ! is_null(this->matchedData[self::VARS]) ? this->matchedData[self::VARS] : [];
    }
}
