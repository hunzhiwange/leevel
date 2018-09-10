
extern zend_class_entry *leevel_cookie_ce;

ZEPHIR_INIT_CLASS(Leevel_Cookie);

PHP_METHOD(Leevel_Cookie, name);

ZEPHIR_INIT_FUNCS(leevel_cookie_method_entry) {
	PHP_ME(Leevel_Cookie, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
