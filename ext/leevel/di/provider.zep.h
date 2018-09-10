
extern zend_class_entry *leevel_di_provider_ce;

ZEPHIR_INIT_CLASS(Leevel_Di_Provider);

PHP_METHOD(Leevel_Di_Provider, __construct);
PHP_METHOD(Leevel_Di_Provider, register);
PHP_METHOD(Leevel_Di_Provider, registerAlias);
PHP_METHOD(Leevel_Di_Provider, providers);
PHP_METHOD(Leevel_Di_Provider, isDeferred);
PHP_METHOD(Leevel_Di_Provider, container);
PHP_METHOD(Leevel_Di_Provider, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_provider___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_provider___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_di_provider_method_entry) {
	PHP_ME(Leevel_Di_Provider, __construct, arginfo_leevel_di_provider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Di_Provider, register, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Provider, registerAlias, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Provider, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Di_Provider, isDeferred, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Di_Provider, container, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Provider, __call, arginfo_leevel_di_provider___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
