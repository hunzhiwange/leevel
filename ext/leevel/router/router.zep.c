
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "Zend/zend_closures.h"
#include "kernel/concat.h"


/**
 * 路由解析
 * 2018.04.10 开始进行一次重构系统路由架构
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.01.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_Router) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Router, Router, leevel, router_router, leevel_router_router_method_entry, 0);

	/**
	 * IOC Container
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * http 请求
	 *
	 * @var \Leevel\Http\IRequest
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 路由匹配数据
	 * 
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("matchedData"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 路由匹配初始化数据
	 * 
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("matcheDataInit"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 是否已经进行匹配.
	 *
	 * @var bool
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("isMatched"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 基础路径 
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("basePaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 分组路径.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("groupPaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 分组
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("groups"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 路由 
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("routers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 中间件分组 
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("middlewareGroups"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 中间件别名 
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("middlewareAlias"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 控制器相对目录
	 * 
	 * @var string
	 */
	zend_declare_property_string(leevel_router_router_ce, SL("controllerDir"), "App\\Controller", ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 注册的动态扩展
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("macro"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	leevel_router_router_ce->create_object = zephir_init_properties_Leevel_Router_Router;

	zend_class_implements(leevel_router_router_ce TSRMLS_CC, 1, leevel_router_irouter_ce);
	zend_class_implements(leevel_router_router_ce TSRMLS_CC, 1, leevel_support_imacro_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, __construct) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * 分发请求到路由
 *
 * @param \Leevel\Http\IRequest $request
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Router_Router, dispatch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	zephir_update_property_zval(this_ptr, SL("request"), request);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dispatchtoroute", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 初始化请求
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, initRequest) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("matchedData"), &__$null);

}

/**
 * 设置匹配路由
 * 绕过路由解析，可以用于高性能 RPC 快速匹配资源
 *
 * @param array $matchedData
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setMatchedData) {

	zval *matchedData_param = NULL, __$true, __$false, _0, _1;
	zval matchedData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matchedData);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matchedData_param);

	zephir_get_arrval(&matchedData, matchedData_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_static_property_ce(&_1, leevel_router_router_ce, SL("matcheDataInit"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &matchedData TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("matchedData"), &_0);
	if (1) {
		zephir_update_property_zval(this_ptr, SL("isMatched"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isMatched"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 穿越中间件
 *
 * @param \Leevel\Http\IRequest $passed
 * @param array $passedExtend
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, throughMiddleware) {

	zend_bool _0;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval passedExtend, _3, _5, _9, _7$$4;
	zval *passed, passed_sub, *passedExtend_param = NULL, method, pipeline, middlewares, _1, _2, _4, _10, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&passed_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&pipeline);
	ZVAL_UNDEF(&middlewares);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&passedExtend);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &passed, &passedExtend_param);

	if (!passedExtend_param) {
		ZEPHIR_INIT_VAR(&passedExtend);
		array_init(&passedExtend);
	} else {
		zephir_get_arrval(&passedExtend, passedExtend_param);
	}


	if (ZEPHIR_IS_EMPTY(&passedExtend)) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "handle");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "terminate");
	}
	ZEPHIR_CALL_METHOD(&middlewares, this_ptr, "matchedmiddlewares", NULL, 0);
	zephir_check_call_status();
	_0 = !(zephir_array_isset(&middlewares, &method));
	if (!(_0)) {
		zephir_array_fetch(&_1, &middlewares, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 207 TSRMLS_CC);
		_0 = ZEPHIR_IS_EMPTY(&_1);
	}
	if (_0) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&pipeline);
	object_init_ex(&pipeline, leevel_pipeline_pipeline_ce);
	zephir_read_property(&_2, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &pipeline, "__construct", NULL, 138, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, &pipeline);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "send");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0 TSRMLS_CC);
	zephir_array_fast_append(&_5, passed);
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, 12, &_3, &_5);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&passedExtend))) {
		ZEPHIR_INIT_VAR(&_7$$4);
		zephir_create_array(&_7$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$4, &pipeline);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "send");
		zephir_array_fast_append(&_7$$4, &_8$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, 12, &_7$$4, &passedExtend);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_9, &pipeline);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "through");
	zephir_array_fast_append(&_9, &_4);
	zephir_array_fetch(&_10, &middlewares, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 219 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_6, 12, &_9, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &pipeline, "then", NULL, 139);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 设置控制器相对目录
 *
 * @param string $controllerDir
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setControllerDir) {

	zval *controllerDir_param = NULL, _0, _1, _2;
	zval controllerDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controllerDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &controllerDir_param);

	zephir_get_strval(&controllerDir, controllerDir_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\");
	zephir_fast_str_replace(&_0, &_1, &_2, &controllerDir TSRMLS_CC);
	zephir_get_strval(&controllerDir, &_0);
	zephir_update_property_zval(this_ptr, SL("controllerDir"), &controllerDir);
	ZEPHIR_MM_RESTORE();

}

/**
 * 返回控制器相对目录
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, getControllerDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "controllerDir");

}

/**
 * 设置路由
 *
 * @param array $routers
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setRouters) {

	zval *routers_param = NULL;
	zval routers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&routers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &routers_param);

	zephir_get_arrval(&routers, routers_param);


	zephir_update_property_zval(this_ptr, SL("routers"), &routers);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得当前路由
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getRouters) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "routers");

}

/**
 * 设置基础路径
 *
 * @param array $basePaths
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setBasePaths) {

	zval *basePaths_param = NULL;
	zval basePaths;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basePaths);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basePaths_param);

	zephir_get_arrval(&basePaths, basePaths_param);


	zephir_update_property_zval(this_ptr, SL("basePaths"), &basePaths);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得基础路径
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getBasePaths) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "basePaths");

}

/**
 * 设置分组路径.
 *
 * @param array $groupPaths
 */
