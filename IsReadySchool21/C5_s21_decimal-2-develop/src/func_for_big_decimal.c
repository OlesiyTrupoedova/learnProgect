#include <stdio.h>

#include "s21_decimal.h"

void to_big_decimal(s21_decimal value, big_decimal *big_value) {
  for (int i = 0; i < 3; i++) {
    big_value->bits[i] = value.bits[i];
  }
  big_value->bits[6] = value.bits[3];
}

void big_align_exp(big_decimal *value_1, big_decimal *value_2) {
  int exp = 0;
  comm_byte vl_1, vl_2;

  vl_1.bits = value_1->bits[6];
  vl_2.bits = value_2->bits[6];

  if (vl_1.bite.exp > vl_2.bite.exp) {
    exp = vl_1.bite.exp - vl_2.bite.exp;
    for (int i = 0; i < exp; i++) {
      mul10_for_big(value_2);
    }
    vl_2.bite.exp = vl_1.bite.exp;
    value_2->bits[6] = vl_2.bits;
  }
  if (vl_1.bite.exp < vl_2.bite.exp) {
    exp = vl_2.bite.exp - vl_1.bite.exp;
    for (int i = 0; i < exp; i++) {
      mul10_for_big(value_1);
    }
    vl_1.bite.exp = vl_2.bite.exp;
    value_1->bits[6] = vl_1.bits;
  }
}

int process_add(big_decimal value_1, big_decimal value_2, big_decimal *result) {
  int norm = 0;
  int error = 0;

  for (int i = 0; i < 192; i++) {
    if (get_bit_mantisa_for_big(value_1, i) &&
        get_bit_mantisa_for_big(value_2, i)) {
      if (norm) {
        set_bit_mantisa_for_big(result, i);
      }
      norm = 1;
      continue;
    } else if ((get_bit_mantisa_for_big(value_1, i) &&
                !get_bit_mantisa_for_big(value_2, i)) ||
               (!get_bit_mantisa_for_big(value_1, i) &&
                get_bit_mantisa_for_big(value_2, i))) {
      if (!norm) {
        set_bit_mantisa_for_big(result, i);
      }
      continue;
    }
    if (norm) {
      set_bit_mantisa_for_big(result, i);
    }
    norm = 0;
  }

  return error;
}

void add_big_decimal(big_decimal big_value_1, big_decimal big_value_2,
                     big_decimal *big_result) {
  decimal_to_null_for_big(big_result);

  comm_byte vl_1, vl_2, res;
  res.bits = big_result->bits[6];
  vl_1.bits = big_value_1.bits[6];
  vl_2.bits = big_value_2.bits[6];

  if (!vl_1.bite.unar && !vl_2.bite.unar) {
    process_add(big_value_1, big_value_2, big_result);
  } else if (vl_1.bite.unar && !vl_2.bite.unar) {
    vl_1.bite.unar = 0;
    big_value_1.bits[6] = vl_1.bits;
    if (is_less_for_big(big_value_2, big_value_1)) {
      res.bite.unar = 1;
    }
    sub_big_decimal(big_value_2, big_value_1, big_result);
    if (is_big_decimal_zero(*big_result)) {
      res.bite.unar = 1;
    }
    big_result->bits[6] = res.bits;
  } else if ((!vl_1.bite.unar && vl_2.bite.unar) ||
             (vl_1.bite.unar && vl_2.bite.unar)) {
    if (vl_1.bite.unar && vl_2.bite.unar) {
      res.bite.unar = 1;
    }
    vl_2.bite.unar = 0;
    big_value_2.bits[6] = vl_2.bits;
    if (is_less_for_big(big_value_1, big_value_2)) {
      res.bite.unar = 1;
    }
    sub_big_decimal(big_value_1, big_value_2, big_result);
    big_result->bits[6] = res.bits;
  }
}

