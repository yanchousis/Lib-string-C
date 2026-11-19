#include <locale.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#if defined(__LP64__) || defined(_WIN64)
typedef uint64_t my_size_t;
#else
typedef uint32_t my_size_t;
#endif

#ifndef my_NULL
#define my_NULL ((void *)0)
#endif

typedef long double ldouble;
typedef unsigned long ulong;

typedef struct {
  int left_align;
  int space_flag;
  int plus_flag;
  int sharp_flag;
  int zero_flag;
  int width;
  int precision;
  int h;
  int l;
  int L;
} format_spec;

char *my_strerror(int errnum);
void *my_memchr(const void *str, int c, my_size_t n);
int my_memcmp(const void *str1, const void *str2, my_size_t n);
void *my_memcpy(void *dest, const void *src, my_size_t n);
void *my_memset(void *str, int c, my_size_t n);
char *my_strncat(char *dest, const char *src, my_size_t n);
char *my_strchr(const char *str, int c);
int my_strncmp(const char *str1, const char *str2, my_size_t n);
char *my_strncpy(char *dest, const char *src, my_size_t n);
my_size_t my_strcspn(const char *str1, const char *str2);
my_size_t my_strlen(const char *str);
char *my_strpbrk(const char *str1, const char *str2);
char *my_strrchr(const char *str, int c);
char *my_strstr(const char *haystack, const char *needle);
char *my_strtok(char *str, const char *delim);

void *my_to_upper(const char *str);
void *my_to_lower(const char *str);
char *my_trim(const char *src, const char *trim_chars);
void *my_insert(const char *src, const char *str, my_size_t start_index);

int my_sprintf(char *, const char *, ...);
void my_process_format(const char **, va_list, char **);
void myParseFormatSpec(const char **, format_spec *, va_list);
void fillStructSpec(format_spec *);
char *my_print_int(va_list, char *, const format_spec *);
char *my_print_char(va_list, char *, format_spec *);
char *my_print_wchar(va_list, char *, format_spec *);
char *my_print_str(va_list, char *, format_spec *);
char *my_print_wstr(va_list, char *, format_spec *);
char *my_print_float(va_list, char *, format_spec *);
char *my_print_hex(va_list, char *, const format_spec *, char);
char *my_print_ten(va_list, char *, const format_spec *);
char *my_print_oct(va_list, char *, const format_spec *);
char *my_print_exp(va_list, char *, format_spec *, char);
char *my_print_shortest(va_list, char *, format_spec *, char);
char *my_print_pointer(va_list, char *, format_spec *);
char *my_print_procent(char *);

my_size_t intToStr(long, char **, char *);
my_size_t intToStrU(ulong, char **);
char *doubleToStr(ldouble, char *, const format_spec *, char *, char *);
char *fillScientificNotation(char, char *, int);
void swapNumber(char *, char *);
int plusSpaceFlag(char, char **, const format_spec *);
void leftAlign(char **, char *, my_size_t, const format_spec *);
void widthFlag(char **, my_size_t, const format_spec *);
char registergGeE(char);
int cutNull(ldouble, const format_spec *);
int min(int, int, const format_spec *, char);

int my_sscanf(const char *, const char *, ...);
int my_process_format_scanf(const char **, const char **, va_list);
void my_scanf_doble(const char **);
int my_scanf_int(const char **, va_list);
int my_scanf_char(const char **, va_list);
int my_scanf_double(const char **, va_list);
int my_scanf_ten(const char **, va_list);
int my_scanf_oct(const char **, va_list);
int my_scanf_hex(const char **, va_list);
int my_scanf_all_int(const char **, va_list);
int my_scanf_str(const char **, va_list);
int my_scanf_pointer(const char **, va_list);
int my_scanf_procent(const char **);
