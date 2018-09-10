
extern zend_class_entry *leevel_router_match_pathinfo_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_Match_PathInfo);

PHP_METHOD(Leevel_Router_Match_PathInfo, matche);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_match_pathinfo_matche, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, router, Leevel\\Router\\IRouter, 0)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_match_pathinfo_method_entry) {
	PHP_ME(Leevel_Router_Match_PathInfo, matche, arginfo_leevel_router_match_pathinfo_matche, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
