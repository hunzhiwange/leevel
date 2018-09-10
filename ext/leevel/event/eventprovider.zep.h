
extern zend_class_entry *leevel_event_eventprovider_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_EventProvider);

PHP_METHOD(Leevel_Event_EventProvider, bootstrap);
PHP_METHOD(Leevel_Event_EventProvider, register);
PHP_METHOD(Leevel_Event_EventProvider, get);
zend_object *zephir_init_properties_Leevel_Event_EventProvider(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_eventprovider_bootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, dispatch, Leevel\\Event\\IDispatch, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_eventprovider_method_entry) {
	PHP_ME(Leevel_Event_EventProvider, bootstrap, arginfo_leevel_event_eventprovider_bootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_EventProvider, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_EventProvider, get, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
