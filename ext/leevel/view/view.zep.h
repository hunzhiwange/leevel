
extern zend_class_entry *leevel_view_view_ce;

ZEPHIR_INIT_CLASS(Leevel_View_View);

PHP_METHOD(Leevel_View_View, __construct);
PHP_METHOD(Leevel_View_View, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_view___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connect, Leevel\\View\\IConnect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_view___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_view_view_method_entry) {
	PHP_ME(Leevel_View_View, __construct, arginfo_leevel_view_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_View_View, __call, arginfo_leevel_view_view___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
