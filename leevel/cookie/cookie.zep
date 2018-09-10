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
namespace Leevel\Cookie;

use Exception;
use Leevel\Cookie\ICookie;

/**
 * cookie 封装
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.06
 * 
 * @version 1.0
 */
class Cookie implements ICookie
{

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "expire" : 86400,
        "domain" : "",
        "path" : "/",
        "secure" : false,
        "httponly" : false
    ];

    /**
     * Cookie 设置数据
     *
     * @var array
     */
    protected cookies = []; 

    /**
     * 构造函数
     *
     * @param array $option
     * @return void
     */
    public function __construct(array option = [])
    {
        let this->option = array_merge(this->option, option);
    }

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function setOption(string name, var value)
    {
        let this->option[name] = value;
        
        return this;
    }

    /**
     * 设置 COOKIE
     *
     * @param string $name
     * @param string $value
     * @param array $option
     * @return void
     */
    public function set(string name, var value = "", array! option = [])
    {
        let option = this->normalizeOptions(option);

        if typeof value == "array" {
            let value = json_encode(value);
        }

        if ! is_scalar(value) && ! is_null(value) {
            throw new Exception("Cookie value must be scalar or null.");
        }

        let option["expire"] = intval(option["expire"]);

        if option["expire"] > 0 {
            let option["expire"] = time() + option["expire"];
        } elseif option["expire"] < 0 {
            let option["expire"] = time() - 31536000;
        }

        // 对应 setcookie 的参数
        let this->cookies[name] = [
            name,
            value,
            option["expire"],
            option["path"],
            option["domain"],
            option["secure"],
            option["httponly"]
        ];
    }

    /**
     * 批量插入
     *
     * @param string|array $keys
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function put(var keys, var value = null, array! option = [])
    {
        var key, tmpKeys;

        if typeof keys != "array" {
            let tmpKeys = [
                keys : value
            ];
        } else {
            let tmpKeys = keys;
        }

        for key, value in tmpKeys {
            this->set(key, value, option);
        }
    }

    /**
     * 数组插入数据
     *
     * @param string $key
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function push(string key, var value, array! option = [])
    {
        var arr;
        let arr = this->get(key, [], option);
        let arr[] = value;
        this->set(key, arr, option);
    }

    /**
     * 合并元素
     *
     * @param string $key
     * @param array $value
     * @param array $option
     * @return void
     */
    public function merge(string key, array value, array! option = [])
    {
        this->set(key, array_merge(this->get(key, [], option), value), option);
    }

    /**
     * 弹出元素
     *
     * @param string $key
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function pop(string key, array value, array! option = [])
    {
        this->set(key, array_diff(this->get(key, [], option), value), option);
    }

    /**
     * 数组插入键值对数据
     *
     * @param string $key
     * @param mixed $keys
     * @param mixed $value
     * @param array $option
     * @return void
     */
    public function arr(string key, var keys, var value = null, array! option = [])
    {
        var arr;

        let arr = this->get(key, [], option);

        if typeof keys == "string" {
            let arr[keys] = value;
        } elseif typeof keys == "array" {
            let arr = array_merge(arr, keys);
        }

        this->set(key, arr, option);
    }

    /**
     * 数组键值删除数据
     *
     * @param string $key
     * @param mixed $keys
     * @return void
     */
    public function arrDelete(string key, var keys, array! option = [])
    {
        var arr, tmp, deleteKey;

        let arr =  this->get(key, [], option);

        if typeof keys != "array" {
            let deleteKey = [
                keys
            ];
        } else {
            let deleteKey = keys;
        }

        for tmp in deleteKey {
            if isset arr[tmp] {
                unset arr[tmp];
            }
        }

        this->set(key, arr, option);
    }

    /**
     * 获取 cookie
     *
     * @param string $name
     * @param mixed $defaults
     * @param array $option
     * @return mixed
     */
    public function get(string name, var defaults = null, array! option = [])
    {
        let option = this->normalizeOptions(option);

        if isset this->cookies[name] {
            if this->isJson(this->cookies[name][1]) {
                return json_decode(this->cookies[name][1], true);
            }
            
            return this->cookies[name][1];
        } else {
            return defaults;
        }
    }

    /**
     * 删除 cookie
     *
     * @param string $name
     * @param array $option
     * @return void
     */
    public function delete(string name, array! option = [])
    {
        this->set(name, null, option);
    }

    /**
     * 清空 cookie
     *
     * @param array $option
     * @return void
     */
    public function clear(array! option = [])
    {
        var key;

        let option = this->normalizeOptions(option);

        for key, _ in this->cookies {
            this->delete(key, option);
        }
    }

    /**
     * 返回所有 cookie
     *
     * @return array
     */
    public function all()-> array
    {
        return this->cookies;
    }

    /**
     * 整理配置.
     *
     * @param array $option
     *
     * @return array
     */
    protected function normalizeOptions(array option = [])
    {
        return !empty option ? array_merge(this->option, option) : this->option;
    }

    /**
     * 验证是否为正常的 JSON 字符串
     *
     * @param mixed $data
     * @return boolean
     */
    protected function isJson(var data)
    {
        if ! is_scalar(data) && ! method_exists(data, "__toString") {
            return false;
        }

        json_decode(strval(data));

        return json_last_error() === JSON_ERROR_NONE;
    }
}
