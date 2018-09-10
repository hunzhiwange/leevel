
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/array.h"


/**
 * twig 模板处理类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.15
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_Twig) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\View, Twig, leevel, view_twig, leevel_view_connect_ce, leevel_view_twig_method_entry, 0);

	/**
	 * 视图分析器.
	 *
	 * @var \Leevel\View\IParser
	 */
	zend_declare_property_null(leevel_view_twig_ce, SL("parser"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 解析 parse.
	 *
	 * @var callable
	 */
	zend_declare_property_null(leevel_view_twig_ce, SL("parseResolver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_twig_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_view_twig_ce->create_object = zephir_init_properties_Leevel_View_Twig;

	zend_class_implements(leevel_view_twig_ce TSRMLS_CC, 1, leevel_view_iconnect_ce);
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
PHP_METHOD(Leevel_View_Twig, display) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool display;
	zval vars;
	zval *file_param = NULL, *vars_param = NULL, *ext = NULL, ext_sub, *display_param = NULL, __$null, tmpFile, _1$$5;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmpFile);
	ZVAL_UNDEF(&_1$$5);
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
	if (display == 0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderfile", &_0, 0, &tmpFile);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&_1$$5, this_ptr, "renderfile", &_0, 0, &tmpFile);
		zephir_check_call_status();
		zend_print_zval(&_1$$5, 0);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 parse 解析回调.
 *
 * @param callable $parseResolver
 */
PHP_METHOD(Leevel_View_Twig, setParseResolver) {

	zval *parseResolver, parseResolver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parseResolver_sub);

	zephir_fetch_params(0, 1, 0, &parseResolver);



	zephir_update_property_zval(this_ptr, SL("parseResolver"), parseResolver);

}

/**
 * 解析 parse.
 *
 * @return \Twig_Environment
 */
PHP_METHOD(Leevel_View_Twig, resolverParser) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("parseResolver"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Twig theme not set parse resolver.", "leevel/view/twig.zep", 104);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("parseResolver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC(return_value, &_1);
	zephir_check_call_status();
	return;

}

/**
 * 获取分析器.
 *
 * @return \Leevel\View\IParser
 */
PHP_METHOD(Leevel_View_Twig, parser) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("parser"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "parser");
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolverparser", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("parser"), &_1);
	RETURN_MM_MEMBER(getThis(), "parser");

}

/**
 * 渲染模板
 *
 * @param string $file
 *
 * @return string
 */
PHP_METHOD(Leevel_View_Twig, renderFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, loader, template, _0, _1, _2, _3, _4, _5;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parser", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("parser"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&loader, &_0, "getloader", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "dirname", NULL, 47, &file);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &loader, "setpaths", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("parser"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setloader", NULL, 0, &loader);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("parser"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	zephir_basename(&_4, &file TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&template, &_3, "load", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("vars"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&template, "render", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_View_Twig(zend_class_entry *class_type TSRMLS_DC) {

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
			add_assoc_stringl_ex(&_3$$4, SL("suffix"), SL(".twig"));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

