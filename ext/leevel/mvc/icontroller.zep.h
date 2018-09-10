
extern zend_class_entry *leevel_mvc_icontroller_ce;

ZEPHIR_INIT_CLASS(Leevel_Mvc_IController);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_mvc_icontroller_setview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, view, Leevel\\Mvc\\IView, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_mvc_icontroller_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Mvc_IController, setView, arginfo_leevel_mvc_icontroller_setview)
	PHP_FE_END
};
