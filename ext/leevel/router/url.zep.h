
extern zend_class_entry *leevel_router_url_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_Url);

PHP_METHOD(Leevel_Router_Url, __construct);
PHP_METHOD(Leevel_Router_Url, make);
PHP_METHOD(Leevel_Router_Url, getRequest);
PHP_METHOD(Leevel_Router_Url, setOption);
PHP_METHOD(Leevel_Router_Url, makeUrl);
PHP_METHOD(Leevel_Router_Url, matchVar);
PHP_METHOD(Leevel_Router_Url, withDomain);
PHP_METHOD(Leevel_Router_Url, isSecure);
PHP_METHOD(Leevel_Router_Url, withSuffix);
PHP_METHOD(Leevel_Router_Url, withEnter);
zend_object *zephir_init_properties_Leevel_Router_Url(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_make, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, subdomain)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_makeurl, 0, 0, 3)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_matchvar, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_withdomain, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, domain)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_withsuffix, 0, 0, 2)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_url_withenter, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_url_method_entry) {
	PHP_ME(Leevel_Router_Url, __construct, arginfo_leevel_router_url___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Router_Url, make, arginfo_leevel_router_url_make, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, setOption, arginfo_leevel_router_url_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Url, makeUrl, arginfo_leevel_router_url_makeurl, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, matchVar, arginfo_leevel_router_url_matchvar, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, withDomain, arginfo_leevel_router_url_withdomain, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, isSecure, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, withSuffix, arginfo_leevel_router_url_withsuffix, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Url, withEnter, arginfo_leevel_router_url_withenter, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
