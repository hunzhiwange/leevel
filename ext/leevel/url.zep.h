
extern zend_class_entry *leevel_url_ce;

ZEPHIR_INIT_CLASS(Leevel_Url);

PHP_METHOD(Leevel_Url, name);

ZEPHIR_INIT_FUNCS(leevel_url_method_entry) {
	PHP_ME(Leevel_Url, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
