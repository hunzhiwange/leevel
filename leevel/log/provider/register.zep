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
namespace Leevel\Log\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Log\Manager;
use Leevel\Di\IContainer;

/**
 * log 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.05.12
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
        this->logs();
        this->log();
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
            "logs" : [
                "Leevel\\Log\\Manager"
            ], 
            "log" : [
                "Leevel\\Log\\Log", 
                "Leevel\\Log\\ILog"
            ], 
            "Leevel\\Log\\Middleware\\Log"
        ];
    }
    
    /**
     * 注册 logs 服务
     *
     * @return void
     */
    protected function logs()
    {
        this->container->singleton("logs", Closure::fromCallable([this, "logsClosure"]));
    }

    /**
     * 创建 logs 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Log\Manager
     */
    protected function logsClosure(<IContainer> container)
    {
        return new Manager(container);
    }
    
    /**
     * 注册 log 服务
     *
     * @return void
     */
    protected function log()
    {
        this->container->singleton("log", Closure::fromCallable([this, "logClosure"]));
    }

    /**
     * 创建 log 服务闭包
     *
     * @param \Leevel\Di\IContainer $container
     * @return object
     */
    protected function logClosure(<IContainer> container)
    {
        return container->make("logs")->connect();
    }
    
    /**
     * 注册 middleware 服务
     *
     * @return void
     */
    protected function middleware()
    {
        this->container->singleton("Leevel\\Log\\Middleware\\Log");
    }
}
