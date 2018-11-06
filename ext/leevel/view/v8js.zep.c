
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/variables.h"


/**
 * v8 模板处理类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.10
 *
 * @version 1.0
 * @codeCoverageIgnore
 */
ZEPHIR_INIT_CLASS(Leevel_View_V8js) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\View, V8js, leevel, view_v8js, leevel_view_connect_ce, leevel_view_v8js_method_entry, 0);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_v8js_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * v8js.
	 *
	 * @var \V8Js
	 */
	zend_declare_property_null(leevel_view_v8js_ce, SL("v8js"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_view_v8js_ce->create_object = zephir_init_properties_Leevel_View_V8js;

	zend_class_implements(leevel_view_v8js_ce TSRMLS_CC, 1, leevel_view_iconnect_ce);
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param array $option
 *
 * @see http://php.net/manual/zh/book.v8js.php
 */
PHP_METHOD(Leevel_View_V8js, __construct) {

	zend_class_entry *_3 = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, item, method, _0, _1, _4, *_6, _7$$4;
	zval option, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "v8js");
	ZEPHIR_CALL_FUNCTION(&_1, "extension_loaded", NULL, 70, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Please install php v8js extension.", "leevel/view/v8js.zep", 73);
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, leevel_view_v8js_ce, getThis(), "__construct", &_2, 0, &option);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	if (!_3) {
	_3 = zephir_fetch_class_str_ex(SL("V8Js"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _3);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_STRING(&_4, "$");
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_4);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("v8js"), &_0);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 7, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "base");
	zephir_array_fast_append(&_5, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "dd");
	zephir_array_fast_append(&_5, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "dump");
	zephir_array_fast_append(&_5, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "echo");
	zephir_array_fast_append(&_5, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "html");
	zephir_array_fast_append(&_5, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "load");
	zephir_array_fast_append(&_5, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "module");
	zephir_array_fast_append(&_5, &_4);
	zephir_is_iterable(&_5, 0, "leevel/view/v8js.zep", 84);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5), _6)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _6);
		ZEPHIR_CALL_FUNCTION(&_7$$4, "ucwords", &_8, 23, &item);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&method);
		ZEPHIR_CONCAT_SV(&method, "init", &_7$$4);
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回 V8js.
 *
 * @return \V8js
 */
PHP_METHOD(Leevel_View_V8js, getV8js) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "v8js");

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
PHP_METHOD(Leevel_View_V8js, display) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool display;
	zval vars;
	zval *file_param = NULL, *vars_param = NULL, *ext = NULL, ext_sub, *display_param = NULL, __$null, key, value, source, tmpFile, _0, *_1;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&tmpFile);
	ZVAL_UNDEF(&_0);
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
	zephir_is_iterable(&_0, 0, "leevel/view/v8js.zep", 122);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setv8jsprop", &_4, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&source);
	zephir_file_get_contents(&source, &tmpFile TSRMLS_CC);
	if (display == 0) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "select", NULL, 0, &source);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &source);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 执行 js 并返回输入文本.
 *
 * @param string $js
 *
 * @return string
 */
PHP_METHOD(Leevel_View_V8js, select) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *js_param = NULL, _0;
	zval js;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&js);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(&js, js_param);


	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 62);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("v8js"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "executestring", NULL, 0, &js);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ob_get_clean", NULL, 164);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 执行 js.
 *
 * @param string $js
 *
 * @return mixed
 */
PHP_METHOD(Leevel_View_V8js, execute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *js_param = NULL, _0;
	zval js;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&js);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &js_param);

	zephir_get_strval(&js, js_param);


	zephir_read_property(&_0, this_ptr, SL("v8js"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "executestring", NULL, 0, &js);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * initDd.
 * 调试会导致 cli 中断.
 *
 * @codeCoverageIgnore
 */
PHP_METHOD(Leevel_View_V8js, initDd) {

	zval _2;
	zend_class_entry *_1;
	zval _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "initDdClosure");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "$dd");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setv8jsprop", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "this.dd = this.$dd = $.$dd;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 initDd 闭包
 * 
 * @param mixed $message
 */
PHP_METHOD(Leevel_View_V8js, initDdClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message);



	ZEPHIR_CALL_FUNCTION(NULL, "dd", NULL, 0, message);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * initDump.
 */
PHP_METHOD(Leevel_View_V8js, initDump) {

	zval _2;
	zend_class_entry *_1;
	zval _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "initDumpClosure");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "$dump");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setv8jsprop", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "this.dump = this.$dump = $.$dump;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 initDump 闭包
 * 
 * @param mixed $message
 */
