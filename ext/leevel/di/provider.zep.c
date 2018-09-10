
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.25
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Di_Provider) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Di, Provider, leevel, di_provider, leevel_di_provider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * IOC 容器
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_di_provider_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Di_Provider, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registeralias", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Di_Provider, register) {

}

/**
 * 注册服务别名
 *
 * @return void
 */
PHP_METHOD(Leevel_Di_Provider, registerAlias) {

	zval providers, _0, _1$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&providers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_STATIC(&_0, "isdeferred", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_STATIC(&providers, "providers", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&providers))) {
			zephir_read_property(&_1$$4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "alias", NULL, 0, &providers);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Leevel_Di_Provider, providers) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

/**
 * 是否延迟载入
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Di_Provider, isDeferred) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

/**
 * 返回 IOC 容器
 *
 * @return \Leevel\Di\IContainer
 */
PHP_METHOD(Leevel_Di_Provider, container) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Di_Provider, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _1, _2;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	if (ZEPHIR_IS_STRING(&method, "bootstrap")) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_2, "sprintf", NULL, 1, &_1, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 2, &_2);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_0, "leevel/di/provider.zep", 120 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

