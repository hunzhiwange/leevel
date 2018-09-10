
extern zend_class_entry *leevel_event_dispatch_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_Dispatch);

PHP_METHOD(Leevel_Event_Dispatch, __construct);
PHP_METHOD(Leevel_Event_Dispatch, run);
PHP_METHOD(Leevel_Event_Dispatch, register);
PHP_METHOD(Leevel_Event_Dispatch, get);
PHP_METHOD(Leevel_Event_Dispatch, has);
PHP_METHOD(Leevel_Event_Dispatch, delete);
PHP_METHOD(Leevel_Event_Dispatch, normalizeEvent);
PHP_METHOD(Leevel_Event_Dispatch, makeSubject);
PHP_METHOD(Leevel_Event_Dispatch, prepareRegexForWildcard);
zend_object *zephir_init_properties_Leevel_Event_Dispatch(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_register, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_get, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_has, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_normalizeevent, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_makesubject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, listeners, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_dispatch_prepareregexforwildcard, 0, 0, 1)
	ZEND_ARG_INFO(0, regex)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_dispatch_method_entry) {
	PHP_ME(Leevel_Event_Dispatch, __construct, arginfo_leevel_event_dispatch___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Event_Dispatch, run, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, register, arginfo_leevel_event_dispatch_register, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, get, arginfo_leevel_event_dispatch_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, has, arginfo_leevel_event_dispatch_has, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, delete, arginfo_leevel_event_dispatch_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Dispatch, normalizeEvent, arginfo_leevel_event_dispatch_normalizeevent, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Event_Dispatch, makeSubject, arginfo_leevel_event_dispatch_makesubject, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Event_Dispatch, prepareRegexForWildcard, arginfo_leevel_event_dispatch_prepareregexforwildcard, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
