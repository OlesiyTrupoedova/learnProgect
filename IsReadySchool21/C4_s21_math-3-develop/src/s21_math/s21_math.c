#include "../s21_math.h"
#include <math.h>
#include <stdio.h>


static long double s21_exp_long(long double lx) {
  if (lx != lx) return lx;
  if (lx == S21_POS_INF || lx == S21_NEG_INF) return lx;
  if (lx > LOG_DBL_MAX) {
    return S21_POS_INF;
  } else if (lx < LOG_DBL_MIN) {
    return 0;
  }

  long double an = 1.0;
  long double result = an;
  register long long n = 1;
  for (; (n < PRICISION_ROUGH_LIMIT) &&
         (an > PRICISION_LIMIT || an < -PRICISION_LIMIT);
       ++n) {
    an = an * lx / n;
    result += an;
  }

  return result;
}

static long double s21_log_long(long double lx) {
  if (lx < 0.) return S21_NAN;
  if (lx == 0.) return S21_NEG_INF;
  long double minus = 0.0;
  if (lx < 0.5) {
    lx *= 1.0e10;
    minus -= 23.0258509;
  }

  long double start = lx > 1 ? 0 : -20;
  long double end = lx;
  long double mid = (end + start) * 0.5;
  long double res = (s21_exp_long(mid) - lx);
  for (long long n = 0; (n < PRICISION_ROUGH_LIMIT) &&
                        (res > PRICISION_LIMIT || res < PRICISION_LIMIT);
       ++n) {
    if (res > 0) end = mid;
    if (res < 0) start = mid;
    mid = (end + start) * 0.5;
    res = (s21_exp_long(mid) - lx);
  }

  return mid + minus;
}

static long double s21_pow_long(long double lx, long double ly) {
  if (lx == 0.) {
    if (ly == 0.) return 1.;
    if (ly > 0.)
      return 0.;
    else
      return S21_POS_INF;
  }

  if (ly == (long long)ly) {
    unsigned long ypow = (unsigned long)ly;
    long double res = 1.;
    if (ly < 0.) {
      ypow = -ypow;
      lx = 1. / lx;
    }

    for (;;) {
      if (ypow & 1) res *= lx;
      if ((ypow >>= 1) == 0) break;
      lx *= lx;
    }
    return res;
  }

  return s21_exp_long(ly * s21_log_long(lx));
}

static long double s21_sqrt_long(long double lx) {
  if (lx != lx) return lx;
  if (lx == S21_POS_INF || lx == S21_NEG_INF) return lx;

  return s21_pow_long(lx, 0.5);
}

static long double s21_cos_long(long double lx) {
  if (lx != lx) return lx;
  if (lx == S21_POS_INF || lx == S21_NEG_INF) return lx;

  lx = (lx - (s21_floor(lx / S21_2PI)) * S21_2PI);

  char sign = 1;
  if (lx > S21_PI) {
    lx -= S21_PI;
    sign = -1;
  }
  long double res = 1.0;
  long double an = 1.0;
  long double x_na_x = lx * lx;
  long double n = 1;
  for (; (n < PRICISION_ROUGH_LIMIT) &&
         (an > PRICISION_LIMIT || an < -PRICISION_LIMIT);
       n++) {
    an *= (-1) * x_na_x / ((2 * n - 1) * (2 * n));
    res += an;
  }
  return res * sign;
}

static long double s21_sin_long(long double lx) {
  if (lx != lx) return lx;
  if (lx == S21_POS_INF || lx == S21_NEG_INF) return lx;

  lx = (lx - (s21_floor(lx / S21_2PI)) * S21_2PI);

  char sign = 1;
  if (lx > S21_PI) {
    lx -= S21_PI;
    sign = -1;
  }
  long double res = lx;
  long double an = lx;
  long double x_na_x = lx * lx;
  register long long n = 0;
  for (; an > PRICISION_LIMIT || an < -PRICISION_LIMIT;) {
    an *= (-1) * x_na_x / ((2 * n + 2) * (2 * n + 3));
    res += an;
    n++;
  }
  return res * sign;
}

static long double s21_atan_long(long double lx) {
  if (lx != lx) return lx;
  if (lx == S21_POS_INF || lx == S21_NEG_INF) return lx;

  if (lx == 1) return S21_PI_4;
  if (lx == -1) return -S21_PI_4;
  if (lx > 1) return S21_PI_2 - s21_atan_long(1 / lx);
  if (lx < -1) return -S21_PI_2 - s21_atan_long(1 / lx);

  long double sum = 0;
  register unsigned int n = 1;
  long double an = 1.0;
  for (; an > PRICISION_LIMIT || an < -PRICISION_LIMIT; ++n) {
    an = s21_pow_long(-1, n - 1) * s21_pow_long(lx, 2 * n - 1) / (2 * n - 1);
    sum += an;
  }

  return sum;
}

int s21_abs(int x) {
  if (x == -1) return 1;
  return x < 0 ? x *= -1 : x;
}

long double s21_floor(double x) {
  const int mant_bit = 52;

  double_cast d;
  d.d = x;
  if (d.d < 1 && d.d > 0) return 0;
  if (d.parts.e <= 1022) /*it`s a magic (~>w<~)*/
    d.parts.e = 0;
  d.parts.m >>= (mant_bit - (d.parts.e - 1023));
  d.parts.m <<= (mant_bit - (d.parts.e - 1023));
  if ((d.parts.s == 1) && (x - d.d != 0)) d.d--;
  return d.d;
}

