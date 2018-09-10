
extern zend_class_entry *leevel_di_container_ce;

ZEPHIR_INIT_CLASS(Leevel_Di_Container);

PHP_METHOD(Leevel_Di_Container, bind);
PHP_METHOD(Leevel_Di_Container, instance);
PHP_METHOD(Leevel_Di_Container, singleton);
PHP_METHOD(Leevel_Di_Container, share);
PHP_METHOD(Leevel_Di_Container, shareClosure);
PHP_METHOD(Leevel_Di_Container, alias);
PHP_METHOD(Leevel_Di_Container, make);
PHP_METHOD(Leevel_Di_Container, call);
PHP_METHOD(Leevel_Di_Container, remove);
PHP_METHOD(Leevel_Di_Container, exists);
PHP_METHOD(Leevel_Di_Container, normalize);
PHP_METHOD(Leevel_Di_Container, getAlias);
PHP_METHOD(Leevel_Di_Container, getInjectionObject);
PHP_METHOD(Leevel_Di_Container, normalizeInjectionArgs);
PHP_METHOD(Leevel_Di_Container, parseInjection);
PHP_METHOD(Leevel_Di_Container, parseParameterClass);
PHP_METHOD(Leevel_Di_Container, parseClassInstance);
PHP_METHOD(Leevel_Di_Container, parseClassFromContainer);
PHP_METHOD(Leevel_Di_Container, parseClassNotExists);
PHP_METHOD(Leevel_Di_Container, parseReflection);
PHP_METHOD(Leevel_Di_Container, parseClosureReflection);
PHP_METHOD(Leevel_Di_Container, parseMethodReflection);
PHP_METHOD(Leevel_Di_Container, parseClassReflection);
PHP_METHOD(Leevel_Di_Container, newInstanceArgs);
PHP_METHOD(Leevel_Di_Container, parseAlias);
PHP_METHOD(Leevel_Di_Container, offsetExists);
PHP_METHOD(Leevel_Di_Container, offsetGet);
PHP_METHOD(Leevel_Di_Container, offsetSet);
PHP_METHOD(Leevel_Di_Container, offsetUnset);
PHP_METHOD(Leevel_Di_Container, __get);
PHP_METHOD(Leevel_Di_Container, __set);
PHP_METHOD(Leevel_Di_Container, __call);
zend_object *zephir_init_properties_Leevel_Di_Container(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_bind, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
	ZEND_ARG_INFO(0, share)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_instance, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_singleton, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_share, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, closures, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_shareclosure, 0, 0, 1)
	ZEND_ARG_INFO(0, container)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_alias, 0, 0, 1)
	ZEND_ARG_INFO(0, alias)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_make, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_call, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_normalize, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_getalias, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_getinjectionobject, 0, 0, 1)
	ZEND_ARG_INFO(0, classname)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_normalizeinjectionargs, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseinjection, 0, 0, 1)
	ZEND_ARG_INFO(0, injection)
	ZEND_ARG_ARRAY_INFO(0, args, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseparameterclass, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, param, ReflectionParameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseclassinstance, 0, 0, 1)
	ZEND_ARG_INFO(0, argsclass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseclassfromcontainer, 0, 0, 1)
	ZEND_ARG_INFO(0, argsclass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseclassnotexists, 0, 0, 1)
	ZEND_ARG_INFO(0, argsclass)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parsereflection, 0, 0, 1)
	ZEND_ARG_INFO(0, injection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseclosurereflection, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, injection, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parsemethodreflection, 0, 0, 1)
	ZEND_ARG_INFO(0, injection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parseclassreflection, 0, 0, 1)
	ZEND_ARG_INFO(0, injection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_newinstanceargs, 0, 0, 2)
	ZEND_ARG_INFO(0, classname)
	ZEND_ARG_INFO(0, args)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_parsealias, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, name, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, service)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_di_container___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_di_container_method_entry) {
	PHP_ME(Leevel_Di_Container, bind, arginfo_leevel_di_container_bind, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, instance, arginfo_leevel_di_container_instance, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, singleton, arginfo_leevel_di_container_singleton, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, share, arginfo_leevel_di_container_share, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, shareClosure, arginfo_leevel_di_container_shareclosure, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, alias, arginfo_leevel_di_container_alias, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, make, arginfo_leevel_di_container_make, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, call, arginfo_leevel_di_container_call, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, remove, arginfo_leevel_di_container_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, exists, arginfo_leevel_di_container_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, normalize, arginfo_leevel_di_container_normalize, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, getAlias, arginfo_leevel_di_container_getalias, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, getInjectionObject, arginfo_leevel_di_container_getinjectionobject, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, normalizeInjectionArgs, arginfo_leevel_di_container_normalizeinjectionargs, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseInjection, arginfo_leevel_di_container_parseinjection, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseParameterClass, arginfo_leevel_di_container_parseparameterclass, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseClassInstance, arginfo_leevel_di_container_parseclassinstance, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseClassFromContainer, arginfo_leevel_di_container_parseclassfromcontainer, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseClassNotExists, arginfo_leevel_di_container_parseclassnotexists, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseReflection, arginfo_leevel_di_container_parsereflection, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseClosureReflection, arginfo_leevel_di_container_parseclosurereflection, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseMethodReflection, arginfo_leevel_di_container_parsemethodreflection, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseClassReflection, arginfo_leevel_di_container_parseclassreflection, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, newInstanceArgs, arginfo_leevel_di_container_newinstanceargs, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, parseAlias, arginfo_leevel_di_container_parsealias, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Di_Container, offsetExists, arginfo_leevel_di_container_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, offsetGet, arginfo_leevel_di_container_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, offsetSet, arginfo_leevel_di_container_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, offsetUnset, arginfo_leevel_di_container_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, __get, arginfo_leevel_di_container___get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, __set, arginfo_leevel_di_container___set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Di_Container, __call, arginfo_leevel_di_container___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
