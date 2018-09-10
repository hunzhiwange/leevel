
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * throttler 服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.28
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Throttler_Provider_Register) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Throttler\\Provider, Register, leevel, throttler_provider_register, leevel_di_provider_ce, leevel_throttler_provider_register_method_entry, 0);

	return SUCCESS;

}

/**
 * 创建一个服务容器提供者实例
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_CALL_PARENT(NULL, leevel_throttler_provider_register_ce, getThis(), "__construct", &_0, 0, container);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "throttler", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "middleware", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者
 *
 * @return array
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, providers) {

	zval _1;
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Throttler\\Throttler");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Throttler\\IThrottler");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_update_string(return_value, SL("throttler"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Throttler\\Middleware\\Throttler");
	zephir_array_fast_append(return_value, &_1);
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, isDeferred) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * 注册 throttler 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, throttler) {

	zval _3;
	zend_class_entry *_2;
	zval _0, _1, _4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	_2 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "throttlerClosure");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_CALL_CE_STATIC(&_1, _2, "fromcallable", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "throttler");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_4, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 创建 throttler 服务闭包
 *
 * @param \Leevel\Di\IContainer $container
 * @return \Leevel\Throttler\Throttler
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, throttlerClosure) {

	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, throttler, _1, _2, _3, _4, _5, _6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&throttler);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&throttler);
	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Throttler\\Throttler"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&throttler, _0);
	if (zephir_has_constructor(&throttler TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "caches");
		ZEPHIR_CALL_METHOD(&_1, container, "make", NULL, 0, &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "option");
		ZEPHIR_CALL_METHOD(&_4, container, "make", NULL, 0, &_2);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "throttler\\driver");
		ZEPHIR_CALL_METHOD(&_5, &_4, "get", NULL, 0, &_2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3, &_1, "connect", NULL, 0, &_5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &throttler, "__construct", NULL, 0, &_3);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "request");
	ZEPHIR_CALL_METHOD(&_6, container, "make", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &throttler, "setrequest", NULL, 0, &_6);
	zephir_check_call_status();
	RETURN_CCTOR(&throttler);

}

/**
 * 注册 middleware 服务
 *
 * @return void
 */
PHP_METHOD(Leevel_Throttler_Provider_Register, middleware) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Throttler\\Middleware\\Throttler");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

