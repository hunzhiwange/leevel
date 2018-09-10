
extern zend_class_entry *leevel_http_response_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_Response);

PHP_METHOD(Leevel_Http_Response, __construct);
PHP_METHOD(Leevel_Http_Response, create);
PHP_METHOD(Leevel_Http_Response, setCookieResolver);
PHP_METHOD(Leevel_Http_Response, send);
PHP_METHOD(Leevel_Http_Response, sendHeaders);
PHP_METHOD(Leevel_Http_Response, sendContent);
PHP_METHOD(Leevel_Http_Response, setContent);
PHP_METHOD(Leevel_Http_Response, appendContent);
PHP_METHOD(Leevel_Http_Response, setHeader);
PHP_METHOD(Leevel_Http_Response, withHeaders);
PHP_METHOD(Leevel_Http_Response, cookie);
PHP_METHOD(Leevel_Http_Response, setCookie);
PHP_METHOD(Leevel_Http_Response, withCookies);
PHP_METHOD(Leevel_Http_Response, getCookies);
PHP_METHOD(Leevel_Http_Response, getData);
PHP_METHOD(Leevel_Http_Response, setData);
PHP_METHOD(Leevel_Http_Response, getContent);
PHP_METHOD(Leevel_Http_Response, content);
PHP_METHOD(Leevel_Http_Response, getOriginal);
PHP_METHOD(Leevel_Http_Response, setProtocolVersion);
PHP_METHOD(Leevel_Http_Response, getProtocolVersion);
PHP_METHOD(Leevel_Http_Response, setStatusCode);
PHP_METHOD(Leevel_Http_Response, status);
PHP_METHOD(Leevel_Http_Response, getStatusCode);
PHP_METHOD(Leevel_Http_Response, setCharset);
PHP_METHOD(Leevel_Http_Response, charset);
PHP_METHOD(Leevel_Http_Response, getCharset);
PHP_METHOD(Leevel_Http_Response, setExpires);
PHP_METHOD(Leevel_Http_Response, setLastModified);
PHP_METHOD(Leevel_Http_Response, setCache);
PHP_METHOD(Leevel_Http_Response, setNotModified);
PHP_METHOD(Leevel_Http_Response, setContentType);
PHP_METHOD(Leevel_Http_Response, setContentLength);
PHP_METHOD(Leevel_Http_Response, setEtag);
PHP_METHOD(Leevel_Http_Response, isJson);
PHP_METHOD(Leevel_Http_Response, isInvalid);
PHP_METHOD(Leevel_Http_Response, isInformational);
PHP_METHOD(Leevel_Http_Response, isSuccessful);
PHP_METHOD(Leevel_Http_Response, isRedirection);
PHP_METHOD(Leevel_Http_Response, isClientError);
PHP_METHOD(Leevel_Http_Response, isServerError);
PHP_METHOD(Leevel_Http_Response, isOk);
PHP_METHOD(Leevel_Http_Response, isForbidden);
PHP_METHOD(Leevel_Http_Response, isNotFound);
PHP_METHOD(Leevel_Http_Response, isRedirect);
PHP_METHOD(Leevel_Http_Response, isEmpty);
PHP_METHOD(Leevel_Http_Response, ifs);
PHP_METHOD(Leevel_Http_Response, elseIfs);
PHP_METHOD(Leevel_Http_Response, elses);
PHP_METHOD(Leevel_Http_Response, endIfs);
PHP_METHOD(Leevel_Http_Response, setTControl);
PHP_METHOD(Leevel_Http_Response, checkTControl);
PHP_METHOD(Leevel_Http_Response, placeholderTControl);
PHP_METHOD(Leevel_Http_Response, macro);
PHP_METHOD(Leevel_Http_Response, hasMacro);
PHP_METHOD(Leevel_Http_Response, callStaticMacro);
PHP_METHOD(Leevel_Http_Response, callMacro);
PHP_METHOD(Leevel_Http_Response, normalizeDateTime);
PHP_METHOD(Leevel_Http_Response, contentToJson);
PHP_METHOD(Leevel_Http_Response, contentShouldJson);
PHP_METHOD(Leevel_Http_Response, __callStatic);
PHP_METHOD(Leevel_Http_Response, __call);
void zephir_init_static_properties_Leevel_Http_Response(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_create, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcookieresolver, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, cookieResolver, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_appendcontent, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_withheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_cookie, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_withcookies, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_getdata, 0, 0, 0)
	ZEND_ARG_INFO(0, assoc)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setdata, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, encodingOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, protocolVersion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcharset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_charset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setexpires, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setlastmodified, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcache, 0, 0, 1)
	ZEND_ARG_INFO(0, minutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setcontentlength, 0, 0, 1)
	ZEND_ARG_INFO(0, contentLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_setetag, 0, 0, 1)
	ZEND_ARG_INFO(0, etag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_isredirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_ifs, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_elseifs, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_settcontrol, 0, 0, 2)
	ZEND_ARG_INFO(0, inFlowControl)
	ZEND_ARG_INFO(0, isFlowControlTrue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_placeholdertcontrol, 0, 0, 1)
	ZEND_ARG_INFO(0, method)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_normalizedatetime, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_contenttojson, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response_contentshouldjson, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_response___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_response_method_entry) {
	PHP_ME(Leevel_Http_Response, __construct, arginfo_leevel_http_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Http_Response, create, arginfo_leevel_http_response_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_Response, setCookieResolver, arginfo_leevel_http_response_setcookieresolver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_Response, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, sendHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, sendContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setContent, arginfo_leevel_http_response_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, appendContent, arginfo_leevel_http_response_appendcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setHeader, arginfo_leevel_http_response_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, withHeaders, arginfo_leevel_http_response_withheaders, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, cookie, arginfo_leevel_http_response_cookie, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setCookie, arginfo_leevel_http_response_setcookie, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, withCookies, arginfo_leevel_http_response_withcookies, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getData, arginfo_leevel_http_response_getdata, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setData, arginfo_leevel_http_response_setdata, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, content, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getOriginal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setProtocolVersion, arginfo_leevel_http_response_setprotocolversion, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getProtocolVersion, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setStatusCode, arginfo_leevel_http_response_setstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, status, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getStatusCode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setCharset, arginfo_leevel_http_response_setcharset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, charset, arginfo_leevel_http_response_charset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, getCharset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setExpires, arginfo_leevel_http_response_setexpires, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setLastModified, arginfo_leevel_http_response_setlastmodified, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setCache, arginfo_leevel_http_response_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setNotModified, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setContentType, arginfo_leevel_http_response_setcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setContentLength, arginfo_leevel_http_response_setcontentlength, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setEtag, arginfo_leevel_http_response_setetag, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isJson, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isInvalid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isInformational, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isSuccessful, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isRedirection, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isClientError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isServerError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isOk, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isForbidden, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isNotFound, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isRedirect, arginfo_leevel_http_response_isredirect, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, ifs, arginfo_leevel_http_response_ifs, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, elseIfs, arginfo_leevel_http_response_elseifs, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, elses, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, endIfs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, setTControl, arginfo_leevel_http_response_settcontrol, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, checkTControl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, placeholderTControl, arginfo_leevel_http_response_placeholdertcontrol, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, macro, arginfo_leevel_http_response_macro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_Response, hasMacro, arginfo_leevel_http_response_hasmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_Response, callStaticMacro, arginfo_leevel_http_response_callstaticmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_Response, callMacro, arginfo_leevel_http_response_callmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_Response, normalizeDateTime, arginfo_leevel_http_response_normalizedatetime, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Http_Response, contentToJson, arginfo_leevel_http_response_contenttojson, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Http_Response, contentShouldJson, arginfo_leevel_http_response_contentshouldjson, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Http_Response, __callStatic, arginfo_leevel_http_response___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_Response, __call, arginfo_leevel_http_response___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
