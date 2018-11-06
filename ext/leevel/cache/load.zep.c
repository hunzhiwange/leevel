
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * cache 快捷载入.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.11.20
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Load) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Cache, Load, leevel, cache_load, leevel_cache_load_method_entry, 0);

	/**
	 * IOC Container.
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_cache_load_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * cache 仓储.
	 *
	 * @var \Leevel\Cache\ICache
	 */
	zend_declare_property_null(leevel_cache_load_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 已经载入的缓存数据.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cache_load_ce, SL("cacheLoaded"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_cache_load_ce->create_object = zephir_init_properties_Leevel_Cache_Load;
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param \Leevel\Di\IContainer $container
 * @param \Leevel\Cache\ICache  $cache
 */
PHP_METHOD(Leevel_Cache_Load, __construct) {

	zval *container, container_sub, *cache, cache_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&cache_sub);

	zephir_fetch_params(0, 2, 0, &container, &cache);



	zephir_update_property_zval(this_ptr, SL("container"), container);
	zephir_update_property_zval(this_ptr, SL("cache"), cache);

}

/**
 * 切换缓存仓储.
 *
 * @param \Leevel\Cache\ICache $cache
 */
PHP_METHOD(Leevel_Cache_Load, switchCache) {

	zval *cache, cache_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);

	zephir_fetch_params(0, 1, 0, &cache);



	zephir_update_property_zval(this_ptr, SL("cache"), cache);

}

/**
 * 返回缓存仓储.
 *
 * @return \Leevel\Cache\ICache
 */
PHP_METHOD(Leevel_Cache_Load, getCache) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cache");

}

/**
 * 载入缓存数据
 * 系统自动存储缓存到内存，可重复执行不会重复载入数据.
 *
 * @param array|string $names
 * @param array        $option
 * @param bool         $force
 *
 * @return array
 */
PHP_METHOD(Leevel_Cache_Load, data) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool force, _2$$3;
	zval option;
	zval *names, names_sub, *option_param = NULL, *force_param = NULL, name, result, tmpNames, *_0, *_6, _9, _1$$3, _3$$4, _4$$4, _7$$5, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&tmpNames);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &names, &option_param, &force_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	if (Z_TYPE_P(names) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&tmpNames, names);
	} else {
		ZEPHIR_INIT_NVAR(&tmpNames);
		zephir_create_array(&tmpNames, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tmpNames, names);
	}
	zephir_is_iterable(&tmpNames, 0, "leevel/cache/load.zep", 108);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmpNames), _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _0);
		zephir_read_property(&_1$$3, this_ptr, SL("cacheLoaded"), PH_NOISY_CC | PH_READONLY);
		_2$$3 = !((zephir_array_isset(&_1$$3, &name)));
		if (!(_2$$3)) {
			_2$$3 = force;
		}
		if (_2$$3) {
			if (force) {
				ZVAL_BOOL(&_4$$4, 1);
			} else {
				ZVAL_BOOL(&_4$$4, 0);
			}
			ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "cache", &_5, 0, &name, &option, &_4$$4);
			zephir_check_call_status();
			zephir_update_property_array(this_ptr, SL("cacheLoaded"), &name, &_3$$4 TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&tmpNames, 0, "leevel/cache/load.zep", 114);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmpNames), _6)
	{
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _6);
		zephir_read_property(&_7$$5, this_ptr, SL("cacheLoaded"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_8$$5, &_7$$5, &name, PH_NOISY | PH_READONLY, "leevel/cache/load.zep", 111 TSRMLS_CC);
		zephir_array_update_zval(&result, &name, &_8$$5, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_VAR(&_9);
	if (zephir_fast_count_int(&result TSRMLS_CC) > 1) {
		ZEPHIR_CPY_WRT(&_9, &result);
	} else {
		ZEPHIR_MAKE_REF(&result);
		ZEPHIR_CALL_FUNCTION(&_9, "reset", NULL, 83, &result);
		ZEPHIR_UNREF(&result);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_9);

}

/**
 * 刷新缓存数据.
 *
 * @param array|string $names
 */
PHP_METHOD(Leevel_Cache_Load, refresh) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *names, names_sub, name, tmpNames, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmpNames);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &names);



	if (Z_TYPE_P(names) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&tmpNames, names);
	} else {
		ZEPHIR_INIT_NVAR(&tmpNames);
		zephir_create_array(&tmpNames, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tmpNames, names);
	}
	zephir_is_iterable(&tmpNames, 0, "leevel/cache/load.zep", 131);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmpNames), _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_1, 0, &name);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 从载入缓存数据中获取
 * 不存在不用更新缓存，返回 false.
 *
 * @param array|string $names
 * @param mixed        $force
 *
 * @return array
 */
