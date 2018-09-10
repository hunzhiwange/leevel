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
namespace Leevel\Bootstrap;

use Exception;
use Throwable;
use ErrorException;
use Leevel\Http\IRequest;
use Leevel\Router\IRouter;
use Leevel\Kernel\IKernel;
use Leevel\Http\IResponse;
use Leevel\Kernel\IProject;
use Leevel\Http\ApiResponse;
use Leevel\Http\JsonResponse;
use Leevel\Http\RedirectResponse;
use Leevel\Support\Debug\Console;

/**
 * 内核执行
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2016.11.18
 * 
 * @version 1.0
 */
abstract class Kernel implements IKernel
{
    /**
     * 项目
     *
     * @var \Leevel\Kernel\IProject
     */
    protected project;
    
    /**
     * 路由
     *
     * @var \Leevel\Router\IRouter
     */
    protected router;
    
    /**
     * 项目初始化执行
     *
     * @var array
     */
    protected bootstraps = [
        "Leevel\\Bootstrap\\Bootstrap\\LoadOption",
        "Leevel\\Bootstrap\\Bootstrap\\LoadI18n",
        "Leevel\\Bootstrap\\Bootstrap\\RegisterRuntime",
        "Leevel\\Bootstrap\\Bootstrap\\TraverseProvider"
    ];
    
    /**
     * 构造函数
     *
     * @param \Leevel\Kernel\IProject $project
     * @param \Leevel\Router\IRouter $router
     */
    public function __construct(<IProject> project, <IRouter> router)
    {
        let this->project = project;
        let this->router = router;
    }
    
    /**
     * 响应 HTTP 请求
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    public function handle(<IRequest> request) -> <IResponse>
    {
        var response, e, fatalException;
    
        try {
            this->registerBaseService(request);

            this->bootstrap();

            let response = this->getResponseWithRequest(request);

            let response = this->prepareTrace(response);

            this->middlewareTerminate(request, response);
        } catch Exception, e {
            this->reportException(e);

            let response = this->renderException(request, e);
        } catch Throwable, e {
            let fatalException = new ErrorException(
                e->getMessage(),
                e->getCode(),
                E_ERROR,
                e->getFile(),
                e->getLine(),
                e->getPrevious()
            );

            this->reportException(fatalException);

            let response = this->renderException(request, fatalException);
        }

        return response;
    }
    
    /**
     * 返回运行处理器
     * 
     * @return \Leevel\Bootstrap\Runtime\IRuntime
     */
    protected function getRuntime() -> <IRuntime>
    {
        return this->project->make("Leevel\\Kernel\\Runtime\\IRuntime");
    }
    
    /**
     * 执行结束
     *
     * @param \Leevel\Http\IRequest $request
     * @param \Leevel\Http\IResponse $response
     */
    public function terminate(<IRequest> request, <IResponse> response) -> void
    {
    }
    
    /**
     * 返回项目
     *
     * @return \Leevel\Kernel\IProject
     */
    public function getProject() -> <IProject>
    {
        return this->project;
    }
    
    /**
     * 注册基础服务
     * 
     * @param \Leevel\Http\IRequest $request
     */
    protected function registerBaseService(<IRequest> request)
    {
        this->project->instance("request", request);
    }
    
    /**
     * 根据请求返回响应
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    protected function getResponseWithRequest(<IRequest> request) -> <IResponse>
    {
        return this->dispatchRouter(request);
    }
    
    /**
     * 路由调度
     *
     * @param \Leevel\Http\IRequest $request
     * @return \Leevel\Http\IResponse
     */
    protected function dispatchRouter(<IRequest> request) -> <IResponse>
    {
        return this->router->dispatch(request);
    }
    
    /**
     * 初始化
     */
    protected function bootstrap()
    {
        this->project->bootstrap(this->bootstraps);
    }
    
    /**
     * 上报错误
     *
     * @param \Exception $e
     */
    protected function reportException(<Exception> e)
    {
        this->getRuntime()->report(e);
    }
    
    /**
     * 渲染异常
     *
     * @param \Leevel\Http\IRequest $request
     * @param \Exception $e
     * @return \Leevel\Http\IResponse
     */
    protected function renderException(<IRequest> request, <Exception> e) -> <IResponse>
    {
        return this->getRuntime()->render(request, e);
    }
    
    /**
     * 调试信息
     *
     * @param \Leevel\Http\IResponse $response
     * @return \Leevel\Http\IResponse
     */
    protected function prepareTrace(<IResponse> response) -> <IResponse>
    {
        var logs, data;
    
        if ! (this->project->debug()) {
            return response;
        }

        let logs = this->project->make("Leevel\\Log\\ILog")->all();
        let data = response->getData();

        if (response instanceof ApiResponse || 
            response instanceof JsonResponse || 
            response->isJson()) && is_array(data) {
            let data["_TRACE"] = Console::jsonTrace(logs);
            response->setData(data);
        } elseif ! (response instanceof RedirectResponse) {
            let data = Console::trace(logs);
            response->appendContent(data);
        }

        return response;
    }

    /**
     * 中间件结束响应.
     *
     * @param \Leevel\Http\IRequest  $request
     * @param \Leevel\Http\IResponse $response
     */
    protected function middlewareTerminate(<IRequest> request, <IResponse> response)
    {
        this->router->throughMiddleware(request, [response]);
    }
}
