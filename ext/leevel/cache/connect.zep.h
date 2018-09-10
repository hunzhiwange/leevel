
extern zend_class_entry *leevel_cache_connect_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Connect);

PHP_METHOD(Leevel_Cache_Connect, __construct);
PHP_METHOD(Leevel_Cache_Connect, setOption);
PHP_METHOD(Leevel_Cache_Connect, handle);
PHP_METHOD(Leevel_Cache_Connect, getCacheName);
PHP_METHOD(Leevel_Cache_Connect, cacheTime);
PHP_METHOD(Leevel_Cache_Connect, prepareRegexForWildcard);
PHP_METHOD(Leevel_Cache_Connect, normalizeOptions);
zend_object *zephir_init_properties_Leevel_Cache_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_connect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_connect_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_connect_getcachename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_connect_cachetime, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, defaultTime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_connect_prepareregexforwildcard, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_connect_normalizeoptions, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_connect_method_entry) {
	PHP_ME(Leevel_Cache_Connect, __construct, arginfo_leevel_cache_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cache_Connect, setOption, arginfo_leevel_cache_connect_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Connect, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Connect, getCacheName, arginfo_leevel_cache_connect_getcachename, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Connect, cacheTime, arginfo_leevel_cache_connect_cachetime, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Connect, prepareRegexForWildcard, arginfo_leevel_cache_connect_prepareregexforwildcard, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_Connect, normalizeOptions, arginfo_leevel_cache_connect_normalizeoptions, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
