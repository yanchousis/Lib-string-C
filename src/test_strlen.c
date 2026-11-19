#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strlen1) {
  const char *str = "Hello, world!";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_my_strlen2) {
  const char *str = "";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_my_strlen3) {
  const char *str = "size_t strlen(const char *str);";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_my_strlen4) {
  const char *str = ",/()^*";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

START_TEST(test_my_strlen5) {
  const char *str = "\0";
  ck_assert_uint_eq(my_strlen(str), strlen(str));
}
END_TEST

Suite *test_suite_strlen() {
  Suite *suite = suite_create("test_my_strlen");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strlen1);
  tcase_add_test(tcase, test_my_strlen2);
  tcase_add_test(tcase, test_my_strlen3);
  tcase_add_test(tcase, test_my_strlen4);
  tcase_add_test(tcase, test_my_strlen5);

  suite_add_tcase(suite, tcase);
  return suite;
}
