
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
#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * 国际化组件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.06
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_I18n_I18n) {

	ZEPHIR_REGISTER_CLASS(Leevel\\I18n, I18n, leevel, i18n_i18n, leevel_i18n_i18n_method_entry, 0);

	/**
	 * 当前语言上下文
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_i18n_i18n_ce, SL("i18n"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 语言数据
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_i18n_i18n_ce, SL("text"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_i18n_i18n_ce->create_object = zephir_init_properties_Leevel_I18n_I18n;

	zend_class_implements(leevel_i18n_i18n_ce TSRMLS_CC, 1, leevel_i18n_ii18n_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param string $i18n
 * @return void
 */
PHP_METHOD(Leevel_I18n_I18n, __construct) {

	zval *i18n_param = NULL, _0;
	zval i18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i18n_param);

	zephir_get_strval(&i18n, i18n_param);


	zephir_update_property_zval(this_ptr, SL("i18n"), &i18n);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_array(this_ptr, SL("text"), &i18n, &_0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取语言 text
 *
 * @return string
 */
PHP_METHOD(Leevel_I18n_I18n, getText) {

	zval arr, _0, _1, _2, _3, _11, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$5, _10$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arr);
	zephir_get_args(&arr);
	if (!(zephir_array_isset_long(&arr, 0))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_0, this_ptr, SL("text"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("i18n"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_READONLY, "leevel/i18n/i18n.zep", 75 TSRMLS_CC);
	zephir_array_fetch_long(&_3, &arr, 0, PH_READONLY, "leevel/i18n/i18n.zep", 75 TSRMLS_CC);
	if (zephir_array_isset(&_1, &_3)) {
		zephir_read_property(&_4$$4, this_ptr, SL("text"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_6$$4);
		zephir_read_property(&_6$$4, this_ptr, SL("i18n"), PH_NOISY_CC);
		zephir_array_fetch(&_5$$4, &_4$$4, &_6$$4, PH_NOISY | PH_READONLY, "leevel/i18n/i18n.zep", 76 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_8$$4);
		zephir_array_fetch_long(&_8$$4, &arr, 0, PH_NOISY, "leevel/i18n/i18n.zep", 76 TSRMLS_CC);
		zephir_array_fetch(&_7$$4, &_5$$4, &_8$$4, PH_NOISY | PH_READONLY, "leevel/i18n/i18n.zep", 76 TSRMLS_CC);
		zephir_array_update_long(&arr, 0, &_7$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	if (zephir_fast_count_int(&arr TSRMLS_CC) > 1) {
		ZEPHIR_INIT_VAR(&_9$$5);
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "sprintf");
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_9$$5, &_10$$5, &arr);
		zephir_check_call_status();
		zephir_array_update_long(&arr, 0, &_9$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	zephir_array_fetch_long(&_11, &arr, 0, PH_NOISY | PH_READONLY, "leevel/i18n/i18n.zep", 83 TSRMLS_CC);
	RETURN_CTOR(&_11);

}

/**
 * 获取语言 text
 *
 * @return string
 */
PHP_METHOD(Leevel_I18n_I18n, __) {

	zval _0;
	zval arr, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arr);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&arr);
	zephir_get_args(&arr);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "getText");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arr);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 添加语言包
 *
 * @param string $i18n 语言名字
 * @param array $data 语言包数据
 * @return void
 */
PHP_METHOD(Leevel_I18n_I18n, addText) {

	zval data;
	zval *i18n_param = NULL, *data_param = NULL, _0, _1$$3, _2$$3, _3$$3;
	zval i18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &i18n_param, &data_param);

	zephir_get_strval(&i18n, i18n_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	zephir_read_property(&_0, this_ptr, SL("text"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_0, &i18n TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("text"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &i18n, PH_NOISY | PH_READONLY, "leevel/i18n/i18n.zep", 108 TSRMLS_CC);
		zephir_fast_array_merge(&_1$$3, &_3$$3, &data TSRMLS_CC);
		zephir_update_property_array(this_ptr, SL("text"), &i18n, &_1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("text"), &i18n, &data TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置当前语言包上下文环境
 *
 * @param string $i18n
 * @return void
 */
PHP_METHOD(Leevel_I18n_I18n, setI18n) {

	zval *i18n_param = NULL;
	zval i18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i18n_param);

	zephir_get_strval(&i18n, i18n_param);


	zephir_update_property_zval(this_ptr, SL("i18n"), &i18n);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取当前语言包
 *
 * @return string
 */
PHP_METHOD(Leevel_I18n_I18n, getI18n) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "i18n");

}

/**
 * 返回所有语言包
 *
 * @return array
 */
PHP_METHOD(Leevel_I18n_I18n, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "text");

}

zend_object *zephir_init_properties_Leevel_I18n_I18n(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("text"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("text"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

