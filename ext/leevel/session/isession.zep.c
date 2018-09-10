
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ISession 接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.11
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Session_ISession) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Session, ISession, leevel, session_isession, leevel_session_isession_method_entry);

	/**
	 * 默认 session 名字.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_session_isession_ce, SL("SESSION_NAME"), "UID");

	return SUCCESS;

}

/**
 * 启动 session.
 *
 * @param string $sessionId
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, start);

/**
 * 程序执行保存 session.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, save);

/**
 * 取回所有 session 数据.
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, all);

/**
 * 设置 session.
 *
 * @param string $name
 * @param mxied  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, set);

/**
 * 批量插入.
 *
 * @param array|string $keys
 * @param mixed        $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, put);

/**
 * 数组插入数据.
 *
 * @param string $key
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, push);

/**
 * 合并元素.
 *
 * @param string $key
 * @param array  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, merge);

/**
 * 弹出元素.
 *
 * @param string $key
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, pop);

/**
 * 数组插入键值对数据.
 *
 * @param string $key
 * @param mixed  $keys
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, arr);

/**
 * 数组键值删除数据.
 *
 * @param string $key
 * @param mixed  $keys
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, arrDelete);

/**
 * 取回 session.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return mxied
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, get);

/**
 * 返回数组部分数据.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, getPart);

/**
 * 删除 session.
 *
 * @param string $name
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, delete);

/**
 * 是否存在 session.
 *
 * @param string $name
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, has);

/**
 * 删除 session.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, clear);

/**
 * 闪存一个数据，当前请求和下一个请求可用.
 *
 * @param string $key
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, flash);

/**
 * 批量闪存数据，当前请求和下一个请求可用.
 *
 * @param array $flash
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, flashs);

/**
 * 闪存一个 flash 用于当前请求使用，下一个请求将无法获取.
 *
 * @param string $key
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, nowFlash);

/**
 * 保持所有闪存数据.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, rebuildFlash);

/**
 * 保持闪存数据.
 *
 * @param mixed $keys
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, keepFlash);

/**
 * 返回闪存数据.
 *
 * @param string $key
 * @param mixed  $defaults
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, getFlash);

/**
 * 删除闪存数据.
 *
 * @param mixed $keys
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, deleteFlash);

/**
 * 清理所有闪存数据.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, clearFlash);

/**
 * 程序执行结束清理 flash.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, unregisterFlash);

/**
 * 获取前一个请求地址
 *
 * @return null|string
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, prevUrl);

/**
 * 设置前一个请求地址
 *
 * @param string $url
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, setPrevUrl);

/**
 * 终止会话.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, destroy);

/**
 * session 是否已经启动.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, isStart);

/**
 * 设置 SESSION 名字.
 *
 * @param string $name
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, setName);

/**
 * 取得 SESSION 名字.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, getName);

/**
 * 设置 SESSION ID.
 *
 * @param string $id
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, setId);

/**
 * 取得 SESSION ID.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, getId);

/**
 * 重新生成 SESSION ID.
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, regenerateId);

/**
 * 返回连接.
 *
 * @return \SessionHandlerInterface
 */
ZEPHIR_DOC_METHOD(Leevel_Session_ISession, getConnect);

