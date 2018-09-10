
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 流程控制复用
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * 
 * @since 2018.03.05
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Flow_IControl) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Flow, IControl, leevel, flow_icontrol, leevel_flow_icontrol_method_entry);

	return SUCCESS;

}

/**
 * 条件语句 ifs.
 *
 * @param mixed $value
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, ifs);

/**
 * 条件语句 elseIfs.
 *
 * @param mixed $value
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, elseIfs);

/**
 * 条件语句 elses
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, elses);

/**
 * 条件语句 endIfs
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, endIfs);

/**
 * 设置当前条件表达式状态
 *
 * @param bool $inFlowControl
 * @param bool $isFlowControlTrue
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, setTControl);

/**
 * 验证一下条件表达式是否通过.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, checkTControl);

/**
 * 占位符.
 *
 * @param string $method
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Flow_IControl, placeholderTControl);

