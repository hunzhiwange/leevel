
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * php redis 扩展缓存.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.07.29
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Redis_PhpRedis) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Cache\\Redis, PhpRedis, leevel, cache_redis_phpredis, leevel_cache_redis_phpredis_method_entry, 0);

	/**
	 * redis 句柄.
	 *
	 * @var handle
	 */
	zend_declare_property_null(leevel_cache_redis_phpredis_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cache_redis_phpredis_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_cache_redis_phpredis_ce->create_object = zephir_init_properties_Leevel_Cache_Redis_PhpRedis;

	zend_class_implements(leevel_cache_redis_phpredis_ce TSRMLS_CC, 1, leevel_cache_redis_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, method, _0, _1, _2, _3, _4, _5, _7, _8, _9, _10, _11, _12, _13, _14, _18, _19, _15$$4, _16$$4, _17$$4, _20$$5, _21$$5, _22$$5;
	zval option, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "redis");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 70, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Redis extension must be loaded before use.", "leevel/cache/redis/phpredis.zep", 64);
		return;
	}
	ZEPHIR_INIT_NVAR(&_0);
	zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_2, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "createredis", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("handle"), &_3);
	zephir_read_property(&_4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_5, &_4, SL("persistent"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 71 TSRMLS_CC);
	if (zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "pconnect");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "connect");
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_7);
	zephir_read_property(&_7, this_ptr, SL("handle"), PH_NOISY_CC);
	zephir_array_fast_append(&_6, &_7);
	zephir_array_fast_append(&_6, &method);
	zephir_read_property(&_8, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_9, &_8, SL("host"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 75 TSRMLS_CC);
	zephir_read_property(&_10, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_NVAR(&_7);
	zephir_array_fetch_string(&_7, &_10, SL("port"), PH_NOISY, "leevel/cache/redis/phpredis.zep", 76 TSRMLS_CC);
	zephir_read_property(&_11, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_12, &_11, SL("timeout"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 78 TSRMLS_CC);
	ZVAL_LONG(&_13, zephir_get_intval(&_7));
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 8, &_6, &_9, &_13, &_12);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_14, &_13, SL("password"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 80 TSRMLS_CC);
	if (zephir_is_true(&_14)) {
		zephir_read_property(&_15$$4, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_16$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_17$$4, &_16$$4, SL("password"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 81 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_15$$4, "auth", NULL, 0, &_17$$4);
		zephir_check_call_status();
	}
	zephir_read_property(&_18, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_19, &_18, SL("select"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 84 TSRMLS_CC);
	if (zephir_is_true(&_19)) {
		zephir_read_property(&_20$$5, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_21$$5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_22$$5, &_21$$5, SL("select"), PH_NOISY | PH_READONLY, "leevel/cache/redis/phpredis.zep", 85 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_20$$5, "select", NULL, 0, &_22$$5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回缓存句柄.
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, handle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handle");

}

/**
 * 获取缓存.
 *
 * @param string $name
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置缓存.
 *
 * @param string $name
 * @param mixed  $data
 * @param int    $expire
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *data, data_sub, *expire = NULL, expire_sub, __$null, _0$$3, _1$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &data, &expire);

	zephir_get_strval(&name, name_param);
	if (!expire) {
		expire = &expire_sub;
		expire = &__$null;
	}


	if (zephir_is_true(expire)) {
		zephir_read_property(&_0$$3, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "setex", NULL, 0, &name, expire, data);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_1$$4, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "set", NULL, 0, &name, data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 清除缓存.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 关闭 redis.
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, close) {

	zval __$null, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "close", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("handle"), &__$null);
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回 redis 对象
 *
 * @return \Redis
 */
PHP_METHOD(Leevel_Cache_Redis_PhpRedis, createRedis) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("redis")));
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Cache_Redis_PhpRedis(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$false, _0;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 6, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("host"), SL("127.0.0.1"));
			add_assoc_long_ex(&_1$$3, SL("port"), 6379);
			add_assoc_stringl_ex(&_1$$3, SL("password"), SL(""));
			add_assoc_long_ex(&_1$$3, SL("select"), 0);
			add_assoc_long_ex(&_1$$3, SL("timeout"), 0);
			zephir_array_update_string(&_1$$3, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

