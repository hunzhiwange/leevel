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

namespace Leevel\Session;

use Leevel\Support\Str;
use RuntimeException;
use SessionHandlerInterface;
use BadMethodCallException;

/**
 * session 仓储.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.17
 *
 * @version 1.0
 */
class Session implements ISession
{
    /**
     * session ID.
     * 相当于 session_id.
     *
     * @var string
     */
    protected id;
    
    /**
     * session 名字.
     * 相当于 session_name.
     *
     * @var string
     */
    protected name;
    
    /**
     * session handler.
     *
     * @var \SessionHandlerInterface
     */
    protected connect;
    
    /**
     * session 是否开启.
     *
     * @var bool
     */
    protected started = false;
    
    /**
     * session 数据.
     *
     * @var array
     */
    protected datas = [];
    
    /**
     * 配置.
     *
     * @var array
     */
    protected option = [
        "id" : null,
        "name" : null
    ];
    
    /**
     * 构造函数.
     *
     * @param \SessionHandlerInterface $connect
     * @param array                    $option
     */
    public function __construct(<SessionHandlerInterface> connect, array option = []) -> void
    {
        let this->connect = connect;

        let this->option = array_merge(this->option, option);

        this->setName(this->option["name"]);
    }
    
    /**
     * 启动 session.
     *
     * @param string $sessionId
     */
    public function start(var sessionId = null)
    {
        if this->isStart() {
            return this;
        }

        this->setId(sessionId ? sessionId : this->option["id"]);

        this->loadData();

        let this->started = true;
    }
    
    /**
     * 程序执行保存 session.
     */
    public function save() -> void
    {
        if ! (this->isStart()) {
            throw new RuntimeException("Session is not start yet.");
        }

        this->unregisterFlash();

        this->connect->write(this->getId(), serialize(this->datas));

        let this->started = false;
    }
    
    /**
     * 取回所有 session 数据.
     *
     * @return array
     */
    public function all() -> array
    {
        return this->datas;
    }
    
    /**
     * 设置 session.
     *
     * @param string $name
     * @param mxied  $value
     */
    public function set(string name, var value) -> void
    {
        var tmp;

        let tmp = this->getNormalizeName(name);

        let this->datas[tmp] = value;
    }
    
    /**
     * 批量插入.
     *
     * @param array|string $keys
     * @param mixed        $value
     */
    public function put(var keys, var value = null) -> void
    {
        var item, tmp;
    
        if ! (is_array(keys)) {
            let tmp = [keys : value];
        } else {
            let tmp = keys;
        }

        for item, value in tmp {
            this->set(item, value);
        }
    }
    
    /**
     * 数组插入数据.
     *
     * @param string $key
     * @param mixed  $value
     */
    public function push(string key, var value) -> void
    {
        var arr;

        let arr = this->get(key, []);
        let arr[] = value;

        this->set(key, arr);
    }
    
    /**
     * 合并元素.
     *
     * @param string $key
     * @param array  $value
     */
    public function merge(string key, array value) -> void
    {
        this->set(key, array_merge(this->get(key, []), value));
    }
    
    /**
     * 弹出元素.
     *
     * @param string $key
     * @param mixed  $value
     */
    public function pop(string key, array value) -> void
    {
        this->set(key, array_diff(this->get(key, []), value));
    }
    
    /**
     * 数组插入键值对数据.
     *
     * @param string $key
     * @param mixed  $keys
     * @param mixed  $value
     */
    public function arr(string key, var keys, var value = null) -> void
    {
        var arr;

        let arr = this->get(key, []);

        if typeof keys == "string" {
            let arr[keys] = value;
        } elseif typeof keys == "array" {
            let arr = array_merge(arr, keys);
        }

        this->set(key, arr);
    }
    
    /**
     * 数组键值删除数据.
     *
     * @param string $key
     * @param mixed  $keys
     */
    public function arrDelete(string key, var keys) -> void
    {
        var arr, item, tmp;

        let arr = this->get(key, []);

        if typeof keys != "array" {
            let tmp = [
                keys
            ];
        } else {
            let tmp = keys;
        }

        for item in tmp {
            if isset arr[item] {
                unset arr[item];
            }
        }

        this->set(key, arr);
    }
    
    /**
     * 取回 session.
     *
     * @param string $name
     * @param mixed  $value
     *
     * @return mxied
     */
    public function get(string name, var value = null)
    {
        var tmp;

        let tmp = this->getNormalizeName(name);

        return isset this->datas[tmp] ? this->datas[tmp] : value;
    }
    
    /**
     * 返回数组部分数据.
     *
     * @param string $name
     * @param mixed  $value
     *
     * @return mixed
     */
    public function getPart(string name, var value = null)
    {
        return this->getPartData(name, value);
    }
    
