#include "my_string.h"

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef __APPLE__
#define OS_MACOS
#elif defined(__linux__)
#define OS_LINUX
#endif

#if defined(OS_MACOS)
static char *macos_error_messages[] = {
    "Success",

    "Operation not permitted",

    "No such file or directory",

    "No such process",

    "Interrupted system call",

    "Input/output error",

    "Device not configured",

    "Argument list too long",

    "Exec format error",

    "Bad file descriptor",

    "No child processes",

    "Resource deadlock avoided",

    "Cannot allocate memory",

    "Permission denied",

    "Bad address",

    "Block device required",

    "Resource busy",

    "File exists",

    "Cross-device link",

    "Operation not supported by device",

    "Not a directory",

    "Is a directory",

    "Invalid argument",

    "Too many open files in system",

    "Too many open files",

    "Inappropriate ioctl for device",

    "Text file busy",

    "File too large",

    "No space left on device",

    "Illegal seek",

    "Read-only file system",

    "Too many links",

    "Broken pipe",

    "Numerical argument out of domain",

    "Result too large",

    "Resource temporarily unavailable",

    "Operation now in progress",

    "Operation already in progress",

    "Socket operation on non-socket",

    "Destination address required",

    "Message too long",

    "Protocol wrong type for socket",

    "Protocol not available",

    "Protocol not supported",

    "Socket type not supported",

    "Operation not supported",

    "Protocol family not supported",

    "Address family not supported by protocol family",

    "Address already in use",

    "Can't assign requested address",

    "Network is down",

    "Network is unreachable",

    "Network dropped connection on reset",

    "Software caused connection abort",

    "Connection reset by peer",

    "No buffer space available",

    "Socket is already connected",

    "Socket is not connected",

    "Can't send after socket shutdown",

    "Too many references: can't splice",

    "Operation timed out",

    "Connection refused",

    "Too many levels of symbolic links",

    "File name too long",

    "Host is down",

    "No route to host",

    "Directory not empty",

    "Too many processes",

    "Too many users",

    "Disc quota exceeded",

    "Stale NFS file handle",

    "Too many levels of remote in path",

    "RPC struct is bad",

    "RPC version wrong",

    "RPC prog. not avail",

    "Program version wrong",

    "Bad procedure for program",

    "No locks available",

    "Function not implemented",

    "Inappropriate file type or format",

    "Authentication error",

    "Need authenticator",

    "Device power is off",

    "Device error, e.g. paper out",

    "Value too large to be stored in data type",

    "Bad executable",

    "Bad CPU type in executable",

    "Shared library version mismatch",

    "Malformed Macho file",

    "Operation canceled",

    "Identifier removed",

    "No message of desired type",

    "Illegal byte sequence",

    "Attribute not found",

    "Bad message",

    "Reserved",

    "No message available on STREAM",

    "Reserved",

    "No STREAM resources",

    "Not a STREAM",

    "Protocol error",

    "STREAM ioctl timeout",

    "Operation not supported on socket",

    "No such policy registered",

    "State not recoverable",

    "Previous owner died",

    "Interface output queue is full"};
#endif

#if defined OS_LINUX
static char *linux_error_messages[] = {
    "Success",

    "Operation not permitted",

    "No such file or directory",

    "No such process",

    "Interrupted system call",

    "Input/output error",

    "No such device or address",

    "Argument list too long",

    "Exec format error",

    "Bad file descriptor",

    "No child processes",

    "Resource temporarily unavailable",

    "Cannot allocate memory",

    "Permission denied",

    "Bad address",

    "Block device required",

    "Device or resource busy",

    "File exists",

    "Invalid cross-device link",

    "No such device",

    "Not a directory",

    "Is a directory",

    "Invalid argument",

    "Too many open files in system",

    "Too many open files",

    "Inappropriate ioctl for device",

    "Text file busy",

    "File too large",

    "No space left on device",

    "Illegal seek",

    "Read-only file system",

    "Too many links",

    "Broken pipe",

    "Numerical argument out of domain",

    "Numerical result out of range",

    "Resource deadlock avoided",

    "File name too long",

    "No locks available",

    "Function not implemented",

    "Directory not empty",

    "Too many levels of symbolic links",

    "Unknown error 41",

    "No message of desired type",

    "Identifier removed",

    "Channel number out of range",

    "Level 2 not synchronized",

    "Level 3 halted",

    "Level 3 reset",

    "Link number out of range",

    "Protocol driver not attached",

    "No CSI structure available",

    "Level 2 halted",

    "Invalid exchange",

    "Invalid request descriptor",

    "Exchange full",

    "No anode",

    "Invalid request code",

    "Invalid slot",

    "Unknown error 58",

    "Bad font file format",

    "Device not a stream",

    "No data available",

    "Timer expired",

    "Out of streams resources",

    "Machine is not on the network",

    "Package not installed",

    "Object is remote",

    "Link has been severed",

    "Advertise error",

    "Srmount error",

    "Communication error on send",

    "Protocol error",

    "Multihop attempted",

    "RFS specific error",

    "Bad message",

    "Value too large for defined data type",

    "Name not unique on network",

    "File descriptor in bad state",

    "Remote address changed",

    "Can not access a needed shared library",

    "Accessing a corrupted shared library",

    ".lib section in a.out corrupted",

    "Attempting to link in too many shared libraries",

    "Cannot exec a shared library directly",

    "Invalid or incomplete multibyte or wide character",

    "Interrupted system call should be restarted",

    "Streams pipe error",

    "Too many users",

    "Socket operation on non-socket",

    "Destination address required",

    "Message too long",

    "Protocol wrong type for socket",

    "Protocol not available",

    "Protocol not supported",

    "Socket type not supported",

    "Operation not supported",

    "Protocol family not supported",

    "Address family not supported by protocol",

    "Address already in use",

    "Cannot assign requested address",

    "Network is down",

    "Network is unreachable",

    "Network dropped connection on reset",

    "Software caused connection abort",

    "Connection reset by peer",

    "No buffer space available",

    "Transport endpoint is already connected",

    "Transport endpoint is not connected",

    "Cannot send after transport endpoint shutdown",

    "Too many references: cannot splice",

    "Connection timed out",

    "Connection refused",

    "Host is down",

    "No route to host",

    "Operation already in progress",

    "Operation now in progress",

    "Stale file handle",

    "Structure needs cleaning",

    "Not a XENIX named type file",

    "No XENIX semaphores available",

    "Is a named type file",

    "Remote I/O error",

    "Disk quota exceeded",

    "No medium found",

    "Wrong medium type",

    "Operation canceled",

    "Required key not available",

    "Key has expired",

    "Key has been revoked",

    "Key was rejected by service",

    "Owner died",

    "State not recoverable",

    "Operation not possible due to RF-kill",

    "Memory page has hardware error"};
