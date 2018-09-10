
extern zend_class_entry *leevel_database_ce;

ZEPHIR_INIT_CLASS(Leevel_Database);

PHP_METHOD(Leevel_Database, name);

ZEPHIR_INIT_FUNCS(leevel_database_method_entry) {
	PHP_ME(Leevel_Database, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
