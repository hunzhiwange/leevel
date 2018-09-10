
extern zend_class_entry *leevel_support_type_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_Type);

PHP_METHOD(Leevel_Support_Type, vars);
PHP_METHOD(Leevel_Support_Type, num);
PHP_METHOD(Leevel_Support_Type, ints);
PHP_METHOD(Leevel_Support_Type, these);
PHP_METHOD(Leevel_Support_Type, arr);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_type_vars, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_type_num, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_type_ints, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_type_these, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, types)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_type_arr, 0, 0, 2)
	ZEND_ARG_INFO(0, arr)
	ZEND_ARG_ARRAY_INFO(0, types, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_support_type_method_entry) {
	PHP_ME(Leevel_Support_Type, vars, arginfo_leevel_support_type_vars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Type, num, arginfo_leevel_support_type_num, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Type, ints, arginfo_leevel_support_type_ints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Type, these, arginfo_leevel_support_type_these, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Type, arr, arginfo_leevel_support_type_arr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
