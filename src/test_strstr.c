#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strstr1) {
  char str[30] = "Hello, world! Hello, world!";
  const char str1[20] = "world";
  ck_assert_pstr_eq(my_strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(test_my_strstr2) {
  char str[30] = "Hello, world! Hello, world!";
  const char str1[20] = "H";
  ck_assert_pstr_eq(my_strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(test_my_strstr3) {
  char str[30] = "Hello, world! Hello, world!";
  const char str1[20] = ", w";
  ck_assert_pstr_eq(my_strstr(str, str1), strstr(str, str1));
}
END_TEST

START_TEST(test_my_strstr4) {
  char str[30] = "Hello, world! Hello, world!";
  const char str1[20] = "klmn";
  ck_assert_pstr_eq(my_strstr(str, str1), strstr(str, str1));
  ck_assert_ptr_null(my_strstr(str, str1));
}
END_TEST

START_TEST(test_my_strstr5) {
  const char str[20] = "";
  const char str1[10] = "";
  ck_assert_ptr_null(my_strstr(str, str1));
}
END_TEST

START_TEST(test_my_strstr6) {
  char str[30] = "123456\078910\0";
  const char str1[20] = "\0";
  ck_assert_pstr_eq(my_strstr(str, str1), strstr(str, str1));
}
END_TEST

Suite *test_suite_strstr() {
  Suite *suite = suite_create("test_my_strstr");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strstr1);
  tcase_add_test(tcase, test_my_strstr2);
  tcase_add_test(tcase, test_my_strstr3);
  tcase_add_test(tcase, test_my_strstr4);
  tcase_add_test(tcase, test_my_strstr5);
  tcase_add_test(tcase, test_my_strstr6);

  suite_add_tcase(suite, tcase);
  return suite;
}
