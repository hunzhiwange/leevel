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

namespace Leevel\Flow;

/**
 * 流程控制复用
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * 
 * @since 2018.03.05
 * 
 * @version 1.0
 */
interface IControl
{
    /**
     * 条件语句 ifs.
     *
     * @param mixed $value
     *
     * @return $this
     */
    public function ifs(var value = false);
    
    /**
     * 条件语句 elseIfs.
     *
     * @param mixed $value
     *
     * @return $this
     */
    public function elseIfs(var value = false);
    
    /**
     * 条件语句 elses
     *
     * @return $this
     */
    public function elses();
    
    /**
     * 条件语句 endIfs
     *
     * @return $this
     */
    public function endIfs();
    
    /**
     * 设置当前条件表达式状态
     *
     * @param bool $inFlowControl
     * @param bool $isFlowControlTrue
     *
     * @return $this
     */
    public function setTControl(bool inFlowControl, bool isFlowControlTrue);
    
    /**
     * 验证一下条件表达式是否通过.
     *
     * @return bool
     */
    public function checkTControl() -> bool;
    
    /**
     * 占位符.
     *
     * @param string $method
     *
     * @return bool
     */
    public function placeholderTControl(string method) -> bool;
}
