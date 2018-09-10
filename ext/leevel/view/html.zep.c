
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
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


/**
 * html 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2016.11.18
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_Html) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\View, Html, leevel, view_html, leevel_view_connect_ce, leevel_view_html_method_entry, 0);

	/**
	 * 视图分析器
	 *
	 * @var \Leevel\View\IParserr
	 */
	zend_declare_property_null(leevel_view_html_ce, SL("parser"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 解析 parser
	 *
	 * @var callable
	 */
	zend_declare_property_null(leevel_view_html_ce, SL("parserResolver"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_view_html_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_view_html_ce->create_object = zephir_init_properties_Leevel_View_Html;

	zend_class_implements(leevel_view_html_ce TSRMLS_CC, 1, leevel_view_iconnect_ce);
	return SUCCESS;

}

/**
 * 加载视图文件
 *
 * @param string $file 视图文件地址
 * @param array $vars
 * @param string $ext 后缀
 * @param boolean $display 是否显示
 * @return void|string
 */
PHP_METHOD(Leevel_View_Html, display) {

	zend_string *_4$$4;
	zend_ulong _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool display;
	zval vars;
	zval *file_param = NULL, *vars_param = NULL, *ext = NULL, ext_sub, *display_param = NULL, __$null, cachepath, result, key, value, tmpFile, _0, _6, _1$$4, *_2$$4, _5$$5, _7$$6;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&cachepath);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&tmpFile);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
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
		zephir_is_iterable(&_1$$4, 0, "leevel/view/html.zep", 83);
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
	ZEPHIR_CALL_METHOD(&cachepath, this_ptr, "getcachepath", NULL, 0, &tmpFile);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "iscacheexpired", NULL, 0, &tmpFile, &cachepath);
	zephir_check_call_status();
	if (zephir_is_true(&_6)) {
		ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "parser", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_7$$6, "docompile", NULL, 0, &tmpFile, &cachepath);
		zephir_check_call_status();
	}
	if (display == 0) {
		ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 62);
		zephir_check_call_status();
		if (zephir_require_zval(&cachepath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		ZEPHIR_CALL_FUNCTION(&result, "ob_get_contents", NULL, 157);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 158);
		zephir_check_call_status();
		RETURN_CCTOR(&result);
	} else {
		if (zephir_require_zval(&cachepath TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置 parser 解析回调
 *
 * @param callable $parserResolver
 * @return void
 */
PHP_METHOD(Leevel_View_Html, setParseResolver) {

	zval *parserResolver, parserResolver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parserResolver_sub);

	zephir_fetch_params(0, 1, 0, &parserResolver);



	zephir_update_property_zval(this_ptr, SL("parserResolver"), parserResolver);

}

/**
 * 获取编译路径
 *
 * @param string $file
 * @return string
 */
PHP_METHOD(Leevel_View_Html, getCachePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("cache_path"), PH_NOISY | PH_READONLY, "leevel/view/html.zep", 123 TSRMLS_CC);
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Theme cache path must be set.", "leevel/view/html.zep", 124);
		return;
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "\\");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/");
	zephir_fast_str_replace(&_2, &_3, &_4, &file TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "//");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "/");
	ZEPHIR_INIT_NVAR(&file);
	zephir_fast_str_replace(&file, &_5, &_6, &_2 TSRMLS_CC);
	ZVAL_LONG(&_7, 4);
	ZEPHIR_CALL_FUNCTION(&_8, "pathinfo", NULL, 27, &file, &_7);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SV(&_9, ".", &_8);
	ZEPHIR_CALL_FUNCTION(&_10, "basename", NULL, 125, &file, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_md5(&_11, &file);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_VSVS(&_12, &_10, ".", &_11, ".php");
	zephir_get_strval(&file, &_12);
	zephir_read_property(&_7, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_13, &_7, SL("cache_path"), PH_NOISY | PH_READONLY, "leevel/view/html.zep", 131 TSRMLS_CC);
	ZEPHIR_CONCAT_VSV(return_value, &_13, "/", &file);
	RETURN_MM();

}

/**
 * 解析 parser
 *
 * @return \Leevel\View\IParserr
 */
PHP_METHOD(Leevel_View_Html, resolverParser) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("parserResolver"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Html theme not set parse resolver.", "leevel/view/html.zep", 142);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("parserResolver"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC(return_value, &_1);
	zephir_check_call_status();
	return;

}

/**
 * 获取分析器
 *
 * @return \Leevel\View\IParserr
 */
PHP_METHOD(Leevel_View_Html, parser) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("parser"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		RETURN_MM_MEMBER(getThis(), "parser");
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "resolverparser", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("parser"), &_1);
	RETURN_MM_MEMBER(getThis(), "parser");

}

/**
 * 判断缓存是否过期
 *
 * @param string $file
 * @param string $cachepath
 * @return boolean
 */
PHP_METHOD(Leevel_View_Html, isCacheExpired) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *file_param = NULL, *cachepath_param = NULL, _0, _1, _2;
	zval file, cachepath;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&cachepath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &file_param, &cachepath_param);

	zephir_get_strval(&file, file_param);
	zephir_get_strval(&cachepath, cachepath_param);


	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 26, &cachepath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_filemtime(&_1, &file TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_filemtime(&_2, &cachepath TSRMLS_CC);
	if (ZEPHIR_GE(&_1, &_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

zend_object *zephir_init_properties_Leevel_View_Html(zend_class_entry *class_type TSRMLS_DC) {

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
			zephir_create_array(&_3$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("theme_path"), SL(""));
			add_assoc_stringl_ex(&_3$$4, SL("suffix"), SL(".html"));
			add_assoc_stringl_ex(&_3$$4, SL("cache_path"), SL(""));
			zephir_update_property_zval(this_ptr, SL("option"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

