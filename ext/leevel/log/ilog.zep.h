
extern zend_class_entry *leevel_log_ilog_ce;

ZEPHIR_INIT_CLASS(Leevel_Log_ILog);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_setoption, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_emergency, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_alert, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_critical, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_error, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_warning, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_notice, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_info, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_debug, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_log, 0, 0, 2)
	ZEND_ARG_INFO(0, level)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_ARRAY_INFO(0, context, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_all, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_count, 0, 0, 0)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_filter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, filter, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_log_ilog_processor, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, processor, Closure, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_log_ilog_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Log_ILog, setOption, arginfo_leevel_log_ilog_setoption)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, emergency, arginfo_leevel_log_ilog_emergency)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, alert, arginfo_leevel_log_ilog_alert)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, critical, arginfo_leevel_log_ilog_critical)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, error, arginfo_leevel_log_ilog_error)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, warning, arginfo_leevel_log_ilog_warning)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, notice, arginfo_leevel_log_ilog_notice)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, info, arginfo_leevel_log_ilog_info)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, debug, arginfo_leevel_log_ilog_debug)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, log, arginfo_leevel_log_ilog_log)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, flush, NULL)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, clear, arginfo_leevel_log_ilog_clear)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, all, arginfo_leevel_log_ilog_all)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, count, arginfo_leevel_log_ilog_count)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, filter, arginfo_leevel_log_ilog_filter)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, processor, arginfo_leevel_log_ilog_processor)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, isMonolog, NULL)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, getMonolog, NULL)
	PHP_ABSTRACT_ME(Leevel_Log_ILog, getConnect, NULL)
	PHP_FE_END
};
