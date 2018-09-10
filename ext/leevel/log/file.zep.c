
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/math.h"
#include "kernel/concat.h"
#include "kernel/time.h"
#include "kernel/file.h"
#include "kernel/string.h"


/**
 * log.file.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.05
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_File) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Log, File, leevel, log_file, leevel_log_file_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_log_file_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_log_file_ce->create_object = zephir_init_properties_Leevel_Log_File;

	zend_class_implements(leevel_log_file_ce TSRMLS_CC, 1, leevel_log_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 */
PHP_METHOD(Leevel_Log_File, __construct) {

	zval *option_param = NULL, _0, _1;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置配置.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return $this
 */
PHP_METHOD(Leevel_Log_File, setOption) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 日志写入接口.
 *
 * @param array $datas
 */
PHP_METHOD(Leevel_Log_File, flush) {

	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *datas_param = NULL, level, filepath, value, _0, *_1, _2$$3, _4$$3, _5$$3;
	zval datas, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&datas);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &datas_param);

	zephir_get_arrval(&datas, datas_param);


	zephir_array_fetch_long(&_0, &datas, 0, PH_NOISY | PH_READONLY, "leevel/log/file.zep", 78 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&level);
	zephir_array_fetch_long(&level, &_0, 0, PH_NOISY, "leevel/log/file.zep", 78 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "normalizepath", NULL, 0, &level);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checksize", NULL, 0, &filepath);
	zephir_check_call_status();
	zephir_is_iterable(&datas, 0, "leevel/log/file.zep", 86);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&datas), _1)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_create_array(&_3$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$3, this_ptr);
		ZEPHIR_INIT_NVAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "formatMessage");
		zephir_array_fast_append(&_3$$3, &_4$$3);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_2$$3, &_3$$3, &value);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_6, 124, &_2$$3, &_5$$3, &filepath);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_MM_RESTORE();

}

/**
 * 验证日志文件大小.
 *
 * @param string $filePath
 */
