#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_sprintf1) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%+d", -123);
  my_sprintf(strTest, "%+d", -123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf2) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%+d", 123);
  my_sprintf(strTest, "%+d", 123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf3) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "% d", 123);
  my_sprintf(strTest, "% d", 123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf4) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%+f", 123.123);
  my_sprintf(strTest, "%+f", 123.123);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf5) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%15.2f", -123.666);
  my_sprintf(strTest, "%15.2f", -123.666);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf6) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%.5f", 123.666);
  my_sprintf(strTest, "%.5f", 123.666);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf7) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%.1f", 123.666);
  my_sprintf(strTest, "%.1f", 123.666);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf8) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%.0f", 123.666);
  my_sprintf(strTest, "%.0f", 123.666);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf9) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%10dab", -12345);
  my_sprintf(strTest, "%10dab", -12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf10) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%4dab", -12345);
  my_sprintf(strTest, "%4dab", -12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf11) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%10uab", 12345u);
  my_sprintf(strTest, "%10uab", 12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf12) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%3uab", 12345u);
  my_sprintf(strTest, "%3uab", 12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf13) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%3c ab", 'a');
  my_sprintf(strTest, "%3c ab", 'a');
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf14) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%4s ab", "sda");
  my_sprintf(strTest, "%4s ab", "sda");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf15) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-10dab", -12345);
  my_sprintf(strTest, "%-10dab", -12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf16) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-4dab", -12345);
  my_sprintf(strTest, "%-4dab", -12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf17) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-10uab", 12345u);
  my_sprintf(strTest, "%-10uab", 12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf18) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-3uab", 12345u);
  my_sprintf(strTest, "%-3uab", 12345);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf19) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-3c ab", 'a');
  my_sprintf(strTest, "%-3c ab", 'a');
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf20) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-4s ab", "sda");
  my_sprintf(strTest, "%-4s ab", "sda");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf21) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-2s ab", "sda");
  my_sprintf(strTest, "%-2s ab", "sda");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf22) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-3s ab", "sda");
  my_sprintf(strTest, "%-3s ab", "sda");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf23) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%12fas", 123.123);
  my_sprintf(strTest, "%12fas", 123.123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf24) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%5fas", 123.123);
  my_sprintf(strTest, "%5fas", 123.123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf25) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%+15.10da", 123123);
  my_sprintf(strTest, "a%+15.10da", 123123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf26) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%-15.10da", 123123);
  my_sprintf(strTest, "a%-15.10da", 123123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf27) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%.3da", 123456);
  my_sprintf(strTest, "a%.3da", 123456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf28) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%-.3da", 123456);
  my_sprintf(strTest, "a%-.3da", 123456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf29) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%.10da", 0);
  my_sprintf(strTest, "a%.10da", 0);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf30) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%-12fas", 123.123);
  my_sprintf(strTest, "%-12fas", 123.123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf31) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%-.10da", 0);
  my_sprintf(strTest, "a%-.10da", 0);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf32) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%.10da", 1234);
  my_sprintf(strTest, "a%.10da", 1234);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf33) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%-.10da", 1234);
  my_sprintf(strTest, "a%-.10da", 1234);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf34) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%.da", 1234);
  my_sprintf(strTest, "a%.da", 1234);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf35) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%.d", 0);
  my_sprintf(strTest, "%.d", 0);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf36) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%.5f", 123.0000159);
  my_sprintf(strTest, "%.5f", 123.0000159);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf37) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%f", 123.666);
  my_sprintf(strTest, "%f", 123.666);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf38) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%s", "Stroka1123");
  my_sprintf(strTest, "%s", "Stroka1123");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf39) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%.4s", "Stroka1123");
  my_sprintf(strTest, "%.4s", "Stroka1123");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf40) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%10.4sa", "Stroka1123");
  my_sprintf(strTest, "a%10.4sa", "Stroka1123");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf41) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%-10.4sa", "Stroka1123");
  my_sprintf(strTest, "a%-10.4sa", "Stroka1123");
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf42) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%hda", (short)32769);
  my_sprintf(strTest, "a%hda", 32769);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf43) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%hua", (unsigned short)330000u);
  my_sprintf(strTest, "a%hua", 330000);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf44) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%lda", -9223372036854775807);
  my_sprintf(strTest, "a%lda", -9223372036854775807);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf45) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%10.2ea", 123.556);
  my_sprintf(strTest, "a%10.2ea", 123.556);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf46) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%10.2ea", -123.556);
  my_sprintf(strTest, "a%10.2ea", -123.556);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf47) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a% Ea", 0.000456);
  my_sprintf(strTest, "a% Ea", 0.000456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf48) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Ea", 123.456);
  my_sprintf(strTest, "a%Ea", 123.456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf49) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Ea", 12.15151123456);
  my_sprintf(strTest, "a%Ea", 12.15151123456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf50) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Ea", 0.00000000456);
  my_sprintf(strTest, "a%Ea", 0.00000000456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf51) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%xa", 123);
  my_sprintf(strTest, "a%xa", 123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf52) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%xa", 0);
  my_sprintf(strTest, "a%xa", 0);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf54) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Xa", 123);
  my_sprintf(strTest, "a%Xa", 123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf55) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%10Xa", 255);
  my_sprintf(strTest, "a%10Xa", 255);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf56) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%oa", 123);
  my_sprintf(strTest, "a%oa", 123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf57) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%oa", 0);
  my_sprintf(strTest, "a%oa", 0);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf58) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%-10oa", 123);
  my_sprintf(strTest, "a%-10oa", 123);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf59) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%ga", 123.1);
  my_sprintf(strTest, "a%ga", 123.1);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf60) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%ga", 123.456);
  my_sprintf(strTest, "a%ga", 123.456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf61) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%ga", 0.0000123456);
  my_sprintf(strTest, "a%ga", 0.0000123456);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf62) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%ga", 123456789.0);
  my_sprintf(strTest, "a%ga", 123456789.0);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf63) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%.3ga", 123.456789);
  my_sprintf(strTest, "a%.3ga", 123.456789);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf64) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%ga", 0.001234);
  my_sprintf(strTest, "a%ga", 0.001234);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}

