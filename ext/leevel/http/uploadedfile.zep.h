
extern zend_class_entry *leevel_http_uploadedfile_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_UploadedFile);

PHP_METHOD(Leevel_Http_UploadedFile, __construct);
PHP_METHOD(Leevel_Http_UploadedFile, getOriginalName);
PHP_METHOD(Leevel_Http_UploadedFile, getOriginalExtension);
PHP_METHOD(Leevel_Http_UploadedFile, getMimeType);
PHP_METHOD(Leevel_Http_UploadedFile, getError);
PHP_METHOD(Leevel_Http_UploadedFile, isValid);
PHP_METHOD(Leevel_Http_UploadedFile, move);
PHP_METHOD(Leevel_Http_UploadedFile, getMaxFilesize);
PHP_METHOD(Leevel_Http_UploadedFile, getErrorMessage);
void zephir_init_static_properties_Leevel_Http_UploadedFile(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_uploadedfile___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, originalName)
	ZEND_ARG_INFO(0, mimeType)
	ZEND_ARG_INFO(0, error)
	ZEND_ARG_INFO(0, test)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_uploadedfile_move, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_uploadedfile_method_entry) {
	PHP_ME(Leevel_Http_UploadedFile, __construct, arginfo_leevel_http_uploadedfile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Http_UploadedFile, getOriginalName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_UploadedFile, getOriginalExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_UploadedFile, getMimeType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_UploadedFile, getError, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_UploadedFile, isValid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_UploadedFile, move, arginfo_leevel_http_uploadedfile_move, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_UploadedFile, getMaxFilesize, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_UploadedFile, getErrorMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
