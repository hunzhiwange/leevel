
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
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * header bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.04
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Http_HeaderBag) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, HeaderBag, leevel, http_headerbag, leevel_http_bag_ce, leevel_http_headerbag_method_entry, 0);

	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param array $elements
 * @return void 
 */
PHP_METHOD(Leevel_Http_HeaderBag, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Http_HeaderBag, replace) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, _0;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("elements"), &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "add", NULL, 0, &elements);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Http_HeaderBag, add) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, key, value, *_0;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	zephir_is_iterable(&elements, 0, "leevel/http/headerbag.zep", 60);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&elements), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 0, &key, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化 header 字符串 
 * 
 * @return string
 */
PHP_METHOD(Leevel_Http_HeaderBag, __toString) {

	zend_string *_2;
	zend_ulong _1;
	zval headers, content, name, value, *_0, _3$$4, _4$$4, _6$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&headers, this_ptr, "all", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&headers))) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_MAKE_REF(&headers);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 52, &headers);
	ZEPHIR_UNREF(&headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&content);
	ZVAL_STRING(&content, "");
	zephir_is_iterable(&headers, 0, "leevel/http/headerbag.zep", 85);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_INIT_NVAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "-");
		ZEPHIR_CALL_FUNCTION(&_4$$4, "ucwords", &_5, 23, &name, &_3$$4);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&name, &_4$$4);
		ZEPHIR_INIT_LNVAR(_6$$4);
		ZEPHIR_CONCAT_VSVS(&_6$$4, &name, ": ", &value, "\r\n");
		zephir_concat_self(&content, &_6$$4 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&content);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Http_HeaderBag, normalize) {

	zval *key = NULL, key_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, key);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "_");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-");
	ZEPHIR_INIT_NVAR(key);
	zephir_fast_str_replace(key, &_1, &_2, &_0 TSRMLS_CC);
	RETVAL_ZVAL(key, 1, 0);
	RETURN_MM();

}

