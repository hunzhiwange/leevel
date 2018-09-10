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
namespace Leevel\View;

use RuntimeException;
use Leevel\View\Connect;
use Leevel\View\IConnect;

/**
 * html 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2016.11.18
 * @version 1.0
 */
class Html extends Connect implements IConnect
{

    /**
     * 视图分析器
     *
     * @var \Leevel\View\IParserr
     */
    protected parser;

    /**
     * 解析 parser
     *
     * @var callable
     */
    protected parserResolver;

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "theme_path" : "",
        "suffix" : ".html",
        "cache_path" : ""
    ];

    /**
     * 加载视图文件
     *
     * @param string $file 视图文件地址
     * @param array $vars
     * @param string $ext 后缀
     * @param boolean $display 是否显示
     * @return void|string
     */
    public function display(string file, array! vars = [], var ext = null, boolean display = true)
    {
        var cachepath, result, key, value, tmpFile;

        // 加载视图文件
        let tmpFile = this->parseDisplayFile(file, ext);

        // 变量赋值
        if typeof vars == "array" {
            this->setVar(vars);
        }

        if ! empty this->vars {
            for key, value in this->vars {
                let {key} = value;
            }
        }

        let cachepath = this->getCachePath(tmpFile); // 编译文件路径

        if this->isCacheExpired(tmpFile, cachepath) { // 重新编译
            this->parser()->doCompile(tmpFile, cachepath);
        }

        // 返回类型
        if display === false {
            ob_start();
            require cachepath;
            let result = ob_get_contents();
            ob_end_clean();

            return result;
        } else {
            require cachepath;
        }
    }

    /**
     * 设置 parser 解析回调
     *
     * @param callable $parserResolver
     * @return void
     */
    public function setParseResolver(parserResolver)
    {
        let this->parserResolver = parserResolver;
    }

    /**
     * 获取编译路径
     *
     * @param string $file
     * @return string
     */
    public function getCachePath(string file)
    {
        if ! this->option["cache_path"] {
            throw new RuntimeException("Theme cache path must be set.");
        }

        let file = str_replace("//", "/", str_replace("\\", "/", file));

        let file = basename(file, "." . pathinfo(file, PATHINFO_EXTENSION)) . "." . md5(file) . ".php";

        return this->option["cache_path"] . "/" . file;
    }

    /**
     * 解析 parser
     *
     * @return \Leevel\View\IParserr
     */
    protected function resolverParser()
    {
        if ! this->parserResolver {
            throw new RuntimeException("Html theme not set parse resolver.");
        }

        return call_user_func(this->parserResolver);
    }

    /**
     * 获取分析器
     *
     * @return \Leevel\View\IParserr
     */
    protected function parser()
    {
        if typeof this->parser != "null" {
            return this->parser;
        }

        let this->parser = this->resolverParser();

        return this->parser;
    }

    /**
     * 判断缓存是否过期
     *
     * @param string $file
     * @param string $cachepath
     * @return boolean
     */
    protected function isCacheExpired(string file, string cachepath)
    {
        if ! is_file(cachepath) {
            return true;
        }

        if filemtime(file) >= filemtime(cachepath) {
            return true;
        }

        return false;
    }
}
