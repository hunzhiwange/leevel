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
namespace Leevel\Bootstrap\Bootstrap;

use Exception;
use ErrorException;
use Leevel\Kernel\IProject;
use Leevel\Bootstrap\Runtime\Runtime;
use Symfony\Component\Console\Output\ConsoleOutput;

/**
 * 注册运行时异常
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.04.25
 * 
 * @version 1.0
 */
class RegisterRuntime
{
    /**
     * 容器
     *
     * @var \Leevel\Di\IProject
     */
    protected project;
    
    /**
     * 响应
     * 
     * @param \Leevel\Kernel\IProject $project
     * @return void
     */
    public function handle()
    {
        var test, args, project;

        let args = func_get_args();
        let project = args[0];
        let this->project = project;

        let test = 2 === func_num_args();

        if (! test) {
            error_reporting(E_ALL);
        
            set_error_handler([this, "setErrorHandle"]);

            set_exception_handler([this, "setExceptionHandler"]);

            register_shutdown_function([this, "registerShutdownFunction"]);

            if project->environment() === "production" {
                ini_set("display_errors", "Off");
            }
        }
    }
    
    /**
     * 设置错误句柄
     * 
     * @param integer $code
     * @param string $description
     * @param string $file
     * @param interger $line
     * @param mixed $context
     * @return void
     */
    public function setErrorHandle(int code, string description, var file = null, var line = null, var context = null)
    {
        // 根据 error_reporing 等级来确定是否抛出错误
        if ! (error_reporting() & code) {
            return;
        }
        
        throw new ErrorException(description, 0, code, file, line);
    }
    
    /**
     * 设置退出句柄
     *
     * @return void
     */
    public function registerShutdownFunction()
    {
        var error;
    
        let error = error_get_last();

        if error && ! empty error["type"] {
            this->setExceptionHandler(this->formatErrorException(error));
        }
    }
    
    /**
     * 响应异常
     *
     * @param \Throwable $e
     * @return void
     */
    public function setExceptionHandler(var e)
    {
        var fatalException;

        if ! (e instanceof Exception) {
            let fatalException = new ErrorException(     
                e->getMessage(),
                e->getCode(),
                E_ERROR,
                e->getFile(),
                e->getLine(),
                e->getPrevious()
            );
        } else {
            let fatalException = e;
        }

        try {
            this->getRuntime()->report(fatalException);
        } catch Exception {
        }

        if this->project->console() {
            this->renderConsoleResponse(fatalException);
        } else {
            this->renderHttpResponse(fatalException);
        }
    }
    
    /**
     * 渲染命令行异常并输出
     *
     * @param \Exception $e
     * @return void
     */
    protected function renderConsoleResponse(<Exception> e)
    {
        this->getRuntime()->renderForConsole(new ConsoleOutput(), e);
    }
    
    /**
     * 渲染 HTTP 异常并输出
     *
     * @param \Exception $e
     * @return void
     */
    protected function renderHttpResponse(<Exception> e)
    {
        this->getRuntime()->render(this->project->make("request"), e)->send();
    }
    
    /**
     * 格式化致命错误信息
     *
     * @param array $error
     * @return \ErrorException
     */
    protected function formatErrorException(array error)
    {
        return new ErrorException(
            error["message"], error["type"], 0, error["file"], error["line"]
        );
    }
    
    /**
     * 返回运行处理器
     * 
     * @return \Leevel\Kernel\Exception\IRuntime
     */
    protected function getRuntime()
    {
        return this->project->make("Leevel\\Kernel\\Runtime\\IRuntime");
    }
}
