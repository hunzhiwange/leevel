
extern zend_class_entry *leevel_mail_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Mail_Provider_Register);

PHP_METHOD(Leevel_Mail_Provider_Register, __construct);
PHP_METHOD(Leevel_Mail_Provider_Register, register);
PHP_METHOD(Leevel_Mail_Provider_Register, providers);
PHP_METHOD(Leevel_Mail_Provider_Register, mails);
PHP_METHOD(Leevel_Mail_Provider_Register, mailsClosure);
PHP_METHOD(Leevel_Mail_Provider_Register, mail);
PHP_METHOD(Leevel_Mail_Provider_Register, mailClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mail_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mail_provider_register_mailsclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mail_provider_register_mailclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_mail_provider_register_method_entry) {
	PHP_ME(Leevel_Mail_Provider_Register, __construct, arginfo_leevel_mail_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Mail_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Mail_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Mail_Provider_Register, mails, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Mail_Provider_Register, mailsClosure, arginfo_leevel_mail_provider_register_mailsclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Mail_Provider_Register, mail, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Mail_Provider_Register, mailClosure, arginfo_leevel_mail_provider_register_mailclosure, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
