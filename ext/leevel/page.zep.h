
extern zend_class_entry *leevel_page_ce;

ZEPHIR_INIT_CLASS(Leevel_Page);

PHP_METHOD(Leevel_Page, name);

ZEPHIR_INIT_FUNCS(leevel_page_method_entry) {
	PHP_ME(Leevel_Page, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
