
extern zend_class_entry *leevel_session_redis_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Redis);

PHP_METHOD(Leevel_Session_Redis, __construct);
PHP_METHOD(Leevel_Session_Redis, createCache);
zend_object *zephir_init_properties_Leevel_Session_Redis(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_redis___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_redis_method_entry) {
	PHP_ME(Leevel_Session_Redis, __construct, arginfo_leevel_session_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Session_Redis, createCache, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