void sub_big_decimal(big_decimal value_1, big_decimal value_2,
                     big_decimal *result) {
  comm_byte vl_1, vl_2, res;
  res.bits = result->bits[6];
  vl_1.bits = value_1.bits[6];
  vl_2.bits = value_2.bits[6];

  if (!vl_1.bite.unar && !vl_2.bite.unar) {
    int n = 0;
    if (is_greater_for_big(value_1, value_2)) {
      n = first_set_bit_for_big(value_1);
      decimal_inversion_for_big(&value_1, n);
      add_big_decimal(value_1, value_2, result);
      decimal_inversion_for_big(result, n);
    } else if (is_equal_for_big(value_1, value_2)) {
      res.bite.unar = 0;
      decimal_to_null_for_big(result);
    } else {
      n = first_set_bit_for_big(value_2);
      decimal_inversion_for_big(&value_2, n);
      add_big_decimal(value_2, value_1, result);
      decimal_inversion_for_big(result, n);
      res.bite.unar = 1;
      result->bits[6] = res.bits;
    }
  } else if (!vl_1.bite.unar && vl_2.bite.unar) {
    vl_2.bite.unar = 0;
    value_2.bits[6] = vl_2.bits;
    add_big_decimal(value_1, value_2, result);
  } else if (vl_1.bite.unar && !vl_2.bite.unar) {
    vl_1.bite.unar = 0;
    value_1.bits[6] = vl_1.bits;
    add_big_decimal(value_1, value_2, result);
    res.bite.unar = 1;
    result->bits[6] = res.bits;
  } else if (vl_1.bite.unar && vl_2.bite.unar) {
    vl_2.bite.unar = 0;
    value_2.bits[6] = vl_2.bits;
    add_big_decimal(value_1, value_2, result);
  }
}

int get_bit_mantisa_for_big(big_decimal x, int getbit) {
  int res = 0;
  if (getbit >= 0 && getbit <= 31) {
    res = get_bit(x.bits[0], getbit);
  }
  if (getbit >= 32 && getbit <= 63) {
    res = get_bit(x.bits[1], getbit - 32);
  }
  if (getbit >= 64 && getbit <= 95) {
    res = get_bit(x.bits[2], getbit - 64);
  }
  if (getbit >= 96 && getbit <= 127) {
    res = get_bit(x.bits[3], getbit - 96);
  }
  if (getbit >= 128 && getbit <= 159) {
    res = get_bit(x.bits[4], getbit - 128);
  }
  if (getbit >= 160 && getbit <= 191) {
    res = get_bit(x.bits[5], getbit - 160);
  }
  return res;
}

void set_bit_mantisa_for_big(big_decimal *x, int placeBit) {
  if (placeBit >= 0 && placeBit <= 31) {
    set_bit(&x->bits[0], placeBit);
  }
  if (placeBit >= 32 && placeBit <= 63) {
    set_bit(&x->bits[1], placeBit - 32);
  }
  if (placeBit >= 64 && placeBit <= 95) {
    set_bit(&x->bits[2], placeBit - 64);
  }
  if (placeBit >= 96 && placeBit <= 127) {
    set_bit(&x->bits[3], placeBit - 96);
  }
  if (placeBit >= 128 && placeBit <= 159) {
    set_bit(&x->bits[4], placeBit - 128);
  }
  if (placeBit >= 160 && placeBit <= 191) {
    set_bit(&x->bits[5], placeBit - 160);
  }
}

