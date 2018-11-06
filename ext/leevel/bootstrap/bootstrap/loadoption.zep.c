
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
#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/concat.h"


/**
 * 读取配置
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.04.24
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_LoadOption) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Bootstrap\\Bootstrap, LoadOption, leevel, bootstrap_bootstrap_loadoption, leevel_bootstrap_bootstrap_loadoption_method_entry, 0);

	return SUCCESS;

}

/**
 * 响应
 * 
 * @param \Leevel\Kernel\IProject $project
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, handle) {

	zend_class_entry *_6$$4 = NULL;
	zval _3$$3;
	zend_bool test = 0;
	zval data, load, option, args, project, _0, _8, _1$$3, _2$$3, _4$$3, _5$$3, _7$$4;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&load);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&project);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_OBS_VAR(&project);
	zephir_array_fetch_long(&project, &args, 0, PH_NOISY, "leevel/bootstrap/bootstrap/loadoption.zep", 45 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, &project, "iscachedoption", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, &project, "optioncachedpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2$$3);
		if (zephir_require_zval_ret(&_2$$3, &_1$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		zephir_get_arrval(&_3$$3, &_2$$3);
		ZEPHIR_CPY_WRT(&data, &_3$$3);
		zephir_array_fetch_string(&_4$$3, &data, SL("app"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/loadoption.zep", 49 TSRMLS_CC);
		zephir_array_fetch_string(&_5$$3, &_4$$3, SL("_env"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/loadoption.zep", 49 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setenvs", NULL, 0, &_5$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&load);
		if (!_6$$4) {
		_6$$4 = zephir_fetch_class_str_ex(SL("Leevel\\Option\\Load"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&load, _6$$4);
		if (zephir_has_constructor(&load TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_7$$4, &project, "optionpath", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &load, "__construct", NULL, 0, &_7$$4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&data, &load, "loaddata", NULL, 0, &project);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&option);
	object_init_ex(&option, leevel_option_option_ce);
	ZEPHIR_CALL_METHOD(NULL, &option, "__construct", NULL, 57, &data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "option");
	ZEPHIR_CALL_METHOD(NULL, &project, "instance", NULL, 0, &_8, &option);
	zephir_check_call_status();
	test = 2 == ZEND_NUM_ARGS();
	if (!test) {
		ZEPHIR_CALL_CE_STATIC(NULL, leevel_support_facade_ce, "setcontainer", &_9, 0, &project);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initialization", NULL, 0, &option);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化处理
 *
 * @param array $env
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, setEnvs) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *env_param = NULL, name, value, *_0;
	zval env;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env_param);

	zephir_get_arrval(&env, env_param);


	zephir_is_iterable(&env, 0, "leevel/bootstrap/bootstrap/loadoption.zep", 80);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&env), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setenvvar", &_3, 0, &name, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置环境变量
 *
 * @param string $name
 * @param string|null $value
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, setEnvVar) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *name_param = NULL, *value = NULL, value_sub, *_ENV, *_SERVER, __$null, _0$$3, _1$$3, _4$$5;
	zval name, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_get_global(&_ENV, SL("_ENV"));
	if (!_ENV) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 1, &name_param, &value);

	zephir_get_strval(&name, name_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if ((Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(value)) {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "(true)");
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "(false)");
		}
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_VSV(&_1$$3, &name, "=", &_0$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "putenv", &_2, 58, &_1$$3);
		zephir_check_call_status();
	} else if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_VS(&_3$$4, &name, "(null)");
		ZEPHIR_CALL_FUNCTION(NULL, "putenv", &_2, 58, &_3$$4);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CONCAT_VSV(&_4$$5, &name, "=", value);
		ZEPHIR_CALL_FUNCTION(NULL, "putenv", &_2, 58, &_4$$5);
		zephir_check_call_status();
	}
	zephir_array_update_zval(_ENV, &name, value, PH_COPY | PH_SEPARATE);
	zephir_array_update_zval(_SERVER, &name, value, PH_COPY | PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化处理
 *
 * @param \Leevel\Option\Option $option
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadOption, initialization) {

	zend_bool _5;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option, option_sub, _0, _4, _6, _7, _1$$3, _2$$3, _3$$3, _8$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &option);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "UTF-8");
	ZEPHIR_CALL_FUNCTION(NULL, "mb_internal_encoding", NULL, 59, &_0);
	zephir_check_call_status();
	if ((zephir_function_exists_ex(SL("date_default_timezone_set") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "time_zone");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "UTC");
		ZEPHIR_CALL_METHOD(&_1$$3, option, "get", NULL, 0, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "date_default_timezone_set", NULL, 60, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "cli");
	if (ZEPHIR_IS_EQUAL(&_4, &_0)) {
		RETURN_MM_NULL();
	}
	_5 = (zephir_function_exists_ex(SL("gz_handler") TSRMLS_CC) == SUCCESS);
	if (_5) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "start_gzip");
		ZEPHIR_CALL_METHOD(&_6, option, "get", NULL, 0, &_7);
		zephir_check_call_status();
		_5 = zephir_is_true(&_6);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "gz_handler");
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_9, 61, &_8$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_9, 61);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

