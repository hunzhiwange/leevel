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
     * 全局路由绑定中间件
     *
     * @var array
     */
    protected globalMiddlewares = [];
    
    /**
     * 当前的中间件
     *
     * @var array
     */
    protected currentMiddlewares;
    
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
        "_c" : null, 
        "_a" : null, 
        "_prefix" : null, 
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
    protected basepaths = [];
    
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
        var method, pipeline;
    
        if is_null(this->currentMiddlewares) {
            let this->currentMiddlewares = this->parseMiddleware();
        }

        let method = empty passedExtend ? "handle" : "terminate";

        if ! this->currentMiddlewares[method] {
            return;
        }

        if this->currentMiddlewares[method] {
            let pipeline = new Pipeline(this->container);

            call_user_func([pipeline, "send"], passed);

            if ! empty passedExtend {
                call_user_func([pipeline, "send"], passedExtend);
            }

            call_user_func([pipeline, "through"], this->currentMiddlewares[method]);

            pipeline->then();
        }
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
     * @param string $controllerDir
     * @return void
     */
    public function getControllerDir()
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
     * @param array $basepaths
     * @return void
     */
    public function setBasepaths(array basepaths)
    {
        let this->basepaths = basepaths;
    }
    
    /**
     * 添加基础路径
     *
     * @param array $basepaths
     * @return void
     */
    public function addBasepaths(array basepaths)
    {
        let this->basepaths = array_unique(array_merge(this->basepaths, basepaths));
    }
    
    /**
     * 取得基础路径
     *
     * @return array
     */
    public function getBasepaths() -> array
    {
        return this->basepaths;
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
     * 添加路由分组
     *
     * @param array $groups
     * @return void
     */
    public function addGroups(array groups)
    {
        let this->groups = array_unique(array_merge(this->groups, groups));
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
     * 设置全局中间件
     *
     * @param array $middlewares
     * @return void
     */
    public function setGlobalMiddlewares(array middlewares)
    {
        let this->globalMiddlewares = middlewares;
    }
    
    /**
     * 取得全局中间件
     *
     * @return array
     */
    public function getGlobalMiddlewares() -> array
    {
        return this->globalMiddlewares;
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
     * 匹配路径.
     *
     * @param string $path
     * @param bool   $ignoreMiddleware
     *
     * @return array
     */
    public function matchePath(string path, bool ignoreMiddleware = false) -> array
    {
        var result, query, tmpListPathQuery, item, basepath, paths, params, tmpListPathsParams, tmpPath, option;
        array baseOptions;
    
        let result = [];

        if strpos(path, "?") !== false {
            let tmpListPathQuery = explode("?", path);
            let tmpPath = tmpListPathQuery[0];
            let query = tmpListPathQuery[1];

            if query {
                for item in explode("&", query) {
                    let item = explode("=", item);
                    let result[self::PARAMS][item[0]] = item[1];
                }
            }
        } else {
            let tmpPath = path;
        }

        // 匹配基础路径
        let basepath = "";
        let baseOptions = [];

        for item, option in this->getBasepaths() {
            if strpos(tmpPath, item) === 0 {
                let tmpPath = substr(path, strlen(item) + 1);
                let basepath = item;
                let baseOptions = option;
                break;
            }
        }

        let tmpPath = trim(tmpPath, "/");
        let paths = tmpPath ? explode("/", tmpPath) : [];

        // 应用
        if paths && this->findApp(paths[0]) {
            let result[self::APP] = substr(array_shift(paths), 1);
        }

        if ! paths {
            let result[IRouter::CONTROLLER] = IRouter::DEFAULT_HOME_CONTROLLER;

            return result;
        }

        let tmpListPathsParams = this->normalizePathsAndParams(paths);
        let paths = tmpListPathsParams[0];
        let params = tmpListPathsParams[1];

        if count(paths) == 1 {
            let result[self::CONTROLLER] = array_pop(paths);
        } else {
            if paths {
                let result[self::ACTION] = array_pop(paths);
            }

            if paths {
                let result[self::CONTROLLER] = array_pop(paths);
            }

            if paths {
                let result[self::PREFIX] = implode("\\", this->normalizePrefix(paths));
            }
        }

        let result[self::PARAMS] = array_merge(isset result[self::PARAMS] ? result[self::PARAMS] : [], params);
        let result[self::PARAMS][self::BASEPATH] = basepath ? basepath : null;

        if ! ignoreMiddleware {
            let result[self::MIDDLEWARES] = isset baseOptions["middlewares"] ? baseOptions["middlewares"] : [];
        }

        return result;
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
     * 是否找到 app
     * 
     * @param string $app
     * @return boolean
     */
    protected function findApp(string app) -> boolean
    {
        return strpos(app, ":") === 0;
    }
    
    /**
     * 解析路径和参数
     * 
     * @param array $data
     * @return array
     */
    protected function normalizePathsAndParams(array data) -> array
    {
        var paths, params, k, item;
    
        let paths = [];
        let params = [];

        let k = 0;
        for item in data {
            if is_numeric(item) {
                let params["_param" . k] = item;
                let k++;
            } else {
                let paths[] = item;
            }
        }

        return [paths, params];
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
            let bind = this->urlRouterBind(dataPathInfo);
        }

        return bind;
    }
    
    /**
     * URL 路由绑定
     *
     * @param array $dataPathInfo 
     * @return mixed
     */
    protected function urlRouterBind(array dataPathInfo)
    {
        var data;
    
        let data = this->normalizeMatchedData("Url");

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

        return this->parseDefaultBind();
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
            let result = result . "\\" . this->matchedPrefix();
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
        var type, matchedType;
    
        this->pathinfoRestful();

        for type in ["App", "Controller", "Action"] {
            let matchedType = "matched" . type;
            let type = "set" . type;

            this->request->{type}(this->{matchedType}());
        }

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
     * 分析默认控制器
     *
     * @return false|callable
     */
    protected function parseDefaultBind()
    {
        var app, controller, action, controllerClass, method;
    
        let app = this->matchedApp();
        let controller = this->matchedController();
        let action = this->matchedAction();

        // 尝试直接读取方法控制器类
        let controllerClass = app . "\\" . this->parseControllerDir() . "\\" . controller . "\\" . ucfirst(action);

        if class_exists(controllerClass) {
            let controller = this->container->make(controllerClass);
            let method = method_exists(controller, "handle") ? "handle" : "run";
        } else {
            let controllerClass = app . "\\" . this->parseControllerDir() . "\\" . controller;
            if ! (class_exists(controllerClass)) {
                return false;
            }

            let controller = this->container->make(controllerClass);
            let method = action;
        }
        
        if is_object(controller) && controller instanceof IController {
            controller->setView(this->container->make("Leevel\\Mvc\\IView"));
        }

        if ! (method_exists(controller, method)) {
            return false;
        }

        return [
            controller,
            method
        ];
    }
    
    /**
     * 获取绑定的中间件
     * 暂时不做重复过滤，允许中间件多次执行
     *
     * @return array
     */
    protected function parseMiddleware() -> array
    {
        var matchedMiddlewares;

        let matchedMiddlewares = this->matchedMiddlewares();

        return [
            "handle" : array_merge(
                isset this->globalMiddlewares["handle"] ? this->globalMiddlewares["handle"] : [],
                isset matchedMiddlewares["handle"] ? matchedMiddlewares["handle"] : []
            ), 
            "terminate" : array_merge(
                isset this->globalMiddlewares["terminate"] ? this->globalMiddlewares["terminate"] : [],
                isset matchedMiddlewares["terminate"] ? matchedMiddlewares["terminate"] : []
            )
        ];
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
        return ucfirst(this->matchedData[self::CONTROLLER]);
    }
    
    /**
     * 取回方法名
     *
     * @return string
     */
    protected function matchedAction() -> string
    {
        var action;

        let action = this->matchedData[self::ACTION];

        if strpos(action, "-") !== false {
            let action = str_replace("-", "_", action);
        }

        if strpos(action, "_") !== false {
            let action = "_" . str_replace("_", " ", action);
            let action = ltrim(str_replace(" ", "", ucwords(action)), "_");
        }

        return action;
    }
    
    /**
     * 取回控制器前缀
     *
     * @return string|null
     */
    protected function matchedPrefix()
    {
        return this->matchedData[self::PREFIX];
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
        return ! is_null(this->matchedData[self::MIDDLEWARES]) ? this->matchedData[self::MIDDLEWARES] : [
            "handle" : [],
            "terminate" : []
        ];
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
