
extern zend_class_entry *leevel_pipeline_pipeline_ce;

ZEPHIR_INIT_CLASS(Leevel_Pipeline_Pipeline);

PHP_METHOD(Leevel_Pipeline_Pipeline, __construct);
PHP_METHOD(Leevel_Pipeline_Pipeline, send);
PHP_METHOD(Leevel_Pipeline_Pipeline, through);
PHP_METHOD(Leevel_Pipeline_Pipeline, then);
PHP_METHOD(Leevel_Pipeline_Pipeline, traverseGenerator);
PHP_METHOD(Leevel_Pipeline_Pipeline, makeNextClosure);
PHP_METHOD(Leevel_Pipeline_Pipeline, stageGenerator);
PHP_METHOD(Leevel_Pipeline_Pipeline, stageCallback);
PHP_METHOD(Leevel_Pipeline_Pipeline, parse);
zend_object *zephir_init_properties_Leevel_Pipeline_Pipeline(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_pipeline___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_pipeline_then, 0, 0, 0)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_pipeline_stagegenerator, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, stage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_pipeline_stagecallback, 0, 0, 1)
	ZEND_ARG_INFO(0, stages)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_pipeline_parse, 0, 0, 1)
	ZEND_ARG_INFO(0, stage)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_pipeline_pipeline_method_entry) {
	PHP_ME(Leevel_Pipeline_Pipeline, __construct, arginfo_leevel_pipeline_pipeline___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Pipeline_Pipeline, send, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Pipeline_Pipeline, through, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Pipeline_Pipeline, then, arginfo_leevel_pipeline_pipeline_then, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Pipeline_Pipeline, traverseGenerator, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Pipeline_Pipeline, makeNextClosure, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Pipeline_Pipeline, stageGenerator, arginfo_leevel_pipeline_pipeline_stagegenerator, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Pipeline_Pipeline, stageCallback, arginfo_leevel_pipeline_pipeline_stagecallback, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Pipeline_Pipeline, parse, arginfo_leevel_pipeline_pipeline_parse, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
