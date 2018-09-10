
extern zend_class_entry *leevel_view_phpui_ce;

ZEPHIR_INIT_CLASS(Leevel_View_Phpui);

PHP_METHOD(Leevel_View_Phpui, display);
zend_object *zephir_init_properties_Leevel_View_Phpui(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_phpui_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, display)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_view_phpui_method_entry) {
	PHP_ME(Leevel_View_Phpui, display, arginfo_leevel_view_phpui_display, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