#endif

char *my_strerror(int errnum) {
#if defined(OS_MACOS)
  my_size_t array_size = sizeof(macos_error_messages) / sizeof(char *);
  if (errnum >= 0 && errnum < (int)array_size) {
    return macos_error_messages[errnum];
  }
  const char *str2 = "Unknown error:";
  int len = 15;
#elif defined(OS_LINUX)
  my_size_t array_size = sizeof(linux_error_messages) / sizeof(char *);
  if (errnum >= 0 && errnum < (int)array_size) {
    return linux_error_messages[errnum];
  }
  const char *str2 = "Unknown error";
  int len = 14;
#endif
  int errnum2 = errnum;
  int k = 0;
  while (errnum2 / 10 != 0) {
    errnum2 /= 10;
    ++k;
  }
  char buffer[16];
  sprintf(buffer, " %d", errnum);
  char *str = (char *)malloc(sizeof(char) * (len + 1) + sizeof(buffer));
  str[0] = '\0';
  char *res = my_strncat(str, str2, len);
  char *result = my_strncat(res, buffer, k + 2);
  result[len + k + 1] = '\0';
  return result;
}

void *my_memchr(const void *str, int c, my_size_t n) {
  const unsigned char *p = (const unsigned char *)str;
  void *result = my_NULL;
  while (n-- > 0 && result == my_NULL) {
    if (*p == (unsigned char)c) {
      result = (void *)p;
    }
    p++;
  }
  if (result == my_NULL) {
    result = my_NULL;
  }
  return result;
}

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  const unsigned char *s1 = (const unsigned char *)str1;
  const unsigned char *s2 = (const unsigned char *)str2;
  int result = 0;

  for (my_size_t i = 0; i < n && result == 0; ++i) {
    if (s1[i] != s2[i]) {
      result = (int)(s1[i] - s2[i]);
    }
  }

  return result;
}

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (const unsigned char *)src;

  for (my_size_t i = 0; i < n; ++i) {
    d[i] = s[i];
  }

  return dest;
}

void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *ptr = (unsigned char *)str;

  for (my_size_t i = 0; i < n && ptr[i] && ptr != my_NULL && (unsigned char)c;
       ++i) {
    ptr[i] = (unsigned char)c;
  }

  return str;
}

char *my_strncat(char *dest, const char *src, my_size_t n) {
  char *d = dest;
  while (*d) {
    d++;
  }

  my_size_t i = 0;
  while (i < n && src[i]) {
    *d++ = src[i++];
  }

  *d = '\0';

  return dest;
}

char *my_strchr(const char *str, int c) {
  char *result = my_NULL;
  while (*str && result == my_NULL) {
    if (*str == (char)c) {
      result = (char *)str;
    }
    str++;
  }

  if (*str == (char)c) {
    result = (char *)str;
  }
  if (result == my_NULL) {
    result = my_NULL;
  }
  return result;
}

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int result = 0;

  for (my_size_t i = 0; i < n && result == 0; ++i) {
    if (str1[i] != str2[i]) {
      result = str1[i] - str2[i];
    }
    if (str1[i] == '\0' || str2[i] == '\0') {
      result = str1[i] - str2[i];
    }
  }

  return result;
}

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_size_t i;

  for (i = 0; i < n && src[i] != '\0'; ++i) {
    dest[i] = src[i];
  }

  for (; i < n; ++i) {
    dest[i] = '\0';
  }

  return dest;
}

