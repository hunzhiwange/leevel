
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
#include "kernel/operators.h"


/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.09
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Session, Manager, leevel, session_manager, leevel_manager_manager_ce, leevel_session_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 返回 session 配置.
 *
 * @return array
 */
PHP_METHOD(Leevel_Session_Manager, getSessionOption) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdefaultdriver", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "normalizeconnectoption", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Leevel_Session_Manager, normalizeOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("session");

}

/**
 * 创建连接对象
 *
 * @param object $connect
 * @return object
 */
PHP_METHOD(Leevel_Session_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connect, connect_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect);



	object_init_ex(return_value, leevel_session_session_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getcommonoption", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 146, connect, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 nulls 缓存
 *
 * @param array $options
 * @return \Leevel\Session\Nulls
 */
PHP_METHOD(Leevel_Session_Manager, makeConnectNulls) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	object_init_ex(return_value, leevel_session_nulls_ce);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_1);
		ZVAL_STRING(&_1, "nulls");
		ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 创建 file 缓存
 *
 * @param array $options
 * @return \Leevel\Session\File
 */
PHP_METHOD(Leevel_Session_Manager, makeConnectFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	object_init_ex(return_value, leevel_session_file_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "file");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 147, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 redis 缓存
 *
 * @param array $options
 * @return \Leevel\Session\Redis
 */
PHP_METHOD(Leevel_Session_Manager, makeConnectRedis) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	object_init_ex(return_value, leevel_session_redis_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "redis");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "normalizeconnectoption", NULL, 0, &_1, &options);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 148, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 读取连接配置
 *
 * @param string $connect
 * @return array
 */
PHP_METHOD(Leevel_Session_Manager, getConnectOption) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *connect_param = NULL, _0;
	zval connect;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connect_param);

	zephir_get_strval(&connect, connect_param);


	ZEPHIR_CALL_PARENT(&_0, leevel_session_manager_ce, getThis(), "getconnectoption", &_1, 0, &connect);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "filternullofoption", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

