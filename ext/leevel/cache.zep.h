
extern zend_class_entry *leevel_cache_ce;

ZEPHIR_INIT_CLASS(Leevel_Cache);

PHP_METHOD(Leevel_Cache, name);

ZEPHIR_INIT_FUNCS(leevel_cache_method_entry) {
	PHP_ME(Leevel_Cache, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
