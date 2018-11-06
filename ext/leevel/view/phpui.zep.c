
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * phpui 模板处理类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.11.21
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_Phpui) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\View, Phpui, leevel, view_phpui, leevel_view_connect_ce, leevel_view_phpui_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_phpui_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_view_phpui_ce->create_object = zephir_init_properties_Leevel_View_Phpui;

	zend_class_implements(leevel_view_phpui_ce TSRMLS_CC, 1, leevel_view_iconnect_ce);
	return SUCCESS;

}

/**
 * 加载视图文件.
 *
 * @param string $file    视图文件地址
 * @param array  $vars
 * @param string $ext     后缀
 * @param bool   $display 是否显示
 *
 * @return void|string
 */
PHP_METHOD(Leevel_View_Phpui, display) {

	zend_string *_4$$4;
	zend_ulong _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool display;
	zval vars;
	zval *file_param = NULL, *vars_param = NULL, *ext = NULL, ext_sub, *display_param = NULL, __$null, result, key, value, tmpFile, _0, _1$$4, *_2$$4, _5$$5;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&tmpFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&vars);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &file_param, &vars_param, &ext, &display_param);

	zephir_get_strval(&file, file_param);
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&vars, vars_param);
	}
	if (!ext) {
		ext = &ext_sub;
		ext = &__$null;
	}
	if (!display_param) {
		display = 1;
	} else {
		display = zephir_get_boolval(display_param);
	}


	ZEPHIR_CALL_METHOD(&tmpFile, this_ptr, "parsedisplayfile", NULL, 0, &file, ext);
	zephir_check_call_status();
	if (1 == 1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvar", NULL, 0, &vars);
		zephir_check_call_status();
	}
	zephir_read_property(&_0, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		zephir_read_property(&_1$$4, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$4, 0, "leevel/view/phpui.zep", 66);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1$$4), _3$$4, _4$$4, _2$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _4$$4);
			} else {
				ZVAL_LONG(&key, _3$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2$$4);
			ZEPHIR_CPY_WRT(&_5$$5, &value);
			if (zephir_set_symbol(&key, &_5$$5 TSRMLS_CC) == FAILURE) {
				return;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	}
	if (display == 0) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 62);
		zephir_check_call_status();
		if (zephir_require_zval(&tmpFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CALL_FUNCTION(&result, "ob_get_contents", NULL, 157);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 158);
		zephir_check_call_status();
		RETURN_CCTOR(&result);
	} else {
		if (zephir_require_zval(&tmpFile TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_View_Phpui(zend_class_entry *class_type TSRMLS_DC) {

		zval _3$$4;
	zval _0, _2, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("vars"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 2, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("theme_path"), SL(""));
			add_assoc_stringl_ex(&_3$$4, SL("suffix"), SL(".php"));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

