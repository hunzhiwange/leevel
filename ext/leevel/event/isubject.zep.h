
extern zend_class_entry *leevel_event_isubject_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_ISubject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_isubject_attachs, 0, 0, 1)
	ZEND_ARG_INFO(0, observer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_isubject_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Event_ISubject, attachs, arginfo_leevel_event_isubject_attachs)
	PHP_FE_END
};
