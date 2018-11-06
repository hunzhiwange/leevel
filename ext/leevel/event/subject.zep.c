
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/main.h"
#include "kernel/operators.h"
#include "Zend/zend_closures.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


/**
 * 观察者目标角色 subject
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.23
 * @link http://php.net/manual/zh/class.splsubject.php
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Event_Subject) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Event, Subject, leevel, event_subject, leevel_event_subject_method_entry, 0);

	/**
	 * 容器
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_event_subject_ce, SL("container"), ZEND_ACC_PUBLIC TSRMLS_CC);

	/**
	 * 观察者角色 observer
	 *
	 * @var \SplObjectStorage(\SplObserver)
	 */
	zend_declare_property_null(leevel_event_subject_ce, SL("observers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 通知附加参数
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_event_subject_ce, SL("notifyArgs"), ZEND_ACC_PUBLIC TSRMLS_CC);

	leevel_event_subject_ce->create_object = zephir_init_properties_Leevel_Event_Subject;

	zend_class_implements(leevel_event_subject_ce TSRMLS_CC, 1, leevel_event_isubject_ce);
	zend_class_implements(leevel_event_subject_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("splsubject")));
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Event_Subject, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *container, container_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &container);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("observers"), &_0);
	zephir_update_property_zval(this_ptr, SL("container"), container);
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Event_Subject, attach) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *observer, observer_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &observer);



	zephir_read_property(&_0, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "attach", NULL, 0, observer);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Event_Subject, detach) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *observer, observer_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &observer);



	zephir_read_property(&_0, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "detach", NULL, 0, observer);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Event_Subject, notify) {

	zval _0, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_get_args(&_0);
	zephir_update_property_zval(this_ptr, SL("notifyArgs"), &_0);
	zephir_read_property(&_1, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		zephir_read_property(&_2, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3, &_2, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_3))) {
			break;
		}
		zephir_read_property(&_4$$3, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "current", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "update", NULL, 0, this_ptr);
		zephir_check_call_status();
		zephir_read_property(&_6$$3, this_ptr, SL("observers"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "next", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 添加一个观察者角色
 *
 * @param \SplObserver|string|\Closure $observer
 * @return $this
 */
PHP_METHOD(Leevel_Event_Subject, register) {

	zend_class_entry *_16$$7;
	zval _9$$7, _17$$7;
	zend_bool _0, _8$$4;
	zephir_fcall_cache_entry *_1 = NULL, *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *observer = NULL, observer_sub, _2$$5, _3$$5, _4$$6, _5$$6, _6$$6, _10$$7, _15$$7, _11$$8, _12$$8, _13$$8, _14$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&observer_sub);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_17$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &observer);

	ZEPHIR_SEPARATE_PARAM(observer);


	_0 = Z_TYPE_P(observer) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(observer, zend_ce_closure TSRMLS_CC);
	}
	if (_0) {
		ZEPHIR_INIT_NVAR(observer);
		object_init_ex(observer, leevel_event_observer_ce);
		ZEPHIR_CALL_METHOD(NULL, observer, "__construct", &_1, 101, observer);
		zephir_check_call_status();
	} else {
		if (Z_TYPE_P(observer) == IS_STRING) {
			zephir_read_property(&_2$$5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_3$$5, &_2$$5, "make", NULL, 0, observer);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(observer, &_3$$5);
			if (Z_TYPE_P(observer) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_4$$6);
				object_init_ex(&_4$$6, spl_ce_InvalidArgumentException);
				ZEPHIR_INIT_VAR(&_5$$6);
				ZVAL_STRING(&_5$$6, "Observer `%s` is invalid.");
				ZEPHIR_CALL_FUNCTION(&_6$$6, "sprintf", &_7, 1, &_5$$6, observer);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_4$$6, "__construct", NULL, 21, &_6$$6);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$6, "leevel/event/subject.zep", 117 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_8$$4 = Z_TYPE_P(observer) == IS_OBJECT;
		if (_8$$4) {
			_8$$4 = zephir_is_instance_of(observer, SL("SplObserver") TSRMLS_CC);
		}
		if (!(_8$$4)) {
			ZEPHIR_INIT_VAR(&_9$$7);
			zephir_create_array(&_9$$7, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_9$$7, observer);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "handle");
			zephir_array_fast_append(&_9$$7, &_10$$7);
			if (!(zephir_is_callable(&_9$$7 TSRMLS_CC))) {
				ZEPHIR_INIT_VAR(&_11$$8);
				object_init_ex(&_11$$8, spl_ce_InvalidArgumentException);
				ZEPHIR_INIT_VAR(&_12$$8);
				zephir_get_class(&_12$$8, observer, 0 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_13$$8);
				ZVAL_STRING(&_13$$8, "Observer `%s` is invalid.");
				ZEPHIR_CALL_FUNCTION(&_14$$8, "sprintf", &_7, 1, &_13$$8, &_12$$8);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_11$$8, "__construct", NULL, 21, &_14$$8);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_11$$8, "leevel/event/subject.zep", 125 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_FUNCTION(NULL, "dd", NULL, 0, observer);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(observer);
			object_init_ex(observer, leevel_event_observer_ce);
			_16$$7 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
			ZEPHIR_INIT_VAR(&_17$$7);
			zephir_create_array(&_17$$7, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_17$$7, observer);
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "handle");
			zephir_array_fast_append(&_17$$7, &_10$$7);
			ZEPHIR_CALL_CE_STATIC(&_15$$7, _16$$7, "fromcallable", NULL, 0, &_17$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, observer, "__construct", &_1, 101, &_15$$7);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, observer);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_Event_Subject(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("notifyArgs"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("notifyArgs"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

