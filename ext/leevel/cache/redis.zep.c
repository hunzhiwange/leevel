
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * redis 扩展缓存.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.05
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Cache, Redis, leevel, cache_redis, leevel_cache_connect_ce, leevel_cache_redis_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cache_redis_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_cache_redis_ce->create_object = zephir_init_properties_Leevel_Cache_Redis;

	zend_class_implements(leevel_cache_redis_ce TSRMLS_CC, 1, leevel_cache_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param \Leevel\Cache\Redis\IConnect $handle
 * @param array                        $option
 */
PHP_METHOD(Leevel_Cache_Redis, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval option;
	zval *handle, handle_sub, *option_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handle_sub);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &handle, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_PARENT(NULL, leevel_cache_redis_ce, getThis(), "__construct", &_0, 0, &option);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("handle"), handle);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取缓存.
 *
 * @param string $name
 * @param mixed  $defaults
 * @param array  $option
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_Redis, get) {

	zend_bool _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *defaults = NULL, defaults_sub, *option_param = NULL, __$false, data, _0, _1, _2, _3, _5$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &defaults, &option_param);

	zephir_get_strval(&name, name_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$false;
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	zephir_read_property(&_1, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getcachename", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		RETVAL_ZVAL(defaults, 1, 0);
		RETURN_MM();
	}
	zephir_array_fetch_string(&_3, &option, SL("serialize"), PH_NOISY | PH_READONLY, "leevel/cache/redis.zep", 76 TSRMLS_CC);
	_4 = zephir_is_true(&_3);
	if (_4) {
		_4 = Z_TYPE_P(&data) == IS_STRING;
	}
	if (_4) {
		ZEPHIR_CALL_FUNCTION(&_5$$4, "unserialize", NULL, 29, &data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_5$$4);
	}
	RETURN_CCTOR(&data);

}

/**
 * 设置缓存.
 *
 * @param string $name
 * @param mixed  $data
 * @param array  $option
 */
PHP_METHOD(Leevel_Cache_Redis, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *data = NULL, data_sub, *option_param = NULL, _0, _1, _3, _4, _5, _6, _7, _8, _9, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &data, &option_param);

	zephir_get_strval(&name, name_param);
	ZEPHIR_SEPARATE_PARAM(data);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	zephir_array_fetch_string(&_1, &option, SL("serialize"), PH_NOISY | PH_READONLY, "leevel/cache/redis.zep", 94 TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(&_2$$3, "serialize", NULL, 24, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, &_2$$3);
	}
	zephir_array_fetch_string(&_4, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cache/redis.zep", 98 TSRMLS_CC);
	ZVAL_LONG(&_5, zephir_get_intval(&_4));
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "cachetime", NULL, 0, &name, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&option, SL("expire"), &_3, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_5, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "getcachename", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	zephir_array_fetch_string(&_8, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cache/redis.zep", 102 TSRMLS_CC);
	if (zephir_is_true(&_8)) {
		ZEPHIR_OBS_VAR(&_9);
		zephir_array_fetch_string(&_9, &option, SL("expire"), PH_NOISY, "leevel/cache/redis.zep", 102 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_LONG(&_7, zephir_get_intval(&_9));
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_NULL(&_7);
	}
	ZEPHIR_CALL_METHOD(NULL, &_5, "set", NULL, 0, &_6, data, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清除缓存.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Cache_Redis, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcachename", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 关闭 redis.
 */
PHP_METHOD(Leevel_Cache_Redis, close) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "close", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_Cache_Redis(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$true, _0, _2$$3;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("time_preset"), &_2$$3, PH_COPY | PH_SEPARATE);
			add_assoc_long_ex(&_1$$3, SL("expire"), 86400);
			zephir_array_update_string(&_1$$3, SL("serialize"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