PHP_METHOD(Leevel_Router_Router, setGroupPaths) {

	zval *groupPaths_param = NULL;
	zval groupPaths;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&groupPaths);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &groupPaths_param);

	zephir_get_arrval(&groupPaths, groupPaths_param);


	zephir_update_property_zval(this_ptr, SL("groupPaths"), &groupPaths);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得分组路径.
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getGroupPaths) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "groupPaths");

}

/**
 * 设置路由分组
 *
 * @param array $groups
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setGroups) {

	zval *groups_param = NULL;
	zval groups;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&groups);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &groups_param);

	zephir_get_arrval(&groups, groups_param);


	zephir_update_property_zval(this_ptr, SL("groups"), &groups);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得路由分组
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getGroups) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "groups");

}

/**
 * 设置中间件分组
 *
 * @param array $middlewareGroups
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setMiddlewareGroups) {

	zval *middlewareGroups_param = NULL;
	zval middlewareGroups;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middlewareGroups);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middlewareGroups_param);

	zephir_get_arrval(&middlewareGroups, middlewareGroups_param);


	zephir_update_property_zval(this_ptr, SL("middlewareGroups"), &middlewareGroups);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得中间件分组
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getMiddlewareGroups) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "middlewareGroups");

}

/**
 * 设置中间件别名
 *
 * @param array $middlewareAlias
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setMiddlewareAlias) {

	zval *middlewareAlias_param = NULL;
	zval middlewareAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middlewareAlias);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middlewareAlias_param);

	zephir_get_arrval(&middlewareAlias, middlewareAlias_param);


	zephir_update_property_zval(this_ptr, SL("middlewareAlias"), &middlewareAlias);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得中间件别名
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getMiddlewareAlias) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "middlewareAlias");

}

/**
 * 注册一个扩展
 *
 * @param string $name
 * @param callable $macro
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, macro) {

	zval *name_param = NULL, *macro, macro_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&macro_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &macro);

	zephir_get_strval(&name, name_param);


	zephir_update_static_property_array_multi_ce(leevel_router_router_ce, SL("macro"), macro TSRMLS_CC, SL("z"), 1, &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断一个扩展是否注册
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Leevel_Router_Router, hasMacro) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_static_property_ce(&_0, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

/**
 * __callStatic 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Router_Router, callStaticMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _3, _4, _5, _1$$3, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 408 TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 1, &_4, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 2, &_5);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_3, "leevel/router/router.zep", 411 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * __call 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
 * 
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_Router_Router, callMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _8, _9, _10, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY, "leevel/router/router.zep", 427 TSRMLS_CC);
		if (zephir_instance_of_ev(&_2$$3, zend_ce_closure TSRMLS_CC)) {
			zephir_read_static_property_ce(&_3$$4, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$4, &_3$$4, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 428 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "bindto", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5$$4, &args);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			zephir_read_static_property_ce(&_6$$5, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$5, &_6$$5, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 430 TSRMLS_CC);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_7$$5, &args);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	object_init_ex(&_8, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_10, "sprintf", NULL, 1, &_9, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 2, &_10);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_8, "leevel/router/router.zep", 434 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 格式化前缀
 * 
 * @param array $paths
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, normalizePrefix) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_7 = NULL;
	zval *paths_param = NULL, item, *_0, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _6$$4, _8$$4, _9$$5;
	zval paths, result;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paths_param);

	zephir_get_arrval(&paths, paths_param);


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	zephir_is_iterable(&paths, 0, "leevel/router/router.zep", 459);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&paths), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "_");
		ZEPHIR_INIT_NVAR(&_2$$3);
		zephir_fast_strpos(&_2$$3, &item, &_1$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "_");
			ZEPHIR_INIT_NVAR(&_5$$4);
			ZVAL_STRING(&_5$$4, " ");
			zephir_fast_str_replace(&_3$$4, &_4$$4, &_5$$4, &item TSRMLS_CC);
			ZEPHIR_CPY_WRT(&item, &_3$$4);
			ZEPHIR_CALL_FUNCTION(&_6$$4, "ucwords", &_7, 6, &item);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, " ");
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "");
			ZEPHIR_INIT_NVAR(&item);
			zephir_fast_str_replace(&item, &_3$$4, &_8$$4, &_6$$4 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_9$$5);
			zephir_ucfirst(&_9$$5, &item);
			ZEPHIR_CPY_WRT(&item, &_9$$5);
		}
		zephir_array_append(&result, &item, PH_SEPARATE, "leevel/router/router.zep", 456);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&result);

}

/**
 * 路由匹配
 * 高效匹配，如果默认 PathInfo 路由能够匹配上则忽略 OpenApi 路由匹配.
 *
 * @return mixed|void
 */
