
extern zend_class_entry *leevel_database_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Database_Provider_Register);

PHP_METHOD(Leevel_Database_Provider_Register, __construct);
PHP_METHOD(Leevel_Database_Provider_Register, register);
PHP_METHOD(Leevel_Database_Provider_Register, providers);
PHP_METHOD(Leevel_Database_Provider_Register, databases);
PHP_METHOD(Leevel_Database_Provider_Register, databasesClosure);
PHP_METHOD(Leevel_Database_Provider_Register, database);
PHP_METHOD(Leevel_Database_Provider_Register, databaseClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_provider_register_databasesclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_database_provider_register_databaseclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_database_provider_register_method_entry) {
	PHP_ME(Leevel_Database_Provider_Register, __construct, arginfo_leevel_database_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Database_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Database_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Database_Provider_Register, databases, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Provider_Register, databasesClosure, arginfo_leevel_database_provider_register_databasesclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Provider_Register, database, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Database_Provider_Register, databaseClosure, arginfo_leevel_database_provider_register_databaseclosure, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