PHP_METHOD(Leevel_View_V8js, initDumpClosure) {

	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);

	zephir_fetch_params(0, 1, 0, &message);



	zephir_var_dump(message TSRMLS_CC);

}

/**
 * initEcho.
 */
PHP_METHOD(Leevel_View_V8js, initEcho) {

	zval _2;
	zend_class_entry *_1;
	zval _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "initEchoClosure");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "$echo");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setv8jsprop", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "this.echo = this.$echo = $.$echo;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 initEcho 闭包
 * 
 * @param mixed $message
 */
PHP_METHOD(Leevel_View_V8js, initEchoClosure) {

	zval *message, message_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);

	zephir_fetch_params(0, 1, 0, &message);



	zend_print_zval(message, 0);

}

/**
 * initHtml.
 */
PHP_METHOD(Leevel_View_V8js, initHtml) {

	zval _2;
	zend_class_entry *_1;
	zval _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "initHtmlClosure");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "$html");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setv8jsprop", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "this.html = this.$html = $.$html;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 initHtml 闭包
 * 
 * @param string $package
 * @param string $package
 *
 * @return string
 */
PHP_METHOD(Leevel_View_V8js, initHtmlClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, *ext_param = NULL, file;
	zval path, ext;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&ext);
	ZVAL_UNDEF(&file);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &ext_param);

	zephir_get_strval(&path, path_param);
	if (!ext_param) {
		ZEPHIR_INIT_VAR(&ext);
		ZVAL_STRING(&ext, ".html");
	} else {
		zephir_get_strval(&ext, ext_param);
	}


	ZEPHIR_CALL_METHOD(&file, this_ptr, "parsedisplayfile", NULL, 0, &path, &ext);
	zephir_check_call_status();
	zephir_file_get_contents(return_value, &file TSRMLS_CC);
	RETURN_MM();

}

/**
 * initLoad.
 */
PHP_METHOD(Leevel_View_V8js, initLoad) {

	zval _2;
	zend_class_entry *_1;
	zval _0, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "initLoadClosure");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "fromcallable", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "$load");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setv8jsprop", NULL, 0, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "this.load = this.$load = $.$load;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 initLoad 闭包
 * 
 * @param string $package
 */
PHP_METHOD(Leevel_View_V8js, initLoadClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *package, package_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&package_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &package);

	ZEPHIR_SEPARATE_PARAM(package);


	zephir_concat_self_str(&package, SL("Package") TSRMLS_CC);
	if (!((zephir_method_exists(this_ptr, package TSRMLS_CC)  == SUCCESS))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Package is not preset, we just support vue and art.", "leevel/view/v8js.zep", 270);
		return;
	}
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, package, NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * initModule.
 */
PHP_METHOD(Leevel_View_V8js, initModule) {

	zval _3, _8;
	zend_class_entry *_2, *_7;
	zval _0, _1, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("v8js"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "moduleNormaliserClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "setmodulenormaliser", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("v8js"), PH_NOISY_CC | PH_READONLY);
	_7 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_8, this_ptr);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "moduleLoaderClosure");
	zephir_array_fast_append(&_8, &_4);
	ZEPHIR_CALL_CE_STATIC(&_6, _7, "fromcallable", NULL, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "setmoduleloader", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建模块格式化闭包
 * 
 * @param string $base
 * @param string $module
 * 
 * @return array
 */
PHP_METHOD(Leevel_View_V8js, moduleNormaliserClosure) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *base, base_sub, *module = NULL, module_sub, _0$$3, _1, _2, _4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&base_sub);
	ZVAL_UNDEF(&module_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &base, &module);

	ZEPHIR_SEPARATE_PARAM(module);



	/* try_start_1: */

		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "parsedisplayfile", NULL, 0, module);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CPY_WRT(module, &_0$$3);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_OBJ(&_1, EG(exception));
		Z_ADDREF_P(&_1);
		ZEPHIR_INIT_VAR(&_2);
		if (zephir_instance_of_ev(&_1, spl_ce_RuntimeException TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_2, &_1);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_VS(&_3$$4, module, "/index");
			ZEPHIR_CALL_METHOD(module, this_ptr, "parsedisplayfile", NULL, 0, &_3$$4);
			zephir_check_call_status();
		}
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "");
	zephir_array_fast_append(return_value, &_4);
	zephir_array_fast_append(return_value, module);
	RETURN_MM();

}

/**
 * 创建模块载入闭包
 * 
 * @param string $module
 * 
 * @return string
 */
