
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * 配置管理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Option_Option) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Option, Option, leevel, option_option, leevel_option_option_method_entry, 0);

	/**
	 * 配置数据
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_option_option_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_option_option_ce->create_object = zephir_init_properties_Leevel_Option_Option;
	/**
	 * 默认命名空间
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_option_option_ce, SL("DEFAUTL_NAMESPACE"), "app");

	zend_class_implements(leevel_option_option_ce TSRMLS_CC, 1, leevel_option_ioption_ce);
	zend_class_implements(leevel_option_option_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param array $option
 * @return void
 */
PHP_METHOD(Leevel_Option_Option, __construct) {

	zval *option_param = NULL;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	zephir_update_property_zval(this_ptr, SL("option"), &option);
	ZEPHIR_MM_RESTORE();

}

/**
 * 是否存在配置
 *
 * @param string $name 配置键值
 * @return string
 */
PHP_METHOD(Leevel_Option_Option, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, tempname, names, namespaces, parts, part, option, _1, _2, _5, _6, *_7, _0$$3, _3$$4, _4$$4, _8$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tempname);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "app\\");
	} else {
		zephir_get_strval(&name, name_param);
	}


	ZEPHIR_CALL_METHOD(&names, this_ptr, "parsenamespace", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&namespaces);
	zephir_array_fetch_long(&namespaces, &names, 0, PH_NOISY, "leevel/option/option.zep", 68 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&tempname);
	zephir_array_fetch_long(&tempname, &names, 1, PH_NOISY, "leevel/option/option.zep", 69 TSRMLS_CC);
	zephir_get_strval(&name, &tempname);
	if (ZEPHIR_IS_STRING(&name, "*")) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_BOOL(zephir_array_isset(&_0$$3, &namespaces));
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &name, &_1, 0 );
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 77 TSRMLS_CC);
		RETURN_MM_BOOL(zephir_array_key_exists(&_4$$4, &name TSRMLS_CC));
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
	zephir_read_property(&_5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 81 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&option, &_6);
	zephir_is_iterable(&parts, 0, "leevel/option/option.zep", 89);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _7)
	{
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _7);
		if (!(zephir_array_isset(&option, &part))) {
			RETURN_MM_BOOL(0);
		}
		zephir_array_fetch(&_8$$5, &option, &part, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 86 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&option, &_8$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	RETURN_MM_BOOL(1);

}

/**
 * 获取配置
 *
 * @param string $name 配置键值
 * @param mixed $defaults 配置默认值
 * @return string
 */
PHP_METHOD(Leevel_Option_Option, get) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *defaults = NULL, defaults_sub, __$null, tempname, names, namespaces, parts, part, option, _2, _3, _9, _10, *_11, _0$$3, _1$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _12$$5;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tempname);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_12$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &name_param, &defaults);

	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "app\\");
	} else {
		zephir_get_strval(&name, name_param);
	}
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_CALL_METHOD(&names, this_ptr, "parsenamespace", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&namespaces);
	zephir_array_fetch_long(&namespaces, &names, 0, PH_NOISY, "leevel/option/option.zep", 104 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&tempname);
	zephir_array_fetch_long(&tempname, &names, 1, PH_NOISY, "leevel/option/option.zep", 105 TSRMLS_CC);
	zephir_get_strval(&name, &tempname);
	if (ZEPHIR_IS_STRING(&name, "*")) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_1$$3, &_0$$3, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 109 TSRMLS_CC);
		RETURN_CTOR(&_1$$3);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, ".");
	ZEPHIR_INIT_VAR(&_3);
	zephir_fast_strpos(&_3, &name, &_2, 0 );
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_6$$4, &_5$$4, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 113 TSRMLS_CC);
		if (zephir_array_key_exists(&_6$$4, &name TSRMLS_CC)) {
			zephir_read_property(&_7$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$4, &_7$$4, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 113 TSRMLS_CC);
			zephir_array_fetch(&_4$$4, &_8$$4, &name, PH_NOISY, "leevel/option/option.zep", 113 TSRMLS_CC);
		} else {
			ZEPHIR_CPY_WRT(&_4$$4, defaults);
		}
		RETURN_CCTOR(&_4$$4);
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
	zephir_read_property(&_9, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_10, &_9, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 117 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&option, &_10);
	zephir_is_iterable(&parts, 0, "leevel/option/option.zep", 125);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&parts), _11)
	{
		ZEPHIR_INIT_NVAR(&part);
		ZVAL_COPY(&part, _11);
		if (!(zephir_array_isset(&option, &part))) {
			RETVAL_ZVAL(defaults, 1, 0);
			RETURN_MM();
		}
		zephir_array_fetch(&_12$$5, &option, &part, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 122 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&option, &_12$$5);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&part);
	RETURN_CCTOR(&option);

}

/**
 * 返回所有配置
 *
 * @return array
 */
PHP_METHOD(Leevel_Option_Option, all) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "option");

}

