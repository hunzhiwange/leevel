
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


/**
 * log 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Log, Manager, leevel, log_manager, leevel_manager_manager_ce, leevel_log_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Leevel_Log_Manager, normalizeOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("log");

}

/**
 * 创建连接对象
 *
 * @param object $connect
 * @return object
 */
PHP_METHOD(Leevel_Log_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect, connect_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect);



	object_init_ex(return_value, leevel_log_log_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcommonoption", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 127, connect, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 file 日志驱动
 *
 * @param array $options
 * @return \Leevel\Log\File
 */
PHP_METHOD(Leevel_Log_Manager, makeConnectFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	object_init_ex(return_value, leevel_log_file_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "file");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 128, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 syslog 日志驱动
 *
 * @param array $options
 * @return \Leevel\Log\Syslog
 */
PHP_METHOD(Leevel_Log_Manager, makeConnectSyslog) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	object_init_ex(return_value, leevel_log_syslog_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "syslog");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 129, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

