
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * database 入口.
 *
 * @method $this whereNull(...$arr)
 * @method $this whereNotNull(...$arr)
 * @method $this whereBetween(...$arr)
 * @method $this whereNotBetween(...$arr)
 * @method $this whereIn(...$arr)
 * @method $this whereNotIn(...$arr)
 * @method $this whereLike(...$arr)
 * @method $this whereNotLike(...$arr)
 * @method $this havingNull(...$arr)
 * @method $this havingNotNull(...$arr)
 * @method $this havingBetween(...$arr)
 * @method $this havingNotBetween(...$arr)
 * @method $this havingIn(...$arr)
 * @method $this havingNotIn(...$arr)
 * @method $this havingLike(...$arr)
 * @method $this havingNotLike(...$arr)
 * @method $this innerJoin($table, $cols, $cond)
 * @method $this leftJoin($table, $cols, $cond)
 * @method $this rightJoin($table, $cols, $cond)
 * @method $this fullJoin($table, $cols, $cond)
 * @method $this crossJoin($table, $cols)
 * @method $this naturalJoin($table, $cols)
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.02.15
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Database_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Database, Manager, leevel, database_manager, leevel_manager_manager_ce, leevel_database_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间.
 *
 * @return string
 */
PHP_METHOD(Leevel_Database_Manager, normalizeOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("database");

}

/**
 * 创建连接对象
 *
 * @param object $connect
 *
 * @return object
 */
PHP_METHOD(Leevel_Database_Manager, createConnect) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect, connect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect);



	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Database\\Database"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, connect);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 创建 mysql 连接.
 *
 * @param array $option
 *
 * @return \Leevel\Database\Mysql
 */
PHP_METHOD(Leevel_Database_Manager, makeConnectMysql) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, _1, _2;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Database\\Mysql"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "mysql");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizeconnectoption", NULL, 0, &_2, &option);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 读取默认配置.
 *
 * @param string $connect
 * @param array  $extendOption
 *
 * @return array
 */
PHP_METHOD(Leevel_Database_Manager, normalizeConnectOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval extendOption;
	zval *connect_param = NULL, *extendOption_param = NULL, _0;
	zval connect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&extendOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &connect_param, &extendOption_param);

	zephir_get_strval(&connect, connect_param);
	if (!extendOption_param) {
		ZEPHIR_INIT_VAR(&extendOption);
		array_init(&extendOption);
	} else {
		zephir_get_arrval(&extendOption, extendOption_param);
	}


	ZEPHIR_CALL_PARENT(&_0, leevel_database_manager_ce, getThis(), "normalizeconnectoption", &_1, 0, &connect, &extendOption);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsedatabaseoption", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析数据库配置参数.
 *
 * @param array $option
 *
 * @return array
 */
PHP_METHOD(Leevel_Database_Manager, parseDatabaseOption) {

	zend_string *_24$$11;
	zend_ulong _23$$11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *option_param = NULL, __$true, temp, type, tempSlave, k, _0, *_1, _7, *_8, _11, _12, _13, _3$$3, _4$$3, _9$$8, _10$$9, _14$$10, _15$$11, _16$$11, _17$$11, _18$$11, _20$$11, _21$$11, *_22$$11, _19$$12, _25$$13, _26$$13, _27$$13;
	zval option, _6, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&tempSlave);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	zephir_get_arrval(&option, option_param);


	ZEPHIR_CPY_WRT(&temp, &option);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &option TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "leevel/database/manager.zep", 129);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_create_array(&_2$$3, 5, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "distributed");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "separate");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "driver");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "master");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "slave");
		zephir_array_fast_append(&_2$$3, &_3$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "in_array", &_5, 55, &type, &_2$$3, &__$true);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			if (zephir_array_isset(&temp, &type)) {
				zephir_array_unset(&temp, &type, PH_SEPARATE);
			}
		} else {
			if (zephir_array_isset(&option, &type)) {
				zephir_array_unset(&option, &type, PH_SEPARATE);
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "master");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "slave");
	zephir_array_fast_append(&_6, &_7);
	zephir_is_iterable(&_6, 0, "leevel/database/manager.zep", 135);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_6), _8)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _8);
		zephir_array_fetch(&_9$$8, &option, &type, PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 130 TSRMLS_CC);
		if (!(Z_TYPE_P(&_9$$8) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_10$$9);
			array_init(&_10$$9);
			zephir_array_update_zval(&option, &type, &_10$$9, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_INIT_NVAR(&_7);
	zephir_array_fetch_string(&_11, &option, SL("master"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 135 TSRMLS_CC);
	zephir_fast_array_merge(&_7, &_11, &temp TSRMLS_CC);
	zephir_array_update_string(&option, SL("master"), &_7, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_12, &option, SL("distributed"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 137 TSRMLS_CC);
	zephir_array_fetch_string(&_13, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 139 TSRMLS_CC);
	if (!(zephir_is_true(&_12))) {
		ZEPHIR_INIT_VAR(&_14$$10);
		array_init(&_14$$10);
		zephir_array_update_string(&option, SL("slave"), &_14$$10, PH_COPY | PH_SEPARATE);
	} else if (zephir_is_true(&_13)) {
		zephir_array_fetch_string(&_15$$11, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 140 TSRMLS_CC);
		zephir_array_fetch_string(&_16$$11, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 140 TSRMLS_CC);
		ZVAL_LONG(&_17$$11, 1);
		ZEPHIR_CALL_FUNCTION(&_18$$11, "count", NULL, 95, &_16$$11, &_17$$11);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG_IDENTICAL(&_18$$11, zephir_fast_count_int(&_15$$11 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&tempSlave);
			zephir_create_array(&tempSlave, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_19$$12);
			zephir_array_fetch_string(&_19$$12, &option, SL("slave"), PH_NOISY, "leevel/database/manager.zep", 141 TSRMLS_CC);
			zephir_array_fast_append(&tempSlave, &_19$$12);
			zephir_array_update_string(&option, SL("slave"), &tempSlave, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_20$$11, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 145 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_21$$11);
		zephir_is_iterable(&_20$$11, 0, "leevel/database/manager.zep", 148);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_20$$11), _23$$11, _24$$11, _22$$11)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_24$$11 != NULL) { 
				ZVAL_STR_COPY(&k, _24$$11);
			} else {
				ZVAL_LONG(&k, _23$$11);
			}
			ZEPHIR_INIT_NVAR(&_21$$11);
			ZVAL_COPY(&_21$$11, _22$$11);
			ZEPHIR_INIT_NVAR(&_25$$13);
			zephir_array_fetch_string(&_26$$13, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 146 TSRMLS_CC);
			zephir_array_fetch(&_27$$13, &_26$$13, &k, PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 146 TSRMLS_CC);
			zephir_fast_array_merge(&_25$$13, &_27$$13, &temp TSRMLS_CC);
			zephir_array_update_multi(&option, &_25$$13 TSRMLS_CC, SL("sz"), 3, SL("slave"), &k);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&_21$$11);
		ZEPHIR_INIT_NVAR(&k);
	}
	RETURN_CTOR(&option);

}

