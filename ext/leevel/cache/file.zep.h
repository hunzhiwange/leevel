
extern zend_class_entry *leevel_cache_file_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_File);

PHP_METHOD(Leevel_Cache_File, get);
PHP_METHOD(Leevel_Cache_File, set);
PHP_METHOD(Leevel_Cache_File, delete);
PHP_METHOD(Leevel_Cache_File, close);
PHP_METHOD(Leevel_Cache_File, isExpired);
PHP_METHOD(Leevel_Cache_File, getCachePath);
PHP_METHOD(Leevel_Cache_File, writeData);
PHP_METHOD(Leevel_Cache_File, exist);
PHP_METHOD(Leevel_Cache_File, getCacheName);
zend_object *zephir_init_properties_Leevel_Cache_File(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_isexpired, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, option, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_getcachepath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_writedata, 0, 0, 2)
	ZEND_ARG_INFO(0, fileName)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_exist, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_file_getcachename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_file_method_entry) {
	PHP_ME(Leevel_Cache_File, get, arginfo_leevel_cache_file_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_File, set, arginfo_leevel_cache_file_set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_File, delete, arginfo_leevel_cache_file_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_File, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_File, isExpired, arginfo_leevel_cache_file_isexpired, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_File, getCachePath, arginfo_leevel_cache_file_getcachepath, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_File, writeData, arginfo_leevel_cache_file_writedata, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_File, exist, arginfo_leevel_cache_file_exist, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Cache_File, getCacheName, arginfo_leevel_cache_file_getcachename, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
