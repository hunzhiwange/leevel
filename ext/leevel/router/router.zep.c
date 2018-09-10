
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
	 * 全局路由绑定中间件
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("globalMiddlewares"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 当前的中间件
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_router_router_ce, SL("currentMiddlewares"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	zend_declare_property_null(leevel_router_router_ce, SL("basepaths"), ZEND_ACC_PROTECTED TSRMLS_CC);

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

	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval passedExtend, _7$$5, _12$$5, _10$$6;
	zval *passed, passed_sub, *passedExtend_param = NULL, method, pipeline, _0, _2, _3, _4, _5, _1$$3, _6$$5, _8$$5, _13$$5, _14$$5, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&passed_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&pipeline);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&passedExtend);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_10$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &passed, &passedExtend_param);

	if (!passedExtend_param) {
		ZEPHIR_INIT_VAR(&passedExtend);
		array_init(&passedExtend);
	} else {
		zephir_get_arrval(&passedExtend, passedExtend_param);
	}


	zephir_read_property(&_0, this_ptr, SL("currentMiddlewares"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "parsemiddleware", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("currentMiddlewares"), &_1$$3);
	}
	if (ZEPHIR_IS_EMPTY(&passedExtend)) {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_STRING(&method, "handle");
	} else {
		ZEPHIR_INIT_NVAR(&method);
		ZVAL_STRING(&method, "terminate");
	}
	zephir_read_property(&_2, this_ptr, SL("currentMiddlewares"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_3, &_2, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 216 TSRMLS_CC);
	if (!(zephir_is_true(&_3))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_4, this_ptr, SL("currentMiddlewares"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 220 TSRMLS_CC);
	if (zephir_is_true(&_5)) {
		ZEPHIR_INIT_VAR(&pipeline);
		object_init_ex(&pipeline, leevel_pipeline_pipeline_ce);
		zephir_read_property(&_6$$5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &pipeline, "__construct", NULL, 141, &_6$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$5);
		zephir_create_array(&_7$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_7$$5, &pipeline);
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "send");
		zephir_array_fast_append(&_7$$5, &_8$$5);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_9, 8, &_7$$5, passed);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&passedExtend))) {
			ZEPHIR_INIT_VAR(&_10$$6);
			zephir_create_array(&_10$$6, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_10$$6, &pipeline);
			ZEPHIR_INIT_VAR(&_11$$6);
			ZVAL_STRING(&_11$$6, "send");
			zephir_array_fast_append(&_10$$6, &_11$$6);
			ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_9, 8, &_10$$6, &passedExtend);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_12$$5);
		zephir_create_array(&_12$$5, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_12$$5, &pipeline);
		ZEPHIR_INIT_NVAR(&_8$$5);
		ZVAL_STRING(&_8$$5, "through");
		zephir_array_fast_append(&_12$$5, &_8$$5);
		zephir_read_property(&_13$$5, this_ptr, SL("currentMiddlewares"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_14$$5, &_13$$5, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 229 TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", &_9, 8, &_12$$5, &_14$$5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &pipeline, "then", NULL, 142);
		zephir_check_call_status();
	}
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
 * @param string $controllerDir
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
 * @param array $basepaths
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setBasepaths) {

	zval *basepaths_param = NULL;
	zval basepaths;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basepaths);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basepaths_param);

	zephir_get_arrval(&basepaths, basepaths_param);


	zephir_update_property_zval(this_ptr, SL("basepaths"), &basepaths);
	ZEPHIR_MM_RESTORE();

}

