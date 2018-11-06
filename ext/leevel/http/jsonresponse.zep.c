
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
#include "ext/spl/spl_array.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/string.h"


/**
 * JSON 响应请求
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.06
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Leevel_Http_JsonResponse) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, JsonResponse, leevel, http_jsonresponse, leevel_http_response_ce, leevel_http_jsonresponse_method_entry, 0);

	/**
	 * 响应内容
	 * 
	 * @var sting
	 */
	zend_declare_property_null(leevel_http_jsonresponse_ce, SL("data"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * JSON 格式化参数
	 * 
	 * @var int
	 */
	zend_declare_property_long(leevel_http_jsonresponse_ce, SL("encodingOptions"), 256, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * JSONP 回调
	 * 
	 * @var \callable
	 */
	zend_declare_property_null(leevel_http_jsonresponse_ce, SL("callback"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 默认 JSON 格式化参数 
	 *  
	 * @var int
	 */
	zephir_declare_class_constant_long(leevel_http_jsonresponse_ce, SL("DEFAULT_ENCODING_OPTIONS"), 256);

	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @param bool $json
 * @return void
 */
PHP_METHOD(Leevel_Http_JsonResponse, __construct) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_bool json;
	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *status_param = NULL, *headers_param = NULL, *json_param = NULL, __$true, __$false, __$null, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 4, &data, &status_param, &headers_param, &json_param);

	if (!data) {
		data = &data_sub;
		ZEPHIR_CPY_WRT(data, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(data);
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


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZVAL_LONG(&_2, status);
	ZEPHIR_CALL_PARENT(NULL, leevel_http_jsonresponse_ce, getThis(), "__construct", &_0, 0, &_1, &_2, &headers);
	zephir_check_call_status();
	if (Z_TYPE_P(data) == IS_NULL) {
		ZEPHIR_INIT_NVAR(data);
		object_init_ex(data, spl_ce_ArrayObject);
		ZEPHIR_CALL_METHOD(NULL, data, "__construct", NULL, 52);
		zephir_check_call_status();
	}
	if (json) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setjson", NULL, 0, data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdata", NULL, 0, data);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("isJson"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isJson"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建一个 JSON 响应
 * 
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @return static
 */
PHP_METHOD(Leevel_Http_JsonResponse, create) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *status_param = NULL, *headers_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &status_param, &headers_param);

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


	object_init_ex(return_value, leevel_http_jsonresponse_ce);
	ZVAL_LONG(&_0, status);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, data, &_0, &headers);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 从 JSON 字符串创建响应对象  
 * 
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @return static
 */
PHP_METHOD(Leevel_Http_JsonResponse, fromJsonString) {

	zval headers;
	zend_long status, ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *status_param = NULL, *headers_param = NULL, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &data, &status_param, &headers_param);

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


	object_init_ex(return_value, leevel_http_jsonresponse_ce);
	ZVAL_LONG(&_0, status);
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 53, data, &_0, &headers, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置 JSONP 回调 
 *
 * @param string|null $callback
 * @return $this
 */
PHP_METHOD(Leevel_Http_JsonResponse, setCallback) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback = NULL, callback_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &callback);

	if (!callback) {
		callback = &callback_sub;
		callback = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	zephir_update_property_zval(this_ptr, SL("callback"), callback);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "updatecontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置原生 JSON 数据
 *
 * @param mixed $json
 * @return $this
 */
PHP_METHOD(Leevel_Http_JsonResponse, setJson) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *json, json_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&json_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &json);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "isjsondata", NULL, 0, json);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "The method setJson need a json data.", "leevel/http/jsonresponse.zep", 147);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("data"), json);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "updatecontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置数据作为 JSON   
 *
 * @param mixed $data
 * @param int $encodingOptions
 * @return $this
 */
