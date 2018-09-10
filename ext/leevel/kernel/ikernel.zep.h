
extern zend_class_entry *leevel_kernel_ikernel_ce;

ZEPHIR_INIT_CLASS(Leevel_Kernel_IKernel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_ikernel_handle, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_ikernel_terminate, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, request, Leevel\\Http\\IRequest, 0)
	ZEND_ARG_OBJ_INFO(0, response, Leevel\\Http\\IResponse, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_kernel_ikernel_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Kernel_IKernel, handle, arginfo_leevel_kernel_ikernel_handle)
	PHP_ABSTRACT_ME(Leevel_Kernel_IKernel, terminate, arginfo_leevel_kernel_ikernel_terminate)
	PHP_ABSTRACT_ME(Leevel_Kernel_IKernel, getProject, NULL)
	PHP_FE_END
};
