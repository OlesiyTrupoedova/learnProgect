#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <math.h>
#include <stdlib.h>

#define assert_double(x, y) (fabsl(x - y) < 0.0000001)

#include "../logic.h"

Suite *test_validate();
Suite *test_calc_hard();

#endif  // TEST_H