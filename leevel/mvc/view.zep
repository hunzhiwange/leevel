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
namespace Leevel\Mvc;

use Leevel\Mvc\IView;
use Leevel\View\IView as IViews;

/**
 * 视图
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.02
 * @version 1.0
 */
class View implements IView
{

    /**
     * 视图模板
     *
     * @var \Queryyessimple\View\IView
     */
    protected theme;

    /**
     * 构造函数
     *
     * @param \Leevel\View\IView $theme
     * @return void
     */
    public function __construct(<IViews> theme)
    {
        let this->theme = theme;
    }

    /**
     * 切换视图
     *
     * @param \Leevel\View\IView $theme
     * @return $this
     */
    public function switchView(<IViews> theme)
    {
        var assign;

        let assign = this->getAssign();
        let this->theme = theme;
        this->assign(assign);

        return this;
    }

    /**
     * 变量赋值
     *
     * @param mixed $name
     * @param mixed $value
     * @return $this
     */
    public function assign(var name, var value = null)
    {
        this->theme->setVar(name, value);

        return this;
    }

    /**
     * 获取变量赋值
     *
     * @param string|null $name
     * @return mixed
     */
    public function getAssign(var name = null)
    {
        return this->theme->getVar(name);
    }

    /**
     * 删除变量值
     *
     * @param mixed $name
     * @return $this
     */
    public function deleteAssign()
    {
        var args;

        let args = func_get_args();

        call_user_func_array([
            this->theme,
            "deleteVar"
        ], args);

        return this;
    }

    /**
     * 清空变量值
     *
     * @param string|null $name
     * @return $this
     */
    public function clearAssign()
    {
        this->theme->clearVar();
        
        return this;
    }

    /**
     * 加载视图文件
     *
     * @param string $file
     * @param array $vars
     * @param string $ext
     * @return string
     */
    public function display(string file, array! vars = [], var ext = null)
    {
        return this->theme->display(file, vars, ext, false);
    }
}
