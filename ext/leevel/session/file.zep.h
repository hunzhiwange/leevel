
extern zend_class_entry *leevel_session_file_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_File);

PHP_METHOD(Leevel_Session_File, __construct);
PHP_METHOD(Leevel_Session_File, createCache);
zend_object *zephir_init_properties_Leevel_Session_File(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_file___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_file_method_entry) {
	PHP_ME(Leevel_Session_File, __construct, arginfo_leevel_session_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Session_File, createCache, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
