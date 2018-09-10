
extern zend_class_entry *leevel_option_ioption_ce;

ZEPHIR_INIT_CLASS(Leevel_Option_IOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_ioption_has, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_ioption_get, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_ioption_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_ioption_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_option_ioption_reset, 0, 0, 0)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_option_ioption_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Option_IOption, has, arginfo_leevel_option_ioption_has)
	PHP_ABSTRACT_ME(Leevel_Option_IOption, get, arginfo_leevel_option_ioption_get)
	PHP_ABSTRACT_ME(Leevel_Option_IOption, all, NULL)
	PHP_ABSTRACT_ME(Leevel_Option_IOption, set, arginfo_leevel_option_ioption_set)
	PHP_ABSTRACT_ME(Leevel_Option_IOption, delete, arginfo_leevel_option_ioption_delete)
	PHP_ABSTRACT_ME(Leevel_Option_IOption, reset, arginfo_leevel_option_ioption_reset)
	PHP_FE_END
};
