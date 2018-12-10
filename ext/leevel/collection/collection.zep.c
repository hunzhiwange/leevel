
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 集合
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.03
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Collection_Collection) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Collection, Collection, leevel, collection_collection, leevel_collection_collection_method_entry, 0);

	/**
	 * 元素合集
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_collection_collection_ce, SL("elements"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 验证
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(leevel_collection_collection_ce, SL("valid"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 类型
	 *
	 * @var mixed
	 */
	zend_declare_property_null(leevel_collection_collection_ce, SL("type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的动态扩展
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_collection_collection_ce, SL("macro"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	leevel_collection_collection_ce->create_object = zephir_init_properties_Leevel_Collection_Collection;

	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, leevel_support_imacro_ce);
	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, leevel_support_iarray_ce);
	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, leevel_support_ijson_ce);
	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, zend_ce_aggregate);
	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, spl_ce_Countable);
	zend_class_implements(leevel_collection_collection_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param mixed $elements
 * @param array $type
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, __construct) {

	zend_string *_4$$4;
	zend_ulong _3$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type;
	zval *elements = NULL, elements_sub, *type_param = NULL, key, value, _0, _1, *_2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &elements, &type_param);

	if (!elements) {
		elements = &elements_sub;
		ZEPHIR_INIT_VAR(elements);
		array_init(elements);
	} else {
		ZEPHIR_SEPARATE_PARAM(elements);
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		array_init(&type);
	} else {
		zephir_get_arrval(&type, type_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&type))) {
		zephir_update_property_zval(this_ptr, SL("type"), &type);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getarrayelements", NULL, 0, elements);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(elements, &_0);
	zephir_read_property(&_1, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_is_iterable(elements, 0, "leevel/collection/collection.zep", 94);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(elements), _3$$4, _4$$4, _2$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _4$$4);
			} else {
				ZVAL_LONG(&key, _3$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _2$$4);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", &_5, 0, &key, &value);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		zephir_update_property_zval(this_ptr, SL("elements"), elements);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建一个集合
 *
 * @param mixed $elements
 * @param mixed $type
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, make) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements = NULL, elements_sub, *type = NULL, type_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &elements, &type);

	if (!elements) {
		elements = &elements_sub;
		ZEPHIR_INIT_VAR(elements);
		array_init(elements);
	}
	if (!type) {
		type = &type_sub;
		type = &__$null;
	}


	object_init_ex(return_value, leevel_collection_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 92, elements, type);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 当前元素
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, current) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("current", NULL, 43, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 当前 key
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, key) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_FUNCTION("key", NULL, 42, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 下一个元素
 *
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, next) {

	zval __$true, __$false, next, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&next);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(&next, "next", NULL, 93, &_0);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&next)) {
		zephir_update_property_zval(this_ptr, SL("valid"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("valid"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 指针重置
 *
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, rewind) {

	zval __$true, __$false, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 84, &_0);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, SL("valid"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("valid"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 验证
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Collection_Collection, valid) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "valid");

}

/**
 * 实现 IteratorAggregate::getIterator.
 *
 * @return \ArrayIterator
 */
PHP_METHOD(Leevel_Collection_Collection, getIterator) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, zephir_get_internal_ce(SL("arrayiterator")));
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 10, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetExists
 *
 * @param mixed $index
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, offsetExists) {

	zval *index, index_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &index);



	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, index));

}

/**
 * 实现 ArrayAccess::offsetGet
 *
 * @param mixed $index
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, offsetGet) {

	zval *index, index_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index);



	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, index)) {
		zephir_read_property(&_2, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, index, PH_NOISY, "leevel/collection/collection.zep", 194 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 实现 ArrayAccess::offsetSet
 *
 * @param mixed $index
 * @param mixed $newval
 */
PHP_METHOD(Leevel_Collection_Collection, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *index, index_sub, *newval, newval_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&newval_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index, &newval);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktype", NULL, 0, newval);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("elements"), index, newval TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * 实现 ArrayAccess::offsetUnset
 *
 * @param mixed $index
 */
