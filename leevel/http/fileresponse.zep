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

use DateTime;
use SplFileInfo;
use SplFileObject;
use LogicException;
use InvalidArgumentException;

/**
 * FILE 响应请求
 * This class borrows heavily from the Symfony4 Framework and is part of the symfony package
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.06
 * @version 1.0
 * @see Symfony\Component\HttpFoundation (https://github.com/symfony/symfony)
 */
class FileResponse extends Response
{

    /**
     * 文件
     * 
     * @var \Leevel\Http\File
     */
    protected file;

    /**
     * 构造函数
     * 
     * @param \SplFileObject|\SplFileInfo|string $file
     * @param integer $status
     * @param array $headers
     * @param null|string $contentDisposition
     * @param bool $autoEtag
     * @param bool $autoLastModified
     * @return void
     */
    public function __construct(var file, int status = 200, array headers = [], var contentDisposition = null, boolean autoEtag = false, boolean autoLastModified = true)
    {
        parent::__construct(null, status, headers);

        this->setFile(file, contentDisposition, autoEtag, autoLastModified);
    }
    
    /**
     * 创建一个文件响应
     * 
     * @param \SplFileObject|\SplFileInfo|string $file
     * @param integer $status
     * @param array $headers
     * @param null|string $contentDisposition
     * @param bool $autoEtag
     * @param bool $autoLastModified
     * @return static
     */
    public static function create(var file = null, int status = 200, array headers = [], var contentDisposition = null, boolean autoEtag = false, boolean autoLastModified = true)
    {
        return new static(file, status, headers, contentDisposition, autoEtag, autoLastModified);
    }
    
    /**
     * 设置文件
     *
     * @param \SplFileObject|\SplFileInfo|string $file 
     * @param string $contentDisposition
     * @param bool $autoEtag
     * @param bool $autoLastModified
     * @return $this
     */
    public function setFile(var file, var contentDisposition = null, boolean autoEtag = false, boolean autoLastModified = true)
    {
        var files;

        if this->checkTControl() {
            return this;
        }

        if ! (is_object(file) && file instanceof File) {
            if is_object(file) && (file instanceof SplFileInfo || file instanceof SplFileObject) {
                let files = new File(file->getPathname());
            } else {
                if (!is_readable(file)) {
                    throw new FileException("File must be readable.");
                }

                let files = new File(strval(file));
            }
        } else {
            let files = file;
        }

        if ! (files->isReadable()) {
            throw new FileException("File must be readable.");
        }

        let this->file = files;

        if autoEtag {
            this->setAutoEtag();
        }

        if autoLastModified {
            this->setAutoLastModified();
        }

        if contentDisposition {
            this->setContentDisposition(contentDisposition);
        }
        
        return this;
    }
    
    /**
     * 取回文件
     *
     * @return \Leevel\Http\File
     */
    public function getFile() -> <File>
    {
        return this->file;
    }
    
    /**
     * 自动设置最后修改时间
     *
     * @return void
     */
    public function setAutoLastModified()
    {
        if this->checkTControl() {
            return this;
        }

        this->setLastModified(DateTime::createFromFormat("U", strval(this->file->getMTime())));

        return this;
    }
    
    /**
     * 自动设置标记
     *
     * @return void
     */
    public function setAutoEtag()
    {
        var etag;
    
        if this->checkTControl() {
            return this;
        }

        let etag = base64_encode(hash_file("sha256", this->file->getPathname(), true));
        this->setEtag(etag);

        return this;
    }
    
    /**
     * {@inheritdoc}
     */
    public function setContent(var content)
    {
        if this->checkTControl() {
            return this;
        }

        if content !== null {
            throw new LogicException("The content cannot be set on a FileResponse instance.");
        }

        return this;
    }
    
    /**
     * {@inheritdoc}
     */
    public function getContent()
    {
        return false;
    }
    
    /**
     * 设置文件下载模式
     *
     * @param string $disposition
     * @param string $filename
     * @return $this
     */
    public function setContentDisposition(string disposition, var filename = "")
    {
        if this->checkTControl() {
            return this;
        }

        if filename === "" {
            let filename = this->file->getFilename();
        }

        if ! (in_array(disposition, [
            ResponseHeaderBag::DISPOSITION_ATTACHMENT, 
            ResponseHeaderBag::DISPOSITION_INLINE
        ])) {
            throw new InvalidArgumentException("The disposition type is invalid.");
        }

        this->headers->set(
            "Content-Disposition",
            sprintf("%s; filename=\"%s\"", disposition, str_replace("\"", "\\\"", basename(filename)))
        );

        return this;
    }
    
    /**
     * {@inheritdoc}
     */
    public function sendContent()
    {
        var out, file;
    
        if this->checkTControl() {
            return this;
        }

        if ! (this->isSuccessful()) {
            return parent::sendContent();
        }

        let out = fopen("php://output", "wb");
        let file = fopen(this->file->getPathname(), "rb");
        
        stream_copy_to_stream(file, out);
        fclose(out);
        fclose(file);

        return this;
    }
}
