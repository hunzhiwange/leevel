
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


/**
 * log.syslog.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.09.01
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_Syslog) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Log, Syslog, leevel, log_syslog, leevel_log_connect_ce, leevel_log_syslog_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @see \Monolog\Handler\AbstractSyslogHandler
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_syslog_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_log_syslog_ce->create_object = zephir_init_properties_Leevel_Log_Syslog;
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 */
PHP_METHOD(Leevel_Log_Syslog, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *option_param = NULL;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_CALL_PARENT(NULL, leevel_log_syslog_ce, getThis(), "__construct", &_0, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "makesysloghandler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化系统 handler.
 *
 * @return \Psr\Log\LoggerInterface
 */
PHP_METHOD(Leevel_Log_Syslog, makeSyslogHandler) {

	zend_class_entry *_0 = NULL;
	zval handler, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&handler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Monolog\\Handler\\SyslogHandler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&handler, _0);
	if (zephir_has_constructor(&handler TSRMLS_CC)) {
		zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_2, &_1, SL("channel"), PH_NOISY | PH_READONLY, "leevel/log/syslog.zep", 67 TSRMLS_CC);
		zephir_read_property(&_3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_4, &_3, SL("facility"), PH_NOISY | PH_READONLY, "leevel/log/syslog.zep", 68 TSRMLS_CC);
		zephir_read_property(&_6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_7, &_6, SL("level"), PH_NOISY | PH_READONLY, "leevel/log/syslog.zep", 69 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_5, this_ptr, "normalizemonologlevel", NULL, 0, &_7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &handler, "__construct", NULL, 0, &_2, &_4, &_5);
		zephir_check_call_status();
	}
	zephir_read_property(&_8, this_ptr, SL("monolog"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "normalizehandler", NULL, 0, &handler);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_8, "pushhandler", NULL, 0, &_9);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Log_Syslog(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_3$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("channel"), SL("development"));
			add_assoc_long_ex(&_3$$4, SL("facility"), 8);
			add_assoc_stringl_ex(&_3$$4, SL("level"), SL("debug"));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