my_size_t my_strcspn(const char *str1, const char *str2) {
  const char *p1 = str1;
  my_size_t count = 0;

  while (*p1) {
    const char *p2 = str2;

    while (*p2 && *p1 != *p2) {
      p2++;
    }

    if (!*p2) {
      count++;
      p1++;
    } else {
      break;
    }
  }

  return count;
}

my_size_t my_strlen(const char *str) {
  const char *s = str;
  my_size_t length = 0;

  while (*s++) {
    length++;
  }

  return length;
}

char *my_strpbrk(const char *str1, const char *str2) {
  const char *p1 = str1;
  char *result = my_NULL;

  while (*p1 && result == my_NULL) {
    const char *p2 = str2;

    while (*p2) {
      if (*p1 == *p2) {
        result = (char *)p1;
      }
      p2++;
    }
    p1++;
  }

  return result;
}

char *my_strrchr(const char *str, int c) {
  const char *lastOccurrence = my_NULL;

  do {
    if (*str == (char)c) {
      lastOccurrence = str;
    }
  } while (*str++);

  return (char *)lastOccurrence;
}

char *my_strstr(const char *haystack, const char *needle) {
  const char *h = haystack;
  const char *n = needle;
  char *result = my_NULL;

  while (*h && result == my_NULL) {
    const char *tempH = h;
    const char *tempN = n;

    while (*tempH && *tempN && *tempH == *tempN) {
      tempH++;
      tempN++;
    }

    if (*tempN == '\0') {
      result = (char *)h;
    }

    h++;
  }

  return result;
}

char *my_strtok(char *str, const char *delim) {
  static char *str_saved = my_NULL;
  int error = 0;
  if (str == my_NULL) {
    str = str_saved;
  } else {
    str_saved = str;
  }
  if (str == my_NULL) {
    error++;
  }
  if (error == 0) {
    while (*str && my_strpbrk(str, delim) == str) {
      str++;
    }
    if (*str == '\0' && error == 0) {
      error++;
    }
    if (error == 0) {
      char *token_end = my_strpbrk(str, delim);
      if (token_end) {
        *token_end = '\0';
        str_saved = token_end + 1;
      } else {
        str_saved = my_NULL;
      }
    } else {
      str = my_NULL;
    }
  } else {
    str = my_NULL;
  }
  return str;
}

void *my_to_upper(const char *str) {
  my_size_t len = strlen(str);
  char *upper_str = (char *)malloc(len + 1);

  for (my_size_t i = 0; i < len; ++i) {
    upper_str[i] = toupper((unsigned char)str[i]);
  }

  upper_str[len] = '\0';

  return upper_str;
}

void *my_to_lower(const char *str) {
  my_size_t len = my_strlen(str);
  char *lower_str = malloc(len + 1);

  for (my_size_t i = 0; i < len; ++i) {
    lower_str[i] = tolower((unsigned char)str[i]);
  }

  lower_str[len] = '\0';

  return lower_str;
}

char *my_trim(const char *src, const char *trim_chars) {
  char *trimmed_str;

  if (!src) {
    trimmed_str = my_NULL;
  } else {
    my_size_t src_len = my_strlen(src);
    my_size_t start = 0;
    while (start < src_len && my_strchr(trim_chars, src[start]) != my_NULL) {
      ++start;
    }

    int end = (int)(src_len - 1);
    while (end >= (int)start && my_strchr(trim_chars, src[end]) != my_NULL) {
      --end;
    }

    my_size_t trimmed_length = (end >= (int)start) ? (end - start + 1) : 0;

    trimmed_str = malloc(trimmed_length + 1);

    my_strncpy(trimmed_str, src + start, trimmed_length);
    trimmed_str[trimmed_length] = '\0';
  }

  return trimmed_str;
}

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  my_size_t src_len = my_strlen(src);
  my_size_t str_len = my_strlen(str);

  my_size_t new_str_len = src_len + str_len;

  if (start_index > src_len) start_index = src_len;

  char *new_str = malloc(new_str_len + 1);

  my_memcpy(new_str, src, start_index);

  my_memcpy(new_str + start_index, str, str_len);

  my_memcpy(new_str + start_index + str_len, src + start_index,
             src_len - start_index);

  new_str[new_str_len] = '\0';

  return new_str;
}

// my_sprintf

#define INTTYPE(type)                \
  type value = va_arg(args, type);   \
  if (spec->h) value = (short)value; \
                                     \
  lenNumber = intToStr(value, &p, &negative);

#define UINTTYPE(type)                        \
  type value = va_arg(args, type);            \
  if (spec->h) value = (unsigned short)value; \
                                              \
  lenNumber = intToStrU(value, &p);

#define OCTTYPE(type)                         \
  type value = va_arg(args, type);            \
  if (spec->h) value = (unsigned short)value; \
                                              \
  if (value == 0 && spec->precision != 0) {   \
    *p++ = '0';                               \
  } else if (value != 0) {                    \
    while (value != 0) {                      \
      *p++ = value % 8 + '0';                 \
      value /= 8;                             \
    }                                         \
  }

