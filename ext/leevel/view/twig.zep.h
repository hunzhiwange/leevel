
extern zend_class_entry *leevel_view_twig_ce;

ZEPHIR_INIT_CLASS(Leevel_View_Twig);

PHP_METHOD(Leevel_View_Twig, display);
PHP_METHOD(Leevel_View_Twig, setParseResolver);
PHP_METHOD(Leevel_View_Twig, resolverParser);
PHP_METHOD(Leevel_View_Twig, parser);
PHP_METHOD(Leevel_View_Twig, renderFile);
zend_object *zephir_init_properties_Leevel_View_Twig(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_twig_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, display)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_twig_setparseresolver, 0, 0, 1)
	ZEND_ARG_INFO(0, parseResolver)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_twig_renderfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_view_twig_method_entry) {
	PHP_ME(Leevel_View_Twig, display, arginfo_leevel_view_twig_display, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Twig, setParseResolver, arginfo_leevel_view_twig_setparseresolver, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Twig, resolverParser, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Twig, parser, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Twig, renderFile, arginfo_leevel_view_twig_renderfile, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
