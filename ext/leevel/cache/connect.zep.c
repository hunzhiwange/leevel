
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * 缓存抽象类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.02.15
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_Connect) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Cache, Connect, leevel, cache_connect, leevel_cache_connect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 缓存服务句柄.
	 *
	 * @var handle
	 */
	zend_declare_property_null(leevel_cache_connect_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cache_connect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_cache_connect_ce->create_object = zephir_init_properties_Leevel_Cache_Connect;
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 */
PHP_METHOD(Leevel_Cache_Connect, __construct) {

	zval *option_param = NULL, _0, _1;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置配置.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return $this
 */
PHP_METHOD(Leevel_Cache_Connect, setOption) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 返回缓存句柄.
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_Connect, handle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handle");

}

/**
 * 获取缓存名字.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Leevel_Cache_Connect, getCacheName) {

	zval *name_param = NULL;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	RETURN_CTOR(&name);

}

/**
 * 读取缓存时间配置.
 *
 * @param string $id
 * @param int    $defaultTime
 *
 * @return int
 */
PHP_METHOD(Leevel_Cache_Connect, cacheTime) {

	zend_string *_12;
	zend_ulong _11;
	zephir_fcall_cache_entry *_15 = NULL;
	zend_long defaultTime, ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL, *defaultTime_param = NULL, key, res, _0, _1, _2, _3, _7, _8, _9, *_10, _4$$4, _5$$4, _6$$4, _13$$5, _14$$5, _16$$6, _17$$6, _18$$6;
	zval id;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &id_param, &defaultTime_param);

	zephir_get_strval(&id, id_param);
	if (!defaultTime_param) {
		defaultTime = 0;
	} else {
		defaultTime = zephir_get_intval(defaultTime_param);
	}


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("time_preset"), PH_NOISY | PH_READONLY, "leevel/cache/connect.zep", 103 TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_LONG(defaultTime);
	}
	zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("time_preset"), PH_READONLY, "leevel/cache/connect.zep", 107 TSRMLS_CC);
	if (zephir_array_isset(&_3, &id)) {
		zephir_read_property(&_4$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5$$4, &_4$$4, SL("time_preset"), PH_NOISY | PH_READONLY, "leevel/cache/connect.zep", 108 TSRMLS_CC);
		zephir_array_fetch(&_6$$4, &_5$$4, &id, PH_NOISY | PH_READONLY, "leevel/cache/connect.zep", 108 TSRMLS_CC);
		RETURN_CTOR(&_6$$4);
	}
	zephir_read_property(&_7, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_8, &_7, SL("time_preset"), PH_NOISY | PH_READONLY, "leevel/cache/connect.zep", 111 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_9);
	zephir_is_iterable(&_8, 0, "leevel/cache/connect.zep", 117);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_8), _11, _12, _10)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_12 != NULL) { 
			ZVAL_STR_COPY(&key, _12);
		} else {
			ZVAL_LONG(&key, _11);
		}
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_COPY(&_9, _10);
		ZEPHIR_INIT_NVAR(&_13$$5);
		ZEPHIR_CALL_METHOD(&_14$$5, this_ptr, "prepareregexforwildcard", &_15, 0, &key);
		zephir_check_call_status();
		zephir_preg_match(&_13$$5, &_14$$5, &id, &res, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_13$$5)) {
			zephir_read_property(&_16$$6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_17$$6, &_16$$6, SL("time_preset"), PH_NOISY | PH_READONLY, "leevel/cache/connect.zep", 113 TSRMLS_CC);
			zephir_array_fetch(&_18$$6, &_17$$6, &key, PH_NOISY | PH_READONLY, "leevel/cache/connect.zep", 113 TSRMLS_CC);
			RETURN_CTOR(&_18$$6);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&_9);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_MM_LONG(defaultTime);

}

/**
 * 通配符正则.
 *
 * @param string $regex
 *
 * @return string
 */
PHP_METHOD(Leevel_Cache_Connect, prepareRegexForWildcard) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *regex_param = NULL, _0, _1, _2, _3, _4;
	zval regex;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regex_param);

	zephir_get_strval(&regex, regex_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_CALL_FUNCTION(&_1, "preg_quote", NULL, 28, &regex, &_0);
	zephir_check_call_status();
	zephir_get_strval(&regex, &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\*");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "(\\S+)");
	zephir_fast_str_replace(&_0, &_2, &_3, &regex TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVS(&_4, "/^", &_0, "$/");
	zephir_get_strval(&regex, &_4);
	RETURN_CTOR(&regex);

}

/**
 * 整理配置.
 *
 * @param array $option
 *
 * @return array
 */
PHP_METHOD(Leevel_Cache_Connect, normalizeOptions) {

	zval *option_param = NULL, _0, _1;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&option))) {
		zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	} else {
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

zend_object *zephir_init_properties_Leevel_Cache_Connect(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

