#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strrchr1) {
  const char str[] = "Hello, world! Hello, world!";
  char s = 'o';
  ck_assert_str_eq(my_strrchr(str, s), strrchr(str, s));
}
END_TEST

START_TEST(test_my_strrchr2) {
  const char str[] = "Hello, world! Hello, world!";
  char s = 111;
  ck_assert_str_eq(my_strrchr(str, s), strrchr(str, s));
}
END_TEST

START_TEST(test_my_strrchr3) {
  const char str[] = "Hello, world!";
  char s = ',';
  ck_assert_ptr_eq(my_strrchr(str, s), strrchr(str, s));
}
END_TEST

START_TEST(test_my_strrchr4) {
  const char str[] = "Hello, world!";
  char s = 119;
  ck_assert_ptr_eq(my_strrchr(str, s), strrchr(str, s));
}
END_TEST

START_TEST(test_my_strrchr5) {
  const char str[] = "Hello, world!";
  char s = 75;
  ck_assert_ptr_eq(my_strrchr(str, s), strrchr(str, s));
  ck_assert_ptr_null(my_strrchr(str, s));
}
END_TEST

START_TEST(test_my_strrchr6) {
  const char str[] = "Hello, world!";
  char s = 'a';
  ck_assert_ptr_eq(my_strrchr(str, s), strrchr(str, s));
  ck_assert_ptr_null(my_strrchr(str, s));
}
END_TEST

Suite *test_suite_strrchr() {
  Suite *suite = suite_create("test_my_strrchr");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strrchr1);
  tcase_add_test(tcase, test_my_strrchr2);
  tcase_add_test(tcase, test_my_strrchr3);
  tcase_add_test(tcase, test_my_strrchr4);
  tcase_add_test(tcase, test_my_strrchr5);
  tcase_add_test(tcase, test_my_strrchr6);

  suite_add_tcase(suite, tcase);
  return suite;
}
