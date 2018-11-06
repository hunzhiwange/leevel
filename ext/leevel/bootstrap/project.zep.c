
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/require.h"
#include "kernel/string.h"


/**
 * 项目管理.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.01.14
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Project) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel\\Bootstrap, Project, leevel, bootstrap_project, leevel_di_container_ce, leevel_bootstrap_project_method_entry, 0);

	/**
	 * 当前项目实例.
	 *
	 * @var static
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("project"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	/**
	 * 项目基础路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 应用路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("appPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 公共路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("commonPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 运行时路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("runtimePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 存储路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("storagePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 资源路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("publicPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 主题路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("themesPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("optionPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 语言包路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("i18nPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 环境变量路径.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("envPath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 环境变量文件.
	 *
	 * @var string
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("envFile"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 延迟载入服务提供者.
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("deferredProviders"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 服务提供者引导
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_bootstrap_project_ce, SL("providerBootstraps"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 是否已经初始化引导
	 *
	 * @var bool
	 */
	zend_declare_property_bool(leevel_bootstrap_project_ce, SL("isBootstrap"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_bootstrap_project_ce->create_object = zephir_init_properties_Leevel_Bootstrap_Project;

	zend_class_implements(leevel_bootstrap_project_ce TSRMLS_CC, 1, leevel_kernel_iproject_ce);
	return SUCCESS;

}

/**
 * 构造函数
 * 项目中通过 singletons 生成单一实例.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);

	if (!path) {
		path = &path_sub;
		path = &__$null;
	}


	if (zephir_is_true(path)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpath", NULL, 0, path);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbaseservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerbaseprovider", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 禁止克隆.
 */
PHP_METHOD(Leevel_Bootstrap_Project, __clone) {

	zval *this_ptr = getThis();


	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "Project disallowed clone.", "leevel/bootstrap/project.zep", 166);
	return;

}

/**
 * 返回项目.
 *
 * @param string $path
 *
 * @return static
 * @codeCoverageIgnore
 */
