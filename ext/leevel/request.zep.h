
extern zend_class_entry *leevel_request_ce;

ZEPHIR_INIT_CLASS(Leevel_Request);

PHP_METHOD(Leevel_Request, name);

ZEPHIR_INIT_FUNCS(leevel_request_method_entry) {
	PHP_ME(Leevel_Request, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
