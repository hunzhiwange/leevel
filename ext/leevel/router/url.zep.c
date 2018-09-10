
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * url 生成
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.01.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_Url) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Router, Url, leevel, router_url, leevel_router_url_method_entry, 0);

	/**
	 * HTTP 请求
	 * 
	 * @var \Leevel\Http\IRequest
	 */
	zend_declare_property_null(leevel_router_url_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * URL 参数 
	 * 
	 * @var array 
	 */
	zend_declare_property_null(leevel_router_url_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_url_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_router_url_ce->create_object = zephir_init_properties_Leevel_Router_Url;

	zend_class_implements(leevel_router_url_ce TSRMLS_CC, 1, leevel_router_iurl_ce);
	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param \Leevel\Http\IRequest $request
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Router_Url, __construct) {

	zval option;
	zval *request, request_sub, *option_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &request, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	zephir_update_property_zval(this_ptr, SL("request"), request);
	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &option TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("option"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成路由地址
 *
 * @param string $url
 * @param array $params
 * @param string $subdomain
 * @param mixed $suffix
 * @return string
 */
PHP_METHOD(Leevel_Router_Url, make) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval subdomain;
	zval params;
	zval *url = NULL, url_sub, *params_param = NULL, *subdomain_param = NULL, *suffix = NULL, suffix_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&suffix_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&subdomain);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &url, &params_param, &subdomain_param, &suffix);

	ZEPHIR_SEPARATE_PARAM(url);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}
	if (!subdomain_param) {
		ZEPHIR_INIT_VAR(&subdomain);
		ZVAL_STRING(&subdomain, "www");
	} else {
		zephir_get_strval(&subdomain, subdomain_param);
	}
	if (!suffix) {
		suffix = &suffix_sub;
		suffix = &__$null;
	}


	ZEPHIR_INIT_VAR(&_1);
	if (!(Z_TYPE_P(suffix) == IS_NULL)) {
		ZEPHIR_CPY_WRT(&_1, suffix);
	} else {
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_1);
		zephir_array_fetch_string(&_1, &_2, SL("with_suffix"), PH_NOISY, "leevel/router/url.zep", 82 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "makeurl", NULL, 0, url, &params, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(url, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "withenter", NULL, 0, url);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(url, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "withdomain", NULL, 0, url, &subdomain);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(url, &_0);
	RETVAL_ZVAL(url, 1, 0);
	RETURN_MM();

}

/**
 * 返回 HTTP 请求
 * 
 * @return \Leevel\Http\IRequest
 */
PHP_METHOD(Leevel_Router_Url, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

/**
 * 设置配置
 * 
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_Router_Url, setOption) {

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
 * 自定义 URL
 * 
 * @param string $url
 * @param array $params
 * @param mixed $suffix
 * @return string
 */
PHP_METHOD(Leevel_Router_Url, makeUrl) {

	zend_class_entry *_7$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _8$$4;
	zval *url = NULL, url_sub, *params_param = NULL, *suffix, suffix_sub, queryUrl, _0, _1, _2, _4, _5, _11, _17, _3$$3, _6$$4, _9$$4, _10$$4, _12$$5, _13$$5, _14$$5, _15$$5, _16$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url_sub);
	ZVAL_UNDEF(&suffix_sub);
	ZVAL_UNDEF(&queryUrl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &url, &params_param, &suffix);

	ZEPHIR_SEPARATE_PARAM(url);
	zephir_get_arrval(&params, params_param);


	zephir_update_property_zval(this_ptr, SL("params"), &params);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, url, 0 , 1 , 0);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&_2, "/")) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "/", url);
		ZEPHIR_CPY_WRT(url, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "{");
	ZEPHIR_INIT_VAR(&_5);
	zephir_fast_strpos(&_5, url, &_4, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_5)) {
		_7$$4 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_create_array(&_8$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_8$$4, this_ptr);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "matchVar");
		zephir_array_fast_append(&_8$$4, &_9$$4);
		ZEPHIR_CALL_CE_STATIC(&_6$$4, _7$$4, "fromcallable", NULL, 0, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "/{(.+?)}/");
		ZEPHIR_CALL_FUNCTION(&_10$$4, "preg_replace_callback", NULL, 144, &_9$$4, &_6$$4, url);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(url, &_10$$4);
	}
	zephir_read_property(&_11, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_11)) {
		zephir_read_property(&_12$$5, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&queryUrl, "http_build_query", NULL, 145, &_12$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_INIT_VAR(&_14$$5);
		ZVAL_STRING(&_14$$5, "?");
		ZEPHIR_INIT_VAR(&_15$$5);
		zephir_fast_strpos(&_15$$5, url, &_14$$5, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_15$$5)) {
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "&");
		} else {
			ZEPHIR_INIT_NVAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "?");
		}
		ZEPHIR_INIT_VAR(&_16$$5);
		ZEPHIR_CONCAT_VV(&_16$$5, &_13$$5, &queryUrl);
		zephir_concat_self(url, &_16$$5 TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "withsuffix", NULL, 0, url, suffix);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(url, &_17);
	RETVAL_ZVAL(url, 1, 0);
	RETURN_MM();

}

/**
 * 匹配 URL 变量
 * 
 * @param array $matches
 * @return string
 */
