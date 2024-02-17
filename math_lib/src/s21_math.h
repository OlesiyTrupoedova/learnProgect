#ifndef S21_MATH_H
#define S21_MATH_H

#define S21_E 2.71828182845904523536028747470936999L

#define S21_2PI 6.28318530717958647692528676656L
#define S21_PI 3.14159265358979323846264338327950288L
#define S21_PI_2 1.57079632679489661923132169163975144L
#define S21_PI_4 0.785398163397448309615660845819875721L

#define LOG_DBL_MAX 709.78271289338399674395674310289905407L
#define LOG_DBL_MIN -708.39641853226410622701436636816652026L

#define PRICISION_ROUGH_LIMIT 1000
#define PRICISION_LIMIT 0.0000001

#define S21_NAN 0.0 / 0.0
#define S21_POS_INF (1.0 / 0.0)
#define S21_NEG_INF (-1.0 / 0.0)

typedef union {
  double d;
  struct {
    unsigned long long int m : 52;
    unsigned int e : 11;
    unsigned int s : 1;
  } parts;
} double_cast;

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif /*S21_MATH_H*/
