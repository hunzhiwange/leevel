
extern zend_class_entry *leevel_option_ce;

ZEPHIR_INIT_CLASS(Leevel_Option);

PHP_METHOD(Leevel_Option, name);

ZEPHIR_INIT_FUNCS(leevel_option_method_entry) {
	PHP_ME(Leevel_Option, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
