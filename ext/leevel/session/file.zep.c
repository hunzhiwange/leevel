
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
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * session.file.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.08.16
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_File) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Session, File, leevel, session_file, leevel_session_connect_ce, leevel_session_file_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_session_file_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_session_file_ce->create_object = zephir_init_properties_Leevel_Session_File;
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 */
PHP_METHOD(Leevel_Session_File, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *option_param = NULL, _0, _1, _3;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

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
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "createcache", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, leevel_session_file_ce, getThis(), "__construct", &_2, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 文件缓存.
 *
 * @return \Leevel\Cache\Cache
 */
PHP_METHOD(Leevel_Session_File, createCache) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, leevel_cache_cache_ce);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, leevel_cache_file_ce);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 87, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 86, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Session_File(zend_class_entry *class_type TSRMLS_DC) {

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