PHP_METHOD(Leevel_Router_Router, matchRouter) {

	zend_bool _1;
	zval dataPathInfo, bind, _0, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataPathInfo);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("isMatched"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_IS_TRUE_IDENTICAL(&_0);
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		_1 = !((Z_TYPE_P(&_2) == IS_NULL));
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "findrouterbind", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initrequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "PathInfo");
	ZEPHIR_CALL_METHOD(&dataPathInfo, this_ptr, "normalizematcheddata", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolvematcheddata", NULL, 0, &dataPathInfo);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bind, this_ptr, "normalizerouterbind", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&bind)) {
		ZEPHIR_CALL_METHOD(&bind, this_ptr, "annotationrouterbind", NULL, 0, &dataPathInfo);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&bind);

}

/**
 * 注解路由绑定.
 *
 * @param array $dataPathInfo 
 * @return mixed
 */
PHP_METHOD(Leevel_Router_Router, annotationRouterBind) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dataPathInfo_param = NULL, data, _0;
	zval dataPathInfo;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dataPathInfo);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dataPathInfo_param);

	zephir_get_arrval(&dataPathInfo, dataPathInfo_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Annotation");
	ZEPHIR_CALL_METHOD(&data, this_ptr, "normalizematcheddata", NULL, 0, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&data))) {
		ZEPHIR_CPY_WRT(&data, &dataPathInfo);
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initrequest", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "resolvematcheddata", NULL, 0, &data);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "findrouterbind", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 完成路由匹配数据
 *
 * @param array $data 
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, resolveMatchedData) {

	zval *data_param = NULL, _0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_static_property_ce(&_1, leevel_router_router_ce, SL("matcheDataInit"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &data TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("matchedData"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * 解析路由匹配数据
 *
 * @param string $matche
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, normalizeMatchedData) {

	zend_class_entry *_3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matche_param = NULL, _1, _2, _4;
	zval matche, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matche);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matche_param);

	zephir_get_strval(&matche, matche_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Leevel\\Router\\Match\\", &matche);
	ZEPHIR_CPY_WRT(&matche, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fetch_safe_class(&_2, &matche);
	_3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2), Z_STRLEN_P(&_2), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&_1, _3);
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "matche", NULL, 0, this_ptr, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 尝试获取路由绑定
 *
 * @return callable|void
 */
PHP_METHOD(Leevel_Router_Router, findRouterBind) {

	zval bind;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bind);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&bind, this_ptr, "normalizerouterbind", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&bind)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "routernotfound", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&bind);

}

