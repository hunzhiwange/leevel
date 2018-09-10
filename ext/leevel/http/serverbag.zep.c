
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * server bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.04
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Http_ServerBag) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Http, ServerBag, leevel, http_serverbag, leevel_http_bag_ce, leevel_http_serverbag_method_entry, 0);

	return SUCCESS;

}

/**
 * 取回 HTTP HEADERS
 *
 * @return array
 */
PHP_METHOD(Leevel_Http_ServerBag, getHeaders) {

	zend_string *_4;
	zend_ulong _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_8 = NULL;
	zval __$true, result, contentHeaders, key, value, _0, _1, *_2, _5$$3, _6$$3, _7$$3, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&contentHeaders);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&contentHeaders);
	zephir_create_array(&contentHeaders, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "CONTENT_LENGTH");
	zephir_array_fast_append(&contentHeaders, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "CONTENT_MD5");
	zephir_array_fast_append(&contentHeaders, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "CONTENT_TYPE");
	zephir_array_fast_append(&contentHeaders, &_0);
	zephir_read_property(&_1, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "leevel/http/serverbag.zep", 53);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_1), _3, _4, _2)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_4 != NULL) { 
			ZVAL_STR_COPY(&key, _4);
		} else {
			ZVAL_LONG(&key, _3);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _2);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "HTTP_");
		ZEPHIR_INIT_NVAR(&_6$$3);
		zephir_fast_strpos(&_6$$3, &key, &_5$$3, 0 );
		ZEPHIR_CALL_FUNCTION(&_7$$3, "in_array", &_8, 55, &key, &contentHeaders, &__$true);
		zephir_check_call_status();
		if (ZEPHIR_IS_LONG_IDENTICAL(&_6$$3, 0)) {
			ZVAL_LONG(&_9$$4, 5);
			ZEPHIR_INIT_NVAR(&_10$$4);
			zephir_substr(&_10$$4, &key, 5 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			zephir_array_update_zval(&result, &_10$$4, &value, PH_COPY | PH_SEPARATE);
		} else if (zephir_is_true(&_7$$3)) {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&result);

}

