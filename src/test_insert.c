#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_insert1) {
  char *str = my_insert("Hello, world!", "world, ", 7);
  ck_assert_str_eq(str, "Hello, world, world!");
  free(str);
}
END_TEST

START_TEST(test_my_insert2) {
  char *str = my_insert("Hello, world!", "world, ", 0);
  ck_assert_str_eq(str, "world, Hello, world!");
  free(str);
}
END_TEST

START_TEST(test_my_insert3) {
  char *str = my_insert("Hello, world!", " world!", 13);
  ck_assert_str_eq(str, "Hello, world! world!");
  free(str);
}
END_TEST

START_TEST(test_my_insert4) {
  char *str = my_insert("", "Hello", 0);
  ck_assert_str_eq(str, "Hello");
  free(str);
}
END_TEST

START_TEST(test_my_insert5) {
  char *str = my_insert("Hello", "", 2);
  ck_assert_str_eq(str, "Hello");
  free(str);
}
END_TEST

Suite *test_suite_insert() {
  Suite *suite = suite_create("test_my_insert");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_insert1);
  tcase_add_test(tcase, test_my_insert2);
  tcase_add_test(tcase, test_my_insert3);
  tcase_add_test(tcase, test_my_insert4);
  tcase_add_test(tcase, test_my_insert5);

  suite_add_tcase(suite, tcase);
  return suite;
}
