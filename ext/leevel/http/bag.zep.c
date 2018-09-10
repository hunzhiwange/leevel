
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
#include "ext/spl/spl_iterators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * http bag
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.19
 *
 * @version 1.0
 *
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
ZEPHIR_INIT_CLASS(Leevel_Http_Bag) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Http, Bag, leevel, http_bag, leevel_http_bag_method_entry, 0);

	/**
	 * zephir 不支持 eval 动态赋值
	 * 
	 * @var boolean
	 */
	zend_declare_property_bool(leevel_http_bag_ce, SL("zephirAssign"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 元素合集
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_http_bag_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_http_bag_ce->create_object = zephir_init_properties_Leevel_Http_Bag;

	zend_class_implements(leevel_http_bag_ce TSRMLS_CC, 1, leevel_support_iarray_ce);
	zend_class_implements(leevel_http_bag_ce TSRMLS_CC, 1, leevel_support_ijson_ce);
	zend_class_implements(leevel_http_bag_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(leevel_http_bag_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(leevel_http_bag_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * 构造函数
 * 
 * @param array $elements
 * @return void 
 */
PHP_METHOD(Leevel_Http_Bag, __construct) {

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


	zephir_update_property_zval(this_ptr, SL("elements"), &elements);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回元素
 *
 * @return array
 */
PHP_METHOD(Leevel_Http_Bag, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "elements");

}

/**
 * 返回元素键值
 *
 * @return array
 */
PHP_METHOD(Leevel_Http_Bag, keys) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_array_keys(return_value, &_0 TSRMLS_CC);
	return;

}

/**
 * 替换当前所有元素
 *
 * @param array $elements
 * @return void
 */
PHP_METHOD(Leevel_Http_Bag, replace) {

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


	zephir_update_property_zval(this_ptr, SL("elements"), &elements);
	ZEPHIR_MM_RESTORE();

}

/**
 * 新增元素
 *
 * @param array $elements
 * @return void
 */
PHP_METHOD(Leevel_Http_Bag, add) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements_param = NULL, _0, _1;
	zval elements;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &elements_param);

	if (!elements_param) {
		ZEPHIR_INIT_VAR(&elements);
		array_init(&elements);
	} else {
		zephir_get_arrval(&elements, elements_param);
	}


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "array_replace", NULL, 4, &_0, &elements);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("elements"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回元素值
 *
 * @param string $key
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *defaults = NULL, defaults_sub, __$null, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaults);

	zephir_get_strval(&key, key_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filter", NULL, 0, &key, defaults);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置元素值
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Http_Bag, set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_update_property_array(this_ptr, SL("elements"), &key, value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断是否存在元素值
 *
 * @param string $key
 * @return bool
 */
PHP_METHOD(Leevel_Http_Bag, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	zephir_read_property(&_1, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_key_exists(&_1, &key TSRMLS_CC));

}

/**
 * 删除元素值
 *
 * @param string $key
 * @return void
 */
PHP_METHOD(Leevel_Http_Bag, remove) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, &key);
	zephir_check_call_status();
	zephir_get_strval(&key, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "has", NULL, 0, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, &key, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取过滤变量
 *
 * @param string $key
 * @param mixed $defaults
 * @param array|sting|int $filter
 * @param array $options
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, filter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *key = NULL, key_sub, *defaults = NULL, defaults_sub, *filter = NULL, filter_sub, *options_param = NULL, __$null, tmp, tmpKey, result, part, _0, _1, _2, _3, _4, _5$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmpKey);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &key, &defaults, &filter, &options_param);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}
	if (!filter) {
		filter = &filter_sub;
		ZEPHIR_CPY_WRT(filter, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(filter);
	}
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	ZEPHIR_INIT_VAR(&tmpKey);
	array_init(&tmpKey);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalize", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(key, &_0);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsefilter", NULL, 0, filter);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(filter, &_0);
	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "parsekeyfilter", NULL, 0, key, filter);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(key);
	zephir_array_fetch_long(key, &tmp, 0, PH_NOISY, "leevel/http/bag.zep", 178 TSRMLS_CC);
	ZEPHIR_OBS_NVAR(filter);
	zephir_array_fetch_long(filter, &tmp, 1, PH_NOISY, "leevel/http/bag.zep", 179 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&part);
	ZVAL_STRING(&part, "");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "\\");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, key, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		ZEPHIR_INIT_NVAR(&tmpKey);
		zephir_fast_explode_str(&tmpKey, SL("\\"), key, LONG_MAX TSRMLS_CC);
		ZEPHIR_OBS_NVAR(key);
		zephir_array_fetch_long(key, &tmpKey, 0, PH_NOISY, "leevel/http/bag.zep", 184 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&part);
		zephir_array_fetch_long(&part, &tmpKey, 1, PH_NOISY, "leevel/http/bag.zep", 185 TSRMLS_CC);
	}
	zephir_read_property(&_3, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_key_exists(&_3, key TSRMLS_CC)) {
		zephir_read_property(&_4, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&result);
		zephir_array_fetch(&result, &_4, key, PH_NOISY, "leevel/http/bag.zep", 188 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&result, defaults);
	}
	if (zephir_is_true(&part)) {
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "getpartdata", NULL, 0, &part, &result, defaults);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_5$$4);
	}
	if (zephir_is_true(filter)) {
		ZEPHIR_CALL_METHOD(&_6$$5, this_ptr, "filtervalue", NULL, 0, &result, defaults, filter, &options);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&result, &_6$$5);
	}
	RETURN_CCTOR(&result);

}

