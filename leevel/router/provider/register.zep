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
namespace Leevel\Router\Provider;

use Closure;
use Leevel\Cookie\Cookie;
use Leevel\Router\Url;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Http\Response;
use Leevel\Mvc\View;
use Leevel\Router\Router;
use Leevel\Router\Redirect;
use Leevel\Router\ResponseFactory;

/**
 * router 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.28
 * @version 1.0
 */
class Register extends Provider
{

    /**
     * 创建一个服务容器提供者实例
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        parent::__construct(container);
    }

    /**
     * 注册服务
     *
     * @return void
     */
    public function register()
    {
        this->router();
        this->url();
        this->redirect();
        this->response();
        this->cookie();
        this->view();
        this->cookieResolver();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        return [
            "router" : [
                "Leevel\\Router\\Router",
                "Leevel\\Router\\IRouter"
            ],
            "url" : [
                "Leevel\\Router\\Url"
            ],
            "redirect" : [
                "Leevel\\Router\\Redirect"
            ],
            "response" : [
                "Leevel\\Router\\IResponseFactory",
                "Leevel\\Router\\ResponseFactory"
            ],
            "cookie" : [
                "Leevel\\Cookie\\Cookie",
                "Leevel\\Cookie\\ICookie"
            ],
            "view" : [
                "Leevel\\Mvc\\View",
                "Leevel\\Mvc\\IView"
            ]
        ];
    }

    /**
     * 注册 router 服务
     *
     * @return void
     */
    protected function router()
    {
        this->container->singleton("router", Closure::fromCallable([this, "routerClosure"]));
    }

    /**
     * 创建 router 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Router\Router
     */
    protected function routerClosure(<IContainer> container)
    {
        return new Router(container);
    }

    /**
     * 注册 url 服务
     *
     * @return void
     */
    protected function url()
    {
        this->container->singleton("url", Closure::fromCallable([this, "urlClosure"]));
    }

    /**
     * 创建 url 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Router\Url
     */
    protected function urlClosure(<IContainer> container)
    {
        var option, request, options = [], item;
        
        let option = container->make("option");
        let request = container->make("request");

        for item in [
            "with_suffix",
            "html_suffix",
            "domain_top",
            "subdomain_on"
        ] {
            let options[item] = option->get(item);
        }

        return new Url(request, options);
    }

    /**
     * 注册 redirect 服务
     *
     * @return void
     */
    protected function redirect()
    {
        this->container->bind("redirect", this->container->share(
            Closure::fromCallable([this, "redirectClosure"])
        ));
    }

    /**
     * 创建 redirect 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Router\Redirect
     */
    protected function redirectClosure(<IContainer> container)
    {
        var redirect, session;

        let redirect = new Redirect(container->make("url"));
        let session = container->make("session");

        if (session !== false) {
            redirect->setSession(session);
        }

        return redirect;
    }

    /**
     * 注册 response 服务
     *
     * @return void
     */
    protected function response()
    {
        this->container->singleton("response", Closure::fromCallable([this, "responseClosure"]));
    }

    /**
     * 创建 response 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Router\ResponseFactory
     */
    protected function responseClosure(<IContainer> container)
    {
        var option, response;

        let option = container->make("option");
        let response = new ResponseFactory(container->make("view"), container->make("redirect"));

        return response->

        setViewSuccessTemplate(option->get("view\\action_success"))->

        setViewFailTemplate(option->get("view\\action_fail"));
    }

    /**
     * 注册 cookie 服务
     */
    public function cookie()
    {
        this->container->singleton("cookie", Closure::fromCallable([this, "cookieClosure"]));
    }

    /**
     * 创建 cookie 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Cookie\Cookie
     */
    protected function cookieClosure(<IContainer> container)
    {
        return new Cookie(container->make("option")->get("cookie\\"));
    }

    /**
     * 注册 view 服务
     */
    public function view()
    {
        this->container->singleton("view", Closure::fromCallable([this, "viewClosure"]));
    }

    /**
     * 创建 view 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Mvc\View
     */
    protected function viewClosure(<IContainer> container)
    {
        return new View(container->make("view.view"));
    }

    /**
     * 设置 COOKIE Resolver
     */
    protected function cookieResolver()
    {
        Response::setCookieResolver(Closure::fromCallable([this, "makeCookieResolverClosure"]));
    }

   /**
     * 生成 COOKIE
     *
     * @return \Leevel\Cookie\ICookie
     */
    protected function makeCookieResolverClosure()
    {
        return this->container->make("cookie");
    }
}
