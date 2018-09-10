
extern zend_class_entry *leevel_http_apiresponse_ce;

ZEPHIR_INIT_CLASS(Leevel_Http_ApiResponse);

PHP_METHOD(Leevel_Http_ApiResponse, create);
PHP_METHOD(Leevel_Http_ApiResponse, ok);
PHP_METHOD(Leevel_Http_ApiResponse, created);
PHP_METHOD(Leevel_Http_ApiResponse, accepted);
PHP_METHOD(Leevel_Http_ApiResponse, noContent);
PHP_METHOD(Leevel_Http_ApiResponse, unprocessableEntity);
PHP_METHOD(Leevel_Http_ApiResponse, error);
PHP_METHOD(Leevel_Http_ApiResponse, badRequest);
PHP_METHOD(Leevel_Http_ApiResponse, unauthorized);
PHP_METHOD(Leevel_Http_ApiResponse, forbidden);
PHP_METHOD(Leevel_Http_ApiResponse, notFound);
PHP_METHOD(Leevel_Http_ApiResponse, methodNotAllowed);
PHP_METHOD(Leevel_Http_ApiResponse, tooManyRequests);
PHP_METHOD(Leevel_Http_ApiResponse, internalServerError);
PHP_METHOD(Leevel_Http_ApiResponse, normalizeErrorMessage);
PHP_METHOD(Leevel_Http_ApiResponse, parseErrorMessage);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_create, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_ok, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_created, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_accepted, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_unprocessableentity, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, errors, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_error, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_badrequest, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_unauthorized, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_forbidden, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_notfound, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_methodnotallowed, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_toomanyrequests, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_internalservererror, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_normalizeerrormessage, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_http_apiresponse_parseerrormessage, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_http_apiresponse_method_entry) {
	PHP_ME(Leevel_Http_ApiResponse, create, arginfo_leevel_http_apiresponse_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Http_ApiResponse, ok, arginfo_leevel_http_apiresponse_ok, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, created, arginfo_leevel_http_apiresponse_created, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, accepted, arginfo_leevel_http_apiresponse_accepted, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, noContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, unprocessableEntity, arginfo_leevel_http_apiresponse_unprocessableentity, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, error, arginfo_leevel_http_apiresponse_error, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, badRequest, arginfo_leevel_http_apiresponse_badrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, unauthorized, arginfo_leevel_http_apiresponse_unauthorized, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, forbidden, arginfo_leevel_http_apiresponse_forbidden, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, notFound, arginfo_leevel_http_apiresponse_notfound, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, methodNotAllowed, arginfo_leevel_http_apiresponse_methodnotallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, tooManyRequests, arginfo_leevel_http_apiresponse_toomanyrequests, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, internalServerError, arginfo_leevel_http_apiresponse_internalservererror, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Http_ApiResponse, normalizeErrorMessage, arginfo_leevel_http_apiresponse_normalizeerrormessage, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Http_ApiResponse, parseErrorMessage, arginfo_leevel_http_apiresponse_parseerrormessage, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
