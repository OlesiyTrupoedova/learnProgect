#include "../import/s21_math.h"
#include <math.h>
#include <stdlib.h>

/*--------EXP-TEST-START------------------------------------------*/

#test exp_test_1
    double a = 4;
    long double res1 = exp(a);
    long double res2 = s21_exp(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test exp_test_2
    double a = -4;
    long double res1 = exp(a);
    long double res2 = s21_exp(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test exp_test_3
    double a = +0;
    long double res1 = exp(a);
    long double res2 = s21_exp(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test exp_test_4
    double a = -0;
    long double res1 = exp(a);
    long double res2 = s21_exp(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test exp_test_5
    double a = 123456789;
    long double res2 = s21_exp(a);
    ck_assert_ldouble_infinite(res2);

#test exp_test_6
    double a = 1024;
    long double res2 = s21_exp(a);
    ck_assert_ldouble_infinite(res2);

#test exp_test_7
    double a = -1024;
    long double res1 = exp(a);
    long double res2 = s21_exp(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test exp_test_8
    long double res2 = s21_exp(S21_NAN);
    ck_assert_ldouble_nan(res2);


/*--------EXP-TEST-END------------------------------------------*/


/*--------ACOS-TEST-START---------------------------------------*/
#test acos_test_1
    double a = 4;
    long double res2 = s21_acos(a);
    ck_assert_ldouble_nan(res2);

#test acos_test_2
    double a = -4;
    long double res2 = s21_acos(a);
    ck_assert_ldouble_nan(res2);

#test acos_test_3
    double a = +0;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_4
    double a = -0;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_5
    double a = 123456789;
    long double res2 = s21_acos(a);
    ck_assert_ldouble_nan(res2);

#test acos_test_6
    double a = 111;
    long double res2 = s21_acos(a);
    ck_assert_ldouble_nan(res2);

#test acos_test_7
    double a = -0.4;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_8
    double a = 0.1;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_9
    double a = 0.1473433;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_10
    double a = -0.5473433;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_11
    double a = -0.5473433;
    long double res1 = acos(a);
    long double res2 = s21_acos(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test acos_test_12
    double a = -884848584.5473433;
    long double res2 = s21_acos(a);
    ck_assert_ldouble_nan( res2);

#test acos_test_13
    long double res2 = s21_acos(S21_NAN);
    ck_assert_ldouble_nan( res2);

#test acos_test_14
    long double res2 = s21_acos(S21_POS_INF);
    ck_assert_ldouble_infinite(res2);
/*--------ACOS-TEST-END-----------------------------------------*/


/*--------POW-TEST-START---------------------------------------*/
#test pow_test_1
    double a = 4.12;
    long double res1 = pow(a, 3.1254);
    long double res2 = s21_pow(a, 3.1254);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);


#test pow_test_2
    double a = -4;
    long double res1 = pow(a, 16);
    long double res2 = s21_pow(a, 16);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);


#test pow_test_3
    double a = +0;
    long double res1 = pow(a, 3);
    long double res2 = s21_pow(a, 3);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);


#test pow_test_4
    double a = -84.24;
    long double res2 = s21_pow(a, 8.954);
    ck_assert_ldouble_nan(res2);

#test pow_test_5
    double a = 84.24;
    long double res1 = pow(a, 9);
    long double res2 = s21_pow(a, 9);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);

#test pow_test_6
    long double res1 = s21_pow(S21_NAN, 2);
    ck_assert_ldouble_ne(res1, res1);

#test pow_test_7
    double a = -104.987;
    long double res2 = s21_pow(a, 0.98);
    ck_assert_ldouble_nan(res2);

#test pow_test_8
    long double res2 = s21_pow(0, -0.98);
    ck_assert_ldouble_infinite( res2);

#test pow_test_9
    double a = 84.24;
    long double res1 = pow(a, -2);
    long double res2 = s21_pow(a, -2);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);

#test pow_test_10
    double a = 84.24;
    long double res1 = pow(a, 0);
    long double res2 = s21_pow(a, 0);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);

#test pow_test_11
    double a = 0;
    long double res1 = pow(a, 0);
    long double res2 = s21_pow(a, 0);
    long double res = res2 - res1;
    ck_assert_ldouble_lt(res, 0.000001);

/*--------POW-TEST-END-----------------------------------------*/

/*------------ABS-TEST-START-----------------------------------------*/

#test abs_test_1
    int a = -43434314;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_2
    int a = -4;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_3
    int a = +0;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_4
    int a = -0;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_5
    int a = 123456789;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_6
    int a = -1;
    int res1 =abs(a);
    int res2 =s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_7
    int a = -1024;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

#test abs_test_8
    int a = -9126789;
    int res1 = abs(a);
    int res2 = s21_abs(a);
    ck_assert_int_eq(res1, res2);

/*--------ABS-TEST-END-----------------------------------------*/

/*--------FLOOR-TEST-START-----------------------------------------*/

#test floor_test_1
    long double a = 4.122232134343;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_2
    long double a = -4.345532335343;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_3
    long double a = +0.234343433;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_4
    long double a = -0.243232;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_5
    long double a = 121212.123456789;
    long double res1 = floor(a);
