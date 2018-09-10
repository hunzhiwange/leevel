
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
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * Api 响应请求
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.01
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Http_ApiResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, ApiResponse, leevel, http_apiresponse, leevel_http_jsonresponse_ce, leevel_http_apiresponse_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个 API 响应
 * 
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @return static
 */
PHP_METHOD(Leevel_Http_ApiResponse, create) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *status_param = NULL, *headers_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &status_param, &headers_param);

	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		ZVAL_STRING(data, "");
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


	object_init_ex(return_value, leevel_http_apiresponse_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 54, data, &_0, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 请求成功
 * 一般用于GET与POST请求： 200
 * 
 * @param mixed $content
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, ok) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *content = NULL, content_sub, *text = NULL, text_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZVAL_LONG(&_1, 200);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1, text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setdata", NULL, 0, content);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 已创建
 * 成功请求并创建了新的资源: 201
 *
 * @param null|string $location
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, created) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, *content = NULL, content_sub, _0, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &location, &content);

	if (!location) {
		location = &location_sub;
		ZEPHIR_INIT_VAR(location);
		ZVAL_STRING(location, "");
	}
	if (!content) {
		content = &content_sub;
		ZEPHIR_INIT_VAR(content);
		ZVAL_STRING(content, "");
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, content);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 201);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(location) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Location");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2$$4, location);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 已接受
 * 已经接受请求，但未处理完成: 202
 *
 * @param null|string $location
 * @param mixed $content
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, accepted) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *location = NULL, location_sub, *content = NULL, content_sub, __$null, _0, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&location_sub);
	ZVAL_UNDEF(&content_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, content);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 202);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(location) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Location");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_2$$4, location);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * 无内容
 * 服务器成功处理，但未返回内容: 204
 *
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, noContent) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZVAL_LONG(&_1, 204);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setstatuscode", NULL, 0, &_1);
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
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, unprocessableEntity) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *errors_param = NULL, *message = NULL, message_sub, *text = NULL, text_sub, __$null, tmpArr, _0, _1, _3;
	zval errors, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&errors);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmpArr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);

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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZVAL_LONG(&_1, 422);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, &_1, text);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&errors))) {
		ZEPHIR_CPY_WRT(&tmpArr, &errors);
	} else {
		ZEPHIR_INIT_NVAR(&tmpArr);
		array_init(&tmpArr);
	}
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "parseerrormessage", NULL, 0, message);
	zephir_check_call_status();
	zephir_array_update_string(&_2, SL("message"), &_3, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_2, SL("errors"), &tmpArr, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, &_2);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 * 
 * @param string $message
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *statusCode, statusCode_sub, *text = NULL, text_sub, __$null, _0;
	zval message;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&statusCode_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &message_param, &statusCode, &text);

	zephir_get_strval(&message, message_param);
	if (!text) {
		text = &text_sub;
		text = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setstatuscode", NULL, 0, statusCode, text);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "normalizeerrormessage", NULL, 0, &message);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, badRequest) {

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


	ZVAL_LONG(&_0, 400);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 未授权
 * 对于需要登录的网页，服务器可能返回此响应: 401
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, unauthorized) {

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


	ZVAL_LONG(&_0, 401);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 禁止
 * 服务器拒绝请求: 403
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, forbidden) {

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


	ZVAL_LONG(&_0, 403);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 未找到
 * 用户发出的请求针对的是不存在的记录: 404
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, notFound) {

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


	ZVAL_LONG(&_0, 404);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 方法禁用
 * 禁用请求中指定的方法: 405
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, methodNotAllowed) {

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


	ZVAL_LONG(&_0, 405);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 太多请求
 * 用户在给定的时间内发送了太多的请求: 429
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, tooManyRequests) {

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


	ZVAL_LONG(&_0, 429);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 服务器内部错误
 * 服务器遇到错误，无法完成请求: 500
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, internalServerError) {

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


	ZVAL_LONG(&_0, 500);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "error", NULL, 0, message, &_0, text);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 格式化错误消息
 *  
 * @param string $message
 * @return $this
 */
PHP_METHOD(Leevel_Http_ApiResponse, normalizeErrorMessage) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, message_sub, *text = NULL, text_sub, __$null, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&text_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
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


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "parseerrormessage", NULL, 0, message);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("message"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setdata", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析错误消息
 *  
 * @param string $message
 * @return string
 */
PHP_METHOD(Leevel_Http_ApiResponse, parseErrorMessage) {

	zval *message = NULL, message_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &message);

	if (!message) {
		message = &message_sub;
		message = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(message)) {
		ZEPHIR_CPY_WRT(&_0, message);
	} else {
		zephir_read_property(&_0, this_ptr, SL("statusText"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