PHP_METHOD(Leevel_Cache_Load, dataLoaded) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool force;
	zval option;
	zval *names, names_sub, *option_param = NULL, *force_param = NULL, result, name, tmpNames, *_0, _4, _1$$3, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&names_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmpNames);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &names, &option_param, &force_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	if (Z_TYPE_P(names) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&tmpNames, names);
	} else {
		ZEPHIR_INIT_NVAR(&tmpNames);
		zephir_create_array(&tmpNames, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tmpNames, names);
	}
	zephir_is_iterable(&tmpNames, 0, "leevel/cache/load.zep", 156);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmpNames), _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		ZVAL_COPY(&name, _0);
		ZEPHIR_INIT_LNVAR(_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("cacheLoaded"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_key_exists(&_2$$3, &name TSRMLS_CC)) {
			zephir_read_property(&_3$$3, this_ptr, SL("cacheLoaded"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_NVAR(&_1$$3);
			zephir_array_fetch(&_1$$3, &_3$$3, &name, PH_NOISY, "leevel/cache/load.zep", 152 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_BOOL(&_1$$3, 0);
		}
		zephir_array_update_zval(&result, &name, &_1$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_fast_count_int(&result TSRMLS_CC) > 1) {
		ZEPHIR_CPY_WRT(&_4, &result);
	} else {
		ZEPHIR_MAKE_REF(&result);
		ZEPHIR_CALL_FUNCTION(&_4, "reset", NULL, 83, &result);
		ZEPHIR_UNREF(&result);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_4);

}

/**
 * 删除缓存数据.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Cache_Load, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "deletepersistence", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 读取缓存数据.
 *
 * @param string $name
 * @param array  $option
 * @param bool   $force
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_Load, cache) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool force;
	zval option;
	zval *name_param = NULL, *option_param = NULL, *force_param = NULL, data, _0$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &option_param, &force_param);

	zephir_get_strval(&name, name_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}
	if (!force_param) {
		force = 0;
	} else {
		force = zephir_get_boolval(force_param);
	}


	if (force == 0) {
		ZVAL_BOOL(&_0$$3, 0);
		ZEPHIR_CALL_METHOD(&data, this_ptr, "getpersistence", NULL, 0, &name, &_0$$3, &option);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_BOOL(&data, 0);
	}
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		ZEPHIR_CALL_METHOD(&data, this_ptr, "update", NULL, 0, &name, &option);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&data);

}

/**
 * 更新缓存数据.
 *
 * @param string $name
 * @param array  $option
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_Load, update) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *option_param = NULL, sourceName, tempName, params, tmpListNameParams, method, tmpListNameMethod, cache, tempCallback, sourceData, _0, _1, _2, _3$$5, _4$$5, _5$$5, _7$$6, _8$$6, _9$$6, _10$$6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&sourceName);
	ZVAL_UNDEF(&tempName);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&tmpListNameParams);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&tmpListNameMethod);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&tempCallback);
	ZVAL_UNDEF(&sourceData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &option_param);

	zephir_get_strval(&name, name_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_CPY_WRT(&sourceName, &name);
	ZEPHIR_CALL_METHOD(&tmpListNameParams, this_ptr, "parse", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&tempName);
	zephir_array_fetch_long(&tempName, &tmpListNameParams, 0, PH_NOISY, "leevel/cache/load.zep", 209 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&params);
	zephir_array_fetch_long(&params, &tmpListNameParams, 1, PH_NOISY, "leevel/cache/load.zep", 210 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "@");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &tempName, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&tmpListNameMethod);
		zephir_fast_explode_str(&tmpListNameMethod, SL("@"), &tempName, LONG_MAX TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&tempName);
		zephir_array_fetch_long(&tempName, &tmpListNameMethod, 0, PH_NOISY, "leevel/cache/load.zep", 214 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&method);
		zephir_array_fetch_long(&method, &tmpListNameMethod, 1, PH_NOISY, "leevel/cache/load.zep", 215 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "handle");
	}
	zephir_read_property(&_2, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&cache, &_2, "make", NULL, 0, &tempName);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&cache) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_3$$5);
		object_init_ex(&_3$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "Cache %s is not valid.");
		ZEPHIR_CALL_FUNCTION(&_5$$5, "sprintf", &_6, 1, &_4$$5, &tempName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 21, &_5$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$5, "leevel/cache/load.zep", 225 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&tempCallback);
	zephir_create_array(&tempCallback, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&tempCallback, &cache);
	zephir_array_fast_append(&tempCallback, &method);
	if (!(zephir_is_callable(&tempCallback TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_7$$6);
		object_init_ex(&_7$$6, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_8$$6);
		ZEPHIR_CONCAT_VSV(&_8$$6, &tempName, "@", &method);
		ZEPHIR_INIT_VAR(&_9$$6);
		ZVAL_STRING(&_9$$6, "Cache %s is not a callable.");
		ZEPHIR_CALL_FUNCTION(&_10$$6, "sprintf", &_6, 1, &_9$$6, &_8$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$6, "__construct", NULL, 21, &_10$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$6, "leevel/cache/load.zep", 233 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&sourceData);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&sourceData, &tempCallback, &params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpersistence", NULL, 0, &sourceName, &sourceData, &option);
	zephir_check_call_status();
	RETURN_CCTOR(&sourceData);

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
PHP_METHOD(Leevel_Cache_Load, getPersistence) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *defaults = NULL, defaults_sub, *option_param = NULL, __$false, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
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


	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &name, defaults, &option);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置缓存.
 *
 * @param string $name
 * @param mixed  $data
 * @param array  $option
 */
PHP_METHOD(Leevel_Cache_Load, setPersistence) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *data, data_sub, *option_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &data, &option_param);

	zephir_get_strval(&name, name_param);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &name, data, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清除缓存.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Cache_Load, deletePersistence) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 解析缓存.
 *
 * @param string $name
 *
 * @return array
 */
PHP_METHOD(Leevel_Cache_Load, parse) {

	zend_string *_6;
	zend_ulong _5;
	zval newArgs;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, args, temp, tempName, key, item, _0, _1, _2, *_4, _3$$3, _7$$4, _8$$4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&tempName);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&newArgs);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&newArgs);
	array_init(&newArgs);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL(":"), &name, 2  TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&temp, "array_pad", NULL, 84, &_0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&tempName);
	zephir_array_fetch_long(&tempName, &temp, 0, PH_NOISY, "leevel/cache/load.zep", 292 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&args);
	zephir_array_fetch_long(&args, &temp, 1, PH_NOISY, "leevel/cache/load.zep", 293 TSRMLS_CC);
	if (Z_TYPE_P(&args) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_explode_str(&_3$$3, SL(","), &args, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&args, &_3$$3);
	}
	zephir_is_iterable(&args, 0, "leevel/cache/load.zep", 303);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&args), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		ZEPHIR_INIT_LNVAR(_7$$4);
		ZEPHIR_CALL_FUNCTION(&_8$$4, "ctype_digit", &_9, 12, &item);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$4)) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_LONG(&_7$$4, zephir_get_intval(&item));
		} else {
			ZEPHIR_CPY_WRT(&_7$$4, &item);
		}
		zephir_array_update_zval(&newArgs, &key, &_7$$4, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &tempName);
	zephir_array_fast_append(return_value, &newArgs);
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Cache_Load(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("cacheLoaded"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("cacheLoaded"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