PHP_METHOD(Leevel_Bootstrap_Project, singletons) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, __$null, _0, _1$$3, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);

	if (!path) {
		path = &path_sub;
		path = &__$null;
	}


	zephir_read_static_property_ce(&_0, leevel_bootstrap_project_ce, SL("project"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		zephir_read_static_property_ce(&_1$$3, leevel_bootstrap_project_ce, SL("project"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_1$$3);
	} else {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, leevel_bootstrap_project_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 69, path);
		zephir_check_call_status();
		zend_update_static_property(leevel_bootstrap_project_ce, ZEND_STRL("project"), &_2$$4);
		zephir_read_static_property_ce(&_3$$4, leevel_bootstrap_project_ce, SL("project"), PH_NOISY_CC | PH_READONLY);
		RETURN_CTOR(&_3$$4);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 程序版本.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, version) {

	zval *this_ptr = getThis();


	RETURN_STRING("1.0.0");

}

/**
 * 是否以扩展方式运行.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, runWithExtension) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "leevel");
	ZEPHIR_RETURN_CALL_FUNCTION("extension_loaded", NULL, 70, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为 Console.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, console) {

	zval _0, _1, _4, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(Z_TYPE_P(&_0) == IS_OBJECT)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_GET_CONSTANT(&_2$$3, "PHP_SAPI");
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_STRING(&_3$$3, "cli");
		RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_3$$3, &_2$$3));
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "request");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_4, "iscli", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Bootstrap_Project, make) {

	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *name = NULL, name_sub, *args_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &args_param);

	ZEPHIR_SEPARATE_PARAM(name);
	if (!args_param) {
		ZEPHIR_INIT_VAR(&args);
		array_init(&args);
	} else {
		zephir_get_arrval(&args, args_param);
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getalias", NULL, 0, name);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, name)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerdeferredprovider", NULL, 0, name);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_PARENT(leevel_bootstrap_project_ce, getThis(), "make", &_2, 0, name, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 设置项目路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("path"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 基础路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, path) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_1);
	RETURN_MM();

}

/**
 * 设置应用路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setAppPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("appPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 应用路径.
 *
 * @param bool|string $app
 * @param string      $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, appPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path;
	zval *app = NULL, app_sub, *path_param = NULL, __$false, _0, _1, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &app, &path_param);

	if (!app) {
		app = &app_sub;
		app = &__$false;
	}
	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("appPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("appPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "application");
	}
	ZEPHIR_INIT_VAR(&_3);
	if (zephir_is_true(app)) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "normalizeapp", NULL, 0, app);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3);
		ZEPHIR_CONCAT_SV(&_3, "/", &_4);
	} else {
		ZEPHIR_CPY_WRT(&_3, app);
	}
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVV(return_value, &_0, &_3, &_5);
	RETURN_MM();

}

/**
 * 取得应用主题目录.
 *
 * @param bool|string $app
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, themePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app = NULL, app_sub, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &app);

	if (!app) {
		app = &app_sub;
		app = &__$false;
	}


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "apppath", NULL, 0, app);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/ui/theme");
	RETURN_MM();

}

/**
 * 设置公共路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setCommonPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("commonPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 公共路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, commonPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("commonPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("commonPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "common");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置运行时路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setRuntimePath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("runtimePath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 运行路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, runtimePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("runtimePath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("runtimePath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "runtime");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置存储路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setStoragePath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("storagePath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 附件路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, storagePath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("storagePath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("storagePath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "storage");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置资源路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setPublicPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("publicPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 资源路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, publicPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("publicPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("publicPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "public");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置主题路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setThemesPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("themesPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 主题路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, themesPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("themesPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("themesPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "themes");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置配置路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setOptionPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("optionPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 配置路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, optionPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path_param = NULL, _0, _1, _2, _3;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path_param);

	if (!path_param) {
		ZEPHIR_INIT_VAR(&path);
		ZVAL_STRING(&path, "");
	} else {
		zephir_get_strval(&path, path_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("optionPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("optionPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "option");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, &path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置语言包路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setI18nPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("i18nPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 语言包路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, i18nPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *path = NULL, path_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &path);

	if (!path) {
		path = &path_sub;
		ZEPHIR_INIT_VAR(path);
		ZVAL_STRING(path, "");
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("i18nPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_read_property(&_0, this_ptr, SL("i18nPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_2, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_CONCAT_VSS(&_0, &_2, "/", "i18n");
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "normalizepath", NULL, 0, path);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_0, &_3);
	RETURN_MM();

}

/**
 * 设置环境变量路径.
 *
 * @param string $path
 */
PHP_METHOD(Leevel_Bootstrap_Project, setEnvPath) {

	zval *path_param = NULL;
	zval path;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	zephir_update_property_zval(this_ptr, SL("envPath"), &path);
	ZEPHIR_MM_RESTORE();

}

/**
 * 环境变量路径.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, envPath) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("envPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("envPath"), PH_NOISY_CC);
	} else {
		zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 设置环境变量文件.
 *
 * @param string $file
 */
PHP_METHOD(Leevel_Bootstrap_Project, setEnvFile) {

	zval *file_param = NULL;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &file_param);

	zephir_get_strval(&file, file_param);


	zephir_update_property_zval(this_ptr, SL("envFile"), &file);
	ZEPHIR_MM_RESTORE();

}

