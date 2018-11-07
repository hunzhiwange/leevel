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

namespace Leevel\Database;

use Leevel\Manager\Manager as Managers;

/**
 * database 入口.
 *
 * @method $this whereNull(...$arr)
 * @method $this whereNotNull(...$arr)
 * @method $this whereBetween(...$arr)
 * @method $this whereNotBetween(...$arr)
 * @method $this whereIn(...$arr)
 * @method $this whereNotIn(...$arr)
 * @method $this whereLike(...$arr)
 * @method $this whereNotLike(...$arr)
 * @method $this havingNull(...$arr)
 * @method $this havingNotNull(...$arr)
 * @method $this havingBetween(...$arr)
 * @method $this havingNotBetween(...$arr)
 * @method $this havingIn(...$arr)
 * @method $this havingNotIn(...$arr)
 * @method $this havingLike(...$arr)
 * @method $this havingNotLike(...$arr)
 * @method $this innerJoin($table, $cols, $cond)
 * @method $this leftJoin($table, $cols, $cond)
 * @method $this rightJoin($table, $cols, $cond)
 * @method $this fullJoin($table, $cols, $cond)
 * @method $this crossJoin($table, $cols)
 * @method $this naturalJoin($table, $cols)
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.02.15
 *
 * @version 1.0
 */
class Manager extends Managers
{
    /**
     * 取得配置命名空间.
     *
     * @return string
     */
    protected function normalizeOptionNamespace() -> string
    {
        return "database";
    }
    
    /**
     * 创建连接对象
     *
     * @param object $connect
     *
     * @return object
     */
    protected function createConnect(connect)
    {
        return new Database(connect);
    }
    
    /**
     * 创建 mysql 连接.
     *
     * @param array $option
     *
     * @return \Leevel\Database\Mysql
     */
    protected function makeConnectMysql(array option = [])
    {
        return new Mysql(this->normalizeConnectOption("mysql", option));
    }
    
    /**
     * 读取默认配置.
     *
     * @param string $connect
     * @param array  $extendOption
     *
     * @return array
     */
    protected function normalizeConnectOption(string connect, array extendOption = []) -> array
    {
        return this->parseDatabaseOption(
            parent::normalizeConnectOption(connect, extendOption)
        );
    }
    
    /**
     * 分析数据库配置参数.
     *
     * @param array $option
     *
     * @return array
     */
    protected function parseDatabaseOption(array option) -> array
    {
        var temp, type, tmp, slave, tmp2;
    
        let temp = option;

        for type in array_keys(option) {
            let tmp = ["distributed", "separate", "driver", "master", "slave"];

            if in_array(type, tmp, true) {
                if isset temp[type] {
                    unset temp[type];
                }
            } else {
                if isset option[type] {
                    unset option[type];
                }
            }
        }

        for type in ["master", "slave"] {
            if ! (is_array(option[type])) {
                let option[type] = [];
            }
        }

        let option["master"] = array_merge(option["master"], temp);

        if ! (option["distributed"]) {
            let option["slave"] = [];
        } elseif option["slave"] {
            if count(option["slave"]) === count(option["slave"], COUNT_RECURSIVE) {
                let tmp2 = [option["slave"]];
                let option["slave"] = tmp2;
            }

            for slave in option["slave"] {
                let slave = array_merge(slave, temp);
            }
        }

        return option;
    }
}
