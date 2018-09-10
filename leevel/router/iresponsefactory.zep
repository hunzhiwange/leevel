/*
 * This file is part of the ************************ package.
 * _____________                           _______________
 *  ______/     \__  _____  ____  ______  / /_  _________
 *   ____/ __   / / / / _ \/ __`\/ / __ \/ __ \/ __ \___
 *    __/ / /  / /_/ /  __/ /  \  / /_/ / / / / /_/ /__
 *      \_\ \_/\____/\___/_/   / / .___/_/ /_/ .___/
 *         \_\                /_/_/         /_/
 *
 * The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
 * (c) 2010-2018 http://queryphp.com All rights reserved.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Leevel\Router;

/**
 * 响应工厂接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.07
 * @version 1.0
 */
interface IResponseFactory
{
    /**
     * 返回一个响应
     * 
     * @param string $content
     * @param integer $status
     * @param array $headers
     * @return \Leevel\Http\Response
     */
    public function make(string content = "", int status = 200, array headers = []);
    
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
    public function view(var file = null, array vars = [], var ext = null, int status = 200, array headers = []);
    
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
    public function viewSuccess(string message = "", string url = "", int time = 1, int status = 200, array headers = []);
    
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
    public function viewError(string message = "", string url = "", int time = 3, int status = 200, array headers = []);
    
    /**
     * 返回 JSON 响应
     *
     * @param string $data
     * @param integer $status
     * @param array $headers
     * @param bool $json
     * @return \Leevel\Http\JsonResponse
     */
    public function json(var data = null, int status = 200, array headers = [], boolean json = false);
    
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
    public function jsonp(string callback, var data = null, int status = 200, array headers = [], boolean json = false);
    
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
    public function download(var file, var name = null, int status = 200, array headers = [], boolean autoEtag = false, boolean autoLastModified = true);
    
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
    public function file(var file, int status = 200, array headers = [], boolean autoEtag = false, boolean autoLastModified = true);
    
    /*
     * 返回一个 URL 生成跳转响应
     *
     * @param string $url
     * @param array $params
     * @param string $subdomain
     * @param mixed $suffix
     * @param int $status
     * @param array $headers
     * @return \Leevel\Http\RedirectResponse
     */
    public function redirect(string url, array params = [], string subdomain = "www", var suffix = false, int status = 302, array headers = []);
    
    /**
     * 返回一个跳转响应
     *
     * @param string $url
     * @param int $status
     * @param array $headers
     * @return \Leevel\Http\RedirectResponse
     */
    public function redirectRaw(string url, int status = 302, array headers = []);
    
    /**
     * 请求成功
     * 一般用于GET与POST请求： 200
     * 
     * @param mixed $content
     * @param string $text
     * @return $this
     */
    public function apiOk(var content = "", var text = null);
    
    /**
     * 已创建
     * 成功请求并创建了新的资源: 201
     *
     * @param null|string $location
     * @return $this
     */
    public function apiCreated(var location = "", var content = "");
    
    /**
     * 已接受
     * 已经接受请求，但未处理完成: 202
     *
     * @param null|string $location
     * @param mixed $content
     * @return $this
     */
    public function apiAccepted(var location = null, var content = "");
    
    /**
     * 无内容
     * 服务器成功处理，但未返回内容: 204
     *
     * @return $this
     */
    public function apiNoContent();
    
    /**
     * 错误请求
     * 服务器不理解请求的语法: 400
     * 
     * @param string $message
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiError(string message, var statusCode, var text = null);
    
    /**
     * 错误请求
     * 服务器不理解请求的语法: 400
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiBadRequest(var message = null, var text = null);
    
    /**
     * 未授权
     * 对于需要登录的网页，服务器可能返回此响应: 401
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiUnauthorized(var message = null, var text = null);
    
    /**
     * 禁止
     * 服务器拒绝请求: 403
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiForbidden(var message = null, var text = null);
    
    /**
     * 未找到
     * 用户发出的请求针对的是不存在的记录: 404
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiNotFound(var message = null, var text = null);
    
    /**
     * 方法禁用
     * 禁用请求中指定的方法: 405
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiMethodNotAllowed(var message = null, var text = null);
    
    /**
     * 无法处理的实体
     * 请求格式正确，但是由于含有语义错误，无法响应: 422
     * 
     * @param array $errors
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiUnprocessableEntity(array errors = null, var message = null, var text = null);
    
    /**
     * 太多请求
     * 用户在给定的时间内发送了太多的请求: 429
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiTooManyRequests(var message = null, var text = null);
    
    /**
     * 服务器内部错误
     * 服务器遇到错误，无法完成请求: 500
     * 
     * @param string $message
     * @param string $text
     * @return $this
     */
    public function apiInternalServerError(var message = null, var text = null);
    
    /**
     * 设置视图正确模板
     * 
     * @param string $template
     * @return $this
     */
    public function setViewSuccessTemplate(string template);
    
    /**
     * 设置视图错误模板
     * 
     * @param string $template
     * @return $this
     */
    public function setViewFailTemplate(string template);
}
