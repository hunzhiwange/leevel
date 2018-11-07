
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
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * 观察者角色 observer
 * \SplObserver 无法识别 container
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.01
 * @link http://php.net/manual/zh/class.splobserver.php
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Event_Observer) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Event, Observer, leevel, event_observer, leevel_event_observer_method_entry, 0);

	/**
	 * 观察者目标角色 subject
	 *
	 * @var \SplSubject
	 */
	zend_declare_property_null(leevel_event_observer_ce, SL("subject"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 观察者实现.
	 *
	 * @var \Closure
	 */
	zend_declare_property_null(leevel_event_observer_ce, SL("handle"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(leevel_event_observer_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("splobserver")));
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Closure $handle
 * @return void
 */
PHP_METHOD(Leevel_Event_Observer, __construct) {

	zval *handle = NULL, handle_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handle_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &handle);

	if (!handle) {
		handle = &handle_sub;
		handle = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("handle"), handle);

}

/**
 * 观察者实现.
 */
PHP_METHOD(Leevel_Event_Observer, __invoke) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_args(&_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Event_Observer, update) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subject, subject_sub, handle, _0, _7, _8, _1$$3, _2$$4, _3$$6, _4$$6, _5$$6, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subject_sub);
	ZVAL_UNDEF(&handle);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subject);



	zephir_read_property(&_0, this_ptr, SL("handle"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_method_exists_ex(this_ptr, SL("handle") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&handle);
		zephir_create_array(&handle, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&handle, this_ptr);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "handle");
		zephir_array_fast_append(&handle, &_1$$3);
	} else if (zephir_is_true(&_0)) {
		ZEPHIR_INIT_NVAR(&handle);
		zephir_create_array(&handle, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&handle, this_ptr);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "__invoke");
		zephir_array_fast_append(&handle, &_2$$4);
	} else {
		ZEPHIR_INIT_NVAR(&handle);
		ZVAL_NULL(&handle);
	}
	if (!(zephir_is_callable(&handle TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_3$$6);
		object_init_ex(&_3$$6, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_4$$6);
		zephir_get_class(&_4$$6, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$6);
		ZVAL_STRING(&_5$$6, "Observer %s must has handle method.");
		ZEPHIR_CALL_FUNCTION(&_6$$6, "sprintf", NULL, 1, &_5$$6, &_4$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_3$$6, "__construct", NULL, 25, &_6$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$6, "leevel/event/observer.zep", 86 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_7, subject, SL("container"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, subject, SL("notifyArgs"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_7, "call", NULL, 0, &handle, &_8);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