/**
 * 取得环境变量文件.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, envFile) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("envFile"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_0, this_ptr, SL("envFile"), PH_NOISY_CC);
	} else {
		ZVAL_STRING(&_0, ".env");
	}
	RETURN_CCTOR(&_0);

}

/**
 * 取得环境变量完整路径.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, fullEnvPath) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "envpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "envfile", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSV(return_value, &_0, "/", &_1);
	RETURN_MM();

}

/**
 * 返回语言包缓存路径.
 *
 * @param string $i18n
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, i18nCachedPath) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *i18n_param = NULL, _0;
	zval i18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i18n_param);

	zephir_get_strval(&i18n, i18n_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "runtimepath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VSVS(return_value, &_0, "/i18n/", &i18n, ".php");
	RETURN_MM();

}

/**
 * 是否存在语言包缓存.
 *
 * @param string $i18n
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, isCachedI18n) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *i18n_param = NULL, _0;
	zval i18n;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &i18n_param);

	zephir_get_strval(&i18n, i18n_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "i18ncachedpath", NULL, 0, &i18n);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 26, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回配置缓存路径.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, optionCachedPath) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "runtimepath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/bootstrap/option.php");
	RETURN_MM();

}

/**
 * 是否存在配置缓存.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, isCachedOption) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "optioncachedpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 26, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 返回路由缓存路径.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, routerCachedPath) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "runtimepath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VS(return_value, &_0, "/bootstrap/router.php");
	RETURN_MM();

}

/**
 * 是否存在路由缓存.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, isCachedRouter) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "routercachedpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("is_file", NULL, 26, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 取得 composer.
 *
 * @return \Composer\Autoload\ClassLoader
 * @codeCoverageIgnore
 */
PHP_METHOD(Leevel_Bootstrap_Project, composer) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("path"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &_0, "/vendor/autoload.php");
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_2);
	if (zephir_require_zval_ret(&_2, &_1 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&_2);

}

/**
 * 获取命名空间路径.
 *
 * @param string $namespaces
 *
 * @return null|string
 * @codeCoverageIgnore
 */
PHP_METHOD(Leevel_Bootstrap_Project, getPathByComposer) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *namespaces_param = NULL, prefix, tmp, _0, _1, _2, _3, _4, _5, _6;
	zval namespaces;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&namespaces);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &namespaces_param);

	zephir_get_strval(&namespaces, namespaces_param);


	ZEPHIR_INIT_VAR(&tmp);
	zephir_fast_explode_str(&tmp, SL("\\"), &namespaces, LONG_MAX TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "composer", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&prefix, &_0, "getprefixespsr4", NULL, 0);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &tmp, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 595 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_1, "\\");
	if (!(zephir_array_isset(&prefix, &_2))) {
		RETURN_MM_NULL();
	}
	zephir_array_fetch_long(&_4, &tmp, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 599 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VS(&_5, &_4, "\\");
	zephir_array_fetch(&_3, &prefix, &_5, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 599 TSRMLS_CC);
	zephir_array_fetch_long(&_6, &_3, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 599 TSRMLS_CC);
	zephir_array_update_long(&tmp, 0, &_6, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	zephir_fast_join_str(return_value, SL("/"), &tmp TSRMLS_CC);
	RETURN_MM();

}

/**
 * 是否开启 debug.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, debug) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "debug");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 是否为开发环境.
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, development) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "environment", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_STRING_IDENTICAL(&_0, "development"));

}

/**
 * 运行环境.
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, environment) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "environment");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建服务提供者.
 *
 * @param string $provider
 *
 * @return \Leevel\Di\Provider
 */
PHP_METHOD(Leevel_Bootstrap_Project, makeProvider) {

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider_param = NULL, _0;
	zval provider;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider_param);

	zephir_get_strval(&provider, provider_param);


	zephir_fetch_safe_class(&_0, &provider);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM();

}

/**
 * 执行 bootstrap.
 *
 * @param \Leevel\Di\Provider $provider
 */
