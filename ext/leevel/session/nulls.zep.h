
extern zend_class_entry *leevel_session_nulls_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Nulls);

PHP_METHOD(Leevel_Session_Nulls, open);
PHP_METHOD(Leevel_Session_Nulls, close);
PHP_METHOD(Leevel_Session_Nulls, read);
PHP_METHOD(Leevel_Session_Nulls, write);
PHP_METHOD(Leevel_Session_Nulls, destroy);
PHP_METHOD(Leevel_Session_Nulls, gc);
PHP_METHOD(Leevel_Session_Nulls, getCache);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_nulls_open, 0, 0, 2)
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_nulls_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_nulls_write, 0, 0, 2)
	ZEND_ARG_INFO(0, sessionid)
	ZEND_ARG_INFO(0, sessiondata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_nulls_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_nulls_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_nulls_method_entry) {
	PHP_ME(Leevel_Session_Nulls, open, arginfo_leevel_session_nulls_open, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Nulls, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Nulls, read, arginfo_leevel_session_nulls_read, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Nulls, write, arginfo_leevel_session_nulls_write, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Nulls, destroy, arginfo_leevel_session_nulls_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Nulls, gc, arginfo_leevel_session_nulls_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Nulls, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
