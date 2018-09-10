
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * HTTP 响应接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.27
 * @see https://baike.baidu.com/item/HTTP%E7%8A%B6%E6%80%81%E7%A0%81/5053660?fr=aladdin
 * @see http://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Http_IResponse) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Http, IResponse, leevel, http_iresponse, leevel_http_iresponse_method_entry);

	/**
	 * HTTP_CONTINUE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_CONTINUE"), 100);

	/**
	 * HTTP_SWITCHING_PROTOCOLS
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_SWITCHING_PROTOCOLS"), 101);

	/**
	 * HTTP_PROCESSING (RFC2518)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PROCESSING"), 102);

	/**
	 * HTTP_OK
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_OK"), 200);

	/**
	 * HTTP_CREATED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_CREATED"), 201);

	/**
	 * HTTP_ACCEPTED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_ACCEPTED"), 202);

	/**
	 * HTTP_NON_AUTHORITATIVE_INFORMATION
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NON_AUTHORITATIVE_INFORMATION"), 203);

	/**
	 * HTTP_NO_CONTENT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NO_CONTENT"), 204);

	/**
	 * HTTP_RESET_CONTENT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_RESET_CONTENT"), 205);

	/**
	 * HTTP_PARTIAL_CONTENT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PARTIAL_CONTENT"), 206);

	/**
	 * HTTP_MULTI_STATUS (RFC4918)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_MULTI_STATUS"), 207);

	/**
	 * HTTP_ALREADY_REPORTED (RFC5842)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_ALREADY_REPORTED"), 208);

	/**
	 * HTTP_IM_USED (RFC3229)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_IM_USED"), 226);

	/**
	 * HTTP_MULTIPLE_CHOICES
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_MULTIPLE_CHOICES"), 300);

	/**
	 * HTTP_MOVED_PERMANENTLY
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_MOVED_PERMANENTLY"), 301);

	/**
	 * HTTP_FOUND
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_FOUND"), 302);

	/**
	 * HTTP_SEE_OTHER
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_SEE_OTHER"), 303);

	/**
	 * HTTP_NOT_MODIFIED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NOT_MODIFIED"), 304);

	/**
	 * HTTP_USE_PROXY
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_USE_PROXY"), 305);

	/**
	 * HTTP_RESERVED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_RESERVED"), 306);

	/**
	 * HTTP_TEMPORARY_REDIRECT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_TEMPORARY_REDIRECT"), 307);

	/**
	 * HTTP_PERMANENTLY_REDIRECT (RFC7238)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PERMANENTLY_REDIRECT"), 308);

	/**
	 * HTTP_BAD_REQUEST
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_BAD_REQUEST"), 400);

	/**
	 * HTTP_UNAUTHORIZED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_UNAUTHORIZED"), 401);

	/**
	 * HTTP_PAYMENT_REQUIRED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PAYMENT_REQUIRED"), 402);

	/**
	 * HTTP_FORBIDDEN
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_FORBIDDEN"), 403);

	/**
	 * HTTP_NOT_FOUND
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NOT_FOUND"), 404);

	/**
	 * HTTP_METHOD_NOT_ALLOWED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_METHOD_NOT_ALLOWED"), 405);

	/**
	 * HTTP_NOT_ACCEPTABLE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NOT_ACCEPTABLE"), 406);

	/**
	 * HTTP_PROXY_AUTHENTICATION_REQUIRED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PROXY_AUTHENTICATION_REQUIRED"), 407);

	/**
	 * HTTP_REQUEST_TIMEOUT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_REQUEST_TIMEOUT"), 408);

	/**
	 * HTTP_CONFLICT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_CONFLICT"), 409);

	/**
	 * HTTP_GONE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_GONE"), 410);

	/**
	 * HTTP_LENGTH_REQUIRED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_LENGTH_REQUIRED"), 411);

	/**
	 * HTTP_PRECONDITION_FAILED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PRECONDITION_FAILED"), 412);

	/**
	 * HTTP_REQUEST_ENTITY_TOO_LARGE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_REQUEST_ENTITY_TOO_LARGE"), 413);

	/**
	 * HTTP_REQUEST_URI_TOO_LONG
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_REQUEST_URI_TOO_LONG"), 414);

	/**
	 * HTTP_UNSUPPORTED_MEDIA_TYPE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_UNSUPPORTED_MEDIA_TYPE"), 415);

	/**
	 * HTTP_REQUESTED_RANGE_NOT_SATISFIABLE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_REQUESTED_RANGE_NOT_SATISFIABLE"), 416);

	/**
	 * HTTP_EXPECTATION_FAILED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_EXPECTATION_FAILED"), 417);

	/**
	 * HTTP_I_AM_A_TEAPOT (RFC2324)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_I_AM_A_TEAPOT"), 418);

	/**
	 * HTTP_MISDIRECTED_REQUEST (RFC7540)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_MISDIRECTED_REQUEST"), 421);

	/**
	 * HTTP_UNPROCESSABLE_ENTITY (RFC4918)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_UNPROCESSABLE_ENTITY"), 422);

	/**
	 * HTTP_LOCKED (RFC4918)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_LOCKED"), 423);

	/**
	 * HTTP_FAILED_DEPENDENCY (RFC4918)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_FAILED_DEPENDENCY"), 424);

	/**
	 * HTTP_RESERVED_FOR_WEBDAV_ADVANCED_COLLECTIONS_EXPIRED_PROPOSAL (RFC2817)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_RESERVED_FOR_WEBDAV_ADVANCED_COLLECTIONS_EXPIRED_PROPOSAL"), 425);

	/**
	 * HTTP_UPGRADE_REQUIRED (RFC2817)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_UPGRADE_REQUIRED"), 426);

	/**
	 * HTTP_PRECONDITION_REQUIRED (RFC6585)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_PRECONDITION_REQUIRED"), 428);

	/**
	 * HTTP_TOO_MANY_REQUESTS (RFC6585)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_TOO_MANY_REQUESTS"), 429);

	/**
	 * HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE (RFC6585)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE"), 431);

	/**
	 * HTTP_UNAVAILABLE_FOR_LEGAL_REASONS
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_UNAVAILABLE_FOR_LEGAL_REASONS"), 451);

	/**
	 * HTTP_INTERNAL_SERVER_ERROR
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_INTERNAL_SERVER_ERROR"), 500);

	/**
	 * HTTP_NOT_IMPLEMENTED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NOT_IMPLEMENTED"), 501);

	/**
	 * HTTP_BAD_GATEWAY
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_BAD_GATEWAY"), 502);

	/**
	 * HTTP_SERVICE_UNAVAILABLE
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_SERVICE_UNAVAILABLE"), 503);

	/**
	 * HTTP_GATEWAY_TIMEOUT
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_GATEWAY_TIMEOUT"), 504);

	/**
	 * HTTP_VERSION_NOT_SUPPORTED
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_VERSION_NOT_SUPPORTED"), 505);

	/**
	 * HTTP_VARIANT_ALSO_NEGOTIATES_EXPERIMENTAL (RFC2295)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_VARIANT_ALSO_NEGOTIATES_EXPERIMENTAL"), 506);

	/**
	 * HTTP_INSUFFICIENT_STORAGE (RFC4918)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_INSUFFICIENT_STORAGE"), 507);

	/**
	 * HTTP_LOOP_DETECTED (RFC5842)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_LOOP_DETECTED"), 508);

	/**
	 * HTTP_NOT_EXTENDED (RFC2774)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NOT_EXTENDED"), 510);

	/**
	 * HTTP_NETWORK_AUTHENTICATION_REQUIRED (RFC6585)
	 * 
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_iresponse_ce, SL("HTTP_NETWORK_AUTHENTICATION_REQUIRED"), 511);

	return SUCCESS;

}

/**
 * 创建一个响应.
 *
 * @param string $content
 * @param int    $status
 * @param array  $headers
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, create);

/**
 * 设置 COOKIE Resolver.
 *
 * @param \Closure $cookieResolver
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setCookieResolver);

/**
 * 发送 HTTP 响应.
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, send);

/**
 * 发送响应头.
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, sendHeaders);

/**
 * 发送响应内容.
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, sendContent);

/**
 * 设置内容.
 *
 * @param mixed $content
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setContent);

/**
 * 附加内容.
 *
 * @param string $content
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, appendContent);

/**
 * 设置响应头.
 *
 * @param string $key
 * @param string $value
 * @param bool   $replace
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setHeader);

/**
 * 批量设置响应头.
 *
 * @param array $headers
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, withHeaders);

/**
 * 设置 COOKIE 别名.
 *
 * @param string $name
 * @param string $value
 * @param array  $option
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, cookie);

/**
 * 设置 COOKIE.
 *
 * @param string $name
 * @param string $value
 * @param array  $option
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setCookie);

/**
 * 批量设置 COOKIE.
 *
 * @param array $cookies
 * @param array $option
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, withCookies);

/**
 * 获取 COOKIE.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getCookies);

/**
 * 取回 JSON 数据.
 *
 * @param bool $assoc
 * @param int  $depth
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getData);

/**
 * 设置 JSON 数据.
 *
 * @param mixed $data
 * @param int   $encodingOptions
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setData);

/**
 * 获取内容.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getContent);

/**
 * 获取内容.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, content);

/**
 * 获取原始内容.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getOriginal);

/**
 * 设置 HTTP 协议版本 (1.0 or 1.1).
 *
 * @param string $protocolVersion
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setProtocolVersion);

/**
 * 获取 HTTP 协议版本.
 *
 * @final
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getProtocolVersion);

/**
 * 设置相应状态码
 *
 * @param int   $code
 * @param mixed $text
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setStatusCode);

/**
 * 获取状态码
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, status);

/**
 * 获取状态码
 *
 * @final
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getStatusCode);

/**
 * 编码设置.
 *
 * @param string $charset
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setCharset);

/**
 * 编码设置.
 *
 * @param string $charset
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, charset);

/**
 * 获取编码
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, getCharset);

/**
 * 设置过期时间.
 *
 * @param \DateTime $datetime
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setExpires);

/**
 * 设置最后修改时间.
 *
 * @param \DateTime $datetime
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setLastModified);

/**
 * 设置缓存.
 *
 * @param int $minutes
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setCache);

/**
 * 设置响应未修改.
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setNotModified);

/**
 * 设置响应内容类型.
 *
 * @param string $contentType
 * @param string $charset
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setContentType);

/**
 * 设置响应内容长度.
 *
 * @param int $contentLength
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setContentLength);

/**
 * 设置自定义标识符.
 *
 * @param string $etag
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, setEtag);

/**
 * 响应是否为 JSON.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isJson);

/**
 * 响应是否正确.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isInvalid);

/**
 * 是否为信息性响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isInformational);

/**
 * 是否为正确响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isSuccessful);

/**
 * 是否为重定向响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isRedirection);

/**
 * 是否为客户端错误响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isClientError);

/**
 * 是否为服务端错误响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isServerError);

/**
 * 是否为正常响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isOk);

/**
 * 是否为受限响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isForbidden);

/**
 * 是否为 404 NOT FOUND.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isNotFound);

/**
 * 是否为表单重定向响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isRedirect);

/**
 * 是否为空响应.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Http_IResponse, isEmpty);

