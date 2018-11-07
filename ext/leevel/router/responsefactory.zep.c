
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * 响应工厂
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.03
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_ResponseFactory) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Router, ResponseFactory, leevel, router_responsefactory, leevel_router_responsefactory_method_entry, 0);

	/**
	 * 视图
	 *
	 * @var \Leevel\Mvc\IView
	 */
	zend_declare_property_null(leevel_router_responsefactory_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 跳转实例
	 *
	 * @var \Leevel\Router\Redirector
	 */
	zend_declare_property_null(leevel_router_responsefactory_ce, SL("redirector"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 视图正确模板
	 *
	 * @var string
	 */
	zend_declare_property_string(leevel_router_responsefactory_ce, SL("viewSuccessTemplate"), "success", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 视图错误模板
	 *
	 * @var string
	 */
	zend_declare_property_string(leevel_router_responsefactory_ce, SL("viewFailTemplate"), "fail", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(leevel_router_responsefactory_ce TSRMLS_CC, 1, leevel_router_iresponsefactory_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Mvc\IView $view
 * @param \Leevel\Router\Redirect $redirector
 * @return void
 */
PHP_METHOD(Leevel_Router_ResponseFactory, __construct) {

	zval *view, view_sub, *redirector, redirector_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);
	ZVAL_UNDEF(&redirector_sub);

	zephir_fetch_params(0, 2, 0, &view, &redirector);



	zephir_update_property_zval(this_ptr, SL("view"), view);
	zephir_update_property_zval(this_ptr, SL("redirector"), redirector);

}

/**
 * 返回一个响应
 *
 * @param mixed $content
 * @param integer $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
PHP_METHOD(Leevel_Router_ResponseFactory, make) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *status_param = NULL, *headers_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &content, &status_param, &headers_param);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	object_init_ex(return_value, leevel_http_response_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 18, content, &_0, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回视图响应
 *
 * @param string $file
 * @param array $vars
 * @param string $ext
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
PHP_METHOD(Leevel_Router_ResponseFactory, view) {

	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval vars, headers;
	zval *file_param = NULL, *vars_param = NULL, *ext = NULL, ext_sub, *status_param = NULL, *headers_param = NULL, __$null, _0, _1, _2;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &file_param, &vars_param, &ext, &status_param, &headers_param);

	zephir_get_strval(&file, file_param);
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
		zephir_get_arrval(&vars, vars_param);
	}
	if (!ext) {
		ext = &ext_sub;
		ext = &__$null;
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "display", NULL, 0, &file, &vars, ext);
	zephir_check_call_status();
	ZVAL_LONG(&_2, status);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "make", NULL, 0, &_1, &_2, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回视图成功消息
 *
 * @param string $message
 * @param string $url
 * @param int $time
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
PHP_METHOD(Leevel_Router_ResponseFactory, viewSuccess) {

	zval headers;
	zend_long time, status, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *url_param = NULL, *time_param = NULL, *status_param = NULL, *headers_param = NULL, vars, _0, _1, _2, _3;
	zval message, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &message_param, &url_param, &time_param, &status_param, &headers_param);

	zephir_get_strval(&message, message_param);
	if (!url_param) {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_STRING(&url, "");
	} else {
		zephir_get_strval(&url, url_param);
	}
	if (!time_param) {
		time = 1;
	} else {
		time = zephir_get_intval(time_param);
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_INIT_VAR(&vars);
	zephir_create_array(&vars, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&vars, SL("message"), &message, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&vars, SL("url"), &url, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, time);
	zephir_array_update_string(&vars, SL("time"), &_0, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, SL("viewSuccessTemplate"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_2);
	ZVAL_LONG(&_3, status);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "view", NULL, 0, &_1, &vars, &_2, &_3, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回视图失败消息
 *
 * @param string $message
 * @param string $url
 * @param int $time
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
PHP_METHOD(Leevel_Router_ResponseFactory, viewFail) {

	zval headers;
	zend_long time, status, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *url_param = NULL, *time_param = NULL, *status_param = NULL, *headers_param = NULL, vars, _0, _1, _2, _3;
	zval message, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &message_param, &url_param, &time_param, &status_param, &headers_param);

	zephir_get_strval(&message, message_param);
	if (!url_param) {
		ZEPHIR_INIT_VAR(&url);
		ZVAL_STRING(&url, "");
	} else {
		zephir_get_strval(&url, url_param);
	}
	if (!time_param) {
		time = 3;
	} else {
		time = zephir_get_intval(time_param);
	}
	if (!status_param) {
		status = 404;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	ZEPHIR_INIT_VAR(&vars);
	zephir_create_array(&vars, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&vars, SL("message"), &message, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&vars, SL("url"), &url, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, time);
	zephir_array_update_string(&vars, SL("time"), &_0, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_1, this_ptr, SL("viewFailTemplate"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_2);
	ZVAL_LONG(&_3, status);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "view", NULL, 0, &_1, &vars, &_2, &_3, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回 JSON 响应
 *
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @param bool $json
 * @return \Leevel\Http\JsonResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, json) {

	zend_bool json;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *status_param = NULL, *headers_param = NULL, *json_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &data, &status_param, &headers_param, &json_param);

	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}


	object_init_ex(return_value, leevel_http_jsonresponse_ce);
	ZVAL_LONG(&_0, status);
	if (json) {
		ZVAL_BOOL(&_1, 1);
	} else {
		ZVAL_BOOL(&_1, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 54, data, &_0, &headers, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回 JSONP 响应
 *
 * @param string $callback
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @param bool $json
 * @return \Leevel\Http\JsonResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, jsonp) {

	zend_bool json;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *callback_param = NULL, *data = NULL, data_sub, *status_param = NULL, *headers_param = NULL, *json_param = NULL, __$null, _0, _1, _2;
	zval callback;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &callback_param, &data, &status_param, &headers_param, &json_param);

	zephir_get_strval(&callback, callback_param);
	if (!data) {
		data = &data_sub;
		data = &__$null;
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!json_param) {
		json = 0;
	} else {
		json = zephir_get_boolval(json_param);
	}


	ZVAL_LONG(&_1, status);
	if (json) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "json", NULL, 0, data, &_1, &headers, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "setcallback", NULL, 0, &callback);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回下载响应
 *
 * @param \SplFileObject|\SplFileInfo|string $file
 * @param string $name
 * @param integer $status
 * @param array $headers
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return \Leevel\Http\FileResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, download) {

	zend_bool autoEtag, autoLastModified;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval name;
	zval *file, file_sub, *name_param = NULL, *status_param = NULL, *headers_param = NULL, *autoEtag_param = NULL, *autoLastModified_param = NULL, response, _0, _1, _2, _3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &file, &name_param, &status_param, &headers_param, &autoEtag_param, &autoLastModified_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!autoEtag_param) {
		autoEtag = 0;
	} else {
		autoEtag = zephir_get_boolval(autoEtag_param);
	}
	if (!autoLastModified_param) {
		autoLastModified = 1;
	} else {
		autoLastModified = zephir_get_boolval(autoLastModified_param);
	}


	ZEPHIR_INIT_VAR(&response);
	object_init_ex(&response, leevel_http_fileresponse_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "attachment");
	if (autoEtag) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (autoLastModified) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, &response, "__construct", NULL, 107, file, &_0, &headers, &_1, &_2, &_3);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&name) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "attachment");
		ZEPHIR_RETURN_CALL_METHOD(&response, "setcontentdisposition", NULL, 142, &_4$$3, &name);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&response);

}

/**
 * 返回文件响应
 *
 * @param \SplFileObject|\SplFileInfo|string $file
 * @param integer $status
 * @param array $headers
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return \Leevel\Http\FileResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, file) {

	zend_bool autoEtag, autoLastModified;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *file, file_sub, *status_param = NULL, *headers_param = NULL, *autoEtag_param = NULL, *autoLastModified_param = NULL, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 4, &file, &status_param, &headers_param, &autoEtag_param, &autoLastModified_param);

	if (!status_param) {
		status = 200;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	if (!autoEtag_param) {
		autoEtag = 0;
	} else {
		autoEtag = zephir_get_boolval(autoEtag_param);
	}
	if (!autoLastModified_param) {
		autoLastModified = 1;
	} else {
		autoLastModified = zephir_get_boolval(autoLastModified_param);
	}


	object_init_ex(return_value, leevel_http_fileresponse_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "inline");
	if (autoEtag) {
		ZVAL_BOOL(&_2, 1);
	} else {
		ZVAL_BOOL(&_2, 0);
	}
	if (autoLastModified) {
		ZVAL_BOOL(&_3, 1);
	} else {
		ZVAL_BOOL(&_3, 0);
	}
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 107, file, &_0, &headers, &_1, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Leevel_Router_ResponseFactory, redirect) {

	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval params, headers;
	zval *url_param = NULL, *params_param = NULL, *subdomain_param = NULL, *suffix = NULL, suffix_sub, *status_param = NULL, *headers_param = NULL, __$false, _0, _1;
	zval url, subdomain;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&subdomain);
	ZVAL_UNDEF(&suffix_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 5, &url_param, &params_param, &subdomain_param, &suffix, &status_param, &headers_param);

	zephir_get_strval(&url, url_param);
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
		suffix = &__$false;
	}
	if (!status_param) {
		status = 302;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	zephir_read_property(&_0, this_ptr, SL("redirector"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, status);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "url", NULL, 0, &url, &params, &subdomain, suffix, &_1, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回一个跳转响应
 *
 * @param string $url
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\RedirectResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, redirectRaw) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *url_param = NULL, *status_param = NULL, *headers_param = NULL, _0, _1;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &url_param, &status_param, &headers_param);

	zephir_get_strval(&url, url_param);
	if (!status_param) {
		status = 302;
	} else {
		status = zephir_get_intval(status_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}


	zephir_read_property(&_0, this_ptr, SL("redirector"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, status);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "raw", NULL, 0, &url, &_1, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 请求成功
 * 一般用于GET与POST请求: 200
 *
 * @param mixed $content
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiOk) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &content, &text);

	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "ok", NULL, 0, content, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 已创建
 * 成功请求并创建了新的资源: 201
 *
 * @param null|string $location
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiCreated) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, *content = NULL, content_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &location, &content);

	if (!location) {
		location = &location_sub;
		location = &__$null;
	}
	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "created", NULL, 0, location, content);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 已接受
 * 已经接受请求，但未处理完成: 202
 *
 * @param null|string $location
 * @param mixed $content
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiAccepted) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, *content = NULL, content_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &location, &content);

	if (!location) {
		location = &location_sub;
		location = &__$null;
	}
	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "accepted", NULL, 0, location, content);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 无内容
 * 服务器成功处理，但未返回内容: 204
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiNoContent) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "nocontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 错误请求
 *
 * @param string $message
 * @param int $statusCode
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiError) {

	zend_long statusCode, ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *statusCode_param = NULL, *text = NULL, text_sub, __$null, _0, _1;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &message_param, &statusCode_param, &text);

	zephir_get_strval(&message, message_param);
	statusCode = zephir_get_intval(statusCode_param);
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, statusCode);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "error", NULL, 0, &message, &_1, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiBadRequest) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "badrequest", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 未授权
 * 对于需要登录的网页，服务器可能返回此响应: 401
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiUnauthorized) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "unauthorized", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 禁止
 * 服务器拒绝请求: 403
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiForbidden) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "forbidden", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 未找到
 * 用户发出的请求针对的是不存在的记录: 404
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiNotFound) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "notfound", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 方法禁用
 * 禁用请求中指定的方法: 405
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiMethodNotAllowed) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "methodnotallowed", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 无法处理的实体
 * 请求格式正确，但是由于含有语义错误，无法响应: 422
 *
 * @param array $errors
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiUnprocessableEntity) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *errors_param = NULL, *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval errors;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &errors_param, &message, &text);

	if (!errors_param) {
		ZEPHIR_INIT_VAR(&errors);
		array_init(&errors);
	} else {
		zephir_get_arrval(&errors, errors_param);
	}
	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "unprocessableentity", NULL, 0, &errors, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 太多请求
 * 用户在给定的时间内发送了太多的请求: 429
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiTooManyRequests) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toomanyrequests", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 服务器内部错误
 * 服务器遇到错误，无法完成请求: 500
 *
 * @param string $message
 * @param string $text
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, apiInternalServerError) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &text);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "createapiresponse", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "internalservererror", NULL, 0, message, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置视图正确模板
 *
 * @param string $template
 * @return $this
 */
PHP_METHOD(Leevel_Router_ResponseFactory, setViewSuccessTemplate) {

	zval *template_param = NULL;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &template_param);

	zephir_get_strval(&template, template_param);


	zephir_update_property_zval(this_ptr, SL("viewSuccessTemplate"), &template);
	RETURN_THIS();

}

/**
 * 设置视图错误模板
 *
 * @param string $template
 * @return $this
 */
PHP_METHOD(Leevel_Router_ResponseFactory, setViewFailTemplate) {

	zval *template_param = NULL;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &template_param);

	zephir_get_strval(&template, template_param);


	zephir_update_property_zval(this_ptr, SL("viewFailTemplate"), &template);
	RETURN_THIS();

}

/**
 * 创建基础 API 响应
 *
 * @return \Leevel\Http\ApiResponse
 */
PHP_METHOD(Leevel_Router_ResponseFactory, createApiResponse) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, leevel_http_apiresponse_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 54);
	zephir_check_call_status();
	RETURN_MM();

}

