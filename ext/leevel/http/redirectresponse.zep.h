
extern zend_class_entry *leevel_http_redirectresponse_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_RedirectResponse);

PHP_METHOD(Leevel_Http_RedirectResponse, __construct);
PHP_METHOD(Leevel_Http_RedirectResponse, create);
PHP_METHOD(Leevel_Http_RedirectResponse, with);
PHP_METHOD(Leevel_Http_RedirectResponse, withInput);
PHP_METHOD(Leevel_Http_RedirectResponse, onlyInput);
PHP_METHOD(Leevel_Http_RedirectResponse, exceptInput);
PHP_METHOD(Leevel_Http_RedirectResponse, withErrors);
PHP_METHOD(Leevel_Http_RedirectResponse, getTargetUrl);
PHP_METHOD(Leevel_Http_RedirectResponse, setTargetUrl);
PHP_METHOD(Leevel_Http_RedirectResponse, getRequest);
PHP_METHOD(Leevel_Http_RedirectResponse, setRequest);
PHP_METHOD(Leevel_Http_RedirectResponse, getSession);
PHP_METHOD(Leevel_Http_RedirectResponse, setSession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_create, 0, 0, 0)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_with, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_withinput, 0, 0, 0)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_witherrors, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_settargeturl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_setrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_redirectresponse_setsession, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, session, Leevel\\Session\\ISession, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_redirectresponse_method_entry) {
	PHP_ME(Leevel_Http_RedirectResponse, __construct, arginfo_leevel_http_redirectresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Http_RedirectResponse, create, arginfo_leevel_http_redirectresponse_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_RedirectResponse, with, arginfo_leevel_http_redirectresponse_with, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, withInput, arginfo_leevel_http_redirectresponse_withinput, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, onlyInput, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, exceptInput, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, withErrors, arginfo_leevel_http_redirectresponse_witherrors, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, getTargetUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, setTargetUrl, arginfo_leevel_http_redirectresponse_settargeturl, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, setRequest, arginfo_leevel_http_redirectresponse_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, getSession, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_RedirectResponse, setSession, arginfo_leevel_http_redirectresponse_setsession, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
