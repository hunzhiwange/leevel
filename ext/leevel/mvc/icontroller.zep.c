
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IController 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Mvc_IController) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Mvc, IController, leevel, mvc_icontroller, leevel_mvc_icontroller_method_entry);

	zend_class_implements(leevel_mvc_icontroller_ce TSRMLS_CC, 1, leevel_mvc_iview_ce);
	return SUCCESS;

}

/**
 * 返回父控制器
 *
 * @param \Leevel\Mvc\IView $view
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Mvc_IController, setView);