/**
 * 解析路由绑定
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Router_Router, normalizeRouterBind) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "completerequest", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsematchedbind", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 发送路由并返回响应
 *
 * @param \Leevel\Http\IRequest $request
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Router_Router, dispatchToRoute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "matchrouter", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "runroute", NULL, 0, request, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 运行路由
 * 
 * @param \Leevel\Http\IRequest $request
 * @param callable $bind
 * @return \Leevel\Http\IResponse
 */
PHP_METHOD(Leevel_Router_Router, runRoute) {

	zend_bool _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *bind, bind_sub, response, result, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&bind_sub);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &request, &bind);



	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "throughmiddleware", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "matchedvars", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, &_1, "call", NULL, 0, bind, &_2);
	zephir_check_call_status();
	_3 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_3) {
		_3 = zephir_instance_of_ev(&response, leevel_http_iresponse_ce TSRMLS_CC);
	}
	if (!(_3)) {
		ZEPHIR_INIT_VAR(&result);
		object_init_ex(&result, leevel_http_response_ce);
		ZEPHIR_CALL_METHOD(NULL, &result, "__construct", NULL, 18, &response);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&result, &response);
	}
	RETURN_CCTOR(&result);

}

/**
 * 路由未找到异常.
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, routerNotFound) {

	zend_class_entry *_2 = NULL;
	zval message, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "makerouternode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "The router %s was not found.");
	ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 1, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	if (!_2) {
	_2 = zephir_fetch_class_str_ex(SL("Leevel\\Router\\RouterNotFoundException"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&_1, _2);
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &message);
		zephir_check_call_status();
	}
	zephir_throw_exception_debug(&_1, "leevel/router/router.zep", 613 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 生成路由节点资源.
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, makeRouterNode) {

	zval matchedBind, _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matchedBind);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&matchedBind, this_ptr, "matchedbind", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&matchedBind)) {
		RETURN_CCTOR(&matchedBind);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "matchedapp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsecontrollerdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "matchedcontroller", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "matchedaction", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVSVSVS(return_value, &_0, "\\", &_1, "\\", &_2, "::", &_3, "()");
	RETURN_MM();

}

/**
 * 取得控制器命名空间目录
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, parseControllerDir) {

	zval result, _0, _2$$3, _3$$3;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&result, this_ptr, "getcontrollerdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "matchedprefix", &_1, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "matchedprefix", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "\\", &_2$$3);
		zephir_concat_self(&result, &_3$$3 TSRMLS_CC);
	}
	RETURN_CCTOR(&result);

}

/**
 * 完成请求
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, completeRequest) {

	zval _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pathinforestful", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "matchedapp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "app_name");
	ZEPHIR_CALL_METHOD(NULL, &_0, "instance", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, &_3, SL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "matchedparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "replace", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 智能 restful 解析
 * 路由匹配如果没有匹配上方法则系统会进入 restful 解析.
 */
