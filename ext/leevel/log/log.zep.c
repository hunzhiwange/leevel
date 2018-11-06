
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
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * 日志仓储.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.03.03
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_Log) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Log, Log, leevel, log_log, leevel_log_log_method_entry, 0);

	/**
	 * 存储连接对象
	 *
	 * @var \Leevel\Log\IConnect
	 */
	zend_declare_property_null(leevel_log_log_ce, SL("connect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 当前记录的日志信息.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_log_ce, SL("logs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志过滤器.
	 *
	 * @var \Closure
	 */
	zend_declare_property_null(leevel_log_log_ce, SL("filter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志处理器.
	 *
	 * @var \Closure
	 */
	zend_declare_property_null(leevel_log_log_ce, SL("processor"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志数量.
	 *
	 * @var int
	 */
	zend_declare_property_long(leevel_log_log_ce, SL("count"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_log_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_log_log_ce->create_object = zephir_init_properties_Leevel_Log_Log;

	zend_class_implements(leevel_log_log_ce TSRMLS_CC, 1, leevel_log_ilog_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param \Leevel\Log\IConnect $connect
 * @param array                $option
 */
PHP_METHOD(Leevel_Log_Log, __construct) {

	zval option;
	zval *connect, connect_sub, *option_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
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
PHP_METHOD(Leevel_Log_Log, setOption) {

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
 * 系统无法使用.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, emergency) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "emergency");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 必须立即采取行动.
 *
 * 比如: 整个网站宕机，数据库不可用等等.
 * 这种错误应该通过短信通知你.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "alert");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 临界条件.
 *
 * 比如: 应用程序组件不可用，意外异常.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, critical) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "critical");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 运行时错误，不需要立即处理.
 * 但是需要被记录和监控.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 非错误的异常事件.
 *
 * 比如: 弃用的 API 接口, API 使用不足, 不良事物.
 * 它们不一定是错误的.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 正常重要事件.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 想记录的日志.
 *
 * 比如: 用户日志, SQL 日志.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 调试信息.
 *
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, debug) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "debug");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 记录特定级别的日志信息.
 *
 * @param mixed  $level
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Leevel_Log_Log, log) {

	zend_bool _4, _9, _12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, __$true, data, _0, _1, _2, _3, _5, _6, _7, _8, _10, _11, _13, _14, _15;
	zval level, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	zephir_get_strval(&level, level_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("levels"), PH_NOISY | PH_READONLY, "leevel/log/log.zep", 225 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "in_array", NULL, 55, &level, &_1, &__$true);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&data, &level);
	zephir_array_fast_append(&data, &message);
	zephir_array_fast_append(&data, &context);
	zephir_read_property(&_3, this_ptr, SL("filter"), PH_NOISY_CC | PH_READONLY);
	_4 = Z_TYPE_P(&_3) != IS_NULL;
	if (_4) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_read_property(&_6, this_ptr, SL("filter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_5, &_6, &data);
		zephir_check_call_status();
		_4 = ZEPHIR_IS_FALSE_IDENTICAL(&_5);
	}
	if (_4) {
		RETURN_MM_NULL();
	}
	RETURN_ON_FAILURE(zephir_property_incr(this_ptr, SL("count") TSRMLS_CC));
	zephir_update_property_array_multi(this_ptr, SL("logs"), &data TSRMLS_CC, SL("za"), 2, &level);
	zephir_read_property(&_7, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_8, &_7, SL("buffer"), PH_NOISY | PH_READONLY, "leevel/log/log.zep", 242 TSRMLS_CC);
	_9 = ZEPHIR_IS_FALSE_IDENTICAL(&_8);
	if (!(_9)) {
		zephir_read_property(&_10, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_11);
		zephir_array_fetch_string(&_11, &_10, SL("buffer_size"), PH_NOISY, "leevel/log/log.zep", 243 TSRMLS_CC);
		_12 = zephir_is_true(&_11);
		if (_12) {
			zephir_read_property(&_13, this_ptr, SL("count"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_14, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch_string(&_15, &_14, SL("buffer_size"), PH_NOISY | PH_READONLY, "leevel/log/log.zep", 243 TSRMLS_CC);
			_12 = ZEPHIR_GE(&_13, &_15);
		}
		_9 = _12;
	}
	if (_9) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存日志信息.
 */
PHP_METHOD(Leevel_Log_Log, flush) {

	zval data, _0, *_1;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "leevel/log/log.zep", 259);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&data);
		ZVAL_COPY(&data, _1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "savestore", &_2, 0, &data);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&data);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清理日志记录.
 *
 * @param string $level
 */
PHP_METHOD(Leevel_Log_Log, clear) {

	zval *level = NULL, level_sub, __$null, _0$$3, _1$$3, _2, _3$$4, _4$$4, _5$$4, _6$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &level);

	if (!level) {
		level = &level_sub;
		level = &__$null;
	}


	if (Z_TYPE_P(level) == IS_NULL) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$3);
		ZVAL_LONG(&_0$$3, 0);
		zephir_update_property_zval(this_ptr, SL("count"), &_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		array_init(&_1$$3);
		zephir_update_property_zval(this_ptr, SL("logs"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_2, level)) {
		zephir_read_property(&_3$$4, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, level, PH_NOISY | PH_READONLY, "leevel/log/log.zep", 275 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_LONG(&_6$$4, zephir_fast_count_int(&_4$$4 TSRMLS_CC));
		zephir_read_property(&_5$$4, this_ptr, SL("count"), PH_NOISY_CC);
		ZEPHIR_SUB_ASSIGN(&_5$$4, &_6$$4)
		zephir_update_property_zval(this_ptr, SL("count"), &_5$$4);
		ZEPHIR_INIT_VAR(&_7$$4);
		array_init(&_7$$4);
		zephir_update_property_array(this_ptr, SL("logs"), level, &_7$$4 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取日志记录.
 *
 * @param string $level
 *
 * @return array
 */
PHP_METHOD(Leevel_Log_Log, all) {

	zval *level = NULL, level_sub, __$null, _0, _1$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	zephir_fetch_params(0, 0, 1, &level);

	if (!level) {
		level = &level_sub;
		level = &__$null;
	}


	if (Z_TYPE_P(level) == IS_NULL) {
		RETURN_MEMBER(getThis(), "logs");
	}
	zephir_read_property(&_0, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, level)) {
		zephir_read_property(&_1$$4, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$4, &_1$$4, level, PH_NOISY | PH_READONLY, "leevel/log/log.zep", 294 TSRMLS_CC);
		RETURN_CTORW(&_2$$4);
	}
	array_init(return_value);
	return;

}

/**
 * 获取日志记录数量.
 *
 * @param string $level
 *
 * @return int
 */
PHP_METHOD(Leevel_Log_Log, count) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *level = NULL, level_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &level);

	if (!level) {
		level = &level_sub;
		level = &__$null;
	}


	if (Z_TYPE_P(level) == IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "count");
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "all", NULL, 0, level);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * 注册日志过滤器.
 *
 * @param \Closure $filter
 */
PHP_METHOD(Leevel_Log_Log, filter) {

	zval *filter, filter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);

	zephir_fetch_params(0, 1, 0, &filter);



	zephir_update_property_zval(this_ptr, SL("filter"), filter);

}

/**
 * 注册日志处理器.
 *
 * @param \Closure $processor
 */
PHP_METHOD(Leevel_Log_Log, processor) {

	zval *processor, processor_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&processor_sub);

	zephir_fetch_params(0, 1, 0, &processor);



	zephir_update_property_zval(this_ptr, SL("processor"), processor);

}

/**
 * 是否为 Monolog.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Log_Log, isMonolog) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL((zephir_method_exists_ex(&_0, SL("getmonolog") TSRMLS_CC) == SUCCESS));

}

/**
 * 取得 Monolog.
 *
 * @return null|\Monolog\Logger
 */
PHP_METHOD(Leevel_Log_Log, getMonolog) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "ismonolog", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getmonolog", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回连接.
 *
 * @return \Leevel\Log\IConnect
 */
PHP_METHOD(Leevel_Log_Log, getConnect) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "connect");

}

/**
 * 存储日志.
 *
 * @param array $data
 */
PHP_METHOD(Leevel_Log_Log, saveStore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, value, _0, _4, *_1$$3, _2$$4, _3$$4;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_read_property(&_0, this_ptr, SL("processor"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_is_iterable(&data, 0, "leevel/log/log.zep", 383);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _1$$3)
		{
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _1$$3);
			ZEPHIR_INIT_NVAR(&_2$$4);
			zephir_read_property(&_3$$4, this_ptr, SL("processor"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_2$$4, &_3$$4, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
	}
	zephir_read_property(&_4, this_ptr, SL("connect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "flush", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_Log_Log(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _2$$3;
	zval __$true, _0, _4, _3$$3, _5$$4;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 8, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "debug");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "info");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "notice");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "warning");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "error");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "critical");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "alert");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "emergency");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			zephir_array_update_string(&_1$$3, SL("levels"), &_2$$3, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_1$$3, SL("buffer"), &__$true, PH_COPY | PH_SEPARATE);
			add_assoc_long_ex(&_1$$3, SL("buffer_size"), 100);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_4, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$4);
			array_init(&_5$$4);
			zephir_update_property_zval(this_ptr, SL("logs"), &_5$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

