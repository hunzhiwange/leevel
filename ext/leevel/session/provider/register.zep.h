
extern zend_class_entry *leevel_session_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Provider_Register);

PHP_METHOD(Leevel_Session_Provider_Register, __construct);
PHP_METHOD(Leevel_Session_Provider_Register, register);
PHP_METHOD(Leevel_Session_Provider_Register, providers);
PHP_METHOD(Leevel_Session_Provider_Register, sessions);
PHP_METHOD(Leevel_Session_Provider_Register, sessionsClosure);
PHP_METHOD(Leevel_Session_Provider_Register, session);
PHP_METHOD(Leevel_Session_Provider_Register, sessionClosure);
PHP_METHOD(Leevel_Session_Provider_Register, middleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_provider_register_sessionsclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_provider_register_sessionclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_provider_register_method_entry) {
	PHP_ME(Leevel_Session_Provider_Register, __construct, arginfo_leevel_session_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Session_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Session_Provider_Register, sessions, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Provider_Register, sessionsClosure, arginfo_leevel_session_provider_register_sessionsclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Provider_Register, session, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Provider_Register, sessionClosure, arginfo_leevel_session_provider_register_sessionclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Provider_Register, middleware, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