PHP_METHOD(Leevel_Router_Router, pathinfoRestful) {

	zend_bool _1;
	zval _0, _2, _3, _4, _5, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	_1 = !(zephir_array_isset_string(&_0, SL("_a")));
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("_a"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 676 TSRMLS_CC);
		_1 = !(ZEPHIR_IS_EMPTY(&_3));
	}
	if (_1) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_4, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "getmethod", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_STRING(&_5, "POST")) {
			ZEPHIR_INIT_VAR(&_6$$4);
			ZVAL_STRING(&_6$$4, "_a");
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "store");
			zephir_update_property_array(this_ptr, SL("matchedData"), &_6$$4, &_7$$4 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_5, "PUT")) {
			ZEPHIR_INIT_VAR(&_8$$5);
			ZVAL_STRING(&_8$$5, "_a");
			ZEPHIR_INIT_VAR(&_9$$5);
			ZVAL_STRING(&_9$$5, "update");
			zephir_update_property_array(this_ptr, SL("matchedData"), &_8$$5, &_9$$5 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_STRING(&_5, "DELETE")) {
			ZEPHIR_INIT_VAR(&_10$$6);
			ZVAL_STRING(&_10$$6, "_a");
			ZEPHIR_INIT_VAR(&_11$$6);
			ZVAL_STRING(&_11$$6, "destroy");
			zephir_update_property_array(this_ptr, SL("matchedData"), &_10$$6, &_11$$6 TSRMLS_CC);
			break;
		}
		ZEPHIR_INIT_VAR(&_12$$7);
		ZVAL_STRING(&_12$$7, "_a");
		ZEPHIR_INIT_VAR(&_13$$7);
		ZVAL_STRING(&_13$$7, "show");
		zephir_update_property_array(this_ptr, SL("matchedData"), &_12$$7, &_13$$7 TSRMLS_CC);
		break;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * 分析匹配绑定路由.
 *
 * @return false|callable
 */
PHP_METHOD(Leevel_Router_Router, parseMatchedBind) {

	zend_bool _10;
	zval matchedApp, matchedController, matchedAction, controllerClass, method, matchedBind, tmpBind, bindClass, controller, _0$$3, _1$$3, _2$$4, _3$$6, _4$$8, _6$$8, _7$$9, _8$$10, _9$$10, _11$$12, _12$$12, _13$$12;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matchedApp);
	ZVAL_UNDEF(&matchedController);
	ZVAL_UNDEF(&matchedAction);
	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&matchedBind);
	ZVAL_UNDEF(&tmpBind);
	ZVAL_UNDEF(&bindClass);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$12);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&matchedBind, this_ptr, "matchedbind", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&matchedBind)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "@");
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_fast_strpos(&_1$$3, &matchedBind, &_0$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$3)) {
			ZEPHIR_INIT_VAR(&tmpBind);
			zephir_fast_explode_str(&tmpBind, SL("@"), &matchedBind, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_VAR(&bindClass);
			zephir_array_fetch_long(&bindClass, &tmpBind, 0, PH_NOISY, "leevel/router/router.zep", 715 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&method);
			zephir_array_fetch_long(&method, &tmpBind, 1, PH_NOISY, "leevel/router/router.zep", 716 TSRMLS_CC);
			if (!(zephir_class_exists(&bindClass, 1 TSRMLS_CC))) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_2$$4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&controller, &_2$$4, "make", NULL, 0, &bindClass);
			zephir_check_call_status();
		} else {
			if (!(zephir_class_exists(&matchedBind, 1 TSRMLS_CC))) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_3$$6, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&controller, &_3$$6, "make", NULL, 0, &matchedBind);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "handle");
		}
	} else {
		ZEPHIR_CALL_METHOD(&matchedApp, this_ptr, "matchedapp", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&matchedController, this_ptr, "matchedcontroller", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&matchedAction, this_ptr, "matchedaction", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "parsecontrollerdir", &_5, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$8);
		zephir_ucfirst(&_6$$8, &matchedAction);
		ZEPHIR_INIT_VAR(&controllerClass);
		ZEPHIR_CONCAT_VSVSVSV(&controllerClass, &matchedApp, "\\", &_4$$8, "\\", &matchedController, "\\", &_6$$8);
		if (zephir_class_exists(&controllerClass, 1 TSRMLS_CC)) {
			zephir_read_property(&_7$$9, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&controller, &_7$$9, "make", NULL, 0, &controllerClass);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "handle");
		} else {
			ZEPHIR_CALL_METHOD(&_8$$10, this_ptr, "parsecontrollerdir", &_5, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&controllerClass);
			ZEPHIR_CONCAT_VSVSV(&controllerClass, &matchedApp, "\\", &_8$$10, "\\", &matchedController);
			if (!(zephir_class_exists(&controllerClass, 1 TSRMLS_CC))) {
				RETURN_MM_BOOL(0);
			}
			zephir_read_property(&_9$$10, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&controller, &_9$$10, "make", NULL, 0, &controllerClass);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&method, &matchedAction);
		}
	}
	_10 = Z_TYPE_P(&controller) == IS_OBJECT;
	if (_10) {
		_10 = zephir_instance_of_ev(&controller, leevel_mvc_icontroller_ce TSRMLS_CC);
	}
	if (_10) {
		zephir_read_property(&_11$$12, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_13$$12);
		ZVAL_STRING(&_13$$12, "Leevel\\Mvc\\IView");
		ZEPHIR_CALL_METHOD(&_12$$12, &_11$$12, "make", NULL, 0, &_13$$12);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &controller, "setview", NULL, 0, &_12$$12);
		zephir_check_call_status();
	}
	if (!((zephir_method_exists(&controller, &method TSRMLS_CC)  == SUCCESS))) {
		RETURN_MM_BOOL(0);
	}
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &controller);
	zephir_array_fast_append(return_value, &method);
	RETURN_MM();

}

