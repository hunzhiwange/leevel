
extern zend_class_entry *leevel_throttler_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Throttler_Provider_Register);

PHP_METHOD(Leevel_Throttler_Provider_Register, __construct);
PHP_METHOD(Leevel_Throttler_Provider_Register, register);
PHP_METHOD(Leevel_Throttler_Provider_Register, providers);
PHP_METHOD(Leevel_Throttler_Provider_Register, isDeferred);
PHP_METHOD(Leevel_Throttler_Provider_Register, throttler);
PHP_METHOD(Leevel_Throttler_Provider_Register, throttlerClosure);
PHP_METHOD(Leevel_Throttler_Provider_Register, middleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_throttler_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_throttler_provider_register_throttlerclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_throttler_provider_register_method_entry) {
	PHP_ME(Leevel_Throttler_Provider_Register, __construct, arginfo_leevel_throttler_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Throttler_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Throttler_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Throttler_Provider_Register, isDeferred, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Throttler_Provider_Register, throttler, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Throttler_Provider_Register, throttlerClosure, arginfo_leevel_throttler_provider_register_throttlerclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Throttler_Provider_Register, middleware, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
