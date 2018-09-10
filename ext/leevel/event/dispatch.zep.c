
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
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * 事件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.31
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Event_Dispatch) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Event, Dispatch, leevel, event_dispatch, leevel_event_dispatch_method_entry, 0);

	/**
	 * 项目容器
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_event_dispatch_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的监听器
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_event_dispatch_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 通配符的监听器
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_event_dispatch_ce, SL("wildcards"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_event_dispatch_ce->create_object = zephir_init_properties_Leevel_Event_Dispatch;

	zend_class_implements(leevel_event_dispatch_ce TSRMLS_CC, 1, leevel_event_idispatch_ce);
	return SUCCESS;

}

/**
 * 创建一个事件解析器
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Event_Dispatch, __construct) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * 执行一个事件
 *
 * @return void
 */
PHP_METHOD(Leevel_Event_Dispatch, run) {

	zval _6$$6;
	zval event, listeners, items, params, name, *_2, _0$$4, _1$$4, _3$$6, _5$$6, _7$$6;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&items);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_NVAR(&params);
	zephir_get_args(&params);
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(&event, "array_shift", NULL, 6, &params);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	if (Z_TYPE_P(&event) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&name);
		zephir_get_class(&name, &event, 0 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&name, &event);
		zephir_read_property(&_0$$4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_1$$4, &_0$$4, "make", NULL, 0, &event);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&event, &_1$$4);
	}
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 32, &params, &event);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&listeners, this_ptr, "get", NULL, 0, &name);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&listeners)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_MAKE_REF(&listeners);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 52, &listeners);
	ZEPHIR_UNREF(&listeners);
	zephir_check_call_status();
	zephir_is_iterable(&listeners, 0, "leevel/event/dispatch.zep", 99);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&listeners), _2)
	{
		ZEPHIR_INIT_NVAR(&items);
		ZVAL_COPY(&items, _2);
		ZEPHIR_CALL_METHOD(&_3$$6, this_ptr, "makesubject", &_4, 0, &items);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&items, &_3$$6);
		ZEPHIR_INIT_NVAR(&_5$$6);
		ZEPHIR_INIT_NVAR(&_6$$6);
		zephir_create_array(&_6$$6, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_6$$6, &items);
		ZEPHIR_INIT_NVAR(&_7$$6);
		ZVAL_STRING(&_7$$6, "notify");
		zephir_array_fast_append(&_6$$6, &_7$$6);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_5$$6, &_6$$6, &params);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&items);
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册监听器
 *
 * @param string|array|object $event
 * @param mixed $listener
 * @param int $priority
 * @return void
 */
