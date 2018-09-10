
extern zend_class_entry *leevel_bootstrap_bootstrap_traverseprovider_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_TraverseProvider);

PHP_METHOD(Leevel_Bootstrap_Bootstrap_TraverseProvider, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_traverseprovider_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, project, Leevel\\Kernel\\IProject, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_bootstrap_traverseprovider_method_entry) {
	PHP_ME(Leevel_Bootstrap_Bootstrap_TraverseProvider, handle, arginfo_leevel_bootstrap_bootstrap_traverseprovider_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
