
extern zend_class_entry *leevel_cache_icache_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_ICache);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_icache_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_icache_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Cache_ICache, put, arginfo_leevel_cache_icache_put)
	PHP_FE_END
};
