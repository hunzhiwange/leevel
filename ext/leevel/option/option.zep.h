
extern zend_class_entry *leevel_option_option_ce;

ZEPHIR_INIT_CLASS(Leevel_Option_Option);

PHP_METHOD(Leevel_Option_Option, __construct);
PHP_METHOD(Leevel_Option_Option, has);
PHP_METHOD(Leevel_Option_Option, get);
PHP_METHOD(Leevel_Option_Option, all);
PHP_METHOD(Leevel_Option_Option, set);
PHP_METHOD(Leevel_Option_Option, delete);
PHP_METHOD(Leevel_Option_Option, reset);
PHP_METHOD(Leevel_Option_Option, offsetExists);
PHP_METHOD(Leevel_Option_Option, offsetGet);
PHP_METHOD(Leevel_Option_Option, offsetSet);
PHP_METHOD(Leevel_Option_Option, offsetUnset);
PHP_METHOD(Leevel_Option_Option, setRecursion);
PHP_METHOD(Leevel_Option_Option, deleteRecursion);
PHP_METHOD(Leevel_Option_Option, parseNamespace);
zend_object *zephir_init_properties_Leevel_Option_Option(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_has, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_reset, 0, 0, 0)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_setrecursion, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, part, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_deleterecursion, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, part, 0)
	ZEND_ARG_ARRAY_INFO(0, result, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_option_parsenamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_option_option_method_entry) {
	PHP_ME(Leevel_Option_Option, __construct, arginfo_leevel_option_option___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Option_Option, has, arginfo_leevel_option_option_has, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, get, arginfo_leevel_option_option_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, set, arginfo_leevel_option_option_set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, delete, arginfo_leevel_option_option_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, reset, arginfo_leevel_option_option_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, offsetExists, arginfo_leevel_option_option_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, offsetGet, arginfo_leevel_option_option_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, offsetSet, arginfo_leevel_option_option_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, offsetUnset, arginfo_leevel_option_option_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Option_Option, setRecursion, arginfo_leevel_option_option_setrecursion, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Option_Option, deleteRecursion, arginfo_leevel_option_option_deleterecursion, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Option_Option, parseNamespace, arginfo_leevel_option_option_parsenamespace, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
