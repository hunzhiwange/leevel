
extern zend_class_entry *leevel_http_headerbag_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_HeaderBag);

PHP_METHOD(Leevel_Http_HeaderBag, __construct);
PHP_METHOD(Leevel_Http_HeaderBag, replace);
PHP_METHOD(Leevel_Http_HeaderBag, add);
PHP_METHOD(Leevel_Http_HeaderBag, __toString);
PHP_METHOD(Leevel_Http_HeaderBag, normalize);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_headerbag___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_headerbag_replace, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_headerbag_add, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, elements, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_headerbag_normalize, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_headerbag_method_entry) {
	PHP_ME(Leevel_Http_HeaderBag, __construct, arginfo_leevel_http_headerbag___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Http_HeaderBag, replace, arginfo_leevel_http_headerbag_replace, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_HeaderBag, add, arginfo_leevel_http_headerbag_add, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_HeaderBag, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_HeaderBag, normalize, arginfo_leevel_http_headerbag_normalize, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
