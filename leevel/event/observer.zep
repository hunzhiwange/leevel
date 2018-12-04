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

namespace Leevel\Event;

use SplSubject;
use SplObserver;
use Closure;
use InvalidArgumentException;

/**
 * 观察者角色 observer
 * \SplObserver 无法识别 container
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.01
 * @link http://php.net/manual/zh/class.splobserver.php
 * @version 1.0
 */
class Observer implements SplObserver
{
    /**
     * 观察者目标角色 subject
     *
     * @var \SplSubject
     */
    protected subject;

    /**
     * 观察者实现.
     *
     * @var \Closure
     */
    protected handle;

    /**
     * 构造函数
     *
     * @param \Closure $handle
     * @return void
     */
    public function __construct(var handle = null)
    {
        let this->handle = handle;
    }

    /**
     * 观察者实现.
     */
    public function __invoke()
    {
        call_user_func_array(this->handle, func_get_args());
    }

    /**
     * {@inheritdoc}
     */
    public function update(<SplSubject> subject) -> void
    {
        var handle;

        if method_exists(this, "handle") {
            let handle = [this, "handle"];
        } elseif this->handle {
            let handle = [this, "__invoke"];
        } else {
            let handle = null;
        }

        if ! (is_callable(handle)) {
            throw new InvalidArgumentException(
                sprintf("Observer %s must has handle method.", get_class(this))
            );
        }

        subject->container->call(handle, subject->notifyArgs);
    }
}
