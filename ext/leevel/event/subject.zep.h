
extern zend_class_entry *leevel_event_subject_ce;

ZEPHIR_INIT_CLASS(Leevel_Event_Subject);

PHP_METHOD(Leevel_Event_Subject, __construct);
PHP_METHOD(Leevel_Event_Subject, attach);
PHP_METHOD(Leevel_Event_Subject, detach);
PHP_METHOD(Leevel_Event_Subject, notify);
PHP_METHOD(Leevel_Event_Subject, attachs);
zend_object *zephir_init_properties_Leevel_Event_Subject(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_subject___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_subject_attach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, observer, SplObserver, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_subject_detach, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, observer, SplObserver, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_event_subject_attachs, 0, 0, 1)
	ZEND_ARG_INFO(0, observer)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_event_subject_method_entry) {
	PHP_ME(Leevel_Event_Subject, __construct, arginfo_leevel_event_subject___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Event_Subject, attach, arginfo_leevel_event_subject_attach, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Subject, detach, arginfo_leevel_event_subject_detach, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Subject, notify, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Event_Subject, attachs, arginfo_leevel_event_subject_attachs, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
