
extern zend_class_entry *leevel_router_responsefactory_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_ResponseFactory);

PHP_METHOD(Leevel_Router_ResponseFactory, __construct);
PHP_METHOD(Leevel_Router_ResponseFactory, make);
PHP_METHOD(Leevel_Router_ResponseFactory, view);
PHP_METHOD(Leevel_Router_ResponseFactory, viewSuccess);
PHP_METHOD(Leevel_Router_ResponseFactory, viewError);
PHP_METHOD(Leevel_Router_ResponseFactory, json);
PHP_METHOD(Leevel_Router_ResponseFactory, jsonp);
PHP_METHOD(Leevel_Router_ResponseFactory, download);
PHP_METHOD(Leevel_Router_ResponseFactory, file);
PHP_METHOD(Leevel_Router_ResponseFactory, redirect);
PHP_METHOD(Leevel_Router_ResponseFactory, redirectRaw);
PHP_METHOD(Leevel_Router_ResponseFactory, apiOk);
PHP_METHOD(Leevel_Router_ResponseFactory, apiCreated);
PHP_METHOD(Leevel_Router_ResponseFactory, apiAccepted);
PHP_METHOD(Leevel_Router_ResponseFactory, apiNoContent);
PHP_METHOD(Leevel_Router_ResponseFactory, apiError);
PHP_METHOD(Leevel_Router_ResponseFactory, apiBadRequest);
PHP_METHOD(Leevel_Router_ResponseFactory, apiUnauthorized);
PHP_METHOD(Leevel_Router_ResponseFactory, apiForbidden);
PHP_METHOD(Leevel_Router_ResponseFactory, apiNotFound);
PHP_METHOD(Leevel_Router_ResponseFactory, apiMethodNotAllowed);
PHP_METHOD(Leevel_Router_ResponseFactory, apiUnprocessableEntity);
PHP_METHOD(Leevel_Router_ResponseFactory, apiTooManyRequests);
PHP_METHOD(Leevel_Router_ResponseFactory, apiInternalServerError);
PHP_METHOD(Leevel_Router_ResponseFactory, setViewSuccessTemplate);
PHP_METHOD(Leevel_Router_ResponseFactory, setViewFailTemplate);
PHP_METHOD(Leevel_Router_ResponseFactory, createApiResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, view, Leevel\\Mvc\\IView, 0)
	ZEND_ARG_OBJ_INFO(0, redirector, Leevel\\Router\\Redirect, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_make, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_view, 0, 0, 0)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_viewsuccess, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_viewerror, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, time)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_json, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_jsonp, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, json)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_download, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, autoEtag)
	ZEND_ARG_INFO(0, autoLastModified)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_file, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
	ZEND_ARG_INFO(0, autoEtag)
	ZEND_ARG_INFO(0, autoLastModified)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_redirect, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
	ZEND_ARG_INFO(0, subdomain)
	ZEND_ARG_INFO(0, suffix)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_redirectraw, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
	ZEND_ARG_INFO(0, status)
	ZEND_ARG_ARRAY_INFO(0, headers, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apiok, 0, 0, 0)
	ZEND_ARG_INFO(0, content)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apicreated, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apiaccepted, 0, 0, 0)
	ZEND_ARG_INFO(0, location)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apierror, 0, 0, 2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, statusCode)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apibadrequest, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apiunauthorized, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apiforbidden, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apinotfound, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apimethodnotallowed, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apiunprocessableentity, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, errors, 1)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apitoomanyrequests, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_apiinternalservererror, 0, 0, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_setviewsuccesstemplate, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_responsefactory_setviewfailtemplate, 0, 0, 1)
	ZEND_ARG_INFO(0, template)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_responsefactory_method_entry) {
	PHP_ME(Leevel_Router_ResponseFactory, __construct, arginfo_leevel_router_responsefactory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Router_ResponseFactory, make, arginfo_leevel_router_responsefactory_make, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, view, arginfo_leevel_router_responsefactory_view, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, viewSuccess, arginfo_leevel_router_responsefactory_viewsuccess, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, viewError, arginfo_leevel_router_responsefactory_viewerror, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, json, arginfo_leevel_router_responsefactory_json, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, jsonp, arginfo_leevel_router_responsefactory_jsonp, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, download, arginfo_leevel_router_responsefactory_download, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, file, arginfo_leevel_router_responsefactory_file, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, redirect, arginfo_leevel_router_responsefactory_redirect, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, redirectRaw, arginfo_leevel_router_responsefactory_redirectraw, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiOk, arginfo_leevel_router_responsefactory_apiok, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiCreated, arginfo_leevel_router_responsefactory_apicreated, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiAccepted, arginfo_leevel_router_responsefactory_apiaccepted, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiNoContent, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiError, arginfo_leevel_router_responsefactory_apierror, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiBadRequest, arginfo_leevel_router_responsefactory_apibadrequest, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiUnauthorized, arginfo_leevel_router_responsefactory_apiunauthorized, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiForbidden, arginfo_leevel_router_responsefactory_apiforbidden, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiNotFound, arginfo_leevel_router_responsefactory_apinotfound, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiMethodNotAllowed, arginfo_leevel_router_responsefactory_apimethodnotallowed, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiUnprocessableEntity, arginfo_leevel_router_responsefactory_apiunprocessableentity, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiTooManyRequests, arginfo_leevel_router_responsefactory_apitoomanyrequests, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, apiInternalServerError, arginfo_leevel_router_responsefactory_apiinternalservererror, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, setViewSuccessTemplate, arginfo_leevel_router_responsefactory_setviewsuccesstemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, setViewFailTemplate, arginfo_leevel_router_responsefactory_setviewfailtemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_ResponseFactory, createApiResponse, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
