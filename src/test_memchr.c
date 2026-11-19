#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_memchr1) {
  char str[] = "Hello world";
  int c = ' ';
  my_size_t num = 11;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr2) {
  char str[] = "Hello world";
  int c = 'o';
  my_size_t num = strlen(str);
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr3) {
  const char str[] = "Hello world";
  int c = 'z';
  my_size_t num = strlen(str);
  ck_assert_ptr_null(my_memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr4) {
  char str[] = "aaaaaa";
  int c = 'a';
  my_size_t num = 6;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr5) {
  char str[] = "Hello world";
  int c = 'H';
  my_size_t num = 1;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr6) {
  char str[] = "Hello world";
  int c = 'l';
  my_size_t num = 3;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr7) {
  char str[] = "Hello world";
  int c = 'w';
  my_size_t num = 5;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr8) {
  char str[] = "Hello world";
  int c = ' ';
  my_size_t num = 11;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr9) {
  char str[] = "";
  int c = 'a';
  my_size_t num = 0;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr10) {
  char str[] = "Hello world";
  int c = 'd';
  my_size_t num = 11;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr11) {
  char str[] = "Hello world";
  int c = 'r';
  my_size_t num = 8;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr12) {
  char str[] = "Hello world";
  int c = 'e';
  my_size_t num = 6;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr13) {
  char str[] = "Hello world";
  int c = 'l';
  my_size_t num = 4;
  ck_assert_ptr_eq(my_memchr(str, c, num), memchr(str, c, num));
}
END_TEST

START_TEST(test_my_memchr14) {
  const char str[] = "Hello world";
  int c = 'x';
  my_size_t num = 11;
  ck_assert_ptr_null(my_memchr(str, c, num));
}
END_TEST

Suite *test_suite_memchr() {
  Suite *suite = suite_create("test_my_memchr");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_memchr1);
  tcase_add_test(tcase, test_my_memchr2);
  tcase_add_test(tcase, test_my_memchr3);
  tcase_add_test(tcase, test_my_memchr4);
  tcase_add_test(tcase, test_my_memchr5);
  tcase_add_test(tcase, test_my_memchr6);
  tcase_add_test(tcase, test_my_memchr7);
  tcase_add_test(tcase, test_my_memchr8);
  tcase_add_test(tcase, test_my_memchr9);
  tcase_add_test(tcase, test_my_memchr10);
  tcase_add_test(tcase, test_my_memchr11);
  tcase_add_test(tcase, test_my_memchr12);
  tcase_add_test(tcase, test_my_memchr13);
  tcase_add_test(tcase, test_my_memchr14);

  suite_add_tcase(suite, tcase);
  return suite;
}
