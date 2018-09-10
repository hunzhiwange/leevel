
extern zend_class_entry *leevel_collection_collection_ce;

ZEPHIR_INIT_CLASS(Leevel_Collection_Collection);

PHP_METHOD(Leevel_Collection_Collection, __construct);
PHP_METHOD(Leevel_Collection_Collection, make);
PHP_METHOD(Leevel_Collection_Collection, current);
PHP_METHOD(Leevel_Collection_Collection, key);
PHP_METHOD(Leevel_Collection_Collection, next);
PHP_METHOD(Leevel_Collection_Collection, rewind);
PHP_METHOD(Leevel_Collection_Collection, valid);
PHP_METHOD(Leevel_Collection_Collection, offsetExists);
PHP_METHOD(Leevel_Collection_Collection, offsetGet);
PHP_METHOD(Leevel_Collection_Collection, offsetSet);
PHP_METHOD(Leevel_Collection_Collection, offsetUnset);
PHP_METHOD(Leevel_Collection_Collection, count);
PHP_METHOD(Leevel_Collection_Collection, all);
PHP_METHOD(Leevel_Collection_Collection, toArray);
PHP_METHOD(Leevel_Collection_Collection, jsonSerialize);
PHP_METHOD(Leevel_Collection_Collection, toJson);
PHP_METHOD(Leevel_Collection_Collection, __toString);
PHP_METHOD(Leevel_Collection_Collection, each);
PHP_METHOD(Leevel_Collection_Collection, prev);
PHP_METHOD(Leevel_Collection_Collection, end);
PHP_METHOD(Leevel_Collection_Collection, siblings);
PHP_METHOD(Leevel_Collection_Collection, nextAll);
PHP_METHOD(Leevel_Collection_Collection, prevAll);
PHP_METHOD(Leevel_Collection_Collection, attr);
PHP_METHOD(Leevel_Collection_Collection, eq);
PHP_METHOD(Leevel_Collection_Collection, get);
PHP_METHOD(Leevel_Collection_Collection, index);
PHP_METHOD(Leevel_Collection_Collection, find);
PHP_METHOD(Leevel_Collection_Collection, first);
PHP_METHOD(Leevel_Collection_Collection, last);
PHP_METHOD(Leevel_Collection_Collection, is);
PHP_METHOD(Leevel_Collection_Collection, slice);
PHP_METHOD(Leevel_Collection_Collection, not);
PHP_METHOD(Leevel_Collection_Collection, filter);
PHP_METHOD(Leevel_Collection_Collection, size);
PHP_METHOD(Leevel_Collection_Collection, isEmpty);
PHP_METHOD(Leevel_Collection_Collection, map);
PHP_METHOD(Leevel_Collection_Collection, macro);
PHP_METHOD(Leevel_Collection_Collection, hasMacro);
PHP_METHOD(Leevel_Collection_Collection, callStaticMacro);
PHP_METHOD(Leevel_Collection_Collection, callMacro);
PHP_METHOD(Leevel_Collection_Collection, checkType);
PHP_METHOD(Leevel_Collection_Collection, getArrayElements);
PHP_METHOD(Leevel_Collection_Collection, parseKey);
PHP_METHOD(Leevel_Collection_Collection, __get);
PHP_METHOD(Leevel_Collection_Collection, __set);
PHP_METHOD(Leevel_Collection_Collection, __callStatic);
PHP_METHOD(Leevel_Collection_Collection, __call);
zend_object *zephir_init_properties_Leevel_Collection_Collection(zend_class_entry *class_type TSRMLS_DC);
void zephir_init_static_properties_Leevel_Collection_Collection(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, elements)
	ZEND_ARG_ARRAY_INFO(0, type, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_make, 0, 0, 0)
	ZEND_ARG_INFO(0, elements)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_tojson, 0, 0, 0)
	ZEND_ARG_INFO(0, option)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_each, 0, 0, 1)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_siblings, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_nextall, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_prevall, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_attr, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_eq, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_index, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, strict)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_find, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_is, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_slice, 0, 0, 1)
	ZEND_ARG_INFO(0, selector)
	ZEND_ARG_INFO(0, length)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_not, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_filter, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_map, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_checktype, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_getarrayelements, 0, 0, 1)
	ZEND_ARG_INFO(0, elements)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection_parsekey, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection___set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection___callstatic, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_collection_collection___call, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_collection_collection_method_entry) {
	PHP_ME(Leevel_Collection_Collection, __construct, arginfo_leevel_collection_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Collection_Collection, make, arginfo_leevel_collection_collection_make, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Collection_Collection, current, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, key, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, next, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, rewind, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, valid, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, offsetExists, arginfo_leevel_collection_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, offsetGet, arginfo_leevel_collection_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, offsetSet, arginfo_leevel_collection_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, offsetUnset, arginfo_leevel_collection_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, count, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, toJson, arginfo_leevel_collection_collection_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, each, arginfo_leevel_collection_collection_each, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, prev, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, end, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, siblings, arginfo_leevel_collection_collection_siblings, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, nextAll, arginfo_leevel_collection_collection_nextall, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, prevAll, arginfo_leevel_collection_collection_prevall, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, attr, arginfo_leevel_collection_collection_attr, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, eq, arginfo_leevel_collection_collection_eq, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, get, arginfo_leevel_collection_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, index, arginfo_leevel_collection_collection_index, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, find, arginfo_leevel_collection_collection_find, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, first, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, last, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, is, arginfo_leevel_collection_collection_is, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, slice, arginfo_leevel_collection_collection_slice, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, not, arginfo_leevel_collection_collection_not, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, filter, arginfo_leevel_collection_collection_filter, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, size, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, map, arginfo_leevel_collection_collection_map, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, macro, arginfo_leevel_collection_collection_macro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Collection_Collection, hasMacro, arginfo_leevel_collection_collection_hasmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Collection_Collection, callStaticMacro, arginfo_leevel_collection_collection_callstaticmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Collection_Collection, callMacro, arginfo_leevel_collection_collection_callmacro, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, checkType, arginfo_leevel_collection_collection_checktype, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Collection_Collection, getArrayElements, arginfo_leevel_collection_collection_getarrayelements, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Collection_Collection, parseKey, arginfo_leevel_collection_collection_parsekey, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Collection_Collection, __get, arginfo_leevel_collection_collection___get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, __set, arginfo_leevel_collection_collection___set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Collection_Collection, __callStatic, arginfo_leevel_collection_collection___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Collection_Collection, __call, arginfo_leevel_collection_collection___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
