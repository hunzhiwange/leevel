
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <php.h>
#include "php_ext.h"
#include <ext/standard/php_string.h>
#include "ext.h"
#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/concat.h"

void zephir_concat_ss(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	uint offset = 0, length;

	length = op1_len + op2_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssssssssssssssssssssssssssssssss(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, const char *op4, zend_uint op4_len, const char *op5, zend_uint op5_len, const char *op6, zend_uint op6_len, const char *op7, zend_uint op7_len, const char *op8, zend_uint op8_len, const char *op9, zend_uint op9_len, const char *op10, zend_uint op10_len, const char *op11, zend_uint op11_len, const char *op12, zend_uint op12_len, const char *op13, zend_uint op13_len, const char *op14, zend_uint op14_len, const char *op15, zend_uint op15_len, const char *op16, zend_uint op16_len, const char *op17, zend_uint op17_len, const char *op18, zend_uint op18_len, const char *op19, zend_uint op19_len, const char *op20, zend_uint op20_len, const char *op21, zend_uint op21_len, const char *op22, zend_uint op22_len, const char *op23, zend_uint op23_len, const char *op24, zend_uint op24_len, const char *op25, zend_uint op25_len, const char *op26, zend_uint op26_len, const char *op27, zend_uint op27_len, const char *op28, zend_uint op28_len, const char *op29, zend_uint op29_len, const char *op30, zend_uint op30_len, const char *op31, zend_uint op31_len, const char *op32, zend_uint op32_len, int self_var){

	zval result_copy;
	int use_copy = 0;
	uint offset = 0, length;

	length = op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len + op32_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len, op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len, op5, op5_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len, op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len, op7, op7_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len, op8, op8_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len, op9, op9_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len, op10, op10_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len, op11, op11_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len, op12, op12_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len, op13, op13_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len, op14, op14_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len, op15, op15_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len, op16, op16_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len, op17, op17_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len, op18, op18_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len, op19, op19_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len, op20, op20_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len, op21, op21_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len, op22, op22_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len, op23, op23_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len, op24, op24_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len, op25, op25_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len, op26, op26_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len, op27, op27_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len, op28, op28_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len, op29, op29_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len, op30, op30_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len, op31, op31_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + op3_len + op4_len + op5_len + op6_len + op7_len + op8_len + op9_len + op10_len + op11_len + op12_len + op13_len + op14_len + op15_len + op16_len + op17_len + op18_len + op19_len + op20_len + op21_len + op22_len + op23_len + op24_len + op25_len + op26_len + op27_len + op28_len + op29_len + op30_len + op31_len, op32, op32_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_ssvs(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var){

	zval result_copy, op3_copy;
	int use_copy = 0, use_copy3 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = op1_len + op2_len + Z_STRLEN_P(op3) + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_sv(zval *result, const char *op1, zend_uint op1_len, zval *op2, int self_var){

	zval result_copy, op2_copy;
	int use_copy = 0, use_copy2 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svs(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, int self_var){

	zval result_copy, op2_copy;
	int use_copy = 0, use_copy2 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svsvs(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var){

	zval result_copy, op2_copy, op4_copy;
	int use_copy = 0, use_copy2 = 0, use_copy4 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4) + op5_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svv(zval *result, const char *op1, zend_uint op1_len, zval *op2, zval *op3, int self_var){

	zval result_copy, op2_copy, op3_copy;
	int use_copy = 0, use_copy2 = 0, use_copy3 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_svvv(zval *result, const char *op1, zend_uint op1_len, zval *op2, zval *op3, zval *op4, int self_var){

	zval result_copy, op2_copy, op3_copy, op4_copy;
	int use_copy = 0, use_copy2 = 0, use_copy3 = 0, use_copy4 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, op1, op1_len);
	memcpy(Z_STRVAL_P(result) + offset + op1_len, Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + op1_len + Z_STRLEN_P(op2) + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vs(zval *result, zval *op1, const char *op2, zend_uint op2_len, int self_var){

	zval result_copy, op1_copy;
	int use_copy = 0, use_copy1 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vss(zval *result, zval *op1, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, int self_var){

	zval result_copy, op1_copy;
	int use_copy = 0, use_copy1 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + op3_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, op3, op3_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vssvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var){

	zval result_copy, op1_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy4 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + op3_len + Z_STRLEN_P(op4) + op5_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, op3, op3_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + op3_len, Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + op3_len + Z_STRLEN_P(op4), op5, op5_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, int self_var){

	zval result_copy, op1_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var){

	zval result_copy, op1_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, zval *op7, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy7 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, zval *op7, const char *op8, zend_uint op8_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy, op7_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy7 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op7) != IS_STRING) {
	   use_copy7 = zend_make_printable_zval(op7, &op7_copy);
	   if (use_copy7) {
	       op7 = &op7_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7) + op8_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), op6, op6_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len, Z_STRVAL_P(op7), Z_STRLEN_P(op7));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + op6_len + Z_STRLEN_P(op7), op8, op8_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy7) {
	   zval_dtor(op7);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvsvvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, zval *op6, const char *op7, zend_uint op7_len, int self_var){

	zval result_copy, op1_copy, op3_copy, op5_copy, op6_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy5 = 0, use_copy6 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op5) != IS_STRING) {
	   use_copy5 = zend_make_printable_zval(op5, &op5_copy);
	   if (use_copy5) {
	       op5 = &op5_copy;
	   }
	}

	if (Z_TYPE_P(op6) != IS_STRING) {
	   use_copy6 = zend_make_printable_zval(op6, &op6_copy);
	   if (use_copy6) {
	       op6 = &op6_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + Z_STRLEN_P(op6) + op7_len;
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), op4, op4_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len, Z_STRVAL_P(op5), Z_STRLEN_P(op5));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5), Z_STRVAL_P(op6), Z_STRLEN_P(op6));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + op4_len + Z_STRLEN_P(op5) + Z_STRLEN_P(op6), op7, op7_len);
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy5) {
	   zval_dtor(op5);
	}

	if (use_copy6) {
	   zval_dtor(op6);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vsvv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, zval *op4, int self_var){

	zval result_copy, op1_copy, op3_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy3 = 0, use_copy4 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3) + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), op2, op2_len);
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len, Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + op2_len + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var){

	zval result_copy, op1_copy, op2_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var){

	zval result_copy, op1_copy, op2_copy, op3_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy3 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_vvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var){

	zval result_copy, op1_copy, op2_copy, op3_copy, op4_copy;
	int use_copy = 0, use_copy1 = 0, use_copy2 = 0, use_copy3 = 0, use_copy4 = 0;
	uint offset = 0, length;

	if (Z_TYPE_P(op1) != IS_STRING) {
	   use_copy1 = zend_make_printable_zval(op1, &op1_copy);
	   if (use_copy1) {
	       op1 = &op1_copy;
	   }
	}

	if (Z_TYPE_P(op2) != IS_STRING) {
	   use_copy2 = zend_make_printable_zval(op2, &op2_copy);
	   if (use_copy2) {
	       op2 = &op2_copy;
	   }
	}

	if (Z_TYPE_P(op3) != IS_STRING) {
	   use_copy3 = zend_make_printable_zval(op3, &op3_copy);
	   if (use_copy3) {
	       op3 = &op3_copy;
	   }
	}

	if (Z_TYPE_P(op4) != IS_STRING) {
	   use_copy4 = zend_make_printable_zval(op4, &op4_copy);
	   if (use_copy4) {
	       op4 = &op4_copy;
	   }
	}

	length = Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3) + Z_STRLEN_P(op4);
	if (self_var) {

		if (Z_TYPE_P(result) != IS_STRING) {
			use_copy = zend_make_printable_zval(result, &result_copy);
			if (use_copy) {
				ZEPHIR_CPY_WRT_CTOR(result, (&result_copy));
			}
		}

		offset = Z_STRLEN_P(result);
		length += offset;
		Z_STR_P(result) = zend_string_realloc(Z_STR_P(result), length, 0);

	} else {
		ZVAL_STR(result, zend_string_alloc(length, 0));
	}

	memcpy(Z_STRVAL_P(result) + offset, Z_STRVAL_P(op1), Z_STRLEN_P(op1));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1), Z_STRVAL_P(op2), Z_STRLEN_P(op2));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2), Z_STRVAL_P(op3), Z_STRLEN_P(op3));
	memcpy(Z_STRVAL_P(result) + offset + Z_STRLEN_P(op1) + Z_STRLEN_P(op2) + Z_STRLEN_P(op3), Z_STRVAL_P(op4), Z_STRLEN_P(op4));
	Z_STRVAL_P(result)[length] = 0;
	zend_string_forget_hash_val(Z_STR_P(result));
	if (use_copy1) {
	   zval_dtor(op1);
	}

	if (use_copy2) {
	   zval_dtor(op2);
	}

	if (use_copy3) {
	   zval_dtor(op3);
	}

	if (use_copy4) {
	   zval_dtor(op4);
	}

	if (use_copy) {
	   zval_dtor(&result_copy);
	}

}

void zephir_concat_function(zval *result, zval *op1, zval *op2)
{
	zval tmp;
	SEPARATE_ZVAL_IF_NOT_REF(result);

	/*
		res == op1 == op2: won't leak
		res == op1 != op2: won't leak
		res == op2 != op1: will leak
	 */
	if (result == op2 && result != op1) {
		ZVAL_COPY_VALUE(&tmp, result);
		ZVAL_NULL(result);
		op2 = &tmp;
	}
	else {
		ZVAL_UNDEF(&tmp);
	}

	concat_function(result, op1, op2);
	assert(!Z_REFCOUNTED(tmp) || 1 == Z_REFCOUNT(tmp));
	zval_dtor(&tmp);
}