int is_greater_for_big(big_decimal first, big_decimal second) {
  comm_byte bn1, bn2;
  bn1.bits = first.bits[6];
  bn2.bits = second.bits[6];

  int result = 0;

  big_align_exp(&first, &second);

  if (bn1.bite.unar && bn2.bite.unar) {
    if (first_set_bit_for_big(first) < first_set_bit_for_big(second))
      result = 1;
    else if (first_set_bit_for_big(first) == first_set_bit_for_big(second)) {
      for (int i = first_set_bit_for_big(first); i >= 0; i--) {
        if (!get_bit_mantisa_for_big(first, i) &&
            get_bit_mantisa_for_big(second, i)) {
          result = 1;
          break;
        } else if (get_bit_mantisa_for_big(first, i) &&
                   !get_bit_mantisa_for_big(second, i))
          break;
      }
    }
  } else if (bn1.bite.unar || bn2.bite.unar) {
    if (bn2.bite.unar) {
      result = 1;
    }
  } else {
    if (first_set_bit_for_big(first) > first_set_bit_for_big(second)) {
      result = 1;
    } else if (first_set_bit_for_big(first) == first_set_bit_for_big(second)) {
      for (int i = first_set_bit_for_big(first); i >= 0; i--) {
        if (get_bit_mantisa_for_big(first, i) &&
            !get_bit_mantisa_for_big(second, i)) {
          result = 1;
          break;
        } else if (!get_bit_mantisa_for_big(first, i) &&
                   get_bit_mantisa_for_big(second, i)) {
          break;
        }
      }
    }
  }

  return result;
}

void mul10_for_big(big_decimal *value_1) {
  comm_byte v1, v2, res = {0};

  big_decimal value_2 = {0}, result = {0};
  value_2.bits[0] = 10;

  v1.bits = value_1->bits[6];
  v2.bits = value_2.bits[6];

  v1.bite.unar = 0;

  value_1->bits[6] = v1.bits;

  res.bite.unar = v1.bite.unar ^ v2.bite.unar;
  res.bite.exp = v1.bite.exp + v2.bite.exp;

  while (!is_big_decimal_zero(value_2)) {
    if ((value_2.bits[0] & RIGHT_BIT) == RIGHT_BIT) {
      add_big_decimal(*value_1, result, &result);
    }

    shift_right_for_big(&value_2, 1);
    shift_left_for_big(value_1, 1);
  }

  result.bits[6] = res.bits;
  for (int i = 0; i < 7; i++) {
    value_1->bits[i] = result.bits[i];
  }
}

void shift_left_for_big(big_decimal *first, int shift) {
  for (int i = 0; i < shift; i++) {
    int f1 = (first->bits[0] & LEFT_BIT) == LEFT_BIT;
    int f2 = (first->bits[1] & LEFT_BIT) == LEFT_BIT;
    int f3 = (first->bits[2] & LEFT_BIT) == LEFT_BIT;
    int f4 = (first->bits[3] & LEFT_BIT) == LEFT_BIT;
    int f5 = (first->bits[4] & LEFT_BIT) == LEFT_BIT;

    for (int i = 0; i < 6; i++) {
      first->bits[i] <<= 1;
    }

    if (f1) {
      set_bit(&first->bits[1], 0);
    }
    if (f2) {
      set_bit(&first->bits[2], 0);
    }
    if (f3) {
      set_bit(&first->bits[3], 0);
    }
    if (f4) {
      set_bit(&first->bits[4], 0);
    }
    if (f5) {
      set_bit(&first->bits[5], 0);
    }
  }
}

void shift_right_for_big(big_decimal *first, int shift) {
  for (int i = 0; i < shift; i++) {
    int f1 = (first->bits[1] & RIGHT_BIT) == RIGHT_BIT;
    int f2 = (first->bits[2] & RIGHT_BIT) == RIGHT_BIT;
    int f3 = (first->bits[3] & RIGHT_BIT) == RIGHT_BIT;
    int f4 = (first->bits[4] & RIGHT_BIT) == RIGHT_BIT;
    int f5 = (first->bits[5] & RIGHT_BIT) == RIGHT_BIT;

    for (int i = 0; i < 6; i++) {
      first->bits[i] >>= 1;
    }

    if (f1) {
      set_bit(&first->bits[0], 31);
    }
    if (f2) {
      set_bit(&first->bits[1], 31);
    }
    if (f3) {
      set_bit(&first->bits[2], 31);
    }
    if (f4) {
      set_bit(&first->bits[3], 31);
    }
    if (f5) {
      set_bit(&first->bits[4], 31);
    }
  }
}

