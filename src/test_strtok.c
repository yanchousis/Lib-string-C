#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_strtok1) {
  char str[100] = "Hello, hello, world!";
  char str1[100] = "Hello, hello, world!";
  const char *delim = " ,!";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_pstr_eq(token, token1);
  while (token != NULL && token1 != NULL) {
    token = my_strtok(NULL, delim);
    token1 = strtok(NULL, delim);
    ck_assert_pstr_eq(token, token1);
  }
}
END_TEST

START_TEST(test_my_strtok2) {
  char str[100] = "Hello, hello, world!";
  char str1[100] = "Hello, hello, world!";
  const char *delim = "";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_pstr_eq(token, token1);
  while (token != NULL && token1 != NULL) {
    token = my_strtok(NULL, delim);
    token1 = strtok(NULL, delim);
    ck_assert_pstr_eq(token, token1);
  }
}
END_TEST

START_TEST(test_my_strtok3) {
  char str[100] = "Hello,,, hello,,, world!!";
  char str1[100] = "Hello,,, hello,,, world!!";
  const char *delim = " ,!";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_pstr_eq(token, token1);
  while (token != NULL && token1 != NULL) {
    token = my_strtok(NULL, delim);
    token1 = strtok(NULL, delim);
    ck_assert_pstr_eq(token, token1);
  }
}
END_TEST

START_TEST(test_my_strtok4) {
  char str[100] = " ,!";
  char str1[100] = " ,!";
  const char *delim = " ,!";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_ptr_eq(token, token1);
  ck_assert_ptr_null(token);
}
END_TEST

START_TEST(test_my_strtok5) {
  char str[100] = "";
  char str1[100] = "";
  const char *delim = " ,!";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_ptr_eq(token, token1);
  ck_assert_ptr_null(token);
}
END_TEST

START_TEST(test_my_strtok6) {
  char str[100] = "Hello world";
  char str1[100] = "Hello world";
  const char *delim = ",";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_pstr_eq(token, token1);
  while (token != NULL && token1 != NULL) {
    token = my_strtok(NULL, delim);
    token1 = strtok(NULL, delim);
    ck_assert_pstr_eq(token, token1);
  }
}
END_TEST

START_TEST(test_my_strtok7) {
  char str[100] = "Hello, world!";
  char str1[100] = "Hello, world!";
  const char *delim = "., ! ,.!!";
  char *token = my_strtok(str, delim);
  char *token1 = strtok(str1, delim);
  ck_assert_pstr_eq(token, token1);
  while (token != NULL && token1 != NULL) {
    token = my_strtok(NULL, delim);
    token1 = strtok(NULL, delim);
    ck_assert_pstr_eq(token, token1);
  }
}
END_TEST

Suite *test_suite_strtok() {
  Suite *suite = suite_create("test_my_strtok");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_strtok1);
  tcase_add_test(tcase, test_my_strtok2);
  tcase_add_test(tcase, test_my_strtok3);
  tcase_add_test(tcase, test_my_strtok4);
  tcase_add_test(tcase, test_my_strtok5);
  tcase_add_test(tcase, test_my_strtok6);
  tcase_add_test(tcase, test_my_strtok7);

  suite_add_tcase(suite, tcase);
  return suite;
}
