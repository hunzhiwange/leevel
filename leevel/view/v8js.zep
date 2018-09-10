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
use V8Js as V8Jss;
use Closure;

/**
 * v8 模板处理类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.10
 *
 * @version 1.0
 * @codeCoverageIgnore
 */
class V8js extends Connect implements IConnect
{
    /**
     * 配置.
     *
     * @var array
     */
    protected option = [
        "theme_path" : "",
        "suffix" : ".js",

        // node_modules/vue/dist/vue.js
        "vue_path" : "node_modules/vue/dist/vue.js",

        // node_modules/vue-server-renderer/basic.js
        "vue_renderer" : "node_modules/vue-server-renderer/basic.js",

        // node_modules/art-template/lib/template-web.js
        "art_path" : "node_modules/art-template/lib/template-web.js"
    ];
    
    /**
     * v8js.
     *
     * @var \V8Js
     */
    protected v8js;
    
    /**
     * 构造函数.
     *
     * @param array $option
     *
     * @see http://php.net/manual/zh/book.v8js.php
     */
    public function __construct(array option = []) -> void
    {
        var item, method;
    
        if ! (extension_loaded("v8js")) {
            throw new RuntimeException("Please install php v8js extension.");
        }

        parent::__construct(option);

        let this->v8js = new V8Jss("$");

        for item in ["base", "dd", "dump", "echo", "html", "load", "module"] {
            let method = "init" . ucwords(item);
            this->{method}();
        }
    }
    
    /**
     * 返回 V8js.
     *
     * @return \V8js
     */
    public function getV8js() -> <V8Jss>
    {
        return this->v8js;
    }
    
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
        var key, value, source, tmpFile;
    
        // 加载视图文件
        let tmpFile = this->parseDisplayFile(file, ext);

        // 传递变量
        if typeof vars == "array" {
            this->setVar(vars);
        }

        for key, value in this->vars {
            this->setV8jsProp(key, value);
        }

        let source = file_get_contents(tmpFile);

        // 返回类型
        if display === false {
            return this->select(source);
        }