int first_set_bit_for_big(big_decimal value) {
  unsigned k = 1 << 31;
  int flag = 0;
  int res = 192;

  for (int i = 5; i >= 0; i--) {
    for (int j = 0; j < 32; j++) {
      if ((value.bits[i] & k) == k) {
        flag = 1;
        break;
      }
      res--;
      k = k >> 1;
    }
    if (flag) {
      break;
    }
    k = 1 << 31;
  }

  return res;
}

void decimal_inversion_for_big(big_decimal *value, int n) {
  int firstBit = n;

  unsigned k = (1 << (firstBit % 32 % 32 % 32 % 32 % 32)) - 1;

  if (firstBit >= 0 && firstBit <= 31) {
    value->bits[0] = value->bits[0] ^ k;
  }
  if (firstBit >= 32 && firstBit <= 63) {
    value->bits[1] = value->bits[1] ^ k;
    value->bits[0] = ~value->bits[0];
  }
  if (firstBit >= 64 && firstBit <= 95) {
    value->bits[2] = value->bits[2] ^ k;
    value->bits[1] = ~value->bits[1];
    value->bits[0] = ~value->bits[0];
  }
  if (firstBit >= 96 && firstBit <= 127) {
    value->bits[3] = value->bits[3] ^ k;
    value->bits[2] = ~value->bits[2];
    value->bits[1] = ~value->bits[1];
    value->bits[0] = ~value->bits[0];
  }
  if (firstBit >= 128 && firstBit <= 159) {
    value->bits[4] = value->bits[4] ^ k;
    value->bits[3] = ~value->bits[3];
    value->bits[2] = ~value->bits[2];
    value->bits[1] = ~value->bits[1];
    value->bits[0] = ~value->bits[0];
  }
  if (firstBit >= 160 && firstBit <= 191) {
    value->bits[5] = value->bits[5] ^ k;
    value->bits[4] = ~value->bits[4];
    value->bits[3] = ~value->bits[3];
    value->bits[2] = ~value->bits[2];
    value->bits[1] = ~value->bits[1];
    value->bits[0] = ~value->bits[0];
  }
}

int is_equal_for_big(big_decimal first, big_decimal second) {
  int is_equal = 1;

  for (int i = 0; i < 6 && is_equal; i++) {
    if (first.bits[i] != second.bits[i]) {
      is_equal = 0;
    }
  }
  return is_equal;
}

void decimal_to_null_for_big(big_decimal *value) {
  for (int i = 0; i < 7; i++) {
    value->bits[i] = 0;
  }
}

int is_big_decimal_zero(big_decimal value) {
  int flag = 1;
  for (int i = 0; i < 6; i++)
    if (value.bits[i] != 0) {
      flag = 0;
    }

  return flag;
}

int is_greater_or_equal_for_big(big_decimal first, big_decimal second) {
  return is_greater_for_big(first, second) || is_equal_for_big(first, second);
}

int is_less_or_equal_for_big(big_decimal first, big_decimal second) {
  return !is_greater_for_big(first, second);
}

void div_completely(big_decimal *value_1, big_decimal value_2,
                    big_decimal *result) {
  decimal_to_null_for_big(result);
  while (is_greater_or_equal_for_big(*value_1, value_2)) {
    big_decimal temp = value_2;

    big_decimal p = {0};
    p.bits[0] = 1;
    shift_left_for_big(&temp, 1);

    while (is_less_or_equal_for_big(temp, *value_1)) {
      shift_left_for_big(&p, 1);
      shift_left_for_big(&temp, 1);
    }

    shift_right_for_big(&temp, 1);
    sub_big_decimal(*value_1, temp, value_1);

    add_big_decimal(*result, p, result);
  }
}

int is_big_equal_with_int(big_decimal first, int second) {
  big_decimal sec = {0};
  sec.bits[0] = second;
  return is_equal_for_big(first, sec);
}

