
#ifndef ZEPHIR_KERNEL_CONCAT_H
#define ZEPHIR_KERNEL_CONCAT_H
#include <php.h>
#include <Zend/zend.h>
#include "kernel/main.h"
#define ZEPHIR_CONCAT_SS(result, op1, op2) \
	 zephir_concat_ss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_SS(result, op1, op2) \
	 zephir_concat_ss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13, op14, op15, op16, op17, op18, op19, op20, op21, op22, op23, op24, op25, op26, op27, op28, op29, op30, op31, op32) \
	 zephir_concat_ssssssssssssssssssssssssssssssss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, sizeof(op7)-1, op8, sizeof(op8)-1, op9, sizeof(op9)-1, op10, sizeof(op10)-1, op11, sizeof(op11)-1, op12, sizeof(op12)-1, op13, sizeof(op13)-1, op14, sizeof(op14)-1, op15, sizeof(op15)-1, op16, sizeof(op16)-1, op17, sizeof(op17)-1, op18, sizeof(op18)-1, op19, sizeof(op19)-1, op20, sizeof(op20)-1, op21, sizeof(op21)-1, op22, sizeof(op22)-1, op23, sizeof(op23)-1, op24, sizeof(op24)-1, op25, sizeof(op25)-1, op26, sizeof(op26)-1, op27, sizeof(op27)-1, op28, sizeof(op28)-1, op29, sizeof(op29)-1, op30, sizeof(op30)-1, op31, sizeof(op31)-1, op32, sizeof(op32)-1, 0);
#define ZEPHIR_SCONCAT_SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS(result, op1, op2, op3, op4, op5, op6, op7, op8, op9, op10, op11, op12, op13, op14, op15, op16, op17, op18, op19, op20, op21, op22, op23, op24, op25, op26, op27, op28, op29, op30, op31, op32) \
	 zephir_concat_ssssssssssssssssssssssssssssssss(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, sizeof(op4)-1, op5, sizeof(op5)-1, op6, sizeof(op6)-1, op7, sizeof(op7)-1, op8, sizeof(op8)-1, op9, sizeof(op9)-1, op10, sizeof(op10)-1, op11, sizeof(op11)-1, op12, sizeof(op12)-1, op13, sizeof(op13)-1, op14, sizeof(op14)-1, op15, sizeof(op15)-1, op16, sizeof(op16)-1, op17, sizeof(op17)-1, op18, sizeof(op18)-1, op19, sizeof(op19)-1, op20, sizeof(op20)-1, op21, sizeof(op21)-1, op22, sizeof(op22)-1, op23, sizeof(op23)-1, op24, sizeof(op24)-1, op25, sizeof(op25)-1, op26, sizeof(op26)-1, op27, sizeof(op27)-1, op28, sizeof(op28)-1, op29, sizeof(op29)-1, op30, sizeof(op30)-1, op31, sizeof(op31)-1, op32, sizeof(op32)-1, 1);

#define ZEPHIR_CONCAT_SSVS(result, op1, op2, op3, op4) \
	 zephir_concat_ssvs(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_SSVS(result, op1, op2, op3, op4) \
	 zephir_concat_ssvs(result, op1, sizeof(op1)-1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 0);
#define ZEPHIR_SCONCAT_SV(result, op1, op2) \
	 zephir_concat_sv(result, op1, sizeof(op1)-1, op2, 1);

#define ZEPHIR_CONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_SVS(result, op1, op2, op3) \
	 zephir_concat_svs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_SVSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_svsvs(result, op1, sizeof(op1)-1, op2, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 0);
#define ZEPHIR_SCONCAT_SVV(result, op1, op2, op3) \
	 zephir_concat_svv(result, op1, sizeof(op1)-1, op2, op3, 1);

#define ZEPHIR_CONCAT_SVVV(result, op1, op2, op3, op4) \
	 zephir_concat_svvv(result, op1, sizeof(op1)-1, op2, op3, op4, 0);
#define ZEPHIR_SCONCAT_SVVV(result, op1, op2, op3, op4) \
	 zephir_concat_svvv(result, op1, sizeof(op1)-1, op2, op3, op4, 1);

#define ZEPHIR_CONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 0);
#define ZEPHIR_SCONCAT_VS(result, op1, op2) \
	 zephir_concat_vs(result, op1, op2, sizeof(op2)-1, 1);

#define ZEPHIR_CONCAT_VSS(result, op1, op2, op3) \
	 zephir_concat_vss(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 0);
#define ZEPHIR_SCONCAT_VSS(result, op1, op2, op3) \
	 zephir_concat_vss(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, 1);

#define ZEPHIR_CONCAT_VSSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vssvs(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 0);
#define ZEPHIR_SCONCAT_VSSVS(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vssvs(result, op1, op2, sizeof(op2)-1, op3, sizeof(op3)-1, op4, op5, sizeof(op5)-1, 1);

#define ZEPHIR_CONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 0);
#define ZEPHIR_SCONCAT_VSV(result, op1, op2, op3) \
	 zephir_concat_vsv(result, op1, op2, sizeof(op2)-1, op3, 1);

#define ZEPHIR_CONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 0);
#define ZEPHIR_SCONCAT_VSVS(result, op1, op2, op3, op4) \
	 zephir_concat_vsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, 1);

#define ZEPHIR_CONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 0);
#define ZEPHIR_SCONCAT_VSVSV(result, op1, op2, op3, op4, op5) \
	 zephir_concat_vsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, 1);

