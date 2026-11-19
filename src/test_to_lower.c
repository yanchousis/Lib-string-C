#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_to_lower1) {
  const char str[] = "HELLO WORLD!";
  char str1[] = "hello world!";
  char *result = my_to_lower(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_lower2) {
  const char str[] = "HELLO, WORLD!";
  char str1[] = "hello, world!";
  char *result = my_to_lower(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_lower3) {
  const char str[] = "";
  char str1[] = "";
  char *result = my_to_lower(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_lower4) {
  const char str[] = " ";
  char str1[] = " ";
  char *result = my_to_lower(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_lower5) {
  const char str[] = "12345 6789\\0|35||?//124A";
  char str1[] = "12345 6789\\0|35||?//124a";
  char *result = my_to_lower(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

START_TEST(test_my_to_lower6) {
  const char str[] = "H";
  char str1[] = "h";
  char *result = my_to_lower(str);
  ck_assert_str_eq(result, str1);
  free(result);
}
END_TEST

Suite *test_suite_to_lower() {
  Suite *suite = suite_create("test_my_to_lower");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_to_lower1);
  tcase_add_test(tcase, test_my_to_lower2);
  tcase_add_test(tcase, test_my_to_lower3);
  tcase_add_test(tcase, test_my_to_lower4);
  tcase_add_test(tcase, test_my_to_lower5);
  tcase_add_test(tcase, test_my_to_lower6);

  suite_add_tcase(suite, tcase);
  return suite;
}
