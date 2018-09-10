
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * 实现类的静态访问门面
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.12.23
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Support_Facade) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Support, Facade, leevel, support_facade, leevel_support_facade_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 项目容器
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_support_facade_ce, SL("container"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 注入容器实例
	 *
	 * @var object
	 */
	zend_declare_property_null(leevel_support_facade_ce, SL("instances"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Support_Facade, __callStatic) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, instance, callback, _0$$3, _1$$3, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&instance, "facades", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&callback);
	zephir_create_array(&callback, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&callback, &instance);
	zephir_array_fast_append(&callback, &method);
	if (!(zephir_is_callable(&callback TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, spl_ce_BadMethodCallException);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Method %s is not exits.");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 1, &_1$$3, &method);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 2, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "leevel/support/facade.zep", 68 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &callback, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 获取注册容器的实例
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Support_Facade, facades) {

	zval unique, instance, _0, _1, _2, _3, _4$$4, _5$$4, _6$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unique);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&unique, "name", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&instance);
	zephir_read_static_property_ce(&_0, leevel_support_facade_ce, SL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&instance, &_0, &unique, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&instance);
	}
	ZEPHIR_CALL_SELF(&_1, "container", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "make", NULL, 0, &unique);
	zephir_check_call_status();
	zephir_update_static_property_array_multi_ce(leevel_support_facade_ce, SL("instances"), &_2 TSRMLS_CC, SL("z"), 1, &unique);
	zephir_read_static_property_ce(&_3, leevel_support_facade_ce, SL("instances"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_NVAR(&instance);
	zephir_array_fetch(&instance, &_3, &unique, PH_NOISY, "leevel/support/facade.zep", 90 TSRMLS_CC);
	if (Z_TYPE_P(&instance) != IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "Services %s was not found in the IOC container.");
		ZEPHIR_CALL_FUNCTION(&_6$$4, "sprintf", NULL, 1, &_5$$4, &unique);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 3, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "leevel/support/facade.zep", 98 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&instance);

}

/**
 * 删除实例.
 *
 * @param null|string $name
 */
PHP_METHOD(Leevel_Support_Facade, remove) {

	zval *name = NULL, name_sub, __$null, _0$$3, _1, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	if (Z_TYPE_P(name) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		array_init(&_0$$3);
		zend_update_static_property(leevel_support_facade_ce, ZEND_STRL("instances"), &_0$$3);
		RETURN_MM_NULL();
	}
	zephir_read_static_property_ce(&_1, leevel_support_facade_ce, SL("instances"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		zephir_read_static_property_ce(&_2$$4, leevel_support_facade_ce, SL("instances"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$4, name, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回服务容器
 *
 * @return \Leevel\Di\IContainer
 */
PHP_METHOD(Leevel_Support_Facade, container) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, leevel_support_facade_ce, SL("container"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * 设置服务容器
 *
 * @param null|\Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Support_Facade, setContainer) {

	zval *container = NULL, container_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &container);

	if (!container) {
		container = &container_sub;
		container = &__$null;
	}


	zend_update_static_property(leevel_support_facade_ce, ZEND_STRL("container"), container);

}

/**
 * 门面名字
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Facade, name) {

	zval *this_ptr = getThis();


	RETURN_STRING("");

}

void zephir_init_static_properties_Leevel_Support_Facade(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(leevel_support_facade_ce, ZEND_STRL("instances"), &_0);
	ZEPHIR_MM_RESTORE();

}

