
extern zend_class_entry *leevel_log_log_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_Log);

PHP_METHOD(Leevel_Log_Log, __construct);
PHP_METHOD(Leevel_Log_Log, setOption);
PHP_METHOD(Leevel_Log_Log, emergency);
PHP_METHOD(Leevel_Log_Log, alert);
PHP_METHOD(Leevel_Log_Log, critical);
PHP_METHOD(Leevel_Log_Log, error);
PHP_METHOD(Leevel_Log_Log, warning);
PHP_METHOD(Leevel_Log_Log, notice);
PHP_METHOD(Leevel_Log_Log, info);
PHP_METHOD(Leevel_Log_Log, debug);
PHP_METHOD(Leevel_Log_Log, log);
PHP_METHOD(Leevel_Log_Log, flush);
PHP_METHOD(Leevel_Log_Log, clear);
PHP_METHOD(Leevel_Log_Log, all);
PHP_METHOD(Leevel_Log_Log, count);
PHP_METHOD(Leevel_Log_Log, filter);
PHP_METHOD(Leevel_Log_Log, processor);
PHP_METHOD(Leevel_Log_Log, isMonolog);
PHP_METHOD(Leevel_Log_Log, getMonolog);
PHP_METHOD(Leevel_Log_Log, getConnect);
PHP_METHOD(Leevel_Log_Log, saveStore);
zend_object *zephir_init_properties_Leevel_Log_Log(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connect, Leevel\\Log\\IConnect, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_all, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_count, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_filter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_processor, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, processor, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_log_savestore, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_log_method_entry) {
	PHP_ME(Leevel_Log_Log, __construct, arginfo_leevel_log_log___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_Log, setOption, arginfo_leevel_log_log_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, emergency, arginfo_leevel_log_log_emergency, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, alert, arginfo_leevel_log_log_alert, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, critical, arginfo_leevel_log_log_critical, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, error, arginfo_leevel_log_log_error, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, warning, arginfo_leevel_log_log_warning, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, notice, arginfo_leevel_log_log_notice, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, info, arginfo_leevel_log_log_info, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, debug, arginfo_leevel_log_log_debug, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, log, arginfo_leevel_log_log_log, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, clear, arginfo_leevel_log_log_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, all, arginfo_leevel_log_log_all, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, count, arginfo_leevel_log_log_count, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, filter, arginfo_leevel_log_log_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, processor, arginfo_leevel_log_log_processor, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, isMonolog, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, getMonolog, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, getConnect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Log, saveStore, arginfo_leevel_log_log_savestore, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
