
extern zend_class_entry *leevel_response_ce;

ZEPHIR_INIT_CLASS(Leevel_Response);

PHP_METHOD(Leevel_Response, name);

ZEPHIR_INIT_FUNCS(leevel_response_method_entry) {
	PHP_ME(Leevel_Response, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
