
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
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * 模板处理抽象类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.02
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_Connect) {

	ZEPHIR_REGISTER_CLASS(Leevel\\View, Connect, leevel, view_connect, leevel_view_connect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 变量值
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_connect_ce, SL("vars"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_connect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_view_connect_ce->create_object = zephir_init_properties_Leevel_View_Connect;
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array option
 * @return void
 */
PHP_METHOD(Leevel_View_Connect, __construct) {

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
 * 设置配置
 * 
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, setOption) {

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
 * 设置模板变量
 *
 * @param mixed $name
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_View_Connect, setVar) {

	zval *name, name_sub, *value = NULL, value_sub, __$null, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(name) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_read_property(&_1$$3, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(&_0$$3, &_1$$3, name TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("vars"), &_0$$3);
	} else {
		zephir_update_property_array(this_ptr, SL("vars"), name, value TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取变量值
 *
 * @param string|null $name
 * @return mixed
 */
PHP_METHOD(Leevel_View_Connect, getVar) {

	zval *name = NULL, name_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	if (Z_TYPE_P(name) == IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "vars");
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_property(&_2, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, name, PH_NOISY, "leevel/view/connect.zep", 98 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 删除变量值
 *
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, deleteVar) {

	zend_class_entry *_1$$3 = NULL;
	zval item, name, args, _3, *_4, _0$$3, _2$$3, _5$$4, _6$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (!_1$$3) {
		_1$$3 = zephir_fetch_class_str_ex(SL("Leevel\\View\\BadMethodCallException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$3, _1$$3);
		if (zephir_has_constructor(&_0$$3 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Wrong number of parameters");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_2$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$3, "leevel/view/connect.zep", 113 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_array_fetch_long(&_3, &args, 0, PH_NOISY, "leevel/view/connect.zep", 116 TSRMLS_CC);
	if (Z_TYPE_P(&_3) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_long(&name, &args, 0, PH_NOISY, "leevel/view/connect.zep", 116 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&name, &args);
	}
	zephir_is_iterable(&name, 0, "leevel/view/connect.zep", 124);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&name), _4)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		zephir_read_property(&_5$$4, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_5$$4, &item)) {
			zephir_read_property(&_6$$5, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_6$$5, &item, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @param string|null $name
 * @return $this
 */
PHP_METHOD(Leevel_View_Connect, clearVar) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("vars"), &_0);
	RETURN_THIS();

}

/**
 * 分析展示的视图文件
 *
 * @param string $file 视图文件地址
 * @param string $ext 后缀
 * @return string|void
 */
PHP_METHOD(Leevel_View_Connect, parseDisplayFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *file_param = NULL, *ext_param = NULL, _0, _3, _2$$3, _4$$4, _5$$4, _6$$4;
	zval file, ext;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &file_param, &ext_param);

	zephir_get_strval(&file, file_param);
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, "");
	} else {
		zephir_get_strval(&ext, ext_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", &_1, 26, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "parsefile", NULL, 0, &file, &ext);
		zephir_check_call_status();
		zephir_get_strval(&file, &_2$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_3, "is_file", &_1, 26, &file);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "Template file %s does not exist.");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "sprintf", NULL, 1, &_5$$4, &file);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "leevel/view/connect.zep", 156 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&file);

}

/**
 * 分析模板真实路径            
 *
 * @param string $tpl 文件地址
 * @param string $ext 扩展名
 * @return string
 */
PHP_METHOD(Leevel_View_Connect, parseFile) {

	zend_bool _5, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tpl_param = NULL, *ext_param = NULL, tplTmp, _0, _1, _2, _3, _4, _6, _7, _9, _10, _11, _12, _13, _14, _15;
	zval tpl, ext;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tpl);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&tplTmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &tpl_param, &ext_param);

	zephir_get_strval(&tpl, tpl_param);
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, "");
	} else {
		zephir_get_strval(&ext, ext_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "->");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	zephir_fast_str_replace(&_0, &_1, &_2, &tpl TSRMLS_CC);
	ZEPHIR_INIT_VAR(&tplTmp);
	zephir_fast_trim(&tplTmp, &_0, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZVAL_LONG(&_3, 4);
	ZEPHIR_CALL_FUNCTION(&_4, "pathinfo", NULL, 27, &tplTmp, &_3);
	zephir_check_call_status();
	_5 = zephir_is_true(&_4);
	if (!(_5)) {
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "$");
		ZEPHIR_INIT_VAR(&_7);
		zephir_fast_strpos(&_7, &tplTmp, &_6, 0 );
		_5 = ZEPHIR_IS_LONG_IDENTICAL(&_7, 0);
	}
	_8 = _5;
	if (!(_8)) {
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_STRING(&_9, "(");
		ZEPHIR_INIT_VAR(&_10);
		zephir_fast_strpos(&_10, &tplTmp, &_9, 0 );
		_8 = !ZEPHIR_IS_FALSE_IDENTICAL(&_10);
	}
	if (_8) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "formatfile", NULL, 0, &tplTmp);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_11, &_3, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 182 TSRMLS_CC);
	if (!(zephir_is_true(&_11))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme path must be set.", "leevel/view/connect.zep", 183);
		return;
	}
	zephir_read_property(&_12, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_13, &_12, SL("theme_path"), PH_NOISY | PH_READONLY, "leevel/view/connect.zep", 186 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_14);
	if (!(ZEPHIR_IS_EMPTY(&ext))) {
		ZEPHIR_CPY_WRT(&_14, &ext);
	} else {
		zephir_read_property(&_15, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_14);
		zephir_array_fetch_string(&_14, &_15, SL("suffix"), PH_NOISY, "leevel/view/connect.zep", 187 TSRMLS_CC);
	}
	ZEPHIR_CONCAT_VSVV(return_value, &_13, "/", &tplTmp, &_14);
	RETURN_MM();

}

/**
 * 格式化文件名
 *
 * @param string $content
 * @return string
 */
PHP_METHOD(Leevel_View_Connect, formatFile) {

	zval _0, _2;
	zval *content_param = NULL, _1;
	zval content;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &content_param);

	zephir_get_strval(&content, content_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ":");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "+");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "->");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "::");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_str_replace(&_1, &_0, &_2, &content TSRMLS_CC);
	RETURN_CCTOR(&_1);

}

zend_object *zephir_init_properties_Leevel_View_Connect(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("vars"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

