#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strncat1) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = " world";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncat(str, str1, len), strncat(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncat2) {
  char str[20] = "";
  char str2[20] = "";
  const char str1[20] = "Hello world";
  my_size_t len = strlen(str1);
  ck_assert_str_eq(my_strncat(str, str1, len), strncat(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncat3) {
  char str[20] = "Hello";
  char str2[20] = "Hello";
  const char str1[20] = "world";
  my_size_t len = 2;
  ck_assert_str_eq(my_strncat(str, str1, len), strncat(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncat4) {
  char str[20] = "Hello\0";
  char str2[20] = "Hello\0";
  const char str1[20] = " world";
  my_size_t len = 7;
  ck_assert_str_eq(my_strncat(str, str1, len), strncat(str2, str1, len));
}
END_TEST

START_TEST(test_my_strncat5) {
  char str[20] = ".";
  char str2[20] = ".";
  const char str1[20] = ",";
  my_size_t len = 5;
  ck_assert_str_eq(my_strncat(str, str1, len), strncat(str2, str1, len));
}
END_TEST

Suite *test_suite_strncat() {
  Suite *suite = suite_create("test_my_strncat");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_strncat1);
  tcase_add_test(tcase, test_my_strncat2);
  tcase_add_test(tcase, test_my_strncat3);
  tcase_add_test(tcase, test_my_strncat4);
  tcase_add_test(tcase, test_my_strncat5);

  suite_add_tcase(suite, tcase);
  return suite;
}
