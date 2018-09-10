
extern zend_class_entry *leevel_throttler_ce;

ZEPHIR_INIT_CLASS(Leevel_Throttler);

PHP_METHOD(Leevel_Throttler, name);

ZEPHIR_INIT_FUNCS(leevel_throttler_method_entry) {
	PHP_ME(Leevel_Throttler, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
