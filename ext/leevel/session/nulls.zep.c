
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
#include "kernel/memory.h"


/**
 * session.nulls.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.08.17
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_Nulls) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Session, Nulls, leevel, session_nulls, leevel_session_nulls_method_entry, 0);

	zend_class_implements(leevel_session_nulls_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("sessionhandlerinterface")));
	return SUCCESS;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Nulls, open) {

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
PHP_METHOD(Leevel_Session_Nulls, close) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Nulls, read) {

	zval *sessionid, sessionid_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid_sub);

	zephir_fetch_params(0, 1, 0, &sessionid);



	array_init(return_value);
	return;

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Nulls, write) {

	zval *sessionid, sessionid_sub, *sessiondata, sessiondata_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid_sub);
	ZVAL_UNDEF(&sessiondata_sub);

	zephir_fetch_params(0, 2, 0, &sessionid, &sessiondata);



	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Nulls, destroy) {

	zval *sessionid, sessionid_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionid_sub);

	zephir_fetch_params(0, 1, 0, &sessionid);



	RETURN_BOOL(1);

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Leevel_Session_Nulls, gc) {

	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);

	zephir_fetch_params(0, 1, 0, &maxlifetime);



	RETURN_BOOL(1);

}

/**
 * 返回缓存仓储.
 */
PHP_METHOD(Leevel_Session_Nulls, getCache) {

	zval *this_ptr = getThis();



}

