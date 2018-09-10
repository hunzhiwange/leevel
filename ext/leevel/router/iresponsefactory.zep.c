
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * 响应工厂接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Router_IResponseFactory) {

	ZEPHIR_REGISTER_INTERFACE(Leevel\\Router, IResponseFactory, leevel, router_iresponsefactory, leevel_router_iresponsefactory_method_entry);

	return SUCCESS;

}

/**
 * 返回一个响应
 * 
 * @param string $content
 * @param integer $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, make);

/**
 * 返回视图响应
 *
 * @param string $file
 * @param array $vars
 * @param string $ext
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, view);

/**
 * 返回视图正确消息
 *
 * @param string $message
 * @param string $url
 * @param int $time
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, viewSuccess);

/**
 * 返回视图错误消息
 *
 * @param string $message
 * @param string $url
 * @param int $time
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\Response
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, viewError);

/**
 * 返回 JSON 响应
 *
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @param bool $json
 * @return \Leevel\Http\JsonResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, json);

/**
 * 返回 JSONP 响应
 *
 * @param string $callback
 * @param string $data
 * @param integer $status
 * @param array $headers
 * @param bool $json
 * @return \Leevel\Http\JsonResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, jsonp);

/**
 * 返回下载响应
 *
 * @param \SplFileObject|\SplFileInfo|string $file
 * @param string $name
 * @param integer $status
 * @param array $headers
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return \Leevel\Http\FileResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, download);

/**
 * 返回文件响应
 *
 * @param \SplFileObject|\SplFileInfo|string $file
 * @param integer $status
 * @param array $headers
 * @param bool $autoEtag
 * @param bool $autoLastModified
 * @return \Leevel\Http\FileResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, file);

ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, redirect);

/**
 * 返回一个跳转响应
 *
 * @param string $url
 * @param int $status
 * @param array $headers
 * @return \Leevel\Http\RedirectResponse
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, redirectRaw);

/**
 * 请求成功
 * 一般用于GET与POST请求： 200
 * 
 * @param mixed $content
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiOk);

/**
 * 已创建
 * 成功请求并创建了新的资源: 201
 *
 * @param null|string $location
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiCreated);

/**
 * 已接受
 * 已经接受请求，但未处理完成: 202
 *
 * @param null|string $location
 * @param mixed $content
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiAccepted);

/**
 * 无内容
 * 服务器成功处理，但未返回内容: 204
 *
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiNoContent);

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 * 
 * @param string $message
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiError);

/**
 * 错误请求
 * 服务器不理解请求的语法: 400
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiBadRequest);

/**
 * 未授权
 * 对于需要登录的网页，服务器可能返回此响应: 401
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiUnauthorized);

/**
 * 禁止
 * 服务器拒绝请求: 403
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiForbidden);

/**
 * 未找到
 * 用户发出的请求针对的是不存在的记录: 404
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiNotFound);

/**
 * 方法禁用
 * 禁用请求中指定的方法: 405
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiMethodNotAllowed);

/**
 * 无法处理的实体
 * 请求格式正确，但是由于含有语义错误，无法响应: 422
 * 
 * @param array $errors
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiUnprocessableEntity);

/**
 * 太多请求
 * 用户在给定的时间内发送了太多的请求: 429
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiTooManyRequests);

/**
 * 服务器内部错误
 * 服务器遇到错误，无法完成请求: 500
 * 
 * @param string $message
 * @param string $text
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, apiInternalServerError);

/**
 * 设置视图正确模板
 * 
 * @param string $template
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, setViewSuccessTemplate);

/**
 * 设置视图错误模板
 * 
 * @param string $template
 * @return $this
 */
ZEPHIR_DOC_METHOD(Leevel_Router_IResponseFactory, setViewFailTemplate);

