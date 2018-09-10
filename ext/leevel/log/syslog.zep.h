
extern zend_class_entry *leevel_log_syslog_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_Syslog);

PHP_METHOD(Leevel_Log_Syslog, __construct);
PHP_METHOD(Leevel_Log_Syslog, makeSyslogHandler);
zend_object *zephir_init_properties_Leevel_Log_Syslog(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_syslog___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_syslog_method_entry) {
	PHP_ME(Leevel_Log_Syslog, __construct, arginfo_leevel_log_syslog___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_Syslog, makeSyslogHandler, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
