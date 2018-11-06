
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/math.h"
#include "kernel/array.h"
#include "kernel/time.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "Zend/zend_closures.h"


/**
 * 字符串.
 *
 * @author Xiangmin Liu <635750556@qq.com>
 *
 * @since 2017.04.05
 *
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Leevel_Support_Str) {

	ZEPHIR_REGISTER_CLASS(Leevel\\Support, Str, leevel, support_str, leevel_support_str_method_entry, 0);

	/**
	 * 注册的动态扩展
	 *
	 * @var array
	 */
	zend_declare_property_null(leevel_support_str_ce, SL("macro"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(leevel_support_str_ce TSRMLS_CC, 1, leevel_support_imacro_ce);
	return SUCCESS;

}

/**
 * 随机字母数字.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randAlphaNum) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_0, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机小写字母数字.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randAlphaNumLowercase) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0$$5, _1;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "abcdefghijklmnopqrstuvwxyz1234567890");
	} else {
		ZEPHIR_INIT_VAR(&_0$$5);
		zephir_fast_strtolower(&_0$$5, charBox);
		ZEPHIR_CPY_WRT(charBox, &_0$$5);
	}
	ZVAL_LONG(&_1, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_1, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机大写字母数字.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randAlphaNumUppercase) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0$$5, _1;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
	} else {
		ZEPHIR_INIT_VAR(&_0$$5);
		zephir_fast_strtoupper(&_0$$5, charBox);
		ZEPHIR_CPY_WRT(charBox, &_0$$5);
	}
	ZVAL_LONG(&_1, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_1, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机字母.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randAlpha) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_0, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机小写字母.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randAlphaLowercase) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0$$5, _1;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "abcdefghijklmnopqrstuvwxyz");
	} else {
		ZEPHIR_INIT_VAR(&_0$$5);
		zephir_fast_strtolower(&_0$$5, charBox);
		ZEPHIR_CPY_WRT(charBox, &_0$$5);
	}
	ZVAL_LONG(&_1, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_1, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机大写字母.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randAlphaUppercase) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0$$5, _1;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	} else {
		ZEPHIR_INIT_VAR(&_0$$5);
		zephir_fast_strtoupper(&_0$$5, charBox);
		ZEPHIR_CPY_WRT(charBox, &_0$$5);
	}
	ZVAL_LONG(&_1, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_1, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机数字.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randNum) {

	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, _0;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_NVAR(charBox);
		ZVAL_STRING(charBox, "0123456789");
	}
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_STATIC("randstr", NULL, 0, &_0, charBox);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 随机字中文.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randChinese) {

	zval _0$$4;
	zend_bool _1;
	zephir_fcall_cache_entry *_5 = NULL, *_8 = NULL;
	zval *length_param = NULL, *charBox = NULL, charBox_sub, __$null, result, i, _4$$5, _6$$5, _7$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _14$$5;
	zend_long length, ZEPHIR_LAST_CALL_STATUS, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&i);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &length_param, &charBox);

	length = zephir_get_intval(length_param);
	if (!charBox) {
		charBox = &charBox_sub;
		ZEPHIR_CPY_WRT(charBox, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(charBox);
	}


	if (!(length)) {
		RETURN_MM_STRING("");
	}
	if (Z_TYPE_P(charBox) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZEPHIR_CONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS(&_0$$4, "在了不和有大这主中人上为们地个用工时要动国产以我到他会", "作来分生对于学下级就年阶义发成部民可出能方进同行面说种过命度革而", "多子后自社加小机也经力线本电高量长党得实家定深法表着水理化争现所", "二起政三好十战无农使性前等反体合斗路图把结第里正新开论之物从当两", "些还天资事队批如应形想制心样干都向变关点育重其思与间内去因件日利", "相由压员气业代全组数果期导平各基或月毛然问比展那它最及外没看治提", "五解系林者米群头意只明四道马认次文通但条较克又公孔领军流入接席位", "情运器并飞原油放立题质指建区验活众很教决特此常石强极土少已根共直", "团统式转别造切九您取西持总料连任志观调七么山程百报更见必真保热委", "手改管处己将修支识病象几先老光专什六型具示复安带每东增则完风回南", "广劳轮科北打积车计给节做务被整联步类集号列温装即毫知轴研单色坚据", "速防史拉世设达尔场织历花受求传口断况采精金界品判参层止边清至万确", "究书术状厂须离再目海交权且儿青才证低越际八试规斯近注办布门铁需走", "议县兵固除般引齿千胜细影济白格效置推空配刀叶率述今选养德话查差半", "敌始片施响收华觉备名红续均药标记难存测士身紧液派准斤角降维板许破", "述技消底床田势端感往神便贺村构照容非搞亚磨族火段算适讲按值美态黄", "易彪服早班麦削信排台声该击素张密害侯草何树肥继右属市严径螺检左页", "抗苏显苦英快称坏移约巴材省黑武培着河帝仅针怎植京助升王眼她抓含苗", "副杂普谈围食射源例致酸旧却充足短划剂宣环落首尺波承粉践府鱼随考刻", "靠够满夫失包住促枝局菌杆周护岩师举曲春元超负砂封换太模贫减阳扬江", "析亩木言球朝医校古呢稻宋听唯输滑站另卫字鼓刚写刘微略范供阿块某功", "套友限项余倒卷创律雨让骨远帮初皮播优占死毒圈伟季训控激找叫云互跟", "裂粮粒母练塞钢顶策双留误础吸阻故寸盾晚丝女散焊功株亲院冷彻弹错散", "商视艺灭版烈零室轻血倍缺厘泵察绝富城冲喷壤简否柱李望盘磁雄似困巩", "益洲脱投送奴侧润盖挥距触星松送获兴独官混纪依未突架宽冬章湿偏纹吃", "执阀矿寨责熟稳夺硬价努翻奇甲预职评读背协损棉侵灰虽矛厚罗泥辟告卵", "箱掌氧恩爱停曾溶营终纲孟钱待尽俄缩沙退陈讨奋械载胞幼哪剥迫旋征槽", "倒握担仍呀鲜吧卡粗介钻逐弱脚怕盐末阴丰编印蜂急拿扩伤飞露核缘游振", "操央伍域甚迅辉异序免纸夜乡久隶缸夹念兰映沟乙吗儒杀汽磷艰晶插埃燃", "欢铁补咱芽永瓦倾阵碳演威附牙芽永瓦斜灌欧献顺猪洋腐请透司危括脉宜", "笑若尾束壮暴企菜穗楚汉愈绿拖牛份染既秋遍锻玉夏疗尖殖井费州访吹荣", "铜沿替滚客召旱悟刺脑的一是");
		ZEPHIR_CPY_WRT(charBox, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&result);
	ZVAL_STRING(&result, "");
	ZEPHIR_INIT_VAR(&i);
	ZVAL_LONG(&i, 0);
	length--;
	_3 = length;
	_2 = 0;
	_1 = 0;
	if (_2 <= _3) {
		while (1) {
			if (_1) {
				_2++;
				if (!(_2 <= _3)) {
					break;
				}
			} else {
				_1 = 1;
			}
			ZEPHIR_INIT_NVAR(&i);
			ZVAL_LONG(&i, _2);
			ZEPHIR_INIT_NVAR(&_6$$5);
			ZVAL_STRING(&_6$$5, "utf-8");
			ZEPHIR_CALL_FUNCTION(&_7$$5, "mb_strlen", &_8, 151, charBox, &_6$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_9$$5, 0);
			ZVAL_LONG(&_10$$5, (zephir_get_numberval(&_7$$5) - 1));
			ZVAL_LONG(&_11$$5, zephir_mt_rand(zephir_get_intval(&_9$$5), zephir_get_intval(&_10$$5) TSRMLS_CC));
			ZVAL_DOUBLE(&_12$$5, zephir_floor(&_11$$5 TSRMLS_CC));
			ZVAL_LONG(&_13$$5, zephir_get_intval(&_12$$5));
			ZVAL_LONG(&_14$$5, 1);
			ZEPHIR_CALL_STATIC(&_4$$5, "substr", &_5, 0, charBox, &_13$$5, &_14$$5);
			zephir_check_call_status();
			zephir_concat_self(&result, &_4$$5 TSRMLS_CC);
		}
	}
	ZEPHIR_INIT_NVAR(charBox);
	ZVAL_NULL(charBox);
	RETURN_CCTOR(&result);

}

/**
 * 随机字符串.
 *
 * @param int    $length
 * @param string $charBox
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, randStr) {

	zend_bool _0;
	zval *length_param = NULL, *charBox, charBox_sub, _1, _2, _3;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&charBox_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &length_param, &charBox);

	length = zephir_get_intval(length_param);


	_0 = !length;
	if (!(_0)) {
		_0 = !zephir_is_true(charBox);
	}
	if (_0) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_CALL_FUNCTION(&_1, "str_shuffle", NULL, 152, charBox);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 0);
	ZVAL_LONG(&_3, length);
	zephir_substr(return_value, &_1, 0 , zephir_get_intval(&_3), 0);
	RETURN_MM();

}

/**
 * 字符串编码转换.
 *
 * @param mixed  $contents
 * @param string $fromChar
 * @param string $toChar
 *
 * @return mixed
 */
PHP_METHOD(Leevel_Support_Str, strEncoding) {

	zend_string *_7;
	zend_ulong _6;
	zend_bool _0, _1, _2;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval fromChar, toChar;
	zval *contents, contents_sub, *fromChar_param = NULL, *toChar_param = NULL, key, val, tmp, _3, _4, *_5, _9$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&fromChar);
	ZVAL_UNDEF(&toChar);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &contents, &fromChar_param, &toChar_param);

	ZEPHIR_SEPARATE_PARAM(contents);
	zephir_get_strval(&fromChar, fromChar_param);
	if (!toChar_param) {
		ZEPHIR_INIT_VAR(&toChar);
		ZVAL_STRING(&toChar, "utf-8");
	} else {
		zephir_get_strval(&toChar, toChar_param);
	}


	_0 = ZEPHIR_IS_EMPTY(contents);
	if (!(_0)) {
		_1 = !((Z_TYPE_P(contents) == IS_ARRAY));
		if (_1) {
			_1 = !((Z_TYPE_P(contents) == IS_STRING));
		}
		_0 = _1;
	}
	_2 = _0;
	if (!(_2)) {
		ZEPHIR_INIT_VAR(&_3);
		zephir_fast_strtolower(&_3, &fromChar);
		ZEPHIR_INIT_VAR(&_4);
		zephir_fast_strtolower(&_4, &toChar);
		_2 = ZEPHIR_IS_IDENTICAL(&_3, &_4);
	}
	if (_2) {
		RETVAL_ZVAL(contents, 1, 0);
		RETURN_MM();
	}
	if (Z_TYPE_P(contents) == IS_STRING) {
		ZEPHIR_RETURN_CALL_FUNCTION("mb_convert_encoding", NULL, 153, contents, &toChar, &fromChar);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_is_iterable(contents, 1, "leevel/support/str.zep", 313);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(contents), _6, _7, _5)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_7 != NULL) { 
			ZVAL_STR_COPY(&key, _7);
		} else {
			ZVAL_LONG(&key, _6);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _5);
		ZEPHIR_CALL_STATIC(&tmp, "strencoding", &_8, 0, &key, &fromChar, &toChar);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_9$$5, "strencoding", &_8, 0, &val, &fromChar, &toChar);
		zephir_check_call_status();
		zephir_array_update_zval(contents, &tmp, &_9$$5, PH_COPY | PH_SEPARATE);
		if (!ZEPHIR_IS_IDENTICAL(&key, &tmp)) {
			zephir_array_unset(contents, &tmp, PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETVAL_ZVAL(contents, 1, 0);
	RETURN_MM();

}

/**
 * 字符串截取.
 *
 * @param string $strings
 * @param int    $start
 * @param int    $length
 * @param string $charset
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, substr) {

	zend_long start, length, ZEPHIR_LAST_CALL_STATUS;
	zval *strings_param = NULL, *start_param = NULL, *length_param = NULL, *charset_param = NULL, _0, _1;
	zval strings, charset;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strings);
	ZVAL_UNDEF(&charset);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &strings_param, &start_param, &length_param, &charset_param);

	zephir_get_strval(&strings, strings_param);
	if (!start_param) {
		start = 0;
	} else {
		start = zephir_get_intval(start_param);
	}
	if (!length_param) {
		length = 255;
	} else {
		length = zephir_get_intval(length_param);
	}
	if (!charset_param) {
		ZEPHIR_INIT_VAR(&charset);
		ZVAL_STRING(&charset, "utf-8");
	} else {
		zephir_get_strval(&charset, charset_param);
	}


	ZVAL_LONG(&_0, start);
	ZVAL_LONG(&_1, length);
	ZEPHIR_RETURN_CALL_FUNCTION("mb_substr", NULL, 154, &strings, &_0, &_1, &charset);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 日期格式化.
 *
 * @param int    $dateTemp
 * @param array  $lang
 * @param string $dateFormat
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, formatDate) {

	zephir_fcall_cache_entry *_2 = NULL;
	zval dateFormat;
	zval lang;
	zval *dateTemp_param = NULL, *lang_param = NULL, *dateFormat_param = NULL, sec, hover, min, _0, _3, _4, _10, _1$$3, _5$$4, _6$$4, _8$$4, _7$$5, _9$$6;
	zend_long dateTemp, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sec);
	ZVAL_UNDEF(&hover);
	ZVAL_UNDEF(&min);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&lang);
	ZVAL_UNDEF(&dateFormat);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &dateTemp_param, &lang_param, &dateFormat_param);

	dateTemp = zephir_get_intval(dateTemp_param);
	if (!lang_param) {
		ZEPHIR_INIT_VAR(&lang);
		array_init(&lang);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&lang, lang_param);
	}
	if (!dateFormat_param) {
		ZEPHIR_INIT_VAR(&dateFormat);
		ZVAL_STRING(&dateFormat, "Y-m-d H:i");
	} else {
		zephir_get_strval(&dateFormat, dateFormat_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_time(&_0);
	ZEPHIR_INIT_VAR(&sec);
	ZVAL_LONG(&sec, (zephir_get_numberval(&_0) - dateTemp));
	if (ZEPHIR_LT_LONG(&sec, 0)) {
		ZVAL_LONG(&_1$$3, dateTemp);
		ZEPHIR_RETURN_CALL_FUNCTION("date", &_2, 80, &dateFormat, &_1$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZVAL_DOUBLE(&_3, zephir_safe_div_zval_long(&sec, 3600 TSRMLS_CC));
	ZVAL_DOUBLE(&_4, zephir_floor(&_3 TSRMLS_CC));
	ZEPHIR_INIT_VAR(&hover);
	ZVAL_LONG(&hover, zephir_get_intval(&_4));
	if (ZEPHIR_IS_LONG_IDENTICAL(&hover, 0)) {
		ZVAL_DOUBLE(&_5$$4, zephir_safe_div_zval_long(&sec, 60 TSRMLS_CC));
		ZVAL_DOUBLE(&_6$$4, zephir_floor(&_5$$4 TSRMLS_CC));
		ZEPHIR_INIT_VAR(&min);
		ZVAL_LONG(&min, zephir_get_intval(&_6$$4));
		if (ZEPHIR_IS_LONG_IDENTICAL(&min, 0)) {
			ZEPHIR_INIT_VAR(&_7$$5);
			if (zephir_array_isset_string(&lang, SL("seconds"))) {
				ZEPHIR_OBS_NVAR(&_7$$5);
				zephir_array_fetch_string(&_7$$5, &lang, SL("seconds"), PH_NOISY, "leevel/support/str.zep", 356 TSRMLS_CC);
			} else {
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_STRING(&_7$$5, "seconds ago");
			}
			ZEPHIR_CONCAT_VSV(return_value, &sec, " ", &_7$$5);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&_8$$4);
		if (zephir_array_isset_string(&lang, SL("minutes"))) {
			ZEPHIR_OBS_NVAR(&_8$$4);
			zephir_array_fetch_string(&_8$$4, &lang, SL("minutes"), PH_NOISY, "leevel/support/str.zep", 359 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_8$$4);
			ZVAL_STRING(&_8$$4, "minutes ago");
		}
		ZEPHIR_CONCAT_VSV(return_value, &min, " ", &_8$$4);
		RETURN_MM();
	} else if (ZEPHIR_LT_LONG(&hover, 24)) {
		ZEPHIR_INIT_VAR(&_9$$6);
		if (zephir_array_isset_string(&lang, SL("hours"))) {
			ZEPHIR_OBS_NVAR(&_9$$6);
			zephir_array_fetch_string(&_9$$6, &lang, SL("hours"), PH_NOISY, "leevel/support/str.zep", 361 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_NVAR(&_9$$6);
			ZVAL_STRING(&_9$$6, "hours ago");
		}
		ZEPHIR_CONCAT_VSV(return_value, &hover, " ", &_9$$6);
		RETURN_MM();
	}
	ZVAL_LONG(&_10, dateTemp);
	ZEPHIR_RETURN_CALL_FUNCTION("date", &_2, 80, &dateFormat, &_10);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 文件大小格式化.
 *
 * @param int  $fileSize
 * @param bool $withUnit
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, formatBytes) {

	zend_bool withUnit;
	zval *fileSize_param = NULL, *withUnit_param = NULL, tmp, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$5, _9$$5, _10$$5, _11$$5, _12$$6, _13$$6;
	zend_long fileSize;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &fileSize_param, &withUnit_param);

	fileSize = zephir_get_intval(fileSize_param);
	if (!withUnit_param) {
		withUnit = 1;
	} else {
		withUnit = zephir_get_boolval(withUnit_param);
	}


	if (fileSize >= 1073741824) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_DOUBLE(&_1$$3, zephir_safe_div_long_long(fileSize, 1073741824 TSRMLS_CC));
		ZVAL_LONG(&_2$$3, 2);
		zephir_round(&_0$$3, &_1$$3, &_2$$3, NULL TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$3);
		if (withUnit) {
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "G");
		} else {
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "");
		}
		ZEPHIR_INIT_VAR(&tmp);
		ZEPHIR_CONCAT_VV(&tmp, &_0$$3, &_3$$3);
	} else if (fileSize >= 1048576) {
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_DOUBLE(&_5$$4, zephir_safe_div_long_long(fileSize, 1048576 TSRMLS_CC));
		ZVAL_LONG(&_6$$4, 2);
		zephir_round(&_4$$4, &_5$$4, &_6$$4, NULL TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_7$$4);
		if (withUnit) {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "M");
		} else {
			ZEPHIR_INIT_NVAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "");
		}
		ZEPHIR_INIT_NVAR(&tmp);
		ZEPHIR_CONCAT_VV(&tmp, &_4$$4, &_7$$4);
	} else if (fileSize >= 1024) {
		ZEPHIR_INIT_VAR(&_8$$5);
		ZVAL_DOUBLE(&_9$$5, zephir_safe_div_long_long(fileSize, 1024 TSRMLS_CC));
		ZVAL_LONG(&_10$$5, 2);
		zephir_round(&_8$$5, &_9$$5, &_10$$5, NULL TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_11$$5);
		if (withUnit) {
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZVAL_STRING(&_11$$5, "K");
		} else {
			ZEPHIR_INIT_NVAR(&_11$$5);
			ZVAL_STRING(&_11$$5, "");
		}
		ZEPHIR_INIT_NVAR(&tmp);
		ZEPHIR_CONCAT_VV(&tmp, &_8$$5, &_11$$5);
	} else {
		ZEPHIR_SINIT_VAR(_12$$6);
		ZVAL_LONG(&_12$$6, fileSize);
		ZEPHIR_INIT_VAR(&_13$$6);
		if (withUnit) {
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_STRING(&_13$$6, "B");
		} else {
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_STRING(&_13$$6, "");
		}
		ZEPHIR_INIT_NVAR(&tmp);
		ZEPHIR_CONCAT_VV(&tmp, &_12$$6, &_13$$6);
	}
	RETURN_CCTOR(&tmp);

}

/**
 * 下划线转驼峰.
 *
 * @param string $value
 * @param string $separator
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, camelize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *separator_param = NULL, tmp, _0, _1, _2, _3, _4, _5, _6;
	zval value, separator;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &separator_param);

	zephir_get_strval(&value, value_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_strtolower(&_1, &value);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, " ");
	zephir_fast_str_replace(&_0, &separator, &_2, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&tmp);
	ZEPHIR_CONCAT_VV(&tmp, &separator, &_0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CALL_FUNCTION(&_4, "ucwords", NULL, 23, &tmp);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, " ");
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "");
	zephir_fast_str_replace(&_3, &_5, &_6, &_4 TSRMLS_CC);
	zephir_fast_trim(return_value, &_3, &separator, ZEPHIR_TRIM_LEFT TSRMLS_CC);
	RETURN_MM();

}

/**
 * 驼峰转下划线
 *
 * @param string $value
 * @param string $separator
 *
 * @return string
 */
PHP_METHOD(Leevel_Support_Str, unCamelize) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value_param = NULL, *separator_param = NULL, _1, _2;
	zval value, separator, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&separator);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value_param, &separator_param);

	zephir_get_strval(&value, value_param);
	if (!separator_param) {
		ZEPHIR_INIT_VAR(&separator);
		ZVAL_STRING(&separator, "_");
	} else {
		zephir_get_strval(&separator, separator_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "$1", &separator, "$2");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/([a-z])([A-Z])/");
	ZEPHIR_CALL_FUNCTION(&_2, "preg_replace", NULL, 155, &_1, &_0, &value);
	zephir_check_call_status();
	zephir_fast_strtolower(return_value, &_2);
	RETURN_MM();

}

