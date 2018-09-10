
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
ZEPHIR_INIT_CLASS(Leevel_Cache_IConnect) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Cache, IConnect, leevel, cache_iconnect, leevel_cache_iconnect_method_entry);

	return SUCCESS;

}

/**
 * 设置配置.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_IConnect, setOption);

/**
 * 获取缓存.
 *
 * @param string $name
 * @param mixed  $defaults
 * @param array  $option
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_IConnect, get);

/**
 * 设置缓存.
 *
 * @param string $name
 * @param mixed  $data
 * @param array  $option
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_IConnect, set);

/**
 * 清除缓存.
 *
 * @param string $name
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_IConnect, delete);

/**
 * 返回缓存句柄.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_IConnect, handle);

/**
 * 关闭.
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_IConnect, close);

