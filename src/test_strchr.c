#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strchr1) {
  const char str[] = "Hello, world!";
  char s = 'w';
  ck_assert_ptr_eq(my_strchr(str, s), strchr(str, s));
}
END_TEST

START_TEST(test_my_strchr2) {
  const char str[] = "Hello, world!";
  char s = 'a';
  ck_assert_ptr_eq(my_strchr(str, s), strchr(str, s));
  ck_assert_ptr_null(my_strchr(str, s));
}
END_TEST

START_TEST(test_my_strchr3) {
  const char str[] = "Hello, world!";
  char s = ',';
  ck_assert_ptr_eq(my_strchr(str, s), strchr(str, s));
}
END_TEST

START_TEST(test_my_strchr4) {
  const char str[] = "Hello, world!";
  int s = 119;
  ck_assert_ptr_eq(my_strchr(str, s), strchr(str, s));
}
END_TEST

START_TEST(test_my_strchr5) {
  const char str[] = "Hello, world!";
  int s = 75;
  ck_assert_ptr_eq(my_strchr(str, s), strchr(str, s));
  ck_assert_ptr_null(my_strchr(str, s));
}
END_TEST

START_TEST(test_my_strchr6) {
  const char str[] = "Hello, world!";
  int s = 0;
  ck_assert_ptr_eq(my_strchr(str, s), strchr(str, s));
}
END_TEST

Suite *test_suite_strchr() {
  Suite *suite = suite_create("test_my_strchr");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strchr1);
  tcase_add_test(tcase, test_my_strchr2);
  tcase_add_test(tcase, test_my_strchr3);
  tcase_add_test(tcase, test_my_strchr4);
  tcase_add_test(tcase, test_my_strchr5);
  tcase_add_test(tcase, test_my_strchr6);

  suite_add_tcase(suite, tcase);
  return suite;
}