PHP_METHOD(Leevel_View_V8js, moduleLoaderClosure) {

	zval *module_param = NULL;
	zval module;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_strval(&module, module_param);


	zephir_file_get_contents(return_value, &module TSRMLS_CC);
	RETURN_MM();

}

/**
 * initBase.
 */
PHP_METHOD(Leevel_View_V8js, initBase) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/*!\n * console.js v0.2.0 (https://github.com/yanhaijing/console.js)\n * Copyright 2013 yanhaijing. All Rights Reserved\n * Licensed under MIT (https://github.com/yanhaijing/console.js/blob/master/MIT-LICENSE.txt)\n */\n;(function(g) {\n    'use strict';\n    var _console = g.console || {};\n    var methods = ['assert', 'clear', 'count', 'debug', 'dir', 'dirxml', 'exception', 'error', 'group', 'groupCollapsed', 'groupEnd', 'info', 'log', 'profile', 'profileEnd', 'table', 'time', 'timeEnd', 'timeStamp', 'trace', 'warn'];\n\n    var console = {version: '0.2.0'};\n    var key;\n    for(var i = 0, len = methods.length; i < len; i++) {\n        key = methods[i];\n        console[key] = function (key) {\n            var method = key;\n            return function () {\n                if (method == 'log') {\n                    $.$dd(arguments[0]);\n                } else {\n                    print(arguments[0]);\n                    print('<br />');\n                }\n            };           \n        }(key);\n    }\n    \n    g.console = console;\n}(this));");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 v8js 属性.
 *
 * @param string $name
 * @param mixed $value
 */
PHP_METHOD(Leevel_View_V8js, setV8jsProp) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *value, value_sub, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("v8js"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__set", NULL, 0, &name, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化 vue.
 */
PHP_METHOD(Leevel_View_V8js, vuePackage) {

	zval vue, renderer, _0, _1, _2, _8, _12, _14, _4$$3, _5$$3, _6$$3, _9$$4, _10$$4, _11$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_13 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&vue);
	ZVAL_UNDEF(&renderer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&vue);
	zephir_array_fetch_string(&vue, &_0, SL("vue_path"), PH_NOISY, "leevel/view/v8js.zep", 343 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&renderer);
	zephir_array_fetch_string(&renderer, &_1, SL("vue_renderer"), PH_NOISY, "leevel/view/v8js.zep", 344 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", &_3, 26, &vue);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "Vue path %s is not exits, please use npm install.");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", &_7, 1, &_5$$3, &vue);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 3, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "leevel/view/v8js.zep", 349 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_FUNCTION(&_8, "is_file", &_3, 26, &renderer);
	zephir_check_call_status();
	if (!(zephir_is_true(&_8))) {
		ZEPHIR_INIT_VAR(&_9$$4);
		object_init_ex(&_9$$4, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, "Vue renderer %s is not exits, please use npm install.");
		ZEPHIR_CALL_FUNCTION(&_11$$4, "sprintf", &_7, 1, &_10$$4, &renderer);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$4, "__construct", NULL, 3, &_11$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$4, "leevel/view/v8js.zep", 355 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "delete this.window; this.global = { process: { env: { VUE_ENV: \"server\", NODE_ENV: \"production\" } } };");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_13, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_12);
	zephir_file_get_contents(&_12, &vue TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_13, 0, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_14);
	zephir_file_get_contents(&_14, &renderer TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_13, 0, &_14);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化 art.
 */
PHP_METHOD(Leevel_View_V8js, artPackage) {

	zval art, _0, _1, _5, _7, _2$$3, _3$$3, _4$$3;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&art);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&art);
	zephir_array_fetch_string(&art, &_0, SL("art_path"), PH_NOISY, "leevel/view/v8js.zep", 370 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 26, &art);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Art path %s is not exits, please use npm install.");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 1, &_3$$3, &art);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "leevel/view/v8js.zep", 375 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "this.window = null;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_6, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_5);
	zephir_file_get_contents(&_5, &art TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_6, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "delete this.window;");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_6, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_View_V8js(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_3$$4, 5, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("theme_path"), SL(""));
			add_assoc_stringl_ex(&_3$$4, SL("suffix"), SL(".js"));
			add_assoc_stringl_ex(&_3$$4, SL("vue_path"), SL("node_modules/vue/dist/vue.js"));
			add_assoc_stringl_ex(&_3$$4, SL("vue_renderer"), SL("node_modules/vue-server-renderer/basic.js"));
			add_assoc_stringl_ex(&_3$$4, SL("art_path"), SL("node_modules/art-template/lib/template-web.js"));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

