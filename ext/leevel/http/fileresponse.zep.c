
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_directory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/file.h"


/**
 * FILE 响应请求
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.06
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Leevel_Http_FileResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, FileResponse, leevel, http_fileresponse, leevel_http_response_ce, leevel_http_fileresponse_method_entry, 0);

	/**
	 * 文件
	 * 
	 * @var \Leevel\Http\File
	 */
	zend_declare_property_null(leevel_http_fileresponse_ce, SL("file"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param \SplFileObject|\SplFileInfo|string $file
 * @param integer $status
 * @param array $headers
 * @param null|string $contentDisposition
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return void
 */
PHP_METHOD(Leevel_Http_FileResponse, __construct) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool autoEtag, autoLastModified;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, *status_param = NULL, *headers_param = NULL, *contentDisposition = NULL, contentDisposition_sub, *autoEtag_param = NULL, *autoLastModified_param = NULL, __$null, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&contentDisposition_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &file, &status_param, &headers_param, &contentDisposition, &autoEtag_param, &autoLastModified_param);

	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!contentDisposition) {
		contentDisposition = &contentDisposition_sub;
		contentDisposition = &__$null;
	}
	if (!autoEtag_param) {
		autoEtag = 0;
	} else {
		autoEtag = zephir_get_boolval(autoEtag_param);
	}
	if (!autoLastModified_param) {
		autoLastModified = 1;
	} else {
		autoLastModified = zephir_get_boolval(autoLastModified_param);
	}


	ZVAL_NULL(&_1);
	ZVAL_LONG(&_2, status);
	ZEPHIR_CALL_PARENT(NULL, leevel_http_fileresponse_ce, getThis(), "__construct", &_0, 0, &_1, &_2, &headers);
	zephir_check_call_status();
	if (autoEtag) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (autoLastModified) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setfile", NULL, 0, file, contentDisposition, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建一个文件响应
 * 
 * @param \SplFileObject|\SplFileInfo|string $file
 * @param integer $status
 * @param array $headers
 * @param null|string $contentDisposition
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return static
 */
PHP_METHOD(Leevel_Http_FileResponse, create) {

	zend_bool autoEtag, autoLastModified;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *file = NULL, file_sub, *status_param = NULL, *headers_param = NULL, *contentDisposition = NULL, contentDisposition_sub, *autoEtag_param = NULL, *autoLastModified_param = NULL, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&contentDisposition_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 6, &file, &status_param, &headers_param, &contentDisposition, &autoEtag_param, &autoLastModified_param);

	if (!file) {
		file = &file_sub;
		file = &__$null;
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!contentDisposition) {
		contentDisposition = &contentDisposition_sub;
		contentDisposition = &__$null;
	}
	if (!autoEtag_param) {
		autoEtag = 0;
	} else {
		autoEtag = zephir_get_boolval(autoEtag_param);
	}
	if (!autoLastModified_param) {
		autoLastModified = 1;
	} else {
		autoLastModified = zephir_get_boolval(autoLastModified_param);
	}


	object_init_ex(return_value, leevel_http_fileresponse_ce);
	ZVAL_LONG(&_0, status);
	if (autoEtag) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	if (autoLastModified) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 105, file, &_0, &headers, contentDisposition, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置文件
 *
 * @param \SplFileObject|\SplFileInfo|string $file 
 * @param string $contentDisposition
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return $this
 */
PHP_METHOD(Leevel_Http_FileResponse, setFile) {

	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool autoEtag, autoLastModified, _1, _2$$4, _3$$4;
	zval *file, file_sub, *contentDisposition = NULL, contentDisposition_sub, *autoEtag_param = NULL, *autoLastModified_param = NULL, __$null, files, _0, _8, _4$$5, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&contentDisposition_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &file, &contentDisposition, &autoEtag_param, &autoLastModified_param);

	if (!contentDisposition) {
		contentDisposition = &contentDisposition_sub;
		contentDisposition = &__$null;
	}
	if (!autoEtag_param) {
		autoEtag = 0;
	} else {
		autoEtag = zephir_get_boolval(autoEtag_param);
	}
	if (!autoLastModified_param) {
		autoLastModified = 1;
	} else {
		autoLastModified = zephir_get_boolval(autoLastModified_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	_1 = Z_TYPE_P(file) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(file, leevel_http_file_ce TSRMLS_CC);
	}
	if (!(_1)) {
		_2$$4 = Z_TYPE_P(file) == IS_OBJECT;
		if (_2$$4) {
			_3$$4 = zephir_instance_of_ev(file, spl_ce_SplFileInfo TSRMLS_CC);
			if (!(_3$$4)) {
				_3$$4 = zephir_instance_of_ev(file, spl_ce_SplFileObject TSRMLS_CC);
			}
			_2$$4 = _3$$4;
		}
		ZEPHIR_INIT_VAR(&files);
		if (_2$$4) {
			object_init_ex(&files, leevel_http_file_ce);
			ZEPHIR_CALL_METHOD(&_4$$5, file, "getpathname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &files, "__construct", &_5, 44, &_4$$5);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_FUNCTION(&_6$$6, "is_readable", NULL, 75, file);
			zephir_check_call_status();
			if (!zephir_is_true(&_6$$6)) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(leevel_http_fileexception_ce, "File must be readable.", "leevel/http/fileresponse.zep", 100);
				return;
			}
			object_init_ex(&files, leevel_http_file_ce);
			ZEPHIR_CALL_FUNCTION(&_7$$6, "strval", NULL, 11, file);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &files, "__construct", &_5, 44, &_7$$6);
			zephir_check_call_status();
		}
	} else {
		ZEPHIR_CPY_WRT(&files, file);
	}
	ZEPHIR_CALL_METHOD(&_8, &files, "isreadable", NULL, 106);
	zephir_check_call_status();
	if (!(zephir_is_true(&_8))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(leevel_http_fileexception_ce, "File must be readable.", "leevel/http/fileresponse.zep", 110);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("file"), &files);
	if (autoEtag) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setautoetag", NULL, 0);
		zephir_check_call_status();
	}
	if (autoLastModified) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setautolastmodified", NULL, 0);
		zephir_check_call_status();
	}
	if (zephir_is_true(contentDisposition)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontentdisposition", NULL, 0, contentDisposition);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 取回文件
 *
 * @return \Leevel\Http\File
 */
PHP_METHOD(Leevel_Http_FileResponse, getFile) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "file");

}

