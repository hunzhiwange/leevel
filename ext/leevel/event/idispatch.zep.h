
extern zend_class_entry *leevel_event_idispatch_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_IDispatch);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_idispatch_register, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, listener)
	ZEND_ARG_INFO(0, priority)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_idispatch_get, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_idispatch_has, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_idispatch_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, event)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_idispatch_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Event_IDispatch, run, NULL)
	PHP_ABSTRACT_ME(Leevel_Event_IDispatch, register, arginfo_leevel_event_idispatch_register)
	PHP_ABSTRACT_ME(Leevel_Event_IDispatch, get, arginfo_leevel_event_idispatch_get)
	PHP_ABSTRACT_ME(Leevel_Event_IDispatch, has, arginfo_leevel_event_idispatch_has)
	PHP_ABSTRACT_ME(Leevel_Event_IDispatch, delete, arginfo_leevel_event_idispatch_delete)
	PHP_FE_END
};
