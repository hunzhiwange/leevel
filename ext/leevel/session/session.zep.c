
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/time.h"


/**
 * session 仓储.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.17
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Session) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Session, Session, leevel, session_session, leevel_session_session_method_entry, 0);

	/**
	 * session ID.
	 * 相当于 session_id.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("id"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session 名字.
	 * 相当于 session_name.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session handler.
	 *
	 * @var \SessionHandlerInterface
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("connect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session 是否开启.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(leevel_session_session_ce, SL("started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * session 数据.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("datas"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_session_session_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_session_session_ce->create_object = zephir_init_properties_Leevel_Session_Session;

	zend_class_implements(leevel_session_session_ce TSRMLS_CC, 1, leevel_session_isession_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param \SessionHandlerInterface $connect
 * @param array                    $option
 */
PHP_METHOD(Leevel_Session_Session, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *connect, connect_sub, *option_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &connect, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	zephir_update_property_zval(this_ptr, SL("connect"), connect);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("name"), PH_NOISY | PH_READONLY, "leevel/session/session.zep", 94 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setname", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 启动 session.
 *
 * @param string $sessionId
 */
PHP_METHOD(Leevel_Session_Session, start) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionId = NULL, sessionId_sub, __$true, __$false, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sessionId);

	if (!sessionId) {
		sessionId = &sessionId_sub;
		sessionId = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstart", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(sessionId)) {
		ZEPHIR_CPY_WRT(&_1, sessionId);
	} else {
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_1);
		zephir_array_fetch_string(&_1, &_2, SL("id"), PH_NOISY, "leevel/session/session.zep", 108 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setid", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "loaddata", NULL, 0);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, SL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 程序执行保存 session.
 */
PHP_METHOD(Leevel_Session_Session, save) {

	zval __$true, __$false, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isstart", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Session is not start yet.", "leevel/session/session.zep", 121);
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "unregisterflash", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getid", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_4, "serialize", NULL, 24, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "write", NULL, 0, &_2, &_4);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(this_ptr, SL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回所有 session 数据.
 *
 * @return array
 */
PHP_METHOD(Leevel_Session_Session, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "datas");

}

/**
 * 设置 session.
 *
 * @param string $name
 * @param mxied  $value
 */
PHP_METHOD(Leevel_Session_Session, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, tmp;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&tmp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("datas"), &tmp, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量插入.
 *
 * @param array|string $keys
 * @param mixed        $value
 */
PHP_METHOD(Leevel_Session_Session, put) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys, keys_sub, *value = NULL, value_sub, __$null, item, tmp, *_0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmp);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &keys, &value);

	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}


	if (!(Z_TYPE_P(keys) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
		zephir_array_update_zval(&tmp, keys, value, PH_COPY);
	} else {
		ZEPHIR_CPY_WRT(&tmp, keys);
	}
	zephir_is_iterable(&tmp, 0, "leevel/session/session.zep", 175);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&tmp), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&item, _2);
		} else {
			ZVAL_LONG(&item, _1);
		}
		ZEPHIR_INIT_NVAR(value);
		ZVAL_COPY(value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &item, value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(value);
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入数据.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Session_Session, push) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, arr, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	zephir_array_append(&arr, value, PH_SEPARATE, "leevel/session/session.zep", 188);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并元素.
 *
 * @param string $key
 * @param array  $value
 */
