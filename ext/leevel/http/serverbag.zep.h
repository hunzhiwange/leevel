
extern zend_class_entry *leevel_http_serverbag_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_ServerBag);

PHP_METHOD(Leevel_Http_ServerBag, getHeaders);

ZEPHIR_INIT_FUNCS(leevel_http_serverbag_method_entry) {
	PHP_ME(Leevel_Http_ServerBag, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
