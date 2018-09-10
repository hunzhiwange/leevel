
extern zend_class_entry *leevel_log_iconnect_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_IConnect);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_iconnect_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_iconnect_flush, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, datas, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_iconnect_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Log_IConnect, setOption, arginfo_leevel_log_iconnect_setoption)
	PHP_ABSTRACT_ME(Leevel_Log_IConnect, flush, arginfo_leevel_log_iconnect_flush)
	PHP_FE_END
};
