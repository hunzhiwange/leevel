
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
#include "ext/spl/spl_directory.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/main.h"


/**
 * 文件
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.26
 *
 * @version 1.0
 *
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Leevel_Http_File) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, File, leevel, http_file, spl_ce_SplFileObject, leevel_http_file_method_entry, 0);

	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param string $path
 * @return void
 */
PHP_METHOD(Leevel_Http_File, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1$$3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 26, &path);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, leevel_http_filenotfoundexception_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &path);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/http/file.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, leevel_http_file_ce, getThis(), "__construct", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 移动文件
 *
 * @param string $directory
 * @param string $name
 * @return \Leevel\Http\File
 */
PHP_METHOD(Leevel_Http_File, move) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory_param = NULL, *name = NULL, name_sub, __$null, target, _0;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directory_param, &name);

	zephir_get_strval(&directory, directory_param);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(&target, this_ptr, "gettargetfile", NULL, 0, &directory, name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpathname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "movetotarget", NULL, 0, &_0, &target);
	zephir_check_call_status();
	object_init_ex(return_value, leevel_http_file_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 44, &target);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取目标文件
 *
 * @param string $directory
 * @param string $name
 * @return string
 */
PHP_METHOD(Leevel_Http_File, getTargetFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory_param = NULL, *name = NULL, name_sub, __$true, __$null, target, _0, _1, _11, _12, _13, _2$$3, _3$$3, _7$$3, _4$$4, _5$$4, _6$$4, _8$$5, _9$$5, _10$$5;
	zval directory;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory);
	ZVAL_UNDEF(&name_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directory_param, &name);

	zephir_get_strval(&directory, directory_param);
	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 45, &directory);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_writable", NULL, 46, &directory);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_FUNCTION(&_2$$3, "dirname", NULL, 47, &directory);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_3$$3, "is_writable", NULL, 46, &_2$$3);
		zephir_check_call_status();
		if (!zephir_is_true(&_3$$3)) {
			ZEPHIR_INIT_VAR(&_4$$4);
			object_init_ex(&_4$$4, leevel_http_fileexception_ce);
			ZEPHIR_INIT_VAR(&_5$$4);
			ZVAL_STRING(&_5$$4, "Unable to create the %s directory.");
			ZEPHIR_CALL_FUNCTION(&_6$$4, "sprintf", NULL, 1, &_5$$4, &directory);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_6$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$4, "leevel/http/file.zep", 84 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_7$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 48, &directory, &_7$$3, &__$true);
		zephir_check_call_status();
	} else if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_8$$5);
		object_init_ex(&_8$$5, leevel_http_fileexception_ce);
		ZEPHIR_INIT_VAR(&_9$$5);
		ZVAL_STRING(&_9$$5, "Unable to write in the %s directory.");
		ZEPHIR_CALL_FUNCTION(&_10$$5, "sprintf", NULL, 1, &_9$$5, &directory);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_8$$5, "__construct", NULL, 3, &_10$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$5, "leevel/http/file.zep", 91 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "/\\");
	zephir_fast_trim(&_11, &directory, &_12, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_13);
	if (Z_TYPE_P(name) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_13, this_ptr, "getbasename", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&_13, name);
	}
	ZEPHIR_INIT_VAR(&target);
	ZEPHIR_CONCAT_VSV(&target, &_11, "/", &_13);
	RETURN_CCTOR(&target);

}

/**
 * 移动文件到目标文件
 *
 * @param string $sourcePath
 * @param string $target
 * @param bool   $isUploaded
 */
PHP_METHOD(Leevel_Http_File, moveToTarget) {

	zval _2;
	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isUploaded;
	zval *sourcePath_param = NULL, *target_param = NULL, *isUploaded_param = NULL, method, _0, _3, _4;
	zval sourcePath, target;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sourcePath);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &sourcePath_param, &target_param, &isUploaded_param);

	zephir_get_strval(&sourcePath, sourcePath_param);
	zephir_get_strval(&target, target_param);
	if (!isUploaded_param) {
		isUploaded = 0;
	} else {
		isUploaded = zephir_get_boolval(isUploaded_param);
	}


	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "errorHandlerClosure");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "set_error_handler", NULL, 49, &_0);
	zephir_check_call_status();
	if (isUploaded) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "move_uploaded_file");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "rename");
	}
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 8, &method, &sourcePath, &target);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "restore_error_handler", NULL, 50);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 0666);
	ZEPHIR_CALL_FUNCTION(NULL, "chmod", NULL, 51, &target, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建错误句柄闭包
 */
PHP_METHOD(Leevel_Http_File, errorHandlerClosure) {

	zval args, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, leevel_http_fileexception_ce);
	zephir_array_fetch_long(&_1, &args, 1, PH_NOISY | PH_READONLY, "leevel/http/file.zep", 129 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 3, &_1);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "leevel/http/file.zep", 129 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