#define HEXTYPE(type)                         \
  type value = va_arg(args, type);            \
  if (spec->h) value = (unsigned short)value; \
                                              \
  if (value == 0 && spec->precision != 0) {   \
    *p++ = '0';                               \
    printed = 1;                              \
  } else if (value != 0) {                    \
    printed = 1;                              \
    while (value != 0) {                      \
      if (specifier == 'x') {                 \
        *p++ = hexNumberLow[value % 16];      \
      } else if (specifier == 'X') {          \
        *p++ = hexNumberHigh[value % 16];     \
      }                                       \
                                              \
      value /= 16;                            \
    }                                         \
  }

#define DOUBLETYPE(type)                          \
  type value = va_arg(args, type);                \
                                                  \
  if (spec->precision == -1) spec->precision = 6; \
  p = doubleToStr(value, p, spec, tempStart, &negative);

#define DOUBLETYPEEXP(type)          \
  type value = va_arg(args, type);   \
                                     \
  if ((int)value == 0) {             \
    while ((int)value == 0) {        \
      value *= 10;                   \
      --exponenta;                   \
    }                                \
  } else {                           \
    while ((int)(value / 10) != 0) { \
      value /= 10;                   \
      ++exponenta;                   \
    }                                \
  }                                  \
                                     \
  p = doubleToStr(value, p, spec, tempStart, &negative);

#define DOUBLETYPESHORT(type)                                                 \
  va_list argsCopy;                                                           \
  va_copy(argsCopy, args);                                                    \
  type value = va_arg(argsCopy, type);                                        \
  va_end(argsCopy);                                                           \
  type valueStart = value;                                                    \
                                                                              \
  if ((int)value == 0) {                                                      \
    while ((int)value == 0) {                                                 \
      value *= 10;                                                            \
      --exp;                                                                  \
    }                                                                         \
  } else {                                                                    \
    while ((int)(value / 10) != 0) {                                          \
      value /= 10;                                                            \
      ++exp;                                                                  \
    }                                                                         \
  }                                                                           \
                                                                              \
  if (exp < -4 || exp >= spec->precision) {                                   \
    spec->precision =                                                         \
        min(spec->precision - exp - 1, cutNull(value, spec) - 1, spec, 1);    \
    if (spec->sharp_flag) spec->precision -= (exp - 1);                       \
                                                                              \
    p = my_print_exp(args, p, spec, registergGeE(sp));                       \
  } else {                                                                    \
    if (!spec->sharp_flag) {                                                  \
      spec->precision =                                                       \
          min(spec->precision - exp - 1, cutNull(valueStart, spec), spec, 2); \
    } else {                                                                  \
      spec->precision = spec->precision - exp - 1;                            \
    }                                                                         \
                                                                              \
    p = my_print_float(args, p, spec);                                       \
  }

int my_sprintf(char *buffer, const char *format, ...) {
  va_list args;
  va_start(args, format);
  char *p = buffer;

  while (*format) {
    if (*format == '%') {
      format++;
      my_process_format(&format, args, &p);
    } else {
      *p++ = *format;
    }

    format++;
  }

  *p = '\0';
  va_end(args);

  return p - buffer;
}

void my_process_format(const char **format, va_list args, char **p) {
  format_spec spec;
  myParseFormatSpec(format, &spec, args);

  switch (**format) {
    case 'd':
      *p = my_print_int(args, *p, &spec);
      break;
    case 'c':
      *p = my_print_char(args, *p, &spec);
      break;
    case 's':
      *p = my_print_str(args, *p, &spec);
      break;
    case 'f':
      *p = my_print_float(args, *p, &spec);
      break;
    case 'x':
      *p = my_print_hex(args, *p, &spec, 'x');
      break;
    case 'X':
      *p = my_print_hex(args, *p, &spec, 'X');
      break;
    case 'u':
      *p = my_print_ten(args, *p, &spec);
      break;
    case 'o':
      *p = my_print_oct(args, *p, &spec);
      break;
    case 'e':
      *p = my_print_exp(args, *p, &spec, 'e');
      break;
    case 'E':
      *p = my_print_exp(args, *p, &spec, 'E');
      break;
    case 'g':
      *p = my_print_shortest(args, *p, &spec, 'g');
      break;
    case 'G':
      *p = my_print_shortest(args, *p, &spec, 'G');
      break;
    case 'p':
      *p = my_print_pointer(args, *p, &spec);
      break;
    case '%':
      *p = my_print_procent(*p);
      break;
    default:
      **p = **format;
      (*p)++;
      break;
  }
}

