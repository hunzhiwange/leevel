
extern zend_class_entry *leevel_pipeline_ipipeline_ce;

ZEPHIR_INIT_CLASS(Leevel_Pipeline_IPipeline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_ipipeline_send, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, passed, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_ipipeline_through, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, stage, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_ipipeline_then, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, end, Closure, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_pipeline_ipipeline_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Pipeline_IPipeline, send, arginfo_leevel_pipeline_ipipeline_send)
	PHP_ABSTRACT_ME(Leevel_Pipeline_IPipeline, through, arginfo_leevel_pipeline_ipipeline_through)
	PHP_ABSTRACT_ME(Leevel_Pipeline_IPipeline, then, arginfo_leevel_pipeline_ipipeline_then)
	PHP_FE_END
};
