
extern zend_class_entry *leevel_filesystem_provider_register_ce;

ZEPHIR_INIT_CLASS(Leevel_Filesystem_Provider_Register);

PHP_METHOD(Leevel_Filesystem_Provider_Register, __construct);
PHP_METHOD(Leevel_Filesystem_Provider_Register, register);
PHP_METHOD(Leevel_Filesystem_Provider_Register, providers);
PHP_METHOD(Leevel_Filesystem_Provider_Register, isDeferred);
PHP_METHOD(Leevel_Filesystem_Provider_Register, filesystems);
PHP_METHOD(Leevel_Filesystem_Provider_Register, filesystemsClosure);
PHP_METHOD(Leevel_Filesystem_Provider_Register, filesystem);
PHP_METHOD(Leevel_Filesystem_Provider_Register, filesystemClosure);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_filesystem_provider_register___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_filesystem_provider_register_filesystemsclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_filesystem_provider_register_filesystemclosure, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Leevel\\Di\\IContainer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_filesystem_provider_register_method_entry) {
	PHP_ME(Leevel_Filesystem_Provider_Register, __construct, arginfo_leevel_filesystem_provider_register___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Filesystem_Provider_Register, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Filesystem_Provider_Register, providers, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Filesystem_Provider_Register, isDeferred, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Filesystem_Provider_Register, filesystems, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Filesystem_Provider_Register, filesystemsClosure, arginfo_leevel_filesystem_provider_register_filesystemsclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Filesystem_Provider_Register, filesystem, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Filesystem_Provider_Register, filesystemClosure, arginfo_leevel_filesystem_provider_register_filesystemclosure, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
