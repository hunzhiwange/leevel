
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * IProject 接口.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.23
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Kernel_IProject) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Kernel, IProject, leevel, kernel_iproject, leevel_kernel_iproject_method_entry);

	/**
	 * QueryPHP 版本.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_kernel_iproject_ce, SL("VERSION"), "1.0.0");

	/**
	 * 默认环境变量名字.
	 *
	 * @var string
	 */
	zephir_declare_class_constant_string(leevel_kernel_iproject_ce, SL("DEFAULT_ENV"), ".env");

	zend_class_implements(leevel_kernel_iproject_ce TSRMLS_CC, 1, leevel_di_icontainer_ce);
	return SUCCESS;

}

/**
 * 返回项目.
 *
 * @param string $path
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, singletons);

/**
 * 程序版本.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, version);

/**
 * 是否以扩展方式运行.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, runWithExtension);

/**
 * 是否为 Console.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, console);

/**
 * {@inheritdoc}
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, make);

/**
 * 设置项目路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPath);

/**
 * 基础路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, path);

/**
 * 设置应用路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setAppPath);

/**
 * 应用路径.
 *
 * @param bool|string $app
 * @param string      $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, appPath);

/**
 * 取得应用主题目录.
 *
 * @param bool|string $app
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, themePath);

/**
 * 设置公共路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setCommonPath);

/**
 * 公共路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, commonPath);

/**
 * 设置运行时路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setRuntimePath);

/**
 * 运行路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, runtimePath);

/**
 * 设置存储路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setStoragePath);

/**
 * 附件路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, storagePath);

/**
 * 设置资源路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setPublicPath);

/**
 * 资源路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, publicPath);

/**
 * 设置主题路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setThemesPath);

/**
 * 主题路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, themesPath);

/**
 * 设置配置路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setOptionPath);

/**
 * 配置路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, optionPath);

/**
 * 设置语言包路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setI18nPath);

/**
 * 语言包路径.
 *
 * @param string $path
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, i18nPath);

/**
 * 设置环境变量路径.
 *
 * @param string $path
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setEnvPath);

/**
 * 环境变量路径.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, envPath);

/**
 * 设置环境变量文件.
 *
 * @param string $file
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, setEnvFile);

/**
 * 取得环境变量文件.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, envFile);

/**
 * 取得环境变量完整路径.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, fullEnvPath);

/**
 * 返回语言包缓存路径.
 *
 * @param string $i18n
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, i18nCachedPath);

/**
 * 是否存在语言包缓存.
 *
 * @param string $i18n
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isCachedI18n);

/**
 * 返回配置缓存路径.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, optionCachedPath);

/**
 * 是否存在配置缓存.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isCachedOption);

/**
 * 返回路由缓存路径.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, routerCachedPath);

/**
 * 是否存在路由缓存.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isCachedRouter);

/**
 * 取得 composer.
 *
 * @return \Composer\Autoload\ClassLoader
 * @codeCoverageIgnore
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, composer);

/**
 * 获取命名空间路径.
 *
 * @param string $namespaces
 *
 * @return null|string
 * @codeCoverageIgnore
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, getPathByComposer);

/**
 * 是否开启 debug.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, debug);

/**
 * 是否为开发环境.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, development);

/**
 * 运行环境.
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, environment);

/**
 * 创建服务提供者.
 *
 * @param string $provider
 *
 * @return \Leevel\Di\Provider
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, makeProvider);

/**
 * 执行 bootstrap.
 *
 * @param \Leevel\Di\Provider $provider
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, callProviderBootstrap);

/**
 * 初始化项目.
 *
 * @param array $bootstraps
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, bootstrap);

/**
 * 是否已经初始化引导
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, isBootstrap);

/**
 * 框架基础提供者 register.
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, registerProviders);

/**
 * 执行框架基础提供者 bootstrap.
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, bootstrapProviders);

/**
 * 注册服务提供者.
 *
 * @param \Leevel\Di\Provider|string $provider
 *
 * @return \Leevel\Di\Provider
 */
ZEPHIR_DOC_METHOD(Leevel_Kernel_IProject, register);

