
extern zend_class_entry *leevel_filesystem_ce;

ZEPHIR_INIT_CLASS(Leevel_Filesystem);

PHP_METHOD(Leevel_Filesystem, name);

ZEPHIR_INIT_FUNCS(leevel_filesystem_method_entry) {
	PHP_ME(Leevel_Filesystem, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
