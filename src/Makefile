CC := gcc
CFLAGS := -std=c11 -Wall -Werror -Wextra

LIB_NAME := my_string.a
FILESTEST := main.c test_strstr.c test_strerror.c test_strrchr.c test_strpbrk.c test_strlen.c test_strcspn.c test_strncpy.c test_strncmp.c test_strchr.c test_strncat.c test_memcpy.c test_memchr.c test_memcmp.c test_memset.c test_to_lower.c test_to_upper.c test_trim.c test_insert.c test_strtok.c test_sprintf.c test_sscanf.c
LDFLAGS = -lm

UNAME := $(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS += -lcheck -lsubunit
	OPEN=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS += $(shell pkg-config --libs check)
	OPEN=open
endif

all: $(LIB_NAME)

$(LIB_NAME): clean
	$(CC) -c -o my_string.o my_string.c
	ar rcs $(LIB_NAME) my_string.o

test: $(LIB_NAME)
	$(CC) $(CFLAGS) $(FILESTEST) -L. $(LIB_NAME) $(LDFLAGS) -o main
	./main

gcov_report:
	$(CC) $(CFLAGS) $(FILESTEST) my_string.c -fprofile-arcs -ftest-coverage $(LDFLAGS) -o main
	./main

	gcov main-my_string.c
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info --output-file coverage_filtered.info
	genhtml coverage_filtered.info --output-directory out

	$(OPEN) out/index.html
	echo "Отчет доступен в директории out"

clean:
	rm -rf main
	rm -rf *.gcda *.gcno *.gcov *.info *.a *.o
	rm -rf out
	rm -f *.txt

rebuild: clean all
