
extern zend_class_entry *leevel_support_ijson_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_IJson);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_ijson_tojson, 0, 0, 0)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_support_ijson_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Support_IJson, toJson, arginfo_leevel_support_ijson_tojson)
	PHP_FE_END
};
