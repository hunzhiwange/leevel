
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IView 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_IView) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\View, IView, leevel, view_iview, NULL);

	return SUCCESS;

}

