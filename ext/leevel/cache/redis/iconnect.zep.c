
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IConnect 接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.07.29
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Redis_IConnect) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Cache\\Redis, IConnect, leevel, cache_redis_iconnect, leevel_cache_redis_iconnect_method_entry);

	return SUCCESS;

}

/**
 * 返回缓存句柄.
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_Redis_IConnect, handle);

/**
 * 获取缓存.
 *
 * @param string $name
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_Redis_IConnect, get);

/**
 * 设置缓存.
 *
 * @param string $name
 * @param mixed  $data
 * @param int    $expire
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_Redis_IConnect, set);

/**
 * 清除缓存.
 *
 * @param string $name
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_Redis_IConnect, delete);

/**
 * 关闭 redis.
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_Redis_IConnect, close);