/**
 * 判断字符串中是否包含给定的字符开始.
 *
 * @param string $toSearched
 * @param string $search
 *
 * @return bool
 */
PHP_METHOD(Leevel_Support_Str, startsWith) {

	zend_bool _0;
	zval *toSearched_param = NULL, *search_param = NULL, _1;
	zval toSearched, search;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&toSearched);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &toSearched_param, &search_param);

	zephir_get_strval(&toSearched, toSearched_param);
	zephir_get_strval(&search, search_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&search, "");
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_fast_strpos(&_1, &toSearched, &search, 0 );
		_0 = ZEPHIR_IS_LONG_IDENTICAL(&_1, 0);
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 判断字符串中是否包含给定的字符结尾.
 *
 * @param string $toSearched
 * @param string $search
 *
 * @return bool
 */
PHP_METHOD(Leevel_Support_Str, endsWith) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *toSearched_param = NULL, *search_param = NULL, _0, _1, _2;
	zval toSearched, search;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&toSearched);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &toSearched_param, &search_param);

	zephir_get_strval(&toSearched, toSearched_param);
	zephir_get_strval(&search, search_param);


	ZEPHIR_CALL_FUNCTION(&_0, "strval", NULL, 11, &search);
	zephir_check_call_status();
	ZVAL_LONG(&_1, -zephir_fast_strlen_ev(&search));
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &toSearched, zephir_get_intval(&_1), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	if (ZEPHIR_IS_IDENTICAL(&_0, &_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 判断字符串中是否包含给定的字符串集合.
 *
 * @param string $toSearched
 * @param string $search
 *
 * @return bool
 */
PHP_METHOD(Leevel_Support_Str, contains) {

	zend_bool _0;
	zval *toSearched_param = NULL, *search_param = NULL, _1;
	zval toSearched, search;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&toSearched);
	ZVAL_UNDEF(&search);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &toSearched_param, &search_param);

	zephir_get_strval(&toSearched, toSearched_param);
	zephir_get_strval(&search, search_param);


	_0 = !ZEPHIR_IS_STRING_IDENTICAL(&search, "");
	if (_0) {
		ZEPHIR_INIT_VAR(&_1);
		zephir_fast_strpos(&_1, &toSearched, &search, 0 );
		_0 = !ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	}
	if (_0) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 注册一个扩展
 *
 * @param string $name
 * @param callable $macro
 * @return void
 */
PHP_METHOD(Leevel_Support_Str, macro) {

	zval *name_param = NULL, *macro, macro_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&macro_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &macro);

	zephir_get_strval(&name, name_param);


	zephir_update_static_property_array_multi_ce(leevel_support_str_ce, SL("macro"), macro TSRMLS_CC, SL("z"), 1, &name);
	ZEPHIR_MM_RESTORE();

}

