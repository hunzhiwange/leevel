
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *option_param = NULL, __$true, temp, type, tmp, slave, tmp2, _0, *_1, _6, *_7, _10, _11, _12, _2$$3, _3$$3, _8$$8, _9$$9, _13$$10, _14$$11, _15$$11, _16$$11, _17$$11, _19$$11, *_20$$11, _18$$12, _21$$13;
	zval option, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_5);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&slave);
	ZVAL_UNDEF(&tmp2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$8);
	ZVAL_UNDEF(&_9$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_21$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option_param);

	zephir_get_arrval(&option, option_param);


	ZEPHIR_CPY_WRT(&temp, &option);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, &option TSRMLS_CC);
	zephir_is_iterable(&_0, 0, "leevel/database/manager.zep", 131);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _1);
		ZEPHIR_INIT_NVAR(&tmp);
		zephir_create_array(&tmp, 5, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "distributed");
		zephir_array_fast_append(&tmp, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "separate");
		zephir_array_fast_append(&tmp, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "driver");
		zephir_array_fast_append(&tmp, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "master");
		zephir_array_fast_append(&tmp, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "slave");
		zephir_array_fast_append(&tmp, &_2$$3);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "in_array", &_4, 55, &type, &tmp, &__$true);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
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
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "master");
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "slave");
	zephir_array_fast_append(&_5, &_6);
	zephir_is_iterable(&_5, 0, "leevel/database/manager.zep", 137);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _7)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _7);
		zephir_array_fetch(&_8$$8, &option, &type, PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 132 TSRMLS_CC);
		if (!(Z_TYPE_P(&_8$$8) == IS_ARRAY)) {
			ZEPHIR_INIT_NVAR(&_9$$9);
			array_init(&_9$$9);
			zephir_array_update_zval(&option, &type, &_9$$9, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_array_fetch_string(&_10, &option, SL("master"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 137 TSRMLS_CC);
	zephir_fast_array_merge(&_6, &_10, &temp TSRMLS_CC);
	zephir_array_update_string(&option, SL("master"), &_6, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_11, &option, SL("distributed"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 139 TSRMLS_CC);
	zephir_array_fetch_string(&_12, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 141 TSRMLS_CC);
	if (!(zephir_is_true(&_11))) {
		ZEPHIR_INIT_VAR(&_13$$10);
		array_init(&_13$$10);
		zephir_array_update_string(&option, SL("slave"), &_13$$10, PH_COPY | PH_SEPARATE);
	} else if (zephir_is_true(&_12)) {
		zephir_array_fetch_string(&_14$$11, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 142 TSRMLS_CC);
		zephir_array_fetch_string(&_15$$11, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 142 TSRMLS_CC);
		ZVAL_LONG(&_16$$11, 1);
		ZEPHIR_CALL_FUNCTION(&_17$$11, "count", NULL, 99, &_15$$11, &_16$$11);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG_IDENTICAL(&_17$$11, zephir_fast_count_int(&_14$$11 TSRMLS_CC))) {
			ZEPHIR_INIT_VAR(&tmp2);
			zephir_create_array(&tmp2, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_18$$12);
			zephir_array_fetch_string(&_18$$12, &option, SL("slave"), PH_NOISY, "leevel/database/manager.zep", 143 TSRMLS_CC);
			zephir_array_fast_append(&tmp2, &_18$$12);
			zephir_array_update_string(&option, SL("slave"), &tmp2, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_string(&_19$$11, &option, SL("slave"), PH_NOISY | PH_READONLY, "leevel/database/manager.zep", 147 TSRMLS_CC);
		zephir_is_iterable(&_19$$11, 0, "leevel/database/manager.zep", 150);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_19$$11), _20$$11)
		{
			ZEPHIR_INIT_NVAR(&slave);
			ZVAL_COPY(&slave, _20$$11);
			ZEPHIR_INIT_NVAR(&_21$$13);
			zephir_fast_array_merge(&_21$$13, &slave, &temp TSRMLS_CC);
			ZEPHIR_CPY_WRT(&slave, &_21$$13);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&slave);
	}
	RETURN_CTOR(&option);

}

