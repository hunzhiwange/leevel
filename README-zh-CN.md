![](leevel.png)

<p align="center">
  <a href="https://github.styleci.io/repos/115134497"><img src="https://github.styleci.io/repos/115134497/shield?branch=master" alt="StyleCI"></a>
  <a href="https://travis-ci.org/hunzhiwange/leevel">
    <img alt="Build Status" src="https://img.shields.io/travis/hunzhiwange/leevel.svg" /></a>
  <a href="https://github.com/hunzhiwange/leevel/releases">
    <img alt="Latest Version" src="https://poser.pugx.org/hunzhiwange/leevel-ext/version" /></a>
  <a href="http://opensource.org/licenses/MIT">
    <img alt="Leevel License" src="https://poser.pugx.org/hunzhiwange/leevel-ext/license.svg" /></a>
</p>

<p align="center">
    <a href="./README.md">English</a> | <a href="./README-zh-CN.md">中文</a>
</p>

# Leevel 高性能 PHP 扩展开发框架

Leevel 是一个开源 PHP C 扩展开发框架，采用 zephir 编写，是为了解决使用框架带来性能下降的经典矛盾，Leevel 是为了解决 QueryPHP 性能而开发，可以与同版本的 QueryPHP 混合使用，将接管 composer 中的 PHP 版本功能。

* 官方网站: <https://www.queryphp.com/>
* API 接口: <https://api.queryphp.com>
* 开发文档: <https://www.leevel.vip/>

## 核心包

 * QueryPHP On Github: <https://github.com/hunzhiwange/queryphp/>
 * QueryPHP On Gitee: <https://gitee.com/dyhb/queryphp/>
 * Framework On Github: <https://github.com/hunzhiwange/framework/>
 * Framework On Gitee: <https://gitee.com/dyhb/framework/>
 * Leevel On Github: <https://github.com/hunzhiwange/leevel/>
 * Leevel On Gitee: <https://gitee.com/dyhb/leevel>
 * Tests: <https://github.com/leevels/tests/>
 * Packages: <https://github.com/leevels/>
 * Packages From Hunzhiwange: <https://packagist.org/packages/hunzhiwange/>
 * Packages From Leevel: <https://packagist.org/packages/leevel/>

## 最低 PHP 版本支持

```
version_compare(PHP_VERSION, '7.1.3', '<') && die('PHP 7.1.3 OR Higher');
```

## 如何安装

### Windows

后续会提供 dll 扩展.

### Linux

从下面的仓库下载源代码.

```
git clone git@github.com:hunzhiwange/leevel.git
cd ext
```


GCC 编译源码.

```
$/path/to/phpize
$./configure --with-php-config=/path/to/php-config
$make && make install
```

将扩展添加到你的 php.ini, 使用 php -m 查看扩展是否被安装.

```
extension = leevel.so
```

## 官方文档

请访问官方网站即即可查看 [Leevel website](http://www.queryphp.com).

## 运行测试文件

```
$cd /data/codes/leevel      
$composer install
$php vendor/bin/phpunit tests
```

## Travis CI 持续集成支持

让代码提交更值得信赖.

## 版权协议

Leevel 采用 [MIT license](http://opensource.org/licenses/MIT) 授权许可协议，更自由。
