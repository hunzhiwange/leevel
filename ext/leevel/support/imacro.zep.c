
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 实现类的无限扩展功能
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.02.04
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Support_IMacro) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Support, IMacro, leevel, support_imacro, leevel_support_imacro_method_entry);

	return SUCCESS;

}

/**
 * 注册一个扩展
 *
 * @param string $name
 * @param callable $macro
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Support_IMacro, macro);

/**
 * 判断一个扩展是否注册
 *
 * @param string $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Support_IMacro, hasMacro);

/**
 * __callStatic 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以取消 PHP 版本的静态闭包绑定功能
 *
 * @param string $method
 * @param array $args
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Support_IMacro, callStaticMacro);

/**
 * __call 魔术方法隐射
 * 由于 zephir 对应的 C 扩展版本不支持对象内绑定 class
 * 即 Closure::bind($closures, null, get_called_class())
 * 为保持功能一致，所以绑定对象但是不绑定作用域，即可以使用 $this,只能访问 public 属性
 * 
 * @param string $method
 * @param array $args
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Support_IMacro, callMacro);

