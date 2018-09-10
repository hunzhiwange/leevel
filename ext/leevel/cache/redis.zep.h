
extern zend_class_entry *leevel_cache_redis_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Redis);

PHP_METHOD(Leevel_Cache_Redis, __construct);
PHP_METHOD(Leevel_Cache_Redis, get);
PHP_METHOD(Leevel_Cache_Redis, set);
PHP_METHOD(Leevel_Cache_Redis, delete);
PHP_METHOD(Leevel_Cache_Redis, close);
zend_object *zephir_init_properties_Leevel_Cache_Redis(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, handle, Leevel\\Cache\\Redis\\IConnect, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_redis_method_entry) {
	PHP_ME(Leevel_Cache_Redis, __construct, arginfo_leevel_cache_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cache_Redis, get, arginfo_leevel_cache_redis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis, set, arginfo_leevel_cache_redis_set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis, delete, arginfo_leevel_cache_redis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis, close, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
