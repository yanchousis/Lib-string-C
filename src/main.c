#include <check.h>
#include <stdio.h>
#include <string.h>

#include "my_string.h"

Suite *test_suite_strstr();
Suite *test_suite_strerror();
Suite *test_suite_strrchr();
Suite *test_suite_strpbrk();
Suite *test_suite_strlen();
Suite *test_suite_strcspn();
Suite *test_suite_strncpy();
Suite *test_suite_strncmp();
Suite *test_suite_strchr();
Suite *test_suite_strncat();
Suite *test_suite_memcpy();
Suite *test_suite_memset();
Suite *test_suite_memchr();
Suite *test_suite_memcmp();
Suite *test_suite_to_upper();
Suite *test_suite_to_lower();
Suite *test_suite_trim();
Suite *test_suite_insert();
Suite *test_suite_strtok();
Suite *test_suite_sprintf();
Suite *my_sscanf_suite();
int main(void) {
  SRunner *sr = srunner_create(suite_create("All Tests"));
  srunner_add_suite(sr, test_suite_strstr());
  srunner_add_suite(sr, test_suite_strerror());
  srunner_add_suite(sr, test_suite_strrchr());
  srunner_add_suite(sr, test_suite_strpbrk());
  srunner_add_suite(sr, test_suite_strlen());
  srunner_add_suite(sr, test_suite_strcspn());
  srunner_add_suite(sr, test_suite_strncpy());
  srunner_add_suite(sr, test_suite_strncmp());
  srunner_add_suite(sr, test_suite_strchr());
  srunner_add_suite(sr, test_suite_strncat());
  srunner_add_suite(sr, test_suite_memcpy());
  srunner_add_suite(sr, test_suite_memset());
  srunner_add_suite(sr, test_suite_memchr());
  srunner_add_suite(sr, test_suite_memcmp());
  srunner_add_suite(sr, test_suite_to_upper());
  srunner_add_suite(sr, test_suite_to_lower());
  srunner_add_suite(sr, test_suite_trim());
  srunner_add_suite(sr, test_suite_insert());
  srunner_add_suite(sr, test_suite_strtok());
  srunner_add_suite(sr, test_suite_sprintf());
  srunner_add_suite(sr, my_sscanf_suite());
  srunner_run_all(sr, CK_ENV);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