int is_less_for_big(big_decimal first, big_decimal second) {
  return !is_greater_or_equal_for_big(first, second);
}

int length_big_decimal(big_decimal value) {
  int res = 0;
  for (int i = 0; i < 6; i++) {
    if (value.bits[i]) {
      res += length_int(value.bits[i]);
    }
  }
  return res;
}

// void print_bit_decimal_for_big(big_decimal decimal) {
//   for (int i = 0; i < 7; ++i) {
//     unsigned int a = (decimal.bits[i]);
//     size_t bits_count = 32;
//     while (bits_count--) putchar(a & (1U << bits_count) ? '1' : '0');
//     putchar('\n');
//   }
// }

int from_big_decimal(big_decimal value, s21_decimal *result) {
  int error = 0, first_bit = 0;

  comm_byte v, res = {0};

  v.bits = value.bits[6];
  res.bite.unar = v.bite.unar;
  res.bite.exp = v.bite.exp;
  v.bite.unar = 0;
  value.bits[6] = v.bits;

  big_decimal max = {0}, temp = {0}, big_result = {0};
  max.bits[0] = 0b11111111111111111111111111111111;
  max.bits[1] = 0b11111111111111111111111111111111;
  max.bits[2] = 0b11111111111111111111111111111111;

  if (v.bite.exp) {
    truncate_for_big(value, &temp);
    if (is_greater_for_big(temp, max)) {
      error = res.bite.unar ? 2 : 1;
    } else {
      if ((first_bit = first_set_bit_for_big(value)) <= 96 &&
          (res.bite.exp <= 28)) {
        for (int i = 0; i < 3; i++) {
          result->bits[i] = value.bits[i];
        }
        result->bits[3] = res.bits;
      } else {
        decimal_to_null_for_big(&temp);
        temp.bits[0] = 10;

        value.bits[6] = 0;

        int rest = 0;

        while (res.bite.exp > 28) {
          div_completely(&value, temp, &big_result);
          rest = value.bits[0];
          for (int j = 0; j < 6; j++) {
            value.bits[j] = big_result.bits[j];
          }
          res.bite.exp -= 1;
        }

        while (is_greater_for_big(value, max)) {
          div_completely(&value, temp, &big_result);
          rest = value.bits[0];
          for (int j = 0; j < 6; j++) {
            value.bits[j] = big_result.bits[j];
          }
          res.bite.exp -= 1;
        }

        if (rest > 5 || (rest == 5 && get_bit_mantisa_for_big(big_result, 0))) {
          decimal_to_null_for_big(&temp);
          temp.bits[0] = 1;
          add_big_decimal(big_result, temp, &big_result);
        }

        for (int i = 0; i < 3; i++) {
          result->bits[i] = big_result.bits[i];
        }
        result->bits[3] = res.bits;
      }
    }
  } else {
    // value.bits[6] = 0;
    if (is_greater_for_big(value, max)) {
      error = res.bite.unar ? 2 : 1;
    } else {
      for (int i = 0; i < 3; i++) {
        result->bits[i] = value.bits[i];
      }
      result->bits[3] = res.bits;
    }
  }

  return error;
}

int truncate_for_big(big_decimal value, big_decimal *result) {
  decimal_to_null_for_big(result);
  big_decimal temp = {0}, ten = {0};
  big_decimal value_copy = value;
  comm_byte v = {0}, t = {0};
  ten.bits[0] = 10;
  v.bits = value.bits[6];

  for (int i = 0; i < v.bite.exp; i++) {
    div_completely(&value_copy, ten, &temp);
  }

  t.bite.exp = v.bite.exp;
  temp.bits[6] = t.bits;

  if (v.bite.unar)
    add_big_decimal(value, temp, result);
  else
    sub_big_decimal(value, temp, result);

  decimal_to_null_for_big(&temp);
  temp.bits[0] = 10;
  for (int i = 0; i < v.bite.exp; i++) {
    div_completely(result, temp, result);
  }

  return 0;
}