PHP_METHOD(Leevel_Router_Url, matchVar) {

	zval *matches_param = NULL, value, params, _0, _1, _2$$3, _3$$3;
	zval matches;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matches_param);

	zephir_get_arrval(&matches, matches_param);


	zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&params, &_0);
	zephir_array_fetch_long(&_1, &matches, 1, PH_READONLY, "leevel/router/url.zep", 156 TSRMLS_CC);
	if (zephir_array_isset(&params, &_1)) {
		ZEPHIR_OBS_VAR(&value);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_array_fetch_long(&_2$$3, &matches, 1, PH_NOISY, "leevel/router/url.zep", 157 TSRMLS_CC);
		zephir_array_fetch(&value, &params, &_2$$3, PH_NOISY, "leevel/router/url.zep", 157 TSRMLS_CC);
		zephir_array_fetch_long(&_3$$3, &matches, 1, PH_NOISY | PH_READONLY, "leevel/router/url.zep", 158 TSRMLS_CC);
		zephir_array_unset(&params, &_3$$3, PH_SEPARATE);
		zephir_update_property_zval(this_ptr, SL("params"), &params);
	} else {
		ZEPHIR_OBS_NVAR(&value);
		zephir_array_fetch_long(&value, &matches, 0, PH_NOISY, "leevel/router/url.zep", 161 TSRMLS_CC);
	}
	RETURN_CCTOR(&value);

}

/**
 * 返回完整 URL 地址
 *
 * @param string $url
 * @param string $domain
 * @return string
 */
PHP_METHOD(Leevel_Router_Url, withDomain) {

	zend_bool _2, _5, _9;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *domain_param = NULL, _0, _1, _3, _4, _6, _7, _8, _11, _12;
	zval url, domain, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &domain_param);

	zephir_get_strval(&url, url_param);
	zephir_get_strval(&domain, domain_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("subdomain_on"), PH_NOISY | PH_READONLY, "leevel/router/url.zep", 176 TSRMLS_CC);
	_2 = !ZEPHIR_IS_TRUE_IDENTICAL(&_1);
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_4);
		zephir_array_fetch_string(&_4, &_3, SL("domain_top"), PH_NOISY, "leevel/router/url.zep", 177 TSRMLS_CC);
		_2 = !zephir_is_true(&_4);
	}
	_5 = _2;
	if (!(_5)) {
		_5 = ZEPHIR_IS_EMPTY(&domain);
	}
	if (_5) {
		RETURN_CTOR(&url);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "issecure", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_7)) {
		ZVAL_STRING(&_6, "https://");
	} else {
		ZEPHIR_INIT_VAR(&_8);
		_9 = zephir_is_true(&domain);
		if (_9) {
			_9 = !ZEPHIR_IS_STRING(&domain, "*");
		}
		if (_9) {
			ZEPHIR_INIT_VAR(&_10);
			ZEPHIR_CONCAT_VS(&_10, &domain, ".");
			ZEPHIR_CPY_WRT(&_8, &_10);
		} else {
			ZEPHIR_INIT_NVAR(&_8);
			ZVAL_STRING(&_8, "");
		}
		zephir_read_property(&_11, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_12, &_11, SL("domain_top"), PH_NOISY | PH_READONLY, "leevel/router/url.zep", 184 TSRMLS_CC);
		ZEPHIR_CONCAT_SVVV(&_6, "http://", &_8, &_12, &url);
	}
	RETURN_CCTOR(&_6);

}

/**
 * 是否启用 https
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Router_Url, isSecure) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "issecure", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * url 带后缀
 * 
 * @param string $url
 * @param string|boolean $suffix
 * @return string
 */
PHP_METHOD(Leevel_Router_Url, withSuffix) {

	zend_bool _0;
	zval *url_param = NULL, *suffix = NULL, suffix_sub, _1, _2, _3, _4, _5, _6, _7$$4, _8$$4, _9$$4;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&suffix_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &suffix);

	zephir_get_strval(&url, url_param);
	ZEPHIR_SEPARATE_PARAM(suffix);


	_0 = ZEPHIR_IS_STRING(&url, "/");
	if (!(_0)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "/?");
		ZEPHIR_INIT_VAR(&_2);
		zephir_fast_strpos(&_2, &url, &_1, 0 );
		_0 = ZEPHIR_IS_LONG_IDENTICAL(&_2, 0);
	}
	if (_0) {
		RETURN_CTOR(&url);
	}
	ZEPHIR_INIT_VAR(&_3);
	if (ZEPHIR_IS_TRUE_IDENTICAL(suffix)) {
		zephir_read_property(&_4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_3);
		zephir_array_fetch_string(&_3, &_4, SL("html_suffix"), PH_NOISY, "leevel/router/url.zep", 211 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_3, suffix);
	}
	ZEPHIR_CPY_WRT(suffix, &_3);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "?");
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_strpos(&_6, &url, &_5, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_VS(&_8$$4, suffix, "?");
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "?");
		zephir_fast_str_replace(&_7$$4, &_9$$4, &_8$$4, &url TSRMLS_CC);
		zephir_get_strval(&url, &_7$$4);
	} else {
		zephir_concat_self(&url, suffix TSRMLS_CC);
	}
	RETURN_CTOR(&url);

}

/**
 * 带上入口文件
 * 
 * @param string $url
 * @return string
 */
PHP_METHOD(Leevel_Router_Url, withEnter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, enter, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&enter);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&enter, &_0, "getenter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	if (!ZEPHIR_IS_STRING_IDENTICAL(&enter, "/")) {
		ZEPHIR_CPY_WRT(&_1, &enter);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		ZVAL_STRING(&_1, "");
	}
	ZEPHIR_CPY_WRT(&enter, &_1);
	ZEPHIR_CONCAT_VV(return_value, &enter, &url);
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Router_Url(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval __$false, __$true, _0, _2, _3$$4;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			zephir_array_update_string(&_1$$3, SL("with_suffix"), &__$false, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("html_suffix"), SL(".html"));
			add_assoc_stringl_ex(&_1$$3, SL("domain_top"), SL(""));
			zephir_array_update_string(&_1$$3, SL("subdomain_on"), &__$true, PH_COPY | PH_SEPARATE);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("params"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

