#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_memcmp1) {
  const char str[] = "Hello world";
  const char str1[] = "Hello world";
  my_size_t num = 10;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp2) {
  const char str[] = "Hello!";
  const char str1[] = "Hallo!";
  my_size_t num = 7;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp3) {
  const char str[] = "Hello world";
  const char str1[] = "Hello";
  my_size_t num = 5;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp4) {
  const char str[] = "";
  const char str1[] = "";
  my_size_t num = 0;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp5) {
  const char str[] = "Hello world";
  const char str1[] = "world";
  my_size_t num = 5;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp6) {
  const char str[] = "HELLO WORLD";
  const char str1[] = "hello world";
  my_size_t num = 11;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp7) {
  const char str[] = " Hello world";
  const char str1[] = "Hello world";
  my_size_t num = 12;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

START_TEST(test_my_memcmp8) {
  const char str[] = "12345";
  const char str1[] = "67890";
  my_size_t num = 5;
  ck_assert_int_eq(my_memcmp(str, str1, num), memcmp(str, str1, num));
}
END_TEST

Suite *test_suite_memcmp() {
  Suite *suite = suite_create("test_my_memcmp");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_memcmp1);
  tcase_add_test(tcase, test_my_memcmp2);
  tcase_add_test(tcase, test_my_memcmp3);
  tcase_add_test(tcase, test_my_memcmp4);
  tcase_add_test(tcase, test_my_memcmp5);
  tcase_add_test(tcase, test_my_memcmp6);
  tcase_add_test(tcase, test_my_memcmp7);
  tcase_add_test(tcase, test_my_memcmp8);

  suite_add_tcase(suite, tcase);
  return suite;
}
