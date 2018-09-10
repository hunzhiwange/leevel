
extern zend_class_entry *leevel_log_file_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_File);

PHP_METHOD(Leevel_Log_File, __construct);
PHP_METHOD(Leevel_Log_File, setOption);
PHP_METHOD(Leevel_Log_File, flush);
PHP_METHOD(Leevel_Log_File, checkSize);
PHP_METHOD(Leevel_Log_File, normalizePath);
PHP_METHOD(Leevel_Log_File, formatMessage);
zend_object *zephir_init_properties_Leevel_Log_File(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_file___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_file_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_file_flush, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, datas, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_file_checksize, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_file_normalizepath, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_file_formatmessage, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, contexts, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_file_method_entry) {
	PHP_ME(Leevel_Log_File, __construct, arginfo_leevel_log_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_File, setOption, arginfo_leevel_log_file_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_File, flush, arginfo_leevel_log_file_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_File, checkSize, arginfo_leevel_log_file_checksize, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_File, normalizePath, arginfo_leevel_log_file_normalizepath, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_File, formatMessage, arginfo_leevel_log_file_formatmessage, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