PHP_METHOD(Leevel_Session_Session, merge) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *key_param = NULL, *value_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "get", NULL, 0, &key, &_2);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出元素.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Session_Session, pop) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *key_param = NULL, *value_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &key, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "array_diff", NULL, 98, &_0, &value);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组插入键值对数据.
 *
 * @param string $key
 * @param mixed  $keys
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Session_Session, arr) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *keys, keys_sub, *value = NULL, value_sub, __$null, arr, _0, _1$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &keys, &value);

	zephir_get_strval(&key, key_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) == IS_STRING) {
		zephir_array_update_zval(&arr, keys, value, PH_COPY | PH_SEPARATE);
	} else if (Z_TYPE_P(keys) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fast_array_merge(&_1$$4, &arr, keys TSRMLS_CC);
		ZEPHIR_CPY_WRT(&arr, &_1$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 数组键值删除数据.
 *
 * @param string $key
 * @param mixed  $keys
 */
PHP_METHOD(Leevel_Session_Session, arrDelete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *keys, keys_sub, arr, item, tmp, _0, *_1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&keys_sub);
	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &keys);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", NULL, 0, &key, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(keys) != IS_ARRAY) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_create_array(&tmp, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&tmp, keys);
	} else {
		ZEPHIR_CPY_WRT(&tmp, keys);
	}
	zephir_is_iterable(&tmp, 0, "leevel/session/session.zep", 263);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmp), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		if (zephir_array_isset(&arr, &item)) {
			zephir_array_unset(&arr, &item, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &key, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回 session.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return mxied
 */
PHP_METHOD(Leevel_Session_Session, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, __$null, tmp, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(&name, name_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &tmp)) {
		zephir_read_property(&_2, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &tmp, PH_NOISY, "leevel/session/session.zep", 280 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, value);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 返回数组部分数据.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, getPart) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value = NULL, value_sub, __$null;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(&name, name_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpartdata", NULL, 0, &name, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除 session.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Session_Session, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, tmp, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &tmp)) {
		zephir_read_property(&_1$$3, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &tmp, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 是否存在 session.
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Leevel_Session_Session, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, tmp, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "getnormalizename", NULL, 0, &name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &tmp));

}

/**
 * 删除 session.
 */
PHP_METHOD(Leevel_Session_Session, clear) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("datas"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 闪存一个数据，当前请求和下一个请求可用.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Session_Session, flash) {

	zval _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashdatakey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, &key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量闪存数据，当前请求和下一个请求可用.
 *
 * @param array $flash
 */
PHP_METHOD(Leevel_Session_Session, flashs) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *flash_param = NULL, key, value, *_0;
	zval flash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flash);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flash_param);

	zephir_get_arrval(&flash, flash_param);


	zephir_is_iterable(&flash, 0, "leevel/session/session.zep", 367);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&flash), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flash", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 闪存一个 flash 用于当前请求使用,下一个请求将无法获取.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Session_Session, nowFlash) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashdatakey", NULL, 0, &key);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0, value);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, &key);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeoldflash", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 批量闪存数据,用于当前请求使用，下一个请求将无法获取.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Session_Session, nowFlashs) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *flash_param = NULL, key, value, *_0;
	zval flash;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flash);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &flash_param);

	zephir_get_arrval(&flash, flash_param);


	zephir_is_iterable(&flash, 0, "leevel/session/session.zep", 397);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&flash), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "nowflash", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 保持所有闪存数据.
 */
PHP_METHOD(Leevel_Session_Session, rebuildFlash) {

	zval _0, _1, _3, _4, _5;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_1, this_ptr, "flasholdkey", &_2, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, &_1, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "flasholdkey", &_2, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	array_init(&_5);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保持闪存数据.
 *
 * @param mixed $keys
 */
PHP_METHOD(Leevel_Session_Session, keepFlash) {

	zval keys, args, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters.", "leevel/session/session.zep", 421);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, &args, 0, PH_NOISY, "leevel/session/session.zep", 424 TSRMLS_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&keys);
		zephir_array_fetch_long(&keys, &args, 0, PH_NOISY, "leevel/session/session.zep", 424 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&keys, &args);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergenewflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popoldflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回闪存数据.
 *
 * @param string $key
 * @param mixed  $defaults
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, getFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0, _1, _2$$3, _3$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaults);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &key, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "flash");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getpartdata", NULL, 0, &key, defaults, &_2$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "flashdatakey", NULL, 0, &key);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_3$$4, defaults);
		zephir_check_call_status();
		RETURN_MM();
	}

}

/**
 * 删除闪存数据.
 *
 * @param mixed $keys
 */
PHP_METHOD(Leevel_Session_Session, deleteFlash) {

	zval item, keys, args, _0, *_1, _2$$4;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters.", "leevel/session/session.zep", 459);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, &args, 0, PH_NOISY, "leevel/session/session.zep", 462 TSRMLS_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&keys);
		zephir_array_fetch_long(&keys, &args, 0, PH_NOISY, "leevel/session/session.zep", 462 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&keys, &args);
	}
	zephir_is_iterable(&keys, 0, "leevel/session/session.zep", 468);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&keys), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "flashdatakey", &_3, 0, &item);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_4, 0, &_2$$4);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mergeoldflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "popnewflash", NULL, 0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清理所有闪存数据.
 */
