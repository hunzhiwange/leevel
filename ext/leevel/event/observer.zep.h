
extern zend_class_entry *leevel_event_observer_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_Observer);

PHP_METHOD(Leevel_Event_Observer, setHandle);
PHP_METHOD(Leevel_Event_Observer, __invoke);
PHP_METHOD(Leevel_Event_Observer, update);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_observer_sethandle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, handle, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_observer_update, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, subject, SplSubject, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_observer_method_entry) {
	PHP_ME(Leevel_Event_Observer, setHandle, arginfo_leevel_event_observer_sethandle, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Observer, __invoke, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Observer, update, arginfo_leevel_event_observer_update, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
