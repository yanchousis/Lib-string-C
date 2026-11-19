#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_sscanf_int) {
  int num1, num2;
  const char *input = "42";
  const char *format = "%d";

  int result1 = my_sscanf(input, format, &num1);
  int result2 = sscanf(input, format, &num2);

  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_my_sscanf_two_ints) {
  int num1a, num1b, num2a, num2b;
  const char *input = "123 456";
  const char *format = "%d %d";

  int result1 = my_sscanf(input, format, &num1a, &num1b);
  int result2 = sscanf(input, format, &num2a, &num2b);

  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num1a, num2a);
  ck_assert_int_eq(num1b, num2b);
}
END_TEST

START_TEST(test_my_sscanf_string) {
  char str1[100], str2[100];
  const char *input = "Hello, world!";
  const char *format = "%s";

  int result1 = my_sscanf(input, format, str1);
  int result2 = sscanf(input, format, str2);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sscanf_mixed_format) {
  int num1, num2;
  const char *input = "The answer is 42";
  const char *format = "The answer is %d";

  int result1 = my_sscanf(input, format, &num1);
  int result2 = sscanf(input, format, &num2);

  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num1, num2);
}
END_TEST

START_TEST(test_my_sscanf_float) {
  double num1, num2;
  const char *input = "3.14";
  const char *format = "%lf";

  int result1 = my_sscanf(input, format, &num1);
  int result2 = sscanf(input, format, &num2);

  ck_assert_int_eq(result1, result2);
  ck_assert_double_eq_tol(num1, num2, 1e-6);
}
END_TEST

START_TEST(test_my_sscanf_char) {
  char ch1, ch2;
  const char *input = "A";
  const char *format = "%c";

  int result1 = my_sscanf(input, format, &ch1);
  int result2 = sscanf(input, format, &ch2);

  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(ch1, ch2);
}
END_TEST

START_TEST(test_my_sscanf_space_separated_string) {
  char str1[100], str2[100];
  const char *input = "Hello world!";
  const char *format = "%s";

  int result1 = my_sscanf(input, format, str1);
  int result2 = sscanf(input, format, str2);

  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sscanf_unsigned_int) {
  unsigned int num1, num2;
  const char *input = "4294967295";
  const char *format = "%u";

  int result1 = my_sscanf(input, format, &num1);
  int result2 = sscanf(input, format, &num2);

  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num1, num2);
}
END_TEST

START_TEST(test_octal_specifier) {
  const char buffer[] = "123";
  int result;
  int expected = 83;

  ck_assert_int_eq(my_sscanf(buffer, "%o", &result), 1);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_integer_specifier) {
  const char buffer[] = "-12345";
  int result;
  int expected = -12345;

  ck_assert_int_eq(my_sscanf(buffer, "%i", &result), 1);
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_pointer_specifier) {
  void *ptr = malloc(100);
  char buffer[32];
  snprintf(buffer, sizeof(buffer), "%p", ptr);
  void *result;

  ck_assert_int_eq(my_sscanf(buffer, "%p", &result), 1);
  ck_assert_ptr_eq(ptr, result);

  free(ptr);
}
END_TEST

START_TEST(test_percent_specifier) {
  const char buffer[] = "%%";

  ck_assert_int_eq(my_sscanf(buffer, "%%"), 0);
}
END_TEST

START_TEST(test_hexadecimal_specifier) {
  const char buffer[] = "0xFF";
  unsigned int result;
  unsigned int expected = 255;

  ck_assert_int_eq(my_sscanf(buffer, "%x", &result), 1);
  ck_assert_uint_eq(result, expected);
}
END_TEST

Suite *my_sscanf_suite(void) {
  Suite *suite = suite_create("test_my_sscanf");

  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_my_sscanf_int);
  tcase_add_test(tc_core, test_my_sscanf_two_ints);
  tcase_add_test(tc_core, test_my_sscanf_string);
  tcase_add_test(tc_core, test_my_sscanf_mixed_format);
  tcase_add_test(tc_core, test_my_sscanf_float);
  tcase_add_test(tc_core, test_my_sscanf_int);
  tcase_add_test(tc_core, test_my_sscanf_two_ints);
  tcase_add_test(tc_core, test_my_sscanf_mixed_format);
  tcase_add_test(tc_core, test_my_sscanf_char);
  tcase_add_test(tc_core, test_my_sscanf_space_separated_string);
  tcase_add_test(tc_core, test_my_sscanf_unsigned_int);
  tcase_add_test(tc_core, test_octal_specifier);
  tcase_add_test(tc_core, test_integer_specifier);
  tcase_add_test(tc_core, test_pointer_specifier);
  tcase_add_test(tc_core, test_percent_specifier);
  tcase_add_test(tc_core, test_hexadecimal_specifier);
  suite_add_tcase(suite, tc_core);

  return suite;
}