PHP_METHOD(Leevel_Session_Session, clearFlash) {

	zval _3$$3;
	zval item, newKey, _0, _1, *_2, _4$$3;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&newKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_CALL_METHOD(&newKey, this_ptr, "get", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	zephir_is_iterable(&newKey, 0, "leevel/session/session.zep", 484);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&newKey), _2)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "deleteFlash");
		zephir_array_fast_append(&_3$$3, &_4$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_5, 8, &_3$$3, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 程序执行结束清理 flash.
 */
PHP_METHOD(Leevel_Session_Session, unregisterFlash) {

	zval arr, old, item, _0, _2, _4, _6, *_7, _11, _12, _8$$3;
	zephir_fcall_cache_entry *_1 = NULL, *_3 = NULL, *_5 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&old);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&arr, this_ptr, "get", &_3, 0, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "flasholdkey", &_5, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	ZEPHIR_CALL_METHOD(&old, this_ptr, "get", &_3, 0, &_4, &_6);
	zephir_check_call_status();
	zephir_is_iterable(&old, 0, "leevel/session/session.zep", 500);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&old), _7)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _7);
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "flashdatakey", &_9, 0, &item);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_10, 0, &_8$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "flashnewkey", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", &_10, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, this_ptr, "flasholdkey", &_5, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_12, &arr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取前一个请求地址
 *
 * @return null|string
 */
PHP_METHOD(Leevel_Session_Session, prevUrl) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "prevurlkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置前一个请求地址
 *
 * @param string $url
 */
PHP_METHOD(Leevel_Session_Session, setPrevUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, _0;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "prevurlkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", NULL, 0, &_0, &url);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 终止会话.
 */
PHP_METHOD(Leevel_Session_Session, destroy) {

	zval __$null, __$true, __$false, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "destroy", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("id"), &__$null);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("started"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("started"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * session 是否已经启动.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Session_Session, isStart) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "started");

}

/**
 * 设置 SESSION 名字.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Session_Session, setName) {

	zval *name = NULL, name_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(name)) {
		ZEPHIR_CPY_WRT(&_0, name);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "UID");
	}
	zephir_update_property_zval(this_ptr, SL("name"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得 SESSION 名字.
 *
 * @return null|string
 */
