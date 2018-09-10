
extern zend_class_entry *leevel_bootstrap_bootstrap_loadi18n_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_LoadI18n);

PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadI18n, handle);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadI18n, getExtend);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_loadi18n_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, project, Leevel\\Kernel\\IProject, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_loadi18n_getextend, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, project, Leevel\\Kernel\\IProject, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_bootstrap_loadi18n_method_entry) {
	PHP_ME(Leevel_Bootstrap_Bootstrap_LoadI18n, handle, arginfo_leevel_bootstrap_bootstrap_loadi18n_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Bootstrap_LoadI18n, getExtend, arginfo_leevel_bootstrap_bootstrap_loadi18n_getextend, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
