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
namespace Leevel\Support\Debug;

/**
 * 调试
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.05
 * @version 1.0
 */
class Console
{
    /**
     * 记录调试信息
     * SQL 记录，加载文件等等
     *
     * @param array $log
     * @return string
     */
    public static function trace(array log) -> string
    {
        var trace, include;
    
        // swoole http server 可以调试
        if "cli" == PHP_SAPI && ! ((isset _SERVER["SERVER_SOFTWARE"] && _SERVER["SERVER_SOFTWARE"] == "swoole-http-server")) {
            return;
        }

        // ajax 不调试
        if isset _SERVER["HTTP_X_REQUESTED_WITH"] && strtolower(_SERVER["HTTP_X_REQUESTED_WITH"]) == "xmlhttprequest" {
            return;
        }

        let trace = self::normalizeLog(log);
        let include = get_included_files();
        let trace["LOADED.FILE" . " (" . count(include) . ")"] = implode("\\n", include);

        return self::getOutputToConsole(trace);
    }
    
    /**
     * JSON 记录调试信息
     * SQL 记录，加载文件等等
     *
     * @param array $log
     * @return array
     */
    public static function jsonTrace(array log) -> array
    {
        var trace, include;
    
        let trace = self::normalizeLog(log);
        let include = get_included_files();
        let trace["LOADED.FILE" . " (" . count(include) . ")"] = include;

        return trace;
    }
    
    /**
     * 返回输出到浏览器
     *
     * @param array $trace
     * @return string
     */
    protected static function getOutputToConsole(array trace) -> string
    {
        var content, key, item;
    
        let content = [];
        let content[] = "<script type=\"text/javascript\">
console.log( '%cThe PHP Framework For Code Poem As Free As Wind %c(http://www.queryphp.com)', 'font-weight: bold;color: #06359a;', 'color: #02d629;' );";
        for key, item in trace {
            if is_string(key) {
                let content[] = "console.log('');";
                let content[] = "console.log('%c " . key . "', 'color: blue; background: #045efc; color: #fff; padding: 8px 15px; -moz-border-radius: 15px; -webkit-border-radius: 15px; border-radius: 15px;');";
                let content[] = "console.log('');";
            }

            if item {
                let content[] = "console.log('%c" . item . "', 'color: gray;');";
            }
        }
        let content[] = "</script>";

        return implode("", content);
    }
    
    /**
     * 格式化日志信息
     *
     * @param array $log
     * @return array
     */
    protected static function normalizeLog(array log) -> array
    {
        var result, type, item;
    
        let result = [];

        for type, item in log {
            let result[strtoupper(type) . ".LOG" . " (" . count(item) . ")"] = implode("\\n", self::formatMessages(item));
        }

        return result;
    }

    /**
     * 格式化一组日志信息
     *
     * @param array $messages
     * @return array
     */
    protected static function formatMessages(array messages) -> array
    {
        var item;
        array result = [];

        for item in messages {
            let result[] = self::formatMessage(item);
        }

        return result;
    }
    
    /**
     * 格式化日志信息
     *
     * @param array $item
     * @return string
     */
    protected static function formatMessage(array item) -> string
    {
        return addslashes(item[0] . " " . json_encode(item[1], JSON_UNESCAPED_UNICODE));
    }
}
