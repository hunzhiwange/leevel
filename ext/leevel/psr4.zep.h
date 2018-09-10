
extern zend_class_entry *leevel_psr4_ce;

ZEPHIR_INIT_CLASS(Leevel_Psr4);

PHP_METHOD(Leevel_Psr4, name);

ZEPHIR_INIT_FUNCS(leevel_psr4_method_entry) {
	PHP_ME(Leevel_Psr4, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
