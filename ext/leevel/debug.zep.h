
extern zend_class_entry *leevel_debug_ce;

ZEPHIR_INIT_CLASS(Leevel_Debug);

PHP_METHOD(Leevel_Debug, name);

ZEPHIR_INIT_FUNCS(leevel_debug_method_entry) {
	PHP_ME(Leevel_Debug, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
