
extern zend_class_entry *leevel_auth_ce;

ZEPHIR_INIT_CLASS(Leevel_Auth);

PHP_METHOD(Leevel_Auth, name);

ZEPHIR_INIT_FUNCS(leevel_auth_method_entry) {
	PHP_ME(Leevel_Auth, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
