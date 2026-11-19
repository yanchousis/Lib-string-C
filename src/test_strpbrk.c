#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strpbrk1) {
  const char str[] = "Hello, world!";
  const char str1[] = "world";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_my_strpbrk2) {
  const char str[] = "Hello, world!";
  const char str1[] = "dw";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_my_strpbrk3) {
  const char str[] = "Hello, world!";
  const char str1[] = " ";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_my_strpbrk4) {
  const char str[] = "Hello, world!";
  const char str1[] = "";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_my_strpbrk5) {
  const char str[] = "Hello, world!";
  const char str1[] = "zkpn";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_my_strpbrk6) {
  const char str[20] = "";
  const char str1[20] = "world";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

START_TEST(test_my_strpbrk7) {
  const char str[20] = "";
  const char str1[20] = "";
  ck_assert_pstr_eq(my_strpbrk(str, str1), strpbrk(str, str1));
}
END_TEST

Suite *test_suite_strpbrk() {
  Suite *suite = suite_create("test_my_strpbrk");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_strpbrk1);
  tcase_add_test(tcase, test_my_strpbrk2);
  tcase_add_test(tcase, test_my_strpbrk3);
  tcase_add_test(tcase, test_my_strpbrk4);
  tcase_add_test(tcase, test_my_strpbrk5);
  tcase_add_test(tcase, test_my_strpbrk6);
  tcase_add_test(tcase, test_my_strpbrk7);

  suite_add_tcase(suite, tcase);
  return suite;
}
