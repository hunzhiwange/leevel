
extern zend_class_entry *leevel_mvc_view_ce;

ZEPHIR_INIT_CLASS(Leevel_Mvc_View);

PHP_METHOD(Leevel_Mvc_View, __construct);
PHP_METHOD(Leevel_Mvc_View, switchView);
PHP_METHOD(Leevel_Mvc_View, assign);
PHP_METHOD(Leevel_Mvc_View, getAssign);
PHP_METHOD(Leevel_Mvc_View, deleteAssign);
PHP_METHOD(Leevel_Mvc_View, clearAssign);
PHP_METHOD(Leevel_Mvc_View, display);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_view___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, theme, Leevel\\View\\IView, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_view_switchview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, theme, Leevel\\View\\IView, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_view_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_view_getassign, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_view_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_mvc_view_method_entry) {
	PHP_ME(Leevel_Mvc_View, __construct, arginfo_leevel_mvc_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Mvc_View, switchView, arginfo_leevel_mvc_view_switchview, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Mvc_View, assign, arginfo_leevel_mvc_view_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Mvc_View, getAssign, arginfo_leevel_mvc_view_getassign, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Mvc_View, deleteAssign, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Mvc_View, clearAssign, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Mvc_View, display, arginfo_leevel_mvc_view_display, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
