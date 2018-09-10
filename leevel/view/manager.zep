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

use Closure;
use Leevel\View\View;
use Leevel\View\Html;
use Leevel\View\Twig;
use Leevel\View\Phpui;
use Leevel\View\V8js;
use Leevel\Manager\Manager as Managers;

/**
 * view 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.12
 * @version 1.0
 */
class Manager extends Managers
{

    /**
     * 取得配置命名空间
     *
     * @return string
     */
    protected function normalizeOptionNamespace()
    {
        return "view";
    }

    /**
     * 创建连接对象
     *
     * @param object $connect
     * @return object
     */
    protected function createConnect(var connect)
    {
        return new View(connect);
    }

    /**
     * 创建 html 模板驱动
     *
     * @param array $options
     * @return \Leevel\View\Html
     */
    protected function makeConnectHtml(array options = []) -> <Html>
    {
        var parser, html;

        let options = this->normalizeConnectOption("html", options);
        let options = array_merge(options, this->viewOptionCommon());

        let parser = Closure::fromCallable([this, "makeParserClosure"]);

        let html = new Html(options);
        html->setParseResolver(parser);

        return html;
    }

    /**
     * 创建 twig 模板驱动
     *
     * @param array $options
     * @return \Leevel\View\Twig
     */
    protected function makeConnectTwig(array options = []) -> <Twig>
    {
        var parser, twig;

        let options = this->normalizeConnectOption("twig", options);
        let options = array_merge(options, this->viewOptionCommon());

        let parser = Closure::fromCallable([this, "makeTwigParserClosure"]);

        let twig = new Twig(options);
        twig->setParseResolver(parser);

        return twig;
    }

    /**
     * 创建 phpui 模板驱动
     *
     * @param array $options
     * @return \Leevel\View\Phpui
     */
    protected function makeConnectPhpui(array options = []) -> <Phpui>
    {
        let options = this->normalizeConnectOption("phpui", options);
        let options = array_merge(options, this->viewOptionCommon());

        return new Phpui(options);
    }

    /**
     * 创建 v8js 模板驱动
     *
     * @param array $options
     * @return \Leevel\View\V8js
     */
    protected function makeConnectV8js(array options = []) -> <V8js>
    {
        let options = this->normalizeConnectOption("v8js", options);
        let options = array_merge(options, this->viewOptionCommon());

        return new V8js(options);
    }

    /**
     * 视图公共配置
     *
     * @return array
     */
    protected function viewOptionCommon()
    {
        return [
            "theme_path" : this->container->themesPath(),
            "cache_path" : this->container->runtimePath("theme")
        ];
    }

    /**
     * 创建分析器回调
     *
     * @since 2018.01.12
     * @return void
     */
    protected function makeParserClosure()
    {
        return this->container->make("view.parser");
    }

    /**
     * 创建 twig 分析器回调
     *
     * @since 2018.01.15
     * @return void
     */
    protected function makeTwigParserClosure()
    {
        return this->container->make("view.twig.parser");
    }
}
