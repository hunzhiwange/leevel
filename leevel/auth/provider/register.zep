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

namespace Leevel\Auth\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Auth\Manager;
use Leevel\Di\IContainer;

/**
 * auth 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * 
 * @since 2018.01.28
 * 
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
        this->auths();
        this->auth();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        return [
            "auths" : [
                "Leevel\\Auth\\Manager"
            ], 
            "auth" : [
                "Leevel\\Auth\\Auth", 
                "Leevel\\Auth\\IAuth"
            ]
        ];
    }
    
    /**
     * 注册 auths 服务
     *
     * @return void
     */
    protected function auths()
    {
        this->container->singleton("auths", Closure::fromCallable([this, "authsClosure"]));
    }

    /**
     * 创建 auths 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Auth\Manager
     */
    protected function authsClosure(<IContainer> container)
    {
        return new Manager(container);
    }
    
    /**
     * 注册 auth 服务
     *
     * @return void
     */
    protected function auth()
    {
        this->container->singleton("auth", Closure::fromCallable([this, "authClosure"]));
    }

    /**
     * 创建 auth 服务闭包
     *
     * @param \Leevel\Di\IContainer $container
     * @return object
     */
    protected function authClosure(<IContainer> container)
    {
        return container->make("auths")->connect();
    }
}
