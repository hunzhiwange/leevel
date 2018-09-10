
extern zend_class_entry *leevel_leevel_ce;

ZEPHIR_INIT_CLASS(Leevel_Leevel);

PHP_METHOD(Leevel_Leevel, name);

ZEPHIR_INIT_FUNCS(leevel_leevel_method_entry) {
	PHP_ME(Leevel_Leevel, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