PHP_METHOD(Leevel_Session_Session, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * 设置 SESSION ID.
 *
 * @param string $id
 */
PHP_METHOD(Leevel_Session_Session, setId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *id = NULL, id_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&id_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &id);

	if (!id) {
		id = &id_sub;
		id = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(id)) {
		ZEPHIR_CPY_WRT(&_0, id);
	} else {
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "generatesessionid", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("id"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得 SESSION ID.
 *
 * @return null|string
 */
PHP_METHOD(Leevel_Session_Session, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

/**
 * 重新生成 SESSION ID.
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, regenerateId) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "generatesessionid", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("id"), &_0);
	RETURN_MM_MEMBER(getThis(), "id");

}

/**
 * 返回连接.
 *
 * @return \SessionHandlerInterface
 */
PHP_METHOD(Leevel_Session_Session, getConnect) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "connect");

}

/**
 * 生成 SESSION ID.
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, generateSessionId) {

	zval _0, _1, _2, _4, _5;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsemicrotime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_time(&_1);
	ZVAL_LONG(&_4, 32);
	ZEPHIR_CALL_CE_STATIC(&_2, leevel_support_str_ce, "randalphanum", &_3, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VSVSV(&_5, &_0, ".", &_1, ".", &_2);
	ZEPHIR_RETURN_CALL_FUNCTION("sha1", NULL, 149, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 生成微秒数.
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, parseMicrotime) {

	zval usec, sec, tmpListUsecSec, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&usec);
	ZVAL_UNDEF(&sec);
	ZVAL_UNDEF(&tmpListUsecSec);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, NULL TSRMLS_CC);
	ZEPHIR_INIT_VAR(&tmpListUsecSec);
	zephir_fast_explode_str(&tmpListUsecSec, SL(" "), &_0, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_VAR(&usec);
	zephir_array_fetch_long(&usec, &tmpListUsecSec, 0, PH_NOISY, "leevel/session/session.zep", 628 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&sec);
	zephir_array_fetch_long(&sec, &tmpListUsecSec, 1, PH_NOISY, "leevel/session/session.zep", 629 TSRMLS_CC);
	ZVAL_DOUBLE(&_1, (zephir_get_doubleval(&usec) + zephir_get_doubleval(&sec)));
	ZEPHIR_RETURN_CALL_FUNCTION("strval", NULL, 11, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回 session 名字.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, getNormalizeName) {

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
 * 载入 session 数据.
 */
PHP_METHOD(Leevel_Session_Session, loadData) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "loaddatafromconnect", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &_2 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("datas"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 从驱动载入 session 数据.
 */
PHP_METHOD(Leevel_Session_Session, loadDataFromConnect) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getid", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "read", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 弹出旧闪存 KEY.
 *
 * @param array $keys
 */
PHP_METHOD(Leevel_Session_Session, popOldFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flasholdkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pop", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并旧闪存 KEY.
 *
 * @param array $keys
 */
PHP_METHOD(Leevel_Session_Session, mergeOldFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flasholdkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 弹出新闪存 KEY.
 *
 * @param array $keys
 */
PHP_METHOD(Leevel_Session_Session, popNewFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pop", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 合并新闪存 KEY.
 *
 * @param array $keys
 */
PHP_METHOD(Leevel_Session_Session, mergeNewFlash) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *keys_param = NULL, _0;
	zval keys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &keys_param);

	zephir_get_arrval(&keys, keys_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "flashnewkey", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "merge", NULL, 0, &_0, &keys);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回部分闪存数据.
 *
 * @param string $key
 * @param mixed  $defaults
 * @param string $type
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Session_Session, getPartData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, *type = NULL, type_sub, __$null, name, value, parts, part, tempkeys, tempkey, _1$$3, _2$$4, _3$$4, *_5$$4, _4$$5, _6$$6;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&tempkeys);
	ZVAL_UNDEF(&tempkey);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &key_param, &defaults, &type);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	ZEPHIR_INIT_VAR(&tempkeys);
	zephir_fast_explode_str(&tempkeys, SL("\\"), &key, LONG_MAX TSRMLS_CC);
	ZEPHIR_MAKE_REF(&tempkeys);
	ZEPHIR_CALL_FUNCTION(&tempkey, "array_shift", &_0, 6, &tempkeys);
	ZEPHIR_UNREF(&tempkeys);
	zephir_check_call_status();
	zephir_get_strval(&key, &tempkey);
	ZEPHIR_MAKE_REF(&tempkeys);
	ZEPHIR_CALL_FUNCTION(&name, "array_shift", &_0, 6, &tempkeys);
	ZEPHIR_UNREF(&tempkeys);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(type, "flash")) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "flashdatakey", NULL, 0, &key);
		zephir_check_call_status();
		zephir_get_strval(&key, &_1$$3);
	}
	ZEPHIR_CALL_METHOD(&value, this_ptr, "get", NULL, 0, &key);
	zephir_check_call_status();
	if (Z_TYPE_P(&value) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, ".");
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_fast_strpos(&_3$$4, &name, &_2$$4, 0 );
		if (!(zephir_is_true(&_3$$4))) {
			ZEPHIR_INIT_VAR(&_4$$5);
			if (zephir_array_key_exists(&value, &name TSRMLS_CC)) {
				zephir_array_fetch(&_4$$5, &value, &name, PH_NOISY, "leevel/session/session.zep", 728 TSRMLS_CC);
			} else {
				ZEPHIR_CPY_WRT(&_4$$5, defaults);
			}
			RETURN_CCTOR(&_4$$5);
		}
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
		zephir_is_iterable(&parts, 0, "leevel/session/session.zep", 741);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _5$$4)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _5$$4);
			if (!(zephir_array_isset(&value, &part))) {
				RETVAL_ZVAL(defaults, 1, 0);
				RETURN_MM();
			}
			zephir_array_fetch(&_6$$6, &value, &part, PH_NOISY | PH_READONLY, "leevel/session/session.zep", 738 TSRMLS_CC);
			ZEPHIR_CPY_WRT(&value, &_6$$6);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&part);
		RETURN_CCTOR(&value);
	} else {
		RETVAL_ZVAL(defaults, 1, 0);
		RETURN_MM();
	}

}

/**
 * 闪存值 KEY.
 *
 * @param string $key
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, flashDataKey) {

	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CONCAT_SV(return_value, "flash.data.", &key);
	RETURN_MM();

}

/**
 * 新值闪存 KEY.
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, flashNewKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("flash.new.key");

}

/**
 * 旧值闪存 KEY.
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, flashOldKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("flash.old.key");

}

/**
 * 前一个页面 KEY.
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Session, prevUrlKey) {

	zval *this_ptr = getThis();


	RETURN_STRING("prev.url.key");

}

zend_object *zephir_init_properties_Leevel_Session_Session(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$null, _0, _2, _3$$4;
		ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
			zephir_array_update_string(&_1$$3, SL("id"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("name"), &__$null, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("datas"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("datas"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

