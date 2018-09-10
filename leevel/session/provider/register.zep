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
namespace Leevel\Session\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Session\Manager;

/**
 * session 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.26
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
        this->sessions();
        this->session();
        this->middleware();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        return [
            "sessions" : [
                "Leevel\\Session\\Manager"
            ], 
            "session" : [
                "Leevel\\Session\\Session", 
                "Leevel\\Session\\ISession"
            ], 
            "Leevel\\Session\\Middleware\\Session"
        ];
    }
    
    /**
     * 注册 sessions 服务
     *
     * @return void
     */
    protected function sessions()
    {
        this->container->singleton("sessions", Closure::fromCallable([this, "sessionsClosure"]));
    }
    
    /**
     * 创建 sessions 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Session\Manager
     */
    protected function sessionsClosure(<IContainer> container)
    {
        return new Manager(container);
    }

    /**
     * 注册 session 服务
     *
     * @return void
     */
    protected function session()
    {
        this->container->singleton("session", Closure::fromCallable([this, "sessionClosure"]));
    }

    /**
     * 创建 session 服务闭包
     *
     * @param \Leevel\Di\IContainer $container
     * @return object
     */
    protected function sessionClosure(<IContainer> container)
    {
        return container->make("sessions")->connect();
    }
    
    /**
     * 注册 middleware 服务
     *
     * @return void
     */
    protected function middleware()
    {
        this->container->singleton("Leevel\\Session\\Middleware\\Session");
    }
}
