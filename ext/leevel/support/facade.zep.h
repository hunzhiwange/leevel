
extern zend_class_entry *leevel_support_facade_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_Facade);

PHP_METHOD(Leevel_Support_Facade, __callStatic);
PHP_METHOD(Leevel_Support_Facade, facades);
PHP_METHOD(Leevel_Support_Facade, remove);
PHP_METHOD(Leevel_Support_Facade, container);
PHP_METHOD(Leevel_Support_Facade, setContainer);
PHP_METHOD(Leevel_Support_Facade, name);
void zephir_init_static_properties_Leevel_Support_Facade(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_facade___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_facade_remove, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_facade_setcontainer, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_support_facade_method_entry) {
	PHP_ME(Leevel_Support_Facade, __callStatic, arginfo_leevel_support_facade___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Facade, facades, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Facade, remove, arginfo_leevel_support_facade_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Facade, container, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Facade, setContainer, arginfo_leevel_support_facade_setcontainer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Facade, name, NULL, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