void myParseFormatSpec(const char **format, format_spec *spec, va_list args) {
  fillStructSpec(spec);
  while (**format == '-' || **format == '+' || **format == ' ' ||
         **format == '#' || **format == '0') {
    if (**format == '-') spec->left_align = 1;
    if (**format == '+') spec->plus_flag = 1;
    if (**format == ' ') spec->space_flag = 1;
    if (**format == '#') spec->sharp_flag = 1;
    if (**format == '0') spec->zero_flag = 1;
    (*format)++;
  }

  if (**format == '*') {
    spec->width = va_arg(args, int);
    (*format)++;
  } else {
    while (**format >= '0' && **format <= '9') {
      spec->width = spec->width * 10 + (**format - '0');
      (*format)++;
    }
  }

  if (**format == '.') {
    (*format)++;
    spec->precision = 0;

    if (**format == '*') {
      spec->precision = va_arg(args, int);
      (*format)++;
    } else {
      while (**format >= '0' && **format <= '9') {
        spec->precision = spec->precision * 10 + (**format - '0');
        (*format)++;
      }
    }
  }

  while (**format == 'h' || **format == 'l' || **format == 'L') {
    if (**format == 'h') spec->h = 1;
    if (**format == 'l') spec->l = 1;
    if (**format == 'L') spec->L = 1;
    (*format)++;
  }
}

void fillStructSpec(format_spec *spec) {
  spec->left_align = 0;
  spec->space_flag = 0;
  spec->plus_flag = 0;
  spec->sharp_flag = 0;
  spec->zero_flag = 0;
  spec->width = 0;
  spec->precision = -1;
  spec->h = 0;
  spec->l = 0;
  spec->L = 0;
}

char *my_print_int(va_list args, char *p, const format_spec *spec) {
  char *tempStart = p;
  char negative = 0;
  my_size_t lenNumber = 0;

  if (spec->l) {
    INTTYPE(long)
  } else {
    INTTYPE(int)
  }
  if (lenNumber == 1 && !spec->precision) p--;

  while (spec->precision > -1 && lenNumber < (my_size_t)spec->precision) {
    *p++ = '0';
    ++lenNumber;
  }

  lenNumber += plusSpaceFlag(negative, &p, spec);
  leftAlign(&p, tempStart, lenNumber, spec);

  return p;
}

char *my_print_char(va_list args, char *p, format_spec *spec) {
  if (spec->l) {
    p = my_print_wchar(args, p, spec);
  } else {
    signed char value = (signed char)va_arg(args, int);

    if (spec->left_align && spec->width) {
      *p++ = value;

      while (spec->width > 1) {
        *p++ = ' ';
        --(spec->width);
      }
    } else {
      while (spec->width > 1) {
        *p++ = ' ';
        --(spec->width);
      }

      *p++ = value;
    }
  }

  return p;
}

char *my_print_wchar(va_list args, char *p, format_spec *spec) {
  wchar_t value = (wchar_t)va_arg(args, wchar_t);

  if (spec->left_align && spec->width) {
    char wideChar[MB_CUR_MAX];
    int len = wctomb(wideChar, value);

    for (int i = 0; len != -1 && i < len; ++i) {
      *p++ = wideChar[i];
    }

    while (spec->width > 1) {
      *p++ = ' ';
      --(spec->width);
    }
  } else {
    while (spec->width > 1) {
      *p++ = ' ';
      --(spec->width);
    }

    char wideChar[MB_CUR_MAX];
    int len = wctomb(wideChar, value);

    for (int i = 0; len != -1 && i < len; ++i) {
      *p++ = wideChar[i];
    }
  }

  return p;
}

char *my_print_str(va_list args, char *p, format_spec *spec) {
  if (spec->l) {
    p = my_print_wstr(args, p, spec);
  } else {
    const char *str = va_arg(args, char *);
    if (!str) str = "(my_NULL)";

    int i = 0;
    while (str[i]) {
      ++i;
    }
    int len = i;
    if (spec->precision != -1 && spec->precision < len) len = spec->precision;

    i = 0;
    if (spec->left_align && spec->width) {
      while ((str[i] && spec->precision == -1) ||
             (i < spec->precision && str[i])) {
        *p++ = str[i++];
      }

      while (spec->width > len) {
        *p++ = ' ';
        --(spec->width);
      }
    } else {
      while (spec->width > len) {
        *p++ = ' ';
        --(spec->width);
      }

      while ((str[i] && spec->precision == -1) ||
             (i < spec->precision && str[i])) {
        *p++ = str[i++];
      }
    }
  }

  return p;
}

char *my_print_wstr(va_list args, char *p, format_spec *spec) {
  const wchar_t *wideStr = va_arg(args, wchar_t *);
  if (!wideStr) wideStr = L"(my_NULL)";

  int i = 0;
  while (wideStr[i]) {
    ++i;
  }
  int len = i;
  if (spec->precision != -1 && spec->precision < len) len = spec->precision;

  i = 0;
  if (spec->left_align && spec->width) {
    while ((wideStr[i] && spec->precision == -1) ||
           (i < spec->precision && wideStr[i])) {
      char wideChar[MB_CUR_MAX];
      int lenght = wctomb(wideChar, *wideStr++);

      for (int j = 0; j < lenght; ++j) {
        *p++ = wideChar[j];
      }
    }

    while (spec->width > len) {
      *p++ = ' ';
      --(spec->width);
    }
  } else {
    while (spec->width > len) {
      *p++ = ' ';
      --(spec->width);
    }

    while ((wideStr[i] && spec->precision == -1) ||
           (i < spec->precision && wideStr[i])) {
      char wideChar[MB_CUR_MAX];
      int lenght = wctomb(wideChar, *wideStr++);

      for (int j = 0; j < lenght; ++j) {
        *p++ = wideChar[j];
      }
    }
  }

  return p;
}