/**
 * 设置配置
 *
 * @param mixed $name 配置键值
 * @param mixed $value 配置值
 */
PHP_METHOD(Leevel_Option_Option, set) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, *value = NULL, value_sub, __$null, key, values, names, namespaces, parts, option, *_0$$3, _4$$5, _5$$5, _6$$8, _7$$8, _8$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &value);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	if (Z_TYPE_P(name) == IS_ARRAY) {
		zephir_is_iterable(name, 0, "leevel/option/option.zep", 152);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(name), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$3);
			} else {
				ZVAL_LONG(&key, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&values);
			ZVAL_COPY(&values, _0$$3);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_3, 130, &key, &values);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&values);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		ZEPHIR_CALL_METHOD(&names, this_ptr, "parsenamespace", NULL, 0, name);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&namespaces);
		zephir_array_fetch_long(&namespaces, &names, 0, PH_NOISY, "leevel/option/option.zep", 154 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(name);
		zephir_array_fetch_long(name, &names, 1, PH_NOISY, "leevel/option/option.zep", 155 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(name, "*")) {
			zephir_update_property_array(this_ptr, SL("option"), &namespaces, value TSRMLS_CC);
			RETURN_MM_NULL();
		}
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, ".");
		ZEPHIR_INIT_VAR(&_5$$5);
		zephir_fast_strpos(&_5$$5, name, &_4$$5, 0 );
		if (!(zephir_is_true(&_5$$5))) {
			zephir_update_property_array_multi(this_ptr, SL("option"), value TSRMLS_CC, SL("zz"), 2, &namespaces, name);
		} else {
			ZEPHIR_INIT_VAR(&parts);
			zephir_fast_explode_str(&parts, SL("."), name, LONG_MAX TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&option, this_ptr, "setrecursion", NULL, 0, &parts, value);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_6$$8);
			zephir_read_property(&_7$$8, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_8$$8, &_7$$8, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 167 TSRMLS_CC);
			zephir_fast_array_merge(&_6$$8, &_8$$8, &option TSRMLS_CC);
			zephir_update_property_array(this_ptr, SL("option"), &namespaces, &_6$$8 TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 删除配置
 *
 * @param string $name 配置键值
 * @return string
 */
PHP_METHOD(Leevel_Option_Option, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name, *name_param = NULL, tempname, names, namespaces, parts, option, tmpDelete, _1, _2, _0$$3, _3$$4, _4$$4, _5$$5, _6$$6, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&tempname);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&tmpDelete);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_METHOD(&names, this_ptr, "parsenamespace", NULL, 0, &name);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&namespaces);
	zephir_array_fetch_long(&namespaces, &names, 0, PH_NOISY, "leevel/option/option.zep", 183 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&tempname);
	zephir_array_fetch_long(&tempname, &names, 1, PH_NOISY, "leevel/option/option.zep", 184 TSRMLS_CC);
	ZEPHIR_CPY_WRT(&name, &tempname);
	if (ZEPHIR_IS_STRING(&name, "*")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_update_property_array(this_ptr, SL("option"), &namespaces, &_0$$3 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, ".");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &name, &_1, 0 );
	if (!(zephir_is_true(&_2))) {
		zephir_read_property(&_3$$4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_4$$4, &_3$$4, &namespaces, PH_READONLY, "leevel/option/option.zep", 193 TSRMLS_CC);
		if (zephir_array_isset(&_4$$4, &name)) {
			zephir_read_property(&_5$$5, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_OBS_VAR(&tmpDelete);
			zephir_array_fetch(&tmpDelete, &_5$$5, &namespaces, PH_NOISY, "leevel/option/option.zep", 194 TSRMLS_CC);
			zephir_array_unset(&tmpDelete, &name, PH_SEPARATE);
			zephir_update_property_array(this_ptr, SL("option"), &namespaces, &tmpDelete TSRMLS_CC);
		}
	} else {
		ZEPHIR_INIT_VAR(&parts);
		zephir_fast_explode_str(&parts, SL("."), &name, LONG_MAX TSRMLS_CC);
		zephir_read_property(&_6$$6, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7$$6, &_6$$6, &namespaces, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 200 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&option, this_ptr, "deleterecursion", NULL, 0, &parts, &_7$$6);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("option"), &namespaces, &option TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化配置参数
 *
 * @param mixed $namespaces
 * @return boolean
 */
PHP_METHOD(Leevel_Option_Option, reset) {

	zval *namespaces = NULL, namespaces_sub, __$null, _0$$4, _1$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &namespaces);

	if (!namespaces) {
		namespaces = &namespaces_sub;
		namespaces = &__$null;
	}


	if (Z_TYPE_P(namespaces) == IS_ARRAY) {
		zephir_update_property_zval(this_ptr, SL("option"), namespaces);
	} else if (Z_TYPE_P(namespaces) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$4);
		array_init(&_0$$4);
		zephir_update_property_array(this_ptr, SL("option"), namespaces, &_0$$4 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_VAR(&_1$$5);
		array_init(&_1$$5);
		zephir_update_property_zval(this_ptr, SL("option"), &_1$$5);
	}
	RETURN_MM_BOOL(1);

}

/**
 * 判断配置是否存在
 *
 * @param string $offset
 * @return bool
 */
PHP_METHOD(Leevel_Option_Option, offsetExists) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, &offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetGet
 *
 * @param string $offset
 * @return mixed
 */
PHP_METHOD(Leevel_Option_Option, offsetGet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, &offset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetSet
 *
 * @param string $offset
 * @param mixed $value
 * @return void
 */
PHP_METHOD(Leevel_Option_Option, offsetSet) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL, *value, value_sub;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset_param, &value);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, &offset, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 实现 ArrayAccess::offsetUnset
 *
 * @param string $offset
 * @return void
 */
PHP_METHOD(Leevel_Option_Option, offsetUnset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset_param = NULL;
	zval offset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset_param);

	zephir_get_strval(&offset, offset_param);


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "delete", NULL, 0, &offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 递归设置配置数据
 *
 * @param array $part
 * @param mixed $value
 * @return array
 */
PHP_METHOD(Leevel_Option_Option, setRecursion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *part_param = NULL, *value = NULL, value_sub, __$null, result, item, _0$$3, _1$$4;
	zval part;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &part_param, &value);

	ZEPHIR_OBS_COPY_OR_DUP(&part, part_param);
	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_MAKE_REF(&part);
	ZEPHIR_CALL_FUNCTION(&item, "array_shift", NULL, 6, &part);
	ZEPHIR_UNREF(&part);
	zephir_check_call_status();
	if (!(zephir_array_isset(&result, &item))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zephir_array_update_zval(&result, &item, &_0$$3, PH_COPY | PH_SEPARATE);
	}
	if (!(ZEPHIR_IS_EMPTY(&part))) {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "setrecursion", NULL, 131, &part, value);
		zephir_check_call_status();
		zephir_array_update_zval(&result, &item, &_1$$4, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_zval(&result, &item, value, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&result);

}

/**
 * 递归删除配置数据
 *
 * @param array $part
 * @return array
 */
PHP_METHOD(Leevel_Option_Option, deleteRecursion) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *part_param = NULL, *result_param = NULL, item, _0$$4, _1$$4;
	zval part, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &part_param, &result_param);

	ZEPHIR_OBS_COPY_OR_DUP(&part, part_param);
	ZEPHIR_OBS_COPY_OR_DUP(&result, result_param);


	ZEPHIR_MAKE_REF(&part);
	ZEPHIR_CALL_FUNCTION(&item, "array_shift", NULL, 6, &part);
	ZEPHIR_UNREF(&part);
	zephir_check_call_status();
	if (!(zephir_array_isset(&result, &item))) {
		RETURN_CTOR(&result);
	}
	if (!(ZEPHIR_IS_EMPTY(&part))) {
		zephir_array_fetch(&_1$$4, &result, &item, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 310 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_0$$4, this_ptr, "deleterecursion", NULL, 132, &part, &_1$$4);
		zephir_check_call_status();
		zephir_array_update_zval(&result, &item, &_0$$4, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_array_isset(&result, &item)) {
			zephir_array_unset(&result, &item, PH_SEPARATE);
		}
	}
	RETURN_CTOR(&result);

}

