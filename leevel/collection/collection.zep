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
namespace Leevel\Collection;

use ArrayAccess;
use ArrayIterator;
use Closure;
use Countable;
use stdClass;
use JsonSerializable;
use RuntimeException;
use BadMethodCallException;
use InvalidArgumentException;
use IteratorAggregate;
use Leevel\Support\Type;
use Leevel\Support\IJson;
use Leevel\Support\IArray;
use Leevel\Support\IMacro;

/**
 * 集合
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.03
 *
 * @version 1.0
 */
class Collection implements IMacro, IArray, IJson, IteratorAggregate, ArrayAccess, Countable, JsonSerializable
{
    /**
     * 元素合集
     *
     * @var array
     */
    protected elements = [];

    /**
     * 验证
     *
     * @var boolean
     */
    protected valid = true;

    /**
     * 类型
     *
     * @var mixed
     */
    protected type = [];

    /**
     * 注册的动态扩展
     *
     * @var array
     */
    protected static macro = [];

    /**
     * 构造函数
     *
     * @param mixed $elements
     * @param array $type
     * @return void
     */
    public function __construct(var elements = [], array type = null)
    {
        var key, value;

        if ! empty type {
            let this->type = type;
        }

        let elements = this->getArrayElements(elements);

        if this->type {
            for key, value in elements {
                this->offsetSet(key, value);
            }
        } else {
            let this->elements = elements;
        }
    }

    /**
     * 创建一个集合
     *
     * @param mixed $elements
     * @param mixed $type
     * @return void
     */
    public static function make(elements = [], var type = null)
    {
        return new self(elements, type);
    }

    /**
     * 当前元素
     *
     * @return mixed
     */
    public function current()
    {
        return current(this->elements);
    }

    /**
     * 当前 key
     *
     * @return mixed
     */
    public function key()
    {
        return key(this->elements);
    }

    /**
     * 下一个元素
     *
     * @return void
     */
    public function next()
    {
        var next;

        let next = next(this->elements);
        let this->valid = next !== false;
    }

    /**
     * 指针重置
     *
     * @return void
     */
    public function rewind()
    {
        reset(this->elements);
        let this->valid = true;
    }

    /**
     * 验证
     *
     * @return boolean
     */
    public function valid() -> boolean
    {
        return this->valid;
    }

    /**
     * 实现 IteratorAggregate::getIterator.
     *
     * @return \ArrayIterator
     */
    public function getIterator()-> <ArrayIterator>
    {
        return new ArrayIterator(this->elements);
    }

    /**
     * 实现 ArrayAccess::offsetExists
     *
     * @param mixed $index
     * @return mixed
     */
    public function offsetExists(var index) -> bool
    {
        return isset this->elements[index];
    }

    /**
     * 实现 ArrayAccess::offsetGet
     *
     * @param mixed $index
     * @return mixed
     */
    public function offsetGet(var index)
    {
        return isset this->elements[index] ? this->elements[index] : null;
    }

    /**
     * 实现 ArrayAccess::offsetSet
     *
     * @param mixed $index
     * @param mixed $newval
     */
    public function offsetSet(var index, var newval)
    {
        this->checkType(newval);
        let this->elements[index] = newval;
    }

    /**
     * 实现 ArrayAccess::offsetUnset
     *
     * @param mixed $index
     */
    public function offsetUnset(var index)
    {
        if isset this->elements[index] {
            unset this->elements[index];
        }
    }

    /**
     * 统计元素数量 count($obj)
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->elements);
    }

    /**
     * 返回所有元素
     *
     * @return array
     */
    public function all() -> array
    {
        return this->elements;
    }

    /**
     * 对象转数组
     *
     * @return array
     */
    public function toArray() -> array
    {
        var key, value;
        array result = [];

        for key, value in this->elements {
            if is_object(value) && value instanceof IArray {
                let result[key] = value->toArray();
            } else {
                let result[key] = value;
            }
        }

        return result;
    }

    /**
     * 实现 JsonSerializable::jsonSerialize
     *
     * @return array
     */
    public function jsonSerialize() -> array
    {
        var key, value;
        array result = [];

        for key, value in this->elements {
            if value instanceof JsonSerializable {
                let result[key] = value->jsonSerialize();
            } elseif value instanceof IJson {
                let result[key] = json_decode(value->toJson(), true);
            } elseif value instanceof IArray {
                let result[key] = value->toArray();
            } else {
                let result[key] = value;
            }
        }

        return result;
    }

    /**
     * 对象转 JSON
     *
     * @param integer $option
     * @return string
     */
    public function toJson(var option = null) -> string
    {
        if is_null(option) {
            let option = JSON_UNESCAPED_UNICODE;
        }

        return json_encode(this->jsonSerialize(), option);
    }

    /**
     * __toString 魔术方法
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->toJson();
    }

    /**
     * each
     *
     * @param \Closure $callback
     * @return $this
     */
    public function each(<Closure> callback)
    {
        var key, item;

        if !is_callable(callback) {
            throw new RuntimeException("Each need a callback.");
        }

        for key, item in this->elements {
            if {callback}(item, key) === false {
                break;
            }
        }

        return this;
    }

    /**
     * 注册一个扩展
     *
     * @param string $name
     * @param callable $macro
     * @return void
     */
    public static function macro(string name, <Closure> macro)
    {
        let self::macro[name] = macro;
    }

    /**
     * 判断一个扩展是否注册
     *
     * @param string $name
     * @return bool
     */
    public static function hasMacro(string name) -> boolean
    {
        return isset self::macro[name];
    }

    /**
     * __callStatic 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function callStaticMacro(string method, array args)
    {
        if self::hasMacro(method) {
            return call_user_func_array(self::macro[method], args);
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }

    /**
     * __call 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function callMacro(string method, array args)
    {
        if self::hasMacro(method) {
            if self::macro[method] instanceof Closure {
                return call_user_func_array(self::macro[method]->bindTo(this), args);
            } else {
                return call_user_func_array(self::macro[method], args);
            }
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }

    /**
     * 验证类型
     *
     * @param mixed $value
     * @return void
     */
    protected function checkType(value)
    {
        if ! (this->type) {
            return;
        }

        if Type::these(value, this->type) {
            return;
        }

        throw new InvalidArgumentException(
            sprintf("Collection type %s validation failed.", implode(",", this->type))
        );
    }

    /**
     * 转换数据到数组
     *
     * @param mixed $elements
     * @return array
     */
    protected function getArrayElements(elements) -> array
    {
        if is_array(elements) {
            return elements;
        } elseif is_object(elements) && elements instanceof Collection {
            return elements->all();
        } elseif is_object(elements) && elements instanceof IArray {
            return elements->toArray();
        } elseif is_object(elements) && elements instanceof IJson {
            return json_decode(elements->toJson(), true);
        } elseif is_object(elements) && elements instanceof JsonSerializable {
            return elements->jsonSerialize();
        }

        if is_object(elements) && elements instanceof stdClass {
            return json_decode(json_encode(elements), true);
        }

        return [elements];
    }

    /**
     * __get 魔术方法
     *
     * @param string $key
     * @return mixed
     */
    public function __get(string key)
    {
        return this->offsetGet(key);
    }

    /**
     * __set 魔术方法
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function __set(string key, value)
    {
        this->offsetSet(key, value);
    }

    /**
     * __callStatic 魔术方法
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function __callStatic(string method, array args)
    {
        return self::callStaticMacro(method, args);
    }

    /**
     * __call 魔术方法
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function __call(string method, array args)
    {
        return this->callMacro(method, args);
    }
}