START_TEST(test_my_sprintf65) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Ea", 0.00001);
  my_sprintf(strTest, "a%Ea", 0.00001);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf66) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Ea", 0.00001);
  my_sprintf(strTest, "a%Ea", 0.00001);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf67) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "a%Ea", 0.00001);
  my_sprintf(strTest, "a%Ea", 0.00001);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

END_TEST
START_TEST(test_my_sprintf68) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%X", 255);
  my_sprintf(strTest, "%X", 255);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf69) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%p", (void *)0x12345678);
  my_sprintf(strTest, "%p", (void *)0x12345678);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf70) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));
  sprintf(str, "%15.2f", -123.666);
  my_sprintf(strTest, "%15.2f", -123.666);
  ck_assert_str_eq(str, strTest);
  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf71) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  sprintf(str, "%+05d", -42);
  my_sprintf(strTest, "%+05d", -42);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%#0x", 255);
  my_sprintf(strTest, "%#0x", 255);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf72) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  sprintf(str, "%.15Lf", 12345.67890123456789L);
  my_sprintf(strTest, "%.15Lf", 12345.67890123456789L);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf73) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  int a = 42;

  sprintf(str, "%p", (void *)&a);
  my_sprintf(strTest, "%p", (void *)&a);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%p", (void *)0);
  my_sprintf(strTest, "%p", (void *)0);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%20p", (void *)&a);
  my_sprintf(strTest, "%20p", (void *)&a);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf74) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  sprintf(str, "%10.2f", 123.456);
  my_sprintf(strTest, "%10.2f", 123.456);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%-.3f", -123.456789);
  my_sprintf(strTest, "%-.3f", -123.456789);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf75) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  sprintf(str, "%05X", 255);
  my_sprintf(strTest, "%05X", 255);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%5X", -255);
  my_sprintf(strTest, "%5X", -255);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf76) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  long l_value = 1234567890;
  sprintf(str, "%ld", l_value);
  my_sprintf(strTest, "%ld", l_value);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%lx", l_value);
  my_sprintf(strTest, "%lx", l_value);
  ck_assert_str_eq(str, strTest);

  sprintf(str, "%lo", l_value);
  my_sprintf(strTest, "%lo", l_value);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf77) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  long l_val = 1234567890;
  short sh_val = 12345;

  sprintf(str, "%hd + %ld", sh_val, l_val);
  my_sprintf(strTest, "%hd + %ld", sh_val, l_val);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

START_TEST(test_my_sprintf78) {
  char *strTest = malloc(1024 * sizeof(char));
  char *str = malloc(1024 * sizeof(char));

  double value3 = 1.23456789;
  sprintf(str, "%.10g", value3);
  my_sprintf(strTest, "%.10g", value3);
  ck_assert_str_eq(str, strTest);

  double value1 = 1.23456789;
  sprintf(str, "%10.4g", value1);
  my_sprintf(strTest, "%10.4g", value1);
  ck_assert_str_eq(str, strTest);

  free(strTest);
  free(str);
}
END_TEST