PHP_METHOD(Leevel_Log_File, checkSize) {

	zend_bool _21, _7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL, *_4 = NULL, *_10 = NULL, *_14 = NULL;
	zval *filePath_param = NULL, __$true, dirname, _1, _20, _22, _23, _24, _3$$3, _16$$3, _5$$4, _6$$4, _8$$4, _9$$4, _15$$4, _11$$5, _12$$5, _13$$5, _17$$6, _18$$6, _19$$6, _25$$7, _26$$7, _27$$7, _28$$7, _29$$7;
	zval filePath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&dirname);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath_param);

	zephir_get_strval(&filePath, filePath_param);


	ZEPHIR_CALL_FUNCTION(&dirname, "dirname", &_0, 47, &filePath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, 26, &filePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_CALL_FUNCTION(&_3$$3, "is_dir", &_4, 45, &dirname);
		zephir_check_call_status();
		if (!(zephir_is_true(&_3$$3))) {
			ZEPHIR_CALL_FUNCTION(&_5$$4, "dirname", &_0, 47, &dirname);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_6$$4, "is_dir", &_4, 45, &_5$$4);
			zephir_check_call_status();
			_7$$4 = zephir_is_true(&_6$$4);
			if (_7$$4) {
				ZEPHIR_CALL_FUNCTION(&_8$$4, "dirname", &_0, 47, &dirname);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_9$$4, "is_writable", &_10, 46, &_8$$4);
				zephir_check_call_status();
				_7$$4 = !zephir_is_true(&_9$$4);
			}
			if (_7$$4) {
				ZEPHIR_INIT_VAR(&_11$$5);
				object_init_ex(&_11$$5, spl_ce_InvalidArgumentException);
				ZEPHIR_INIT_VAR(&_12$$5);
				ZVAL_STRING(&_12$$5, "Unable to create the %s directory.");
				ZEPHIR_CALL_FUNCTION(&_13$$5, "sprintf", &_14, 1, &_12$$5, &dirname);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", NULL, 21, &_13$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$5, "leevel/log/file.zep", 104 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZVAL_LONG(&_15$$4, 0777);
			ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 48, &dirname, &_15$$4, &__$true);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_FUNCTION(&_16$$3, "is_writable", &_10, 46, &dirname);
		zephir_check_call_status();
		if (!(zephir_is_true(&_16$$3))) {
			ZEPHIR_INIT_VAR(&_17$$6);
			object_init_ex(&_17$$6, spl_ce_InvalidArgumentException);
			ZEPHIR_INIT_VAR(&_18$$6);
			ZVAL_STRING(&_18$$6, "Dir %s is not writeable.");
			ZEPHIR_CALL_FUNCTION(&_19$$6, "sprintf", &_14, 1, &_18$$6, &dirname);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", NULL, 21, &_19$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_17$$6, "leevel/log/file.zep", 113 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_FUNCTION(NULL, "clearstatcache", NULL, 74);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_20, "is_file", &_2, 26, &filePath);
	zephir_check_call_status();
	_21 = zephir_is_true(&_20);
	if (_21) {
		zephir_read_property(&_22, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_23, &_22, SL("size"), PH_NOISY | PH_READONLY, "leevel/log/file.zep", 121 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_24, "filesize", NULL, 78, &filePath);
		zephir_check_call_status();
		_21 = ZEPHIR_GE_LONG(&_24, zephir_floor(&_23 TSRMLS_CC));
	}
	if (_21) {
		ZEPHIR_INIT_VAR(&_25$$7);
		ZVAL_STRING(&_25$$7, ".log");
		ZEPHIR_CALL_FUNCTION(&_26$$7, "basename", NULL, 125, &filePath, &_25$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_25$$7);
		zephir_time(&_25$$7);
		ZEPHIR_INIT_VAR(&_27$$7);
		zephir_filemtime(&_27$$7, &filePath TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_28$$7);
		zephir_sub_function(&_28$$7, &_25$$7, &_27$$7);
		ZEPHIR_INIT_VAR(&_29$$7);
		ZEPHIR_CONCAT_VSVSVS(&_29$$7, &dirname, "/", &_26$$7, "_", &_28$$7, ".log");
		ZEPHIR_CALL_FUNCTION(NULL, "rename", NULL, 126, &filePath, &_29$$7);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化日志路径.
 *
 * @param string $level
 *
 * @return string
 */
PHP_METHOD(Leevel_Log_File, normalizePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *level_param = NULL, _0, _1, _2, _3, _4, _5, _6, _8, _9, _10;
	zval level, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("path"), PH_NOISY | PH_READONLY, "leevel/log/file.zep", 137 TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Path for log has not set.", "leevel/log/file.zep", 140);
		return;
	}
	zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &_2, SL("path"), PH_NOISY | PH_READONLY, "leevel/log/file.zep", 143 TSRMLS_CC);
	zephir_read_property(&_4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_5, &_4, SL("channel"), PH_NOISY | PH_READONLY, "leevel/log/file.zep", 143 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	if (!(Z_TYPE_P(&level) == IS_UNDEF) && Z_STRLEN_P(&level)) {
		ZEPHIR_INIT_VAR(&_7);
		ZEPHIR_CONCAT_VS(&_7, &level, "/");
		ZEPHIR_CPY_WRT(&_6, &_7);
	} else {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "");
	}
	zephir_read_property(&_8, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_9, &_8, SL("name"), PH_NOISY | PH_READONLY, "leevel/log/file.zep", 144 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_10, "date", NULL, 80, &_9);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVSVVS(return_value, &_3, "/", &_5, ".", &_6, &_10, ".log");
	RETURN_MM();

}

/**
 * 格式化日志信息.
 *
 * @param string $level
 * @param string $message
 * @param array  $contexts
 *
 * @return string
 */
PHP_METHOD(Leevel_Log_File, formatMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval contexts;
	zval *level_param = NULL, *message_param = NULL, *contexts_param = NULL, _0, _1, _2, _3, _4;
	zval level, message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&contexts);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &contexts_param);

	zephir_get_strval(&level, level_param);
	zephir_get_strval(&message, message_param);
	if (!contexts_param) {
		ZEPHIR_INIT_VAR(&contexts);
		array_init(&contexts);
	} else {
		zephir_get_arrval(&contexts, contexts_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "[%s] %s %s: %s", &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_3, "date", NULL, 80, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_LONG(&_4, 256);
	zephir_json_encode(&_2, &contexts, zephir_get_intval(&_4) );
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 1, &_1, &_3, &message, &level, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Log_File(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("channel"), SL("development"));
			add_assoc_stringl_ex(&_1$$3, SL("name"), SL("Y-m-d H"));
			add_assoc_long_ex(&_1$$3, SL("size"), 2097152);
			add_assoc_stringl_ex(&_1$$3, SL("path"), SL(""));
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