char *my_print_float(va_list args, char *p, format_spec *spec) {
  char *tempStart = p;
  char negative = 0;

  if (spec->L) {
    DOUBLETYPE(ldouble)
  } else {
    DOUBLETYPE(double)
  }

  swapNumber(tempStart, p - 1);
  leftAlign(&p, tempStart, p - tempStart, spec);

  return p;
}

char *doubleToStr(ldouble value, char *p, const format_spec *spec, char *start,
                  char *neg) {
  unsigned long long scale = pow(10.0L, spec->precision);
  value = roundl(value * scale) / scale;
  int intPart = (int)value;
  ldouble DoublePart = value - intPart;

  intToStr(intPart, &p, neg);
  plusSpaceFlag(*neg, &p, spec);
  swapNumber(start, p - 1);

  if (spec->sharp_flag || spec->precision != 0) *p++ = '.';
  if (*neg) {
    DoublePart = -DoublePart;
    *neg = 0;
  }

  if (spec->precision != 0) {
    DoublePart *= scale;
    long intPartL = (long)(DoublePart + 0.5);
    char *tempStartDecimal = p;

    my_size_t k = intToStr(intPartL, &p, neg);
    for (my_size_t i = 0; i < spec->precision - k; ++i) *p++ = '0';
    swapNumber(tempStartDecimal, p - 1);
  }

  return p;
}

char *my_print_exp(va_list args, char *p, format_spec *spec, char specifier) {
  char *tempStart = p;
  int exponenta = 0;
  char negative = 0;
  if (spec->precision == -1) spec->precision = 6;

  if (spec->L) {
    DOUBLETYPEEXP(ldouble)
  } else {
    DOUBLETYPEEXP(double)
  }

  p = fillScientificNotation(specifier, p, exponenta);

  swapNumber(tempStart, p - 1);
  leftAlign(&p, tempStart, p - tempStart, spec);

  return p;
}

char *fillScientificNotation(char sp, char *p, int k) {
  if (sp == 'e')
    *p++ = 'e';
  else if (sp == 'E')
    *p++ = 'E';

  if (k >= 0)
    *p++ = '+';
  else
    *p++ = '-';

  if (abs(k) < 10) *p++ = '0';

  char negative = 0;
  intToStr(abs(k), &p, &negative);

  return p;
}

char *my_print_hex(va_list args, char *p, const format_spec *spec,
                    char specifier) {
  char *tempStart = p;
  const char hexNumberLow[] = "0123456789abcdef";
  const char hexNumberHigh[] = "0123456789ABCDEF";
  char printed = 0;

  if (spec->l) {
    HEXTYPE(ulong)
  } else {
    HEXTYPE(unsigned)
  }

  if (spec->sharp_flag && printed) {
    if (specifier == 'x')
      *p++ = 'x';
    else if (specifier == 'X')
      *p++ = 'X';
    *p++ = '0';
  }

  leftAlign(&p, tempStart, p - tempStart, spec);

  return p;
}

char *my_print_ten(va_list args, char *p, const format_spec *spec) {
  char *tempStart = p;
  my_size_t lenNumber = 0;

  if (spec->l) {
    UINTTYPE(ulong)
  } else {
    UINTTYPE(unsigned)
  }
  if (lenNumber == 1 && !spec->precision) p--;

  while (spec->precision > -1 && lenNumber < (my_size_t)spec->precision) {
    *p++ = '0';
    ++lenNumber;
  }

  leftAlign(&p, tempStart, lenNumber, spec);

  return p;
}

char *my_print_oct(va_list args, char *p, const format_spec *spec) {
  char *tempStart = p;

  if (spec->l) {
    OCTTYPE(ulong)
  } else {
    OCTTYPE(unsigned)
  }

  if (spec->sharp_flag) *p++ = '0';

  leftAlign(&p, tempStart, p - tempStart, spec);

  return p;
}

char *my_print_shortest(va_list args, char *p, format_spec *spec, char sp) {
  int exp = 0;
  if (spec->precision == -1) spec->precision = 6;

  if (spec->L) {
    DOUBLETYPESHORT(ldouble)
  } else {
    DOUBLETYPESHORT(double)
  }

  return p;
}

int min(int a, int b, const format_spec *spec, char fun) {
  if (b < 0) b = 0;
  if (a > spec->precision) a = spec->precision;
  if (a < 0 || (a > b && a != spec->precision)) {
    a = b;
  } else if (a == spec->precision) {
    if (fun == 1) {
      a = spec->precision - 1;
    } else if (fun == 2) {
      a = spec->precision;
    }
  }

  return a;
}

