
extern zend_class_entry *leevel_session_ce;

ZEPHIR_INIT_CLASS(Leevel_Session);

PHP_METHOD(Leevel_Session, name);

ZEPHIR_INIT_FUNCS(leevel_session_method_entry) {
	PHP_ME(Leevel_Session, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
