
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ILog 接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.11
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Log_ILog) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Log, ILog, leevel, log_ilog, leevel_log_ilog_method_entry);

	/**
	 * debug.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("DEBUG"), "debug");

	/**
	 * info.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("INFO"), "info");

	/**
	 * notice.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("NOTICE"), "notice");

	/**
	 * warning.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("WARNING"), "warning");

	/**
	 * error.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("ERROR"), "error");

	/**
	 * critical.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("CRITICAL"), "critical");

	/**
	 * alert.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("ALERT"), "alert");

	/**
	 * emergency.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_log_ilog_ce, SL("EMERGENCY"), "emergency");

	return SUCCESS;

}

/**
 * 设置配置.
 *
 * @param string $name
 * @param mixed  $value
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, setOption);

/**
 * 系统无法使用.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, emergency);

/**
 * 必须立即采取行动.
 *
 * 比如: 整个网站宕机，数据库不可用等等.
 * 这种错误应该通过短信通知你.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, alert);

/**
 * 临界条件.
 *
 * 比如: 应用程序组件不可用，意外异常.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, critical);

/**
 * 运行时错误，不需要立即处理.
 * 但是需要被记录和监控.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, error);

/**
 * 非错误的异常事件.
 *
 * 比如: 弃用的 API 接口, API 使用不足, 不良事物.
 * 它们不一定是错误的.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, warning);

/**
 * 正常重要事件.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, notice);

/**
 * 想记录的日志.
 *
 * 比如: 用户日志, SQL 日志.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, info);

/**
 * 调试信息.
 *
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, debug);

/**
 * 记录特定级别的日志信息.
 *
 * @param mixed  $level
 * @param string $message
 * @param array  $context
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, log);

/**
 * 保存日志信息.
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, flush);

/**
 * 清理日志记录.
 *
 * @param string $level
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, clear);

/**
 * 获取日志记录.
 *
 * @param string $level
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, all);

/**
 * 获取日志记录数量.
 *
 * @param string $level
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, count);

/**
 * 注册日志过滤器.
 *
 * @param \Closure $filter
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, filter);

/**
 * 注册日志处理器.
 *
 * @param \Closure $processor
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, processor);

/**
 * 是否为 Monolog.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, isMonolog);

/**
 * 取得 Monolog.
 *
 * @return null|\Monolog\Logger
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, getMonolog);

/**
 * 返回连接.
 *
 * @return \Leevel\Log\IConnect
 */
ZEPHIR_DOC_METHOD(Leevel_Log_ILog, getConnect);

