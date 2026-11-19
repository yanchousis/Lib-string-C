#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strcspn1) {
  const char str[20] = "Hello, world!";
  const char str1[20] = ",!";
  ck_assert_uint_eq(my_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(test_my_strcspn2) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "12345";
  ck_assert_uint_eq(my_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(test_my_strcspn3) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "\54";
  ck_assert_uint_eq(my_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(test_my_strcspn4) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "";
  ck_assert_uint_eq(my_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(test_my_strcspn5) {
  const char str[20] = "Hello, world!";
  const char str1[20] = " ";
  ck_assert_uint_eq(my_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

START_TEST(test_my_strcspn6) {
  const char str[20] = "Hello, world!";
  const char str1[20] = "Hd";
  ck_assert_uint_eq(my_strcspn(str, str1), strcspn(str, str1));
}
END_TEST

Suite *test_suite_strcspn() {
  Suite *suite = suite_create("test_my_strcspn");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strcspn1);
  tcase_add_test(tcase, test_my_strcspn2);
  tcase_add_test(tcase, test_my_strcspn3);
  tcase_add_test(tcase, test_my_strcspn4);
  tcase_add_test(tcase, test_my_strcspn5);
  tcase_add_test(tcase, test_my_strcspn6);

  suite_add_tcase(suite, tcase);
  return suite;
}
