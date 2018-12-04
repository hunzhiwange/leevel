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

namespace Leevel\I18n;

use InvalidArgumentException;
use Leevel\I18n\II18n;

/**
 * 国际化组件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.06
 *
 * @version 1.0
 */
class I18n implements II18n
{
    /**
     * 当前语言上下文
     *
     * @var string
     */
    protected i18n;

    /**
     * 语言数据
     *
     * @var array
     */
    protected text = [];

    /**
     * 构造函数
     *
     * @param string $i18n
     * @return void
     */
    public function __construct(string i18n)
    {
        let this->i18n =  i18n;

        let this->text[i18n] = [];
    }

    /**
     * 获取语言 text
     *
     * @return string
     */
    public function gettext()
    {
        var arr;

        let arr = func_get_args();

        if !isset arr[0] {
            return null;
        }

        if isset this->text[this->i18n][arr[0]] {
            let arr[0] = this->text[this->i18n][arr[0]];
        }

        if count(arr) > 1 {
            let arr[0] = call_user_func_array("sprintf", arr);
        }

        return arr[0];
    }

    /**
     * 获取语言 text
     *
     * @return string
     */
    public function __()
    {
        var arr;
        let arr = func_get_args();
        return call_user_func_array([this, "gettext"], arr);
    }

    /**
     * 添加语言包
     *
     * @param string $i18n 语言名字
     * @param array $data 语言包数据
     * @return void
     */
    public function addtext(string i18n, array data = [])
    {
        if array_key_exists(i18n, this->text) {
            let this->text[i18n] = array_merge(this->text[i18n], data);
        } else {
            let this->text[i18n] = data;
        }
    }

    /**
     * 设置当前语言包上下文环境
     *
     * @param string $i18n
     * @return void
     */
    public function setI18n(string i18n)
    {
        let this->i18n = i18n;
    }

    /**
     * 获取当前语言包
     *
     * @return string
     */
    public function getI18n()
    {
        return this->i18n;
    }

    /**
     * 返回所有语言包
     *
     * @return array
     */
    public function all()-> array
    {
        return this->text;
    }
}
