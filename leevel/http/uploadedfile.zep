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
namespace Leevel\Http;

/**
 * 上传文件
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.05
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
class UploadedFile extends File
{

    /**
     * 文件原始名字
     * 
     * @var string
     */
    protected originalName;
    
    /**
     * 文件类型
     * 
     * @var string
     */
    protected mimeType;
    
    /**
     * 上传错误
     * 
     * @var int|null
     */
    protected error;
    
    /**
     * 上传错误消息格式化
     * 
     * @var array
     */
    protected static errors = [
        1 : "The file %s exceeds your upload_max_filesize ini directive (limit is %d KiB).",
        2 : "The file %s exceeds the upload limit defined in your form.", 
        3 : "The file %s was only partially uploaded.", 
        4 : "No file was uploaded.", 
        7 : "The file %s could not be written on disk.", 
        6 : "File could not be uploaded: missing temporary directory.", 
        8 : "File upload was stopped by a PHP extension."
    ];

    /**
     * 是否为测试.
     *
     * @var bool
     */
    protected test = false;
    
    /**
     * 构造函数
     * $_FILES['foo'](tmp_name, name, type, error)
     *
     * @param string $path
     * @param string $originalName
     * @param string|null $mimeType
     * @param int|null $error
     * @param bool $test
     */
    public function __construct(var path, var originalName, var mimeType = null, var error = null, bool test = false)
    {
        let this->originalName = originalName;
        let this->mimeType = mimeType ? mimeType : "application/octet-stream";
        let this->error = error ? error : UPLOAD_ERR_OK;
        let this->test = test;

        parent::__construct(path);
    }
    
    /**
     * 返回文件原始名字
     *
     * @return string|null
     */
    public function getOriginalName()
    {
        return this->originalName;
    }
    
    /**
     * 返回文件原始名字扩展
     *
     * @return string
     */
    public function getOriginalExtension() -> string
    {
        return pathinfo(this->originalName, PATHINFO_EXTENSION);
    }
    
    /**
     * 返回文件类型
     *
     * @return string|null
     */
    public function getMimeType()
    {
        return this->mimeType;
    }
    
    /**
     * 返回上传错误
     *
     * @return int
     */
    public function getError() -> int
    {
        return this->error;
    }
    
    /**
     * 文件是否上传成功
     *
     * @return bool
     */
    public function isValid() -> boolean
    {
        return UPLOAD_ERR_OK === this->error &&
            (this->test ? true : is_uploaded_file(this->getPathname()));
    }
    
    /**
     * {@inheritdoc}
     *
     * @codeCoverageIgnoreStart
     */
    public function move(var directory, var name = null)
    {
        var target;
    
        if this->isValid() {
            if (this->test) {
                return parent::move(directory, name);
            }

            let target = this->getTargetFile(directory, name);
            this->moveToTarget(this->getPathname(), target, true);

            return new File(target);
        }

        throw new FileException(this->getErrorMessage());
    }
    
    /**
     * 返回文件最大上传字节
     *
     * @return int
     * @codeCoverageIgnoreStart
     */
    public static function getMaxFilesize() -> int
    {
        var iniMax, max;
    
        let iniMax = strtolower(ini_get("upload_max_filesize"));

        if iniMax === "" {
            return PHP_INT_MAX;
        }

        let max = ltrim(iniMax, "+");

        if 0 === strpos(max, "0x") {
            let max = intval(max, 16);
        } elseif 0 === strpos(max, "0") {
            let max = intval(max, 8);
        } else {
            let max = intval(max);
        }

        switch (substr(iniMax, -1)) {
            case "t":
                let max *= 1024;
            case "g":
                let max *= 1024;
            case "m":
                let max *= 1024;
            case "k":
                let max *= 1024;
        }

        return max;
    }
    
    /**
     * 上传错误
     *
     * @return string
     */
    public function getErrorMessage() -> string
    {
        var errorCode, maxFilesize, message;
    
        let errorCode = this->error;
        let maxFilesize = errorCode === UPLOAD_ERR_INI_SIZE ? self::getMaxFilesize() / 1024 : 0;
        let message = isset self::errors[errorCode] ? self::errors[errorCode] : "The file %s was not uploaded due to an unknown error.";
        let message = sprintf(message, this->getOriginalName(), maxFilesize);

        return message;
    }
}
