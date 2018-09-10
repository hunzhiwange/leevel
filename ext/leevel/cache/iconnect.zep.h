
extern zend_class_entry *leevel_cache_iconnect_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_IConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_iconnect_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_iconnect_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_iconnect_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_iconnect_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Cache_IConnect, setOption, arginfo_leevel_cache_iconnect_setoption)
	PHP_ABSTRACT_ME(Leevel_Cache_IConnect, get, arginfo_leevel_cache_iconnect_get)
	PHP_ABSTRACT_ME(Leevel_Cache_IConnect, set, arginfo_leevel_cache_iconnect_set)
	PHP_ABSTRACT_ME(Leevel_Cache_IConnect, delete, arginfo_leevel_cache_iconnect_delete)
	PHP_ABSTRACT_ME(Leevel_Cache_IConnect, handle, NULL)
	PHP_ABSTRACT_ME(Leevel_Cache_IConnect, close, NULL)
	PHP_FE_END
};
