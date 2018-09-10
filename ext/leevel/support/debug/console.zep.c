
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


/**
 * 调试
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.05
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Support_Debug_Console) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Support\\Debug, Console, leevel, support_debug_console, leevel_support_debug_console_method_entry, 0);

	return SUCCESS;

}

/**
 * 记录调试信息
 * SQL 记录，加载文件等等
 *
 * @param array $log
 * @return string
 */
PHP_METHOD(Leevel_Support_Debug_Console, trace) {

	zval _10;
	zend_bool _2, _3, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *log_param = NULL, *_SERVER, trace, include, _0, _1, _4, _6, _7, _8, _9;
	zval log;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&include);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SERVER, SL("_SERVER"));
	if (!_SERVER) {
		ZEPHIR_THROW_EXCEPTION_STR(zend_exception_get_default(), "Invalid superglobal");
		return;
	}
	zephir_fetch_params(1, 1, 0, &log_param);

	zephir_get_arrval(&log, log_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_SAPI");
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "cli");
	_2 = ZEPHIR_IS_EQUAL(&_1, &_0);
	if (_2) {
		_3 = zephir_array_isset_string(_SERVER, SL("SERVER_SOFTWARE"));
		if (_3) {
			zephir_array_fetch_string(&_4, _SERVER, SL("SERVER_SOFTWARE"), PH_NOISY | PH_READONLY, "leevel/support/debug/console.zep", 40 TSRMLS_CC);
			_3 = ZEPHIR_IS_STRING(&_4, "swoole-http-server");
		}
		_2 = !(_3);
	}
	if (_2) {
		RETURN_MM_NULL();
	}
	_5 = zephir_array_isset_string(_SERVER, SL("HTTP_X_REQUESTED_WITH"));
	if (_5) {
		ZEPHIR_INIT_VAR(&_6);
		zephir_array_fetch_string(&_7, _SERVER, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "leevel/support/debug/console.zep", 45 TSRMLS_CC);
		zephir_fast_strtolower(&_6, &_7);
		_5 = ZEPHIR_IS_STRING(&_6, "xmlhttprequest");
	}
	if (_5) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_SELF(&trace, "normalizelog", NULL, 0, &log);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&include, "get_included_files", NULL, 150);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_8);
	zephir_fast_join_str(&_8, SL("\\n"), &include TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_9);
	ZVAL_LONG(&_9, zephir_fast_count_int(&include TSRMLS_CC));
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SSVS(&_10, "LOADED.FILE", " (", &_9, ")");
	zephir_array_update_zval(&trace, &_10, &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_SELF("getoutputtoconsole", NULL, 0, &trace);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * JSON 记录调试信息
 * SQL 记录，加载文件等等
 *
 * @param array $log
 * @return array
 */
PHP_METHOD(Leevel_Support_Debug_Console, jsonTrace) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *log_param = NULL, trace, include, _0;
	zval log;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&include);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &log_param);

	zephir_get_arrval(&log, log_param);


	ZEPHIR_CALL_SELF(&trace, "normalizelog", NULL, 0, &log);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&include, "get_included_files", NULL, 150);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, zephir_fast_count_int(&include TSRMLS_CC));
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SSVS(&_1, "LOADED.FILE", " (", &_0, ")");
	zephir_array_update_zval(&trace, &_1, &include, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&trace);

}

/**
 * 返回输出到浏览器
 *
 * @param array $trace
 * @return string
 */
