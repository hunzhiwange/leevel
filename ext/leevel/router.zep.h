
extern zend_class_entry *leevel_router_ce;

ZEPHIR_INIT_CLASS(Leevel_Router);

PHP_METHOD(Leevel_Router, name);

ZEPHIR_INIT_FUNCS(leevel_router_method_entry) {
	PHP_ME(Leevel_Router, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
