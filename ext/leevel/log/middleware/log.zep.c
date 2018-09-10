
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


/**
 * log 中间件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.28
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_Middleware_Log) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Log\\Middleware, Log, leevel, log_middleware_log, leevel_log_middleware_log_method_entry, 0);

	/**
	 * log 管理
	 *
	 * @var \Leevel\Log\Manager
	 */
	zend_declare_property_null(leevel_log_middleware_log_ce, SL("manager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Log\Manager $manager
 * @return void
 */
PHP_METHOD(Leevel_Log_Middleware_Log, __construct) {

	zval *manager, manager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_zval(this_ptr, SL("manager"), manager);

}

/**
 * 响应
 * 
 * @param \Closure $next
 * @param \Leevel\Http\IRequest $request
 * @param \Leevel\Http\IResponse $response
 * @return void
 */
PHP_METHOD(Leevel_Log_Middleware_Log, terminate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *next, next_sub, *request, request_sub, *response, response_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &next, &request, &response);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "savelog", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, next, NULL, 0, request, response);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存日志
 */
PHP_METHOD(Leevel_Log_Middleware_Log, saveLog) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "flush", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

