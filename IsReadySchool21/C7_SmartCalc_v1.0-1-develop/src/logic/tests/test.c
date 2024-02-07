#include "test.h"

int main() {
  int number_failed = 0;

  Suite *s = test_validate();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_ENV);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  s = test_calc_hard();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_ENV);
  number_failed += srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}