/**
 * 取回控制器前缀
 *
 * @return null|string
 */
PHP_METHOD(Leevel_Router_Router, matchedPrefix) {

	zend_bool _1;
	zval tmp;
	zval prefix, v, _0, *_2, _6, _7, _8, _9, _3$$4, _4$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&tmp);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&prefix);
	zephir_array_fetch_string(&prefix, &_0, SL("_prefix"), PH_NOISY, "leevel/router/router.zep", 776 TSRMLS_CC);
	_1 = !zephir_is_true(&prefix);
	if (!(_1)) {
		_1 = zephir_is_scalar(&prefix);
	}
	if (_1) {
		RETURN_CCTOR(&prefix);
	}
	zephir_is_iterable(&prefix, 0, "leevel/router/router.zep", 786);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&prefix), _2)
	{
		ZEPHIR_INIT_NVAR(&v);
		ZVAL_COPY(&v, _2);
		ZEPHIR_INIT_NVAR(&_4$$4);
		zephir_ucfirst(&_4$$4, &v);
		ZEPHIR_CALL_METHOD(&_3$$4, this_ptr, "convertmatched", &_5, 0, &_4$$4);
		zephir_check_call_status();
		zephir_array_append(&tmp, &_3$$4, PH_SEPARATE, "leevel/router/router.zep", 783);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_join_str(&_6, SL("\\"), &tmp TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "_prefix");
	zephir_update_property_array(this_ptr, SL("matchedData"), &_7, &_6 TSRMLS_CC);
	zephir_read_property(&_8, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_9, &_8, SL("_prefix"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 788 TSRMLS_CC);
	RETURN_CTOR(&_9);

}

/**
 * 取回应用名
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, matchedApp) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("_app"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 798 TSRMLS_CC);
	zephir_ucfirst(return_value, &_1);
	return;

}

/**
 * 取回控制器名
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, matchedController) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("_c"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 808 TSRMLS_CC);
	zephir_ucfirst(&_0, &_2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "convertmatched", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取回方法名
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, matchedAction) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("_a"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 818 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "convertmatched", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 转换匹配资源.
 *
 * @param string $matched
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, convertMatched) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *matched_param = NULL, _0, _1, _5, _6, _2$$3, _3$$3, _4$$3, _7$$4, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4;
	zval matched;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matched);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &matched_param);

	zephir_get_strval(&matched, matched_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &matched, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "-");
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "_");
		zephir_fast_str_replace(&_2$$3, &_3$$3, &_4$$3, &matched TSRMLS_CC);
		zephir_get_strval(&matched, &_2$$3);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "_");
	ZEPHIR_INIT_VAR(&_6);
	zephir_fast_strpos(&_6, &matched, &_5, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6)) {
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "_");
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, " ");
		zephir_fast_str_replace(&_7$$4, &_8$$4, &_9$$4, &matched TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_10$$4);
		ZEPHIR_CONCAT_SV(&_10$$4, "_", &_7$$4);
		zephir_get_strval(&matched, &_10$$4);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_CALL_FUNCTION(&_12$$4, "ucwords", NULL, 6, &matched);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$4);
		ZVAL_STRING(&_13$$4, " ");
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, "");
		zephir_fast_str_replace(&_11$$4, &_13$$4, &_14$$4, &_12$$4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "_");
		ZEPHIR_INIT_NVAR(&matched);
		zephir_fast_trim(&matched, &_11$$4, &_15$$4, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	}
	RETURN_CTOR(&matched);

}

/**
 * 取回绑定资源.
 *
 * @return null|string
 */
PHP_METHOD(Leevel_Router_Router, matchedBind) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("_bind"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 849 TSRMLS_CC);
	RETURN_CTORW(&_1);

}