int cutNull(ldouble value, const format_spec *spec) {
  long double scale = pow(10, spec->precision);
  value = roundl(value * scale) / scale;
  value *= powl(10, spec->precision);

  long valueInt = (long)(value + 0.5);
  my_size_t countNumber = spec->precision;

  while (valueInt % 10 == 0) {
    --countNumber;
    valueInt /= 10;
  }

  return countNumber;
}

char registergGeE(char ch) {
  if (ch == 'g')
    ch = 'e';
  else if (ch == 'G')
    ch = 'E';

  return ch;
}

char *my_print_pointer(va_list args, char *p, format_spec *spec) {
  void *ptr = va_arg(args, void *);
  unsigned long address = (unsigned long)ptr;
  char *tempStart = p;

  if (address == 0) {
#if defined(OS_MACOS)
    const char *nil_str = "0x0";
#elif defined(OS_LINUX)
    const char *nil_str = "(nil)";
#endif

    while (*nil_str) {
      *p++ = *nil_str++;
    }
  } else {
    spec->precision = sizeof(address);
    const char hexDigits[] = "0123456789abcdef";
    *p++ = '0';
    *p++ = 'x';

    int start = 0;
    for (long i = sizeof(void *) * 2 - 1; i >= 0; --i) {
      unsigned char number = address >> (i * 4) & 0xF;
      if (number != 0) start = 1;

      if (start) *p++ = hexDigits[number];
    }
  }

  swapNumber(tempStart, p - 1);
  leftAlign(&p, tempStart, p - tempStart, spec);

  return p;
}

char *my_print_procent(char *p) {
  *p++ = '%';
  return p;
}

my_size_t intToStr(long value, char **p, char *neg) {
  my_size_t lenNumber = 0;

  if (value < 0) {
    value = -value;
    *neg = 1;
  }

  do {
    *(*p)++ = value % 10 + '0';
    value /= 10;
    ++lenNumber;
  } while (value > 0);

  if (*neg) {
    *(*p)++ = '-';
    lenNumber++;
  }

  return lenNumber;
}

my_size_t intToStrU(ulong value, char **p) {
  my_size_t lenNumber = 0;

  do {
    *(*p)++ = value % 10 + '0';
    value /= 10;
    ++lenNumber;
  } while (value > 0);

  return lenNumber;
}

int plusSpaceFlag(char negative, char **p, const format_spec *spec) {
  int len = 0;

  if (spec->plus_flag) {
    if (!negative) {
      *(*p)++ = '+';
      ++len;
    }
  } else if (spec->space_flag) {
    if (!negative) *(*p)++ = ' ';
    ++len;
  }

  return len;
}

void leftAlign(char **p, char *start, my_size_t len, const format_spec *spec) {
  if (spec->left_align && spec->width) {
    swapNumber(start, *p - 1);

    widthFlag(p, len, spec);
  } else {
    widthFlag(p, len, spec);

    swapNumber(start, *p - 1);
  }
}

void widthFlag(char **p, my_size_t len, const format_spec *spec) {
  char neg = 0;

  while (len < (my_size_t)spec->width) {
    if (spec->zero_flag) {
      if (*(*p - 1) == '-') {
        neg = 1;
        (*p)--;
        *(*p)++ = '0';
      } else {
        *(*p)++ = '0';
      }
    } else {
      *(*p)++ = ' ';
    }

    ++len;
  }

  if (neg) *(*p)++ = '-';
}

void swapNumber(char *start, char *end) {
  while (start < end) {
    char chTemp = *end;
    *end-- = *start;
    *start++ = chTemp;
  }
}

// my_sscanf.c

int my_sscanf(const char *p, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int count = 0;

  if (*p == '\0') count = EOF;

  while (*format) {
    if (*format == '%') {
      format++;
      count += my_process_format_scanf(&p, &format, args);
    }
    while (*p && *format == *p && *p != '%') p++;

    if (*format && *format != '%') format++;
  }

  va_end(args);

  return count;
}

int my_process_format_scanf(const char **p, const char **format,
                             va_list args) {
  int retVal = 0;
  my_scanf_doble(format);

  switch (*(*format)++) {
    case 'd':
      retVal += my_scanf_int(p, args);
      break;
    case 'c':
      retVal += my_scanf_char(p, args);
      break;
    case 'e':
    case 'E':
    case 'g':
    case 'G':
    case 'f':
      retVal += my_scanf_double(p, args);
      break;
    case 's':
      retVal += my_scanf_str(p, args);
      break;
    case 'x':
    case 'X':
      retVal += my_scanf_hex(p, args);
      break;
    case 'u':
      retVal += my_scanf_ten(p, args);
      break;
    case 'o':
      retVal += my_scanf_oct(p, args);
      break;
    case 'i':
      retVal += my_scanf_all_int(p, args);
      break;
    case 'p':
      retVal += my_scanf_pointer(p, args);
      break;
    case '%':
      retVal += my_scanf_procent(p);
      break;
    default:
      retVal = -1;
      break;
  }

  return retVal;
}

void my_scanf_doble(const char **format) {
  if (**format == 'l') (*format)++;
}

