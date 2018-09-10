
extern zend_class_entry *leevel_encryption_ce;

ZEPHIR_INIT_CLASS(Leevel_Encryption);

PHP_METHOD(Leevel_Encryption, name);

ZEPHIR_INIT_FUNCS(leevel_encryption_method_entry) {
	PHP_ME(Leevel_Encryption, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
