
extern zend_class_entry *leevel_event_ce;

ZEPHIR_INIT_CLASS(Leevel_Event);

PHP_METHOD(Leevel_Event, name);

ZEPHIR_INIT_FUNCS(leevel_event_method_entry) {
	PHP_ME(Leevel_Event, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
