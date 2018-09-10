
extern zend_class_entry *leevel_view_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_View_Provider_Register);

PHP_METHOD(Leevel_View_Provider_Register, __construct);
PHP_METHOD(Leevel_View_Provider_Register, register);
PHP_METHOD(Leevel_View_Provider_Register, providers);
PHP_METHOD(Leevel_View_Provider_Register, viewViews);
PHP_METHOD(Leevel_View_Provider_Register, viewViewsClosure);
PHP_METHOD(Leevel_View_Provider_Register, viewView);
PHP_METHOD(Leevel_View_Provider_Register, viewViewClosure);
PHP_METHOD(Leevel_View_Provider_Register, viewCompiler);
PHP_METHOD(Leevel_View_Provider_Register, viewCompilerClosure);
PHP_METHOD(Leevel_View_Provider_Register, viewParser);
PHP_METHOD(Leevel_View_Provider_Register, viewParserClosure);
PHP_METHOD(Leevel_View_Provider_Register, viewTwigParser);
PHP_METHOD(Leevel_View_Provider_Register, viewTwigParserClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_provider_register_viewviewsclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_provider_register_viewviewclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_provider_register_viewcompilerclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_provider_register_viewparserclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_provider_register_viewtwigparserclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, project, Leevel\\Kernel\\IProject, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_view_provider_register_method_entry) {
	PHP_ME(Leevel_View_Provider_Register, __construct, arginfo_leevel_view_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_View_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_View_Provider_Register, viewViews, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewViewsClosure, arginfo_leevel_view_provider_register_viewviewsclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewView, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewViewClosure, arginfo_leevel_view_provider_register_viewviewclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewCompiler, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewCompilerClosure, arginfo_leevel_view_provider_register_viewcompilerclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewParser, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewParserClosure, arginfo_leevel_view_provider_register_viewparserclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewTwigParser, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_Provider_Register, viewTwigParserClosure, arginfo_leevel_view_provider_register_viewtwigparserclosure, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
