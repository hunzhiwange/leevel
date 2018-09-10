
extern zend_class_entry *leevel_manager_manager_ce;

ZEPHIR_INIT_CLASS(Leevel_Manager_Manager);

PHP_METHOD(Leevel_Manager_Manager, __construct);
PHP_METHOD(Leevel_Manager_Manager, __call);
PHP_METHOD(Leevel_Manager_Manager, container);
PHP_METHOD(Leevel_Manager_Manager, connect);
PHP_METHOD(Leevel_Manager_Manager, reconnect);
PHP_METHOD(Leevel_Manager_Manager, disconnect);
PHP_METHOD(Leevel_Manager_Manager, getConnects);
PHP_METHOD(Leevel_Manager_Manager, getDefaultDriver);
PHP_METHOD(Leevel_Manager_Manager, setDefaultDriver);
PHP_METHOD(Leevel_Manager_Manager, getContainerOption);
PHP_METHOD(Leevel_Manager_Manager, setContainerOption);
PHP_METHOD(Leevel_Manager_Manager, normalizeOptionNamespace);
PHP_METHOD(Leevel_Manager_Manager, createConnect);
PHP_METHOD(Leevel_Manager_Manager, normalizeOptionName);
PHP_METHOD(Leevel_Manager_Manager, makeConnect);
PHP_METHOD(Leevel_Manager_Manager, createConnectCommon);
PHP_METHOD(Leevel_Manager_Manager, parseOptionAndUnique);
PHP_METHOD(Leevel_Manager_Manager, parseOptionParameter);
PHP_METHOD(Leevel_Manager_Manager, normalizeUnique);
PHP_METHOD(Leevel_Manager_Manager, normalizeConnectOption);
PHP_METHOD(Leevel_Manager_Manager, getCommonOption);
PHP_METHOD(Leevel_Manager_Manager, filterCommonOption);
PHP_METHOD(Leevel_Manager_Manager, defaultCommonOption);
PHP_METHOD(Leevel_Manager_Manager, getConnectOption);
PHP_METHOD(Leevel_Manager_Manager, filterNullOfOption);
zend_object *zephir_init_properties_Leevel_Manager_Manager(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_connect, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_reconnect, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_disconnect, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_setdefaultdriver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_getcontaineroption, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_setcontaineroption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_normalizeoptionname, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_makeconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_createconnectcommon, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_parseoptionandunique, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_parseoptionparameter, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_normalizeunique, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_normalizeconnectoption, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
	ZEND_ARG_ARRAY_INFO(0, extendOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_filtercommonoption, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_getconnectoption, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_manager_manager_filternullofoption, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_manager_manager_method_entry) {
	PHP_ME(Leevel_Manager_Manager, __construct, arginfo_leevel_manager_manager___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Manager_Manager, __call, arginfo_leevel_manager_manager___call, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, container, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, connect, arginfo_leevel_manager_manager_connect, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, reconnect, arginfo_leevel_manager_manager_reconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, disconnect, arginfo_leevel_manager_manager_disconnect, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, getConnects, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, getDefaultDriver, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, setDefaultDriver, arginfo_leevel_manager_manager_setdefaultdriver, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, getContainerOption, arginfo_leevel_manager_manager_getcontaineroption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, setContainerOption, arginfo_leevel_manager_manager_setcontaineroption, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Manager_Manager, normalizeOptionNamespace, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, createConnect, arginfo_leevel_manager_manager_createconnect, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, normalizeOptionName, arginfo_leevel_manager_manager_normalizeoptionname, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, makeConnect, arginfo_leevel_manager_manager_makeconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, createConnectCommon, arginfo_leevel_manager_manager_createconnectcommon, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, parseOptionAndUnique, arginfo_leevel_manager_manager_parseoptionandunique, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, parseOptionParameter, arginfo_leevel_manager_manager_parseoptionparameter, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, normalizeUnique, arginfo_leevel_manager_manager_normalizeunique, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, normalizeConnectOption, arginfo_leevel_manager_manager_normalizeconnectoption, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, getCommonOption, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, filterCommonOption, arginfo_leevel_manager_manager_filtercommonoption, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, defaultCommonOption, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, getConnectOption, arginfo_leevel_manager_manager_getconnectoption, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Manager_Manager, filterNullOfOption, arginfo_leevel_manager_manager_filternullofoption, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
