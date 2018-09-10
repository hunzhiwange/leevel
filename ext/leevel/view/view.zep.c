
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
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


/**
 * view 仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_View) {

	ZEPHIR_REGISTER_CLASS(Leevel\\View, View, leevel, view_view, leevel_view_view_method_entry, 0);

	/**
	 * 连接驱动
	 *
	 * @var \Leevel\View\IConnect
	 */
	zend_declare_property_null(leevel_view_view_ce, SL("connect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(leevel_view_view_ce TSRMLS_CC, 1, leevel_view_iview_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \Leevel\View\IConnect $connect
 * @return void
 */
PHP_METHOD(Leevel_View_View, __construct) {

	zval *connect, connect_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connect_sub);

	zephir_fetch_params(0, 1, 0, &connect);



	zephir_update_property_zval(this_ptr, SL("connect"), connect);

}

/**
 * call 
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
PHP_METHOD(Leevel_View_View, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _0;
	zval *method_param = NULL, *args_param = NULL, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("connect"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &args);
	zephir_check_call_status();
	RETURN_MM();

}

