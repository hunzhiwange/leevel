
extern zend_class_entry *leevel_db_ce;

ZEPHIR_INIT_CLASS(Leevel_Db);

PHP_METHOD(Leevel_Db, name);

ZEPHIR_INIT_FUNCS(leevel_db_method_entry) {
	PHP_ME(Leevel_Db, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
