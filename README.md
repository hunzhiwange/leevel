![](leevel.png)

<p align="center">
  <a href="https://github.styleci.io/repos/115134497"><img src="https://github.styleci.io/repos/115134497/shield?branch=master" alt="StyleCI"></a>
  <a href="https://travis-ci.org/hunzhiwange/leevel">
    <img alt="Build Status" src="https://img.shields.io/travis/hunzhiwange/leevel.svg" /></a>
  <a href="https://github.com/hunzhiwange/leevel/releases">
    <img alt="Latest Version" src="https://poser.pugx.org/hunzhiwange/leevel/version" /></a>
  <a href="http://opensource.org/licenses/MIT">
    <img alt="Leevel License" src="https://poser.pugx.org/hunzhiwange/leevel/license.svg" /></a>
</p>

# The Leevel Framework To Rebuild QueryPHP

Leevel is an open source web framework delivered as a C extension and supplement for the QueryPHP framework providing high performance and lower resource consumption.

* Site: <https://www.queryphp.com/>
* API: <http://api.queryphp.com>
* Document: <https://www.leevel.vip/>

## The core packages

 * QueryPHP On Github: <https://github.com/hunzhiwange/queryphp/>
 * QueryPHP On Gitee: <https://gitee.com/dyhb/queryphp/>
 * Framework On Github: <https://github.com/hunzhiwange/framework/>
 * Framework On Gitee: <https://gitee.com/dyhb/framework/>
 * Leevel On Github: <https://github.com/hunzhiwange/leevel/>
 * Leevel On Gitee: <https://gitee.com/dyhb/queryyetsimple>
 * Test: <https://github.com/queryyetsimple/tests/>
 * Package: <https://github.com/queryyetsimple/>

## Requirement

```
version_compare(PHP_VERSION, '7.1.3', '<') && die('PHP 7.1.3 OR Higher');
```

## How to install

### Windows

Need to tests.

### Linux 

You can download the source code.

```
git clone git@github.com:hunzhiwange/leevel.git
cd ext
```


Then compile it.

```
$/path/to/phpize
$./configure --with-php-config=/path/to/php-config
$make && make install
```

Then add extension to your php.ini,you can see if installation is successful by command php -m.

```
extension = leevel.so
```

## Official Documentation

Documentation for the framework can be found on the [Leevel website](http://www.queryphp.com).

## Run Tests

```
$cd /data/codes/leevel      
$composer install
$php vendor/bin/phpunit tests
```

## Travis CI Supported

Let code poem.

## License

The Leevel framework is open-sourced software licensed under the [MIT license](http://opensource.org/licenses/MIT).
