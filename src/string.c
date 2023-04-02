#include "_string.h"

void *_memchr(const void *str, int c, _size_t n) {
  char *result = _NULL;
  char *p = (char *)str;
  for (_size_t i = 0; i < n; i++) {
    if (*p == (char)c) {
      result = p;
      break;
    }
    p++;
  }
  return (void *)result;
}

int _memcmp(const void *str1, const void *str2, _size_t n) {
  int result = 0;
  char *p = (char *)str1;
  char *q = (char *)str2;
  while (n-- && result == 0) {
    result = *p - *q;
    p++;
    q++;
  }
  return result;
}

void *_memcpy(void *dest, const void *src, _size_t n) {
  char *p = (char *)dest;
  char *q = (char *)src;
  for (_size_t i = 0; i < n; i++) {
    *p = *q;
    p++;
    q++;
  }
  return (void *)dest;
}

void *_memmove(void *dest, const void *src, _size_t n) {
  char *p = (char *)dest;
  char *q = (char *)src;
  if (p < q) {
    while (n != 0) {
      *p++ = *q++;
      n--;
    }
  } else {
    char *q_new = q + (n - 1);
    char *p_new = p + (n - 1);
    while (n != 0) {
      *p_new-- = *q_new--;
      n--;
    }
  }
  return (void *)dest;
}

void *_memset(void *str, int c, _size_t n) {
  char *p = (char *)str;
  for (_size_t i = 0; i < n; i++) {
    *p = c;
    p++;
  }
  return (void *)str;
}

char *_strcat(char *dest, const char *src) {
  _size_t n = _strlen(dest);
  _size_t i = 0;
  for (; src[i] != '\0'; i++) {
    dest[n + i] = src[i];
  }
  dest[n + i] = '\0';
  return dest;
}

char *_strncat(char *dest, const char *src, _size_t n) {
  char *result;
  result = dest;
  while (*dest) {
    dest++;
  }
  while (*src && n != 0) {
    *dest++ = *src++;
    n--;
  }
  *dest = '\0';
  return result;
}

char *_strchr(const char *str, int c) {
  while (*str != c && *str) {
    str += 1;
  }
  return (char *)((*str == c) ? str : 0);
}

int _strcmp(const char *str1, const char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  return *str1 - *str2;
}

int _strncmp(const char *str1, const char *str2, _size_t n) {
  int result = 0;
  n--;
  while (!(result = *str1 - *str2) && *str2 && n) {
    str1++;
    str2++;
    n--;
  }
  return result;
}

char *_strcpy(char *dest, const char *src) {
  char *result = dest;
  if (src != _NULL) {
    while ((*dest++ = *src++) != '\0') {
    }
    *dest = '\0';
  }
  return result;
}

char *_strncpy(char *dest, const char *src, _size_t n) {
  for (_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

_size_t _strcspn(const char *str1, const char *str2) {
  _size_t length = 0;
  int flag = 0;
  for (_size_t i = 0; i < _strlen(str1); i++) {
    for (_size_t j = 0; j < _strlen(str2); j++) {
      if (str2[j] == str1[i]) {
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    } else {
      length++;
    }
  }
  return length;
}

_size_t _strlen(const char *str) {
  _size_t length = 0;
  if (str != _NULL) {
    while (*str++) {
      length++;
    }
  }
  return length;
}

char *_strpbrk(const char *str1, const char *str2) {
  char *result = _NULL;
  int stop = 0;
  for (_size_t i = 0; str1[i] != '\0'; i++) {
    for (_size_t j = 0; str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        result = (char *)&str1[i];
        stop = 1;
        break;
      }
    }
    if (stop) {
      break;
    }
  }
  return result;
}

char *_strrchr(const char *str, int c) {
  char *result = _NULL;
  char *start = (char *)str;
  while (*str++) {
  }
  while (--str != start && *str != (char)c) {
  }
  if (*str == (char)c) {
    result = (char *)str;
  }
  return result;
}

_size_t _strspn(const char *str1, const char *str2) {
  _size_t result = 0;
  for (int i = 0; str1[i]; i++) {
    _size_t match = 0;
    for (int j = 0; str2[j]; j++) {
      if (str1[i] == str2[j]) {
        match++;
        break;
      }
    }
    if (match) {
      result++;
    } else {
      break;
    }
  }
  return result;
}

char *_strstr(const char *haystack, const char *needle) {
  char *result = _NULL;
  int flag = 0;
  while (*haystack && flag == 0) {
    const char *tmp_1 = needle;
    const char *tmp_2 = haystack;
    if (_strlen(needle) != 0) {
      while (*tmp_1 && *haystack == *tmp_1) {
        haystack++;
        tmp_1++;
        flag = 1;
      }
      if (!*tmp_1) {
        result = (char *)(haystack - (tmp_1 - needle));
      }
    } else {
      result = (char *)tmp_2;
      break;
    }
    haystack++;
  }
  return result;
}

char *_strtok(char *str, const char *delim) {
  static char *mem;
  register int ch;
  if (!str) {
    str = mem;
  }
  do {
    if ((ch = *str++) == '\0') {
      str = _NULL;
      break;
    }
  } while (_strchr(delim, ch));
  if (str) {
    --str;
    mem = str + _strcspn(str, delim);
    if (*mem != 0) {
      *mem++ = 0;
    }
  }
  return str;
}
