#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strncmp1) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "Hello, world!";
  my_size_t len = strlen(str);
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

START_TEST(test_my_strncmp2) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "Hello";
  my_size_t len = strlen(str);
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

START_TEST(test_my_strncmp3) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "Hello";
  my_size_t len = strlen(str1);
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

START_TEST(test_my_strncmp4) {
  const char str[20] = "";
  const char str1[20] = "";
  my_size_t len = strlen(str1);
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

START_TEST(test_my_strncmp5) {
  const char str[20] = "Hello, world!";
  const char str1[20] = " Hello, world!";
  my_size_t len = strlen(str1);
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

START_TEST(test_my_strncmp6) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "HELLO, WORLD!";
  my_size_t len = strlen(str1);
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

START_TEST(test_my_strncmp7) {
  const char str[20] = "";
  const char str1[20] = "";
  my_size_t len = 0;
  ck_assert_int_eq(my_strncmp(str, str1, len), strncmp(str, str1, len));
}
END_TEST

Suite *test_suite_strncmp() {
  Suite *suite = suite_create("test_my_strncmp");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strncmp1);
  tcase_add_test(tcase, test_my_strncmp2);
  tcase_add_test(tcase, test_my_strncmp3);
  tcase_add_test(tcase, test_my_strncmp4);
  tcase_add_test(tcase, test_my_strncmp5);
  tcase_add_test(tcase, test_my_strncmp6);
  tcase_add_test(tcase, test_my_strncmp7);

  suite_add_tcase(suite, tcase);
  return suite;
}
