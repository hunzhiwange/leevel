
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * iconnect 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.01.02
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_View_IConnect) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\View, IConnect, leevel, view_iconnect, leevel_view_iconnect_method_entry);

	return SUCCESS;

}

/**
 * 加载视图文件
 *
 * @param string $file 视图文件地址
 * @param array $vars
 * @param string $ext 后缀
 * @param boolean $display 是否显示
 * @return void|string
 */
ZEPHIR_DOC_METHOD(Leevel_View_IConnect, display);

/**
 * 设置模板变量
 *
 * @param mixed $name
 * @param mixed $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_View_IConnect, setVar);

/**
 * 获取变量值
 *
 * @param string|null $name
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_View_IConnect, getVar);

/**
 * 删除变量值
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_View_IConnect, deleteVar);

/**
 * 清空变量值
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_View_IConnect, clearVar);

