
extern zend_class_entry *leevel_support_iarray_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_IArray);

ZEPHIR_INIT_FUNCS(leevel_support_iarray_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Support_IArray, toArray, NULL)
	PHP_FE_END
};
