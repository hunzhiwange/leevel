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

namespace Leevel\Router;

use Closure;
use Leevel\Http\IRequest;

/**
 * url 生成
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.01.10
 * @version 1.0
 */
class Url implements IUrl
{
    /**
     * HTTP 请求
     *
     * @var \Leevel\Http\IRequest
     */
    protected request;

    /**
     * URL 参数
     *
     * @var array
     */
    protected params = [];

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "with_suffix" : false,
        "suffix" : ".html",
        "domain" : ""
    ];

    /**
     * 构造函数
     *
     * @param \Leevel\Http\IRequest $request
     * @param array $option
     * @return void
     */
    public function __construct(<IRequest> request, array option = [])
    {
        let this->request = request;

        let this->option = array_merge(this->option, option);
    }

    /**
     * 生成路由地址
     *
     * @param string $url
     * @param array $params
     * @param string $subdomain
     * @param mixed $suffix
     * @return string
     */
    public function make(var url, array params = [], string subdomain = "www", var suffix = null) -> string
    {
        let url = this->makeUrl(url, params, ! (is_null(suffix)) ? suffix : this->option["with_suffix"]);
        let url = this->withEnter(url);
        let url = this->WithDomain(url, subdomain);

        return url;
    }

    /**
     * 返回 HTTP 请求
     *
     * @return \Leevel\Http\IRequest
     */
    public function getRequest()-> <IRequest>
    {
        return this->request;
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
     * 获取域名.
     *
     * @return string
     */
    public function getDomain()
    {
        return this->option["domain"];
    }

    /**
     * 自定义 URL
     *
     * @param string $url
     * @param array $params
     * @param mixed $suffix
     * @return string
     */
    protected function makeUrl(var url, array params, suffix) -> string
    {
        var queryUrl;

        let this->params = params;

        if substr(url, 0, 1) !== "/" {
            let url = "/" . url;
        }

        if strpos(url, "{") !== false {
            let url = preg_replace_callback("/{(.+?)}/", Closure::fromCallable([this, "matchVar"]), url);
        }

        if this->params {
            let queryUrl = http_build_query(this->params);
            let url .= (strpos(url, "?") !== false ? "&" : "?") . queryUrl;
        }

        let url = this->withSuffix(url, suffix);

        return url;
    }

    /**
     * 匹配 URL 变量
     *
     * @param array $matches
     * @return string
     */
    protected function matchVar(array matches) {
        var value, params;

        let params = this->params;

        if isset params[matches[1]] {
            let value = params[matches[1]];
            unset params[matches[1]];
            let this->params = params;
        } else {
            let value = matches[0];
        }

        return value;
    }

    /**
     * 返回完整 URL 地址
     *
     * @param string $url
     * @param string $domain
     * @return string
     */
    protected function withDomain(string url, string domain) -> string
    {
        if ! (this->option["domain"]) || empty domain {
            return url;
        }

        return (this->isSecure() ? "https://" : "http://") .
            (domain && domain != "*" ? domain . "." : "") .
            this->option["domain"] . url;
    }

    /**
     * 是否启用 https
     *
     * @return boolean
     */
    protected function isSecure() -> boolean
    {
        return this->request->isSecure();
    }

    /**
     * url 带后缀
     *
     * @param string $url
     * @param string|boolean $suffix
     * @return string
     */
    protected function withSuffix(string url, var suffix) -> string
    {
        if url == "/" || strpos(url, "/?") === 0 {
            return url;
        }

        let suffix = suffix === true ? this->option["suffix"] : suffix;

        if strpos(url, "?") !== false {
            let url = str_replace("?", suffix . "?", url);
        } else {
            let url .= suffix;
        }

        return url;
    }

    /**
     * 带上入口文件
     *
     * @param string $url
     * @return string
     */
    protected function withEnter(string url) -> string
    {
        var enter;

        let enter = this->request->getEnter();
        let enter = enter !== "/" ? enter : "";

        return enter . url;
    }
}
