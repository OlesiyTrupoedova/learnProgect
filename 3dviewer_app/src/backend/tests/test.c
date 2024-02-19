#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "../action_with_obgect.h"
#include "../parse.h"

#define M_PI 3.14159265359

START_TEST(test_parse) {
  object *obj = malloc(sizeof(object));

  parse("object/cube.obj", obj);

  ck_assert_int_eq(obj->vertexes_amount, 8);
  ck_assert_int_eq(obj->polygons_amount, 12);
  remove_object(obj);
  // fclose(file);
}
END_TEST

START_TEST(test_action_with_object) {
  object obj;

  parse("object/cube.obj", &obj);
  normalize(&obj);

  rotation_by_ox(&obj, (12 * M_PI) / 180);
  rotation_by_oy(&obj, (12 * M_PI) / 180);
  rotation_by_oz(&obj, (12 * M_PI) / 180);

  skale_object(&obj, 2);

  move_object(&obj, 0.13, 2);
  move_object(&obj, 3, 1);
  move_object(&obj, 2, 0);

  ck_assert_int_eq(obj.vertexes_amount, 8);
  ck_assert_int_eq(obj.polygons_amount, 12);
  remove_object(&obj);
  // fclose(file);
}

int main() {
  Suite *s = suite_create("test");
  TCase *tc = tcase_create("test");
  tcase_add_test(tc, test_parse);
  tcase_add_test(tc, test_action_with_object);
  suite_add_tcase(s, tc);
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_ENV);
  int failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return failed;
}