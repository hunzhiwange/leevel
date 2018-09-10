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
namespace Leevel\Encryption\Provider;

use Closure;
use Leevel\Di\Provider;
use Leevel\Di\IContainer;
use Leevel\Encryption\Encryption;

/**
 * encryption 服务提供者
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
        this->container->singleton("encryption", Closure::fromCallable([this, "encryptionClosure"]));
    }

    /**
     * 创建 encryption 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\Encryption\Encryption
     */
    protected function encryptionClosure(<IContainer> container)
    {
        var option;

        let option = container->make("option");

        return new Encryption(option->get("auth_key"), option->get("auth_expiry"));
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        return [
            "encryption" : [
                "Leevel\\Encryption\\Encryption", 
                "Leevel\\Encryption\\IEncryption"
            ]
        ];
    }

    /**
     * {@inheritdoc}
     */
    public static function isDeferred() -> boolean
    {
        return true;
    }
}
