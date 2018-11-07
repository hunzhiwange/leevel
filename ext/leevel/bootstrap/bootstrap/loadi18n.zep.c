
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


/**
 * 读取语言包
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.05.03
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Bootstrap_LoadI18n) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Bootstrap\\Bootstrap, LoadI18n, leevel, bootstrap_bootstrap_loadi18n, leevel_bootstrap_bootstrap_loadi18n_method_entry, 0);

	return SUCCESS;

}

/**
 * 响应
 * 
 * @param \Leevel\Kernel\IProject $project
 * @return void
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadI18n, handle) {

	zend_class_entry *_7$$4 = NULL;
	zval _5$$3, _8$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, i18nDefault, data, load, i18n, _0, _1, _2, _3$$3, _4$$3, _6$$4, _9$$4, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&i18nDefault);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&load);
	ZVAL_UNDEF(&i18n);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n\\default");
	ZEPHIR_CALL_METHOD(&i18nDefault, &_0, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, project, "iscachedi18n", NULL, 0, &i18nDefault);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&_3$$3, project, "i18ncachedpath", NULL, 0, &i18nDefault);
		zephir_check_call_status();
		ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4$$3);
		if (zephir_require_zval_ret(&_4$$3, &_3$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
		zephir_get_arrval(&_5$$3, &_4$$3);
		ZEPHIR_CPY_WRT(&data, &_5$$3);
	} else {
		ZEPHIR_INIT_VAR(&_6$$4);
		if (!_7$$4) {
		_7$$4 = zephir_fetch_class_str_ex(SL("Leevel\\I18n\\Load"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_6$$4, _7$$4);
		if (zephir_has_constructor(&_6$$4 TSRMLS_CC)) {
			ZEPHIR_INIT_VAR(&_8$$4);
			zephir_create_array(&_8$$4, 1, 0 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_9$$4, project, "i18npath", NULL, 0);
			zephir_check_call_status();
			zephir_array_fast_append(&_8$$4, &_9$$4);
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 0, &_8$$4);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&_9$$4, &_6$$4, "seti18n", NULL, 0, &i18nDefault);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$4, this_ptr, "getextend", NULL, 0, project);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&load, &_9$$4, "adddir", NULL, 0, &_10$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&data, &load, "loaddata", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&i18n);
	object_init_ex(&i18n, leevel_i18n_i18n_ce);
	ZEPHIR_CALL_METHOD(NULL, &i18n, "__construct", NULL, 56, &i18nDefault);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "i18n");
	ZEPHIR_CALL_METHOD(NULL, project, "instance", NULL, 0, &_1, &i18n);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &i18n, "addtext", NULL, 57, &i18nDefault, &data);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 获取扩展语言包
 * 
 * @param \Leevel\Kernel\IProject $project
 * @return array
 */
PHP_METHOD(Leevel_Bootstrap_Bootstrap_LoadI18n, getExtend) {

	zval result;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL, *_12 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *project, project_sub, extend, path, item, _0, _1, _2, *_3, _4$$3, _7$$3, _6$$4, _9$$5, _10$$5, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&project_sub);
	ZVAL_UNDEF(&extend);
	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &project);



	ZEPHIR_INIT_VAR(&result);
	array_init(&result);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "option");
	ZEPHIR_CALL_METHOD(&_0, project, "make", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	array_init(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_composer.i18ns");
	ZEPHIR_CALL_METHOD(&extend, &_0, "get", NULL, 0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&path, project, "path", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&extend, 0, "leevel/bootstrap/bootstrap/loadi18n.zep", 91);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&extend), _3)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "is_file", &_5, 26, &item);
		zephir_check_call_status();
		if (!(zephir_is_true(&_4$$3))) {
			ZEPHIR_INIT_LNVAR(_6$$4);
			ZEPHIR_CONCAT_VSV(&_6$$4, &path, "/", &item);
			ZEPHIR_CPY_WRT(&item, &_6$$4);
		}
		ZEPHIR_CALL_FUNCTION(&_7$$3, "is_dir", &_8, 45, &item);
		zephir_check_call_status();
		if (!(zephir_is_true(&_7$$3))) {
			ZEPHIR_INIT_NVAR(&_9$$5);
			object_init_ex(&_9$$5, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_NVAR(&_10$$5);
			ZVAL_STRING(&_10$$5, "I18n dir %s is not exist.");
			ZEPHIR_CALL_FUNCTION(&_11$$5, "sprintf", &_12, 1, &_10$$5, &item);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", &_13, 5, &_11$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$5, "leevel/bootstrap/bootstrap/loadi18n.zep", 85 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_append(&result, &item, PH_SEPARATE, "leevel/bootstrap/bootstrap/loadi18n.zep", 88);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_CTOR(&result);

}

