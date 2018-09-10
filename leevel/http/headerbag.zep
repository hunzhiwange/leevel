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
namespace Leevel\Http;

/**
 * header bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.04
 * 
 * @version 1.0
 */
class HeaderBag extends Bag
{

    /**
     * 构造函数
     * 
     * @param array $elements
     * @return void 
     */
    public function __construct(array elements = [])
    {
        this->add(elements);
    }
    
    /**
     * {@inheritdoc}
     */
    public function replace(array elements = []) -> void
    {
        let this->elements = [];
        this->add(elements);
    }
    
    /**
     * {@inheritdoc}
     */
    public function add(array elements = []) -> void
    {
        var key, value;
    
        for key, value in elements {
            this->set(key, value);
        }
    }

    /**
     * 格式化 header 字符串 
     * 
     * @return string
     */
    public function __toString() -> string
    {
        var headers, content, name, value;
    
        let headers = this->all();
        if ! (headers) {
            return "";
        }

        ksort(headers);

        let content = "";

        for name, value in headers {
            let name = ucwords(name, "-");
            let content .= name . ": " . value . "\r\n";
        }

        return content;
    }
    
    /**
     * {@inheritdoc}
     */
    protected function normalize(key)
    {
        let key = str_replace("_", "-", strtolower(key));
        return key;
    }
}
