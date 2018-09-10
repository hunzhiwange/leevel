
extern zend_class_entry *leevel_bootstrap_kernel_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Kernel);

PHP_METHOD(Leevel_Bootstrap_Kernel, __construct);
PHP_METHOD(Leevel_Bootstrap_Kernel, handle);
PHP_METHOD(Leevel_Bootstrap_Kernel, getRuntime);
PHP_METHOD(Leevel_Bootstrap_Kernel, terminate);
PHP_METHOD(Leevel_Bootstrap_Kernel, getProject);
PHP_METHOD(Leevel_Bootstrap_Kernel, registerBaseService);
PHP_METHOD(Leevel_Bootstrap_Kernel, getResponseWithRequest);
PHP_METHOD(Leevel_Bootstrap_Kernel, dispatchRouter);
PHP_METHOD(Leevel_Bootstrap_Kernel, bootstrap);
PHP_METHOD(Leevel_Bootstrap_Kernel, reportException);
PHP_METHOD(Leevel_Bootstrap_Kernel, renderException);
PHP_METHOD(Leevel_Bootstrap_Kernel, prepareTrace);
PHP_METHOD(Leevel_Bootstrap_Kernel, middlewareTerminate);
zend_object *zephir_init_properties_Leevel_Bootstrap_Kernel(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, project, Leevel\\Kernel\\IProject, 0)
	ZEND_ARG_OBJ_INFO(0, router, Leevel\\Router\\IRouter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_terminate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_OBJ_INFO(0, response, Leevel\\Http\\IResponse, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_registerbaseservice, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_getresponsewithrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_dispatchrouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_reportexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_renderexception, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_OBJ_INFO(0, e, Exception, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_preparetrace, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Leevel\\Http\\IResponse, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_kernel_middlewareterminate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_OBJ_INFO(0, response, Leevel\\Http\\IResponse, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_kernel_method_entry) {
	PHP_ME(Leevel_Bootstrap_Kernel, __construct, arginfo_leevel_bootstrap_kernel___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Bootstrap_Kernel, handle, arginfo_leevel_bootstrap_kernel_handle, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Kernel, getRuntime, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, terminate, arginfo_leevel_bootstrap_kernel_terminate, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Kernel, getProject, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Kernel, registerBaseService, arginfo_leevel_bootstrap_kernel_registerbaseservice, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, getResponseWithRequest, arginfo_leevel_bootstrap_kernel_getresponsewithrequest, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, dispatchRouter, arginfo_leevel_bootstrap_kernel_dispatchrouter, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, bootstrap, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, reportException, arginfo_leevel_bootstrap_kernel_reportexception, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, renderException, arginfo_leevel_bootstrap_kernel_renderexception, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, prepareTrace, arginfo_leevel_bootstrap_kernel_preparetrace, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Kernel, middlewareTerminate, arginfo_leevel_bootstrap_kernel_middlewareterminate, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
