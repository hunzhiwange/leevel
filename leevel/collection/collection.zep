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

use Closure;
use Iterator;
use Countable;
use ArrayAccess;
use JsonSerializable;
use RuntimeException;
use BadMethodCallException;
use InvalidArgumentException;
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
class Collection implements IMacro, IArray, IJson, Iterator, ArrayAccess, Countable, JsonSerializable
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
     * 实现 ArrayAccess::offsetExists
     *
     * @param string $offset
     * @return mixed
     */
    public function offsetExists(string offset)
    {
        return isset this->elements[offset];
    }
    
    /**
     * 实现 ArrayAccess::offsetGet
     *
     * @param string $offset
     * @return mixed
     */
    public function offsetGet(string offset)
    {
        return isset this->elements[offset] ? this->elements[offset] : null;
    }
    
    /**
     * 实现 ArrayAccess::offsetSet
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function offsetSet(string key, value)
    {
        this->checkType(value);
        let this->elements[key] = value;
    }
    
    /**
     * 实现 ArrayAccess::offsetUnset
     *
     * @param string $key
     * @return void
     */
    public function offsetUnset(string key)
    {
        if isset this->elements[key] {
            unset this->elements[key];
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
    public function toJson(int option = 256) -> string
    {
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
     * JQuery.each
     * 
     * @param callable $callback
     * @return $this
     */
    public function each(callback)
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
     * JQuery.prev
     *
     * @return mixed
     */
    public function prev()
    {
        var prev;
    
        let prev = prev(this->elements);
        let this->valid = true;

        return prev;
    }
    
    /**
     * JQuery.end
     *
     * @return mixed
     */
    public function end()
    {
        var end;
    
        let end = end(this->elements);
        let this->valid = false;

        return end;
    }
    
    /**
     * JQuery.siblings
     *
     * @param mixed $key
     * @return array
     */
    public function siblings(var key = null) -> array
    {
        var result, k, value;
    
        let result = [];
        let key = this->parseKey(key);

        for k, value in this->elements {
            if k === key {
                continue;
            }
            let result[k] = value;
        }

        return result;
    }
    
    /**
     * JQuery.nextAll
     *
     * @param mixed $key
     * @return array
     */
    public function nextAll(var key = null) -> array
    {
        var result, current, k, value;
    
        let result = [];
        let key = this->parseKey(key);
        let current = false;

        for k, value in this->elements {
            if current === false {
                if k === key {
                    let current = true;
                }
                continue;
            }

            let result[k] = value;
        }

        return result;
    }
    
    /**
     * JQuery.prevAll
     *
     * @param mixed $key
     * @return array
     */
    public function prevAll(var key = null) -> array
    {
        var result, current, k, value;
    
        let result = [];
        let key = this->parseKey(key);
        let current = false;

        for k, value in this->elements {
            if k === key {
                let current = true;
                break;
            }

            let result[k] = value;
        }

        return result;
    }
    
    /**
     * JQuery.attr
     *
     * @param string $key
     * @param mixed $value
     * @return void|mixed
     */
    public function attr(string key, var value = null)
    {
        if value === null {
            return this->offsetGet(key);
        } else {
            this->offsetSet(key, value);
        }
    }
    
    /**
     * JQuery.eq
     *
     * @param string $key
     * @return mixed
     */
    public function eq(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * JQuery.get
     *
     * @param string $key
     * @return mixed
     */
    public function get(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * JQuery.index
     *
     * @param mixed $value
     * @param boolean $strict
     * @return mixed
     */
    public function index(var value = null, boolean strict = true)
    {
        var key;
    
        if value === null {
            return this->key();
        } else {
            let key = array_search(value, this->elements, strict);
            if key === false {
                return;
            }

            return key;
        }
    }
    
    /**
     * JQuery.find
     *
     * @param string $key
     * @return mixed
     */
    public function find(string key)
    {
        return this->offsetGet(key);
    }
    
    /**
     * JQuery.first
     *
     * @return mixed
     */
    public function first()
    {
        this->rewind();
        return this->current();
    }
    
    /**
     * JQuery.last
     *
     * @return mixed
     */
    public function last()
    {
        return this->end();
    }
    
    /**
     * JQuery.is
     *
     * @param string $key
     * @return boolean
     */
    public function is(string key) -> boolean
    {
        return this->offsetExists(key);
    }
    
    /**
     * JQuery.slice
     *
     * @param int $selector
     * @param int $length
     * @return array
     */
    public function slice(int selector, var length = null) -> array
    {
        return array_slice(this->elements, selector, length);
    }
    
    /**
     * JQuery.not
     *
     * @param string $key
     * @return array
     */
    public function not(string key) -> array
    {
        return this->siblings(key);
    }
    
    /**
     * JQuery.filter
     *
     * @param string $key
     * @return array
     */
    public function filter(string key) -> array
    {
        return this->siblings(key);
    }
    
    /**
     * jquer.size
     *
     * @return int
     */
    public function size() -> int
    {
        return this->count();
    }
    
    /**
     * 是否为空
     *
     * @return boolean
     */
    public function isEmpty() -> boolean
    {
        return empty(this->elements);
    }
    
    /**
     * 数据 map
     *
     * @param mixed $key
     * @param mixed $value
     * @return array
     */
    public function map(var key, var value = null) -> array
    {
        return array_column(this->elements, key, value);
    }

    /**
     * 注册一个扩展
     *
     * @param string $name
     * @param callable $macro
     * @return void
     */
    public static function macro(string name, var macro)
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
        var temp = [];

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

        if typeof elements != "array" {
            let temp[] = elements;
            let elements = temp;
        }

        return elements;
    }
    
    /**
     * 分析 key
     *
     * @param mixed $key
     * @return mixed
     */
    protected function parseKey(var key = null)
    {
        if is_null(key) {
            let key = this->key();
        }
        return key;
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