/**
 * 自动设置最后修改时间
 *
 * @return void
 */
PHP_METHOD(Leevel_Http_FileResponse, setAutoLastModified) {

	zend_class_entry *_2;
	zval _0, _1, _3, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	_2 = zephir_fetch_class_str_ex(SL("DateTime"), ZEND_FETCH_CLASS_AUTO);
	zephir_read_property(&_3, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getmtime", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "strval", NULL, 11, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "U");
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "createfromformat", NULL, 0, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setlastmodified", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 自动设置标记
 *
 * @return void
 */
PHP_METHOD(Leevel_Http_FileResponse, setAutoEtag) {

	zval __$true, etag, _0, _1, _2, _3, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&etag);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_read_property(&_1, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "getpathname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "sha256");
	ZEPHIR_CALL_FUNCTION(&_4, "hash_file", NULL, 107, &_3, &_2, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&etag, "base64_encode", NULL, 108, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setetag", NULL, 0, &etag);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Http_FileResponse, setContent) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content, content_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (Z_TYPE_P(content) != IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "The content cannot be set on a FileResponse instance.", "leevel/http/fileresponse.zep", 185);
		return;
	}
	RETURN_THIS();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Http_FileResponse, getContent) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * 设置文件下载模式
 *
 * @param string $disposition
 * @param string $filename
 * @return $this
 */
PHP_METHOD(Leevel_Http_FileResponse, setContentDisposition) {

	zval _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *disposition_param = NULL, *filename = NULL, filename_sub, _0, _3, _4, _5, _6, _7, _8, _9, _1$$4;
	zval disposition;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&disposition);
	ZVAL_UNDEF(&filename_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &disposition_param, &filename);

	zephir_get_strval(&disposition, disposition_param);
	if (!filename) {
		filename = &filename_sub;
		ZEPHIR_INIT_VAR(filename);
		ZVAL_STRING(filename, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(filename);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(filename, "")) {
		zephir_read_property(&_1$$4, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(filename, &_1$$4, "getfilename", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "attachment");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "inline");
	zephir_array_fast_append(&_2, &_3);
	if (!(zephir_fast_in_array(&disposition, &_2 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The disposition type is invalid.", "leevel/http/fileresponse.zep", 220);
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_INIT_VAR(&_5);
	zephir_basename(&_5, filename TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "\"");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "\\\"");
	zephir_fast_str_replace(&_3, &_6, &_7, &_5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "%s; filename=\"%s\"");
	ZEPHIR_CALL_FUNCTION(&_9, "sprintf", NULL, 1, &_8, &disposition, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "Content-Disposition");
	ZEPHIR_CALL_METHOD(NULL, &_4, "set", NULL, 0, &_8, &_9);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Http_FileResponse, sendContent) {

	zval out, file, _0, _1, _3, _4, _6, _7;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&out);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "issuccessful", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_RETURN_CALL_PARENT(leevel_http_fileresponse_ce, getThis(), "sendcontent", &_2, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "php://output");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "wb");
	ZEPHIR_CALL_FUNCTION(&out, "fopen", &_5, 76, &_3, &_4);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("file"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, &_6, "getpathname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "rb");
	ZEPHIR_CALL_FUNCTION(&file, "fopen", &_5, 76, &_7, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "stream_copy_to_stream", NULL, 109, &file, &out);
	zephir_check_call_status();
	zephir_fclose(&out TSRMLS_CC);
	zephir_fclose(&file TSRMLS_CC);
	RETURN_THIS();

}

