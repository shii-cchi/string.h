#include "_string.h"

void *to_upper(const char *str) {
  char *result;
  result = _NULL;
  if (str != _NULL) {
    _size_t length = _strlen(str);
    result = calloc(length + 1, sizeof(char));
    if (result != _NULL) {
      for (_size_t i = 0; i < length + 1; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
          result[i] = str[i] - 32;
        } else {
          result[i] = str[i];
        }
      }
      result[length] = '\0';
    }
  }
  return (void *)result;
}

void *to_lower(const char *str) {
  char *lower;
  lower = _NULL;
  if (str != _NULL) {
    _size_t length = _strlen(str);
    lower = calloc(length + 1, sizeof(char));
    if (lower != _NULL) {
      for (_size_t i = 0; i < length + 1; i++) {
        if (str[i] > 64 && str[i] < 91) {
          lower[i] = str[i] + 32;
        } else {
          lower[i] = str[i];
        }
      }
      lower[length] = '\0';
    }
  }
  return (void *)lower;
}

void *insert(const char *src, const char *str, _size_t start_index) {
  char *result = _NULL;
  if (src != _NULL && str != _NULL && _strlen(src) >= start_index) {
    _size_t length_str = _strlen(str);
    _size_t length_result = _strlen(src) + length_str;
    result = calloc(length_result + 1, sizeof(char));
    if (result != _NULL) {
      _size_t index = 0;
      while (index != length_result) {
        if (index < start_index) {
          result[index] = src[index];
        } else if (index < start_index + length_str) {
          result[index] = str[index - start_index];
        } else {
          result[index] = src[index - length_str];
        }
        index++;
      }
      result[length_result] = '\0';
    }
  }
  return (void *)result;
}

void *trim(const char *src, const char *trim_chars) {
  char *result = _NULL;
  if (src != _NULL && trim_chars != _NULL) {
    result = calloc(_strlen(src) + 1, sizeof(char));
    if (result != _NULL) {
      for (int j = _strspn(src, trim_chars), i = 0; i < (int)_strlen(src);
           i++, j++) {
        result[i] = src[j];
      }
      result[_strlen(src)] = '\0';
      result[_strlen(result) - backward_strspn(result, trim_chars)] = '\0';
    }
  }
  return result;
}

_size_t backward_strspn(const char *str1, const char *str2) {
  _size_t result = 0;
  for (int i = _strlen(str1) - 1; i >= 0; i--) {
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
