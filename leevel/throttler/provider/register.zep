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
namespace Leevel\Throttler\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Throttler\Throttler;

/**
 * throttler 服务提供者
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
        this->throttler();
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
            "throttler" : [
                "Leevel\\Throttler\\Throttler", 
                "Leevel\\Throttler\\IThrottler"
            ], 
            "Leevel\\Throttler\\Middleware\\Throttler"
        ];
    }

    /**
     * {@inheritdoc}
     */
    public static function isDeferred() -> boolean
    {
        return true;
    }

    /**
     * 注册 throttler 服务
     *
     * @return void
     */
    protected function throttler()
    {
        this->container->singleton("throttler", Closure::fromCallable([this, "throttlerClosure"]));
    }

    /**
     * 创建 throttler 服务闭包
     *
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Throttler\Throttler
     */
    protected function throttlerClosure(<IContainer> container)
    {
        var throttler;

        let throttler = new Throttler(
            container->make("caches")->connect(container->make("option")->get("throttler\\driver"))
        );

        throttler->setRequest(container->make("request"));

        return throttler;
    }
    
    /**
     * 注册 middleware 服务
     *
     * @return void
     */
    protected function middleware()
    {
        this->container->singleton("Leevel\\Throttler\\Middleware\\Throttler");
    }
}
