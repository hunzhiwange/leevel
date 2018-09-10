
extern zend_class_entry *leevel_support_debug_console_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_Debug_Console);

PHP_METHOD(Leevel_Support_Debug_Console, trace);
PHP_METHOD(Leevel_Support_Debug_Console, jsonTrace);
PHP_METHOD(Leevel_Support_Debug_Console, getOutputToConsole);
PHP_METHOD(Leevel_Support_Debug_Console, normalizeLog);
PHP_METHOD(Leevel_Support_Debug_Console, formatMessages);
PHP_METHOD(Leevel_Support_Debug_Console, formatMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_debug_console_trace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, log, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_debug_console_jsontrace, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, log, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_debug_console_getoutputtoconsole, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, trace, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_debug_console_normalizelog, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, log, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_debug_console_formatmessages, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, messages, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_debug_console_formatmessage, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, item, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_support_debug_console_method_entry) {
	PHP_ME(Leevel_Support_Debug_Console, trace, arginfo_leevel_support_debug_console_trace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Debug_Console, jsonTrace, arginfo_leevel_support_debug_console_jsontrace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Debug_Console, getOutputToConsole, arginfo_leevel_support_debug_console_getoutputtoconsole, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Debug_Console, normalizeLog, arginfo_leevel_support_debug_console_normalizelog, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Debug_Console, formatMessages, arginfo_leevel_support_debug_console_formatmessages, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Debug_Console, formatMessage, arginfo_leevel_support_debug_console_formatmessage, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
