
extern zend_class_entry *leevel_validate_ce;

ZEPHIR_INIT_CLASS(Leevel_Validate);

PHP_METHOD(Leevel_Validate, name);

ZEPHIR_INIT_FUNCS(leevel_validate_method_entry) {
	PHP_ME(Leevel_Validate, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
