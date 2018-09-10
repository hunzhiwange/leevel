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

/**
 * twig 模板处理类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.15
 *
 * @version 1.0
 */
class Twig extends Connect implements IConnect
{
    /**
     * 视图分析器.
     *
     * @var \Leevel\View\IParser
     */
    protected parser;
    
    /**
     * 解析 parse.
     *
     * @var callable
     */
    protected parseResolver;
    
    /**
     * 配置.
     *
     * @var array
     */
    protected option = [
        "theme_path" : "",
        "suffix" : ".twig"
    ];
    
    /**
     * 加载视图文件.
     *
     * @param string $file    视图文件地址
     * @param array  $vars
     * @param string $ext     后缀
     * @param bool   $display 是否显示
     *
     * @return void|string
     */
    public function display(string file, array! vars = [], var ext = null, bool display = true)
    {
        var tmpFile;
        
        // 加载视图文件
        let tmpFile = this->parseDisplayFile(file, ext);

        // 变量赋值
        if typeof vars == "array" {
            this->setVar(vars);
        }

        // 返回类型
        if display === false {
            return this->renderFile(tmpFile);
        } else {
            echo this->renderFile(tmpFile);
        }
    }
    
    /**
     * 设置 parse 解析回调.
     *
     * @param callable $parseResolver
     */
    public function setParseResolver(parseResolver) -> void
    {
        let this->parseResolver = parseResolver;
    }
    
    /**
     * 解析 parse.
     *
     * @return \Twig_Environment
     */
    protected function resolverParser()
    {
        if ! (this->parseResolver) {
            throw new RuntimeException("Twig theme not set parse resolver.");
        }

        return call_user_func(this->parseResolver);
    }
    
    /**
     * 获取分析器.
     *
     * @return \Leevel\View\IParser
     */
    protected function parser()
    {
        if this->parser !== null {
            return this->parser;
        }

        let this->parser = this->resolverParser();

        return this->parser;
    }
    
    /**
     * 渲染模板
     *
     * @param string $file
     *
     * @return string
     */
    protected function renderFile(string file) -> string
    {
        var loader, template;
    
        this->parser();

        let loader = this->parser->getLoader();
        loader->setPaths(dirname(file));
        this->parser->setLoader(loader);

        let template = this->parser->load(basename(file));

        return template->render(this->vars);
    }
}
