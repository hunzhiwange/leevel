
extern zend_class_entry *leevel_session_connect_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Connect);

PHP_METHOD(Leevel_Session_Connect, __construct);
PHP_METHOD(Leevel_Session_Connect, open);
PHP_METHOD(Leevel_Session_Connect, close);
PHP_METHOD(Leevel_Session_Connect, read);
PHP_METHOD(Leevel_Session_Connect, write);
PHP_METHOD(Leevel_Session_Connect, destroy);
PHP_METHOD(Leevel_Session_Connect, gc);
PHP_METHOD(Leevel_Session_Connect, getCache);
PHP_METHOD(Leevel_Session_Connect, getSessionName);
zend_object *zephir_init_properties_Leevel_Session_Connect(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Leevel\\Cache\\ICache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect_open, 0, 0, 2)
	ZEND_ARG_INFO(0, savePath)
	ZEND_ARG_INFO(0, sessionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect_read, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect_write, 0, 0, 2)
	ZEND_ARG_INFO(0, sessionid)
	ZEND_ARG_INFO(0, sessiondata)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect_destroy, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionid)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect_gc, 0, 0, 1)
	ZEND_ARG_INFO(0, maxlifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_connect_getsessionname, 0, 0, 1)
	ZEND_ARG_INFO(0, sessionid)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_connect_method_entry) {
	PHP_ME(Leevel_Session_Connect, __construct, arginfo_leevel_session_connect___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Session_Connect, open, arginfo_leevel_session_connect_open, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, close, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, read, arginfo_leevel_session_connect_read, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, write, arginfo_leevel_session_connect_write, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, destroy, arginfo_leevel_session_connect_destroy, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, gc, arginfo_leevel_session_connect_gc, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Connect, getSessionName, arginfo_leevel_session_connect_getsessionname, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
