
extern zend_class_entry *leevel_cache_load_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Load);

PHP_METHOD(Leevel_Cache_Load, __construct);
PHP_METHOD(Leevel_Cache_Load, switchCache);
PHP_METHOD(Leevel_Cache_Load, getCache);
PHP_METHOD(Leevel_Cache_Load, data);
PHP_METHOD(Leevel_Cache_Load, refresh);
PHP_METHOD(Leevel_Cache_Load, dataLoaded);
PHP_METHOD(Leevel_Cache_Load, delete);
PHP_METHOD(Leevel_Cache_Load, cache);
PHP_METHOD(Leevel_Cache_Load, update);
PHP_METHOD(Leevel_Cache_Load, getPersistence);
PHP_METHOD(Leevel_Cache_Load, setPersistence);
PHP_METHOD(Leevel_Cache_Load, deletePersistence);
PHP_METHOD(Leevel_Cache_Load, parse);
zend_object *zephir_init_properties_Leevel_Cache_Load(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
	ZEND_ARG_OBJ_INFO(0, cache, Leevel\\Cache\\ICache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_switchcache, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Leevel\\Cache\\ICache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_data, 0, 0, 1)
	ZEND_ARG_INFO(0, names)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_refresh, 0, 0, 1)
	ZEND_ARG_INFO(0, names)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_dataloaded, 0, 0, 1)
	ZEND_ARG_INFO(0, names)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_cache, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
	ZEND_ARG_INFO(0, force)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_update, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_getpersistence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_setpersistence, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_deletepersistence, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_load_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_load_method_entry) {
	PHP_ME(Leevel_Cache_Load, __construct, arginfo_leevel_cache_load___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cache_Load, switchCache, arginfo_leevel_cache_load_switchcache, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Load, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Load, data, arginfo_leevel_cache_load_data, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Load, refresh, arginfo_leevel_cache_load_refresh, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Load, dataLoaded, arginfo_leevel_cache_load_dataloaded, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Load, delete, arginfo_leevel_cache_load_delete, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Load, cache, arginfo_leevel_cache_load_cache, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Load, update, arginfo_leevel_cache_load_update, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Load, getPersistence, arginfo_leevel_cache_load_getpersistence, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Load, setPersistence, arginfo_leevel_cache_load_setpersistence, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Load, deletePersistence, arginfo_leevel_cache_load_deletepersistence, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Load, parse, arginfo_leevel_cache_load_parse, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