PHP_METHOD(Leevel_Support_Debug_Console, getOutputToConsole) {

	zend_string *_3;
	zend_ulong _2;
	zval *trace_param = NULL, content, key, item, _0, *_1, _4$$4, _5$$4, _6$$5;
	zval trace;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &trace_param);

	zephir_get_arrval(&trace, trace_param);


	ZEPHIR_INIT_VAR(&content);
	array_init(&content);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "<script type=\"text/javascript\">\nconsole.log( '%cThe PHP Framework For Code Poem As Free As Wind %c(http://www.queryphp.com)', 'font-weight: bold;color: #06359a;', 'color: #02d629;' );");
	zephir_array_append(&content, &_0, PH_SEPARATE, "leevel/support/debug/console.zep", 85);
	zephir_is_iterable(&trace, 0, "leevel/support/debug/console.zep", 97);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&trace), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		if (Z_TYPE_P(&key) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "console.log('');");
			zephir_array_append(&content, &_4$$4, PH_SEPARATE, "leevel/support/debug/console.zep", 88);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_SVS(&_5$$4, "console.log('%c ", &key, "', 'color: blue; background: #045efc; color: #fff; padding: 8px 15px; -moz-border-radius: 15px; -webkit-border-radius: 15px; border-radius: 15px;');");
			zephir_array_append(&content, &_5$$4, PH_SEPARATE, "leevel/support/debug/console.zep", 89);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "console.log('');");
			zephir_array_append(&content, &_4$$4, PH_SEPARATE, "leevel/support/debug/console.zep", 90);
		}
		if (zephir_is_true(&item)) {
			ZEPHIR_INIT_LNVAR(_6$$5);
			ZEPHIR_CONCAT_SVS(&_6$$5, "console.log('%c", &item, "', 'color: gray;');");
			zephir_array_append(&content, &_6$$5, PH_SEPARATE, "leevel/support/debug/console.zep", 94);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "</script>");
	zephir_array_append(&content, &_0, PH_SEPARATE, "leevel/support/debug/console.zep", 97);
	zephir_fast_join_str(return_value, SL(""), &content TSRMLS_CC);
	RETURN_MM();

}

/**
 * 格式化日志信息
 *
 * @param array $log
 * @return array
 */
PHP_METHOD(Leevel_Support_Debug_Console, normalizeLog) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *log_param = NULL, result, type, item, *_0, _3$$3, _4$$3, _6$$3, _7$$3, _8$$3;
	zval log;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &log_param);

	zephir_get_arrval(&log, log_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&log, 0, "leevel/support/debug/console.zep", 118);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&log), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&type);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&type, _2);
		} else {
			ZVAL_LONG(&type, _1);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		ZEPHIR_INIT_NVAR(&_3$$3);
		ZEPHIR_CALL_SELF(&_4$$3, "formatmessages", &_5, 0, &item);
		zephir_check_call_status();
		zephir_fast_join_str(&_3$$3, SL("\\n"), &_4$$3 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_fast_strtoupper(&_6$$3, &type);
		ZEPHIR_SINIT_NVAR(_7$$3);
		ZVAL_LONG(&_7$$3, zephir_fast_count_int(&item TSRMLS_CC));
		ZEPHIR_INIT_LNVAR(_8$$3);
		ZEPHIR_CONCAT_VSSVS(&_8$$3, &_6$$3, ".LOG", " (", &_7$$3, ")");
		zephir_array_update_zval(&result, &_8$$3, &_3$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&type);
	RETURN_CCTOR(&result);

}

/**
 * 格式化一组日志信息
 *
 * @param array $messages
 * @return array
 */
PHP_METHOD(Leevel_Support_Debug_Console, formatMessages) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *messages_param = NULL, item, *_0, _1$$3;
	zval messages, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&messages);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &messages_param);

	zephir_get_arrval(&messages, messages_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&messages, 0, "leevel/support/debug/console.zep", 136);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&messages), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		ZEPHIR_CALL_SELF(&_1$$3, "formatmessage", &_2, 0, &item);
		zephir_check_call_status();
		zephir_array_append(&result, &_1$$3, PH_SEPARATE, "leevel/support/debug/console.zep", 133);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&result);

}

/**
 * 格式化日志信息
 *
 * @param array $item
 * @return string
 */
PHP_METHOD(Leevel_Support_Debug_Console, formatMessage) {

	zval *item_param = NULL, _0, _1, _2, _3, _4;
	zval item;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &item_param);

	zephir_get_arrval(&item, item_param);


	zephir_array_fetch_long(&_0, &item, 0, PH_NOISY | PH_READONLY, "leevel/support/debug/console.zep", 147 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_fetch_long(&_2, &item, 1, PH_NOISY | PH_READONLY, "leevel/support/debug/console.zep", 147 TSRMLS_CC);
	ZVAL_LONG(&_3, 256);
	zephir_json_encode(&_1, &_2, zephir_get_intval(&_3) );
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VSV(&_4, &_0, " ", &_1);
	zephir_addslashes(return_value, &_4 TSRMLS_CC);
	RETURN_MM();

}

