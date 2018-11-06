
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * 文件缓存.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.02.15
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Cache_File) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Cache, File, leevel, cache_file, leevel_cache_connect_ce, leevel_cache_file_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_cache_file_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_cache_file_ce->create_object = zephir_init_properties_Leevel_Cache_File;
	/**
	 * 缓存文件头部.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_cache_file_ce, SL("HEADER"), "<?php die(%s); ?>");

	/**
	 * 缓存文件头部长度.
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_cache_file_ce, SL("HEADER_LENGTH"), 41);

	zend_class_implements(leevel_cache_file_ce TSRMLS_CC, 1, leevel_cache_iconnect_ce);
	return SUCCESS;

}

/**
 * 获取缓存.
 *
 * @param string $name
 * @param mixed  $defaults
 * @param array  $option
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Cache_File, get) {

	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *defaults = NULL, defaults_sub, *option_param = NULL, __$false, cachePath, fp, len, data, _0, _1, _2, _3, _4, _9, _7$$5, _10$$10;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&cachePath);
	ZVAL_UNDEF(&fp);
	ZVAL_UNDEF(&len);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name_param, &defaults, &option_param);

	zephir_get_strval(&name, name_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$false;
	}
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	ZEPHIR_CALL_METHOD(&cachePath, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 74);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 26, &cachePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "is_readable", NULL, 75, &cachePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Cache path is not readable.", "leevel/cache/file.zep", 81);
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "rb");
	ZEPHIR_CALL_FUNCTION(&fp, "fopen", NULL, 76, &cachePath, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "flock", &_5, 77, &fp, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&len, "filesize", NULL, 78, &cachePath);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 41);
	ZEPHIR_CALL_FUNCTION(NULL, "fread", &_6, 79, &fp, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, 41);
	ZEPHIR_SUB_ASSIGN(&len, &_3);
	do {
		ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "isexpired", &_8, 0, &name, &option);
		zephir_check_call_status();
		if (zephir_is_true(&_7$$5)) {
			ZEPHIR_INIT_NVAR(&data);
			ZVAL_BOOL(&data, 0);
			break;
		}
		if (ZEPHIR_GT_LONG(&len, 0)) {
			ZEPHIR_CALL_FUNCTION(&data, "fread", &_6, 79, &fp, &len);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&data);
			ZVAL_BOOL(&data, 0);
		}
	} while (0);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_CALL_FUNCTION(NULL, "flock", &_5, 77, &fp, &_4);
	zephir_check_call_status();
	zephir_fclose(&fp TSRMLS_CC);
	if (ZEPHIR_IS_FALSE_IDENTICAL(&data)) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_string(&_9, &option, SL("serialize"), PH_NOISY | PH_READONLY, "leevel/cache/file.zep", 114 TSRMLS_CC);
	if (zephir_is_true(&_9)) {
		ZEPHIR_CALL_FUNCTION(&_10$$10, "unserialize", NULL, 29, &data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&data, &_10$$10);
	}
	RETURN_CCTOR(&data);

}

/**
 * 设置缓存.
 *
 * @param string $name
 * @param mixed  $data
 * @param array  $option
 */
PHP_METHOD(Leevel_Cache_File, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *data = NULL, data_sub, *option_param = NULL, cachePath, _0, _1, _3, _4, _5, _6, _7, _2$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&cachePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &data, &option_param);

	zephir_get_strval(&name, name_param);
	ZEPHIR_SEPARATE_PARAM(data);
	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeoptions", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&option, &_0);
	zephir_array_fetch_string(&_1, &option, SL("serialize"), PH_NOISY | PH_READONLY, "leevel/cache/file.zep", 134 TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		ZEPHIR_CALL_FUNCTION(&_2$$3, "serialize", NULL, 24, data);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(data, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_4, "date", NULL, 80, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_SVS(&_5, "/* ", &_4, "  */");
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "<?php die(%s); ?>");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 1, &_3, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VV(&_7, &_6, data);
	ZEPHIR_CPY_WRT(data, &_7);
	ZEPHIR_CALL_METHOD(&cachePath, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writedata", NULL, 0, &cachePath, data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 清除缓存.
 *
 * @param string $name
 */
PHP_METHOD(Leevel_Cache_File, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, cachePath, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&cachePath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&cachePath, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "exist", NULL, 0, &name);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 81, &cachePath);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 关闭.
 */
PHP_METHOD(Leevel_Cache_File, close) {

	zval *this_ptr = getThis();



}

/**
 * 验证缓存是否过期
 *
 * @param string $name
 * @param array  $option
 *
 * @return bool
 */
PHP_METHOD(Leevel_Cache_File, isExpired) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *name_param = NULL, *option_param = NULL, filePath, _0, _1, _2, _3, _4, _5, _6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&filePath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &option_param);

	zephir_get_strval(&name, name_param);
	ZEPHIR_OBS_COPY_OR_DUP(&option, option_param);


	ZEPHIR_CALL_METHOD(&filePath, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	zephir_array_fetch_string(&_1, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cache/file.zep", 182 TSRMLS_CC);
	ZVAL_LONG(&_2, zephir_get_intval(&_1));
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "cachetime", NULL, 0, &name, &_2);
	zephir_check_call_status();
	zephir_array_update_string(&option, SL("expire"), &_0, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_3, &option, SL("expire"), PH_NOISY | PH_READONLY, "leevel/cache/file.zep", 184 TSRMLS_CC);
	if (ZEPHIR_LE_LONG(&_3, 0)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_filemtime(&_4, &filePath TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_5);
	zephir_array_fetch_string(&_5, &option, SL("expire"), PH_NOISY, "leevel/cache/file.zep", 188 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	zephir_time(&_6);
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_6, (zephir_get_numberval(&_4) + zephir_get_intval(&_5))));

}