/**
 * 添加基础路径
 *
 * @param array $basepaths
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, addBasepaths) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *basepaths_param = NULL, _0, _1, _2;
	zval basepaths;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&basepaths);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &basepaths_param);

	zephir_get_arrval(&basepaths, basepaths_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("basepaths"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &basepaths TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_unique", NULL, 143, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("basepaths"), &_2);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得基础路径
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getBasepaths) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "basepaths");

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
 * 添加路由分组
 *
 * @param array $groups
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, addGroups) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *groups_param = NULL, _0, _1, _2;
	zval groups;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&groups);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &groups_param);

	zephir_get_arrval(&groups, groups_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("groups"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_array_merge(&_0, &_1, &groups TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_2, "array_unique", NULL, 143, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("groups"), &_2);
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
 * 设置全局中间件
 *
 * @param array $middlewares
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, setGlobalMiddlewares) {

	zval *middlewares_param = NULL;
	zval middlewares;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&middlewares);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &middlewares_param);

	zephir_get_arrval(&middlewares, middlewares_param);


	zephir_update_property_zval(this_ptr, SL("globalMiddlewares"), &middlewares);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得全局中间件
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, getGlobalMiddlewares) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "globalMiddlewares");

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
 * 匹配路径.
 *
 * @param string $path
 * @param bool   $ignoreMiddleware
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, matchePath) {

	zend_string *_10;
	zend_ulong _9;
	zval baseOptions;
	zephir_fcall_cache_entry *_23 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool ignoreMiddleware, _15;
	zval *path_param = NULL, *ignoreMiddleware_param = NULL, result, query, tmpListPathQuery, item, basepath, paths, params, tmpListPathsParams, tmpPath, option, _0, _1, _7, *_8, _13, _14, _16, _17, _28, _29, _2$$4, *_3$$4, _4$$5, _5$$5, _6$$5, _11$$7, _12$$8, _18$$9, _19$$9, _20$$9, _21$$10, _22$$11, _24$$13, _25$$14, _26$$15, _27$$15, _30$$16;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&tmpListPathQuery);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&basepath);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&tmpListPathsParams);
	ZVAL_UNDEF(&tmpPath);
	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&baseOptions);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &ignoreMiddleware_param);

	zephir_get_strval(&path, path_param);
	if (!ignoreMiddleware_param) {
		ignoreMiddleware = 0;
	} else {
		ignoreMiddleware = zephir_get_boolval(ignoreMiddleware_param);
	}


	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "?");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &path, &_0, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1)) {
		ZEPHIR_INIT_VAR(&tmpListPathQuery);
		zephir_fast_explode_str(&tmpListPathQuery, SL("?"), &path, LONG_MAX TSRMLS_CC);
		ZEPHIR_OBS_VAR(&tmpPath);
		zephir_array_fetch_long(&tmpPath, &tmpListPathQuery, 0, PH_NOISY, "leevel/router/router.zep", 424 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&query);
		zephir_array_fetch_long(&query, &tmpListPathQuery, 1, PH_NOISY, "leevel/router/router.zep", 425 TSRMLS_CC);
		if (zephir_is_true(&query)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_fast_explode_str(&_2$$4, SL("&"), &query, LONG_MAX TSRMLS_CC);
			zephir_is_iterable(&_2$$4, 0, "leevel/router/router.zep", 432);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$4), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&item);
				ZVAL_COPY(&item, _3$$4);
				ZEPHIR_INIT_NVAR(&_4$$5);
				zephir_fast_explode_str(&_4$$5, SL("="), &item, LONG_MAX TSRMLS_CC);
				ZEPHIR_CPY_WRT(&item, &_4$$5);
				zephir_array_fetch_long(&_5$$5, &item, 1, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 430 TSRMLS_CC);
				zephir_array_fetch_long(&_6$$5, &item, 0, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 430 TSRMLS_CC);
				zephir_array_update_multi(&result, &_5$$5 TSRMLS_CC, SL("sz"), 3, SL("_params"), &_6$$5);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&item);
		}
	} else {
		ZEPHIR_CPY_WRT(&tmpPath, &path);
	}
	ZEPHIR_INIT_VAR(&basepath);
	ZVAL_STRING(&basepath, "");
	ZEPHIR_INIT_VAR(&baseOptions);
	array_init(&baseOptions);
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "getbasepaths", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_7, 0, "leevel/router/router.zep", 450);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_7), _9, _10, _8)
	{
		ZEPHIR_INIT_NVAR(&item);
		if (_10 != NULL) { 
			ZVAL_STR_COPY(&item, _10);
		} else {
			ZVAL_LONG(&item, _9);
		}
		ZEPHIR_INIT_NVAR(&option);
		ZVAL_COPY(&option, _8);
		ZEPHIR_INIT_NVAR(&_11$$7);
		zephir_fast_strpos(&_11$$7, &tmpPath, &item, 0 );
		if (ZEPHIR_IS_LONG_IDENTICAL(&_11$$7, 0)) {
			ZVAL_LONG(&_12$$8, (zephir_fast_strlen_ev(&item) + 1));
			ZEPHIR_INIT_NVAR(&tmpPath);
			zephir_substr(&tmpPath, &path, zephir_get_intval(&_12$$8), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CPY_WRT(&basepath, &item);
			ZEPHIR_CPY_WRT(&baseOptions, &option);
			break;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&option);
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "/");
	zephir_fast_trim(&_13, &tmpPath, &_14, ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&tmpPath, &_13);
	if (zephir_is_true(&tmpPath)) {
		ZEPHIR_INIT_VAR(&paths);
		zephir_fast_explode_str(&paths, SL("/"), &tmpPath, LONG_MAX TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&paths);
		array_init(&paths);
	}
	_15 = zephir_is_true(&paths);
	if (_15) {
		zephir_array_fetch_long(&_17, &paths, 0, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 454 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&_16, this_ptr, "findapp", NULL, 0, &_17);
		zephir_check_call_status();
		_15 = zephir_is_true(&_16);
	}
	if (_15) {
		ZEPHIR_MAKE_REF(&paths);
		ZEPHIR_CALL_FUNCTION(&_18$$9, "array_shift", NULL, 6, &paths);
		ZEPHIR_UNREF(&paths);
		zephir_check_call_status();
		ZVAL_LONG(&_19$$9, 1);
		ZEPHIR_INIT_VAR(&_20$$9);
		zephir_substr(&_20$$9, &_18$$9, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_array_update_string(&result, SL("_app"), &_20$$9, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_is_true(&paths))) {
		ZEPHIR_INIT_VAR(&_21$$10);
		ZVAL_STRING(&_21$$10, "home");
		zephir_array_update_string(&result, SL("_c"), &_21$$10, PH_COPY | PH_SEPARATE);
		RETURN_CCTOR(&result);
	}
	ZEPHIR_CALL_METHOD(&tmpListPathsParams, this_ptr, "normalizepathsandparams", NULL, 0, &paths);
	zephir_check_call_status();
	ZEPHIR_OBS_NVAR(&paths);
	zephir_array_fetch_long(&paths, &tmpListPathsParams, 0, PH_NOISY, "leevel/router/router.zep", 465 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&params);
	zephir_array_fetch_long(&params, &tmpListPathsParams, 1, PH_NOISY, "leevel/router/router.zep", 466 TSRMLS_CC);
	if (zephir_fast_count_int(&paths TSRMLS_CC) == 1) {
		ZEPHIR_MAKE_REF(&paths);
		ZEPHIR_CALL_FUNCTION(&_22$$11, "array_pop", &_23, 133, &paths);
		ZEPHIR_UNREF(&paths);
		zephir_check_call_status();
		zephir_array_update_string(&result, SL("_c"), &_22$$11, PH_COPY | PH_SEPARATE);
	} else {
		if (zephir_is_true(&paths)) {
			ZEPHIR_MAKE_REF(&paths);
			ZEPHIR_CALL_FUNCTION(&_24$$13, "array_pop", &_23, 133, &paths);
			ZEPHIR_UNREF(&paths);
			zephir_check_call_status();
			zephir_array_update_string(&result, SL("_a"), &_24$$13, PH_COPY | PH_SEPARATE);
		}
		if (zephir_is_true(&paths)) {
			ZEPHIR_MAKE_REF(&paths);
			ZEPHIR_CALL_FUNCTION(&_25$$14, "array_pop", &_23, 133, &paths);
			ZEPHIR_UNREF(&paths);
			zephir_check_call_status();
			zephir_array_update_string(&result, SL("_c"), &_25$$14, PH_COPY | PH_SEPARATE);
		}
		if (zephir_is_true(&paths)) {
			ZEPHIR_INIT_VAR(&_26$$15);
			ZEPHIR_CALL_METHOD(&_27$$15, this_ptr, "normalizeprefix", NULL, 0, &paths);
			zephir_check_call_status();
			zephir_fast_join_str(&_26$$15, SL("\\"), &_27$$15 TSRMLS_CC);
			zephir_array_update_string(&result, SL("_prefix"), &_26$$15, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&_13);
	ZEPHIR_INIT_VAR(&_28);
	if (zephir_array_isset_string(&result, SL("_params"))) {
		ZEPHIR_OBS_NVAR(&_28);
		zephir_array_fetch_string(&_28, &result, SL("_params"), PH_NOISY, "leevel/router/router.zep", 484 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_28);
		array_init(&_28);
	}
	zephir_fast_array_merge(&_13, &_28, &params TSRMLS_CC);
	zephir_array_update_string(&result, SL("_params"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_29);
	if (zephir_is_true(&basepath)) {
		ZEPHIR_CPY_WRT(&_29, &basepath);
	} else {
		ZEPHIR_INIT_NVAR(&_29);
		ZVAL_NULL(&_29);
	}
	zephir_array_update_multi(&result, &_29 TSRMLS_CC, SL("ss"), 4, SL("_params"), SL("_basepath"));
	if (!(ignoreMiddleware)) {
		ZEPHIR_INIT_VAR(&_30$$16);
		if (zephir_array_isset_string(&baseOptions, SL("middlewares"))) {
			ZEPHIR_OBS_NVAR(&_30$$16);
			zephir_array_fetch_string(&_30$$16, &baseOptions, SL("middlewares"), PH_NOISY, "leevel/router/router.zep", 488 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_30$$16);
			array_init(&_30$$16);
		}
		zephir_array_update_string(&result, SL("_middlewares"), &_30$$16, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&result);

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
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 530 TSRMLS_CC);
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
	zephir_throw_exception_debug(&_3, "leevel/router/router.zep", 533 TSRMLS_CC);
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
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY, "leevel/router/router.zep", 549 TSRMLS_CC);
		if (zephir_instance_of_ev(&_2$$3, zend_ce_closure TSRMLS_CC)) {
			zephir_read_static_property_ce(&_3$$4, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$4, &_3$$4, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 550 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "bindto", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5$$4, &args);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			zephir_read_static_property_ce(&_6$$5, leevel_router_router_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$5, &_6$$5, &method, PH_NOISY | PH_READONLY, "leevel/router/router.zep", 552 TSRMLS_CC);
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
	zephir_throw_exception_debug(&_8, "leevel/router/router.zep", 556 TSRMLS_CC);
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
	zephir_is_iterable(&paths, 0, "leevel/router/router.zep", 581);
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
			ZEPHIR_CALL_FUNCTION(&_6$$4, "ucwords", &_7, 23, &item);
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
		zephir_array_append(&result, &item, PH_SEPARATE, "leevel/router/router.zep", 578);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&result);

}

/**
 * 是否找到 app
 * 
 * @param string $app
 * @return boolean
 */
