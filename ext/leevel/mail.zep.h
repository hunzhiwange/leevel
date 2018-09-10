
extern zend_class_entry *leevel_mail_ce;

ZEPHIR_INIT_CLASS(Leevel_Mail);

PHP_METHOD(Leevel_Mail, name);

ZEPHIR_INIT_FUNCS(leevel_mail_method_entry) {
	PHP_ME(Leevel_Mail, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
