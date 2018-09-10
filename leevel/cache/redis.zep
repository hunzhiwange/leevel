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

use Leevel\Cache\Redis\IConnect as RedisIConnect;

/**
 * redis 扩展缓存.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.05
 *
 * @version 1.0
 */
class Redis extends Connect implements IConnect
{
    /**
     * 配置.
     *
     * @var array
     */
    protected option = [
        "time_preset" : [],
        "expire" : 86400,
        "serialize" : true
    ];
    
    /**
     * 构造函数.
     *
     * @param \Leevel\Cache\Redis\IConnect $handle
     * @param array                        $option
     */
    public function __construct(<RedisIConnect> handle, array option = []) -> void
    {
        parent::__construct(option);

        let this->handle = handle;
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
    public function get(string name, var defaults = false, array! option = [])
    {
        var data;
    
        let option = this->normalizeOptions(option);

        let data = this->handle->get(this->getCacheName(name));

        if data === false {
            return defaults;
        }

        if option["serialize"] && is_string(data) {
            let data = unserialize(data);
        }

        return data;
    }
    
    /**
     * 设置缓存.
     *
     * @param string $name
     * @param mixed  $data
     * @param array  $option
     */
    public function set(string name, var data, array! option = []) -> void
    {
        let option = this->normalizeOptions(option);

        if option["serialize"] {
            let data = serialize(data);
        }

        let option["expire"] = this->cacheTime(name, intval(option["expire"]));

        this->handle->set(
            this->getCacheName(name), data,
            option["expire"] ? (int) option["expire"] : null
        );
    }
    
    /**
     * 清除缓存.
     *
     * @param string $name
     */
    public function delete(string name) -> void
    {
        this->handle->delete(this->getCacheName(name));
    }
    
    /**
     * 关闭 redis.
     */
    public function close() -> void
    {
        this->handle->close();
    }
}
