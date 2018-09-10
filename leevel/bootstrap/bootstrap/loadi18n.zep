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
use Leevel\I18n\I18n;
use Leevel\I18n\Load;
use Leevel\Kernel\IProject;

/**
 * 读取语言包
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.05.03
 * 
 * @version 1.0
 */
class LoadI18n
{
    /**
     * 响应
     * 
     * @param \Leevel\Kernel\IProject $project
     * @return void
     */
    public function handle(<IProject> project)-> void
    {
        var i18nDefault, data, load, i18n;
    
        let i18nDefault = project->make("option")->get("i18n\\default");

        if project->isCachedI18n(i18nDefault) {
            let data = (array) require project->i18nCachedPath(i18nDefault);
        } else {
            let load = (new Load([project->i18nPath()]))->

            setI18n(i18nDefault)->

            addDir(this->getExtend(project));

            let data = load->loadData();
        }

        let i18n = new I18n(i18nDefault);
        project->instance("i18n", i18n);

        i18n->addtext(i18nDefault, data);
    }
    
    /**
     * 获取扩展语言包
     * 
     * @param \Leevel\Kernel\IProject $project
     * @return array
     */
    public function getExtend(<IProject> project)-> array
    {
        var extend, path, item;
        array result = [];
    
        let extend = project->make("option")->get("_composer.i18ns", []);
        let path = project->path();

        for item in extend {
            if ! is_file(item) {
                let item = path . "/" . item;
            }

            if ! is_dir(item) {
                throw new Exception(sprintf("I18n dir %s is not exist.", item));
            }

            let result[] = item;
        }

        return result;
    }
}
