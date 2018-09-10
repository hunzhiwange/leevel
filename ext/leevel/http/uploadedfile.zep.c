
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/array.h"


/**
 * 上传文件
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Leevel_Http_UploadedFile) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, UploadedFile, leevel, http_uploadedfile, leevel_http_file_ce, leevel_http_uploadedfile_method_entry, 0);

	/**
	 * 文件原始名字
	 * 
	 * @var string
	 */
	zend_declare_property_null(leevel_http_uploadedfile_ce, SL("originalName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 文件类型
	 * 
	 * @var string
	 */
	zend_declare_property_null(leevel_http_uploadedfile_ce, SL("mimeType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 上传错误
	 * 
	 * @var int|null
	 */
	zend_declare_property_null(leevel_http_uploadedfile_ce, SL("error"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 上传错误消息格式化
	 * 
	 * @var array
	 */
	zend_declare_property_null(leevel_http_uploadedfile_ce, SL("errors"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 是否为测试.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(leevel_http_uploadedfile_ce, SL("test"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 * $_FILES['foo'](tmp_name, name, type, error)
 *
 * @param string $path
 * @param string $originalName
 * @param string|null $mimeType
 * @param int|null $error
 * @param bool $test
 */
PHP_METHOD(Leevel_Http_UploadedFile, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_bool test;
	zval *path, path_sub, *originalName, originalName_sub, *mimeType = NULL, mimeType_sub, *error = NULL, error_sub, *test_param = NULL, __$true, __$false, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&originalName_sub);
	ZVAL_UNDEF(&mimeType_sub);
	ZVAL_UNDEF(&error_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &path, &originalName, &mimeType, &error, &test_param);

	if (!mimeType) {
		mimeType = &mimeType_sub;
		mimeType = &__$null;
	}
	if (!error) {
		error = &error_sub;
		error = &__$null;
	}
	if (!test_param) {
		test = 0;
	} else {
		test = zephir_get_boolval(test_param);
	}


	zephir_update_property_zval(this_ptr, SL("originalName"), originalName);
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(mimeType)) {
		ZEPHIR_CPY_WRT(&_0, mimeType);
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "application/octet-stream");
	}
	zephir_update_property_zval(this_ptr, SL("mimeType"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	if (zephir_is_true(error)) {
		ZEPHIR_CPY_WRT(&_1, error);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_LONG(&_1, 0);
	}
	zephir_update_property_zval(this_ptr, SL("error"), &_1);
	if (test) {
		zephir_update_property_zval(this_ptr, SL("test"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("test"), &__$false);
	}
	ZEPHIR_CALL_PARENT(NULL, leevel_http_uploadedfile_ce, getThis(), "__construct", &_2, 0, path);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回文件原始名字
 *
 * @return string|null
 */
PHP_METHOD(Leevel_Http_UploadedFile, getOriginalName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "originalName");

}

/**
 * 返回文件原始名字扩展
 *
 * @return string
 */
PHP_METHOD(Leevel_Http_UploadedFile, getOriginalExtension) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("originalName"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 27, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回文件类型
 *
 * @return string|null
 */
PHP_METHOD(Leevel_Http_UploadedFile, getMimeType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mimeType");

}

/**
 * 返回上传错误
 *
 * @return int
 */
PHP_METHOD(Leevel_Http_UploadedFile, getError) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "error");

}

/**
 * 文件是否上传成功
 *
 * @return bool
 */
PHP_METHOD(Leevel_Http_UploadedFile, isValid) {

	zend_bool _1;
	zval _0, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("error"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_IS_LONG_IDENTICAL(&_0, 0);
	if (_1) {
		ZEPHIR_INIT_VAR(&_2);
		zephir_read_property(&_3, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_3)) {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_BOOL(&_2, 1);
		} else {
			ZEPHIR_CALL_METHOD(&_4, this_ptr, "getpathname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_2, "is_uploaded_file", NULL, 121, &_4);
			zephir_check_call_status();
		}
		_1 = zephir_is_true(&_2);
	}
	RETURN_MM_BOOL(_1);

}

/**
 * {@inheritdoc}
 *
 * @codeCoverageIgnoreStart
 */
PHP_METHOD(Leevel_Http_UploadedFile, move) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *directory, directory_sub, *name = NULL, name_sub, __$null, target, _0, _5, _6, _1$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&directory_sub);
	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &directory, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isvalid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("test"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$3)) {
			ZEPHIR_RETURN_CALL_PARENT(leevel_http_uploadedfile_ce, getThis(), "move", &_2, 0, directory, name);
			zephir_check_call_status();
			RETURN_MM();
		}
		ZEPHIR_CALL_METHOD(&target, this_ptr, "gettargetfile", NULL, 0, directory, name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$3, this_ptr, "getpathname", NULL, 0);
		zephir_check_call_status();
		ZVAL_BOOL(&_4$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "movetotarget", NULL, 0, &_3$$3, &target, &_4$$3);
		zephir_check_call_status();
		object_init_ex(return_value, leevel_http_file_ce);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 44, &target);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, leevel_http_fileexception_ce);
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "geterrormessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 3, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_5, "leevel/http/uploadedfile.zep", 165 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 返回文件最大上传字节
 *
 * @return int
 * @codeCoverageIgnoreStart
 */
PHP_METHOD(Leevel_Http_UploadedFile, getMaxFilesize) {

	zval iniMax, max, _0, _1, _2, _3, _4, _5, _12, _13, _6$$4, _7$$4, _9$$5, _10$$5, _14$$7, _15$$8, _16$$9, _17$$10;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&iniMax);
	ZVAL_UNDEF(&max);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "upload_max_filesize");
	ZEPHIR_CALL_FUNCTION(&_1, "ini_get", NULL, 122, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&iniMax);
	zephir_fast_strtolower(&iniMax, &_1);
	if (ZEPHIR_IS_STRING_IDENTICAL(&iniMax, "")) {
		ZEPHIR_GET_CONSTANT(return_value, "PHP_INT_MAX");
		RETURN_MM();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "+");
	ZEPHIR_INIT_VAR(&max);
	zephir_fast_trim(&max, &iniMax, &_0, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "0x");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, &max, &_2, 0 );
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "0");
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strpos(&_5, &max, &_4, 0 );
	if (ZEPHIR_IS_LONG_IDENTICAL(&_3, 0)) {
		ZVAL_LONG(&_6$$4, 16);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "intval", &_8, 123, &max, &_6$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&max, &_7$$4);
	} else if (ZEPHIR_IS_LONG_IDENTICAL(&_5, 0)) {
		ZVAL_LONG(&_9$$5, 8);
		ZEPHIR_CALL_FUNCTION(&_10$$5, "intval", &_8, 123, &max, &_9$$5);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&max, &_10$$5);
	} else {
		_11$$6 = zephir_get_intval(&max);
		ZEPHIR_INIT_NVAR(&max);
		ZVAL_LONG(&max, _11$$6);
	}
	ZVAL_LONG(&_12, -1);
	ZEPHIR_INIT_VAR(&_13);
	zephir_substr(&_13, &iniMax, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	do {
		if (ZEPHIR_IS_STRING(&_13, "t")) {
			ZEPHIR_INIT_VAR(&_14$$7);
			ZVAL_LONG(&_14$$7, 1024);
			ZEPHIR_MUL_ASSIGN(&max, &_14$$7);
		}
		if (ZEPHIR_IS_STRING(&_13, "g")) {
			ZEPHIR_INIT_VAR(&_15$$8);
			ZVAL_LONG(&_15$$8, 1024);
			ZEPHIR_MUL_ASSIGN(&max, &_15$$8);
		}
		if (ZEPHIR_IS_STRING(&_13, "m")) {
			ZEPHIR_INIT_VAR(&_16$$9);
			ZVAL_LONG(&_16$$9, 1024);
			ZEPHIR_MUL_ASSIGN(&max, &_16$$9);
		}
		if (ZEPHIR_IS_STRING(&_13, "k")) {
			ZEPHIR_INIT_VAR(&_17$$10);
			ZVAL_LONG(&_17$$10, 1024);
			ZEPHIR_MUL_ASSIGN(&max, &_17$$10);
		}
	} while(0);

	RETURN_CCTOR(&max);

}

/**
 * 上传错误
 *
 * @return string
 */
PHP_METHOD(Leevel_Http_UploadedFile, getErrorMessage) {

	zval errorCode, maxFilesize, message, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errorCode);
	ZVAL_UNDEF(&maxFilesize);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&errorCode);
	zephir_read_property(&errorCode, this_ptr, SL("error"), PH_NOISY_CC);
	if (ZEPHIR_IS_LONG_IDENTICAL(&errorCode, 1)) {
		ZEPHIR_CALL_SELF(&_0, "getmaxfilesize", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&maxFilesize);
		ZVAL_DOUBLE(&maxFilesize, zephir_safe_div_zval_long(&_0, 1024 TSRMLS_CC));
	} else {
		ZEPHIR_INIT_NVAR(&maxFilesize);
		ZVAL_LONG(&maxFilesize, 0);
	}
	zephir_read_static_property_ce(&_1, leevel_http_uploadedfile_ce, SL("errors"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &errorCode)) {
		zephir_read_static_property_ce(&_2, leevel_http_uploadedfile_ce, SL("errors"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&message);
		zephir_array_fetch(&message, &_2, &errorCode, PH_NOISY, "leevel/http/uploadedfile.zep", 219 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&message);
		ZVAL_STRING(&message, "The file %s was not uploaded due to an unknown error.");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoriginalname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 1, &message, &_3, &maxFilesize);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&message, &_4);
	RETURN_CCTOR(&message);

}

void zephir_init_static_properties_Leevel_Http_UploadedFile(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0 TSRMLS_CC);
	add_index_stringl(&_0, 1, SL("The file %s exceeds your upload_max_filesize ini directive (limit is %d KiB)."));
	add_index_stringl(&_0, 2, SL("The file %s exceeds the upload limit defined in your form."));
	add_index_stringl(&_0, 3, SL("The file %s was only partially uploaded."));
	add_index_stringl(&_0, 4, SL("No file was uploaded."));
	add_index_stringl(&_0, 7, SL("The file %s could not be written on disk."));
	add_index_stringl(&_0, 6, SL("File could not be uploaded: missing temporary directory."));
	add_index_stringl(&_0, 8, SL("File upload was stopped by a PHP extension."));
	zend_update_static_property(leevel_http_uploadedfile_ce, ZEND_STRL("errors"), &_0);
	ZEPHIR_MM_RESTORE();

}

