
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"


/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Manager_Manager) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Manager, Manager, leevel, manager_manager, leevel_manager_manager_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * IOC Container
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_manager_manager_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 连接对象
	 *
	 * @var object[]
	 */
	zend_declare_property_null(leevel_manager_manager_ce, SL("connects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_manager_manager_ce->create_object = zephir_init_properties_Leevel_Manager_Manager;
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Manager_Manager, __construct) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Manager_Manager, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _0;
	zval *method_param = NULL, *args_param = NULL, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "connect", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回 IOC 容器
 *
 * @return \Leevel\Di\IContainer
 */
PHP_METHOD(Leevel_Manager_Manager, container) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * 连接 connect 并返回连接对象
 *
 * @param array|string|null $options
 * @return object
 */
PHP_METHOD(Leevel_Manager_Manager, connect) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, __$null, unique, driver, temp, _1, _4, _5, _6, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&unique);
	ZVAL_UNDEF(&driver);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_CPY_WRT(options, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	ZEPHIR_CALL_METHOD(&temp, this_ptr, "parseoptionandunique", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&temp);
	ZEPHIR_CALL_FUNCTION(options, "array_shift", &_0, 6, &temp);
	ZEPHIR_UNREF(&temp);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&temp);
	ZEPHIR_CALL_FUNCTION(&unique, "array_shift", &_0, 6, &temp);
	ZEPHIR_UNREF(&temp);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("connects"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &unique)) {
		zephir_read_property(&_2$$3, this_ptr, SL("connects"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &unique, PH_NOISY | PH_READONLY, "leevel/manager/manager.zep", 95 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	}
	if (zephir_array_isset_string(options, SL("driver"))) {
		ZEPHIR_OBS_VAR(&driver);
		zephir_array_fetch_string(&driver, options, SL("driver"), PH_NOISY, "leevel/manager/manager.zep", 99 TSRMLS_CC);
	} else {
		ZEPHIR_CALL_METHOD(&driver, this_ptr, "getdefaultdriver", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "makeconnect", NULL, 0, &driver, options);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("connects"), &unique, &_4 TSRMLS_CC);
	zephir_read_property(&_5, this_ptr, SL("connects"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_6, &_5, &unique, PH_NOISY | PH_READONLY, "leevel/manager/manager.zep", 106 TSRMLS_CC);
	RETURN_CTOR(&_6);

}

/**
 * 重新连接
 *
 * @param array|string $options
 * @return object
 */
PHP_METHOD(Leevel_Manager_Manager, reconnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "connect", NULL, 0, options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除连接
 *
 * @param array|string $options
 * @return void
 */
PHP_METHOD(Leevel_Manager_Manager, disconnect) {

	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, unique, temp, _1, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&unique);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	ZEPHIR_CALL_METHOD(&temp, this_ptr, "parseoptionandunique", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&temp);
	ZEPHIR_CALL_FUNCTION(options, "array_shift", &_0, 6, &temp);
	ZEPHIR_UNREF(&temp);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&temp);
	ZEPHIR_CALL_FUNCTION(&unique, "array_shift", &_0, 6, &temp);
	ZEPHIR_UNREF(&temp);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("connects"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &unique)) {
		zephir_read_property(&_2$$3, this_ptr, SL("connects"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, &unique, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 取回所有连接
 *
 * @return object[]
 */
PHP_METHOD(Leevel_Manager_Manager, getConnects) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "connects");

}

/**
 * 返回默认驱动
 *
 * @return string
 */
PHP_METHOD(Leevel_Manager_Manager, getDefaultDriver) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontaineroption", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置默认驱动
 *
 * @param string $name
 * @return void
 */
PHP_METHOD(Leevel_Manager_Manager, setDefaultDriver) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontaineroption", NULL, 0, &_0, &name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取容器配置值.
 *
 * @param string $name
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Manager_Manager, getContainerOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, __$null, tmp, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "normalizeoptionname", NULL, 0, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "option");
	ZEPHIR_CALL_METHOD(&_1, &_0, "make", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "get", NULL, 0, &tmp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置容器配置值.
 *
 * @param string $name
 * @param mixed  $value
 */
PHP_METHOD(Leevel_Manager_Manager, setContainerOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value, value_sub, tmp, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &value);



	ZEPHIR_CALL_METHOD(&tmp, this_ptr, "normalizeoptionname", NULL, 0, name);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "option");
	ZEPHIR_CALL_METHOD(&_1, &_0, "make", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &tmp, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Leevel_Manager_Manager, normalizeOptionNamespace) {

}

/**
 * 创建连接对象
 *
 * @param object $connect
 * @return object
 */
PHP_METHOD(Leevel_Manager_Manager, createConnect) {

}

/**
 * 取得连接名字
 *
 * @param string $name
 * @return string
 */
PHP_METHOD(Leevel_Manager_Manager, normalizeOptionName) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeoptionnamespace", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "\\", name);
	RETURN_MM();

}

/**
 * 创建连接
 *
 * @param string $connect
 * @param array $options
 * @return object
 */
