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
use SplObjectStorage;
use InvalidArgumentException;
use Leevel\Di\IContainer;

/**
 * 观察者目标角色 subject
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.23
 * @link http://php.net/manual/zh/class.splsubject.php
 * @version 1.0
 */
class Subject implements ISubject, SplSubject
{

    /**
     * 容器
     *
     * @var \Leevel\Di\IContainer
     */
    public container;
    
    /**
     * 观察者角色 observer
     *
     * @var \SplObjectStorage(\SplObserver)
     */
    protected observers;
    
    /**
     * 通知附加参数
     *
     * @var array
     */
    public notifyArgs = [];
    
    /**
     * 构造函数
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        let this->observers = new SplObjectStorage();
        let this->container = container;
    }
    
    /**
     * {@inheritdoc}
     */
    public function attach(<SplObserver> observer) -> void
    {
        this->observers->attach(observer);
    }
    
    /**
     * {@inheritdoc}
     */
    public function detach(<SplObserver> observer) -> void
    {
        this->observers->detach(observer);
    }
    
    /**
     * {@inheritdoc}
     */
    public function notify() -> void
    {
        let this->notifyArgs = func_get_args();

        this->observers->rewind();
        
        while this->observers->valid() {
            this->observers->current()->update(this);
            this->observers->next();
        }
    }
    
    /**
     * 添加一个观察者角色
     *
     * @param \SplObserver|string $observer
     * @return $this
     */
    public function attachs(observer)
    {
        if is_string(observer) {
            let observer = this->container->make(observer);
            
            if is_string(observer) {
                throw new InvalidArgumentException(
                    sprintf("Observer is invalid.")
                );
            }
        }

        if observer instanceof SplObserver {
            this->attach(observer);
        } else {
            throw new InvalidArgumentException(
                "Invalid observer argument because it not instanceof SplObserver."
            );
        }
    }
}
