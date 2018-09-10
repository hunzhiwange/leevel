
extern zend_class_entry *leevel_http_file_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_File);

PHP_METHOD(Leevel_Http_File, __construct);
PHP_METHOD(Leevel_Http_File, move);
PHP_METHOD(Leevel_Http_File, getTargetFile);
PHP_METHOD(Leevel_Http_File, moveToTarget);
PHP_METHOD(Leevel_Http_File, errorHandlerClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_file_move, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_file_gettargetfile, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_file_movetotarget, 0, 0, 2)
	ZEND_ARG_INFO(0, sourcePath)
	ZEND_ARG_INFO(0, target)
	ZEND_ARG_INFO(0, isUploaded)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_file_method_entry) {
	PHP_ME(Leevel_Http_File, __construct, arginfo_leevel_http_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Http_File, move, arginfo_leevel_http_file_move, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_File, getTargetFile, arginfo_leevel_http_file_gettargetfile, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Http_File, moveToTarget, arginfo_leevel_http_file_movetotarget, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Http_File, errorHandlerClosure, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
