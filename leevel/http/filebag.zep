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

use InvalidArgumentException;

/**
 * file bag
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2018.03.04
 * 
 * @version 1.0
 */
class FileBag extends Bag
{

    /**
     * 上传文件 keys
     * 
     * @var array
     */
    protected static fileKeys = [
        "error", 
        "name", 
        "size", 
        "tmp_name", 
        "type"
    ];
    
    /**
     * 构造函数
     * 
     * @param array $elements
     * @return void 
     */
    public function __construct(array elements = [])
    {
        let elements = this->normalizeArray(elements);

        this->add(elements);
    }
    
    /**
     * {@inheritdoc}
     */
    public function replace(array elements = []) -> void
    {
        let this->elements = [];
        
        let elements = this->normalizeArray(elements);

        this->add(elements);
    }
    
    /**
     * {@inheritdoc}
     */
    public function set(var key, var value) -> void
    {
        if ! (is_array(value)) && ! (is_object(value) && value instanceof UploadedFile) {
            throw new InvalidArgumentException(
                "An uploaded file must be an array or an instance of UploadedFile."
            );
        }

        parent::set(key, this->convertFile(value));
    }
    
    /**
     * {@inheritdoc}
     */
    public function add(array files = []) -> void
    {
        var key, file;
    
        for key, file in files {
            this->set(key, file);
        }
    }
    
    /**
     * 取回文件数组
     * 数组文件请在末尾加上反斜杆访问
     *
     * @param string $key
     * @param array $defaults
     * @return mixed
     */
    public function getArr(string key, array defaults = [])
    {
        var files, k, value;
    
        let files = [];
        for k, value in this->elements {
            if strpos(k, key) === 0 && typeof value !== "null" {
                let files[] = value;
            }
        }

        return files ? files : defaults;
    }
    
    /**
     * 转换上传信息到文件实例 UploadedFile
     *
     * @param array|\Leevel\Http\UploadedFile $file
     * @return \Leevel\Http\UploadedFile|null
     */
    protected function convertFile(var file)
    {
        var result;

        if is_object(file) && file instanceof UploadedFile {
            return file;
        }

        let file = this->normalizeFile(file);

        if file["error"] == UPLOAD_ERR_NO_FILE {
            let result = null;
        } else {
            let result = new UploadedFile(file["tmp_name"], file["name"], file["type"], file["error"]);
        }

        return result;
    }
    
    /**
     * 格式化 $_FILES 数组
     *
     * @param array $data
     * @return array
     */
    protected function normalizeFile(array data) -> array
    {
        var result, key, value, keys;
    
        let result = [];
        for key, value in data {
            if in_array(key, self::fileKeys) {
                let result[key] = value;
            }
        }

        let keys = this->normalizeKey(result);
        if keys !== self::fileKeys {
            throw new InvalidArgumentException(
                sprintf("An array uploaded file must be contain keys %s.", implode(",", self::fileKeys))
            );
        }

        return result;
    }
    
    /**
     * 格式化多维数组类文件为一维数组
     *
     * @param array $elements
     * @return array
     */
    protected function normalizeArray(array elements) -> array
    {
        var result, key, value, index, item, element, fileKey;
    
        let result = [];

        for key, value in elements {
            if typeof value == "array" {
                if array_key_exists("name", value) === false {
                    throw new InvalidArgumentException("An uploaded file must be contain key name.");
                } elseif isset value["name"] && is_array(value["name"]) {
                    for index, item in value["name"] {
                        let element = [];

                        for fileKey in self::fileKeys {
                            if !array_key_exists(fileKey, value) {
                                throw new InvalidArgumentException(
                                    sprintf("An uploaded file must be contain key %s.", fileKey)
                                );
                            }

                            if ! array_key_exists(index, value[fileKey]) {
                                throw new InvalidArgumentException(
                                    sprintf("An uploaded file must be contain %s in key %s.", index, fileKey)
                                );
                            }

                            let element[fileKey] = isset value[fileKey][index] ? value[fileKey][index] : "";
                        }

                        let result[key . "\\" . index] = element;
                        let result = this->normalizeArray(result);
                    }
                } else {
                    let result[key] = value;
                }
            } else {
                let result[key] = value;
            }
        }

        return result;
    }
    
    /**
     * 格式化 keys
     *
     * @param array $data
     * @return array
     */
    protected function normalizeKey(array data) -> array
    {
        var keys;
    
        let keys = array_keys(data);
        sort(keys);

        return keys;
    }
}
