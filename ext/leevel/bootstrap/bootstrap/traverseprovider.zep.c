
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"


/**
 * 遍历服务提供者
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.05.02
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_TraverseProvider) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Bootstrap\\Bootstrap, TraverseProvider, leevel, bootstrap_bootstrap_traverseprovider, leevel_bootstrap_bootstrap_traverseprovider_method_entry, 0);

	return SUCCESS;

}

/**
 * 响应
 * 
 * @param \Leevel\Kernel\IProject $project
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_TraverseProvider, handle) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_CALL_METHOD(NULL, project, "registerproviders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, project, "bootstrapproviders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