/**
 * 实现 Countable::count
 *
 * @return int
 */
PHP_METHOD(Leevel_Http_Bag, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * 对象转数组
 *
 * @return array
 */
PHP_METHOD(Leevel_Http_Bag, toArray) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "elements");

}

/**
 * 实现 JsonSerializable::jsonSerialize
 *
 * @return array
 */
PHP_METHOD(Leevel_Http_Bag, jsonSerialize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 对象转 JSON
 *
 * @param integer $option
 * @return string
 */
PHP_METHOD(Leevel_Http_Bag, toJson) {

	zval *option_param = NULL, _0, _1;
	zend_long option, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		option = 256;
	} else {
		option = zephir_get_intval(option_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "jsonserialize", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_1, option);
	zephir_json_encode(return_value, &_0, zephir_get_intval(&_1) );
	RETURN_MM();

}

/**
 * 实现 IteratorAggregate::getIterator
 *
 * @return \ArrayIterator
 */
PHP_METHOD(Leevel_Http_Bag, getIterator) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 5, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 魔术方法 __toString
 *
 * @return string
 */
PHP_METHOD(Leevel_Http_Bag, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tojson", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析键值和过滤器
 * 
 * @param string $key
 * @param array $filter
 * @return array
 */
PHP_METHOD(Leevel_Http_Bag, parseKeyFilter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filter;
	zval *key_param = NULL, *filter_param = NULL, tmp, tmpKey, _0, _1, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&tmpKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&filter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &filter_param);

	zephir_get_strval(&key, key_param);
	zephir_get_arrval(&filter, filter_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "|");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &key, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&tmp);
		zephir_fast_explode_str(&tmp, SL("|"), &key, LONG_MAX TSRMLS_CC);
		ZEPHIR_MAKE_REF(&tmp);
		ZEPHIR_CALL_FUNCTION(&tmpKey, "array_shift", NULL, 6, &tmp);
		ZEPHIR_UNREF(&tmp);
		zephir_check_call_status();
		zephir_get_strval(&key, &tmpKey);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fast_array_merge(&_2$$3, &tmp, &filter TSRMLS_CC);
		ZEPHIR_CPY_WRT(&filter, &_2$$3);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &key);
	zephir_array_fast_append(return_value, &filter);
	RETURN_MM();

}

/**
 * 分析过滤器
 *
 * @param string|array|null $filter
 * @return array
 */
PHP_METHOD(Leevel_Http_Bag, parseFilter) {

	zval *filter = NULL, filter_sub, __$null, data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &filter);

	if (!filter) {
		filter = &filter_sub;
		filter = &__$null;
	}


	if (Z_TYPE_P(filter) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(filter) == IS_ARRAY) {
		RETVAL_ZVAL(filter, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&data);
	zephir_create_array(&data, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&data, filter);
	RETURN_CCTOR(&data);

}