PHP_METHOD(Leevel_Router_Router, findApp) {

	zval *app_param = NULL, _0, _1;
	zval app;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app_param);

	zephir_get_strval(&app, app_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, ":");
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strpos(&_1, &app, &_0, 0 );
	RETURN_MM_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_1, 0));

}

/**
 * 解析路径和参数
 * 
 * @param array $data
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, normalizePathsAndParams) {

	zval _2$$4;
	zend_long k = 0;
	zval *data_param = NULL, paths, params, item, *_0, _1$$4;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&paths);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	ZEPHIR_INIT_VAR(&paths);
	array_init(&paths);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	k = 0;
	zephir_is_iterable(&data, 0, "leevel/router/router.zep", 618);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _0)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _0);
		if (zephir_is_numeric(&item)) {
			ZEPHIR_SINIT_NVAR(_1$$4);
			ZVAL_LONG(&_1$$4, k);
			ZEPHIR_INIT_LNVAR(_2$$4);
			ZEPHIR_CONCAT_SV(&_2$$4, "_param", &_1$$4);
			zephir_array_update_zval(&params, &_2$$4, &item, PH_COPY | PH_SEPARATE);
			k++;
		} else {
			zephir_array_append(&paths, &item, PH_SEPARATE, "leevel/router/router.zep", 614);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &paths);
	zephir_array_fast_append(return_value, &params);
	RETURN_MM();

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
		ZEPHIR_CALL_METHOD(&bind, this_ptr, "urlrouterbind", NULL, 0, &dataPathInfo);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&bind);

}

/**
 * URL 路由绑定
 *
 * @param array $dataPathInfo 
 * @return mixed
 */
