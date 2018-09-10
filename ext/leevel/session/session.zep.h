
extern zend_class_entry *leevel_session_session_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_Session);

PHP_METHOD(Leevel_Session_Session, __construct);
PHP_METHOD(Leevel_Session_Session, start);
PHP_METHOD(Leevel_Session_Session, save);
PHP_METHOD(Leevel_Session_Session, all);
PHP_METHOD(Leevel_Session_Session, set);
PHP_METHOD(Leevel_Session_Session, put);
PHP_METHOD(Leevel_Session_Session, push);
PHP_METHOD(Leevel_Session_Session, merge);
PHP_METHOD(Leevel_Session_Session, pop);
PHP_METHOD(Leevel_Session_Session, arr);
PHP_METHOD(Leevel_Session_Session, arrDelete);
PHP_METHOD(Leevel_Session_Session, get);
PHP_METHOD(Leevel_Session_Session, getPart);
PHP_METHOD(Leevel_Session_Session, delete);
PHP_METHOD(Leevel_Session_Session, has);
PHP_METHOD(Leevel_Session_Session, clear);
PHP_METHOD(Leevel_Session_Session, flash);
PHP_METHOD(Leevel_Session_Session, flashs);
PHP_METHOD(Leevel_Session_Session, nowFlash);
PHP_METHOD(Leevel_Session_Session, nowFlashs);
PHP_METHOD(Leevel_Session_Session, rebuildFlash);
PHP_METHOD(Leevel_Session_Session, keepFlash);
PHP_METHOD(Leevel_Session_Session, getFlash);
PHP_METHOD(Leevel_Session_Session, deleteFlash);
PHP_METHOD(Leevel_Session_Session, clearFlash);
PHP_METHOD(Leevel_Session_Session, unregisterFlash);
PHP_METHOD(Leevel_Session_Session, prevUrl);
PHP_METHOD(Leevel_Session_Session, setPrevUrl);
PHP_METHOD(Leevel_Session_Session, destroy);
PHP_METHOD(Leevel_Session_Session, isStart);
PHP_METHOD(Leevel_Session_Session, setName);
PHP_METHOD(Leevel_Session_Session, getName);
PHP_METHOD(Leevel_Session_Session, setId);
PHP_METHOD(Leevel_Session_Session, getId);
PHP_METHOD(Leevel_Session_Session, regenerateId);
PHP_METHOD(Leevel_Session_Session, getConnect);
PHP_METHOD(Leevel_Session_Session, generateSessionId);
PHP_METHOD(Leevel_Session_Session, parseMicrotime);
PHP_METHOD(Leevel_Session_Session, getNormalizeName);
PHP_METHOD(Leevel_Session_Session, loadData);
PHP_METHOD(Leevel_Session_Session, loadDataFromConnect);
PHP_METHOD(Leevel_Session_Session, popOldFlash);
PHP_METHOD(Leevel_Session_Session, mergeOldFlash);
PHP_METHOD(Leevel_Session_Session, popNewFlash);
PHP_METHOD(Leevel_Session_Session, mergeNewFlash);
PHP_METHOD(Leevel_Session_Session, getPartData);
PHP_METHOD(Leevel_Session_Session, flashDataKey);
PHP_METHOD(Leevel_Session_Session, flashNewKey);
PHP_METHOD(Leevel_Session_Session, flashOldKey);
PHP_METHOD(Leevel_Session_Session, prevUrlKey);
zend_object *zephir_init_properties_Leevel_Session_Session(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, connect, SessionHandlerInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, option, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_start, 0, 0, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_arr, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_arrdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_flash, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_flashs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flash, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_nowflash, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_nowflashs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flash, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_getflash, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_setprevurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_setname, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_setid, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_getnormalizename, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_popoldflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_mergeoldflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_popnewflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_mergenewflash, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_getpartdata, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_session_flashdatakey, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_session_method_entry) {
	PHP_ME(Leevel_Session_Session, __construct, arginfo_leevel_session_session___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Leevel_Session_Session, start, arginfo_leevel_session_session_start, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, save, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, set, arginfo_leevel_session_session_set, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, put, arginfo_leevel_session_session_put, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, push, arginfo_leevel_session_session_push, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, merge, arginfo_leevel_session_session_merge, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, pop, arginfo_leevel_session_session_pop, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, arr, arginfo_leevel_session_session_arr, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, arrDelete, arginfo_leevel_session_session_arrdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, get, arginfo_leevel_session_session_get, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, getPart, arginfo_leevel_session_session_getpart, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, delete, arginfo_leevel_session_session_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, has, arginfo_leevel_session_session_has, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, flash, arginfo_leevel_session_session_flash, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, flashs, arginfo_leevel_session_session_flashs, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, nowFlash, arginfo_leevel_session_session_nowflash, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, nowFlashs, arginfo_leevel_session_session_nowflashs, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, rebuildFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, keepFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, getFlash, arginfo_leevel_session_session_getflash, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, deleteFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, clearFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, unregisterFlash, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, prevUrl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, setPrevUrl, arginfo_leevel_session_session_setprevurl, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, destroy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, isStart, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, setName, arginfo_leevel_session_session_setname, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, setId, arginfo_leevel_session_session_setid, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, regenerateId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, getConnect, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Leevel_Session_Session, generateSessionId, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, parseMicrotime, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, getNormalizeName, arginfo_leevel_session_session_getnormalizename, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, loadData, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, loadDataFromConnect, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, popOldFlash, arginfo_leevel_session_session_popoldflash, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, mergeOldFlash, arginfo_leevel_session_session_mergeoldflash, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, popNewFlash, arginfo_leevel_session_session_popnewflash, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, mergeNewFlash, arginfo_leevel_session_session_mergenewflash, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, getPartData, arginfo_leevel_session_session_getpartdata, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, flashDataKey, arginfo_leevel_session_session_flashdatakey, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, flashNewKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, flashOldKey, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Leevel_Session_Session, prevUrlKey, NULL, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
