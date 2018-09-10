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

use Leevel\Di\IContainer;

/**
 * 事件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.31
 * 
 * @version 1.0
 */
class Dispatch implements IDispatch
{

    /**
     * 项目容器
     *
     * @var \Leevel\Di\IContainer
     */
    protected container;
    
    /**
     * 注册的监听器
     *
     * @var array
     */
    protected listeners = [];
    
    /**
     * 通配符的监听器
     *
     * @var array
     */
    protected wildcards = [];
    
    /**
     * 创建一个事件解析器
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        let this->container = container;
    }
    
    /**
     * 执行一个事件
     *
     * @return void
     */
    public function run()
    {
        var event, listeners, items, params = [], name;

        let params = func_get_args();
        let event = array_shift(params);
    
        if is_object(event) {
            let name = get_class($event);
        } else {
            let name = event;

            // This may return object or string
            let event = this->container->make(event);
        }

        array_unshift(params, event);

        let listeners = this->get(name);

        if empty listeners {
            return;
        }

        ksort(listeners);

        for items in listeners {
            let items = this->makeSubject(items);
            call_user_func_array([items, "notify"], params);
        }
    }
    
    /**
     * 注册监听器
     *
     * @param string|array|object $event
     * @param mixed $listener
     * @param int $priority
     * @return void
     */
    public function register(var event, var listener, int priority = 500)
    {
        var item, temp = [];

        if typeof event != "array" {
            let temp[] = event;
            let event = temp;
        }

        let priority = intval(priority);

        for item in event {
            let item = this->normalizeEvent(item);

            if strpos(item, "*") !== false {
                let this->wildcards[item][priority][] = listener;
            } else {
                let this->listeners[item][priority][] = listener;
            }
        }
    }
    
    /**
     * 获取一个事件监听器
     *
     * @param string|object $event
     * @return array
     */
    public function get(var event) -> array
    {
        var listeners, key, item, priority, value, res;
    
        let listeners = [];

        let event = this->normalizeEvent(event);

        if isset this->listeners[event] {
            let listeners = this->listeners[event];
        }

        for key, item in this->wildcards {
            let key = this->prepareRegexForWildcard(key);

            if preg_match(key, event, res) {
                for priority, value in item {
                    if ! (isset listeners[priority]) {
                        let listeners[priority] = [];
                    }

                    let listeners[priority] = array_merge(listeners[priority], value);
                }
            }
        }

        return listeners;
    }
    
    /**
     * 判断事件监听器是否存在
     *
     * @param string|object $event
     * @return bool
     */
    public function has(var event) -> boolean
    {
        return ! empty this->get(event);
    }
    
    /**
     * 删除一个事件所有监听器
     *
     * @param string|object $event
     * @return void
     */
    public function delete(var event)
    {
        let event = this->normalizeEvent(event);

        if isset this->listeners[event] {
            unset this->listeners[event];
        }

        if isset this->wildcards[event] {
            unset this->wildcards[event];
        }
    }

    /**
     * 格式化事件名字
     *
     * @param string|object $event
     * @return void
     */
    protected function normalizeEvent(var event)
    {
        return is_object(event) ? get_class(event) : event;
    }

    /**
     * 创建监听器观察者角色主体
     *
     * @param string $listeners
     * @return \Leevel\Event\Subject
     */
    protected function makeSubject(array listeners)
    {
        var subject, item;
    
        let subject = new Subject(this->container);

        for item in listeners {
            subject->attachs(item);
        }

        return subject;
    }
    
    /**
     * 通配符正则
     *
     * @param string $regex
     * @return string
     */
    protected function prepareRegexForWildcard(var regex) -> string
    {
        let regex = preg_quote(regex, "/");
        let regex = "/^" . str_replace("\\*", "(\\S+)", regex) . "$/";

        return regex;
    }
}