long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_6
    long double a = 453.1024;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_7
    long double a = -1024.12;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

#test floor_test_8
    long double a = -123456789;
    long double res1 = floor(a);
    long double res2 = s21_floor(a);
    ck_assert_ldouble_eq(res1, res2);

/*--------FLOOR-TEST-END-----------------------------------------*/

/*--------FABS-TEST-START-----------------------------------------*/
#test fabs_test_1
    long double a = 4.122232134343;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_2
    long double a = -4.345532335343;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_3
    long double a = +0.234343433;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_4
    long double a = -0.243232;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_5
    long double a = 121212.123456789;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_6
    long double a = -453.1024;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_7
    long double a = -1024.12;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fabs_test_8
    long double a = -123456789;
    long double res1 = fabsl(a);
    long double res2 = s21_fabs(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

/*--------FABS-TEST-END-----------------------------------------*/

/*--------CEIL-TEST-START-----------------------------------------*/

#test ceil_test_1
    long double a = 4.122232134343;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_2
    long double a = -4.345532335343;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_3
    long double a = +0.234343433;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_4
    long double a = -0.243232;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_5
    long double a = -121212.123456789;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_6
    long double a = -453.1024;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_7
    long double a = 1024.12;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_8
    long double a = -123456789.54343;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_9
    long double a = 23456789.123432;
    long double res1 = ceil(a);
    long double res2 = s21_ceil(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test ceil_test_10
    long double res2 = s21_ceil(S21_POS_INF);
    ck_assert_ldouble_infinite(res2);

/*--------CEIL-TEST-END-----------------------------------------*/

/*--------SIN-TEST-START-----------------------------------------*/

#test sin_test_1
    long double a = 4.122232134343;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_2
    long double a = -4.345532335343;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_3
    long double a = +0.234343433;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_4
    long double a = -0.243232;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_5
    long double a = 121212.123456789;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_6
    long double a = -453.1024;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_7
    long double a = 1024.12;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_8
    long double a = -123456789;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_9
    long double a = 0.193247;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_10
    long double a = 0.993247;
    long double res1 = sin(a);
    long double res2 = s21_sin(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test sin_test_11
    long double res2 = s21_sin(S21_NAN);
    ck_assert_ldouble_nan( res2);


/*--------SIN-TEST-END-----------------------------------------*/

/*--------COS-TEST-START-----------------------------------------*/

#test cos_test_1
    long double a = 4.122232134343;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_2
    long double a = -4.345532335343;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_3
    long double a = +0.234343433;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_4
    long double a = -0.243232;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_5
    long double a = 121212.123456789;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_6
    long double a = -453.1024;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_7
    long double a = 1024.9493912;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_8
    long double a = -123456;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_9
    long double a = -9459456789.1;
    long double res1 = cos(a);
    long double res2 = s21_cos(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test cos_test_10
    long double a = S21_POS_INF;
    long double res2 = s21_cos(a);
    ck_assert_ldouble_nan( res2);

#test cos_test_11
    long double a = S21_NEG_INF;
    long double res2 = s21_cos(a);
    ck_assert_ldouble_nan( res2);

#test cos_test_12
    long double a = S21_NAN;
    long double res2 = s21_cos(a);
    ck_assert_ldouble_nan( res2);

/*--------FMOD-TEST-END-----------------------------------------*/

#test fmod_test_1
    long double a = 4.122232134343;
    long double y = 2.12;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_2
    long double a = -4.345532335343;
    long double y = 65353;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq(res1, res2);

#test fmod_test_3
    long double a = +0.234343433;
    long double y = 9.99;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_4
    long double a = -0.243232;
    long double y = 0.485987479;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_5
    long double a = 121212.123456789;
    long double y = 212;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_6
    long double a = -453.1024;
    long double y = S21_PI;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_7
    long double a = 1024.12;
    long double y = 3.146546;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_8
    long double a = -123456789;
    long double y = 5.99992;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test fmod_test_9
    long double a = -123456789;
    long double res2 = s21_fmod(a, S21_NEG_INF);
    ck_assert_ldouble_nan(res2);

#test fmod_test_10
    long double a = -123456789;
    long double res2 = s21_fmod(S21_NAN, a);
    ck_assert_ldouble_nan(res2);

#test fmod_test_11
    long double a = 6343789;
    long double y = -5.99992;
    long double res1 = fmod(a, y);
    long double res2 = s21_fmod(a, y);
    ck_assert_ldouble_eq_tol(res1, res2,6);
       
/*--------FMOD-TEST-END-----------------------------------------*/


/*--------ATAN-TEST-START-----------------------------------------*/

#test atan_test_1
    long double a = 4.122232134343;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_2
    long double a = -4.345532335343;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_3
    long double a = +0.234343433;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_4
    long double a = -0.243232;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_5
    long double a = 121212.123456789;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_6
    long double a = -453.1024;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_7
    long double a = 1024.12;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_8
    long double a = -1234567.34343;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_9
    long double a = 0.999934343;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_10
    long double a = 0.111111111;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_11
    long double a = 1;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_12
    long double a = -1;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_13
    long double a = S21_POS_INF;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_14
    long double a = S21_NEG_INF;
    long double res1 = atan(a);
    long double res2 = s21_atan(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test atan_test_15
    long double a = S21_NAN;
    long double res2 = s21_atan(a);
    ck_assert_ldouble_nan(res2);
/*--------ATAN-TEST-END-----------------------------------------*/

/*--------LOG-TEST-START-----------------------------------------*/

#test log_test_1
    long double a = 4.122232134343;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test log_test_2
    long double a = -4.345532335343;
    long double res2 = s21_log(a);
    ck_assert_ldouble_nan(res2);

#test log_test_3
    long double a = +0.234343433;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test log_test_4
    long double a = -0.243232;
    long double res2 = s21_log(a);
    ck_assert_ldouble_nan( res2);

#test log_test_5
    long double a = 121212.123456789;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test log_test_6
    long double a = -453.1024;
    long double res2 = s21_log(a);
    ck_assert_ldouble_nan( res2);

#test log_test_7
    long double a = 1024.12;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test log_test_8
    long double a = 123456789;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test log_test_9
    long double a = 0.111111111111;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);

#test log_test_10
    long double a = 0.9999999;
    long double res1 = log(a);
    long double res2 = s21_log(a);
    ck_assert_ldouble_eq_tol(res1, res2,6);


#test log_test_11
    long double res2 = s21_log(S21_NAN);
    ck_assert_ldouble_nan(res2);

#test log_test_12
    long double res2 = s21_log(S21_POS_INF);
    ck_assert_ldouble_infinite(res2);

#test log_test_13
    long double a = 0.;
    long double res2 = s21_log(a);
    ck_assert_ldouble_infinite(res2);

/*--------LOG-TEST-END-----------------------------------------*/

/*13--------SQRT-TEST-START--------------------------------------*/

#test sqrt_test_1
    long double a = 0.0;
    long double res1 = sqrt(a);
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test sqrt_test_2
    long double a = 1.0;
    long double res1 = sqrt(a);
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test sqrt_test_3
    long double a = -1.0;
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_nan(res2);

#test sqrt_test_4
    long double a = 0.5;
    long double res1 = sqrt(a);
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test sqrt_test_5
    long double a = S21_NAN;
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_nan(res2);

#test sqrt_test_6
    long double a = S21_POS_INF;
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_infinite(res2);

#test sqrt_test_7
    long double a = S21_NEG_INF;
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_nan(res2);

#test sqrt_test_8
    long double a = -123456789;
    long double res2 = s21_sqrt(a);
    ck_assert_ldouble_nan(res2);

/*13--------SQRT-TEST-END----------------------------------------*/

/*14--------TAN-TEST-START--------------------------------------*/

#test tan_test_1
    long double a = 0.0;
    long double res1 = tan(a);
    long double res2 = s21_tan(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test tan_test_2
    long double a = 1.0;
    long double res1 = tan(a);
    long double res2 = s21_tan(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test tan_test_3
    long double a = -1.0;
    long double res1 = tan(a);
    long double res2 = s21_tan(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test tan_test_4
    long double a = 0.5;
    long double res1 = tan(a);
    long double res2 = s21_tan(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test tan_test_5
    long double a = S21_NAN;
    long double res2 = s21_tan(a);
    ck_assert_ldouble_nan(res2);

#test tan_test_6
    long double a = S21_POS_INF;
    long double res2 = s21_tan(a);
    ck_assert_ldouble_infinite(res2);

#test tan_test_7
    long double a = S21_NEG_INF;
    long double res2 = s21_tan(a);
    ck_assert_ldouble_infinite(res2);

#test tan_test_8
    long double a = -123456789;
    long double res1 = tan(a);
    long double res2 = s21_tan(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

/*14--------TAN-TEST-END----------------------------------------*/

/*15--------ASIN-TEST-START--------------------------------------*/

#test asin_test_1
    long double a = 0.0;
    long double res1 = asin(a);
    long double res2 = s21_asin(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test asin_test_2
    long double a = 1.0;
    long double res1 = asin(a);
    long double res2 = s21_asin(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test asin_test_3
    long double a = -1.0;
    long double res2 = s21_asin(a);
    long double res1 = asin(a);
    ck_assert_ldouble_eq_tol(res2, res1, 6);

#test asin_test_4
    long double a = 0.5;
    long double res1 = asin(a);
    long double res2 = s21_asin(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

#test asin_test_5
    long double a = S21_NAN;
    long double res2 = s21_asin(a);
    ck_assert_ldouble_nan(res2);

#test asin_test_6
    long double a = S21_POS_INF;
    long double res2 = s21_asin(a);
    ck_assert_ldouble_infinite(res2);

#test asin_test_7
    long double a = S21_NEG_INF;
    long double res2 = s21_asin(a);
    ck_assert_ldouble_infinite(res2);

#test asin_test_8
    long double a = -123456789;
    long double res1 = tan(a);
    long double res2 = s21_tan(a);
    ck_assert_ldouble_eq_tol(res1, res2, 6);

/*15--------ASIN-TEST-END----------------------------------------*/
