
extern zend_class_entry *leevel_i18n_ce;

ZEPHIR_INIT_CLASS(Leevel_I18n);

PHP_METHOD(Leevel_I18n, name);

ZEPHIR_INIT_FUNCS(leevel_i18n_method_entry) {
	PHP_ME(Leevel_I18n, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
