
extern zend_class_entry *leevel_auth_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Auth_Provider_Register);

PHP_METHOD(Leevel_Auth_Provider_Register, __construct);
PHP_METHOD(Leevel_Auth_Provider_Register, register);
PHP_METHOD(Leevel_Auth_Provider_Register, providers);
PHP_METHOD(Leevel_Auth_Provider_Register, auths);
PHP_METHOD(Leevel_Auth_Provider_Register, authsClosure);
PHP_METHOD(Leevel_Auth_Provider_Register, auth);
PHP_METHOD(Leevel_Auth_Provider_Register, authClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_auth_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_auth_provider_register_authsclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_auth_provider_register_authclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_auth_provider_register_method_entry) {
	PHP_ME(Leevel_Auth_Provider_Register, __construct, arginfo_leevel_auth_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Auth_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Auth_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Auth_Provider_Register, auths, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Auth_Provider_Register, authsClosure, arginfo_leevel_auth_provider_register_authsclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Auth_Provider_Register, auth, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Auth_Provider_Register, authClosure, arginfo_leevel_auth_provider_register_authclosure, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
