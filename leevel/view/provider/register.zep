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

namespace Leevel\View\Provider;

use Closure;
use Leevel\Di\IContainer;
use Leevel\Di\Provider;
use Leevel\Kernel\IProject;
use Leevel\View\Compiler;
use Leevel\View\Manager;
use Leevel\View\Parser;
use Twig_Environment;
use Twig_Loader_Filesystem;

/**
 * view 服务提供者.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.05.12
 *
 * @version 1.0
 */
class Register extends Provider
{
    /**
     * 创建一个服务容器提供者实例
     *
     * @param \Leevel\Di\IContainer $container
     * @return void
     */
    public function __construct(<IContainer> container)
    {
        parent::__construct(container);
    }

    /**
     * 注册服务
     *
     * @return void
     */
    public function register()
    {
        this->viewViews();
        this->viewView();
        this->viewCompiler();
        this->viewParser();
        this->viewTwigParser();
    }
    
    /**
     * 可用服务提供者
     *
     * @return array
     */
    public static function providers() -> array
    {
        return [
            "view.views" : [
                "Leevel\\View\\Manager"
            ], 
            "view.view" : [
                "Leevel\\View\\View", 
                "Leevel\\View\\IView"
            ], 
            "view.compiler" : [
                "Leevel\\View\\Compiler", 
                "Leevel\\View\\ICompiler"
            ], 
            "view.parser" : [
                "Leevel\\View\\Parser", 
                "Leevel\\View\\IParser"
            ], 
            "view.twig.parser"
        ];
    }
    
    /**
     * 注册 view.views 服务
     *
     * @return void
     */
    protected function viewViews()
    {
        this->container->singleton("view.views", Closure::fromCallable([this, "viewViewsClosure"]));
    }

    /**
     * 创建 view.views 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\View\Manager
     */
    protected function viewViewsClosure(<IContainer> container)
    {
        return new Manager(container);
    }
    
    /**
     * 注册 view.view 服务
     *
     * @return void
     */
    protected function viewView()
    {
        this->container->singleton("view.view", Closure::fromCallable([this, "viewViewClosure"]));
    }

    /**
     * 创建 view.view 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return object
     */
    protected function viewViewClosure(<IContainer> container)
    {
        return container->make("view.views")->connect();
    }
    
    /**
     * 注册 view.compiler 服务
     *
     * @return void
     */
    protected function viewCompiler()
    {
        this->container->singleton("view.compiler", Closure::fromCallable([this, "viewCompilerClosure"]));
    }

    /**
     * 创建 view.compiler 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\View\Compiler
     */
    protected function viewCompilerClosure(<IContainer> container)
    {
        return new Compiler();
    }
    
    /**
     * 注册 view.parser 服务
     *
     * @return void
     */
    protected function viewParser()
    {
        this->container->singleton("view.parser", Closure::fromCallable([this, "viewParserClosure"]));
    }

    /**
     * 创建 view.parser 闭包
     * 
     * @param \Leevel\Di\IContainer $container
     * @return \Leevel\View\Parser
     */
    protected function viewParserClosure(<IContainer> container)
    {
        return (new Parser(container->make("view.compiler")))->

        registerCompilers()->

        registerParsers();
    }
    
    /**
     * 注册 view.twig.parser 服务
     *
     * @return void
     */
    protected function viewTwigParser()
    {
        this->container->singleton("view.twig.parser", Closure::fromCallable([this, "viewTwigParserClosure"]));
    }

    /**
     * 创建 view.twig.parser 闭包
     * 
     * @param \Leevel\Kernel\IProject $project
     * @return \Twig_Environment
     */
    protected function viewTwigParserClosure(<IProject> project)
    {
        return new Twig_Environment(new Twig_Loader_Filesystem(), [
            "auto_reload" : true, 
            "debug" : false,
            "strict_variables" : true,
            "cache" : project->runtimePath("theme")
        ]);
    }
}