PHP_METHOD(Leevel_Bootstrap_Project, callProviderBootstrap) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	if (!((zephir_method_exists_ex(provider, SL("bootstrap") TSRMLS_CC) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, provider);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "bootstrap");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "call", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 初始化项目.
 *
 * @param array $bootstraps
 */
PHP_METHOD(Leevel_Bootstrap_Project, bootstrap) {

	zend_class_entry *_4$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *bootstraps_param = NULL, value, _0, *_1, _2$$4, _3$$4;
	zval bootstraps;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&bootstraps);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bootstraps_param);

	zephir_get_arrval(&bootstraps, bootstraps_param);


	zephir_read_property(&_0, this_ptr, SL("isBootstrap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_is_iterable(&bootstraps, 0, "leevel/bootstrap/project.zep", 679);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&bootstraps), _1)
	{
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _1);
		ZEPHIR_INIT_NVAR(&_2$$4);
		zephir_fetch_safe_class(&_3$$4, &value);
		_4$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$4), Z_STRLEN_P(&_3$$4), ZEND_FETCH_CLASS_AUTO);
		object_init_ex(&_2$$4, _4$$4);
		if (zephir_has_constructor(&_2$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "handle", NULL, 0, this_ptr);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_MM_RESTORE();

}

/**
 * 是否已经初始化引导
 *
 * @return bool
 */
PHP_METHOD(Leevel_Bootstrap_Project, isBootstrap) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isBootstrap");

}

/**
 * 框架基础提供者 register.
 *
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerProviders) {

	zval _3;
	zval tmp, alias, deferredAlias, providers, provider, providerInstance, _0, _1, _2, _4, *_5, _7, _8, _9, *_10;
	zephir_fcall_cache_entry *_6 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&deferredAlias);
	ZVAL_UNDEF(&providers);
	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&providerInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("isBootstrap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "option");
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "make", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	zephir_array_fast_append(&_3, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	zephir_array_fast_append(&_3, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "_deferred_providers");
	ZEPHIR_CALL_METHOD(&tmp, &_1, "get", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_array_fetch_long(&_4, &tmp, 0, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 705 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("deferredProviders"), &_4);
	ZEPHIR_OBS_VAR(&deferredAlias);
	zephir_array_fetch_long(&deferredAlias, &tmp, 1, PH_NOISY, "leevel/bootstrap/project.zep", 706 TSRMLS_CC);
	zephir_is_iterable(&deferredAlias, 0, "leevel/bootstrap/project.zep", 712);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&deferredAlias), _5)
	{
		ZEPHIR_INIT_NVAR(&alias);
		ZVAL_COPY(&alias, _5);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", &_6, 0, &alias);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&alias);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "option");
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "make", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "_composer.providers");
	ZEPHIR_CALL_METHOD(&providers, &_7, "get", NULL, 0, &_8, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_9, "array_values", NULL, 32, &providers);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&providers, &_9);
	zephir_is_iterable(&providers, 0, "leevel/bootstrap/project.zep", 723);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&providers), _10)
	{
		ZEPHIR_INIT_NVAR(&provider);
		ZVAL_COPY(&provider, _10);
		ZEPHIR_CALL_METHOD(&providerInstance, this_ptr, "register", &_11, 0, &provider);
		zephir_check_call_status();
		if ((zephir_method_exists_ex(&providerInstance, SL("bootstrap") TSRMLS_CC) == SUCCESS)) {
			zephir_update_property_array_append(this_ptr, SL("providerBootstraps"), &providerInstance TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&provider);
	RETURN_THIS();

}

/**
 * 执行框架基础提供者引导
 *
 * @return $this
 */
