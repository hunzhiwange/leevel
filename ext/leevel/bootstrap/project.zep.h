
extern zend_class_entry *leevel_bootstrap_project_ce;

ZEPHIR_INIT_CLASS(Leevel_Bootstrap_Project);

PHP_METHOD(Leevel_Bootstrap_Project, __construct);
PHP_METHOD(Leevel_Bootstrap_Project, __clone);
PHP_METHOD(Leevel_Bootstrap_Project, singletons);
PHP_METHOD(Leevel_Bootstrap_Project, version);
PHP_METHOD(Leevel_Bootstrap_Project, runWithExtension);
PHP_METHOD(Leevel_Bootstrap_Project, console);
PHP_METHOD(Leevel_Bootstrap_Project, make);
PHP_METHOD(Leevel_Bootstrap_Project, setPath);
PHP_METHOD(Leevel_Bootstrap_Project, path);
PHP_METHOD(Leevel_Bootstrap_Project, setAppPath);
PHP_METHOD(Leevel_Bootstrap_Project, appPath);
PHP_METHOD(Leevel_Bootstrap_Project, themePath);
PHP_METHOD(Leevel_Bootstrap_Project, setCommonPath);
PHP_METHOD(Leevel_Bootstrap_Project, commonPath);
PHP_METHOD(Leevel_Bootstrap_Project, setRuntimePath);
PHP_METHOD(Leevel_Bootstrap_Project, runtimePath);
PHP_METHOD(Leevel_Bootstrap_Project, setStoragePath);
PHP_METHOD(Leevel_Bootstrap_Project, storagePath);
PHP_METHOD(Leevel_Bootstrap_Project, setPublicPath);
PHP_METHOD(Leevel_Bootstrap_Project, publicPath);
PHP_METHOD(Leevel_Bootstrap_Project, setThemesPath);
PHP_METHOD(Leevel_Bootstrap_Project, themesPath);
PHP_METHOD(Leevel_Bootstrap_Project, setOptionPath);
PHP_METHOD(Leevel_Bootstrap_Project, optionPath);
PHP_METHOD(Leevel_Bootstrap_Project, setI18nPath);
PHP_METHOD(Leevel_Bootstrap_Project, i18nPath);
PHP_METHOD(Leevel_Bootstrap_Project, setEnvPath);
PHP_METHOD(Leevel_Bootstrap_Project, envPath);
PHP_METHOD(Leevel_Bootstrap_Project, setEnvFile);
PHP_METHOD(Leevel_Bootstrap_Project, envFile);
PHP_METHOD(Leevel_Bootstrap_Project, fullEnvPath);
PHP_METHOD(Leevel_Bootstrap_Project, i18nCachedPath);
PHP_METHOD(Leevel_Bootstrap_Project, isCachedI18n);
PHP_METHOD(Leevel_Bootstrap_Project, optionCachedPath);
PHP_METHOD(Leevel_Bootstrap_Project, isCachedOption);
PHP_METHOD(Leevel_Bootstrap_Project, routerCachedPath);
PHP_METHOD(Leevel_Bootstrap_Project, isCachedRouter);
PHP_METHOD(Leevel_Bootstrap_Project, composer);
PHP_METHOD(Leevel_Bootstrap_Project, getPathByComposer);
PHP_METHOD(Leevel_Bootstrap_Project, debug);
PHP_METHOD(Leevel_Bootstrap_Project, development);
PHP_METHOD(Leevel_Bootstrap_Project, environment);
PHP_METHOD(Leevel_Bootstrap_Project, makeProvider);
PHP_METHOD(Leevel_Bootstrap_Project, callProviderBootstrap);
PHP_METHOD(Leevel_Bootstrap_Project, bootstrap);
PHP_METHOD(Leevel_Bootstrap_Project, isBootstrap);
PHP_METHOD(Leevel_Bootstrap_Project, registerProviders);
PHP_METHOD(Leevel_Bootstrap_Project, bootstrapProviders);
PHP_METHOD(Leevel_Bootstrap_Project, register);
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseServices);
PHP_METHOD(Leevel_Bootstrap_Project, registerBaseProvider);
PHP_METHOD(Leevel_Bootstrap_Project, registerDeferredProvider);
PHP_METHOD(Leevel_Bootstrap_Project, normalizeApp);
PHP_METHOD(Leevel_Bootstrap_Project, normalizePath);
zend_object *zephir_init_properties_Leevel_Bootstrap_Project(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_singletons, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setapppath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_apppath, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_themepath, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setcommonpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_commonpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setruntimepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_runtimepath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setstoragepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_storagepath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setpublicpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_publicpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setthemespath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_themespath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setoptionpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_optionpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_seti18npath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_i18npath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setenvpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_setenvfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_i18ncachedpath, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_iscachedi18n, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_getpathbycomposer, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_makeprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_callproviderbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Leevel\\Di\\Provider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_bootstrap, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bootstraps, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_register, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_registerdeferredprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_normalizeapp, 0, 0, 1)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_bootstrap_project_normalizepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_bootstrap_project_method_entry) {
	PHP_ME(Leevel_Bootstrap_Project, __construct, arginfo_leevel_bootstrap_project___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Bootstrap_Project, __clone, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, singletons, arginfo_leevel_bootstrap_project_singletons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Bootstrap_Project, version, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, runWithExtension, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, console, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, make, arginfo_leevel_bootstrap_project_make, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPath, arginfo_leevel_bootstrap_project_setpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, path, arginfo_leevel_bootstrap_project_path, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setAppPath, arginfo_leevel_bootstrap_project_setapppath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, appPath, arginfo_leevel_bootstrap_project_apppath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, themePath, arginfo_leevel_bootstrap_project_themepath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setCommonPath, arginfo_leevel_bootstrap_project_setcommonpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, commonPath, arginfo_leevel_bootstrap_project_commonpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setRuntimePath, arginfo_leevel_bootstrap_project_setruntimepath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, runtimePath, arginfo_leevel_bootstrap_project_runtimepath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setStoragePath, arginfo_leevel_bootstrap_project_setstoragepath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, storagePath, arginfo_leevel_bootstrap_project_storagepath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setPublicPath, arginfo_leevel_bootstrap_project_setpublicpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, publicPath, arginfo_leevel_bootstrap_project_publicpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setThemesPath, arginfo_leevel_bootstrap_project_setthemespath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, themesPath, arginfo_leevel_bootstrap_project_themespath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setOptionPath, arginfo_leevel_bootstrap_project_setoptionpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, optionPath, arginfo_leevel_bootstrap_project_optionpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setI18nPath, arginfo_leevel_bootstrap_project_seti18npath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, i18nPath, arginfo_leevel_bootstrap_project_i18npath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setEnvPath, arginfo_leevel_bootstrap_project_setenvpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, envPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, setEnvFile, arginfo_leevel_bootstrap_project_setenvfile, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, envFile, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, fullEnvPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, i18nCachedPath, arginfo_leevel_bootstrap_project_i18ncachedpath, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isCachedI18n, arginfo_leevel_bootstrap_project_iscachedi18n, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, optionCachedPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isCachedOption, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, routerCachedPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isCachedRouter, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, composer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, getPathByComposer, arginfo_leevel_bootstrap_project_getpathbycomposer, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, debug, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, development, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, environment, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, makeProvider, arginfo_leevel_bootstrap_project_makeprovider, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, callProviderBootstrap, arginfo_leevel_bootstrap_project_callproviderbootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, bootstrap, arginfo_leevel_bootstrap_project_bootstrap, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, isBootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, registerProviders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, bootstrapProviders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, register, arginfo_leevel_bootstrap_project_register, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Bootstrap_Project, registerBaseServices, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, registerBaseProvider, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, registerDeferredProvider, arginfo_leevel_bootstrap_project_registerdeferredprovider, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, normalizeApp, arginfo_leevel_bootstrap_project_normalizeapp, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Bootstrap_Project, normalizePath, arginfo_leevel_bootstrap_project_normalizepath, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
