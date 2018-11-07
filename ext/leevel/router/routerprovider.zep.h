
extern zend_class_entry *leevel_router_routerprovider_ce;

ZEPHIR_INIT_CLASS(Leevel_Router_RouterProvider);

PHP_METHOD(Leevel_Router_RouterProvider, bootstrap);
PHP_METHOD(Leevel_Router_RouterProvider, register);
PHP_METHOD(Leevel_Router_RouterProvider, providers);
PHP_METHOD(Leevel_Router_RouterProvider, getRouters);
PHP_METHOD(Leevel_Router_RouterProvider, getMiddlewares);
PHP_METHOD(Leevel_Router_RouterProvider, importCachedRouters);
PHP_METHOD(Leevel_Router_RouterProvider, loadRouters);
PHP_METHOD(Leevel_Router_RouterProvider, makeMiddlewareParser);
PHP_METHOD(Leevel_Router_RouterProvider, setRoutersData);
PHP_METHOD(Leevel_Router_RouterProvider, isRouterCached);
PHP_METHOD(Leevel_Router_RouterProvider, getRouterCachePath);
PHP_METHOD(Leevel_Router_RouterProvider, setControllerDir);
PHP_METHOD(Leevel_Router_RouterProvider, setMiddleware);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_router_routerprovider_setroutersdata, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, routers, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_router_routerprovider_method_entry) {
	PHP_ME(Leevel_Router_RouterProvider, bootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_RouterProvider, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_RouterProvider, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Router_RouterProvider, getRouters, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_RouterProvider, getMiddlewares, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Router_RouterProvider, importCachedRouters, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, loadRouters, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, makeMiddlewareParser, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, setRoutersData, arginfo_leevel_router_routerprovider_setroutersdata, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, isRouterCached, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, getRouterCachePath, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, setControllerDir, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Router_RouterProvider, setMiddleware, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
