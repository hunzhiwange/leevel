
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * HTTP 请求接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.27
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Http_IRequest) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Http, IRequest, leevel, http_irequest, leevel_http_irequest_method_entry);

	/**
	 * METHOD_HEAD.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_HEAD"), "HEAD");

	/**
	 * METHOD_GET.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_GET"), "GET");

	/**
	 * METHOD_POST.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_POST"), "POST");

	/**
	 * METHOD_PUT.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_PUT"), "PUT");

	/**
	 * METHOD_PATCH.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_PATCH"), "PATCH");

	/**
	 * METHOD_DELETE.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_DELETE"), "DELETE");

	/**
	 * METHOD_PURGE.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_PURGE"), "PURGE");

	/**
	 * METHOD_OPTIONS.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_OPTIONS"), "OPTIONS");

	/**
	 * METHOD_TRACE.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_TRACE"), "TRACE");

	/**
	 * METHOD_CONNECT.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("METHOD_CONNECT"), "CONNECT");

	/**
	 * 服务器 url 重写支持 pathInfo.
	 *
	 * Nginx
	 * location @rewrite {
	 *     rewrite ^/(.*)$ /index.php?_url=/$1;
	 * }
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("PATHINFO_URL"), "_url");

	/**
	 * 请求方法伪装.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_METHOD"), "_method");

	/**
	 * AJAX 伪装.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_AJAX"), "_ajax");

	/**
	 * PJAX 伪装.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_PJAX"), "_pjax");

	/**
	 * JSON 伪装.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_JSON"), "_json");

	/**
	 * 接受 JSON 伪装.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_http_irequest_ce, SL("VAR_ACCEPT_JSON"), "_acceptjson");

	return SUCCESS;

}

/**
 * 重置或者初始化.
 *
 * @param array  $query
 * @param array  $request
 * @param array  $params
 * @param array  $cookies
 * @param array  $files
 * @param array  $server
 * @param string $content
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, reset);

/**
 * 全局变量创建一个 Request.
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, createFromGlobals);

/**
 * 格式化请求的内容.
 *
 * @param \Leevel\Http\IRequest $request
 *
 * @return \Leevel\Http\Request
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, normalizeRequestFromContent);

/**
 * 获取参数.
 *
 * @param string $key
 * @param mixed  $defaults
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, get);

/**
 * 请求是否包含给定的 key.
 *
 * @param array|string $key
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, exists);

/**
 * 请求是否包含非空
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, has);

/**
 * 取得给定的 key 数据
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, only);

/**
 * 取得排除给定的 key 数据
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, except);

/**
 * 取回输入和文件.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, all);

/**
 * 获取输入数据.
 *
 * @param string            $key
 * @param null|array|string $defaults
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, input);

/**
 * 取回 query.
 *
 * @param string            $key
 * @param null|array|string $defaults
 *
 * @return array|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, query);

/**
 * 请求是否存在 COOKIE.
 *
 * @param string $key
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, hasCookie);

/**
 * 取回 cookie.
 *
 * @param string            $key
 * @param null|array|string $defaults
 *
 * @return array|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, cookie);

/**
 * 取得所有文件.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, allFiles);

/**
 * 获取文件
 * 数组文件请在末尾加上反斜杆访问.
 *
 * @param string $key
 * @param mixed  $defaults
 *
 * @return null|array|\Leevel\Http\UploadedFile
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, file);

/**
 * 文件是否存在已上传的文件
 * 数组文件请在末尾加上反斜杆访问.
 *
 * @param string $key
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, hasFile);

/**
 * 验证是否为文件实例.
 *
 * @param mixed $file
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isValidFile);

/**
 * 取回 header.
 *
 * @param string            $key
 * @param null|array|string $defaults
 *
 * @return array|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, header);

/**
 * 取回 server.
 *
 * @param string            $key
 * @param null|array|string $defaults
 *
 * @return array|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, server);

/**
 * 取回数据项.
 *
 * @param string            $source
 * @param string            $key
 * @param null|array|string $defaults
 *
 * @return array|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getItem);

/**
 * 合并输入.
 *
 * @param array $input
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, merge);

/**
 * 替换输入.
 *
 * @param array $input
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, replace);

/**
 * PHP 运行模式命令行, 兼容 swoole http service
 * Swoole http 服务器也以命令行运行.
 *
 * @see http://php.net/manual/zh/function.php-sapi-name.php
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isCli);

/**
 * PHP 运行模式命令行.
 *
 * @see http://php.net/manual/zh/function.php-sapi-name.php
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isRealCli);

/**
 * PHP 运行模式 cgi.
 *
 * @see http://php.net/manual/zh/function.php-sapi-name.php
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isCgi);

/**
 * 是否为 Ajax 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isAjax);

/**
 * 是否为 Ajax 请求行为真实.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isRealAjax);

/**
 * 是否为 Ajax 请求行为真实.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isXmlHttpRequest);

/**
 * 是否为 Pjax 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isPjax);

/**
 * 是否为 Pjax 请求行为真实.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isRealPjax);

/**
 * 是否为 json 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isJson);

/**
 * 是否为 json 请求行为真实.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isRealJson);

/**
 * 是否为接受 json 请求
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isAcceptJson);

/**
 * 是否为接受 json 请求真实.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isRealAcceptJson);

/**
 * 是否为接受任何请求
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isAcceptAny);

/**
 * 是否为手机访问.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isMobile);

/**
 * 是否为 HEAD 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isHead);

/**
 * 是否为 GET 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isGet);

/**
 * 是否为 POST 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isPost);

/**
 * 是否为 PUT 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isPut);

/**
 * 是否为 PATCH 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isPatch);

/**
 * 是否为 PURGE 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isPurge);

/**
 * 是否为 OPTIONS 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isOptions);

/**
 * 是否为 TRACE 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isTrace);

/**
 * 是否为 CONNECT 请求行为.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isConnect);

/**
 * 获取 IP 地址
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getClientIp);

/**
 * 请求类型.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getMethod);

/**
 * 设置请求类型.
 *
 * @param string $method
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, setMethod);

/**
 * 实际请求类型.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getRealMethod);

/**
 * 验证是否为指定的方法.
 *
 * @param string $method
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isMethod);

/**
 * 取回应用名.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, app);

/**
 * 取回控制器名.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, controller);

/**
 * 取回方法名.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, action);

/**
 * 取得节点.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getNode);

/**
 * 设置应用名.
 *
 * @param string $app
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, setApp);

/**
 * 设置控制器名.
 *
 * @param string $controller
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, setController);

/**
 * 设置方法名.
 *
 * @param string $action
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, setAction);

/**
 * 返回当前的语言
 *
 * @return null|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, language);

/**
 * 返回当前的语言
 *
 * @return null|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getLanguage);

/**
 * 设置当前的语言
 *
 * @param string $language
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, setLanguage);

/**
 * 取得请求内容.
 *
 * @return resource|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getContent);

/**
 * 返回 root URL.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getRoot);

/**
 * 返回入口文件.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getEnter);

/**
 * 取得脚本名字.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getScriptName);

/**
 * 是否启用 https.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, isSecure);

/**
 * 取得 http host.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getHttpHost);

/**
 * 获取 host.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getHost);

/**
 * 取得 Scheme 和 Host.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getSchemeAndHttpHost);

/**
 * 返回当前 URL 地址
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getUri);

/**
 * 服务器端口.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getPort);

/**
 * 返回 scheme.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getScheme);

/**
 * 取回查询参数.
 *
 * @return null|string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getQueryString);

/**
 * 设置 pathInfo.
 *
 * @param string $pathInfo
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, setPathInfo);

/**
 * pathInfo 兼容性分析.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getPathInfo);

/**
 * 获取基础路径.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getBasePath);

/**
 * 分析基础 url.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getBaseUrl);

/**
 * 请求参数.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IRequest, getRequestUri);

