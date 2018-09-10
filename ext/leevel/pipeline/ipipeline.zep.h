
extern zend_class_entry *leevel_pipeline_ipipeline_ce;

ZEPHIR_INIT_CLASS(Leevel_Pipeline_IPipeline);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_pipeline_ipipeline_then, 0, 0, 0)
	ZEND_ARG_INFO(0, end)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_pipeline_ipipeline_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Pipeline_IPipeline, send, NULL)
	PHP_ABSTRACT_ME(Leevel_Pipeline_IPipeline, through, NULL)
	PHP_ABSTRACT_ME(Leevel_Pipeline_IPipeline, then, arginfo_leevel_pipeline_ipipeline_then)
	PHP_FE_END
};
