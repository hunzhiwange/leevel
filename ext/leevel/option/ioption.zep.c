
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ioption 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Option_IOption) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Option, IOption, leevel, option_ioption, leevel_option_ioption_method_entry);

	return SUCCESS;

}

/**
 * 是否存在配置
 *
 * @param string $name 配置键值
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Option_IOption, has);

/**
 * 获取配置
 *
 * @param string $name 配置键值
 * @param mixed $defaults 配置默认值
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Option_IOption, get);

/**
 * 返回所有配置
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_Option_IOption, all);

/**
 * 设置配置
 *
 * @param mixed $name 配置键值
 * @param mixed $value 配置值
 */
ZEPHIR_DOC_METHOD(Leevel_Option_IOption, set);

/**
 * 删除配置
 *
 * @param string $name 配置键值
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Option_IOption, delete);

/**
 * 初始化配置参数
 *
 * @param mixed $namespaces
 * @return boolean
 */
ZEPHIR_DOC_METHOD(Leevel_Option_IOption, reset);

