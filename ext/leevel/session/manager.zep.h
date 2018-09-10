
extern zend_class_entry *leevel_session_manager_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Manager);

PHP_METHOD(Leevel_Session_Manager, getSessionOption);
PHP_METHOD(Leevel_Session_Manager, normalizeOptionNamespace);
PHP_METHOD(Leevel_Session_Manager, createConnect);
PHP_METHOD(Leevel_Session_Manager, makeConnectNulls);
PHP_METHOD(Leevel_Session_Manager, makeConnectFile);
PHP_METHOD(Leevel_Session_Manager, makeConnectRedis);
PHP_METHOD(Leevel_Session_Manager, getConnectOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_makeconnectnulls, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_makeconnectfile, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_makeconnectredis, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_manager_getconnectoption, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_manager_method_entry) {
	PHP_ME(Leevel_Session_Manager, getSessionOption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Manager, normalizeOptionNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, createConnect, arginfo_leevel_session_manager_createconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, makeConnectNulls, arginfo_leevel_session_manager_makeconnectnulls, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, makeConnectFile, arginfo_leevel_session_manager_makeconnectfile, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, makeConnectRedis, arginfo_leevel_session_manager_makeconnectredis, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Manager, getConnectOption, arginfo_leevel_session_manager_getconnectoption, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
