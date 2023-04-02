#ifndef SRC__STRING_H_
#define SRC__STRING_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#define _NULL (void *)0
#define _size_t unsigned long long
#define LEN_STR 1000
#define LEN 100
#define BUFF_SIZE 512

void *_memchr(const void *str, int c, _size_t n);
int _memcmp(const void *str1, const void *str2, _size_t n);
void *_memcpy(void *dest, const void *src, _size_t n);
void *_memmove(void *dest, const void *src, _size_t n);
void *_memset(void *str, int c, _size_t n);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, _size_t n);
char *_strchr(const char *str, int c);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, _size_t n);
char *_strcpy(char *dest, const char *src);
char *_strncpy(char *dest, const char *src, _size_t n);
_size_t _strcspn(const char *str1, const char *str2);
_size_t _strlen(const char *str);
char *_strpbrk(const char *str1, const char *str2);
char *_strrchr(const char *str, int c);
_size_t _strspn(const char *str1, const char *str2);
char *_strstr(const char *haystack, const char *needle);
char *_strtok(char *str, const char *delim);

void *to_upper(const char *str);
void *to_lower(const char *str);
void *insert(const char *src, const char *str, _size_t start_index);
void *trim(const char *src, const char *trim_chars);

_size_t backward_strspn(const char *str1, const char *str2);

#endif  //  SRC__STRING_H_
