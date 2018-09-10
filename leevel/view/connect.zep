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
 * 模板处理抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.02
 * @version 1.0
 */
abstract class Connect
{

    /**
     * 变量值
     *
     * @var array
     */
    protected vars = [];

    /**
     * 配置
     *
     * @var array
     */
    protected option = [];

    /**
     * 构造函数
     *
     * @param array option
     * @return void
     */
    public function __construct(array option = [])
    {
        let this->option = array_merge(this->option, option);
    }

    /**
     * 设置配置
     * 
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function setOption(string name, var value)
    {
        let this->option[name] = value;

        return this;
    }

    /**
     * 设置模板变量
     *
     * @param mixed $name
     * @param mixed $value
     * @return void
     */
    public function setVar(var name, var value = null)
    {
        if is_array(name) {
            let this->vars = array_merge(this->vars, name);
        } else {
            let this->vars[name] = value;
        }
    }

    /**
     * 获取变量值
     *
     * @param string|null $name
     * @return mixed
     */
    public function getVar(var name = null)
    {
        if typeof name == "null" {
            return this->vars;
        }
        
        return isset(this->vars[name]) ? this->vars[name] : null;
    }

    /**
     * 删除变量值
     *
     * @return $this
     */
    public function deleteVar()
    {
        var item, name, args = [];

        let args = func_get_args();

        if empty args {
            throw new BadMethodCallException("Wrong number of parameters");
        }

        let name = typeof args[0] === "array" ? args[0] : args;

        for item in name {
            if isset this->vars[item] {
                unset(this->vars[item]);
            }
        }

        return this;
    }

    /**
     * 清空变量值
     *
     * @param string|null $name
     * @return $this
     */
    public function clearVar()
    {
        let this->vars = [];
        
        return this;
    }

    /**
     * 分析展示的视图文件
     *
     * @param string $file 视图文件地址
     * @param string $ext 后缀
     * @return string|void
     */
    protected function parseDisplayFile(string file, string ext = "")
    {
        if ! is_file(file) {
            let file = this->parseFile(file, ext);
        }

        if ! is_file(file) {
            throw new RuntimeException(
                sprintf("Template file %s does not exist.", file)
            );
        }

        return file;
    }

    /**
     * 分析模板真实路径            
     *
     * @param string $tpl 文件地址
     * @param string $ext 扩展名
     * @return string
     */
    protected function parseFile(string tpl, string ext = "")
    {
        var tplTmp;

        let tplTmp = trim(str_replace("->", ".", tpl));

        // 完整路径或者变量以及表达式路径
        if pathinfo(tplTmp, PATHINFO_EXTENSION) ||
            strpos(tplTmp, "$") === 0 ||
            strpos(tplTmp, "(") !== false {
            return this->formatFile(tplTmp);
        }

        if ! this->option["theme_path"] {
            throw new RuntimeException("Theme path must be set.");
        }

        return this->option["theme_path"] . "/" . tplTmp . 
            (! empty ext ? ext : this->option["suffix"]);
    }

    /**
     * 格式化文件名
     *
     * @param string $content
     * @return string
     */
    protected function formatFile(string content)
    {
        return str_replace([
            ":",
            "+"
        ], [
            "->",
            "::"
        ], content);
    }
}