#define ZEPHIR_CONCAT_VSVSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 0);
#define ZEPHIR_SCONCAT_VSVSVS(result, op1, op2, op3, op4, op5, op6) \
	 zephir_concat_vsvsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, 1);

#define ZEPHIR_CONCAT_VSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 0);
#define ZEPHIR_SCONCAT_VSVSVSV(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvsv(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, 1);

#define ZEPHIR_CONCAT_VSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_vsvsvsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 0);
#define ZEPHIR_SCONCAT_VSVSVSVS(result, op1, op2, op3, op4, op5, op6, op7, op8) \
	 zephir_concat_vsvsvsvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, sizeof(op6)-1, op7, op8, sizeof(op8)-1, 1);

#define ZEPHIR_CONCAT_VSVSVVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, op7, sizeof(op7)-1, 0);
#define ZEPHIR_SCONCAT_VSVSVVS(result, op1, op2, op3, op4, op5, op6, op7) \
	 zephir_concat_vsvsvvs(result, op1, op2, sizeof(op2)-1, op3, op4, sizeof(op4)-1, op5, op6, op7, sizeof(op7)-1, 1);

#define ZEPHIR_CONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(result, op1, op2, sizeof(op2)-1, op3, op4, 0);
#define ZEPHIR_SCONCAT_VSVV(result, op1, op2, op3, op4) \
	 zephir_concat_vsvv(result, op1, op2, sizeof(op2)-1, op3, op4, 1);

#define ZEPHIR_CONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 0);
#define ZEPHIR_SCONCAT_VV(result, op1, op2) \
	 zephir_concat_vv(result, op1, op2, 1);

#define ZEPHIR_CONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 0);
#define ZEPHIR_SCONCAT_VVV(result, op1, op2, op3) \
	 zephir_concat_vvv(result, op1, op2, op3, 1);

#define ZEPHIR_CONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 0);
#define ZEPHIR_SCONCAT_VVVV(result, op1, op2, op3, op4) \
	 zephir_concat_vvvv(result, op1, op2, op3, op4, 1);


void zephir_concat_ss(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, int self_var);
void zephir_concat_ssssssssssssssssssssssssssssssss(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, const char *op4, zend_uint op4_len, const char *op5, zend_uint op5_len, const char *op6, zend_uint op6_len, const char *op7, zend_uint op7_len, const char *op8, zend_uint op8_len, const char *op9, zend_uint op9_len, const char *op10, zend_uint op10_len, const char *op11, zend_uint op11_len, const char *op12, zend_uint op12_len, const char *op13, zend_uint op13_len, const char *op14, zend_uint op14_len, const char *op15, zend_uint op15_len, const char *op16, zend_uint op16_len, const char *op17, zend_uint op17_len, const char *op18, zend_uint op18_len, const char *op19, zend_uint op19_len, const char *op20, zend_uint op20_len, const char *op21, zend_uint op21_len, const char *op22, zend_uint op22_len, const char *op23, zend_uint op23_len, const char *op24, zend_uint op24_len, const char *op25, zend_uint op25_len, const char *op26, zend_uint op26_len, const char *op27, zend_uint op27_len, const char *op28, zend_uint op28_len, const char *op29, zend_uint op29_len, const char *op30, zend_uint op30_len, const char *op31, zend_uint op31_len, const char *op32, zend_uint op32_len, int self_var);
void zephir_concat_ssvs(zval *result, const char *op1, zend_uint op1_len, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var);
void zephir_concat_sv(zval *result, const char *op1, zend_uint op1_len, zval *op2, int self_var);
void zephir_concat_svs(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, int self_var);
void zephir_concat_svsvs(zval *result, const char *op1, zend_uint op1_len, zval *op2, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var);
void zephir_concat_svv(zval *result, const char *op1, zend_uint op1_len, zval *op2, zval *op3, int self_var);
void zephir_concat_svvv(zval *result, const char *op1, zend_uint op1_len, zval *op2, zval *op3, zval *op4, int self_var);
void zephir_concat_vs(zval *result, zval *op1, const char *op2, zend_uint op2_len, int self_var);
void zephir_concat_vss(zval *result, zval *op1, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, int self_var);
void zephir_concat_vssvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, const char *op3, zend_uint op3_len, zval *op4, const char *op5, zend_uint op5_len, int self_var);
void zephir_concat_vsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, int self_var);
void zephir_concat_vsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, int self_var);
void zephir_concat_vsvsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, int self_var);
void zephir_concat_vsvsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, int self_var);
void zephir_concat_vsvsvsv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, zval *op7, int self_var);
void zephir_concat_vsvsvsvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, const char *op6, zend_uint op6_len, zval *op7, const char *op8, zend_uint op8_len, int self_var);
void zephir_concat_vsvsvvs(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, const char *op4, zend_uint op4_len, zval *op5, zval *op6, const char *op7, zend_uint op7_len, int self_var);
void zephir_concat_vsvv(zval *result, zval *op1, const char *op2, zend_uint op2_len, zval *op3, zval *op4, int self_var);
void zephir_concat_vv(zval *result, zval *op1, zval *op2, int self_var);
void zephir_concat_vvv(zval *result, zval *op1, zval *op2, zval *op3, int self_var);
void zephir_concat_vvvv(zval *result, zval *op1, zval *op2, zval *op3, zval *op4, int self_var);
void zephir_concat_function(zval *result, zval *op1, zval *op2);
#endif /* ZEPHIR_KERNEL_CONCAT_H */
