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

use Leevel\Option\Load;
use Leevel\Option\Option;
use Leevel\Support\Facade;
use Leevel\Kernel\IProject;

/**
 * 读取配置
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.04.24
 * 
 * @version 1.0
 */
class LoadOption
{
    /**
     * 响应
     * 
     * @param \Leevel\Kernel\IProject $project
     * @return void
     */
    public function handle()
    {
        var data, load, option, test, args, project;

        let args = func_get_args();
        let project = args[0];
    
        if project->isCachedOption() {
            let data = (array)require project->optionCachedPath();
            this->setEnvs(data["app"]["_env"]);
        } else {
            let load = new Load(project->optionPath());
            let data = load->loadData(project);
        }

        let option = new Option(data);
        project->instance("option", option);

        let test = 2 === func_num_args();

        if (! test) {
            Facade::setContainer(project);

            this->initialization(option);
        }
    }
    
    /**
     * 初始化处理
     *
     * @param array $env
     * @return void
     */
    protected function setEnvs(array env)
    {
        var name, value;
    
        for name, value in env {
            this->setEnvVar(name, value);
        }
    }
    
    /**
     * 设置环境变量
     *
     * @param string $name
     * @param string|null $value
     * @return void
     */
    protected function setEnvVar(string name, var value = null)
    {
        if is_bool(value) {
            putenv(name . "=" . (value ? "(true)" : "(false)"));
        } elseif is_null(value) {
            putenv(name . "(null)");
        } else {
            putenv(name . "=" . value);
        }

        let _ENV[name] = value;
        let _SERVER[name] = value;
    }
    
    /**
     * 初始化处理
     *
     * @param \Leevel\Option\Option $option
     * @return void
     */
    protected function initialization(<Option> option)
    {
        mb_internal_encoding("UTF-8");

        if function_exists("date_default_timezone_set") {
            date_default_timezone_set(option->get("time_zone", "UTC"));
        }

        if "cli" == PHP_SAPI {
            return;
        }

        if function_exists("gz_handler") && option->get("start_gzip") {
            ob_start("gz_handler");
        } else {
            ob_start();
        }
    }
}
