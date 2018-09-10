
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
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * Session 中间件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.11.14
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Middleware_Session) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Session\\Middleware, Session, leevel, session_middleware_session, leevel_session_middleware_session_method_entry, 0);

	/**
	 * session 管理
	 *
	 * @var \Leevel\Session\Manager
	 */
	zend_declare_property_null(leevel_session_middleware_session_ce, SL("manager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Session\Manager $manager
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, __construct) {

	zval *manager, manager_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&manager_sub);

	zephir_fetch_params(0, 1, 0, &manager);



	zephir_update_property_zval(this_ptr, SL("manager"), manager);

}

/**
 * 请求
 *
 * @param \Closure $next
 * @param \Leevel\Http\IRequest $request
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, handle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *next, next_sub, *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&request_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &next, &request);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "startsession", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, next, NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 响应
 *
 * @param \Closure $next
 * @param \Leevel\Http\IRequest $request
 * @param \Leevel\Http\IResponse $response
 * @return void
 */
PHP_METHOD(Leevel_Session_Middleware_Session, terminate) {

	zval _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *next, next_sub, *request, request_sub, *response, response_sub, _0, _1$$3, _2$$3, _3$$3, _4$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&next_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &next, &request, &response);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setprevurl", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "savesession", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getsessionid", NULL, 0, request);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_3$$3, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "getid", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "getsessionexpire", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_string(&_5$$3, SL("expire"), &_6$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, response, "setcookie", NULL, 0, &_2$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_ZVAL_FUNCTION(NULL, next, NULL, 0, request, response);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 启动 session.
 *
 * @param \Leevel\Http\IRequest $request
 */
PHP_METHOD(Leevel_Session_Middleware_Session, startSession) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsessionid", NULL, 0, request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "start", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存 session.
 */
PHP_METHOD(Leevel_Session_Middleware_Session, saveSession) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "save", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存当期请求 URL.
 *
 * @param \Leevel\Http\IRequest $request
 */
PHP_METHOD(Leevel_Session_Middleware_Session, setPrevUrl) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "setprevurl", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取 session ID.
 *
 * @param \Leevel\Http\IRequest $request
 *
 * @return null|string
 */
PHP_METHOD(Leevel_Session_Middleware_Session, getSessionId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, request, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getname", NULL, 0);
	zephir_check_call_status();
	ZVAL_NULL(&_3);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取 session 过期时间.
 *
 * @return int
 */
PHP_METHOD(Leevel_Session_Middleware_Session, getSessionExpire) {

	zval option, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&option);
	array_init(&option);
	zephir_read_property(&_0, this_ptr, SL("manager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&option, &_0, "getsessionoption", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_array_isset_string(&option, SL("expire"))) {
		zephir_array_fetch_string(&_1, &option, SL("expire"), PH_NOISY, "leevel/session/middleware/session.zep", 143 TSRMLS_CC);
	} else {
		ZVAL_LONG(&_1, 0);
	}
	RETURN_CCTOR(&_1);

}