/**
 * 过滤值
 *
 * @param mixed $value
 * @param mixed $defaults
 * @param array $filters
 * @param array $options
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, filterValue) {

	zend_bool _1$$3, _4$$3;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filters, options;
	zval *value = NULL, value_sub, *defaults, defaults_sub, *filters_param = NULL, *options_param = NULL, item, *_0, _2$$3, _3$$3, _5$$4, _7$$5, _9$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&filters);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &value, &defaults, &filters_param, &options_param);

	ZEPHIR_SEPARATE_PARAM(value);
	zephir_get_arrval(&filters, filters_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	zephir_is_iterable(&filters, 0, "leevel/http/bag.zep", 334);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&filters), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		_1$$3 = Z_TYPE_P(&item) == IS_STRING;
		if (_1$$3) {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "=");
			ZEPHIR_INIT_NVAR(&_3$$3);
			zephir_fast_strpos(&_3$$3, &item, &_2$$3, 0 );
			_1$$3 = !ZEPHIR_IS_FALSE_IDENTICAL(&_3$$3);
		}
		_4$$3 = zephir_is_scalar(value);
		if (_4$$3) {
			_4$$3 = !(ZEPHIR_IS_EMPTY(&item));
		}
		if (_1$$3) {
			ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "filtervaluewithfunc", &_6, 0, value, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, &_5$$4);
		} else if (zephir_is_callable(&item TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(&_7$$5, this_ptr, "filtervaluewithcallable", &_8, 0, value, &item);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, &_7$$5);
		} else if (_4$$3) {
			ZEPHIR_CALL_METHOD(&_9$$6, this_ptr, "filtervaluewithfiltervar", &_10, 0, value, &item, &options);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(value, &_9$$6);
			if (ZEPHIR_IS_FALSE_IDENTICAL(value)) {
				ZEPHIR_CPY_WRT(value, defaults);
				break;
			}
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * 使用函数过滤值
 *
 * @param mixed $value
 * @param string $filter
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, filterValueWithFunc) {

	zend_bool _0$$3, _10$$7, _11$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *filter = NULL, filter_sub, __$true, extend, tmp, evals, tmpExtend, result, v, _20, _23, _1$$3, _2$$3, _3$$3, _5$$3, _4$$4, _6$$5, _7$$5, _15$$5, _16$$5, *_8$$6, _9$$7, _12$$7, _13$$7, _14$$9, _17$$10, _18$$10, _19$$10, _21$$12, _22$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&extend);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&evals);
	ZVAL_UNDEF(&tmpExtend);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter);

	ZEPHIR_SEPARATE_PARAM(value);
	ZEPHIR_SEPARATE_PARAM(filter);


	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	ZEPHIR_INIT_VAR(&tmpExtend);
	array_init(&tmpExtend);
	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_NVAR(&tmp);
	zephir_fast_explode_str(&tmp, SL("="), filter, LONG_MAX TSRMLS_CC);
	ZEPHIR_OBS_NVAR(filter);
	zephir_array_fetch_long(filter, &tmp, 0, PH_NOISY, "leevel/http/bag.zep", 349 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&extend);
	zephir_array_fetch_long(&extend, &tmp, 1, PH_NOISY, "leevel/http/bag.zep", 350 TSRMLS_CC);
	if (ZEPHIR_IS_STRING(filter, "default")) {
		_0$$3 = !(zephir_is_numeric(&extend));
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZEPHIR_INIT_VAR(&_2$$3);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "/^[A-Z\\_]+$/");
			zephir_preg_match(&_2$$3, &_3$$3, &extend, &_1$$3, 0, 0 , 0  TSRMLS_CC);
			_0$$3 = !zephir_is_true(&_2$$3);
		}
		if (_0$$3) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_SVS(&_4$$4, "'", &extend, "'");
			ZEPHIR_CPY_WRT(&extend, &_4$$4);
		}
		ZEPHIR_INIT_VAR(&_5$$3);
		if (zephir_is_true(value)) {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "1");
		} else {
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZVAL_STRING(&_5$$3, "");
		}
		ZEPHIR_INIT_VAR(&evals);
		ZEPHIR_CONCAT_SVSVS(&evals, "$value = '", &_5$$3, "' ?: ", &extend, ";");
	} else if (zephir_is_true(&extend)) {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZVAL_STRING(&_6$$5, ",");
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_fast_strpos(&_7$$5, &extend, &_6$$5, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7$$5)) {
			ZEPHIR_INIT_NVAR(&tmpExtend);
			zephir_fast_explode_str(&tmpExtend, SL(","), &extend, LONG_MAX TSRMLS_CC);
			zephir_is_iterable(&tmpExtend, 0, "leevel/http/bag.zep", 372);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&tmpExtend), _8$$6)
			{
				ZEPHIR_INIT_NVAR(&v);
				ZVAL_COPY(&v, _8$$6);
				ZEPHIR_INIT_NVAR(&_9$$7);
				zephir_fast_trim(&_9$$7, &v, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				ZEPHIR_CPY_WRT(&v, &_9$$7);
				_10$$7 = ZEPHIR_IS_STRING(&v, "**");
				if (!(_10$$7)) {
					_10$$7 = zephir_is_numeric(&v);
				}
				_11$$7 = _10$$7;
				if (!(_11$$7)) {
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZEPHIR_INIT_NVAR(&_9$$7);
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_STRING(&_13$$7, "/^[A-Z\\_]+$/");
					zephir_preg_match(&_9$$7, &_13$$7, &v, &_12$$7, 0, 0 , 0  TSRMLS_CC);
					_11$$7 = zephir_is_true(&_9$$7);
				}
				if (_11$$7) {
					zephir_array_append(&result, &v, PH_SEPARATE, "leevel/http/bag.zep", 366);
				} else {
					ZEPHIR_INIT_LNVAR(_14$$9);
					ZEPHIR_CONCAT_SVS(&_14$$9, "'", &v, "'");
					zephir_array_append(&result, &_14$$9, PH_SEPARATE, "leevel/http/bag.zep", 368);
				}
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&v);
			ZEPHIR_INIT_NVAR(&extend);
			zephir_fast_join_str(&extend, SL(","), &result TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(&_15$$5);
		ZVAL_STRING(&_15$$5, "**");
		ZEPHIR_CALL_FUNCTION(&_16$$5, "strstr", NULL, 7, &extend, &_15$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&evals);
		if (zephir_is_true(&_16$$5)) {
			ZEPHIR_INIT_VAR(&_17$$10);
			ZEPHIR_INIT_VAR(&_18$$10);
			ZVAL_STRING(&_18$$10, "**");
			ZEPHIR_INIT_VAR(&_19$$10);
			ZVAL_STRING(&_19$$10, "$value");
			zephir_fast_str_replace(&_17$$10, &_18$$10, &_19$$10, &extend TSRMLS_CC);
			ZEPHIR_CPY_WRT(&extend, &_17$$10);
			ZEPHIR_CONCAT_SVSVS(&evals, "$value = ", filter, "(", &extend, ");");
		} else {
			ZEPHIR_CONCAT_SVSVS(&evals, "$value = ", filter, "($value, ", &extend, ");");
		}
	}
	zephir_read_static_property_ce(&_20, leevel_http_bag_ce, SL("zephirAssign"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_20)) {
		ZEPHIR_INIT_VAR(&_21$$12);
		ZEPHIR_INIT_VAR(&_22$$12);
		ZVAL_STRING(&_22$$12, "if (! function_exists('zephir_assign')) {\n                function zephir_assign($value, $evals) {\n                    eval($evals);\n                    return $value;\n                }\n            }");
		zephir_eval_php(&_22$$12, &_21$$12, "/data/codes/queryyetsimple/leevel/http/bag.zep:384" TSRMLS_CC);
		zend_update_static_property(leevel_http_bag_ce, ZEND_STRL("zephirAssign"), &__$true);
	}
	ZEPHIR_CALL_FUNCTION(&_23, "zephir_assign", NULL, 0, value, &evals);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(value, &_23);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * 使用回调过滤值
 *
 * @param mixed $value
 * @param string $filter
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, filterValueWithCallable) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval filter;
	zval *value, value_sub, *filter_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filter);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &value, &filter_param);

	zephir_get_strval(&filter, filter_param);


	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 8, &filter, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 使用 filter_var 过滤值
 *
 * @param mixed $value
 * @param mixed $filter
 * @param array $options
 * @see http://php.net/manual/en/function.filter-var.php
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, filterValueWithFilterVar) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *value, value_sub, *filter, filter_sub, *options_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &value, &filter, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsefilterid", NULL, 0, filter);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("filter_var", NULL, 9, value, &_0, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析转换 filter_var 参数
 *
 * @param mixed $filter
 * @return int
 */