PHP_METHOD(Leevel_Event_Dispatch, register) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long priority, ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, event_sub, *listener, listener_sub, *priority_param = NULL, item, temp, _0, *_1, _2$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&listener_sub);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &listener, &priority_param);

	ZEPHIR_SEPARATE_PARAM(event);
	if (!priority_param) {
		priority = 500;
	} else {
		priority = zephir_get_intval(priority_param);
	}


	ZEPHIR_INIT_VAR(&temp);
	array_init(&temp);
	if (Z_TYPE_P(event) != IS_ARRAY) {
		zephir_array_append(&temp, event, PH_SEPARATE, "leevel/event/dispatch.zep", 114);
		ZEPHIR_CPY_WRT(event, &temp);
	}
	ZVAL_LONG(&_0, priority);
	priority = zephir_get_intval(&_0);
	zephir_is_iterable(event, 0, "leevel/event/dispatch.zep", 129);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(event), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(&_2$$4, this_ptr, "normalizeevent", &_3, 0, &item);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&item, &_2$$4);
		ZEPHIR_INIT_NVAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "*");
		ZEPHIR_INIT_NVAR(&_5$$4);
		zephir_fast_strpos(&_5$$4, &item, &_4$$4, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4)) {
			zephir_update_property_array_multi(this_ptr, SL("wildcards"), listener TSRMLS_CC, SL("zla"), 3, &item, priority);
		} else {
			zephir_update_property_array_multi(this_ptr, SL("listeners"), listener TSRMLS_CC, SL("zla"), 3, &item, priority);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取一个事件监听器
 *
 * @param string|object $event
 * @return array
 */
PHP_METHOD(Leevel_Event_Dispatch, get) {

	zend_string *_7, *_13$$5;
	zend_ulong _6, _12$$5;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, event_sub, listeners, key, item, priority, value, res, _0, _1, _4, *_5, _2$$3, _3$$3, _8$$4, _10$$4, *_11$$5, _14$$7, _15$$6, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);

	ZEPHIR_SEPARATE_PARAM(event);


	ZEPHIR_INIT_VAR(&listeners);
	array_init(&listeners);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeevent", NULL, 0, event);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(event, &_0);
	zephir_read_property(&_1, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, event)) {
		zephir_read_property(&_2$$3, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, event, PH_NOISY | PH_READONLY, "leevel/event/dispatch.zep", 146 TSRMLS_CC);
		ZEPHIR_CPY_WRT(&listeners, &_3$$3);
	}
	zephir_read_property(&_4, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "leevel/event/dispatch.zep", 163);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_4), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&key, _7);
		} else {
			ZVAL_LONG(&key, _6);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _5);
		ZEPHIR_CALL_METHOD(&_8$$4, this_ptr, "prepareregexforwildcard", &_9, 0, &key);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&key, &_8$$4);
		ZEPHIR_INIT_NVAR(&_10$$4);
		zephir_preg_match(&_10$$4, &key, event, &res, 0, 0 , 0  TSRMLS_CC);
		if (zephir_is_true(&_10$$4)) {
			zephir_is_iterable(&item, 0, "leevel/event/dispatch.zep", 160);
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&item), _12$$5, _13$$5, _11$$5)
			{
				ZEPHIR_INIT_NVAR(&priority);
				if (_13$$5 != NULL) { 
					ZVAL_STR_COPY(&priority, _13$$5);
				} else {
					ZVAL_LONG(&priority, _12$$5);
				}
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _11$$5);
				if (!(zephir_array_isset(&listeners, &priority))) {
					ZEPHIR_INIT_NVAR(&_14$$7);
					array_init(&_14$$7);
					zephir_array_update_zval(&listeners, &priority, &_14$$7, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_INIT_NVAR(&_15$$6);
				zephir_array_fetch(&_16$$6, &listeners, &priority, PH_NOISY | PH_READONLY, "leevel/event/dispatch.zep", 158 TSRMLS_CC);
				zephir_fast_array_merge(&_15$$6, &_16$$6, &value TSRMLS_CC);
				zephir_array_update_zval(&listeners, &priority, &_15$$6, PH_COPY | PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_INIT_NVAR(&priority);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&listeners);

}

/**
 * 判断事件监听器是否存在
 *
 * @param string|object $event
 * @return bool
 */
PHP_METHOD(Leevel_Event_Dispatch, has) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0, event);
	zephir_check_call_status();
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));

}

/**
 * 删除一个事件所有监听器
 *
 * @param string|object $event
 * @return void
 */
PHP_METHOD(Leevel_Event_Dispatch, delete) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event = NULL, event_sub, _0, _1, _3, _2$$3, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);

	ZEPHIR_SEPARATE_PARAM(event);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeevent", NULL, 0, event);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(event, &_0);
	zephir_read_property(&_1, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, event)) {
		zephir_read_property(&_2$$3, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_2$$3, event, PH_SEPARATE);
	}
	zephir_read_property(&_3, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_3, event)) {
		zephir_read_property(&_4$$4, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_4$$4, event, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化事件名字
 *
 * @param string|object $event
 * @return void
 */
PHP_METHOD(Leevel_Event_Dispatch, normalizeEvent) {

	zval *event, event_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &event);



	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(event) == IS_OBJECT) {
		zephir_get_class(&_0, event, 0 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, event);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 创建监听器观察者角色主体
 *
 * @param string $listeners
 * @return \Leevel\Event\Subject
 */
PHP_METHOD(Leevel_Event_Dispatch, makeSubject) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *listeners_param = NULL, subject, item, _0, *_1;
	zval listeners;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&subject);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &listeners_param);

	zephir_get_arrval(&listeners, listeners_param);


	ZEPHIR_INIT_VAR(&subject);
	object_init_ex(&subject, leevel_event_subject_ce);
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &subject, "__construct", NULL, 99, &_0);
	zephir_check_call_status();
	zephir_is_iterable(&listeners, 0, "leevel/event/dispatch.zep", 223);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&listeners), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(NULL, &subject, "attachs", &_2, 100, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CCTOR(&subject);

}

/**
 * 通配符正则
 *
 * @param string $regex
 * @return string
 */
PHP_METHOD(Leevel_Event_Dispatch, prepareRegexForWildcard) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *regex = NULL, regex_sub, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&regex_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &regex);

	ZEPHIR_SEPARATE_PARAM(regex);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_CALL_FUNCTION(&_1, "preg_quote", NULL, 28, regex, &_0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(regex, &_1);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\*");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "(\\S+)");
	zephir_fast_str_replace(&_0, &_2, &_3, regex TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVS(&_4, "/^", &_0, "$/");
	ZEPHIR_CPY_WRT(regex, &_4);
	RETVAL_ZVAL(regex, 1, 0);
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Event_Dispatch(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("wildcards"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("wildcards"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("listeners"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

