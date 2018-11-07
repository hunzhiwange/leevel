
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/require.h"
#include "kernel/file.h"


/**
 * 路由服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.04.17
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_RouterProvider) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Router, RouterProvider, leevel, router_routerprovider, leevel_di_provider_ce, leevel_router_routerprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 控制器相对目录
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_router_routerprovider_ce, SL("controllerDir"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 中间件分组
	 * 分组可以很方便地批量调用组件
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_routerprovider_ce, SL("middlewareGroups"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 中间件别名
	 * HTTP 中间件提供一个方便的机制来过滤进入应用程序的 HTTP 请求
	 * 例外在应用执行结束后响应环节也会调用 HTTP 中间件
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_routerprovider_ce, SL("middlewareAlias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * bootstrap
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, bootstrap) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcontrollerdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmiddleware", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isroutercached", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "importcachedrouters", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "loadrouters", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册一个提供者
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, register) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Leevel\\Router\\RouterProvider");
	ZEPHIR_CALL_METHOD(NULL, &_0, "singleton", NULL, 0, &_1, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 可用服务提供者.
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_RouterProvider, providers) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Router\\RouterProvider");
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();

}

/**
 * 返回路由
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_RouterProvider, getRouters) {

	zend_class_entry *_1 = NULL;
	zval _0, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	if (!_1) {
	_1 = zephir_fetch_class_str_ex(SL("Leevel\\Router\\ScanRouter"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_0, _1);
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "makemiddlewareparser", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0, &_2);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(&_0, "handle", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 全局中间件
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_RouterProvider, getMiddlewares) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

/**
 * 导入路由缓存
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, importCachedRouters) {

	zval routers, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getroutercachepath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_1);
	if (zephir_require_zval_ret(&_1, &_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&routers, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setroutersdata", NULL, 0, &routers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册路由
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, loadRouters) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getrouters", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setroutersdata", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 生成中间件分析器
 *
 * @return \Leevel\Router\MiddlewareParser
 */
PHP_METHOD(Leevel_Router_RouterProvider, makeMiddlewareParser) {

	zval _1, _2, _3;
	zend_class_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	if (!_0) {
	_0 = zephir_fetch_class_str_ex(SL("Leevel\\Router\\MiddlewareParser"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _0);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_STRING(&_3, "router");
		ZEPHIR_CALL_METHOD(&_2, &_1, "make", NULL, 0, &_3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_2);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 设置路由数据
 *
 * @param array $routers
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, setRoutersData) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *routers_param = NULL, router, _0, _1, _2, _3, _4, _5;
	zval routers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routers);
	ZVAL_UNDEF(&router);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routers_param);

	zephir_get_arrval(&routers, routers_param);


	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "router");
	ZEPHIR_CALL_METHOD(&router, &_0, "make", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_array_fetch_string(&_2, &routers, SL("base_paths"), PH_NOISY | PH_READONLY, "leevel/router/routerprovider.zep", 160 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &router, "setbasepaths", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, &routers, SL("group_paths"), PH_NOISY | PH_READONLY, "leevel/router/routerprovider.zep", 161 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &router, "setgrouppaths", NULL, 0, &_3);
	zephir_check_call_status();
	zephir_array_fetch_string(&_4, &routers, SL("groups"), PH_NOISY | PH_READONLY, "leevel/router/routerprovider.zep", 162 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &router, "setgroups", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_array_fetch_string(&_5, &routers, SL("routers"), PH_NOISY | PH_READONLY, "leevel/router/routerprovider.zep", 163 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, &router, "setrouters", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 路由是否已经缓存
 *
 * @return boolean
 */
PHP_METHOD(Leevel_Router_RouterProvider, isRouterCached) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getroutercachepath", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL((zephir_file_exists(&_0 TSRMLS_CC) == SUCCESS));

}

/**
 * 获取路由缓存地址
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_RouterProvider, getRouterCachePath) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "routercachedpath", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置应用控制器目录
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, setControllerDir) {

	zval _0, _1$$3, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("controllerDir"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "router");
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "make", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, SL("controllerDir"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "setcontrollerdir", NULL, 0, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置中间件
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_RouterProvider, setMiddleware) {

	zval _0, _5, _1$$3, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4, _8$$4, _9$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("middlewareGroups"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_0) == IS_NULL)) {
		zephir_read_property(&_1$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "router");
		ZEPHIR_CALL_METHOD(&_2$$3, &_1$$3, "make", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_read_property(&_4$$3, this_ptr, SL("middlewareGroups"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "setmiddlewaregroups", NULL, 0, &_4$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, SL("middlewareAlias"), PH_NOISY_CC | PH_READONLY);
	if (!(Z_TYPE_P(&_5) == IS_NULL)) {
		zephir_read_property(&_6$$4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "router");
		ZEPHIR_CALL_METHOD(&_7$$4, &_6$$4, "make", NULL, 0, &_8$$4);
		zephir_check_call_status();
		zephir_read_property(&_9$$4, this_ptr, SL("middlewareAlias"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "setmiddlewarealias", NULL, 0, &_9$$4);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

