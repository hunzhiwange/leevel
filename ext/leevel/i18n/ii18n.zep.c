
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * II18n 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.06
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_I18n_II18n) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\I18n, II18n, leevel, i18n_ii18n, leevel_i18n_ii18n_method_entry);

	return SUCCESS;

}

/**
 * 获取语言 text
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_I18n_II18n, getText);

/**
 * 获取语言 text
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_I18n_II18n, __);

/**
 * 添加语言包
 *
 * @param string $i18n 语言名字
 * @param array $data 语言包数据
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_I18n_II18n, addText);

/**
 * 设置当前语言包上下文环境
 *
 * @param string $i18n
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_I18n_II18n, setI18n);

/**
 * 获取当前语言包
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_I18n_II18n, getI18n);

/**
 * 返回所有语言包
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Leevel_I18n_II18n, all);

