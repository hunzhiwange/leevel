
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 内核执行接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.05.21
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Kernel_IKernel) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Kernel, IKernel, leevel, kernel_ikernel, leevel_kernel_ikernel_method_entry);

	return SUCCESS;

}

/**
 * 响应 HTTP 请求
 *
 * @param \Leevel\Http\IRequest $request
 * @return \Leevel\Http\IResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IKernel, handle);

/**
 * 执行结束
 *
 * @param \Leevel\Http\IRequest $request
 * @param \Leevel\Http\IResponse $response
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IKernel, terminate);

/**
 * 返回项目
 *
 * @return \Leevel\Kernel\IProject
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IKernel, getProject);

