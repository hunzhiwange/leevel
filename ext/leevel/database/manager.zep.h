
extern zend_class_entry *leevel_database_manager_ce;

ZEPHIR_INIT_CLASS(Leevel_Database_Manager);

PHP_METHOD(Leevel_Database_Manager, normalizeOptionNamespace);
PHP_METHOD(Leevel_Database_Manager, createConnect);
PHP_METHOD(Leevel_Database_Manager, makeConnectMysql);
PHP_METHOD(Leevel_Database_Manager, normalizeConnectOption);
PHP_METHOD(Leevel_Database_Manager, parseDatabaseOption);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_manager_createconnect, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_manager_makeconnectmysql, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_manager_normalizeconnectoption, 0, 0, 1)
	ZEND_ARG_INFO(0, connect)
	ZEND_ARG_ARRAY_INFO(0, extendOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_manager_parsedatabaseoption, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, option, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_database_manager_method_entry) {
	PHP_ME(Leevel_Database_Manager, normalizeOptionNamespace, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Manager, createConnect, arginfo_leevel_database_manager_createconnect, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Manager, makeConnectMysql, arginfo_leevel_database_manager_makeconnectmysql, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Manager, normalizeConnectOption, arginfo_leevel_database_manager_normalizeconnectoption, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Manager, parseDatabaseOption, arginfo_leevel_database_manager_parsedatabaseoption, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
