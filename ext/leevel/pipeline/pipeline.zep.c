
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
#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * 管道实现类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.05
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Pipeline_Pipeline) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Pipeline, Pipeline, leevel, pipeline_pipeline, leevel_pipeline_pipeline_method_entry, 0);

	/**
	 * 容器
	 *
	 * @var \Leevel\Di\IContainer
	 */
	zend_declare_property_null(leevel_pipeline_pipeline_ce, SL("container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 管道传递的对象
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_pipeline_pipeline_ce, SL("passed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 管道中所有执行工序
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_pipeline_pipeline_ce, SL("stage"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 迭代器
	 *
	 * @var \Leevel\Collection\Collection
	 */
	zend_declare_property_null(leevel_pipeline_pipeline_ce, SL("generator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	leevel_pipeline_pipeline_ce->create_object = zephir_init_properties_Leevel_Pipeline_Pipeline;

	zend_class_implements(leevel_pipeline_pipeline_ce TSRMLS_CC, 1, leevel_pipeline_ipipeline_ce);
	return SUCCESS;

}

/**
 * 创建一个管道
 *
 * @param \Leevel\Di\IContainer $container
 * @return void
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, __construct) {

	zval *container, container_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&container_sub);

	zephir_fetch_params(0, 1, 0, &container);



	zephir_update_property_zval(this_ptr, SL("container"), container);

}

/**
 * 将传输对象传入管道
 *
 * @return $this
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, send) {

	zval item, args, passed, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&passed);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters", "leevel/pipeline/pipeline.zep", 88);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, &args, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 91 TSRMLS_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&passed);
		zephir_array_fetch_long(&passed, &args, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 91 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&passed, &args);
	}
	zephir_is_iterable(&passed, 0, "leevel/pipeline/pipeline.zep", 97);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&passed), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		zephir_update_property_array_append(this_ptr, SL("passed"), &item TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_THIS();

}

/**
 * 设置管道中的执行工序
 *
 * @return $this
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, through) {

	zval item, stage, args, _0, *_1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_NVAR(&args);
	zephir_get_args(&args);
	if (ZEPHIR_IS_EMPTY(&args)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_BadMethodCallException, "Wrong number of parameters", "leevel/pipeline/pipeline.zep", 112);
		return;
	}
	ZEPHIR_OBS_VAR(&_0);
	zephir_array_fetch_long(&_0, &args, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 115 TSRMLS_CC);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&stage);
		zephir_array_fetch_long(&stage, &args, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 115 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&stage, &args);
	}
	zephir_is_iterable(&stage, 0, "leevel/pipeline/pipeline.zep", 121);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&stage), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		zephir_update_property_array_append(this_ptr, SL("stage"), &item TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	RETURN_THIS();

}

/**
 * 执行管道工序响应结果
 * 
 * @param callable|null $end
 * @since 2018.01.03
 * @return mixed
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, then) {

	zval _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *end = NULL, end_sub, __$null, stage, _0, _1, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&end_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &end);

	if (!end) {
		end = &end_sub;
		end = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("stage"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&stage, &_0);
	if (zephir_is_true(end)) {
		if (!(zephir_is_callable(end TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Pipeline then must be a callable.", "leevel/pipeline/pipeline.zep", 139);
			return;
		}
		zephir_array_append(&stage, end, PH_SEPARATE, "leevel/pipeline/pipeline.zep", 142);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "stagegenerator", NULL, 0, &stage);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("generator"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "traverseGenerator");
	zephir_array_fast_append(&_2, &_3);
	zephir_read_property(&_0, this_ptr, SL("passed"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 遍历迭代器
 *
 * @since 2018.01.03
 * @return mixed
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, traverseGenerator) {

	zval _9;
	zend_class_entry *_8;
	zend_bool _2, _5, _13;
	zval args, current, next, params, item, _0, _1, _3, _4, _6, _7, _10, _11, _12, *_14$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&current);
	ZVAL_UNDEF(&next);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("generator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "valid", NULL, 0);
	zephir_check_call_status();
	_2 = !zephir_is_true(&_1);
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, SL("generator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4, &_3, "next", NULL, 0);
		zephir_check_call_status();
		_2 = zephir_is_true(&_4);
	}
	_5 = _2;
	if (!(_5)) {
		zephir_read_property(&_6, this_ptr, SL("generator"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_7, &_6, "valid", NULL, 0);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_7);
	}
	if (_5) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&args);
	zephir_get_args(&args);
	_8 = zephir_fetch_class_str_ex(SL("Closure"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_9, this_ptr);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "makeNextClosure");
	zephir_array_fast_append(&_9, &_10);
	ZEPHIR_CALL_CE_STATIC(&next, _8, "fromcallable", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&args);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 31, &args, &next);
	ZEPHIR_UNREF(&args);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("generator"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&current, &_11, "current", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_10);
	zephir_gettype(&_10, &current TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "array");
	_13 = ZEPHIR_IS_IDENTICAL(&_12, &_10);
	if (_13) {
		_13 = 3 == zephir_fast_count_int(&current TSRMLS_CC);
	}
	if (_13) {
		ZEPHIR_MAKE_REF(&current);
		ZEPHIR_CALL_FUNCTION(&params, "array_pop", NULL, 133, &current);
		ZEPHIR_UNREF(&current);
		zephir_check_call_status();
		zephir_is_iterable(&params, 0, "leevel/pipeline/pipeline.zep", 181);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&params), _14$$4)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _14$$4);
			zephir_array_append(&args, &item, PH_SEPARATE, "leevel/pipeline/pipeline.zep", 179);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&item);
	}
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &current, &args);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 下一次迭代执行回调
 *
 * @since 2018.01.12
 * @return mixed
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, makeNextClosure) {

	zval _1;
	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_0, this_ptr);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "traverseGenerator");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_get_args(&_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 工序迭代器
 * 添加一个空的迭代器，第一次迭代 next 自动移除
 * zephir 不支持 yield，用集合替代
 *
 * @param array $stage
 * @return \Leevel\Collection\Collection
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, stageGenerator) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stage_param = NULL, item, _0, *_1, _2$$3;
	zval stage, temp;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stage_param);

	zephir_get_arrval(&stage, stage_param);


	ZEPHIR_INIT_VAR(&temp);
	array_init(&temp);
	ZVAL_NULL(&_0);
	ZEPHIR_MAKE_REF(&stage);
	ZEPHIR_CALL_FUNCTION(NULL, "array_unshift", NULL, 31, &stage, &_0);
	ZEPHIR_UNREF(&stage);
	zephir_check_call_status();
	zephir_is_iterable(&stage, 0, "leevel/pipeline/pipeline.zep", 216);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&stage), _1)
	{
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _1);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "stagecallback", &_3, 0, &item);
		zephir_check_call_status();
		zephir_array_append(&temp, &_2$$3, PH_SEPARATE, "leevel/pipeline/pipeline.zep", 213);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	object_init_ex(return_value, leevel_collection_collection_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 90, &temp);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 工序回调
 *
 * @param mixed $stages
 * @return null|callable
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, stageCallback) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stages, stages_sub, stage, params, method, temp, _0$$5, _1$$5, _2$$5, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stages_sub);
	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stages);



	if (Z_TYPE_P(stages) == IS_NULL) {
		RETURN_MM_NULL();
	}
	if (zephir_is_callable(stages TSRMLS_CC)) {
		RETVAL_ZVAL(stages, 1, 0);
		RETURN_MM();
	} else {
		ZEPHIR_CALL_METHOD(&temp, this_ptr, "parse", NULL, 0, stages);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&stage);
		zephir_array_fetch_long(&stage, &temp, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 237 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&params);
		zephir_array_fetch_long(&params, &temp, 1, PH_NOISY, "leevel/pipeline/pipeline.zep", 238 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$5);
		ZVAL_STRING(&_0$$5, "@");
		ZEPHIR_INIT_VAR(&_1$$5);
		zephir_fast_strpos(&_1$$5, &stage, &_0$$5, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_1$$5)) {
			ZEPHIR_INIT_NVAR(&temp);
			zephir_fast_explode_str(&temp, SL("@"), &stage, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&stage);
			zephir_array_fetch_long(&stage, &temp, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 242 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&method);
			zephir_array_fetch_long(&method, &temp, 1, PH_NOISY, "leevel/pipeline/pipeline.zep", 243 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&method);
			ZVAL_STRING(&method, "handle");
		}
		zephir_read_property(&_2$$5, this_ptr, SL("container"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_3$$5, &_2$$5, "make", NULL, 0, &stage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&stage, &_3$$5);
		if (Z_TYPE_P(&stage) != IS_OBJECT) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Stage is invalid.", "leevel/pipeline/pipeline.zep", 251);
			return;
		}
		zephir_create_array(return_value, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(return_value, &stage);
		zephir_array_fast_append(return_value, &method);
		zephir_array_fast_append(return_value, &params);
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * 解析工序
 *
 * @param string $stage
 * @return array
 */
PHP_METHOD(Leevel_Pipeline_Pipeline, parse) {

	zend_string *_6;
	zend_ulong _5;
	zval newArgs;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *stage_param = NULL, name, args, temp, key, item, _0, _1, _2, *_4, _3$$3, _7$$4, _8$$4;
	zval stage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&stage);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&temp);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&newArgs);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &stage_param);

	zephir_get_strval(&stage, stage_param);


	ZEPHIR_INIT_VAR(&newArgs);
	array_init(&newArgs);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_explode_str(&_0, SL(":"), &stage, 2  TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	ZVAL_LONG(&_2, 2);
	ZEPHIR_CALL_FUNCTION(&temp, "array_pad", NULL, 83, &_0, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&name);
	zephir_array_fetch_long(&name, &temp, 0, PH_NOISY, "leevel/pipeline/pipeline.zep", 274 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&args);
	zephir_array_fetch_long(&args, &temp, 1, PH_NOISY, "leevel/pipeline/pipeline.zep", 275 TSRMLS_CC);
	if (Z_TYPE_P(&args) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_fast_explode_str(&_3$$3, SL(","), &args, LONG_MAX TSRMLS_CC);
		ZEPHIR_CPY_WRT(&args, &_3$$3);
	}
	zephir_is_iterable(&args, 0, "leevel/pipeline/pipeline.zep", 285);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&args), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&key, _6);
		} else {
			ZVAL_LONG(&key, _5);
		}
		ZEPHIR_INIT_NVAR(&item);
		ZVAL_COPY(&item, _4);
		ZEPHIR_INIT_LNVAR(_7$$4);
		ZEPHIR_CALL_FUNCTION(&_8$$4, "ctype_digit", &_9, 12, &item);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$4)) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_LONG(&_7$$4, zephir_get_intval(&item));
		} else {
			ZEPHIR_CPY_WRT(&_7$$4, &item);
		}
		zephir_array_update_zval(&newArgs, &key, &_7$$4, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_INIT_NVAR(&key);
	zephir_create_array(return_value, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &name);
	zephir_array_fast_append(return_value, &newArgs);
	RETURN_MM();

}

zend_object *zephir_init_properties_Leevel_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("stage"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("stage"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("passed"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("passed"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

