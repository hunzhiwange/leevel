
extern zend_class_entry *leevel_router_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_Provider_Register);

PHP_METHOD(Leevel_Router_Provider_Register, __construct);
PHP_METHOD(Leevel_Router_Provider_Register, register);
PHP_METHOD(Leevel_Router_Provider_Register, providers);
PHP_METHOD(Leevel_Router_Provider_Register, router);
PHP_METHOD(Leevel_Router_Provider_Register, routerClosure);
PHP_METHOD(Leevel_Router_Provider_Register, url);
PHP_METHOD(Leevel_Router_Provider_Register, urlClosure);
PHP_METHOD(Leevel_Router_Provider_Register, redirect);
PHP_METHOD(Leevel_Router_Provider_Register, redirectClosure);
PHP_METHOD(Leevel_Router_Provider_Register, response);
PHP_METHOD(Leevel_Router_Provider_Register, responseClosure);
PHP_METHOD(Leevel_Router_Provider_Register, cookie);
PHP_METHOD(Leevel_Router_Provider_Register, cookieClosure);
PHP_METHOD(Leevel_Router_Provider_Register, view);
PHP_METHOD(Leevel_Router_Provider_Register, viewClosure);
PHP_METHOD(Leevel_Router_Provider_Register, cookieResolver);
PHP_METHOD(Leevel_Router_Provider_Register, makeCookieResolverClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register_routerclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register_urlclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register_redirectclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register_responseclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register_cookieclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_provider_register_viewclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_provider_register_method_entry) {
	PHP_ME(Leevel_Router_Provider_Register, __construct, arginfo_leevel_router_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Router_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Router_Provider_Register, router, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, routerClosure, arginfo_leevel_router_provider_register_routerclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, url, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, urlClosure, arginfo_leevel_router_provider_register_urlclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, redirect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, redirectClosure, arginfo_leevel_router_provider_register_redirectclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, response, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, responseClosure, arginfo_leevel_router_provider_register_responseclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, cookie, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Provider_Register, cookieClosure, arginfo_leevel_router_provider_register_cookieclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, view, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_Provider_Register, viewClosure, arginfo_leevel_router_provider_register_viewclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, cookieResolver, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_Provider_Register, makeCookieResolverClosure, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
