#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_memset1) {
  char str[] = "Hello world";
  char str1[] = "Hello world";
  char c = 'p';
  my_size_t num = 5;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset2) {
  char str[] = "Hello";
  char str1[] = "Hello";
  char c = 'p';
  my_size_t num = 3;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset3) {
  char str[] = "Hello";
  char str1[] = "Hello";
  char c = 'n';
  my_size_t num = strlen(str);
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset4) {
  char str[] = "Hello";
  char str1[] = "Hello";
  char c = 's';
  my_size_t num = 0;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset5) {
  char str[] = "Hello, world";
  char str1[] = "Hello, world";
  char c = 127;
  my_size_t num = 10;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset6) {
  char str[] = "Hello, world";
  char str1[] = "Hello, world";
  char c = 1;
  my_size_t num = 5;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset7) {
  char str[] = "12345/12/y\\.h0";
  char str1[] = "12345/12/y\\.h0";
  char c = 65;
  my_size_t num = strlen(str);
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset8) {
  char str[1] = "";
  char str1[1] = "";
  char c = 65;
  my_size_t num = 0;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset9) {
  char str[] = " ";
  char str1[] = " ";
  char c = 65;
  my_size_t num = 1;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

START_TEST(test_my_memset10) {
  char str[2] = " ";
  char str1[2] = " ";
  char c = 65;
  my_size_t num = 1;
  ck_assert_str_eq(my_memset(str, c, num), memset(str1, c, num));
}
END_TEST

Suite *test_suite_memset() {
  Suite *suite = suite_create("test_my_memset");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_memset1);
  tcase_add_test(tcase, test_my_memset2);
  tcase_add_test(tcase, test_my_memset3);
  tcase_add_test(tcase, test_my_memset4);
  tcase_add_test(tcase, test_my_memset5);
  tcase_add_test(tcase, test_my_memset6);
  tcase_add_test(tcase, test_my_memset7);
  tcase_add_test(tcase, test_my_memset8);
  tcase_add_test(tcase, test_my_memset9);
  tcase_add_test(tcase, test_my_memset10);

  suite_add_tcase(suite, tcase);
  return suite;
}