PHP_METHOD(Leevel_Http_Bag, parseFilterId) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filter, filter_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filter);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "isint", NULL, 0, filter);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_CPY_WRT(&_0, filter);
	} else {
		ZEPHIR_CALL_FUNCTION(&_0, "filter_id", NULL, 10, filter);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&_0);

}

/**
 * 判断字符串是否为数字
 *
 * @param mixed $value
 * @since bool
 */
PHP_METHOD(Leevel_Http_Bag, isInt) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_LONG) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 11, value);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("ctype_digit", NULL, 12, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回部分数组数据
 *
 * @param string $key
 * @param mixed $value
 * @param mixed  $defaults
 * @return mixed
 */
PHP_METHOD(Leevel_Http_Bag, getPartData) {

	zend_bool _1$$4;
	zval *key, key_sub, *value = NULL, value_sub, *defaults = NULL, defaults_sub, __$null, parts, item, *_0, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &defaults);

	ZEPHIR_SEPARATE_PARAM(value);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	if (Z_TYPE_P(value) != IS_ARRAY) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("."), key, LONG_MAX TSRMLS_CC);
	zephir_is_iterable(&parts, 0, "leevel/http/bag.zep", 472);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		_1$$4 = Z_TYPE_P(value) != IS_ARRAY;
		if (!(_1$$4)) {
			_1$$4 = !(zephir_array_isset(value, &item));
		}
		if (_1$$4) {
			RETVAL_ZVAL(defaults, 1, 0);
			RETURN_MM();
		}
		zephir_array_fetch(&_2$$4, value, &item, PH_NOISY | PH_READONLY, "leevel/http/bag.zep", 469 TSRMLS_CC);
		ZEPHIR_CPY_WRT(value, &_2$$4);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * 格式化键值
 *
 * @param string $key
 * @return string
 */
PHP_METHOD(Leevel_Http_Bag, normalize) {

	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	RETURN_CTOR(&key);

}

zend_object *zephir_init_properties_Leevel_Http_Bag(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("elements"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

