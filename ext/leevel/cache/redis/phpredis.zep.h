
extern zend_class_entry *leevel_cache_redis_phpredis_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Redis_PhpRedis);

PHP_METHOD(Leevel_Cache_Redis_PhpRedis, __construct);
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, handle);
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, get);
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, set);
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, delete);
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, close);
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, createRedis);
zend_object *zephir_init_properties_Leevel_Cache_Redis_PhpRedis(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_phpredis___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_phpredis_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_phpredis_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_redis_phpredis_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_redis_phpredis_method_entry) {
	PHP_ME(Leevel_Cache_Redis_PhpRedis, __construct, arginfo_leevel_cache_redis_phpredis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cache_Redis_PhpRedis, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis_PhpRedis, get, arginfo_leevel_cache_redis_phpredis_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis_PhpRedis, set, arginfo_leevel_cache_redis_phpredis_set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis_PhpRedis, delete, arginfo_leevel_cache_redis_phpredis_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis_PhpRedis, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Redis_PhpRedis, createRedis, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
