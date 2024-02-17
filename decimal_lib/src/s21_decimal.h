#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <math.h>

#define LEFT_BIT 0b10000000000000000000000000000000
#define RIGHT_BIT 0b00000000000000000000000000000001

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} big_decimal;

typedef union {
  unsigned int bits;
  struct {
    int nul1 : 15;
    char exp : 8;
    char nul : 7;
    char unar : 1;
  } bite;
} comm_byte;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal first, s21_decimal second);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal first, s21_decimal second);
int s21_is_not_equal(s21_decimal first, s21_decimal second);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int get_bit(unsigned int bite, int pos);
int get_bit_mantisa(s21_decimal x, int getbit);
void set_bit(unsigned int *res, int placeBit);
void decimal_to_null(s21_decimal *value);
int is_decimal_zero(s21_decimal value);
int length_int(int num);
void div_completely(big_decimal *value_1, big_decimal value_2,
                    big_decimal *result);

void shift_left(s21_decimal *first, int shift);

void mul10(s21_decimal *value_1);

void big_align_exp(big_decimal *value_1, big_decimal *value_2);
void align_exp(s21_decimal *value_1, s21_decimal *value_2);
int process_add(big_decimal value_1, big_decimal value_2, big_decimal *result);
void to_big_decimal(s21_decimal value, big_decimal *big_value);
void sub_big_decimal(big_decimal value_1, big_decimal value_2,
                     big_decimal *result);
void add_big_decimal(big_decimal big_value_1, big_decimal big_value_2,
                     big_decimal *big_result);
int get_bit_mantisa_for_big(big_decimal x, int getbit);
void set_bit_mantisa_for_big(big_decimal *x, int placeBit);
int is_greater_for_big(big_decimal first, big_decimal second);
void mul10_for_big(big_decimal *value_1);
void shift_left_for_big(big_decimal *first, int shift);
void shift_right_for_big(big_decimal *first, int shift);
int first_set_bit_for_big(big_decimal value);
void decimal_inversion_for_big(big_decimal *value, int n);
int is_equal_for_big(big_decimal first, big_decimal second);
void decimal_to_null_for_big(big_decimal *value);
int is_big_decimal_zero(big_decimal value);
int is_greater_or_equal_for_big(big_decimal, big_decimal);
int is_less_or_equal_for_big(big_decimal first, big_decimal second);
int is_big_equal_with_int(big_decimal first, int second);
int is_less_for_big(big_decimal first, big_decimal second);
int length_big_decimal(big_decimal value);
int from_big_decimal(big_decimal value, s21_decimal *result);
int truncate_for_big(big_decimal value, big_decimal *result);

#endif /*S21_DECIMAL_H*/
