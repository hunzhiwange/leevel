
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


/**
 * 注册运行时异常
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.04.25
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_RegisterRuntime) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Bootstrap\\Bootstrap, RegisterRuntime, leevel, bootstrap_bootstrap_registerruntime, leevel_bootstrap_bootstrap_registerruntime_method_entry, 0);

	/**
	 * 容器
	 *
	 * @var \Leevel\Di\IProject
	 */
	zend_declare_property_null(leevel_bootstrap_bootstrap_registerruntime_ce, SL("project"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 响应
 * 
 * @param \Leevel\Kernel\IProject $project
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, handle) {

	zval _1$$3, _3$$3, _4$$3;
	zval args, project, _0$$3, _2$$3, _5$$3, _6$$4, _7$$4;
	zend_bool test = 0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&project);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_OBS_VAR(&project);
	zephir_array_fetch_long(&project, &args, 0, PH_NOISY, "leevel/bootstrap/bootstrap/registerruntime.zep", 53 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("project"), &project);
	test = 2 == ZEND_NUM_ARGS();
	if (!test) {
		ZVAL_LONG(&_0$$3, 32767);
		ZEPHIR_CALL_FUNCTION(NULL, "error_reporting", NULL, 62, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_1$$3, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "setErrorHandle");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 48, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "setExceptionHandler");
		zephir_array_fast_append(&_3$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "set_exception_handler", NULL, 63, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_4$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "registerShutdownFunction");
		zephir_array_fast_append(&_4$$3, &_2$$3);
		ZEPHIR_CALL_FUNCTION(NULL, "register_shutdown_function", NULL, 64, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, &project, "environment", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_IS_STRING_IDENTICAL(&_5$$3, "production")) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "display_errors");
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "Off");
			ZEPHIR_CALL_FUNCTION(NULL, "ini_set", NULL, 65, &_6$$4, &_7$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置错误句柄
 * 
 * @param integer $code
 * @param string $description
 * @param string $file
 * @param interger $line
 * @param mixed $context
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, setErrorHandle) {

	zval description;
	zval *code_param = NULL, *description_param = NULL, *file = NULL, file_sub, *line = NULL, line_sub, *context = NULL, context_sub, __$null, _0, _1, _2, _3;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&line_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&description);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &code_param, &description_param, &file, &line, &context);

	code = zephir_get_intval(code_param);
	zephir_get_strval(&description, description_param);
	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!line) {
		line = &line_sub;
		line = &__$null;
	}
	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "error_reporting", NULL, 62);
	zephir_check_call_status();
	if (!(((int) (zephir_get_numberval(&_0)) & code))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("errorexception")));
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, code);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 66, &description, &_2, &_3, file, line);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_1, "leevel/bootstrap/bootstrap/registerruntime.zep", 90 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 设置退出句柄
 *
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, registerShutdownFunction) {

	zend_bool _0;
	zval error, _1, _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&error, "error_get_last", NULL, 67);
	zephir_check_call_status();
	_0 = zephir_is_true(&error);
	if (_0) {
		zephir_array_fetch_string(&_1, &error, SL("type"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/registerruntime.zep", 104 TSRMLS_CC);
		_0 = !(ZEPHIR_IS_EMPTY(&_1));
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "formaterrorexception", NULL, 0, &error);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setexceptionhandler", NULL, 0, &_2$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 响应异常
 *
 * @param \Throwable $e
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, setExceptionHandler) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, fatalException, _7, _8, _9, _10, _0$$3, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&fatalException);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	if (!(zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&fatalException);
		object_init_ex(&fatalException, zephir_get_internal_ce(SL("errorexception")));
		ZEPHIR_CALL_METHOD(&_0$$3, e, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_1$$3, e, "getcode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_2$$3, e, "getfile", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, e, "getline", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, e, "getprevious", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, &fatalException, "__construct", NULL, 66, &_0$$3, &_1$$3, &_5$$3, &_2$$3, &_3$$3, &_4$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&fatalException, e);
	}

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "getruntime", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "report", NULL, 0, &fatalException);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_OBJ(&_7, EG(exception));
		Z_ADDREF_P(&_7);
		ZEPHIR_INIT_VAR(&_8);
		if (zephir_instance_of_ev(&_7, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_8, &_7);
		}
	}
	zephir_read_property(&_9, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_10, &_9, "console", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "renderconsoleresponse", NULL, 0, &fatalException);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "renderhttpresponse", NULL, 0, &fatalException);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 渲染命令行异常并输出
 *
 * @param \Exception $e
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, renderConsoleResponse) {

	zend_class_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getruntime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Symfony\\Component\\Console\\Output\\ConsoleOutput"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_1, _2);
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &_0, "renderforconsole", NULL, 0, &_1, e);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 渲染 HTTP 异常并输出
 *
 * @param \Exception $e
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, renderHttpResponse) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &e);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getruntime", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("project"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "request");
	ZEPHIR_CALL_METHOD(&_3, &_2, "make", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "render", NULL, 0, &_3, e);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "send", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化致命错误信息
 *
 * @param array $error
 * @return \ErrorException
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, formatErrorException) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *error_param = NULL, _0, _1, _2, _3, _4;
	zval error;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &error_param);

	zephir_get_arrval(&error, error_param);


	object_init_ex(return_value, zephir_get_internal_ce(SL("errorexception")));
	zephir_array_fetch_string(&_0, &error, SL("message"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/registerruntime.zep", 175 TSRMLS_CC);
	zephir_array_fetch_string(&_1, &error, SL("type"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/registerruntime.zep", 175 TSRMLS_CC);
	zephir_array_fetch_string(&_2, &error, SL("file"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/registerruntime.zep", 175 TSRMLS_CC);
	zephir_array_fetch_string(&_3, &error, SL("line"), PH_NOISY | PH_READONLY, "leevel/bootstrap/bootstrap/registerruntime.zep", 176 TSRMLS_CC);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 66, &_0, &_1, &_4, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回运行处理器
 * 
 * @return \Leevel\Kernel\Exception\IRuntime
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_RegisterRuntime, getRuntime) {

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