PHP_METHOD(Leevel_Router_Router, urlRouterBind) {

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
	ZVAL_STRING(&_0, "Url");
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
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parsedefaultbind", NULL, 0);
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
		ZEPHIR_CALL_METHOD(NULL, &result, "__construct", NULL, 14, &response);
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
	zephir_throw_exception_debug(&_1, "leevel/router/router.zep", 772 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

/**
 * 生成路由节点资源.
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, makeRouterNode) {

	zval _0, _1, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

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
		ZEPHIR_CONCAT_VSV(&_3$$3, &result, "\\", &_2$$3);
		ZEPHIR_CPY_WRT(&result, &_3$$3);
	}
	RETURN_CCTOR(&result);

}

/**
 * 完成请求
 *
 * @return void
 */
PHP_METHOD(Leevel_Router_Router, completeRequest) {

	zval _0;
	zval type, matchedType, _1, *_2, _6, _7, _8, _3$$3, _4$$3, _5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&matchedType);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "pathinforestful", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "App");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Controller");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "Action");
	zephir_array_fast_append(&_0, &_1);
	zephir_is_iterable(&_0, 0, "leevel/router/router.zep", 824);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _2)
	{
		ZEPHIR_INIT_NVAR(&type);
		ZVAL_COPY(&type, _2);
		ZEPHIR_INIT_NVAR(&matchedType);
		ZEPHIR_CONCAT_SV(&matchedType, "matched", &type);
		ZEPHIR_INIT_LNVAR(_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "set", &type);
		ZEPHIR_CPY_WRT(&type, &_3$$3);
		zephir_read_property(&_4$$3, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD_ZVAL(&_5$$3, this_ptr, &matchedType, NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_ZVAL(NULL, &_4$$3, &type, NULL, 0, &_5$$3);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&type);
	zephir_read_property(&_6, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, &_6, SL("params"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "matchedparams", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_7, "replace", NULL, 0, &_8);
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
		zephir_array_fetch_string(&_3, &_2, SL("_a"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 834 TSRMLS_CC);
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
 * 分析默认控制器
 *
 * @return false|callable
 */
PHP_METHOD(Leevel_Router_Router, parseDefaultBind) {

	zend_bool _6;
	zval app, controller, action, controllerClass, method, _0, _2, _3$$3, _4$$4, _5$$4, _7$$6, _8$$6, _9$$6;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app);
	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&controllerClass);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&app, this_ptr, "matchedapp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&controller, this_ptr, "matchedcontroller", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&action, this_ptr, "matchedaction", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "parsecontrollerdir", &_1, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_ucfirst(&_2, &action);
	ZEPHIR_INIT_VAR(&controllerClass);
	ZEPHIR_CONCAT_VSVSVSV(&controllerClass, &app, "\\", &_0, "\\", &controller, "\\", &_2);
	if (zephir_class_exists(&controllerClass, 1 TSRMLS_CC)) {
		zephir_read_property(&_3$$3, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&controller, &_3$$3, "make", NULL, 0, &controllerClass);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&controller, SL("handle") TSRMLS_CC) == SUCCESS)) {
			ZEPHIR_INIT_VAR(&method);
			ZVAL_STRING(&method, "handle");
		} else {
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "run");
		}
	} else {
		ZEPHIR_CALL_METHOD(&_4$$4, this_ptr, "parsecontrollerdir", &_1, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&controllerClass);
		ZEPHIR_CONCAT_VSVSV(&controllerClass, &app, "\\", &_4$$4, "\\", &controller);
		if (!(zephir_class_exists(&controllerClass, 1 TSRMLS_CC))) {
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_5$$4, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&controller, &_5$$4, "make", NULL, 0, &controllerClass);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&method, &action);
	}
	_6 = Z_TYPE_P(&controller) == IS_OBJECT;
	if (_6) {
		_6 = zephir_instance_of_ev(&controller, leevel_mvc_icontroller_ce TSRMLS_CC);
	}
	if (_6) {
		zephir_read_property(&_7$$6, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_9$$6);
		ZVAL_STRING(&_9$$6, "Leevel\\Mvc\\IView");
		ZEPHIR_CALL_METHOD(&_8$$6, &_7$$6, "make", NULL, 0, &_9$$6);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &controller, "setview", NULL, 0, &_8$$6);
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
 * 获取绑定的中间件
 * 暂时不做重复过滤，允许中间件多次执行
 *
 * @return array
 */
