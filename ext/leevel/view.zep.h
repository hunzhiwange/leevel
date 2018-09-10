
extern zend_class_entry *leevel_view_ce;

ZEPHIR_INIT_CLASS(Leevel_View);

PHP_METHOD(Leevel_View, name);

ZEPHIR_INIT_FUNCS(leevel_view_method_entry) {
	PHP_ME(Leevel_View, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
