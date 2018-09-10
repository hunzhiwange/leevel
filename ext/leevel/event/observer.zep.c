
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


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

	zend_class_implements(leevel_event_observer_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("splobserver")));
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @return void
 */
PHP_METHOD(Leevel_Event_Observer, __construct) {

	zval *this_ptr = getThis();



}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Event_Observer, update) {

	zval _0, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *subject, subject_sub, method, _5, _7, _1$$3, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&subject_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &subject);



	if ((zephir_method_exists_ex(this_ptr, SL("handle") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "handle");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "run");
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	zephir_array_fast_append(&_0, &method);
	if (!(zephir_is_callable(&_0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, spl_ce_RuntimeException);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_get_class(&_2$$3, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Observer %s must has run or handle method.");
		ZEPHIR_CALL_FUNCTION(&_4$$3, "sprintf", NULL, 1, &_3$$3, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 3, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "leevel/event/observer.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, subject, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_6, this_ptr);
	zephir_array_fast_append(&_6, &method);
	zephir_read_property(&_7, subject, SL("notifyArgs"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_5, "call", NULL, 0, &_6, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

