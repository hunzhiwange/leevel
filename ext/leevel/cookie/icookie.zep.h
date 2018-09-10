
extern zend_class_entry *leevel_cookie_icookie_ce;

ZEPHIR_INIT_CLASS(Leevel_Cookie_ICookie);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_set, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_arr, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_arrdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_cookie_icookie_clear, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_cookie_icookie_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, setOption, arginfo_leevel_cookie_icookie_setoption)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, set, arginfo_leevel_cookie_icookie_set)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, put, arginfo_leevel_cookie_icookie_put)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, push, arginfo_leevel_cookie_icookie_push)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, merge, arginfo_leevel_cookie_icookie_merge)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, pop, arginfo_leevel_cookie_icookie_pop)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, arr, arginfo_leevel_cookie_icookie_arr)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, arrDelete, arginfo_leevel_cookie_icookie_arrdelete)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, get, arginfo_leevel_cookie_icookie_get)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, delete, arginfo_leevel_cookie_icookie_delete)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, clear, arginfo_leevel_cookie_icookie_clear)
	PHP_ABSTRACT_ME(Leevel_Cookie_ICookie, all, NULL)
	PHP_FE_END
};
