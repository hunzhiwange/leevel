
extern zend_class_entry *leevel_support_str_ce;

ZEPHIR_INIT_CLASS(Leevel_Support_Str);

PHP_METHOD(Leevel_Support_Str, randAlphaNum);
PHP_METHOD(Leevel_Support_Str, randAlphaNumLowercase);
PHP_METHOD(Leevel_Support_Str, randAlphaNumUppercase);
PHP_METHOD(Leevel_Support_Str, randAlpha);
PHP_METHOD(Leevel_Support_Str, randAlphaLowercase);
PHP_METHOD(Leevel_Support_Str, randAlphaUppercase);
PHP_METHOD(Leevel_Support_Str, randNum);
PHP_METHOD(Leevel_Support_Str, randChinese);
PHP_METHOD(Leevel_Support_Str, randStr);
PHP_METHOD(Leevel_Support_Str, strEncoding);
PHP_METHOD(Leevel_Support_Str, substr);
PHP_METHOD(Leevel_Support_Str, formatDate);
PHP_METHOD(Leevel_Support_Str, formatBytes);
PHP_METHOD(Leevel_Support_Str, camelize);
PHP_METHOD(Leevel_Support_Str, unCamelize);
PHP_METHOD(Leevel_Support_Str, startsWith);
PHP_METHOD(Leevel_Support_Str, endsWith);
PHP_METHOD(Leevel_Support_Str, contains);
PHP_METHOD(Leevel_Support_Str, macro);
PHP_METHOD(Leevel_Support_Str, hasMacro);
PHP_METHOD(Leevel_Support_Str, callStaticMacro);
PHP_METHOD(Leevel_Support_Str, callMacro);
void zephir_init_static_properties_Leevel_Support_Str(TSRMLS_D);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randalphanum, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randalphanumlowercase, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randalphanumuppercase, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randalpha, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randalphalowercase, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randalphauppercase, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randnum, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randchinese, 0, 0, 1)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_randstr, 0, 0, 2)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charBox)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_strencoding, 0, 0, 2)
	ZEND_ARG_INFO(0, contents)
	ZEND_ARG_INFO(0, fromChar)
	ZEND_ARG_INFO(0, toChar)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_substr, 0, 0, 1)
	ZEND_ARG_INFO(0, strings)
	ZEND_ARG_INFO(0, start)
	ZEND_ARG_INFO(0, length)
	ZEND_ARG_INFO(0, charset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_formatdate, 0, 0, 1)
	ZEND_ARG_INFO(0, dateTemp)
	ZEND_ARG_ARRAY_INFO(0, lang, 1)
	ZEND_ARG_INFO(0, dateFormat)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_formatbytes, 0, 0, 1)
	ZEND_ARG_INFO(0, fileSize)
	ZEND_ARG_INFO(0, withUnit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_camelize, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_uncamelize, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, separator)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_startswith, 0, 0, 2)
	ZEND_ARG_INFO(0, toSearched)
	ZEND_ARG_INFO(0, search)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_endswith, 0, 0, 2)
	ZEND_ARG_INFO(0, toSearched)
	ZEND_ARG_INFO(0, search)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_contains, 0, 0, 2)
	ZEND_ARG_INFO(0, toSearched)
	ZEND_ARG_INFO(0, search)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_macro, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, macro)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_hasmacro, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_callstaticmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_support_str_callmacro, 0, 0, 2)
	ZEND_ARG_INFO(0, method)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_support_str_method_entry) {
	PHP_ME(Leevel_Support_Str, randAlphaNum, arginfo_leevel_support_str_randalphanum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randAlphaNumLowercase, arginfo_leevel_support_str_randalphanumlowercase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randAlphaNumUppercase, arginfo_leevel_support_str_randalphanumuppercase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randAlpha, arginfo_leevel_support_str_randalpha, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randAlphaLowercase, arginfo_leevel_support_str_randalphalowercase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randAlphaUppercase, arginfo_leevel_support_str_randalphauppercase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randNum, arginfo_leevel_support_str_randnum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randChinese, arginfo_leevel_support_str_randchinese, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, randStr, arginfo_leevel_support_str_randstr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, strEncoding, arginfo_leevel_support_str_strencoding, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, substr, arginfo_leevel_support_str_substr, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, formatDate, arginfo_leevel_support_str_formatdate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, formatBytes, arginfo_leevel_support_str_formatbytes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, camelize, arginfo_leevel_support_str_camelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, unCamelize, arginfo_leevel_support_str_uncamelize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, startsWith, arginfo_leevel_support_str_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, endsWith, arginfo_leevel_support_str_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, contains, arginfo_leevel_support_str_contains, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, macro, arginfo_leevel_support_str_macro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, hasMacro, arginfo_leevel_support_str_hasmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, callStaticMacro, arginfo_leevel_support_str_callstaticmacro, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Leevel_Support_Str, callMacro, arginfo_leevel_support_str_callmacro, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
