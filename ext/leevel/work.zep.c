
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * 沙盒 work
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.11.11
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Work) {

	ZEPHIR_REGISTER_CLASS_EX(Leevel, Work, leevel, work, leevel_support_facade_ce, leevel_work_method_entry, 0);

	return SUCCESS;

}

/**
 * 返回门面名字
 *
 * @return string
 */
PHP_METHOD(Leevel_Work, name) {

	zval *this_ptr = getThis();


	RETURN_STRING("work");

}

