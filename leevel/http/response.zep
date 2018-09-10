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

use Closure;
use DateTime;
use ArrayObject;
use DateTimeZone;
use JsonSerializable;
use BadMethodCallException;
use InvalidArgumentException;
use UnexpectedValueException;
use Leevel\Support\IJson;
use Leevel\Flow\IControl;
use Leevel\Support\IArray;
use Leevel\Support\IMacro;

/**
 * HTTP 响应
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
class Response implements IControl, IMacro, IResponse
{

    /**
     * 响应头
     * 
     * @var \Leevel\Http\ResponseHeaderBag
     */
    public headers;
    
    /**
     * 原生响应内容
     *
     * @var mixed
     */
    public original;
    
    /**
     * 响应内容
     * 
     * @var string
     */
    protected content;
    
    /**
     * HTTP 协议版本
     * 
     * @var string
     */
    protected protocolVersion;
    
    /**
     * 状态码
     * 
     * @var int
     */
    protected statusCode;
    
    /**
     * 状态码内容
     * 
     * @var string
     */
    protected statusText;
    
    /**
     * 字符编码
     * 
     * @var string
     */
    protected charset;
    
    /**
     * 是否为 JSON
     * 
     * @var boolean
     */
    protected isJson = false;
    
    /**
     * COOKIE Resolver
     * 
     * @var \Closure
     */
    protected static cookieResolver;
    
    /**
     * 状态码
     *
     * @see http://www.iana.org/assignments/http-status-codes/
     * @var array
     */
    public static statusTexts = [
        100 : "Continue", 
        101 : "Switching Protocols", 
        102 : "Processing", 
        103 : "Early Hints", 
        200 : "OK", 
        201 : "Created", 
        202 : "Accepted", 
        203 : "Non-Authoritative Information", 
        204 : "No Content", 
        205 : "Reset Content", 
        206 : "Partial Content", 
        207 : "Multi-Status", 
        208 : "Already Reported", 
        226 : "IM Used", 
        300 : "Multiple Choices", 
        301 : "Moved Permanently", 
        302 : "Found", 
        303 : "See Other", 
        304 : "Not Modified", 
        305 : "Use Proxy", 
        307 : "Temporary Redirect", 
        308 : "Permanent Redirect", 
        400 : "Bad Request", 
        401 : "Unauthorized", 
        402 : "Payment Required", 
        403 : "Forbidden", 
        404 : "Not Found", 
        405 : "Method Not Allowed", 
        406 : "Not Acceptable", 
        407 : "Proxy Authentication Required", 
        408 : "Request Timeout", 
        409 : "Conflict", 
        410 : "Gone", 
        411 : "Length Required", 
        412 : "Precondition Failed", 
        413 : "Payload Too Large", 
        414 : "URI Too Long", 
        415 : "Unsupported Media Type", 
        416 : "Range Not Satisfiable", 
        417 : "Expectation Failed", 
        418 : "I'm a teapot", 
        421 : "Misdirected Request", 
        422 : "Unprocessable Entity", 
        423 : "Locked", 
        424 : "Failed Dependency", 
        425 : "Reserved for WebDAV advanced collections expired proposal", 
        426 : "Upgrade Required", 
        428 : "Precondition Required", 
        429 : "Too Many Requests", 
        431 : "Request Header Fields Too Large", 
        451 : "Unavailable For Legal Reasons", 
        500 : "Internal Server Error", 
        501 : "Not Implemented", 
        502 : "Bad Gateway", 
        503 : "Service Unavailable", 
        504 : "Gateway Timeout", 
        505 : "HTTP Version Not Supported", 
        506 : "Variant Also Negotiates", 
        507 : "Insufficient Storage", 
        508 : "Loop Detected", 
        510 : "Not Extended", 
        511 : "Network Authentication Required"
    ];
    
    /**
     * 注册的动态扩展
     *
     * @var array
     */
    protected static macro = [];

    /**
     * 逻辑代码是否处于条件表达式中
     *
     * @var boolean
     */
    protected inFlowControl = false;
    
    /**
     * 条件表达式是否为真
     *
     * @var boolean
     */
    protected isFlowControlTrue = false;

    /**
     * 构造函数
     * 
     * @param string $content
     * @param integer $status
     * @param array $headers
     * @return void
     */
    public function __construct(var content = "", int status = 200, array headers = [])
    {
        let this->headers = new ResponseHeaderBag(headers);
        this->setContent(content);
        this->setStatusCode(status);
        this->setProtocolVersion("1.0");
    }
    
    /**
     * 创建一个响应
     * 
     * @param string $content
     * @param integer $status
     * @param array $headers
     * @return static
     */
    public static function create(var content = "", int status = 200, array headers = [])
    {
        return new static(content, status, headers);
    }
    
    /**
     * 设置 COOKIE Resolver
     * 
     * @param \Closure $cookieResolver
     * @return void
     */
    public static function setCookieResolver(<Closure> cookieResolver = null)
    {
        let self::cookieResolver = cookieResolver;
    }
    
    /**
     * 发送 HTTP 响应
     *
     * @return $this
     */
    public function send()
    {
        this->sendHeaders();
        this->sendContent();

        if function_exists("fastcgi_finish_request") {
            fastcgi_finish_request();
        }

        return this;
    }
    
    /**
     * 发送响应头
     *
     * @return $this
     */
    public function sendHeaders()
    {
        var name, value, cookie, item;
    
        if this->checkTControl() {
            return this;
        }

        if headers_sent() {
            return this;
        }

        for name, value in this->headers->all() {
            header(name . ": " . value, false, this->statusCode);
        }

        // 状态码
        header(sprintf("HTTP/%s %s %s", this->protocolVersion, this->statusCode, this->statusText), true, this->statusCode);

        // cookie
        let cookie = call_user_func(self::cookieResolver);

        if cookie {
            for item in cookie->all() {
                call_user_func_array("setcookie", item);;
            }
        }
        
        return this;
    }
    
    /**
     * 发送响应内容
     *
     * @return $this
     */
    public function sendContent()
    {
        if this->checkTControl() {
            return this;
        }

        echo this->content;

        return this;
    }
    
    /**
     * 设置内容
     *
     * @param mixed $content
     * @return $this
     */
    public function setContent(var content)
    {
        if this->checkTControl() {
            return this;
        }

        let this->original = content;

        if this->contentShouldJson(content) {
            this->setHeader("Content-Type", "application/json");

            let this->isJson = true;

            let content = this->contentToJson(content);
        }

        if content !== null && ! (is_scalar(content)) && ! (is_callable([
            content, 
            "__toString"
        ])) {
            throw new UnexpectedValueException(
                sprintf("The Response content must be a scalar or object implementing __toString(), %s given.", gettype(content))
            );
        }

        let this->content = strval(content);

        return this;
    }
    
    /**
     * 附加内容
     *
     * @param string $content
     * @return $this
     */
    public function appendContent(var content = null)
    {
        if this->checkTControl() {
            return this;
        }

        let this->content = this->getContent() . content;

        return this;
    }
    
    /**
     * 设置响应头
     *
     * @param string $key
     * @param string $value
     * @param bool $replace
     * @return $this
     */
    public function setHeader(string key, string value, boolean replace = true)
    {
        if this->checkTControl() {
            return this;
        }

        if replace === true || ! (this->headers->has(key)) {
            this->headers->set(key, value);
        }

        return this;
    }
    
    /**
     * 批量设置响应头
     *
     * @param array $headers
     * @return $this
     */
    public function withHeaders(array headers)
    {
        var key, value;
    
        if this->checkTControl() {
            return this;
        }

        for key, value in headers {
            this->headers->set(key, value);
        }

        return this;
    }

    /**
     * 设置 COOKIE 别名
     *
     * @param string $name
     * @param string $value
     * @param array $option
     * @return $this
     */
    public function cookie(string name, string value = "", array option = [])
    {
        return this->setCookie(name, value, option);
    }
    
    /**
     * 设置 COOKIE
     *
     * @param string $name
     * @param string $value
     * @param array $option
     * @return $this
     */
    public function setCookie(string name, string value = "", array option = [])
    {
        var cookie;
    
        if this->checkTControl() {
            return this;
        }

        if ! (self::cookieResolver) {
            throw new InvalidArgumentException("Cookie resolver is not set.");
        }

        let cookie = call_user_func(self::cookieResolver);
        cookie->set(name, value, option);

        return this;
    }
    
    /**
     * 批量设置 COOKIE
     *
     * @param array $cookies
     * @param array $option
     * @return $this
     */
    public function withCookies(array cookies, array option = [])
    {
        var value, key;
    
        if this->checkTControl() {
            return this;
        }

        for key, value in cookies {
            this->setCookie(key, value, option);
        }

        return this;
    }

    /**
     * 获取 COOKIE
     *
     * @return array
     */
    public function getCookies()
    {
        var cookie = call_user_func(self::cookieResolver);
        return cookie->all();
    }
    
    /**
     * 取回 JSON 数据
     *
     * @param bool $assoc
     * @param int $depth
     * @return mixed
     */
    public function getData(boolean assoc = true, int depth = 512)
    {
        if this->isJson {
            return json_decode(this->content, assoc, depth);
        }

        return this->content;
    }
    
    /**
     * 设置 JSON 数据
     *
     * @param mixed $data
     * @param int $encodingOptions
     * @return $this
     */
    public function setData(var data = [], var encodingOptions = null)
    {
        if this->checkTControl() {
            return this;
        }

        let this->original = data;

        if typeof encodingOptions === "null" {
            let encodingOptions = 256;
        }

        if is_object(data) && data instanceof IArray {
            let data = json_encode(data->toArray(), encodingOptions);
        } elseif is_object(data) && data instanceof IJson {
            let data = data->toJson(encodingOptions);
        } elseif is_object(data) && data instanceof JsonSerializable {
            let data = json_encode(data->jsonSerialize(), encodingOptions);
        } else {
            // json_encode("\xB1\x31") 会引发 PHP 内核提示 Segmentation fault (core dumped)
            let data = json_encode(data, encodingOptions);
        }

        if json_last_error() !== JSON_ERROR_NONE {
            throw new InvalidArgumentException(json_last_error_msg());
        }

        let this->content = strval(data);

        return this;
    }
    
    /**
     * 获取内容
     *
     * @return string
     */
    public function getContent() -> string
    {
        return this->content;
    }
    
    /**
     * 获取内容
     *
     * @return string
     */
    public function content() -> string
    {
        return this->getContent();
    }
    
    /**
     * 获取原始内容
     *
     * @return string
     */
    public function getOriginal() -> string
    {
        return this->original;
    }
    
    /**
     * 设置 HTTP 协议版本 (1.0 or 1.1).
     *
     * @param string $protocolVersion
     * @return $this
     */
    public function setProtocolVersion(string protocolVersion)
    {
        if this->checkTControl() {
            return this;
        }

        let this->protocolVersion = protocolVersion;

        return this;
    }
    
    /**
     * 获取 HTTP 协议版本
     *
     * @final
     */
    public function getProtocolVersion()
    {
        return this->protocolVersion;
    }
    
    /**
     * 设置相应状态码
     * 
     * @param int $code
     * @param mixed $text
     * @return $this
     */
    public function setStatusCode(int code, var text = null)
    {
        if this->checkTControl() {
            return this;
        }

        let this->statusCode = code;

        if this->isInvalid() {
            throw new InvalidArgumentException(sprintf("The HTTP status code %s is not valid.", code));
        }

        if text === null {
            let this->statusText = isset self::statusTexts[code] ? self::statusTexts[code] : "unknown status";
            return this;
        }

        if text === false {
            let this->statusText = "";
            return this;
        }

        let this->statusText = text;

        return this;
    }
    
    /**
     * 获取状态码
     *
     * @return int
     */
    public function status() -> int
    {
        return this->getStatusCode();
    }
    
    /**
     * 获取状态码
     *
     * @final
     */
    public function getStatusCode()
    {
        return this->statusCode;
    }

    /**
     * 编码设置
     *
     * @param string $charset
     * @return $this
     */
    public function setCharset(string charset)
    {
        return this->charset(charset);
    }
    
    /**
     * 编码设置
     *
     * @param string $charset
     * @return $this
     */
    public function charset(string charset)
    {
        if this->checkTControl() {
            return this;
        }

        let this->charset = charset;

        return this;
    }
    
    /**
     * 获取编码
     *
     * @return string
     */
    public function getCharset()
    {
        return this->charset;
    }
    
    /**
     * 设置过期时间
     *
     * @param \DateTime $datetime
     * @return $this
     */
    public function setExpires(<DateTime> datetime = null)
    {
        if this->checkTControl() {
            return this;
        }

        if is_null(datetime) {
            this->headers->remove("Expires");
            return this;
        }

        this->setHeader("Expires", this->normalizeDateTime(datetime));

        return this;
    }
    
    /**
     * 设置最后修改时间
     *
     * @param \DateTime $datetime
     * @return $this
     */
    public function setLastModified(<DateTime> datetime = null)
    {
        if this->checkTControl() {
            return this;
        }

        if is_null(datetime) {
            this->headers->remove("Last-Modified");
            return this;
        }

        this->setHeader("Last-Modified", this->normalizeDateTime(datetime));

        return this;
    }
    
    /**
     * 设置缓存
     *
     * @param int $minutes
     * @return $this
     */
    public function setCache(int minutes)
    {
        var date;
    
        if this->checkTControl() {
            return this;
        }

        let date = new DateTime();
        date->modify("+" . minutes . "minutes");

        this->setExpires(date);
        this->setHeader("Cache-Control", "max-age=" . minutes * 60);

        return this;
    }
    
    /**
     * 设置响应未修改
     *
     * @return $this
     */
    public function setNotModified()
    {
        if this->checkTControl() {
            return this;
        }

        this->setStatusCode(304, self::statusTexts[304]);

        return this;
    }
    
    /**
     * 设置响应内容类型
     *
     * @param string $contentType
     * @param string $charset
     * @return $this
     */
    public function setContentType(string contentType, var charset = null)
    {
        if this->checkTControl() {
            return this;
        }

        if charset === null {
            let charset = this->getCharset();
        }

        if charset === null {
            this->setHeader("Content-Type", contentType);
        } else {
            this->setHeader("Content-Type", contentType . "; charset=" . charset);
        }

        return this;
    }
    
    /**
     * 设置响应内容长度
     *
     * @param int $contentLength
     * @return $this
     */
    public function setContentLength(int contentLength)
    {
        if this->checkTControl() {
            return this;
        }

        this->setHeader("Content-Length", strval(contentLength));

        return this;
    }
    
    /**
     * 设置自定义标识符
     *
     * @param string $etag
     * @return $this
     */
    public function setEtag(string etag)
    {
        if this->checkTControl() {
            return this;
        }

        this->setHeader("Etag", etag);

        return this;
    }
    
    /**
     * 响应是否为 JSON
     *
     * @return bool
     */
    public function isJson() -> boolean
    {
        return this->isJson;
    }
    
    /**
     * 响应是否正确
     *
     * @return bool
     */
    public function isInvalid() -> boolean
    {
        return this->statusCode < 100 || this->statusCode >= 600;
    }
    
    /**
     * 是否为信息性响应
     *
     * @return bool
     */
    public function isInformational() -> boolean
    {
        return this->statusCode >= 100 && this->statusCode < 200;
    }
    
    /**
     * 是否为正确响应
     *
     * @return bool
     */
    public function isSuccessful() -> boolean
    {
        return this->statusCode >= 200 && this->statusCode < 300;
    }
    
    /**
     * 是否为重定向响应
     *
     * @return bool
     */
    public function isRedirection() -> boolean
    {
        return this->statusCode >= 300 && this->statusCode < 400;
    }
    
    /**
     * 是否为客户端错误响应
     *
     * @return bool
     */
    public function isClientError() -> boolean
    {
        return this->statusCode >= 400 && this->statusCode < 500;
    }
    
    /**
     * 是否为服务端错误响应
     *
     * @return bool
     */
    public function isServerError() -> boolean
    {
        return this->statusCode >= 500 && this->statusCode < 600;
    }
    
    /**
     * 是否为正常响应
     *
     * @return bool
     */
    public function isOk() -> boolean
    {
        return 200 === this->statusCode;
    }
    
    /**
     * 是否为受限响应
     *
     * @return bool
     */
    public function isForbidden() -> boolean
    {
        return 403 === this->statusCode;
    }
    
    /**
     * 是否为 404 NOT FOUND
     *
     * @return bool
     */
    public function isNotFound() -> boolean
    {
        return 404 === this->statusCode;
    }
    
    /**
     * 是否为表单重定向响应
     *
     * @return bool
     */
    public function isRedirect(var location = null) -> boolean
    {
        return in_array(this->statusCode, [
            201, 
            301, 
            302, 
            303, 
            307, 
            308
        ]) && 
            ( location === null ? location === null : location == this->headers->get("Location"));
    }
    
    /**
     * 是否为空响应
     *
     * @return bool
     */
    public function isEmpty() -> boolean
    {
        return in_array(this->statusCode, [
            204, 
            304
        ]);
    }

    /**
     * 条件语句 ifs.
     *
     * @param mixed $value
     *
     * @return $this
     */
    public function ifs(var value = false)
    {
        return this->setTControl(true, value ? true : false);
    }
    
    /**
     * 条件语句 elseIfs.
     *
     * @param mixed $value
     *
     * @return $this
     */
    public function elseIfs(var value = false)
    {
        return this->setTControl(true, value ? true : false);
    }
    
    /**
     * 条件语句 elses
     *
     * @return $this
     */
    public function elses()
    {
        return this->setTControl(true, !this->isFlowControlTrue);
    }
    
    /**
     * 条件语句 endIfs
     *
     * @return $this
     */
    public function endIfs()
    {
        return this->setTControl(false, false);
    }
    
    /**
     * 设置当前条件表达式状态
     *
     * @param bool $inFlowControl
     * @param bool $isFlowControlTrue
     *
     * @return $this
     */
    public function setTControl(bool inFlowControl, bool isFlowControlTrue)
    {
        let this->inFlowControl = inFlowControl;
        let this->isFlowControlTrue = isFlowControlTrue;

        return this;
    }
    
    /**
     * 验证一下条件表达式是否通过
     *
     * @return bool
     */
    public function checkTControl() -> bool
    {
        return this->inFlowControl && ! (this->isFlowControlTrue);
    }
    
    /**
     * 占位符
     *
     * @param string $method
     * @return boolean
     */
    public function placeholderTControl(string method) -> boolean
    {
        return in_array(method, [
            "placeholder", 
            "foobar"
        ]);
    }

    /**
     * 注册一个扩展
     *
     * @param string $name
     * @param callable $macro
     * @return void
     */
    public static function macro(string name, var macro)
    {
        let self::macro[name] = macro;
    }
    
    /**
     * 判断一个扩展是否注册
     *
     * @param string $name
     * @return bool
     */
    public static function hasMacro(string name) -> boolean
    {
        return isset self::macro[name];
    }

    /**
     * __callStatic 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function callStaticMacro(string method, array args)
    {
        if self::hasMacro(method) {
            return call_user_func_array(self::macro[method], args);
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }

    /**
     * __call 魔术方法隐射
     * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
     * 即 Closure::bind($closures, null, get_called_class())
     * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
     * 
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function callMacro(string method, array args)
    {
        if self::hasMacro(method) {
            if self::macro[method] instanceof Closure {
                return call_user_func_array(self::macro[method]->bindTo(this), args);
            } else {
                return call_user_func_array(self::macro[method], args);
            }
        }

        throw new BadMethodCallException(sprintf("Method %s is not exits.", method));
    }
    
    /**
     * 格式化响应时间
     *
     * @param \DateTime $datetime
     * @return string
     */
    protected function normalizeDateTime(<DateTime> datetime) -> string
    {
        var date;
    
        let date = clone datetime;
        date->setTimezone(new DateTimeZone("UTC"));

        return date->format("D, d M Y H:i:s") . " GMT";
    }
    
    /**
     * 内容转换为 JSON
     *
     * @param mixed $content
     * @return string
     */
    protected function contentToJson(var content) -> string
    {
        if is_object(content) && content instanceof IJson {
            return content->toJson();
        }

        if is_object(content) && content instanceof IArray {
            let content = content->toArray();
        }

        return json_encode(content, JSON_UNESCAPED_UNICODE);
    }
    
    /**
     * 可以转换为 JSON
     *
     * @param mixed $content
     * @return bool
     */
    protected function contentShouldJson(var content) -> boolean
    {
        return (is_object(content) && content instanceof IJson) || 
            (is_object(content) && content instanceof IArray) || 
            (is_object(content) && content instanceof ArrayObject) || 
            (is_object(content) && content instanceof JsonSerializable) || 
            is_array(content);
    }

    /**
     * __callStatic 魔术方法
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public static function __callStatic(string method, array args)
    {
        return self::callStaticMacro(method, args);
    }
    
    /**
     * __call 魔术方法
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function __call(string method, array args)
    {
        return this->callMacro(method, args);
    }
}
