
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * 内核执行
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2016.11.18
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Kernel) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Bootstrap, Kernel, leevel, bootstrap_kernel, leevel_bootstrap_kernel_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 项目
	 *
	 * @var \Leevel\Kernel\IProject
	 */
	zend_declare_property_null(leevel_bootstrap_kernel_ce, SL("project"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 路由
	 *
	 * @var \Leevel\Router\IRouter
	 */
	zend_declare_property_null(leevel_bootstrap_kernel_ce, SL("router"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 项目初始化执行
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_bootstrap_kernel_ce, SL("bootstraps"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_bootstrap_kernel_ce->create_object = zephir_init_properties_Leevel_Bootstrap_Kernel;

	zend_class_implements(leevel_bootstrap_kernel_ce TSRMLS_CC, 1, leevel_kernel_ikernel_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Kernel\IProject $project
 * @param \Leevel\Router\IRouter $router
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, __construct) {

	zval *project, project_sub, *router, router_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&router_sub);

	zephir_fetch_params(0, 2, 0, &project, &router);



	zephir_update_property_zval(this_ptr, SL("project"), project);
	zephir_update_property_zval(this_ptr, SL("router"), router);

}

/**
 * 响应 HTTP 请求
 *
 * @param \Leevel\Http\IRequest $request
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, handle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, response, e, fatalException, _1, _0$$3, _2$$6, _3$$6, _4$$6, _5$$6, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&fatalException);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);




	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbaseservice", NULL, 0, request);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bootstrap", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&response, this_ptr, "getresponsewithrequest", NULL, 0, request);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "preparetrace", NULL, 0, &response);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(&response, &_0$$3);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "middlewareterminate", NULL, 0, request, &response);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		if (zephir_instance_of_ev(&_1, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "reportexception", NULL, 0, &e);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&response, this_ptr, "renderexception", NULL, 0, request, &e);
			zephir_check_call_status();
		} else {
			if (zephir_is_instance_of(&_1, SL("Throwable") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_1);
				ZEPHIR_INIT_VAR(&fatalException);
				object_init_ex(&fatalException, zephir_get_internal_ce(SL("errorexception")));
				ZEPHIR_CALL_METHOD(&_2$$6, &e, "getmessage", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_3$$6, &e, "getcode", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_4$$6, &e, "getfile", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_5$$6, &e, "getline", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$6, &e, "getprevious", NULL, 0);
				zephir_check_call_status();
				ZVAL_LONG(&_7$$6, 1);
				ZEPHIR_CALL_METHOD(NULL, &fatalException, "__construct", NULL, 67, &_2$$6, &_3$$6, &_7$$6, &_4$$6, &_5$$6, &_6$$6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "reportexception", NULL, 0, &fatalException);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&response, this_ptr, "renderexception", NULL, 0, request, &fatalException);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(&response);

}

/**
 * 返回运行处理器
 * 
 * @return \Leevel\Bootstrap\Runtime\IRuntime
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, getRuntime) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Kernel\\Runtime\\IRuntime");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 执行结束
 *
 * @param \Leevel\Http\IRequest $request
 * @param \Leevel\Http\IResponse $response
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, terminate) {

	zval *request, request_sub, *response, response_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);

	zephir_fetch_params(0, 2, 0, &request, &response);




}

/**
 * 返回项目
 *
 * @return \Leevel\Kernel\IProject
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, getProject) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "project");

}

/**
 * 注册基础服务
 * 
 * @param \Leevel\Http\IRequest $request
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, registerBaseService) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(NULL, &_0, "instance", NULL, 0, &_1, request);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 根据请求返回响应
 *
 * @param \Leevel\Http\IRequest $request
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, getResponseWithRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatchrouter", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 路由调度
 *
 * @param \Leevel\Http\IRequest $request
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, dispatchRouter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_read_property(&_0, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "dispatch", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 初始化
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, bootstrap) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("bootstraps"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "bootstrap", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 上报错误
 *
 * @param \Exception $e
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, reportException) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getruntime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "report", NULL, 0, e);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 渲染异常
 *
 * @param \Leevel\Http\IRequest $request
 * @param \Exception $e
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, renderException) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *e, e_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &e);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getruntime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "render", NULL, 0, request, e);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 调试信息
 *
 * @param \Leevel\Http\IResponse $response
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, prepareTrace) {

	zend_bool _5, _6, _8;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, logs, data, _0, _1, _2, _3, _4, _7, _9$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&logs);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	zephir_read_property(&_0, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "debug", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETVAL_ZVAL(response, 1, 0);
		RETURN_MM();
	}
	zephir_read_property(&_2, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Leevel\\Log\\ILog");
	ZEPHIR_CALL_METHOD(&_3, &_2, "make", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&logs, &_3, "all", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&data, response, "getdata", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_instance_of_ev(response, leevel_http_apiresponse_ce TSRMLS_CC);
	if (!(_5)) {
		_5 = zephir_instance_of_ev(response, leevel_http_jsonresponse_ce TSRMLS_CC);
	}
	_6 = _5;
	if (!(_6)) {
		ZEPHIR_CALL_METHOD(&_7, response, "isjson", NULL, 0);
		zephir_check_call_status();
		_6 = zephir_is_true(&_7);
	}
	_8 = _6;
	if (_8) {
		_8 = Z_TYPE_P(&data) == IS_ARRAY;
	}
	if (_8) {
		ZEPHIR_CALL_CE_STATIC(&_9$$4, leevel_support_debug_console_ce, "jsontrace", &_10, 0, &logs);
		zephir_check_call_status();
		zephir_array_update_string(&data, SL("_TRACE"), &_9$$4, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, response, "setdata", NULL, 0, &data);
		zephir_check_call_status();
	} else if (!(zephir_instance_of_ev(response, leevel_http_redirectresponse_ce TSRMLS_CC))) {
		ZEPHIR_CALL_CE_STATIC(&data, leevel_support_debug_console_ce, "trace", &_11, 0, &logs);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, response, "appendcontent", NULL, 0, &data);
		zephir_check_call_status();
	}
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();

}

/**
 * 中间件结束响应.
 *
 * @param \Leevel\Http\IRequest  $request
 * @param \Leevel\Http\IResponse $response
 */
PHP_METHOD(Leevel_Bootstrap_Kernel, middlewareTerminate) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response, response_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &response);



	zephir_read_property(&_0, this_ptr, SL("router"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, response);
	ZEPHIR_CALL_METHOD(NULL, &_0, "throughmiddleware", NULL, 0, request, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_Bootstrap_Kernel(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0, _2$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("bootstraps"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Leevel\\Bootstrap\\Bootstrap\\LoadOption");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Leevel\\Bootstrap\\Bootstrap\\LoadI18n");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Leevel\\Bootstrap\\Bootstrap\\RegisterRuntime");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Leevel\\Bootstrap\\Bootstrap\\TraverseProvider");
			zephir_array_fast_append(&_1$$3, &_2$$3);
			zephir_update_property_zval(this_ptr, SL("bootstraps"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

