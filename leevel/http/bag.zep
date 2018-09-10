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
namespace Leevel\Http;

use ArrayIterator;
use Countable;
use IteratorAggregate;
use JsonSerializable;
use Leevel\Support\IArray;
use Leevel\Support\IJson;

/**
 * http bag
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.19
 *
 * @version 1.0
 *
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
class Bag implements IArray, IJson, Countable, IteratorAggregate, JsonSerializable
{

    /**
     * zephir 不支持 eval 动态赋值
     * 
     * @var boolean
     */
    protected static zephirAssign = false;

    /**
     * 元素合集
     *
     * @var array
     */
    protected elements = [];
    
    /**
     * 构造函数
     * 
     * @param array $elements
     * @return void 
     */
    public function __construct(array elements = [])
    {
        let this->elements = elements;
    }
    
    /**
     * 取回元素
     *
     * @return array
     */
    public function all() -> array
    {
        return this->elements;
    }
    
    /**
     * 返回元素键值
     *
     * @return array
     */
    public function keys() -> array
    {
        return array_keys(this->elements);
    }
    
    /**
     * 替换当前所有元素
     *
     * @param array $elements
     * @return void
     */
    public function replace(array elements = [])
    {
        let this->elements = elements;
    }
    
    /**
     * 新增元素
     *
     * @param array $elements
     * @return void
     */
    public function add(array elements = [])
    {
        let this->elements = array_replace(this->elements, elements);
    }
    
    /**
     * 取回元素值
     *
     * @param string $key
     * @param mixed $defaults
     * @return mixed
     */
    public function get(string key, var defaults = null)
    {
        let key = this->normalize(key);

        return this->filter(key, defaults);
    }
    
    /**
     * 设置元素值
     *
     * @param string $key
     * @param mixed $value
     * @return void
     */
    public function set(string key, var value)
    {
        let key = this->normalize(key);
        let this->elements[key] = value;
    }
    
    /**
     * 判断是否存在元素值
     *
     * @param string $key
     * @return bool
     */
    public function has(string key) -> bool
    {
        let key = this->normalize(key);

        return array_key_exists(key, this->elements);
    }
    
    /**
     * 删除元素值
     *
     * @param string $key
     * @return void
     */
    public function remove(string key)
    {
        let key = this->normalize(key);

        if this->has(key) {
            unset this->elements[key];
        }
    }
    
    /**
     * 获取过滤变量
     *
     * @param string $key
     * @param mixed $defaults
     * @param array|sting|int $filter
     * @param array $options
     * @return mixed
     */
    public function filter(var key, var defaults = null, var filter = null, array options = [])
    {
        var tmp = [], tmpKey = [], result, part;
    
        let key = this->normalize(key);
        let filter = this->parseFilter(filter);
        let tmp = this->parseKeyFilter(key, filter);
        let key = tmp[0];
        let filter = tmp[1];

        let part = "";
        if strpos(key, "\\") !== false {
            let tmpKey = explode("\\", key);
            let key = tmpKey[0];
            let part = tmpKey[1];
        }

        let result = array_key_exists(key, this->elements) ? this->elements[key] : defaults;

        if part {
            let result = this->getPartData(part, result, defaults);
        }

        if filter {
            let result = this->filterValue(result, defaults, filter, options);
        }

        return result;
    }
    
    /**
     * 实现 Countable::count
     *
     * @return int
     */
    public function count() -> int
    {
        return count(this->elements);
    }
    
    /**
     * 对象转数组
     *
     * @return array
     */
    public function toArray() -> array
    {
        return this->elements;
    }
    
    /**
     * 实现 JsonSerializable::jsonSerialize
     *
     * @return array
     */
    public function jsonSerialize() -> array
    {
        return this->toArray();
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
     * 实现 IteratorAggregate::getIterator
     *
     * @return \ArrayIterator
     */
    public function getIterator() -> <ArrayIterator>
    {
        return new ArrayIterator(this->elements);
    }
    
    /**
     * 魔术方法 __toString
     *
     * @return string
     */
    public function __toString() -> string
    {
        return this->toJson();
    }
    
    /**
     * 分析键值和过滤器
     * 
     * @param string $key
     * @param array $filter
     * @return array
     */
    protected function parseKeyFilter(string key, array filter) -> array
    {
        var tmp, tmpKey;
    
        if strpos(key, "|") !== false {
            let tmp = explode("|", key);
            let tmpKey = array_shift(tmp);
            let key = tmpKey;
            let filter = array_merge(tmp, filter);
        }

        return [key, filter];
    }
    
    /**
     * 分析过滤器
     *
     * @param string|array|null $filter
     * @return array
     */
    protected function parseFilter(var filter = null) -> array
    {
        var data;

        if typeof filter === "null" {
            return [];
        }

        if typeof filter === "array" {
            return filter;
        }

        let data = [filter];

        return data;
    }
    
    /**
     * 过滤值
     *
     * @param mixed $value
     * @param mixed $defaults
     * @param array $filters
     * @param array $options
     * @return mixed
     */
    protected function filterValue(var value, var defaults, array filters, array options = [])
    {
        var item;
    
        for item in filters {
            if is_string(item) && strpos(item, "=") !== false {
                let value = this->filterValueWithFunc(value, item);
            } elseif is_callable(item) {
                let value = this->filterValueWithCallable(value, item);
            } elseif is_scalar(value) && ! empty(item) {
                let value = this->filterValueWithFilterVar(value, item, options);

                if value === false {
                    let value = defaults;
                    break;
                }
            }
        }

        return value;
    }
    
    /**
     * 使用函数过滤值
     *
     * @param mixed $value
     * @param string $filter
     * @return mixed
     */
    protected function filterValueWithFunc(var value, var filter)
    {
        var extend, tmp = [], evals, tmpExtend = [], result = [], v;
    
        let tmp = explode("=", filter);
        let filter = tmp[0];
        let extend = tmp[1];

        if filter == "default" {
            if ! is_numeric(extend) && ! preg_match("/^[A-Z\_]+$/", extend) {
                let extend = "'" . extend . "'";
            }

            let evals = "$value = '" . (value ? "1" : "") . "' ?: " . extend . ";";
        } elseif extend {
            if strpos(extend, ",") !== false {
                let tmpExtend = explode(",", extend);

                for v in tmpExtend {
                    let v = trim(v);

                    if v == "**" || is_numeric(v) || preg_match("/^[A-Z\_]+$/", v) {
                        let result[] = v;
                    } else {
                        let result[] = "'" . v . "'";
                    }
                }

                let extend = implode(",", result);
            }

            if strstr(extend, "**") {
                let extend = str_replace("**", "$value", extend);
                let evals = "$value = " . filter . "(" . extend . ");";
            } else {
                let evals = "$value = " . filter . "($value, " . extend . ");";
            }
        }

        if (! self::zephirAssign) {
            eval("if (! function_exists('zephir_assign')) {
                function zephir_assign($value, $evals) {
                    eval($evals);
                    return $value;
                }
            }");

            let self::zephirAssign = true;
        }

        let value = zephir_assign(value, evals);

        return value;
    }
    
    /**
     * 使用回调过滤值
     *
     * @param mixed $value
     * @param string $filter
     * @return mixed
     */
    protected function filterValueWithCallable(var value, string filter)
    {
        return call_user_func(filter, value);
    }
    
    /**
     * 使用 filter_var 过滤值
     *
     * @param mixed $value
     * @param mixed $filter
     * @param array $options
     * @see http://php.net/manual/en/function.filter-var.php
     * @return mixed
     */
    protected function filterValueWithFilterVar(var value, var filter, array options)
    {
        return filter_var(value, this->parseFilterId(filter), options);
    }
    
    /**
     * 分析转换 filter_var 参数
     *
     * @param mixed $filter
     * @return int
     */
    protected function parseFilterId(var filter) -> int
    {
        return this->isInt(filter) ? filter : filter_id(filter);
    }
    
    /**
     * 判断字符串是否为数字
     *
     * @param mixed $value
     * @since bool
     */
    protected function isInt(var value)
    {
        if is_int(value) {
            return true;
        }

        return ctype_digit(strval(value));
    }
    
    /**
     * 返回部分数组数据
     *
     * @param string $key
     * @param mixed $value
     * @param mixed  $defaults
     * @return mixed
     */
    protected function getPartData(var key, var value, var defaults = null)
    {
        var parts, item;
    
        if typeof value != "array" {
            return value;
        }

        let parts = explode(".", key);

        for item in parts {
            if typeof value != "array" || ! isset value[item] {
                return defaults;
            }

            let value = value[item];
        }

        return value;
    }
    
    /**
     * 格式化键值
     *
     * @param string $key
     * @return string
     */
    protected function normalize(string key) -> string
    {
        return key;
    }
}
