
extern zend_class_entry *leevel_log_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_Provider_Register);

PHP_METHOD(Leevel_Log_Provider_Register, __construct);
PHP_METHOD(Leevel_Log_Provider_Register, register);
PHP_METHOD(Leevel_Log_Provider_Register, providers);
PHP_METHOD(Leevel_Log_Provider_Register, logs);
PHP_METHOD(Leevel_Log_Provider_Register, logsClosure);
PHP_METHOD(Leevel_Log_Provider_Register, log);
PHP_METHOD(Leevel_Log_Provider_Register, logClosure);
PHP_METHOD(Leevel_Log_Provider_Register, middleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_provider_register_logsclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_provider_register_logclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_provider_register_method_entry) {
	PHP_ME(Leevel_Log_Provider_Register, __construct, arginfo_leevel_log_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Log_Provider_Register, logs, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Provider_Register, logsClosure, arginfo_leevel_log_provider_register_logsclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Provider_Register, log, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Provider_Register, logClosure, arginfo_leevel_log_provider_register_logclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Provider_Register, middleware, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
