#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_to_upper1) {
  const char str[] = "hello world!";
  char str1[] = "HELLO WORLD!";
  char *result = my_to_upper(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_upper2) {
  const char str[] = "HELLO WORLD!";
  char str1[] = "HELLO WORLD!";
  char *result = my_to_upper(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_upper3) {
  const char str[] = "";
  char str1[] = "";
  char *result = my_to_upper(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_upper4) {
  const char str[] = " ";
  char str1[] = " ";
  char *result = my_to_upper(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_upper5) {
  const char str[] = "12345 6789\\0|35||?//124a";
  char str1[] = "12345 6789\\0|35||?//124A";
  char *result = my_to_upper(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_upper6) {
  const char str[] = "h";
  char str1[] = "H";
  char *result = my_to_upper(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

Suite *test_suite_to_upper() {
  Suite *suite = suite_create("test_my_to_upper");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_to_upper1);
  tcase_add_test(tcase, test_my_to_upper2);
  tcase_add_test(tcase, test_my_to_upper3);
  tcase_add_test(tcase, test_my_to_upper4);
  tcase_add_test(tcase, test_my_to_upper5);
  tcase_add_test(tcase, test_my_to_upper6);

  suite_add_tcase(suite, tcase);
  return suite;
}
