
extern zend_class_entry *leevel_bootstrap_bootstrap_loadoption_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_LoadOption);

PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, handle);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, setEnvs);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, setEnvVar);
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, initialization);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_loadoption_setenvs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, env, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_loadoption_setenvvar, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_bootstrap_loadoption_initialization, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, option, Leevel\\Option\\Option, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_bootstrap_loadoption_method_entry) {
	PHP_ME(Leevel_Bootstrap_Bootstrap_LoadOption, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Bootstrap_LoadOption, setEnvs, arginfo_leevel_bootstrap_bootstrap_loadoption_setenvs, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Bootstrap_LoadOption, setEnvVar, arginfo_leevel_bootstrap_bootstrap_loadoption_setenvvar, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Bootstrap_LoadOption, initialization, arginfo_leevel_bootstrap_bootstrap_loadoption_initialization, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
