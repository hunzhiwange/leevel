
extern zend_class_entry *leevel_cache_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Provider_Register);

PHP_METHOD(Leevel_Cache_Provider_Register, __construct);
PHP_METHOD(Leevel_Cache_Provider_Register, register);
PHP_METHOD(Leevel_Cache_Provider_Register, providers);
PHP_METHOD(Leevel_Cache_Provider_Register, isDeferred);
PHP_METHOD(Leevel_Cache_Provider_Register, caches);
PHP_METHOD(Leevel_Cache_Provider_Register, cachesClosure);
PHP_METHOD(Leevel_Cache_Provider_Register, cache);
PHP_METHOD(Leevel_Cache_Provider_Register, cacheClosure);
PHP_METHOD(Leevel_Cache_Provider_Register, cacheLoad);
PHP_METHOD(Leevel_Cache_Provider_Register, cacheLoadClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_provider_register_cachesclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_provider_register_cacheclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_provider_register_cacheloadclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_provider_register_method_entry) {
	PHP_ME(Leevel_Cache_Provider_Register, __construct, arginfo_leevel_cache_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cache_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Cache_Provider_Register, isDeferred, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Cache_Provider_Register, caches, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Provider_Register, cachesClosure, arginfo_leevel_cache_provider_register_cachesclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Provider_Register, cache, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Provider_Register, cacheClosure, arginfo_leevel_cache_provider_register_cacheclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Provider_Register, cacheLoad, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Provider_Register, cacheLoadClosure, arginfo_leevel_cache_provider_register_cacheloadclosure, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