PHP_METHOD(Leevel_Bootstrap_Project, bootstrapProviders) {

	zval __$true, __$false, item, _0, _1, *_2;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("isBootstrap"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("providerBootstraps"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "leevel/bootstrap/project.zep", 743);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callproviderbootstrap", &_3, 0, &item);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	if (1) {
		zephir_update_property_zval(this_ptr, SL("isBootstrap"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isBootstrap"), &__$false);
	}
	RETURN_THIS();

}

/**
 * 注册服务提供者.
 *
 * @param \Leevel\Di\Provider|string $provider
 *
 * @return \Leevel\Di\Provider
 */
PHP_METHOD(Leevel_Bootstrap_Project, register) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider, provider_sub, providerInstance, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider_sub);
	ZVAL_UNDEF(&providerInstance);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider);



	if (Z_TYPE_P(provider) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&providerInstance, this_ptr, "makeprovider", NULL, 0, provider);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&providerInstance, provider);
	}
	if ((zephir_method_exists_ex(&providerInstance, SL("register") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(NULL, &providerInstance, "register", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isbootstrap", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "callproviderbootstrap", NULL, 0, &providerInstance);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&providerInstance);

}

/**
 * 注册基础服务
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseServices) {

	zval _1, _2;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "project");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "instance", NULL, 0, &_0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Bootstrap\\Project");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Di\\IContainer");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Kernel\\IProject");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "app");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("project"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Http\\IRequest");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Http\\Request");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("request"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Option\\IOption");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\Option\\Option");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("option"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\I18n\\I18n");
	zephir_array_fast_append(&_2, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "Leevel\\I18n\\II18n");
	zephir_array_fast_append(&_2, &_0);
	zephir_array_update_string(&_1, SL("i18n"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "alias", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册基础服务提供者.
 *
 * @codeCoverageIgnore
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseProvider) {

	zval _0, _2, _3;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, leevel_event_provider_register_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 71, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, leevel_log_provider_register_ce);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 72, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, leevel_router_provider_register_ce);
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 73, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "register", &_1, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册延迟载入服务提供者.
 *
 * @param string $provider
 */
PHP_METHOD(Leevel_Bootstrap_Project, registerDeferredProvider) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *provider_param = NULL, providerInstance, _0, _1, _2, _3;
	zval provider;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&provider);
	ZVAL_UNDEF(&providerInstance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &provider_param);

	zephir_get_strval(&provider, provider_param);


	zephir_read_property(&_0, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &provider))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_2, &_1, &provider, PH_NOISY | PH_READONLY, "leevel/bootstrap/project.zep", 832 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&providerInstance, this_ptr, "register", NULL, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "callproviderbootstrap", NULL, 0, &providerInstance);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_3, &provider, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化应用名字.
 *
 * @param bool|string $app
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, normalizeApp) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &app);



	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_TRUE_IDENTICAL(app)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_STRING(&_2, "app_name");
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "make", NULL, 0, &_2);
		zephir_check_call_status();
		if (zephir_is_true(&_1)) {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_STRING(&_2, "app_name");
			ZEPHIR_CALL_METHOD(&_0, this_ptr, "make", NULL, 0, &_2);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_0);
			ZVAL_STRING(&_0, "app");
		}
	} else {
		ZEPHIR_CPY_WRT(&_0, app);
	}
	zephir_fast_strtolower(return_value, &_0);
	RETURN_MM();

}

/**
 * 格式化路径.
 *
 * @param string $path
 *
 * @return string
 */
PHP_METHOD(Leevel_Bootstrap_Project, normalizePath) {

	zval *path_param = NULL, _0;
	zval path, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(&path, path_param);


	ZEPHIR_INIT_VAR(&_0);
	if (!(Z_TYPE_P(&path) == IS_UNDEF) && Z_STRLEN_P(&path)) {
		ZEPHIR_INIT_VAR(&_1);
		ZEPHIR_CONCAT_SV(&_1, "/", &path);
		ZEPHIR_CPY_WRT(&_0, &_1);
	} else {
		ZEPHIR_CPY_WRT(&_0, &path);
	}
	RETURN_CCTOR(&_0);

}

zend_object *zephir_init_properties_Leevel_Bootstrap_Project(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("providerBootstraps"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("providerBootstraps"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("alias"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("alias"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("singletons"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("singletons"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("instances"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("instances"), &_7$$6);
		}
		zephir_read_property(&_8, this_ptr, SL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_8) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_9$$7);
			array_init(&_9$$7);
			zephir_update_property_zval(this_ptr, SL("services"), &_9$$7);
		}
		zephir_read_property(&_10, this_ptr, SL("deferredProviders"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_10) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_11$$8);
			array_init(&_11$$8);
			zephir_update_property_zval(this_ptr, SL("deferredProviders"), &_11$$8);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

