
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/operators.h"


/**
 * view 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.12
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\View, Manager, leevel, view_manager, leevel_manager_manager_ce, leevel_view_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Leevel_View_Manager, normalizeOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("view");

}

/**
 * 创建连接对象
 *
 * @param object $connect
 * @return object
 */
PHP_METHOD(Leevel_View_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect, connect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect);



	object_init_ex(return_value, leevel_view_view_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 159, connect);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 html 模板驱动
 *
 * @param array $options
 * @return \Leevel\View\Html
 */
PHP_METHOD(Leevel_View_Manager, makeConnectHtml) {

	zend_class_entry *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, parser, html, _0, _1, _2, _5;
	zval options, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&parser);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "html");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	_3 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_4, this_ptr);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "makeParserClosure");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_CALL_CE_STATIC(&parser, _3, "fromcallable", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&html);
	object_init_ex(&html, leevel_view_html_ce);
	ZEPHIR_CALL_METHOD(NULL, &html, "__construct", NULL, 160, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &html, "setparseresolver", NULL, 161, &parser);
	zephir_check_call_status();
	RETURN_CCTOR(&html);

}

/**
 * 创建 twig 模板驱动
 *
 * @param array $options
 * @return \Leevel\View\Twig
 */
PHP_METHOD(Leevel_View_Manager, makeConnectTwig) {

	zend_class_entry *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, parser, twig, _0, _1, _2, _5;
	zval options, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&parser);
	ZVAL_UNDEF(&twig);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "twig");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	_3 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_4, this_ptr);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "makeTwigParserClosure");
	zephir_array_fast_append(&_4, &_5);
	ZEPHIR_CALL_CE_STATIC(&parser, _3, "fromcallable", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&twig);
	object_init_ex(&twig, leevel_view_twig_ce);
	ZEPHIR_CALL_METHOD(NULL, &twig, "__construct", NULL, 160, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &twig, "setparseresolver", NULL, 162, &parser);
	zephir_check_call_status();
	RETURN_CCTOR(&twig);

}

/**
 * 创建 phpui 模板驱动
 *
 * @param array $options
 * @return \Leevel\View\Phpui
 */
PHP_METHOD(Leevel_View_Manager, makeConnectPhpui) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "phpui");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	object_init_ex(return_value, leevel_view_phpui_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 160, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 v8js 模板驱动
 *
 * @param array $options
 * @return \Leevel\View\V8js
 */
PHP_METHOD(Leevel_View_Manager, makeConnectV8js) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1, _2;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "v8js");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&options, &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewoptioncommon", NULL, 0);
	zephir_check_call_status();
	zephir_fast_array_merge(&_1, &options, &_2 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&options, &_1);
	object_init_ex(return_value, leevel_view_v8js_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 163, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 视图公共配置
 *
 * @return array
 */
PHP_METHOD(Leevel_View_Manager, viewOptionCommon) {

	zval _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "themespath", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("theme_path"), &_1, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_2, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "theme");
	ZEPHIR_CALL_METHOD(&_1, &_2, "runtimepath", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("cache_path"), &_1, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * 创建分析器回调
 *
 * @since 2018.01.12
 * @return void
 */
PHP_METHOD(Leevel_View_Manager, makeParserClosure) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view.parser");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 twig 分析器回调
 *
 * @since 2018.01.15
 * @return void
 */
PHP_METHOD(Leevel_View_Manager, makeTwigParserClosure) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view.twig.parser");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

