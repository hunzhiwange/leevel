
extern zend_class_entry *leevel_http_fileresponse_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_FileResponse);

PHP_METHOD(Leevel_Http_FileResponse, __construct);
PHP_METHOD(Leevel_Http_FileResponse, create);
PHP_METHOD(Leevel_Http_FileResponse, setFile);
PHP_METHOD(Leevel_Http_FileResponse, getFile);
PHP_METHOD(Leevel_Http_FileResponse, setAutoLastModified);
PHP_METHOD(Leevel_Http_FileResponse, setAutoEtag);
PHP_METHOD(Leevel_Http_FileResponse, setContent);
PHP_METHOD(Leevel_Http_FileResponse, getContent);
PHP_METHOD(Leevel_Http_FileResponse, setContentDisposition);
PHP_METHOD(Leevel_Http_FileResponse, sendContent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_fileresponse___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, contentDisposition)
	ZEND_ARG_INFO(0, autoEtag)
	ZEND_ARG_INFO(0, autoLastModified)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_fileresponse_create, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, contentDisposition)
	ZEND_ARG_INFO(0, autoEtag)
	ZEND_ARG_INFO(0, autoLastModified)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_fileresponse_setfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, contentDisposition)
	ZEND_ARG_INFO(0, autoEtag)
	ZEND_ARG_INFO(0, autoLastModified)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_fileresponse_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_fileresponse_setcontentdisposition, 0, 0, 1)
	ZEND_ARG_INFO(0, disposition)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_fileresponse_method_entry) {
	PHP_ME(Leevel_Http_FileResponse, __construct, arginfo_leevel_http_fileresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Http_FileResponse, create, arginfo_leevel_http_fileresponse_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_FileResponse, setFile, arginfo_leevel_http_fileresponse_setfile, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, getFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, setAutoLastModified, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, setAutoEtag, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, setContent, arginfo_leevel_http_fileresponse_setcontent, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, getContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, setContentDisposition, arginfo_leevel_http_fileresponse_setcontentdisposition, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_FileResponse, sendContent, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
