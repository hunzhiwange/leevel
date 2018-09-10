
extern zend_class_entry *leevel_session_isession_ce;

ZEPHIR_INIT_CLASS(Leevel_Session_ISession);

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_start, 0, 0, 0)
	ZEND_ARG_INFO(0, sessionId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_set, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_put, 0, 0, 1)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_push, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_merge, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_pop, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_ARRAY_INFO(0, value, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_arr, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_arrdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, keys)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_getpart, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_has, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_flash, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_flashs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, flash, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_nowflash, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_getflash, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, defaults)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_setprevurl, 0, 0, 1)
	ZEND_ARG_INFO(0, url)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_setname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_leevel_session_isession_setid, 0, 0, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(leevel_session_isession_method_entry) {
	PHP_ABSTRACT_ME(Leevel_Session_ISession, start, arginfo_leevel_session_isession_start)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, save, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, all, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, set, arginfo_leevel_session_isession_set)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, put, arginfo_leevel_session_isession_put)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, push, arginfo_leevel_session_isession_push)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, merge, arginfo_leevel_session_isession_merge)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, pop, arginfo_leevel_session_isession_pop)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, arr, arginfo_leevel_session_isession_arr)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, arrDelete, arginfo_leevel_session_isession_arrdelete)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, get, arginfo_leevel_session_isession_get)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, getPart, arginfo_leevel_session_isession_getpart)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, delete, arginfo_leevel_session_isession_delete)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, has, arginfo_leevel_session_isession_has)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, clear, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, flash, arginfo_leevel_session_isession_flash)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, flashs, arginfo_leevel_session_isession_flashs)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, nowFlash, arginfo_leevel_session_isession_nowflash)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, rebuildFlash, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, keepFlash, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, getFlash, arginfo_leevel_session_isession_getflash)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, deleteFlash, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, clearFlash, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, unregisterFlash, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, prevUrl, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, setPrevUrl, arginfo_leevel_session_isession_setprevurl)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, destroy, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, isStart, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, setName, arginfo_leevel_session_isession_setname)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, getName, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, setId, arginfo_leevel_session_isession_setid)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, getId, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, regenerateId, NULL)
	PHP_ABSTRACT_ME(Leevel_Session_ISession, getConnect, NULL)
	PHP_FE_END
};