        return this->execute(source);
    }
    
    /**
     * 执行 js 并返回输入文本.
     *
     * @param string $js
     *
     * @return string
     */
    public function select(string js) -> string
    {
        ob_start();
        this->v8js->executeString(js);
        return ob_get_clean();
    }
    
    /**
     * 执行 js.
     *
     * @param string $js
     *
     * @return mixed
     */
    public function execute(string js)
    {
        return this->v8js->executeString(js);
    }
    
    /**
     * initDd.
     * 调试会导致 cli 中断.
     *
     * @codeCoverageIgnore
     */
    public function initDd() -> void
    {
        this->setV8jsProp("$dd", Closure::fromCallable([this, "initDdClosure"]));

        this->execute("this.dd = this.$dd = $.$dd;");
    }

    /**
     * 创建 initDd 闭包
     * 
     * @param mixed $message
     */
    protected function initDdClosure(var message)
    {
        dd(message);
    }
    
    /**
     * initDump.
     */
    public function initDump() -> void
    {
        this->setV8jsProp("$dump", Closure::fromCallable([this, "initDumpClosure"]));

        this->execute("this.dump = this.$dump = $.$dump;");
    }

    /**
     * 创建 initDump 闭包
     * 
     * @param mixed $message
     */
    protected function initDumpClosure(var message)
    {
        var_dump(message);
    }
    
    /**
     * initEcho.
     */
    public function initEcho() -> void
    {
        this->setV8jsProp("$echo", Closure::fromCallable([this, "initEchoClosure"]));

        this->execute("this.echo = this.$echo = $.$echo;");
    }

    /**
     * 创建 initEcho 闭包
     * 
     * @param mixed $message
     */
    protected function initEchoClosure(var message)
    {
        echo message;
    }
    
    /**
     * initHtml.
     */
    public function initHtml()
    {
        this->setV8jsProp("$html", Closure::fromCallable([this, "initHtmlClosure"]));

        this->execute("this.html = this.$html = $.$html;");
    }

    /**
     * 创建 initHtml 闭包
     * 
     * @param string $package
     * @param string $package
     *
     * @return string
     */
    protected function initHtmlClosure(string path, string ext = ".html") -> string
    {
        var file;

        let file = this->parseDisplayFile(path, ext);

        return file_get_contents(file);
    }
    
    /**
     * initLoad.
     */
    public function initLoad() -> void
    {
        this->setV8jsProp("$load", Closure::fromCallable([this, "initLoadClosure"]));

        this->execute("this.load = this.$load = $.$load;");
    }

    /**
     * 创建 initLoad 闭包
     * 
     * @param string $package
     */
    protected function initLoadClosure(var package)
    {
        let package .= "Package";

        if ! (method_exists(this, package)) {
            throw new RuntimeException(
                "Package is not preset, we just support vue and art."
            );
        }

        this->{package}();
    }
    
    /**
     * initModule.
     */
    public function initModule()
    {
        this->v8js->setModuleNormaliser(Closure::fromCallable([this, "moduleNormaliserClosure"]));

        this->v8js->setModuleLoader(Closure::fromCallable([this, "moduleLoaderClosure"]));
    }

    /**
     * 创建模块格式化闭包
     * 
     * @param string $base
     * @param string $module
     * 
     * @return array
     */
    protected function moduleNormaliserClosure(var base, var module) -> array
    {
        try {
            let module = this->parseDisplayFile(module);
        } catch RuntimeException {
            let module = this->parseDisplayFile(module."/index");
        }

        return ["", module];
    }

    /**
     * 创建模块载入闭包
     * 
     * @param string $module
     * 
     * @return string
     */
    protected function moduleLoaderClosure(string module)
    {
        return file_get_contents(module);
    }
    
    /**
     * initBase.
     */
    protected function initBase() -> void
    {
        this->execute("/*!
 * console.js v0.2.0 (https://github.com/yanhaijing/console.js)
 * Copyright 2013 yanhaijing. All Rights Reserved
 * Licensed under MIT (https://github.com/yanhaijing/console.js/blob/master/MIT-LICENSE.txt)
 */
;(function(g) {
    'use strict';
    var _console = g.console || {};
    var methods = ['assert', 'clear', 'count', 'debug', 'dir', 'dirxml', 'exception', 'error', 'group', 'groupCollapsed', 'groupEnd', 'info', 'log', 'profile', 'profileEnd', 'table', 'time', 'timeEnd', 'timeStamp', 'trace', 'warn'];

    var console = {version: '0.2.0'};
    var key;
    for(var i = 0, len = methods.length; i < len; i++) {
        key = methods[i];
        console[key] = function (key) {
            var method = key;
            return function () {
                if (method == 'log') {
                    $.$dd(arguments[0]);
                } else {
                    print(arguments[0]);
                    print('<br />');
                }
            };           
        }(key);
    }
    
    g.console = console;
}(this));");
    }

    /**
     * 设置 v8js 属性.
     *
     * @param string $name
     * @param mixed $value
     */
    public function setV8jsProp(string name, var value)
    {
        this->v8js->__set(name, value);
    }
    
    /**
     * 初始化 vue.
     */
    protected function vuePackage() -> void
    {
        var vue, renderer;
    
        let vue = this->option["vue_path"];
        let renderer = this->option["vue_renderer"];

        if ! (is_file(vue)) {
            throw new RuntimeException(
                sprintf("Vue path %s is not exits, please use npm install.", vue)
            );
        }

        if ! (is_file(renderer)) {
            throw new RuntimeException(
                sprintf("Vue renderer %s is not exits, please use npm install.", renderer)
            );
        }

        this->execute("delete this.window; this.global = { process: { env: { VUE_ENV: \"server\", NODE_ENV: \"production\" } } };");
        this->execute(file_get_contents(vue));
        this->execute(file_get_contents(renderer));
    }
    
    /**
     * 初始化 art.
     */
    protected function artPackage() -> void
    {
        var art;
    
        let art = this->option["art_path"];

        if ! (is_file(art)) {
            throw new RuntimeException(
                sprintf("Art path %s is not exits, please use npm install.", art)
            );
        }

        this->execute("this.window = null;");
        this->execute(file_get_contents(art));
        this->execute("delete this.window;");
    }
}
