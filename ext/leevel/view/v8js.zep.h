
extern zend_class_entry *leevel_view_v8js_ce;

ZEPHIR_INIT_CLASS(Leevel_View_V8js);

PHP_METHOD(Leevel_View_V8js, __construct);
PHP_METHOD(Leevel_View_V8js, getV8js);
PHP_METHOD(Leevel_View_V8js, display);
PHP_METHOD(Leevel_View_V8js, select);
PHP_METHOD(Leevel_View_V8js, execute);
PHP_METHOD(Leevel_View_V8js, initDd);
PHP_METHOD(Leevel_View_V8js, initDdClosure);
PHP_METHOD(Leevel_View_V8js, initDump);
PHP_METHOD(Leevel_View_V8js, initDumpClosure);
PHP_METHOD(Leevel_View_V8js, initEcho);
PHP_METHOD(Leevel_View_V8js, initEchoClosure);
PHP_METHOD(Leevel_View_V8js, initHtml);
PHP_METHOD(Leevel_View_V8js, initHtmlClosure);
PHP_METHOD(Leevel_View_V8js, initLoad);
PHP_METHOD(Leevel_View_V8js, initLoadClosure);
PHP_METHOD(Leevel_View_V8js, initModule);
PHP_METHOD(Leevel_View_V8js, moduleNormaliserClosure);
PHP_METHOD(Leevel_View_V8js, moduleLoaderClosure);
PHP_METHOD(Leevel_View_V8js, initBase);
PHP_METHOD(Leevel_View_V8js, setV8jsProp);
PHP_METHOD(Leevel_View_V8js, vuePackage);
PHP_METHOD(Leevel_View_V8js, artPackage);
zend_object *zephir_init_properties_Leevel_View_V8js(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_display, 0, 0, 1)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_ARRAY_INFO(0, vars, 1)
	ZEND_ARG_INFO(0, ext)
	ZEND_ARG_INFO(0, display)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_select, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_execute, 0, 0, 1)
	ZEND_ARG_INFO(0, js)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_initddclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_initdumpclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_initechoclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_inithtmlclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_initloadclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, package)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_modulenormaliserclosure, 0, 0, 2)
	ZEND_ARG_INFO(0, base)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_moduleloaderclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, module)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_view_v8js_setv8jsprop, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_view_v8js_method_entry) {
	PHP_ME(Leevel_View_V8js, __construct, arginfo_leevel_view_v8js___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_View_V8js, getV8js, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, display, arginfo_leevel_view_v8js_display, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, select, arginfo_leevel_view_v8js_select, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, execute, arginfo_leevel_view_v8js_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, initDd, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, initDdClosure, arginfo_leevel_view_v8js_initddclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, initDump, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, initDumpClosure, arginfo_leevel_view_v8js_initdumpclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, initEcho, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, initEchoClosure, arginfo_leevel_view_v8js_initechoclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, initHtml, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, initHtmlClosure, arginfo_leevel_view_v8js_inithtmlclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, initLoad, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, initLoadClosure, arginfo_leevel_view_v8js_initloadclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, initModule, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, moduleNormaliserClosure, arginfo_leevel_view_v8js_modulenormaliserclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, moduleLoaderClosure, arginfo_leevel_view_v8js_moduleloaderclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, initBase, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, setV8jsProp, arginfo_leevel_view_v8js_setv8jsprop, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_View_V8js, vuePackage, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_View_V8js, artPackage, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