/**
 * 分析命名空间
 *
 * @param string $name
 * @return array
 */
PHP_METHOD(Leevel_Option_Option, parseNamespace) {

	zval *name_param = NULL, names, tempname, namespaces, _0, _1, _4, _2$$3, _3$$4, _5$$6;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&names);
	ZVAL_UNDEF(&tempname);
	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &name, &_0, 0 );
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&names);
		zephir_fast_explode_str(&names, SL("\\"), &name, LONG_MAX TSRMLS_CC);
		zephir_array_fetch_long(&_2$$3, &names, 1, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 332 TSRMLS_CC);
		if (ZEPHIR_IS_EMPTY(&_2$$3)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "*");
			zephir_array_update_long(&names, 1, &_3$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
		}
		zephir_array_fetch_long(&tempname, &names, 1, PH_NOISY | PH_READONLY, "leevel/option/option.zep", 335 TSRMLS_CC);
		zephir_get_strval(&name, &tempname);
		ZEPHIR_OBS_VAR(&namespaces);
		zephir_array_fetch_long(&namespaces, &names, 0, PH_NOISY, "leevel/option/option.zep", 337 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&namespaces);
		ZVAL_STRING(&namespaces, "app");
	}
	zephir_read_property(&_4, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_4, &namespaces))) {
		ZEPHIR_INIT_VAR(&_5$$6);
		array_init(&_5$$6);
		zephir_update_property_array(this_ptr, SL("option"), &namespaces, &_5$$6 TSRMLS_CC);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &namespaces);
	zephir_array_fast_append(return_value, &name);
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Option_Option(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