PHP_METHOD(Leevel_Http_JsonResponse, setData) {

	zend_bool _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, *encodingOptions = NULL, encodingOptions_sub, __$null, _0, _14, _4$$5, _5$$5, _6$$5, _7$$6, _8$$6, _9$$7, _10$$7, _11$$7, _12$$8, _13$$8, _15$$9, _16$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&encodingOptions_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &data, &encodingOptions);

	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}
	if (!encodingOptions) {
		encodingOptions = &encodingOptions_sub;
		encodingOptions = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	if (Z_TYPE_P(encodingOptions) != IS_NULL) {
		zephir_update_property_zval(this_ptr, SL("encodingOptions"), encodingOptions);
	}
	_1 = Z_TYPE_P(data) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(data, leevel_support_iarray_ce TSRMLS_CC);
	}
	_2 = Z_TYPE_P(data) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(data, leevel_support_ijson_ce TSRMLS_CC);
	}
	_3 = Z_TYPE_P(data) == IS_OBJECT;
	if (_3) {
		_3 = zephir_is_instance_of(data, SL("JsonSerializable") TSRMLS_CC);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_4$$5);
		ZEPHIR_CALL_METHOD(&_5$$5, data, "toarray", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_6$$5, this_ptr, SL("encodingOptions"), PH_NOISY_CC | PH_READONLY);
		zephir_json_encode(&_4$$5, &_5$$5, zephir_get_intval(&_6$$5) );
		zephir_update_property_zval(this_ptr, SL("data"), &_4$$5);
	} else if (_2) {
		zephir_read_property(&_8$$6, this_ptr, SL("encodingOptions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7$$6, data, "tojson", NULL, 0, &_8$$6);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("data"), &_7$$6);
	} else if (_3) {
		ZEPHIR_INIT_VAR(&_9$$7);
		ZEPHIR_CALL_METHOD(&_10$$7, data, "jsonserialize", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_11$$7, this_ptr, SL("encodingOptions"), PH_NOISY_CC | PH_READONLY);
		zephir_json_encode(&_9$$7, &_10$$7, zephir_get_intval(&_11$$7) );
		zephir_update_property_zval(this_ptr, SL("data"), &_9$$7);
	} else {
		ZEPHIR_INIT_VAR(&_12$$8);
		zephir_read_property(&_13$$8, this_ptr, SL("encodingOptions"), PH_NOISY_CC | PH_READONLY);
		zephir_json_encode(&_12$$8, data, zephir_get_intval(&_13$$8) );
		zephir_update_property_zval(this_ptr, SL("data"), &_12$$8);
	}
	ZEPHIR_CALL_FUNCTION(&_14, "json_last_error", NULL, 19);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG_IDENTICAL(&_14, 0)) {
		ZEPHIR_INIT_VAR(&_15$$9);
		object_init_ex(&_15$$9, spl_ce_InvalidArgumentException);
		ZEPHIR_CALL_FUNCTION(&_16$$9, "json_last_error_msg", NULL, 20);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_15$$9, "__construct", NULL, 21, &_16$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_15$$9, "leevel/http/jsonresponse.zep", 184 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "updatecontent", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取回数据
 *
 * @param bool $assoc
 * @param int $depth
 * @return mixed
 */
PHP_METHOD(Leevel_Http_JsonResponse, getData) {

	zend_long depth;
	zval *assoc_param = NULL, *depth_param = NULL, _0, _1, _2;
	zend_bool assoc;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	zephir_fetch_params(0, 0, 2, &assoc_param, &depth_param);

	if (!assoc_param) {
		assoc = 1;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}
	if (!depth_param) {
		depth = 512;
	} else {
		depth = zephir_get_intval(depth_param);
	}


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, (assoc ? 1 : 0));
	ZVAL_LONG(&_2, depth);
	zephir_json_decode(return_value, &_0, zephir_get_intval(&_1) );
	return;

}

/**
 * 获取编码参数
 *
 * @return int
 */
PHP_METHOD(Leevel_Http_JsonResponse, getEncodingOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "encodingOptions");

}

/**
 * 设置编码参数
 *
 * @param int $encodingOptions
 * @return $this
 */
PHP_METHOD(Leevel_Http_JsonResponse, setEncodingOptions) {

	zval *encodingOptions_param = NULL, _0, _1, _2, _3;
	zend_long encodingOptions, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encodingOptions_param);

	encodingOptions = zephir_get_intval(encodingOptions_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checktcontrol", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_THIS();
	}
	ZVAL_LONG(&_1, encodingOptions);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, zephir_get_intval(&_1));
	zephir_update_property_zval(this_ptr, SL("encodingOptions"), &_2);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setdata", NULL, 0, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 验证是否为正常的 JSON 字符串
 *
 * @param mixed $data
 * @return boolean
 */
PHP_METHOD(Leevel_Http_JsonResponse, isJsonData) {

	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = !(zephir_is_scalar(data));
	if (_0) {
		_0 = !(((zephir_method_exists_ex(data, SL("__tostring") TSRMLS_CC) == SUCCESS)));
	}
	if (_0) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CALL_FUNCTION(&_2, "strval", NULL, 11, data);
	zephir_check_call_status();
	zephir_json_decode(&_1, &_2, 0 );
	ZEPHIR_CALL_FUNCTION(&_3, "json_last_error", NULL, 19);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_3, 0));

}

/**
 * 更新响应内容
 *
 * @return $this
 */
PHP_METHOD(Leevel_Http_JsonResponse, updateContent) {

	zend_bool _10;
	zval _0, _7, _8, _9, _11, _12, _16, _1$$3, _2$$3, _3$$3, _4$$3, _5$$3, _6$$3, _13$$4, _14$$4, _15$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("callback"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_property(&_1$$3, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Content-Type");
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "text/javascript");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "set", NULL, 0, &_2$$3, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, SL("callback"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_5$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, ";%s(%s);");
		ZEPHIR_CALL_FUNCTION(&_6$$3, "sprintf", NULL, 1, &_2$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcontent", NULL, 0, &_6$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_7, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "Content-Type");
	ZEPHIR_CALL_METHOD(&_8, &_7, "has", NULL, 0, &_9);
	zephir_check_call_status();
	_10 = !zephir_is_true(&_8);
	if (!(_10)) {
		zephir_read_property(&_11, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_9);
		ZVAL_STRING(&_9, "Content-Type");
		ZEPHIR_CALL_METHOD(&_12, &_11, "get", NULL, 0, &_9);
		zephir_check_call_status();
		_10 = ZEPHIR_IS_STRING_IDENTICAL(&_12, "text/javascript");
	}
	if (_10) {
		zephir_read_property(&_13$$4, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "Content-Type");
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "application/json");
		ZEPHIR_CALL_METHOD(NULL, &_13$$4, "set", NULL, 0, &_14$$4, &_15$$4);
		zephir_check_call_status();
	}
	zephir_read_property(&_16, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setcontent", NULL, 0, &_16);
	zephir_check_call_status();
	RETURN_MM();

}