int my_scanf_int(const char **p, va_list args) {
  int *value = va_arg(args, int *);
  int number = 0, sign = 1, retVal = 0, i = 0;

  if (**p == '-') {
    sign = -1;
    (*p)++;
  }

  while (**p >= 48 && **p <= 57) {
    number = number * 10 + *(*p)++ - '0';
    i = 1;
  }

  if (i) {
    *value = number * sign;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_char(const char **p, va_list args) {
  int retVal = 0;
  signed char *value = va_arg(args, signed char *);

  signed char ch = *(*p)++;

  if (ch != '\0') {
    *value = ch;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_double(const char **p, va_list args) {
  double *value = va_arg(args, double *);
  double number = 0.0;
  int sign = 1, retVal = 0, i = 0;

  if (**p == '-') {
    sign = -1;
    (*p)++;
  }
  while (**p >= 48 && **p <= 57) {
    number = number * 10.0 + (double)(*(*p)++ - '0');
    i = 1;
  }
  (*p)++;

  double decimal = 1;
  while (**p >= 48 && **p <= 57) {
    number = number * decimal * 10 + (double)(*(*p)++ - '0');
    decimal *= 10.0;
    number /= decimal;
    i = 2;
  }
  if (**p == 'e' || **p == 'E') {
    (*p)++;
    int signPow = 0;
    if (*(*p)++ == '+')
      signPow = 1;
    else if (*(*p)++ == '-')
      signPow = -1;

    int power = 0;
    while (**p >= 48 && **p <= 57) {
      power = power * 10 + *(*p)++ - '0';
    }
    number *= pow(10, power * signPow);
  }
  if (i == 2) {
    *value = number * (double)sign;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_ten(const char **p, va_list args) {
  unsigned *value = va_arg(args, unsigned *);
  int retVal = 0, i = 0;

  unsigned number = 0;
  while (**p >= 48 && **p <= 57) {
    number = number * 10 + *(*p)++ - '0';
    i = 1;
  }
  if (i) {
    *value = number;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_oct(const char **p, va_list args) {
  int *value = va_arg(args, int *);
  int number = 0, retVal = 0, i = 0;

  if (**p == '0') (*p)++;

  while (**p >= 48 && **p <= 55) {
    number = number * 8 + *(*p)++ - '0';
    i = 1;
  }

  if (i) {
    *value = number;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_hex(const char **p, va_list args) {
  int *value = va_arg(args, int *);
  int number = 0, retVal = 0, i = 0;

  if (**p == '0' && (*(*p + 1) == 'x' || *(*p + 1) == 'X')) {
    (*p) += 2;
  }

  while ((**p >= 48 && **p <= 57) || (**p >= 65 && **p <= 70) ||
         (**p >= 97 && **p <= 102)) {
    if (**p >= 48 && **p <= 57) {
      number = number * 16 + *(*p)++ - '0';
    } else if (**p >= 65 && **p <= 70) {
      number = number * 16 + *(*p)++ - 55;
    } else if (**p >= 97 && **p <= 102) {
      number = number * 16 + *(*p)++ - 87;
    }

    i = 1;
  }
  if (i) {
    *value = number;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_all_int(const char **p, va_list args) {
  int retVal = 0;

  if (**p == '0' && *(*p + 1) != 'x' && *(*p + 1) != 'X') {
    retVal = my_scanf_oct(p, args);
  } else if (**p == '0' && (*(*p)++ == 'x' || *(*p)++ == 'X')) {
    retVal = my_scanf_hex(p, args);
  } else {
    retVal = my_scanf_int(p, args);
  }

  return retVal;
}

int my_scanf_str(const char **p, va_list args) {
  char *str = va_arg(args, char *);
  int i = 0, retVal = 0;

  while (**p != ' ' && **p != '\t' && **p != '\n' && **p != '\0') {
    *(str + i) = *(*p)++;
    ++i;
  }
  if (i) retVal = 1;

  *(str + i) = '\0';
  (*p)++;

  return retVal;
}

int my_scanf_pointer(const char **p, va_list args) {
  void **ptr = va_arg(args, void **);
  long number = 0;
  long unsigned i = 0;
  int retVal = 0;

  if (**p == '0' && (*(*p + 1) == 'x' || *(*p + 1) == 'X')) {
    (*p) += 2;
  }

  while ((**p >= 48 && **p <= 57) || (**p >= 65 && **p <= 70) ||
         (**p >= 97 && **p <= 102)) {
    if (**p >= 48 && **p <= 57) {
      number = number * 16 + *(*p)++ - '0';

    } else if (**p >= 65 && **p <= 70) {
      number = number * 16 + *(*p)++ - 55;

    } else if (**p >= 97 && **p <= 102) {
      number = number * 16 + *(*p)++ - 87;
    }

    ++i;
  }

  if (i > sizeof(void *) * 2) number = 0xffffffffffffffff;
  if (i) {
    *ptr = (void *)number;
    retVal = 1;
  }

  return retVal;
}

int my_scanf_procent(const char **p) {
  if (**p == '%') (*p)++;

  return 0;
}
