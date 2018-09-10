
extern zend_class_entry *leevel_support_ihtml_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_IHtml);

ZEPHIR_INIT_FUNCS(leevel_support_ihtml_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Support_IHtml, toHtml, NULL)
	PHP_FE_END
};
