
extern zend_class_entry *leevel_kernel_iproject_ce;

ZEPHIR_INIT_CLASS(Leevel_Kernel_IProject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_singletons, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_path, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setapppath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_apppath, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_themepath, 0, 0, 0)
	ZEND_ARG_INFO(0, app)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setcommonpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_commonpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setruntimepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_runtimepath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setstoragepath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_storagepath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setpublicpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_publicpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setthemespath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_themespath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setoptionpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_optionpath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_seti18npath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_i18npath, 0, 0, 0)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setenvpath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_setenvfile, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_i18ncachedpath, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_iscachedi18n, 0, 0, 1)
	ZEND_ARG_INFO(0, i18n)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_getpathbycomposer, 0, 0, 1)
	ZEND_ARG_INFO(0, namespaces)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_makeprovider, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_callproviderbootstrap, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, provider, Leevel\\Di\\Provider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_bootstrap, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, bootstraps, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_kernel_iproject_register, 0, 0, 1)
	ZEND_ARG_INFO(0, provider)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_kernel_iproject_method_entry) {
	ZEND_FENTRY(singletons, NULL, arginfo_leevel_kernel_iproject_singletons, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, version, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, runWithExtension, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, console, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, make, arginfo_leevel_kernel_iproject_make)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPath, arginfo_leevel_kernel_iproject_setpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, path, arginfo_leevel_kernel_iproject_path)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setAppPath, arginfo_leevel_kernel_iproject_setapppath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, appPath, arginfo_leevel_kernel_iproject_apppath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, themePath, arginfo_leevel_kernel_iproject_themepath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setCommonPath, arginfo_leevel_kernel_iproject_setcommonpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, commonPath, arginfo_leevel_kernel_iproject_commonpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setRuntimePath, arginfo_leevel_kernel_iproject_setruntimepath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, runtimePath, arginfo_leevel_kernel_iproject_runtimepath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setStoragePath, arginfo_leevel_kernel_iproject_setstoragepath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, storagePath, arginfo_leevel_kernel_iproject_storagepath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setPublicPath, arginfo_leevel_kernel_iproject_setpublicpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, publicPath, arginfo_leevel_kernel_iproject_publicpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setThemesPath, arginfo_leevel_kernel_iproject_setthemespath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, themesPath, arginfo_leevel_kernel_iproject_themespath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setOptionPath, arginfo_leevel_kernel_iproject_setoptionpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, optionPath, arginfo_leevel_kernel_iproject_optionpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setI18nPath, arginfo_leevel_kernel_iproject_seti18npath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, i18nPath, arginfo_leevel_kernel_iproject_i18npath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setEnvPath, arginfo_leevel_kernel_iproject_setenvpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, envPath, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, setEnvFile, arginfo_leevel_kernel_iproject_setenvfile)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, envFile, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, fullEnvPath, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, i18nCachedPath, arginfo_leevel_kernel_iproject_i18ncachedpath)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isCachedI18n, arginfo_leevel_kernel_iproject_iscachedi18n)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, optionCachedPath, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isCachedOption, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, routerCachedPath, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isCachedRouter, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, composer, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, getPathByComposer, arginfo_leevel_kernel_iproject_getpathbycomposer)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, debug, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, development, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, environment, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, makeProvider, arginfo_leevel_kernel_iproject_makeprovider)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, callProviderBootstrap, arginfo_leevel_kernel_iproject_callproviderbootstrap)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, bootstrap, arginfo_leevel_kernel_iproject_bootstrap)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, isBootstrap, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, registerProviders, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, bootstrapProviders, NULL)
	PHP_ABSTRACT_ME(Leevel_Kernel_IProject, register, arginfo_leevel_kernel_iproject_register)
	PHP_FE_END
};