    /**
     * 删除 session.
     *
     * @param string $name
     */
    public function delete(string name) -> void
    {
        var tmp;

        let tmp = this->getNormalizeName(name);

        if isset this->datas[tmp] {
            unset this->datas[tmp];
        }
    }
    
    /**
     * 是否存在 session.
     *
     * @param string $name
     *
     * @return bool
     */
    public function has(string name) -> bool
    {
        var tmp;

        let tmp = this->getNormalizeName(name);

        return isset this->datas[tmp];
    }
    
    /**
     * 删除 session.
     */
    public function clear() -> void
    {
        let this->datas = [];
    }
    
    /**
     * 闪存一个数据，当前请求和下一个请求可用.
     *
     * @param string $key
     * @param mixed  $value
     */
    public function flash(string key, var value) -> void
    {
        this->set(this->flashDataKey(key), value);

        this->mergeNewFlash([
            key
        ]);

        this->popOldFlash([
            key
        ]);
    }
    
    /**
     * 批量闪存数据，当前请求和下一个请求可用.
     *
     * @param array $flash
     */
    public function flashs(array flash) -> void
    {
        var key, value;
    
        for key, value in flash {
            this->flash(key, value);
        }
    }
    
    /**
     * 闪存一个 flash 用于当前请求使用,下一个请求将无法获取.
     *
     * @param string $key
     * @param mixed  $value
     */
    public function nowFlash(string key, var value) -> void
    {
        this->set(this->flashDataKey(key), value);

        this->mergeOldFlash([
            key
        ]);
    }

    /**
     * 批量闪存数据,用于当前请求使用，下一个请求将无法获取.
     *
     * @param string $key
     * @param mixed  $value
     */
    public function nowFlashs(array flash)
    {
        var key, value;

        for key, value in flash {
            this->nowFlash(key, value);
        }
    }

    /**
     * 保持所有闪存数据.
     */
    public function rebuildFlash() -> void
    {
        this->mergeNewFlash(this->get(this->flashOldKey(), []));

        this->set(this->flashOldKey(), []);
    }
    
    /**
     * 保持闪存数据.
     *
     * @param mixed $keys
     */
    public function keepFlash() -> void
    {
        var keys, args = [];

        let args = func_get_args();

        if empty args {
            throw new BadMethodCallException("Wrong number of parameters.");
        }

        let keys = typeof args[0] === "array" ? args[0] : args;

        this->mergeNewFlash(keys);
        this->popOldFlash(keys);
    }
    
    /**
     * 返回闪存数据.
     *
     * @param string $key
     * @param mixed  $defaults
     *
     * @return mixed
     */
    public function getFlash(string key, var defaults = null)
    {
        if strpos(key, "\\") !== false {
            return this->getPartData(key, defaults, "flash");
        } else {
            return this->get(this->flashDataKey(key), defaults);
        }
    }
    
    /**
     * 删除闪存数据.
     *
     * @param mixed $keys
     */
    public function deleteFlash() -> void
    {
        var item, keys, args = [];

        let args = func_get_args();

        if empty args {
            throw new BadMethodCallException("Wrong number of parameters.");
        }

        let keys = typeof args[0] === "array" ? args[0] : args;

        for item in keys {
            this->delete(this->flashDataKey(item));
        }

        this->mergeOldFlash(keys);
        this->popNewFlash(keys);
    }
    
    /**
     * 清理所有闪存数据.
     */
    public function clearFlash() -> void
    {
        var item, newKey;

        let newKey = this->get(this->flashNewKey(), []);

        for item in newKey {
            call_user_func([this, "deleteFlash"], item);
        }
    }
    
    /**
     * 程序执行结束清理 flash.
     */
    public function unregisterFlash() -> void
    {
        var arr, old, item;

        let arr = this->get(this->flashNewKey(), []);
        let old = this->get(this->flashOldKey(), []);

        for item in old {
            this->delete(this->flashDataKey(item));
        }

        this->delete(this->flashNewKey());
        this->set(this->flashOldKey(), arr);
    }
    
    /**
     * 获取前一个请求地址
     *
     * @return null|string
     */
    public function prevUrl()
    {
        return this->get(this->prevUrlKey());
    }
    
    /**
     * 设置前一个请求地址
     *
     * @param string $url
     */
    public function setPrevUrl(string url)
    {
        this->set(this->prevUrlKey(), url);
    }
    
    /**
     * 终止会话.
     */
    public function destroy() -> void
    {
        this->clear();
        this->connect->destroy(this->getId());

        let this->id = null;
        let this->started = false;
    }
    
