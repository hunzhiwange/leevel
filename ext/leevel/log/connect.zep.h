
extern zend_class_entry *leevel_log_connect_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_Connect);

PHP_METHOD(Leevel_Log_Connect, __construct);
PHP_METHOD(Leevel_Log_Connect, setOption);
PHP_METHOD(Leevel_Log_Connect, flush);
PHP_METHOD(Leevel_Log_Connect, getMonolog);
PHP_METHOD(Leevel_Log_Connect, normalizeHandler);
PHP_METHOD(Leevel_Log_Connect, lineFormatter);
PHP_METHOD(Leevel_Log_Connect, normalizeLevel);
PHP_METHOD(Leevel_Log_Connect, normalizeMonologLevel);
zend_object *zephir_init_properties_Leevel_Log_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_flush, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_normalizehandler, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, handler, Monolog\\Handler\\HandlerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_normalizelevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_connect_normalizemonologlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_connect_method_entry) {
	PHP_ME(Leevel_Log_Connect, __construct, arginfo_leevel_log_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_Connect, setOption, arginfo_leevel_log_connect_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Connect, flush, arginfo_leevel_log_connect_flush, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Connect, getMonolog, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Connect, normalizeHandler, arginfo_leevel_log_connect_normalizehandler, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Connect, lineFormatter, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Connect, normalizeLevel, arginfo_leevel_log_connect_normalizelevel, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Log_Connect, normalizeMonologLevel, arginfo_leevel_log_connect_normalizemonologlevel, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
