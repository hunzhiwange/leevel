
extern zend_class_entry *leevel_cache_cache_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache_Cache);

PHP_METHOD(Leevel_Cache_Cache, __construct);
PHP_METHOD(Leevel_Cache_Cache, __call);
PHP_METHOD(Leevel_Cache_Cache, put);
PHP_METHOD(Leevel_Cache_Cache, macro);
PHP_METHOD(Leevel_Cache_Cache, hasMacro);
PHP_METHOD(Leevel_Cache_Cache, callStaticMacro);
PHP_METHOD(Leevel_Cache_Cache, callMacro);
void zephir_init_static_properties_Leevel_Cache_Cache(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connect, Leevel\\Cache\\IConnect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cache_cache_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cache_cache_method_entry) {
	PHP_ME(Leevel_Cache_Cache, __construct, arginfo_leevel_cache_cache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Cache_Cache, __call, arginfo_leevel_cache_cache___call, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Cache, put, arginfo_leevel_cache_cache_put, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Cache_Cache, macro, arginfo_leevel_cache_cache_macro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Cache_Cache, hasMacro, arginfo_leevel_cache_cache_hasmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Cache_Cache, callStaticMacro, arginfo_leevel_cache_cache_callstaticmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Cache_Cache, callMacro, arginfo_leevel_cache_cache_callmacro, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
