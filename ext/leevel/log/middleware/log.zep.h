
extern zend_class_entry *leevel_log_middleware_log_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_Middleware_Log);

PHP_METHOD(Leevel_Log_Middleware_Log, __construct);
PHP_METHOD(Leevel_Log_Middleware_Log, terminate);
PHP_METHOD(Leevel_Log_Middleware_Log, saveLog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_middleware_log___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, manager, Leevel\\Log\\Manager, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_middleware_log_terminate, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, next, Closure, 0)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_OBJ_INFO(0, response, Leevel\\Http\\IResponse, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_middleware_log_method_entry) {
	PHP_ME(Leevel_Log_Middleware_Log, __construct, arginfo_leevel_log_middleware_log___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Log_Middleware_Log, terminate, arginfo_leevel_log_middleware_log_terminate, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Log_Middleware_Log, saveLog, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