/**
 * 判断一个扩展是否注册
 *
 * @param string $name
 * @return bool
 */
PHP_METHOD(Leevel_Support_Str, hasMacro) {

	zval *name_param = NULL, _0;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_static_property_ce(&_0, leevel_support_str_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

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
PHP_METHOD(Leevel_Support_Str, callStaticMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _3, _4, _5, _1$$3, _2$$3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, leevel_support_str_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY | PH_READONLY, "leevel/support/str.zep", 517 TSRMLS_CC);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 1, &_4, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 2, &_5);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_3, "leevel/support/str.zep", 520 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

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
PHP_METHOD(Leevel_Support_Str, callMacro) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *method_param = NULL, *args_param = NULL, _0, _8, _9, _10, _1$$3, _2$$3, _3$$4, _4$$4, _5$$4, _6$$5, _7$$5;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_CALL_SELF(&_0, "hasmacro", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_static_property_ce(&_1$$3, leevel_support_str_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_array_fetch(&_2$$3, &_1$$3, &method, PH_NOISY, "leevel/support/str.zep", 536 TSRMLS_CC);
		if (zephir_instance_of_ev(&_2$$3, zend_ce_closure TSRMLS_CC)) {
			zephir_read_static_property_ce(&_3$$4, leevel_support_str_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_4$$4, &_3$$4, &method, PH_NOISY | PH_READONLY, "leevel/support/str.zep", 537 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_5$$4, &_4$$4, "bindto", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_5$$4, &args);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			zephir_read_static_property_ce(&_6$$5, leevel_support_str_ce, SL("macro"), PH_NOISY_CC | PH_READONLY);
			zephir_array_fetch(&_7$$5, &_6$$5, &method, PH_NOISY | PH_READONLY, "leevel/support/str.zep", 539 TSRMLS_CC);
			ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_7$$5, &args);
			zephir_check_call_status();
			RETURN_MM();
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	object_init_ex(&_8, spl_ce_BadMethodCallException);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "Method %s is not exits.");
	ZEPHIR_CALL_FUNCTION(&_10, "sprintf", NULL, 1, &_9, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 2, &_10);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_8, "leevel/support/str.zep", 543 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

void zephir_init_static_properties_Leevel_Support_Str(TSRMLS_D) {

	zval _0;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zend_update_static_property(leevel_support_str_ce, ZEND_STRL("macro"), &_0);
	ZEPHIR_MM_RESTORE();

}

