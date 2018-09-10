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
namespace Leevel\Database\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Database\Manager;

/**
 * database 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.26
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
        this->databases();
        this->database();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        return [
            "databases" : [
                "Leevel\\Database\\Manager"
            ], 
            "database" : [
                "Leevel\\Database\\Database", 
                "Leevel\\Database\\IDatabase"
            ]
        ];
    }
    
    /**
     * 注册 databases 服务
     *
     * @return void
     */
    protected function databases()
    {
        this->container->singleton("databases", Closure::fromCallable([this, "databasesClosure"]));
    }

    /**
     * 创建 databases 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Database\Manager
     */
    protected function databasesClosure(<IContainer> container)
    {
        return new Manager(container);
    }
    
    /**
     * 注册 database 服务
     *
     * @return void
     */
    protected function database()
    {
        this->container->singleton("database", Closure::fromCallable([this, "databaseClosure"]));
    }

    /**
     * 创建 database 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return object
     */
    protected function databaseClosure(<IContainer> container)
    {
        return container->make("databases")->connect();
    }
}
