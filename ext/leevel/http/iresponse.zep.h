
extern zend_class_entry *leevel_http_iresponse_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_IResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_create, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcookieresolver, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, cookieResolver, Closure, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_appendcontent, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setheader, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, replace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_withheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_cookie, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcookie, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_withcookies, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_getdata, 0, 0, 0)
	ZEND_ARG_INFO(0, assoc)
	ZEND_ARG_INFO(0, depth)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setdata, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, encodingOptions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setprotocolversion, 0, 0, 1)
	ZEND_ARG_INFO(0, protocolVersion)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setstatuscode, 0, 0, 1)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcharset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_charset, 0, 0, 1)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setexpires, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setlastmodified, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, datetime, DateTime, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcache, 0, 0, 1)
	ZEND_ARG_INFO(0, minutes)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcontenttype, 0, 0, 1)
	ZEND_ARG_INFO(0, contentType)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setcontentlength, 0, 0, 1)
	ZEND_ARG_INFO(0, contentLength)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_setetag, 0, 0, 1)
	ZEND_ARG_INFO(0, etag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_iresponse_isredirect, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_iresponse_method_entry) {
	ZEND_FENTRY(create, NULL, arginfo_leevel_http_iresponse_create, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	ZEND_FENTRY(setCookieResolver, NULL, arginfo_leevel_http_iresponse_setcookieresolver, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, send, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, sendHeaders, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, sendContent, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setContent, arginfo_leevel_http_iresponse_setcontent)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, appendContent, arginfo_leevel_http_iresponse_appendcontent)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setHeader, arginfo_leevel_http_iresponse_setheader)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, withHeaders, arginfo_leevel_http_iresponse_withheaders)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, cookie, arginfo_leevel_http_iresponse_cookie)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setCookie, arginfo_leevel_http_iresponse_setcookie)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, withCookies, arginfo_leevel_http_iresponse_withcookies)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getCookies, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getData, arginfo_leevel_http_iresponse_getdata)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setData, arginfo_leevel_http_iresponse_setdata)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getContent, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, content, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getOriginal, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setProtocolVersion, arginfo_leevel_http_iresponse_setprotocolversion)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getProtocolVersion, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setStatusCode, arginfo_leevel_http_iresponse_setstatuscode)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, status, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getStatusCode, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setCharset, arginfo_leevel_http_iresponse_setcharset)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, charset, arginfo_leevel_http_iresponse_charset)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, getCharset, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setExpires, arginfo_leevel_http_iresponse_setexpires)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setLastModified, arginfo_leevel_http_iresponse_setlastmodified)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setCache, arginfo_leevel_http_iresponse_setcache)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setNotModified, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setContentType, arginfo_leevel_http_iresponse_setcontenttype)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setContentLength, arginfo_leevel_http_iresponse_setcontentlength)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, setEtag, arginfo_leevel_http_iresponse_setetag)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isJson, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isInvalid, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isInformational, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isSuccessful, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isRedirection, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isClientError, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isServerError, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isOk, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isForbidden, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isNotFound, NULL)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isRedirect, arginfo_leevel_http_iresponse_isredirect)
	PHP_ABSTRACT_ME(Leevel_Http_IResponse, isEmpty, NULL)
	PHP_FE_END
};
