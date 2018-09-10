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

namespace Leevel\Cache;

use InvalidArgumentException;
use Leevel\Di\IContainer;

/**
 * cache 快捷载入.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.11.20
 *
 * @version 1.0
 */
class Load
{
    /**
     * IOC Container.
     *
     * @var \Leevel\Di\IContainer
     */
    protected container;
    
    /**
     * cache 仓储.
     *
     * @var \Leevel\Cache\ICache
     */
    protected cache;
    
    /**
     * 已经载入的缓存数据.
     *
     * @var array
     */
    protected cacheLoaded = [];
    
    /**
     * 构造函数.
     *
     * @param \Leevel\Di\IContainer $container
     * @param \Leevel\Cache\ICache  $cache
     */
    public function __construct(<IContainer> container, <ICache> cache) -> void
    {
        let this->container = container;
        let this->cache = cache;
    }
    
    /**
     * 切换缓存仓储.
     *
     * @param \Leevel\Cache\ICache $cache
     */
    public function switchCache(<ICache> cache) -> void
    {
        let this->cache = cache;
    }
    
    /**
     * 返回缓存仓储.
     *
     * @return \Leevel\Cache\ICache
     */
    public function getCache() -> <ICache>
    {
        return this->cache;
    }
    
    /**
     * 载入缓存数据
     * 系统自动存储缓存到内存，可重复执行不会重复载入数据.
     *
     * @param array|string $names
     * @param array        $option
     * @param bool         $force
     *
     * @return array
     */
    public function data(var names, array! option = [], bool force = false) -> array
    {
        var name, result, tmpNames;
    
        let tmpNames = is_array(names) ? names : [names];

        for name in tmpNames {
            if ! (isset this->cacheLoaded[name]) || force {
                let this->cacheLoaded[name] = this->cache(name, option, force);
            }
        }

        let result = [];

        for name in tmpNames {
            let result[name] = this->cacheLoaded[name];
        }

        return count(result) > 1 ? result : reset(result);
    }
    
    /**
     * 刷新缓存数据.
     *
     * @param array|string $names
     */
    public function refresh(var names) -> void
    {
        var name, tmpNames;
    
        let tmpNames = is_array(names) ? names : [names];

        for name in tmpNames {
            this->delete(name);
        }
    }
    
    /**
     * 从载入缓存数据中获取
     * 不存在不用更新缓存，返回 false.
     *
     * @param array|string $names
     * @param mixed        $force
     *
     * @return array
     */
    public function dataLoaded(var names, array! option = [], bool force = false) -> array
    {
        var result, name, tmpNames;
    
        let result = [];

        let tmpNames = is_array(names) ? names : [names];

        for name in tmpNames {
            let result[name] = array_key_exists(name, this->cacheLoaded) ?
                this->cacheLoaded[name] :
                false;
        }

        return  count(result) > 1 ? result : reset(result);
    }
    
    /**
     * 删除缓存数据.
     *
     * @param string $name
     */
    protected function delete(string name) -> void
    {
        this->deletePersistence(name);
    }
    
    /**
     * 读取缓存数据.
     *
     * @param string $name
     * @param array  $option
     * @param bool   $force
     *
     * @return mixed
     */
    protected function cache(string name, array! option = [], bool force = false)
    {
        var data;
    
        if force === false {
            let data = this->getPersistence(name, false, option);
        } else {
            let data = false;
        }

        if data === false {
            let data = this->update(name, option);
        }

        return data;
    }
    
    /**
     * 更新缓存数据.
     *
     * @param string $name
     * @param array  $option
     *
     * @return mixed
     */
    protected function update(string name, array! option = [])
    {
        var sourceName, tempName, params, tmpListNameParams, method, tmpListNameMethod, cache, tempCallback, sourceData;
    
        let sourceName = name;
        let tmpListNameParams = this->parse(name);
        let tempName = tmpListNameParams[0];
        let params = tmpListNameParams[1];

        if strpos(tempName, "@") !== false {
            let tmpListNameMethod = explode("@", tempName);
            let tempName = tmpListNameMethod[0];
            let method = tmpListNameMethod[1];
        } else {
            let method = "handle";
        }

        let cache = this->container->make(tempName);

        if ! (is_object(cache)) {
            throw new InvalidArgumentException(
                sprintf("Cache %s is not valid.", tempName)
            );
        }

        let tempCallback = [cache, method];

        if ! (is_callable(tempCallback)) {
            throw new InvalidArgumentException(
                sprintf("Cache %s is not a callable.", tempName . "@" . method)
            );
        }

        let sourceData = call_user_func_array(tempCallback, params);

        this->setPersistence(sourceName, sourceData, option);

        return sourceData;
    }
    
    /**
     * 获取缓存.
     *
     * @param string $name
     * @param mixed  $defaults
     * @param array  $option
     *
     * @return mixed
     */
    protected function getPersistence(string name, var defaults = false, array! option = [])
    {
        return this->cache->get(name, defaults, option);
    }
    
    /**
     * 设置缓存.
     *
     * @param string $name
     * @param mixed  $data
     * @param array  $option
     */
    protected function setPersistence(string name, var data, array! option = []) -> void
    {
        this->cache->set(name, data, option);
    }
    
    /**
     * 清除缓存.
     *
     * @param string $name
     */
    protected function deletePersistence(string name) -> void
    {
        this->cache->delete(name);
    }
    
    /**
     * 解析缓存.
     *
     * @param string $name
     *
     * @return array
     */
    protected function parse(string name) -> array
    {
        var args, temp, tempName, key, item;
        array newArgs = [];

        let temp = array_pad(explode(":", name, 2), 2, []);
        let tempName = temp[0];
        let args = temp[1];

        if typeof args == "string" {
            let args = explode(",", args);
        }

        for key, item in args {
            let newArgs[key] = ctype_digit(item) ? intval(item) : item;
        }

        return [
            tempName,
            newArgs
        ];
    }
}
