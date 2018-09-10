
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
#include "kernel/operators.h"


/**
 * 事件服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.01
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Event_EventProvider) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Event, EventProvider, leevel, event_eventprovider, leevel_di_provider_ce, leevel_event_eventprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 监听器列表
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_event_eventprovider_ce, SL("listeners"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_event_eventprovider_ce->create_object = zephir_init_properties_Leevel_Event_EventProvider;
	return SUCCESS;

}

/**
 * 注册时间监听器
 *
 * @param \Leevel\Event\IDispatch $dispatch
 * @return void
 */
PHP_METHOD(Leevel_Event_EventProvider, bootstrap) {

	zend_string *_3, *_6$$3;
	zend_ulong _2, _5$$3;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dispatch, dispatch_sub, event, listeners, key, item, _0, *_1, *_4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dispatch_sub);
	ZVAL_UNDEF(&event);
	ZVAL_UNDEF(&listeners);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dispatch);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "get", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "leevel/event/eventprovider.zep", 58);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&event);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&event, _3);
		} else {
			ZVAL_LONG(&event, _2);
		}
		ZEPHIR_INIT_NVAR(&listeners);
		ZVAL_COPY(&listeners, _1);
		zephir_is_iterable(&listeners, 0, "leevel/event/eventprovider.zep", 57);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&listeners), _5$$3, _6$$3, _4$$3)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_6$$3 != NULL) { 
				ZVAL_STR_COPY(&key, _6$$3);
			} else {
				ZVAL_LONG(&key, _5$$3);
			}
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _4$$3);
			if (Z_TYPE_P(&item) == IS_LONG) {
				ZEPHIR_CALL_METHOD(NULL, dispatch, "register", &_7, 0, &event, &key, &item);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_METHOD(NULL, dispatch, "register", &_8, 0, &event, &item);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
		ZEPHIR_INIT_NVAR(&key);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&listeners);
	ZEPHIR_INIT_NVAR(&event);
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册一个提供者
 *
 * @return void
 */
PHP_METHOD(Leevel_Event_EventProvider, register) {

	zval *this_ptr = getThis();



}

/**
 * 取得监听器
 *
 * @return array
 */
PHP_METHOD(Leevel_Event_EventProvider, get) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "listeners");

}

zend_object *zephir_init_properties_Leevel_Event_EventProvider(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("listeners"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("listeners"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