Suite *test_suite_sprintf() {
  Suite *suite = suite_create("test_my_sprintf");
  TCase *tcase = tcase_create("my_test");

  tcase_add_test(tcase, test_my_sprintf1);
  tcase_add_test(tcase, test_my_sprintf2);
  tcase_add_test(tcase, test_my_sprintf3);
  tcase_add_test(tcase, test_my_sprintf4);
  tcase_add_test(tcase, test_my_sprintf5);
  tcase_add_test(tcase, test_my_sprintf6);
  tcase_add_test(tcase, test_my_sprintf7);
  tcase_add_test(tcase, test_my_sprintf8);
  tcase_add_test(tcase, test_my_sprintf9);
  tcase_add_test(tcase, test_my_sprintf10);
  tcase_add_test(tcase, test_my_sprintf11);
  tcase_add_test(tcase, test_my_sprintf12);
  tcase_add_test(tcase, test_my_sprintf13);
  tcase_add_test(tcase, test_my_sprintf14);
  tcase_add_test(tcase, test_my_sprintf15);
  tcase_add_test(tcase, test_my_sprintf16);
  tcase_add_test(tcase, test_my_sprintf17);
  tcase_add_test(tcase, test_my_sprintf18);
  tcase_add_test(tcase, test_my_sprintf19);
  tcase_add_test(tcase, test_my_sprintf20);
  tcase_add_test(tcase, test_my_sprintf21);
  tcase_add_test(tcase, test_my_sprintf22);
  tcase_add_test(tcase, test_my_sprintf23);
  tcase_add_test(tcase, test_my_sprintf24);
  tcase_add_test(tcase, test_my_sprintf25);
  tcase_add_test(tcase, test_my_sprintf26);
  tcase_add_test(tcase, test_my_sprintf27);
  tcase_add_test(tcase, test_my_sprintf28);
  tcase_add_test(tcase, test_my_sprintf29);
  tcase_add_test(tcase, test_my_sprintf30);
  tcase_add_test(tcase, test_my_sprintf31);
  tcase_add_test(tcase, test_my_sprintf32);
  tcase_add_test(tcase, test_my_sprintf33);
  tcase_add_test(tcase, test_my_sprintf34);
  tcase_add_test(tcase, test_my_sprintf35);
  tcase_add_test(tcase, test_my_sprintf36);
  tcase_add_test(tcase, test_my_sprintf37);
  tcase_add_test(tcase, test_my_sprintf38);
  tcase_add_test(tcase, test_my_sprintf39);
  tcase_add_test(tcase, test_my_sprintf40);
  tcase_add_test(tcase, test_my_sprintf41);
  tcase_add_test(tcase, test_my_sprintf42);
  tcase_add_test(tcase, test_my_sprintf43);
  tcase_add_test(tcase, test_my_sprintf44);
  tcase_add_test(tcase, test_my_sprintf45);
  tcase_add_test(tcase, test_my_sprintf46);
  tcase_add_test(tcase, test_my_sprintf47);
  tcase_add_test(tcase, test_my_sprintf48);
  tcase_add_test(tcase, test_my_sprintf49);
  tcase_add_test(tcase, test_my_sprintf50);
  tcase_add_test(tcase, test_my_sprintf51);
  tcase_add_test(tcase, test_my_sprintf52);
  tcase_add_test(tcase, test_my_sprintf54);
  tcase_add_test(tcase, test_my_sprintf55);
  tcase_add_test(tcase, test_my_sprintf56);
  tcase_add_test(tcase, test_my_sprintf57);
  tcase_add_test(tcase, test_my_sprintf58);
  tcase_add_test(tcase, test_my_sprintf59);
  tcase_add_test(tcase, test_my_sprintf60);
  tcase_add_test(tcase, test_my_sprintf61);
  tcase_add_test(tcase, test_my_sprintf62);
  tcase_add_test(tcase, test_my_sprintf63);
  tcase_add_test(tcase, test_my_sprintf64);
  tcase_add_test(tcase, test_my_sprintf65);
  tcase_add_test(tcase, test_my_sprintf66);
  tcase_add_test(tcase, test_my_sprintf67);
  tcase_add_test(tcase, test_my_sprintf68);
  tcase_add_test(tcase, test_my_sprintf69);
  tcase_add_test(tcase, test_my_sprintf70);
  tcase_add_test(tcase, test_my_sprintf71);
  tcase_add_test(tcase, test_my_sprintf72);
  tcase_add_test(tcase, test_my_sprintf73);
  tcase_add_test(tcase, test_my_sprintf74);
  tcase_add_test(tcase, test_my_sprintf75);
  tcase_add_test(tcase, test_my_sprintf76);
  tcase_add_test(tcase, test_my_sprintf77);
  tcase_add_test(tcase, test_my_sprintf78);

  suite_add_tcase(suite, tcase);
  return suite;
}