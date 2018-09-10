
extern zend_class_entry *leevel_di_icontainer_ce;

ZEPHIR_INIT_CLASS(Leevel_Di_IContainer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, share)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_instance, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_singleton, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_share, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, closure, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_alias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_call, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_icontainer_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_di_icontainer_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, bind, arginfo_leevel_di_icontainer_bind)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, instance, arginfo_leevel_di_icontainer_instance)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, singleton, arginfo_leevel_di_icontainer_singleton)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, share, arginfo_leevel_di_icontainer_share)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, alias, arginfo_leevel_di_icontainer_alias)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, make, arginfo_leevel_di_icontainer_make)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, call, arginfo_leevel_di_icontainer_call)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, remove, arginfo_leevel_di_icontainer_remove)
	PHP_ABSTRACT_ME(Leevel_Di_IContainer, exists, arginfo_leevel_di_icontainer_exists)
	PHP_FE_END
};
