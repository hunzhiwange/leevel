
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
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * connect 驱动抽象类.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.06.06
 * @see http://php.net/manual/zh/class.sessionhandlerinterface.php
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Connect) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Session, Connect, leevel, session_connect, leevel_session_connect_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 缓存仓储.
	 *
	 * @var \Leevel\Cache\ICache
	 */
	zend_declare_property_null(leevel_session_connect_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_session_connect_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_session_connect_ce->create_object = zephir_init_properties_Leevel_Session_Connect;

	zend_class_implements(leevel_session_connect_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

/**
 * 构造函数.
 *
 * @param \Leevel\Cache\ICache $cache
 */
PHP_METHOD(Leevel_Session_Connect, __construct) {

	zval *cache, cache_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);

	zephir_fetch_params(0, 1, 0, &cache);



	zephir_update_property_zval(this_ptr, SL("cache"), cache);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Connect, open) {

	zval *savePath, savePath_sub, *sessionName, sessionName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);

	zephir_fetch_params(0, 2, 0, &savePath, &sessionName);



	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Connect, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Connect, read) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionid, sessionid_sub, data, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid_sub);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionid);



	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsessionname", NULL, 0, sessionid);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_CALL_METHOD(&data, &_0, "get", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&data)) {
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	}
	RETURN_CCTOR(&data);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Connect, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionid, sessionid_sub, *sessiondata, sessiondata_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid_sub);
	ZVAL_UNDEF(&sessiondata_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sessionid, &sessiondata);



	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsessionname", NULL, 0, sessionid);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_2, "unserialize", NULL, 29, sessiondata);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "set", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Connect, destroy) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sessionid, sessionid_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionid);



	zephir_read_property(&_0, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getsessionname", NULL, 0, sessionid);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_0, "delete", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Connect, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params(0, 1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

/**
 * 返回缓存仓储.
 *
 * @return \Leevel\Cache\ICache
 */
PHP_METHOD(Leevel_Session_Connect, getCache) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cache");

}

/**
 * 获取 session 名字.
 *
 * @param string $sessionid
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Connect, getSessionName) {

	zval *sessionid_param = NULL;
	zval sessionid;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &sessionid_param);

	zephir_get_strval(&sessionid, sessionid_param);


	RETURN_CTOR(&sessionid);

}

zend_object *zephir_init_properties_Leevel_Session_Connect(zend_class_entry *class_type TSRMLS_DC) {

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

