
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IContainer 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.13
 * 
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Di_IContainer) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Di, IContainer, leevel, di_icontainer, leevel_di_icontainer_method_entry);

	return SUCCESS;

}

/**
 * 注册到容器
 *
 * @param mixed $name
 * @param mixed $service
 * @param boolean $share
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, bind);

/**
 * 注册为实例
 *
 * @param mixed $name
 * @param mixed $service
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, instance);

/**
 * 注册单一实例
 *
 * @param string $name
 * @param mixed $service
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, singleton);

/**
 * 创建共享的闭包
 *
 * @param \Closure $closure
 * @return \Closure
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, share);

/**
 * 设置别名
 *
 * @param array|string $alias
 * @param string|null|array $value
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, alias);

/**
 * 服务容器返回对象
 *
 * @param string $name
 * @param array $args
 * @return object|false
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, make);

/**
 * 实例回调自动注入
 *
 * @param callable|array|string $callback
 * @param array $args
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, call);

/**
 * 删除服务和实例
 *
 * @param string $name
 * @return void
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, remove);

/**
 * 服务或者实例是否存在
 *
 * @param string $name
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Di_IContainer, exists);

