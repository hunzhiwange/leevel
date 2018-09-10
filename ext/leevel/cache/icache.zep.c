
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ICache 接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.23
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_ICache) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Cache, ICache, leevel, cache_icache, leevel_cache_icache_method_entry);

	return SUCCESS;

}

/**
 * 批量插入.
 *
 * @param array|string $keys
 * @param mixed        $value
 */
ZEPHIR_DOC_METHOD(Leevel_Cache_ICache, put);

