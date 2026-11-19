#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_trim1) {
  char *str = my_trim("HELLO WORLD", "HELD");
  ck_assert_str_eq(str, "O WOR");
  free(str);
}
END_TEST

START_TEST(test_my_trim2) {
  char *str = my_trim("Hello, world!", "HELD!");
  ck_assert_str_eq(str, "ello, world");
  free(str);
}
END_TEST

START_TEST(test_my_trim3) {
  char *str = my_trim(" ", " ");
  ck_assert_str_eq(str, "");
  free(str);
}
END_TEST

START_TEST(test_my_trim4) {
  char *str = my_trim("    Hello, world!   ", " ");
  ck_assert_str_eq(str, "Hello, world!");
  free(str);
}
END_TEST

START_TEST(test_my_trim5) {
  char *str = my_trim("123 456 789", "278");
  ck_assert_str_eq(str, "123 456 789");
  free(str);
}
END_TEST

Suite *test_suite_trim() {
  Suite *suite = suite_create("test_my_trim");
  TCase *tcase = tcase_create("test_my");

  tcase_add_test(tcase, test_my_trim1);
  tcase_add_test(tcase, test_my_trim2);
  tcase_add_test(tcase, test_my_trim3);
  tcase_add_test(tcase, test_my_trim4);
  tcase_add_test(tcase, test_my_trim5);

  suite_add_tcase(suite, tcase);
  return suite;
}
