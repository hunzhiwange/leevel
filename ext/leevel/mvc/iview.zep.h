
extern zend_class_entry *leevel_mvc_iview_ce;

ZEPHIR_INIT_CLASS(Leevel_Mvc_IView);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_iview_switchview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, theme, Leevel\\View\\IView, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_iview_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_iview_getassign, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_iview_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_mvc_iview_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Mvc_IView, switchView, arginfo_leevel_mvc_iview_switchview)
	PHP_ABSTRACT_ME(Leevel_Mvc_IView, assign, arginfo_leevel_mvc_iview_assign)
	PHP_ABSTRACT_ME(Leevel_Mvc_IView, getAssign, arginfo_leevel_mvc_iview_getassign)
	PHP_ABSTRACT_ME(Leevel_Mvc_IView, deleteAssign, NULL)
	PHP_ABSTRACT_ME(Leevel_Mvc_IView, clearAssign, NULL)
	PHP_ABSTRACT_ME(Leevel_Mvc_IView, display, arginfo_leevel_mvc_iview_display)
	PHP_FE_END
};