/**
 * 获取缓存路径.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Leevel_Cache_File, getCachePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _1, _2, _3, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("path"), PH_NOISY | PH_READONLY, "leevel/cache/file.zep", 200 TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Cache path is not allowed empty.", "leevel/cache/file.zep", 201);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("path"), PH_NOISY | PH_READONLY, "leevel/cache/file.zep", 204 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getcachename", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_3, "/", &_4, ".php");
	RETURN_MM();

}

/**
 * 写入缓存数据.
 *
 * @param string $fileName
 * @param string $data
 */
PHP_METHOD(Leevel_Cache_File, writeData) {

	zend_bool _15, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_8 = NULL, *_12 = NULL;
	zval *fileName_param = NULL, *data_param = NULL, __$true, dirname, _1, _14, _16, _17, _3$$3, _4$$3, _6$$3, _7$$3, _13$$3, _9$$4, _10$$4, _11$$4, _18$$5, _19$$5, _20$$5;
	zval fileName, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fileName);
	ZVAL_UNDEF(&data);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&dirname);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &fileName_param, &data_param);

	zephir_get_strval(&fileName, fileName_param);
	zephir_get_strval(&data, data_param);


	ZEPHIR_CALL_FUNCTION(&dirname, "dirname", &_0, 47, &fileName);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", &_2, 45, &dirname);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_CALL_FUNCTION(&_3$$3, "dirname", &_0, 47, &dirname);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4$$3, "is_dir", &_2, 45, &_3$$3);
		zephir_check_call_status();
		_5$$3 = zephir_is_true(&_4$$3);
		if (_5$$3) {
			ZEPHIR_CALL_FUNCTION(&_6$$3, "dirname", &_0, 47, &dirname);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_7$$3, "is_writable", &_8, 46, &_6$$3);
			zephir_check_call_status();
			_5$$3 = !zephir_is_true(&_7$$3);
		}
		if (_5$$3) {
			ZEPHIR_INIT_VAR(&_9$$4);
			object_init_ex(&_9$$4, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_10$$4);
			ZVAL_STRING(&_10$$4, "Unable to create the %s directory.");
			ZEPHIR_CALL_FUNCTION(&_11$$4, "sprintf", &_12, 1, &_10$$4, &dirname);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", NULL, 21, &_11$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$4, "leevel/cache/file.zep", 223 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZVAL_LONG(&_13$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 48, &dirname, &_13$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_14, "is_writable", &_8, 46, &dirname);
	zephir_check_call_status();
	_15 = !zephir_is_true(&_14);
	if (!(_15)) {
		ZVAL_LONG(&_16, 2);
		ZEPHIR_CALL_FUNCTION(&_17, "file_put_contents", NULL, 82, &fileName, &data, &_16);
		zephir_check_call_status();
		_15 = !zephir_is_true(&_17);
	}
	if (_15) {
		ZEPHIR_INIT_VAR(&_18$$5);
		object_init_ex(&_18$$5, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_19$$5);
		ZVAL_STRING(&_19$$5, "Dir %s is not writeable.");
		ZEPHIR_CALL_FUNCTION(&_20$$5, "sprintf", &_12, 1, &_19$$5, &dirname);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_18$$5, "__construct", NULL, 21, &_20$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_18$$5, "leevel/cache/file.zep", 233 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_16, 0666);
	ZEPHIR_CALL_FUNCTION(NULL, "chmod", NULL, 51, &fileName, &_16);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 验证缓存是否存在.
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Leevel_Cache_File, exist) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcachepath", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 26, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取缓存名字
 * 去掉特殊缓存名字字符.
 *
 * @param string $name
 *
 * @return string
 */
PHP_METHOD(Leevel_Cache_File, getCacheName) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *name_param = NULL, _1, _2, _4;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 9, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "?");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "*");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ":");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\"");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "<");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ">");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\\");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "|");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_PARENT(&_2, leevel_cache_file_ce, getThis(), "getcachename", &_3, 0, &name);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_4);
	zephir_fast_str_replace(&_4, &_0, &_1, &_2 TSRMLS_CC);
	RETURN_CCTOR(&_4);

}

zend_object *zephir_init_properties_Leevel_Cache_File(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$true, _0, _2$$3;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_2$$3);
			array_init(&_2$$3);
			zephir_array_update_string(&_1$$3, SL("time_preset"), &_2$$3, PH_COPY | PH_SEPARATE);
			add_assoc_long_ex(&_1$$3, SL("expire"), 86400);
			add_assoc_stringl_ex(&_1$$3, SL("path"), SL(""));
			zephir_array_update_string(&_1$$3, SL("serialize"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

