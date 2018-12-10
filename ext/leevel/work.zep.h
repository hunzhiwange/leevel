
extern zend_class_entry *leevel_work_ce;

ZEPHIR_INIT_CLASS(Leevel_Work);

PHP_METHOD(Leevel_Work, name);

ZEPHIR_INIT_FUNCS(leevel_work_method_entry) {
	PHP_ME(Leevel_Work, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
