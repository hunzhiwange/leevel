
extern zend_class_entry *leevel_cache_redis_iconnect_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Redis_IConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_iconnect_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_iconnect_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_iconnect_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_redis_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Cache_Redis_IConnect, handle, NULL)
	PHP_ABSTRACT_ME(Leevel_Cache_Redis_IConnect, get, arginfo_leevel_cache_redis_iconnect_get)
	PHP_ABSTRACT_ME(Leevel_Cache_Redis_IConnect, set, arginfo_leevel_cache_redis_iconnect_set)
	PHP_ABSTRACT_ME(Leevel_Cache_Redis_IConnect, delete, arginfo_leevel_cache_redis_iconnect_delete)
	PHP_ABSTRACT_ME(Leevel_Cache_Redis_IConnect, close, NULL)
	PHP_FE_END
};
