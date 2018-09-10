
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 路由匹配接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.12
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_Match_IMatch) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Router\\Match, IMatch, leevel, router_match_imatch, leevel_router_match_imatch_method_entry);

	return SUCCESS;

}

/**
 * 匹配数据项
 *
 * @param \Leevel\Router\IRouter $router
 * @param \Leevel\Http\IRequest $request
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Router_Match_IMatch, matche);