/**
 * 取回匹配参数
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, matchedParams) {

	zval _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("_params"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 859 TSRMLS_CC);
	if (!(Z_TYPE_P(&_2) == IS_NULL)) {
		zephir_read_property(&_3, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_0, &_3, SL("_params"), PH_NOISY, "leevel/router/router.zep", 859 TSRMLS_CC);
	} else {
		array_init(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 取回匹配中间件
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, matchedMiddlewares) {

	zval _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("_middlewares"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 869 TSRMLS_CC);
	if (!(Z_TYPE_P(&_2) == IS_NULL)) {
		zephir_read_property(&_3, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_0, &_3, SL("_middlewares"), PH_NOISY, "leevel/router/router.zep", 870 TSRMLS_CC);
	} else {
		zephir_create_array(&_0, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_4);
		array_init(&_4);
		zephir_array_update_string(&_0, SL("handle"), &_4, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_4);
		array_init(&_4);
		zephir_array_update_string(&_0, SL("terminate"), &_4, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 取回匹配变量
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, matchedVars) {

	zval _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_2, &_1, SL("_vars"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 881 TSRMLS_CC);
	if (!(Z_TYPE_P(&_2) == IS_NULL)) {
		zephir_read_property(&_3, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_0, &_3, SL("_vars"), PH_NOISY, "leevel/router/router.zep", 881 TSRMLS_CC);
	} else {
		array_init(&_0);
	}
	RETURN_CCTOR(&_0);

}

void zephir_init_static_properties_Leevel_Router_Router(TSRMLS_D) {

	zval _1;
	zval __$null, _0;
		ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(leevel_router_router_ce, ZEND_STRL("macro"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 8, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("_app"), SL("app"));
	zephir_array_update_string(&_1, SL("_prefix"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_c"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_a"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_bind"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_params"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_middlewares"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_vars"), &__$null, PH_COPY | PH_SEPARATE);
	zend_update_static_property(leevel_router_router_ce, ZEND_STRL("matcheDataInit"), &_1);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Leevel_Router_Router(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _8, _10, _1$$3, _3$$4, _5$$5, _7$$6, _9$$7, _11$$8;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$8);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("middlewareAlias"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("middlewareAlias"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("middlewareGroups"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("middlewareGroups"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("routers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("routers"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("groups"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("groups"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("groupPaths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("groupPaths"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("basePaths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("basePaths"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

