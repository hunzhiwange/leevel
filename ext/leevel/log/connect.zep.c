
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
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * connect 驱动抽象类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.09.01
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_Connect) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Log, Connect, leevel, log_connect, leevel_log_connect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Monolog.
	 *
	 * @var \Monolog\Logger
	 */
	zend_declare_property_null(leevel_log_connect_ce, SL("monolog"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_connect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Monolog 支持日志级别
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_connect_ce, SL("supportLevel"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_log_connect_ce->create_object = zephir_init_properties_Leevel_Log_Connect;

	zend_class_implements(leevel_log_connect_ce TSRMLS_CC, 1, leevel_log_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 */
PHP_METHOD(Leevel_Log_Connect, __construct) {

	zend_class_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, _0, _1, _2, _4, _5;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

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
	ZEPHIR_INIT_VAR(&_2);
	if (!_3) {
	_3 = zephir_fetch_class_str_ex(SL("Monolog\\Logger"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_2, _3);
	if (zephir_has_constructor(&_2 TSRMLS_CC)) {
		zephir_read_property(&_4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_5, &_4, SL("channel"), PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 75 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0, &_5);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("monolog"), &_2);
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
PHP_METHOD(Leevel_Log_Connect, setOption) {

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
 * 日志写入接口.
 *
 * @param array $data
 */
PHP_METHOD(Leevel_Log_Connect, flush) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_3 = NULL;
	zval *data_param = NULL, value, method, *_0, _1$$3, _4$$3, _6$$3;
	zval data, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_is_iterable(&data, 0, "leevel/log/connect.zep", 106);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _0)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_MAKE_REF(&value);
		ZEPHIR_CALL_FUNCTION(&_1$$3, "array_shift", &_2, 6, &value);
		ZEPHIR_UNREF(&value);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&method, this_ptr, "normalizelevel", &_3, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZEPHIR_INIT_NVAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_6$$3);
		zephir_read_property(&_6$$3, this_ptr, SL("monolog"), PH_NOISY_CC);
		zephir_array_fast_append(&_5$$3, &_6$$3);
		zephir_array_fast_append(&_5$$3, &method);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_4$$3, &_5$$3, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得 Monolog.
 *
 * @return \Monolog\Logger
 */
PHP_METHOD(Leevel_Log_Connect, getMonolog) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "monolog");

}

/**
 * 设置默认格式化.
 *
 * @param \Monolog\Handler\HandlerInterface $handler
 *
 * @return \Monolog\Handler\HandlerInterface
 */
PHP_METHOD(Leevel_Log_Connect, normalizeHandler) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handler);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "lineformatter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(handler, "setformatter", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 默认行格式化.
 *
 * @return \Monolog\Formatter\LineFormatter
 */
PHP_METHOD(Leevel_Log_Connect, lineFormatter) {

	zval _1, _2, _3, _4;
	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Formatter\\LineFormatter"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZVAL_NULL(&_1);
		ZVAL_NULL(&_2);
		ZVAL_BOOL(&_3, 1);
		ZVAL_BOOL(&_4, 1);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_1, &_2, &_3, &_4);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 格式化级别
 * 不支持级别归并到 DEBUG.
 *
 * @param string $level
 *
 * @return string
 */
PHP_METHOD(Leevel_Log_Connect, normalizeLevel) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *level_param = NULL, __$true, _0, _1, _2;
	zval level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(&_0, &_1 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", NULL, 54, &level, &_0, &__$true);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_STRING("debug");
	}
	RETURN_CTOR(&level);

}

/**
 * 获取 Monolog 级别
 * 不支持级别归并到 DEBUG.
 *
 * @param string $level
 *
 * @return int
 */
PHP_METHOD(Leevel_Log_Connect, normalizeMonologLevel) {

	zval *level_param = NULL, _0, _3, _4, _1$$3, _2$$3;
	zval level;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_property(&_0, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &level)) {
		zephir_read_property(&_1$$3, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &level, PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 168 TSRMLS_CC);
		RETURN_CTOR(&_2$$3);
	}
	zephir_read_property(&_3, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("debug"), PH_NOISY | PH_READONLY, "leevel/log/connect.zep", 171 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

zend_object *zephir_init_properties_Leevel_Log_Connect(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _3$$4;
	zval _0, _2;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("supportLevel"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 8, 0 TSRMLS_CC);
			add_assoc_long_ex(&_1$$3, SL("debug"), 100);
			add_assoc_long_ex(&_1$$3, SL("info"), 200);
			add_assoc_long_ex(&_1$$3, SL("notice"), 250);
			add_assoc_long_ex(&_1$$3, SL("warning"), 300);
			add_assoc_long_ex(&_1$$3, SL("error"), 400);
			add_assoc_long_ex(&_1$$3, SL("critical"), 500);
			add_assoc_long_ex(&_1$$3, SL("alert"), 550);
			add_assoc_long_ex(&_1$$3, SL("emergency"), 600);
			zephir_update_property_zval(this_ptr, SL("supportLevel"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 1, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("channel"), SL("development"));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