PHP_METHOD(Leevel_Router_Router, parseMiddleware) {

	zval matchedMiddlewares, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&matchedMiddlewares);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&matchedMiddlewares, this_ptr, "matchedmiddlewares", NULL, 0);
	zephir_check_call_status();
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("globalMiddlewares"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_2, SL("handle"))) {
		zephir_read_property(&_3, this_ptr, SL("globalMiddlewares"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_1);
		zephir_array_fetch_string(&_1, &_3, SL("handle"), PH_NOISY, "leevel/router/router.zep", 915 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_1);
		array_init(&_1);
	}
	ZEPHIR_INIT_VAR(&_4);
	if (zephir_array_isset_string(&matchedMiddlewares, SL("handle"))) {
		ZEPHIR_OBS_NVAR(&_4);
		zephir_array_fetch_string(&_4, &matchedMiddlewares, SL("handle"), PH_NOISY, "leevel/router/router.zep", 916 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		array_init(&_4);
	}
	zephir_fast_array_merge(&_0, &_1, &_4 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("handle"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_5);
	zephir_read_property(&_6, this_ptr, SL("globalMiddlewares"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_6, SL("terminate"))) {
		zephir_read_property(&_7, this_ptr, SL("globalMiddlewares"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_5);
		zephir_array_fetch_string(&_5, &_7, SL("terminate"), PH_NOISY, "leevel/router/router.zep", 919 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_5);
		array_init(&_5);
	}
	ZEPHIR_INIT_VAR(&_8);
	if (zephir_array_isset_string(&matchedMiddlewares, SL("terminate"))) {
		ZEPHIR_OBS_NVAR(&_8);
		zephir_array_fetch_string(&_8, &matchedMiddlewares, SL("terminate"), PH_NOISY, "leevel/router/router.zep", 920 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		array_init(&_8);
	}
	zephir_fast_array_merge(&_0, &_5, &_8 TSRMLS_CC);
	zephir_array_update_string(return_value, SL("terminate"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

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
	zephir_array_fetch_string(&_1, &_0, SL("_app"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 932 TSRMLS_CC);
	zephir_ucfirst(return_value, &_1);
	return;

}

/**
 * 取回控制器名
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, matchedController) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("_c"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 942 TSRMLS_CC);
	zephir_ucfirst(return_value, &_1);
	return;

}

/**
 * 取回方法名
 *
 * @return string
 */
PHP_METHOD(Leevel_Router_Router, matchedAction) {

	zval action, _0, _1, _2, _6, _7, _3$$3, _4$$3, _5$$3, _8$$4, _9$$4, _10$$4, _11$$4, _12$$4, _13$$4, _14$$4, _15$$4, _16$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&action);
	zephir_array_fetch_string(&action, &_0, SL("_a"), PH_NOISY, "leevel/router/router.zep", 954 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "-");
	ZEPHIR_INIT_VAR(&_2);
	zephir_fast_strpos(&_2, &action, &_1, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "-");
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "_");
		zephir_fast_str_replace(&_3$$3, &_4$$3, &_5$$3, &action TSRMLS_CC);
		ZEPHIR_CPY_WRT(&action, &_3$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "_");
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_strpos(&_7, &action, &_6, 0 );
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7)) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "_");
		ZEPHIR_INIT_VAR(&_10$$4);
		ZVAL_STRING(&_10$$4, " ");
		zephir_fast_str_replace(&_8$$4, &_9$$4, &_10$$4, &action TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_CONCAT_SV(&_11$$4, "_", &_8$$4);
		ZEPHIR_CPY_WRT(&action, &_11$$4);
		ZEPHIR_INIT_VAR(&_12$$4);
		ZEPHIR_CALL_FUNCTION(&_13$$4, "ucwords", NULL, 23, &action);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_14$$4);
		ZVAL_STRING(&_14$$4, " ");
		ZEPHIR_INIT_VAR(&_15$$4);
		ZVAL_STRING(&_15$$4, "");
		zephir_fast_str_replace(&_12$$4, &_14$$4, &_15$$4, &_13$$4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZVAL_STRING(&_16$$4, "_");
		ZEPHIR_INIT_NVAR(&action);
		zephir_fast_trim(&action, &_12$$4, &_16$$4, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	}
	RETURN_CCTOR(&action);

}

/**
 * 取回控制器前缀
 *
 * @return string|null
 */
PHP_METHOD(Leevel_Router_Router, matchedPrefix) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("_prefix"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 975 TSRMLS_CC);
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
	zephir_array_fetch_string(&_2, &_1, SL("_params"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 985 TSRMLS_CC);
	if (!(Z_TYPE_P(&_2) == IS_NULL)) {
		zephir_read_property(&_3, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_0, &_3, SL("_params"), PH_NOISY, "leevel/router/router.zep", 985 TSRMLS_CC);
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
	zephir_array_fetch_string(&_2, &_1, SL("_middlewares"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 995 TSRMLS_CC);
	if (!(Z_TYPE_P(&_2) == IS_NULL)) {
		zephir_read_property(&_3, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_0, &_3, SL("_middlewares"), PH_NOISY, "leevel/router/router.zep", 995 TSRMLS_CC);
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
	zephir_array_fetch_string(&_2, &_1, SL("_vars"), PH_NOISY | PH_READONLY, "leevel/router/router.zep", 1008 TSRMLS_CC);
	if (!(Z_TYPE_P(&_2) == IS_NULL)) {
		zephir_read_property(&_3, this_ptr, SL("matchedData"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_0, &_3, SL("_vars"), PH_NOISY, "leevel/router/router.zep", 1008 TSRMLS_CC);
	} else {
		array_init(&_0);
	}
	RETURN_CCTOR(&_0);

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
		zephir_read_property(&_8, this_ptr, SL("basepaths"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("basepaths"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("globalMiddlewares"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("globalMiddlewares"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

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
	zephir_create_array(&_1, 7, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("_app"), SL("app"));
	zephir_array_update_string(&_1, SL("_c"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_a"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_prefix"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_params"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_middlewares"), &__$null, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("_vars"), &__$null, PH_COPY | PH_SEPARATE);
	zend_update_static_property(leevel_router_router_ce, ZEND_STRL("matcheDataInit"), &_1);
	ZEPHIR_MM_RESTORE();

}