long double s21_exp(double x) {
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  if (x > LOG_DBL_MAX) {
    return S21_POS_INF;
  } else if (x < LOG_DBL_MIN) {
    return 0;
  }

  long double lx = x;
  long double an = 1.0;
  long double result = an;
  register long long n = 1;
  for (; (n < PRICISION_ROUGH_LIMIT) &&
         (an > PRICISION_LIMIT || an < -PRICISION_LIMIT);
       ++n) {
    an = an * lx / n;
    result += an;
  }

  return result;
}

long double s21_pow(double x, double y) {
  if (x == 0) {
    if (y == 0) return 1;
    if (y > 0)
      return 0;
    else
      return S21_POS_INF;
  }
  long result = 0;
  long double lx = x;
  long double ly = y;
  
  return s21_exp_long(ly * s21_log_long(lx));
}

long double s21_acos(double x) {
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  long double lx = x;
  if (x == 0) {
    return S21_PI_2;
  } else if (x > 0) {
    return s21_atan_long(s21_sqrt_long(1 - lx * lx) / lx);
  } else
    return S21_PI + (s21_atan_long(s21_sqrt_long(1 - lx * lx) / lx));
}

long double s21_asin(double x) {
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  long double lx = x;
  if (x == 1) {
    return S21_PI_2;
  } else if (x == -1) {
    return -S21_PI_2;
  } else
    return s21_atan_long(x / s21_sqrt_long(1 - lx * lx));
}

long double s21_tan(double x) {
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  long double lx = x;
  return s21_sin_long(lx) / s21_cos_long(lx);
}

long double s21_sqrt(double x) {
  if (x < 0) return S21_NAN;
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;
  if (x == 0) return 0;

  return s21_pow_long(x, 0.5);
}

long double s21_fabs(double x) {
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  double_cast d;
  d.d = x;
  d.parts.s = 0;

  return d.d;
}

long double s21_ceil(double x) {
  const int mant_bit = 52;

  double_cast d;
  d.d = x;
  if (x > -1 && x < 0) return -0;
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  if (d.parts.e <= 1022) /*it`s a magic (~^w^~)*/
    d.parts.e = 0;
  d.parts.m >>= (mant_bit - (d.parts.e - 1023));
  d.parts.m <<= (mant_bit - (d.parts.e - 1023));
  if ((d.parts.s == 0) && (x - d.d != 0)) d.d += 1;
  return d.d;
}

long double s21_sin(double x) {
  if (x != x) return x;
  if (x == S21_POS_INF || x == S21_NEG_INF) return x;

  long double lx = x;

  lx = (lx - (s21_floor(lx / S21_2PI)) * S21_2PI);

  char sign = 1;
  if (lx > S21_PI) {
    lx -= S21_PI;
    sign = -1;
  }
  long double res = lx;
  long double an = lx;
  long double x_na_x = lx * lx;
  register long long n = 0;
  for (; an > PRICISION_LIMIT || an < -PRICISION_LIMIT; n++) {
    an *= (-1) * x_na_x / ((2 * n + 2) * (2 * n + 3));
    res += an;
  }

  return res * sign;
}

long double s21_cos(double x) {
  long double lx = x;

  lx = (lx - (s21_floor(lx / S21_2PI)) * S21_2PI);
  char sign = 1;
  if (lx > S21_PI) {
    lx -= S21_PI;
    sign = -1;
  }

  long double res = 1.0;
  long double an = 1.0;
  long double x_na_x = lx * lx;
  long double n = 1;
  for (; (n < PRICISION_ROUGH_LIMIT) &&
         (an > PRICISION_LIMIT || an < -PRICISION_LIMIT);
       n++) {
    an *= (-1) * x_na_x / ((2 * n - 1) * (2 * n));
    res += an;
  }

  return res * sign;
}

long double s21_fmod(double x, double y) {
  long double lx = s21_fabs(x);
  long double ly = s21_fabs(y);
  long double res;

  char sign = x < 0 ? -1 : 1;
  res = (lx - ly * s21_floor(lx / ly));

  return res *= sign;
}

long double s21_atan(double x) {
  if (x == 1) return S21_PI_4;
  if (x == -1) return -S21_PI_4;
  if (x > 1) return S21_PI_2 - s21_atan(1 / x);
  if (x < -1) return -S21_PI_2 - s21_atan(1 / x);

  long double lx = x;
  long double sum = 0;
  register unsigned int n = 1;
  long double an = 1.0;
  for (; an > PRICISION_LIMIT || an < -PRICISION_LIMIT; ++n) {
    an = s21_pow_long(-1, n - 1) * s21_pow_long(lx, 2 * n - 1) / (2 * n - 1);
    sum += an;
  }

  return sum;
}

long double s21_log(double x) {
  if (x < 0.) return S21_NAN;
  if (x == 0.) return S21_NEG_INF;

  long double minus = 0.0;
  if (x < 0.5) {
    x *= 1.0e10;
    minus -= 23.0258509;
  }
  long double lx = x;
  long double start = x > 1 ? 0 : -20;
  long double end = lx;
  long double mid = (end + start) * 0.5;
  long double res = (s21_exp_long(mid) - lx);
  short n = 0;
  for (; (n < PRICISION_ROUGH_LIMIT) &&
         (res > PRICISION_LIMIT || res < -PRICISION_LIMIT);
       n++) {
    if (res > 0) end = mid;
    if (res < 0) start = mid;
    mid = (end + start) * 0.5;
    res = (s21_exp_long(mid) - lx);
  }

  return mid + minus;
}