PHP_METHOD(Leevel_Collection_Collection, offsetUnset) {

	zval *index, index_sub, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&index_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	zephir_fetch_params(0, 1, 0, &index);



	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, index)) {
		zephir_read_property(&_1$$3, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, index, PH_SEPARATE);
	}

}

/**
 * 统计元素数量 count($obj)
 *
 * @return int
 */
PHP_METHOD(Leevel_Collection_Collection, count) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG(zephir_fast_count_int(&_0 TSRMLS_CC));

}

/**
 * 返回所有元素
 *
 * @return array
 */
PHP_METHOD(Leevel_Collection_Collection, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "elements");

}

/**
 * 对象转数组
 *
 * @return array
 */
PHP_METHOD(Leevel_Collection_Collection, toArray) {

	zend_bool _4$$3;
	zend_string *_3;
	zend_ulong _2;
	zval result;
	zval key, value, _0, *_1, _5$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "leevel/collection/collection.zep", 259);
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
		_4$$3 = Z_TYPE_P(&value) == IS_OBJECT;
		if (_4$$3) {
			_4$$3 = zephir_instance_of_ev(&value, leevel_support_iarray_ce TSRMLS_CC);
		}
		if (_4$$3) {
			ZEPHIR_CALL_METHOD(&_5$$4, &value, "toarray", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&result, &key, &_5$$4, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&result);

}

/**
 * 实现 JsonSerializable::jsonSerialize
 *
 * @return array
 */
PHP_METHOD(Leevel_Collection_Collection, jsonSerialize) {

	zend_string *_3;
	zend_ulong _2;
	zval result;
	zval __$true, key, value, _0, *_1, _4$$5, _5$$6, _6$$6, _7$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "leevel/collection/collection.zep", 288);
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
		if (Z_TYPE_P(&value) == IS_OBJECT) {
			if (zephir_is_instance_of(&value, SL("JsonSerializable") TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_4$$5, &value, "jsonserialize", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_4$$5, PH_COPY | PH_SEPARATE);
			} else if (zephir_instance_of_ev(&value, leevel_support_ijson_ce TSRMLS_CC)) {
				ZEPHIR_INIT_NVAR(&_5$$6);
				ZEPHIR_CALL_METHOD(&_6$$6, &value, "tojson", NULL, 0);
				zephir_check_call_status();
				zephir_json_decode(&_5$$6, &_6$$6, zephir_get_intval(&__$true) );
				zephir_array_update_zval(&result, &key, &_5$$6, PH_COPY | PH_SEPARATE);
			} else if (zephir_instance_of_ev(&value, leevel_support_iarray_ce TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(&_7$$7, &value, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&result, &key, &_7$$7, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
			}
		} else {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&result);

}

/**
 * 对象转 JSON
 *
 * @param integer $option
 * @return string
 */
PHP_METHOD(Leevel_Collection_Collection, toJson) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option = NULL, option_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option);

	if (!option) {
		option = &option_sub;
		ZEPHIR_CPY_WRT(option, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(option);
	}


	if (Z_TYPE_P(option) == IS_NULL) {
		ZEPHIR_INIT_NVAR(option);
		ZVAL_LONG(option, 256);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "jsonserialize", NULL, 0);
	zephir_check_call_status();
	zephir_json_encode(return_value, &_0, zephir_get_intval(option) );
	RETURN_MM();

}

/**
 * __toString 魔术方法
 *
 * @return string
 */
