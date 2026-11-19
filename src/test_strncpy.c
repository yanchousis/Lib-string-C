#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strncpy1) {
  char str[20] = "";
  char str2[20] = "";
  const char str1[20] = "Hello, world!";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncpy2) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "world!";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncpy3) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "world!";
  my_size_t len = 2;
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST
START_TEST(test_my_strncpy4) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "";
  my_size_t len = 2;
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncpy5) {
  char str[20] = "12345\0";
  char str2[20] = "12345\0";
  const char str1[20] = "\012";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncpy6) {
  char str[20] = "Hello\nworld";
  char str2[20] = "Hello\nworld";
  const char str1[20] = "1\n23";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncpy7) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "\n";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncpy8) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "\n";
  my_size_t len = 1;
  ck_assert_str_eq(my_strncpy(str, str1, len), strncpy(str2, str1, len));
}
END_TEST

Suite *test_suite_strncpy() {
  Suite *suite = suite_create("test_my_strncpy");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strncpy1);
  tcase_add_test(tcase, test_my_strncpy2);
  tcase_add_test(tcase, test_my_strncpy3);
  tcase_add_test(tcase, test_my_strncpy4);
  tcase_add_test(tcase, test_my_strncpy5);
  tcase_add_test(tcase, test_my_strncpy6);
  tcase_add_test(tcase, test_my_strncpy7);
  tcase_add_test(tcase, test_my_strncpy8);

  suite_add_tcase(suite, tcase);
  return suite;
}
