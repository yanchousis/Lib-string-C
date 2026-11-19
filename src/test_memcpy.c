#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_memcpy1) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "world";
  my_size_t len = strlen(str);
  ck_assert_str_eq(my_memcpy(str, str1, len), memcpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_memcpy2) {
  char str[20] = "Hello world";
  char str2[20] = "Hello world";
  const char str1[20] = " ";
  my_size_t len = 2;
  ck_assert_str_eq(my_memcpy(str, str1, len), memcpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_memcpy3) {
  char str[20] = " ";
  char str2[20] = " ";
  const char str1[20] = "Hello world";
  my_size_t len = 2;
  ck_assert_str_eq(my_memcpy(str, str1, len), memcpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_memcpy4) {
  char str[20] = "1\2\3\0";
  char str2[20] = "1\2\3\0";
  const char str1[20] = "Hello world";
  my_size_t len = 4;
  ck_assert_str_eq(my_memcpy(str, str1, len), memcpy(str2, str1, len));
}
END_TEST

START_TEST(test_my_memcpy5) {
  char str[20] = "Hello, world!";
  char str2[20] = "Hello, world!";
  const char str1[20] = "\0";
  my_size_t len = 1;
  ck_assert_str_eq(my_memcpy(str, str1, len), memcpy(str2, str1, len));
}
END_TEST

Suite *test_suite_memcpy() {
  Suite *suite = suite_create("test_my_memcpy");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_memcpy1);
  tcase_add_test(tcase, test_my_memcpy2);
  tcase_add_test(tcase, test_my_memcpy3);
  tcase_add_test(tcase, test_my_memcpy4);
  tcase_add_test(tcase, test_my_memcpy5);

  suite_add_tcase(suite, tcase);
  return suite;
}
