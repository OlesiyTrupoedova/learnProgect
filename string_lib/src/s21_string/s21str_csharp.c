#include <stdlib.h>

#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *res = s21_NULL;
  s21_size_t src_length, str_length;
  src_length = (src == s21_NULL) ? 0 : s21_strlen(src);
  str_length = (str == s21_NULL) ? 0 : s21_strlen(str);
  s21_size_t fin_length = src_length + str_length;
  if (start_index <= src_length) {
    res = (char *)calloc(src_length + str_length + 1, sizeof(char));
  }
  if (res) {
    for (s21_size_t i = 0; i < fin_length; i++) {
      if (i < start_index) {
        res[i] = src[i];
      } else if (i < str_length + start_index) {
        res[i] = str[i - start_index];
      } else {
        res[i] = src[i - str_length];
      }
    }
  }
  return res;
}


int startwith(const char *src, const char *trim_chars, int offset) {
  int res = 0;
  int size = s21_strlen(trim_chars);
  for (int i = 0; i < size; i++) {
    if (src[offset] == trim_chars[i]) res = 1;
  }
  return res;
}

int endwith(const char *src, const char *trim_chars, int offset) {
  int res = 0;
  offset--;
  int size = s21_strlen(trim_chars);
  for (int i = 0; i < size; i++) {
    if (src[offset] == trim_chars[i]) res = 1;
  }
  return res;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *newstr = s21_NULL;
  if (src) {
    if (trim_chars && trim_chars[0]) {
      newstr = calloc(s21_strlen(src) + 1, 1);
      s21_size_t start = 0, end = s21_strlen(src);
      while (startwith(src, trim_chars, start)) {
        start++;
      }
      if (start != end) {
        while (endwith(src, trim_chars, end)) end--;
      } else {
        newstr[0] = '\0';
      }
      for (int i = 0; start < end; i++) {
        newstr[i] = src[start];
        start++;
      }
    } else {
      newstr = s21_trim(src, "\t\n ");
    }
  }
  return newstr;
}


void *s21_to_upper(const char *str) {
  s21_size_t size = s21_strlen(str);
  char *k = malloc(sizeof(char) * (size + 1));
  k = s21_memcpy(k, str, size + 1);
  for (s21_size_t i = 0; i < size; i++) {
    if (k[i] >= 97 && k[i] <= 122) {
      k[i] -= 32;
    }
  }
  k[size] = '\0';
  return k;
}

void *s21_to_lower(const char *str) {
  s21_size_t size = s21_strlen(str);
  char *k = malloc(sizeof(char) * (size + 1));
  k = s21_memcpy(k, str, size + 1);
  for (s21_size_t i = 0; i < size; i++) {
    if (k[i] >= 65 && k[i] <= 90) {
      k[i] += 32;
    }
  }
  k[size] = '\0';
  return k;
}
