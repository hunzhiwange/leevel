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
namespace Leevel\Option;

use ArrayAccess;
use Leevel\Option\IOption;

/**
 * 配置管理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.12.24
 * @version 1.0
 */
class Option implements IOption, ArrayAccess
{

    /**
     * 配置数据
     *
     * @var array
     */
    protected option = [];

    /**
     * 默认命名空间
     *
     * @var string
     */
    const DEFAUTL_NAMESPACE = "app";

    /**
     * 构造函数
     *
     * @param array $option
     * @return void
     */
    public function __construct(array option = [])
    {
        let this->option = option;
    }

    /**
     * 是否存在配置
     *
     * @param string $name 配置键值
     * @return string
     */
    public function has(string name = "app\\")
    {
        var tempname, names, namespaces, parts, part, option;

        let names = this->parseNamespace(name);
        let namespaces = names[0];
        let tempname = names[1];
        let name = tempname;

        if name == "*" {
            return isset(this->option[namespaces]);
        }

        if ! strpos(name, ".") {
            return array_key_exists(name, this->option[namespaces]);
        }

        let parts = explode(".", name);
        let option = this->option[namespaces];
        for part in parts {
            if ! isset option[part] {
                return false;
            }
            let option = option[part];
        }

        return true;
    }

    /**
     * 获取配置
     *
     * @param string $name 配置键值
     * @param mixed $defaults 配置默认值
     * @return string
     */
    public function get(string name = "app\\", var defaults = null)
    {
        var tempname, names, namespaces, parts, part, option;

        let names = this->parseNamespace(name);
        let namespaces = names[0];
        let tempname = names[1];
        let name = tempname;

        if name == "*" {
            return this->option[namespaces];
        }

        if ! strpos(name, ".") {
            return array_key_exists(name, this->option[namespaces]) ? this->option[namespaces][name] : defaults;
        }

        let parts = explode(".", name);
        let option = this->option[namespaces];
        for part in parts {
            if ! isset option[part] {
                return defaults;
            }
            let option = option[part];
        }

        return option;
    }

    /**
     * 返回所有配置
     *
     * @return array
     */
    public function all()
    {
        return this->option;
    }

    /**
     * 设置配置
     *
     * @param mixed $name 配置键值
     * @param mixed $value 配置值
     */
    public function set(var name, var value = null)
    {
        var key, values, names, namespaces, parts, option;

        if typeof name == "array" {
            for key, values in name {
                this->set(key, values);
            }
        } else {
            let names = this->parseNamespace(name);
            let namespaces = names[0];
            let name = names[1];

            if name == "*" {
                let this->option[namespaces] = value;
                return;
            }

            if ! strpos(name, ".") {
                let this->option[namespaces][name] = value;
            } else {
                let parts = explode(".", name);
                let option = this->setRecursion(parts, value);
                let this->option[namespaces] = array_merge(this->option[namespaces], option);
            }
        }
    }

    /**
     * 删除配置
     *
     * @param string $name 配置键值
     * @return string
     */
    public function delete(string name)
    {
        var tempname, name, names, namespaces, parts, option, tmpDelete;

        let names = this->parseNamespace(name);
        let namespaces = names[0];
        let tempname = names[1];
        let name = tempname;

        if name == "*" {
            let this->option[namespaces] = [];
            return;
        }

        if ! strpos(name, ".") {
            if isset this->option[namespaces][name] {
                let tmpDelete = this->option[namespaces];
                unset(tmpDelete[name]);
                let this->option[namespaces] = tmpDelete;
            }
        } else {
            let parts = explode(".", name);
            let option = this->deleteRecursion(parts, this->option[namespaces]);
            let this->option[namespaces] = option;
        }
    }

    /**
     * 初始化配置参数
     *
     * @param mixed $namespaces
     * @return boolean
     */
    public function reset(var namespaces = null)
    {
        if typeof namespaces == "array" {
            let this->option = namespaces;
        } elseif typeof namespaces == "string" {
            let this->option[namespaces] = [];
        } else {
            let this->option = [];
        }

        return true;
    }

    /**
     * 判断配置是否存在
     *
     * @param string $offset
     * @return bool
     */
    public function offsetExists(string offset)
    {
        return this->has(offset);
    }

    /**
     * 实现 ArrayAccess::offsetGet
     *
     * @param string $offset
     * @return mixed
     */
    public function offsetGet(string offset)
    {
        return this->get(offset);
    }

    /**
     * 实现 ArrayAccess::offsetSet
     *
     * @param string $offset
     * @param mixed $value
     * @return void
     */
    public function offsetSet(string offset, value)
    {
        return this->set(offset, value);
    }

    /**
     * 实现 ArrayAccess::offsetUnset
     *
     * @param string $offset
     * @return void
     */
    public function offsetUnset(string offset)
    {
        this->delete(offset);
    }

    /**
     * 递归设置配置数据
     *
     * @param array $part
     * @param mixed $value
     * @return array
     */
    protected function setRecursion(array! part, var value = null) -> array
    {
        var result = [], item;

        let item = array_shift(part);
        if ! isset result[item] {
            let result[item] = [];
        }

        if !empty part {
            let result[item] = this->setRecursion(part, value);
        } else {
            let result[item] = value;
        }

        return result;
    }

    /**
     * 递归删除配置数据
     *
     * @param array $part
     * @return array
     */
    protected function deleteRecursion(array! part, array! result) -> array
    {
        var item;

        let item = array_shift(part);
        if ! isset result[item] {
            return result;
        }

        if !empty part {
            let result[item] = this->deleteRecursion(part, result[item]);
        } else {
            if isset result[item] {
                unset result[item];
            }
        }

        return result;
    }

    /**
     * 分析命名空间
     *
     * @param string $name
     * @return array
     */
    protected function parseNamespace(string name)
    {
        var names, tempname, namespaces;

        if strpos(name, "\\") {
            let names = explode("\\", name);
            if empty names[1] {
                let names[1] = "*";
            }
            let tempname = names[1];
            let name = tempname;
            let namespaces = names[0];
        } else {
            let namespaces = self::DEFAUTL_NAMESPACE;
        }

        if ! isset this->option[namespaces] {
            let this->option[namespaces] = [];
        }

        return [
            namespaces,
            name
        ];
    }
}
