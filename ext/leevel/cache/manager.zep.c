
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * 缓存入口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.02.15
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Cache, Manager, leevel, cache_manager, leevel_manager_manager_ce, leevel_cache_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间.
 *
 * @return string
 */
PHP_METHOD(Leevel_Cache_Manager, normalizeOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("cache");

}

/**
 * 创建连接对象
 *
 * @param object $connect
 *
 * @return object
 */
PHP_METHOD(Leevel_Cache_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect, connect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect);



	object_init_ex(return_value, leevel_cache_cache_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 85, connect);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建文件缓存.
 *
 * @param array $options
 *
 * @return \Leevel\Cache\File
 */
PHP_METHOD(Leevel_Cache_Manager, makeConnectFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	object_init_ex(return_value, leevel_cache_file_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "file");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 86, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 redis 缓存.
 *
 * @param array $options
 *
 * @return \Leevel\Cache\Redis
 */
PHP_METHOD(Leevel_Cache_Manager, makeConnectRedis) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, tmp, _0;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "redis");
	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "normalizeconnectoption", NULL, 0, &_0, &options);
	zephir_check_call_status();
	object_init_ex(return_value, leevel_cache_redis_ce);
	ZEPHIR_INIT_NVAR(&_0);
	object_init_ex(&_0, leevel_cache_redis_phpredis_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 87, &tmp);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 88, &_0, &tmp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析连接配置.
 *
 * @param string $connect
 *
 * @return array
 */
PHP_METHOD(Leevel_Cache_Manager, getConnectOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *connect_param = NULL, _0;
	zval connect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect_param);

	zephir_get_strval(&connect, connect_param);


	ZEPHIR_CALL_PARENT(&_0, leevel_cache_manager_ce, getThis(), "getconnectoption", &_1, 0, &connect);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filternullofoption", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

