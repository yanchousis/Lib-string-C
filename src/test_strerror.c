#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strerror1) {
  int errnum = 1;
  ck_assert_str_eq(my_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_my_strerror2) {
  int errnum = 2;
  ck_assert_str_eq(my_strerror(errnum), strerror(errnum));
}
END_TEST

START_TEST(test_my_strerror3) {
  int errnum = 150;
  char *str = my_strerror(errnum);
  ck_assert_str_eq(str, strerror(errnum));
  free(str);
}
END_TEST

START_TEST(test_my_strerror4) {
  int errnum = 1500;
  char *str = my_strerror(errnum);
  ck_assert_str_eq(str, strerror(errnum));
  free(str);
}
END_TEST

START_TEST(test_my_strerror5) {
  int errnum = 32;
  ck_assert_str_eq(my_strerror(errnum), strerror(errnum));
}
END_TEST

Suite *test_suite_strerror() {
  Suite *suite = suite_create("test_my_strerror");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strerror1);
  tcase_add_test(tcase, test_my_strerror2);
  tcase_add_test(tcase, test_my_strerror3);
  tcase_add_test(tcase, test_my_strerror4);
  tcase_add_test(tcase, test_my_strerror5);

  suite_add_tcase(suite, tcase);
  return suite;
}
