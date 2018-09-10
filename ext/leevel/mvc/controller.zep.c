
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
#include "kernel/main.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * 基类控制器
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Mvc_Controller) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Mvc, Controller, leevel, mvc_controller, leevel_mvc_controller_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * 视图
	 *
	 * @var \Leevel\Mvc\IView
	 */
	zend_declare_property_null(leevel_mvc_controller_ce, SL("view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(leevel_mvc_controller_ce TSRMLS_CC, 1, leevel_mvc_icontroller_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @return void
 */
PHP_METHOD(Leevel_Mvc_Controller, __construct) {

	zval *this_ptr = getThis();



}

/**
 * 设置视图
 *
 * @param \Leevel\Mvc\IView $view
 * @return $this
 */
PHP_METHOD(Leevel_Mvc_Controller, setView) {

	zval *view, view_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);

	zephir_fetch_params(0, 1, 0, &view);



	zephir_update_property_zval(this_ptr, SL("view"), view);
	RETURN_THISW();

}

/**
 * 切换视图
 *
 * @param \Leevel\View\IView $theme
 * @return $this
 */
PHP_METHOD(Leevel_Mvc_Controller, switchView) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *theme, theme_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&theme_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &theme);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "switchview", NULL, 0, theme);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 变量赋值
 *
 * @param mixed $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Leevel_Mvc_Controller, assign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *value = NULL, value_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "assign", NULL, 0, name, value);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 获取变量赋值
 *
 * @param string|null $name
 * @return mixed
 */
PHP_METHOD(Leevel_Mvc_Controller, getAssign) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name = NULL, name_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name);

	if (!name) {
		name = &name_sub;
		name = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getassign", NULL, 0, name);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 删除变量值
 *
 * @param mixed $name
 * @return $this
 */
PHP_METHOD(Leevel_Mvc_Controller, deleteAssign) {

	zval _1;
	zval _0, _2, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("view"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "deleteAssign");
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	zephir_get_args(&_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(&_0, &_1, &_3);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 清空变量值
 *
 * @return $this
 */
PHP_METHOD(Leevel_Mvc_Controller, clearAssign) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "clearassign", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * 加载视图文件
 *
 * @param string $file
 * @param array $vars
 * @param string $ext
 * @return string
 */
PHP_METHOD(Leevel_Mvc_Controller, display) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval vars;
	zval *file_param = NULL, *vars_param = NULL, *ext = NULL, ext_sub, __$null, _0;
	zval file;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&ext_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&vars);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &file_param, &vars_param, &ext);

	zephir_get_strval(&file, file_param);
	if (!vars_param) {
		ZEPHIR_INIT_VAR(&vars);
		array_init(&vars);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&vars, vars_param);
	}
	if (!ext) {
		ext = &ext_sub;
		ext = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkview", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "display", NULL, 0, &file, &vars, ext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 验证 view
 *
 * @return void
 */
PHP_METHOD(Leevel_Mvc_Controller, checkView) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("view"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_RuntimeException, "View is not set in controller.", "leevel/mvc/controller.zep", 158);
		return;
	}

}