PHP_METHOD(Leevel_Collection_Collection, __toString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "tojson", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * each
 *
 * @param \Closure $callback
 * @return $this
 */
PHP_METHOD(Leevel_Collection_Collection, each) {

	zend_string *_3;
	zend_ulong _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *callback, callback_sub, key, item, _0, *_1, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &callback);



	if (!(zephir_is_callable(callback TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Each need a callback.", "leevel/collection/collection.zep", 327);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "leevel/collection/collection.zep", 336);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&key, _3);
		} else {
			ZVAL_LONG(&key, _2);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_ZVAL_FUNCTION(&_4$$4, callback, NULL, 0, &item, &key);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_4$$4)) {
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * 注册一个扩展
 *
 * @param string $name
 * @param callable $macro
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, macro) {

	zval *name_param = NULL, *macro, macro_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&macro_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &macro);

	zephir_get_strval(&name, name_param);


	zephir_update_static_property_array_multi_ce(leevel_collection_collection_ce, SL("macro"), macro TSRMLS_CC, SL("z"), 1, &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断一个扩展是否注册
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Leevel_Collection_Collection, hasMacro) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_static_property_ce(&_0, leevel_collection_collection_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * __callStatic 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, callStaticMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _3, _4, _5, _1$$3, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, leevel_collection_collection_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "leevel/collection/collection.zep", 375 TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 1, &_4, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 2, &_5);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_3, "leevel/collection/collection.zep", 378 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * __call 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, callMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _4, _5, _6, _1$$3, _2$$3, _3$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, leevel_collection_collection_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "leevel/collection/collection.zep", 394 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_3$$3, &_2$$3, "bindto", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_3$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 1, &_5, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 2, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "leevel/collection/collection.zep", 397 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 验证类型
 *
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, checkType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value, value_sub, _0, _1, _3, _4, _5, _6, _7, _8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	zephir_read_property(&_0, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_3, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_1, leevel_support_type_ce, "these", &_2, 0, value, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, spl_ce_InvalidArgumentException);
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_join_str(&_5, SL(","), &_6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "Collection type %s validation failed.");
	ZEPHIR_CALL_FUNCTION(&_8, "sprintf", NULL, 1, &_7, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 25, &_8);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "leevel/collection/collection.zep", 418 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 转换数据到数组
 *
 * @param mixed $elements
 * @return array
 */
PHP_METHOD(Leevel_Collection_Collection, getArrayElements) {

	zend_bool _0, _1, _2, _3, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *elements, elements_sub, __$true, _4$$6, _6$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elements_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_6$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &elements);



	_0 = Z_TYPE_P(elements) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(elements, leevel_collection_collection_ce TSRMLS_CC);
	}
	_1 = Z_TYPE_P(elements) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(elements, leevel_support_iarray_ce TSRMLS_CC);
	}
	_2 = Z_TYPE_P(elements) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(elements, leevel_support_ijson_ce TSRMLS_CC);
	}
	_3 = Z_TYPE_P(elements) == IS_OBJECT;
	if (_3) {
		_3 = zephir_is_instance_of(elements, SL("JsonSerializable") TSRMLS_CC);
	}
	if (Z_TYPE_P(elements) == IS_ARRAY) {
		RETVAL_ZVAL(elements, 1, 0);
		RETURN_MM();
	} else if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(elements, "all", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(elements, "toarray", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else if (_2) {
		ZEPHIR_CALL_METHOD(&_4$$6, elements, "tojson", NULL, 0);
		zephir_check_call_status();
		zephir_json_decode(return_value, &_4$$6, zephir_get_intval(&__$true) );
		RETURN_MM();
	} else if (_3) {
		ZEPHIR_RETURN_CALL_METHOD(elements, "jsonserialize", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	_5 = Z_TYPE_P(elements) == IS_OBJECT;
	if (_5) {
		_5 = zephir_instance_of_ev(elements, zend_standard_class_def TSRMLS_CC);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_6$$8);
		zephir_json_encode(&_6$$8, elements, 0 );
		zephir_json_decode(return_value, &_6$$8, zephir_get_intval(&__$true) );
		RETURN_MM();
	}
	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, elements);
	RETURN_MM();

}

/**
 * __get 魔术方法
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, __get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "offsetget", NULL, 0, &key);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * __set 魔术方法
 *
 * @param string $key
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Collection_Collection, __set) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "offsetset", NULL, 0, &key, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * __callStatic 魔术方法
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_RETURN_CALL_SELF("callstaticmacro", NULL, 0, &method, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * __call 魔术方法
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Collection_Collection, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callmacro", NULL, 0, &method, &args);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Collection_Collection(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("type"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("type"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("elements"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("elements"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

void zephir_init_static_properties_Leevel_Collection_Collection(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(leevel_collection_collection_ce, ZEND_STRL("macro"), &_0);
	ZEPHIR_MM_RESTORE();

}

