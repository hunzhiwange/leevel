
extern zend_class_entry *leevel_view_connect_ce;

ZEPHIR_INIT_CLASS(Leevel_View_Connect);

PHP_METHOD(Leevel_View_Connect, __construct);
PHP_METHOD(Leevel_View_Connect, setOption);
PHP_METHOD(Leevel_View_Connect, setVar);
PHP_METHOD(Leevel_View_Connect, getVar);
PHP_METHOD(Leevel_View_Connect, deleteVar);
PHP_METHOD(Leevel_View_Connect, clearVar);
PHP_METHOD(Leevel_View_Connect, parseDisplayFile);
PHP_METHOD(Leevel_View_Connect, parseFile);
PHP_METHOD(Leevel_View_Connect, formatFile);
zend_object *zephir_init_properties_Leevel_View_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect_setvar, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect_getvar, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect_parsedisplayfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect_parsefile, 0, 0, 1)
	ZEND_ARG_INFO(0, tpl)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_connect_formatfile, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_view_connect_method_entry) {
	PHP_ME(Leevel_View_Connect, __construct, arginfo_leevel_view_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_View_Connect, setOption, arginfo_leevel_view_connect_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Connect, setVar, arginfo_leevel_view_connect_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Connect, getVar, arginfo_leevel_view_connect_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Connect, deleteVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Connect, clearVar, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Connect, parseDisplayFile, arginfo_leevel_view_connect_parsedisplayfile, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Connect, parseFile, arginfo_leevel_view_connect_parsefile, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Connect, formatFile, arginfo_leevel_view_connect_formatfile, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
