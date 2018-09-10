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

/**
 * 文件缓存.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.02.15
 *
 * @version 1.0
 */
class File extends Connect implements IConnect
{
    /**
     * 缓存文件头部.
     *
     * @var string
     */
    const HEADER = "<?php die(%s); ?>";

    /**
     * 缓存文件头部长度.
     *
     * @var int
     */
    const HEADER_LENGTH = 41;

    /**
     * 配置.
     *
     * @var array
     */
    protected option = [
        "time_preset" : [],
        "expire" : 86400,
        "path" : "",
        "serialize" : true
    ];
    
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
        var cachePath, fp, len, data;
    
        let option = this->normalizeOptions(option);
        let cachePath = this->getCachePath(name);

        // 清理文件状态缓存 http://php.net/manual/zh/function.clearstatcache.php
        clearstatcache();

        if ! (is_file(cachePath)) {
            return false;
        }

        if ! (is_readable(cachePath)) {
            throw new InvalidArgumentException("Cache path is not readable.");
        }

        let fp = fopen(cachePath, "rb");
        flock(fp, LOCK_SH);

        // 头部的 41 个字节存储了安全代码
        let len = filesize(cachePath);
        fread(fp, self::HEADER_LENGTH);
        let len -= self::HEADER_LENGTH;

        do {
            // 检查缓存是否已经过期
            if this->isExpired(name, option) {
                let data = false;
                break;
            }

            if len > 0 {
                let data = fread(fp, len);
            } else {
                let data = false;
            }
        } while (false);

        flock(fp, LOCK_UN);
        fclose(fp);

        if data === false {
            return false;
        }

        // 解码
        if option["serialize"] {
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
        var cachePath;
    
        let option = this->normalizeOptions(option);

        if option["serialize"] {
            let data = serialize(data);
        }

        let data = sprintf(self::HEADER, "/* " . date("Y-m-d H:i:s") . "  */") . data;

        let cachePath = this->getCachePath(name);

        this->writeData(cachePath, data);
    }
    
    /**
     * 清除缓存.
     *
     * @param string $name
     */
    public function delete(string name) -> void
    {
        var cachePath;
    
        let cachePath = this->getCachePath(name);

        if this->exist(name) {
            unlink(cachePath);
        }
    }
    
    /**
     * 关闭.
     */
    public function close() -> void
    {
    }
    
    /**
     * 验证缓存是否过期
     *
     * @param string $name
     * @param array  $option
     *
     * @return bool
     */
    protected function isExpired(string name, array! option) -> bool
    {
        var filePath;
    
        let filePath = this->getCachePath(name);

        let option["expire"] = this->cacheTime(name, intval(option["expire"]));

        if option["expire"] <= 0 {
            return true;
        }

        return filemtime(filePath) + (int) option["expire"] < time();
    }
    
    /**
     * 获取缓存路径.
     *
     * @param string $name
     *
     * @return string
     */
    protected function getCachePath(string name) -> string
    {
        if ! (this->option["path"]) {
            throw new InvalidArgumentException("Cache path is not allowed empty.");
        }

        return this->option["path"] . "/" . this->getCacheName(name) . ".php";
    }
    
    /**
     * 写入缓存数据.
     *
     * @param string $fileName
     * @param string $data
     */
    protected function writeData(string fileName, string data) -> void
    {
        var dirname;
    
        let dirname = dirname(fileName);

        if ! (is_dir(dirname)) {
            if is_dir(dirname(dirname)) && ! (is_writable(dirname(dirname))) {
                throw new InvalidArgumentException(
                    sprintf("Unable to create the %s directory.", dirname)
                );
            }

            mkdir(dirname, 0777, true);
        }

        if ! (is_writable(dirname)) ||
            ! (file_put_contents(fileName, data, LOCK_EX)) {
            throw new InvalidArgumentException(
                sprintf("Dir %s is not writeable.", dirname)
            );
        }

        chmod(fileName, 0666);
    }
    
    /**
     * 验证缓存是否存在.
     *
     * @param string $name
     *
     * @return bool
     */
    protected function exist(string name) -> bool
    {
        return is_file(this->getCachePath(name));
    }
    
    /**
     * 获取缓存名字
     * 去掉特殊缓存名字字符.
     *
     * @param string $name
     *
     * @return string
     */
    protected function getCacheName(string name) -> string
    {
        return str_replace([
            "?",
            "*",
            ":",
            "\"",
            "<",
            ">",
            "\\",
            "/",
            "|"
        ], ".", parent::getCacheName(name));
    }
}
