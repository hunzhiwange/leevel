
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IConnect 接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.23
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_IConnect) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Log, IConnect, leevel, log_iconnect, leevel_log_iconnect_method_entry);

	return SUCCESS;

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Log_IConnect, setOption);

/**
 * 日志写入接口
 *
 * @param array $data
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Log_IConnect, flush);