    /**
     * session 是否已经启动.
     *
     * @return bool
     */
    public function isStart() -> bool
    {
        return this->started;
    }
    
    /**
     * 设置 SESSION 名字.
     *
     * @param string $name
     */
    public function setName(var name = null) -> void
    {
        let this->name = name ? name : self::SESSION_NAME;
    }
    
    /**
     * 取得 SESSION 名字.
     *
     * @return null|string
     */
    public function getName()
    {
        return this->name;
    }
    
    /**
     * 设置 SESSION ID.
     *
     * @param string $id
     */
    public function setId(var id = null) -> void
    {
        let this->id = id ? id : this->generateSessionId();
    }
    
    /**
     * 取得 SESSION ID.
     *
     * @return null|string
     */
    public function getId()
    {
        return this->id;
    }
    
    /**
     * 重新生成 SESSION ID.
     *
     * @return string
     */
    public function regenerateId() -> string
    {
        let this->id = this->generateSessionId();

        return this->id;
    }
    
    /**
     * 返回连接.
     *
     * @return \SessionHandlerInterface
     */
    public function getConnect() -> <SessionHandlerInterface>
    {
        return this->connect;
    }
    
    /**
     * 生成 SESSION ID.
     *
     * @return string
     */
    protected function generateSessionId() -> string
    {
        return sha1(this->parseMicrotime() . "." . time() . "." . Str::randAlphaNum(32));
    }
    
    /**
     * 生成微秒数.
     *
     * @return string
     */
    protected function parseMicrotime() -> string
    {
        var usec, sec, tmpListUsecSec;
    
        let tmpListUsecSec = explode(" ", microtime());
        let usec = tmpListUsecSec[0];
        let sec = tmpListUsecSec[1];

        return strval((double) usec + (double) sec);
    }
    
    /**
     * 返回 session 名字.
     *
     * @param string $name
     *
     * @return string
     */
    protected function getNormalizeName(string name) -> string
    {
        return name;
    }
    
    /**
     * 载入 session 数据.
     */
    protected function loadData() -> void
    {
        let this->datas = array_merge(this->datas, this->loadDataFromConnect());
    }
    
    /**
     * 从驱动载入 session 数据.
     */
    protected function loadDataFromConnect()
    {
        return this->connect->read(this->getId());
    }
    
    /**
     * 弹出旧闪存 KEY.
     *
     * @param array $keys
     */
    protected function popOldFlash(array keys) -> void
    {
        this->pop(this->flashOldKey(), keys);
    }
    
    /**
     * 合并旧闪存 KEY.
     *
     * @param array $keys
     */
    protected function mergeOldFlash(array keys) -> void
    {
        this->merge(this->flashOldKey(), keys);
    }
    
    /**
     * 弹出新闪存 KEY.
     *
     * @param array $keys
     */
    protected function popNewFlash(array keys) -> void
    {
        this->pop(this->flashNewKey(), keys);
    }
    
    /**
     * 合并新闪存 KEY.
     *
     * @param array $keys
     */
    protected function mergeNewFlash(array keys) -> void
    {
        this->merge(this->flashNewKey(), keys);
    }
    
    /**
     * 返回部分闪存数据.
     *
     * @param string $key
     * @param mixed  $defaults
     * @param string $type
     *
     * @return mixed
     */
    protected function getPartData(string key, var defaults = null, var type = null)
    {
        var name, value, parts, part, tempkeys, tempkey;

        let tempkeys = explode("\\", key);
        let tempkey = array_shift(tempkeys);
        let key = tempkey;
        let name = array_shift(tempkeys);

        if type == "flash" {
            let key = this->flashDataKey(key);
        }

        let value = this->get(key);
        
        if typeof value == "array" {
            if ! strpos(name, ".") {
                return array_key_exists(name, value) ? value[name] : defaults;
            }

            let parts = explode(".", name);

            for part in parts {
                if ! isset value[part] {
                    return defaults;
                }

                let value = value[part];
            }
            
            return value;
        } else {
            return defaults;
        }
    }
    
    /**
     * 闪存值 KEY.
     *
     * @param string $key
     *
     * @return string
     */
    protected function flashDataKey(string key) -> string
    {
        return "flash.data." . key;
    }
    
    /**
     * 新值闪存 KEY.
     *
     * @return string
     */
    protected function flashNewKey() -> string
    {
        return "flash.new.key";
    }
    
    /**
     * 旧值闪存 KEY.
     *
     * @return string
     */
    protected function flashOldKey() -> string
    {
        return "flash.old.key";
    }
    
    /**
     * 前一个页面 KEY.
     *
     * @return string
     */
    protected function prevUrlKey() -> string
    {
        return "prev.url.key";
    }
}