PHP_METHOD(Leevel_Manager_Manager, makeConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *connect_param = NULL, *options_param = NULL, tmp, _1, _5, _2$$3, _3$$3, _4$$3;
	zval connect, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &connect_param, &options_param);

	zephir_get_strval(&connect, connect_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "connect.", &connect);
	ZEPHIR_CPY_WRT(&tmp, &_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcontaineroption", NULL, 0, &tmp);
	zephir_check_call_status();
	if (Z_TYPE_P(&_1) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Connect driver %s not exits.");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 1, &_3$$3, &connect);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 22, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "leevel/manager/manager.zep", 245 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "createconnectcommon", NULL, 0, &connect, &options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "createconnect", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建连接对象公共入口
 *
 * @param string $connect
 * @param array $options
 * @return object
 */
PHP_METHOD(Leevel_Manager_Manager, createConnectCommon) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval connect, *connect_param = NULL, *options_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &connect_param, &options_param);

	zephir_get_strval(&connect, connect_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "ucwords", NULL, 23, &connect);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "makeConnect", &_0);
	ZEPHIR_CPY_WRT(&connect, &_1);
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &connect, NULL, 0, &options);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 分析连接参数以及其唯一值
 *
 * @param array|string $options
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, parseOptionAndUnique) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, unique, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&unique);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	} else {
		ZEPHIR_SEPARATE_PARAM(options);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parseoptionparameter", NULL, 0, options);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(options, &_0);
	ZEPHIR_CALL_METHOD(&unique, this_ptr, "normalizeunique", NULL, 0, options);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, options);
	zephir_array_fast_append(return_value, &unique);
	RETURN_MM();

}

/**
 * 分析连接参数
 *
 * @param array|string $options
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, parseOptionParameter) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL, options_sub, tmp, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options_sub);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = &options_sub;
		ZEPHIR_INIT_VAR(options);
		array_init(options);
	}


	if (Z_TYPE_P(options) == IS_NULL) {
		array_init(return_value);
		RETURN_MM();
	}
	if (Z_TYPE_P(options) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_CONCAT_SV(&_0$$4, "connect.", options);
		ZEPHIR_CALL_METHOD(&tmp, this_ptr, "getcontaineroption", NULL, 0, &_0$$4);
		zephir_check_call_status();
		if (Z_TYPE_P(&tmp) != IS_ARRAY) {
			array_init(return_value);
			RETURN_MM();
		}
	} else {
		ZEPHIR_CPY_WRT(&tmp, options);
	}
	RETURN_CCTOR(&tmp);

}

/**
 * 取得唯一值
 *
 * @param array $options
 * @return string
 */
PHP_METHOD(Leevel_Manager_Manager, normalizeUnique) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_CALL_FUNCTION(&_0, "serialize", NULL, 24, &options);
	zephir_check_call_status();
	zephir_md5(return_value, &_0);
	RETURN_MM();

}

/**
 * 读取默认配置
 *
 * @param string $connect
 * @param array $extendOption
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, normalizeConnectOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval extendOption;
	zval *connect_param = NULL, *extendOption_param = NULL, _0, _1;
	zval connect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&extendOption);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &connect_param, &extendOption_param);

	zephir_get_strval(&connect, connect_param);
	if (!extendOption_param) {
		ZEPHIR_INIT_VAR(&extendOption);
		array_init(&extendOption);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&extendOption, extendOption_param);
	}


	if (1 != 1) {
		ZEPHIR_INIT_NVAR(&extendOption);
		array_init(&extendOption);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getconnectoption", NULL, 0, &connect);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getcommonoption", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("array_merge", NULL, 25, &_0, &_1, &extendOption);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 读取连接全局配置
 *
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, getCommonOption) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcontaineroption", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filtercommonoption", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 过滤全局配置
 *
 * @param array $options
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, filterCommonOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, item, _0, *_1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "defaultcommonoption", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "leevel/manager/manager.zep", 372);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		if (zephir_array_isset(&options, &item)) {
			zephir_array_unset(&options, &item, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&options);

}

/**
 * 过滤全局配置项
 *
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, defaultCommonOption) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	zephir_array_fast_append(return_value, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "connect");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * 读取连接配置
 *
 * @param string $connect
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, getConnectOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect_param = NULL;
	zval connect, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect_param);

	zephir_get_strval(&connect, connect_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "connect.", &connect);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getcontaineroption", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 清除配置 null
 *
 * @param array $options
 * @return array
 */
PHP_METHOD(Leevel_Manager_Manager, filterNullOfOption) {

	zend_string *_2;
	zend_ulong _1;
	zval *options_param = NULL, key, value, *_0;
	zval options, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&options, 0, "leevel/manager/manager.zep", 416);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&options), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		if (Z_TYPE_P(&value) != IS_NULL) {
			zephir_array_update_zval(&result, &key, &value, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CTOR(&result);

}

zend_object *zephir_init_properties_Leevel_Manager_Manager(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("connects"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("connects"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

