
extern zend_class_entry *leevel_router_iurl_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_IUrl);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_iurl_make, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, subdomain)
	ZEND_ARG_INFO(0, suffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_iurl_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_iurl_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Router_IUrl, make, arginfo_leevel_router_iurl_make)
	PHP_ABSTRACT_ME(Leevel_Router_IUrl, getRequest, NULL)
	PHP_ABSTRACT_ME(Leevel_Router_IUrl, setOption, arginfo_leevel_router_iurl_setoption)
	PHP_FE_END
};
