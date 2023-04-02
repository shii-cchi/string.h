#include <check.h>
#include <string.h>

#include "../_string.h"

START_TEST(memchr_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "d";
  char str_4[LEN] = "\0";
  ck_assert_ptr_eq(memchr(str_1, 'd', 2), _memchr(str_1, 'd', 2));
  ck_assert_ptr_eq(memchr(str_1, 'd', 4), _memchr(str_1, 'd', 4));
  ck_assert_ptr_eq(memchr(str_1, 'd', 5), _memchr(str_1, 'd', 5));
  ck_assert_ptr_eq(memchr(str_1, 'o', 2), _memchr(str_1, 'o', 2));
  ck_assert_ptr_eq(memchr(str_2, 'd', 5), _memchr(str_2, 'd', 5));
  ck_assert_ptr_eq(memchr(str_3, 'd', 1), _memchr(str_3, 'd', 1));
  ck_assert_ptr_eq(memchr(str_3, 'd', 2), _memchr(str_3, 'd', 2));
  ck_assert_ptr_eq(memchr(str_4, 'd', 2), _memchr(str_4, 'd', 2));
}
END_TEST

START_TEST(memcmp_test) {
  char *str_1 = "abcdddefg";
  char *str_2 = "abcd\0ddefg";
  char *str_3 = "abcdddefg\0";
  char *str_4 = "";
  char *str_5 = "";
  char *str_6 = "a";
  ck_assert_int_eq(memcmp(str_1, str_2, 2), _memcmp(str_1, str_2, 2));
  ck_assert_int_eq(memcmp(str_1, str_2, 5), _memcmp(str_1, str_2, 5));
  ck_assert_int_eq(memcmp(str_1, str_2, 10), _memcmp(str_1, str_2, 10));
  ck_assert_int_eq(memcmp(str_1, str_3, 5), _memcmp(str_1, str_3, 5));
  ck_assert_int_eq(memcmp(str_1, str_3, 10), _memcmp(str_1, str_3, 10));
  ck_assert_int_eq(memcmp(str_1, str_4, 10), _memcmp(str_1, str_4, 10));
  ck_assert_int_eq(memcmp(str_1, str_6, 1), _memcmp(str_1, str_6, 1));
  ck_assert_int_eq(memcmp(str_1, str_6, 10), _memcmp(str_1, str_6, 10));
  ck_assert_int_eq(memcmp(str_3, str_5, 56), _memcmp(str_3, str_5, 56));
  ck_assert_int_eq(memcmp(str_4, str_5, 1), _memcmp(str_4, str_5, 1));
}
END_TEST

START_TEST(memcpy_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "\0";
  char str_4[LEN] = "";
  char str_5[LEN] = "abs";
  char str_6[LEN] = "abs";
  char str_7[LEN] = "a";
  ck_assert_ptr_eq(memcpy(str_4, str_1, 2), _memcpy(str_4, str_1, 2));
  ck_assert_ptr_eq(memcpy(str_4, str_1, 100), _memcpy(str_4, str_1, 100));
  ck_assert_ptr_eq(memcpy(str_4, str_1, 0), _memcpy(str_4, str_1, 0));
  ck_assert_ptr_eq(memcpy(str_4, str_2, 6), _memcpy(str_4, str_2, 6));
  ck_assert_ptr_eq(memcpy(str_4, str_3, 2), _memcpy(str_4, str_3, 2));
  ck_assert_ptr_eq(memcpy(str_5, str_1, 3), _memcpy(str_5, str_1, 3));
  ck_assert_ptr_eq(memcpy(str_5, str_6, 3), _memcpy(str_5, str_6, 3));
  ck_assert_ptr_eq(memcpy(str_4, str_7, 3), _memcpy(str_4, str_7, 3));
  ck_assert_ptr_eq(memcpy(str_3, str_7, 3), _memcpy(str_3, str_7, 3));
  ck_assert_ptr_eq(memcpy(str_2, str_7, 3), _memcpy(str_2, str_7, 3));
}
END_TEST

START_TEST(memmove_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "\0";
  char str_4[LEN] = "";
  char str_5[LEN] = "abs";
  char str_6[LEN] = "abs";
  char str_7[LEN] = "a";
  ck_assert_ptr_eq(memmove(str_4, str_1, 2), _memmove(str_4, str_1, 2));
  ck_assert_ptr_eq(memmove(str_4, str_1, 100), _memmove(str_4, str_1, 100));
  ck_assert_ptr_eq(memmove(str_4, str_1, 0), _memmove(str_4, str_1, 0));
  ck_assert_ptr_eq(memmove(str_4, str_2, 6), _memmove(str_4, str_2, 6));
  ck_assert_ptr_eq(memmove(str_4, str_3, 2), _memmove(str_4, str_3, 2));
  ck_assert_ptr_eq(memmove(str_5, str_1, 3), _memmove(str_5, str_1, 3));
  ck_assert_ptr_eq(memmove(str_5, str_6, 3), _memmove(str_5, str_6, 3));
  ck_assert_ptr_eq(memmove(str_4, str_7, 3), _memmove(str_4, str_7, 3));
  ck_assert_ptr_eq(memmove(str_3, str_7, 3), _memmove(str_3, str_7, 3));
  ck_assert_ptr_eq(memmove(str_2, str_7, 3), _memmove(str_2, str_7, 3));
}
END_TEST

START_TEST(memset_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "a";
  char str_4[LEN] = "\0";
  ck_assert_ptr_eq(memset(str_1, 'a', 2), _memset(str_1, 'a', 2));
  ck_assert_ptr_eq(memset(str_1, 'a', 100), _memset(str_1, 'a', 100));
  ck_assert_ptr_eq(memset(str_2, 'a', 6), _memset(str_2, 'a', 6));
  ck_assert_ptr_eq(memset(str_3, 'a', 6), _memset(str_3, 'a', 6));
  ck_assert_ptr_eq(memset(str_4, 'a', 2), _memset(str_4, 'a', 2));
}
END_TEST

START_TEST(strcat_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd";
  char str_3[LEN] = "abcd\0ddefg";
  char str_4[LEN] = "a";
  char str_5[LEN] = "\0";
  char str_1_1[LEN] = "abcdddefg";
  ck_assert_str_eq(strcat(str_1, str_2), _strcat(str_1_1, str_2));
  ck_assert_str_eq(strcat(str_1, str_3), _strcat(str_1_1, str_3));
  ck_assert_str_eq(strcat(str_1, str_4), _strcat(str_1_1, str_4));
  ck_assert_str_eq(strcat(str_1, str_5), _strcat(str_1_1, str_5));
}
END_TEST

START_TEST(strncat_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd";
  char str_3[LEN] = "abcd\0ddefg";
  char str_4[LEN] = "a";
  char str_5[LEN] = "\0";
  char str_1_1[LEN] = "abcdddefg";
  ck_assert_str_eq(strncat(str_1, str_2, 2), _strncat(str_1_1, str_2, 2));
  ck_assert_str_eq(strncat(str_1, str_2, 5), _strncat(str_1_1, str_2, 5));
  ck_assert_str_eq(strncat(str_1, str_3, 2), _strncat(str_1_1, str_3, 2));
  ck_assert_str_eq(strncat(str_1, str_3, 10), _strncat(str_1_1, str_3, 10));
  ck_assert_str_eq(strncat(str_1, str_4, 10), _strncat(str_1_1, str_4, 10));
  ck_assert_str_eq(strncat(str_1, str_5, 5), _strncat(str_1_1, str_5, 5));
}
END_TEST

START_TEST(strchr_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcdd\0defg";
  char str_3[LEN] = "a";
  char str_4[LEN] = "\0";
  ck_assert_pstr_eq(strchr(str_1, 'd'), _strchr(str_1, 'd'));
  ck_assert_pstr_eq(strchr(str_1, 'g'), _strchr(str_1, 'g'));
  ck_assert_pstr_eq(strchr(str_1, 'n'), _strchr(str_1, 'n'));
  ck_assert_pstr_eq(strchr(str_1, '\0'), _strchr(str_1, '\0'));
  ck_assert_pstr_eq(strchr(str_2, 'd'), _strchr(str_2, 'd'));
  ck_assert_pstr_eq(strchr(str_2, 'g'), _strchr(str_2, 'g'));
  ck_assert_pstr_eq(strchr(str_2, '\0'), _strchr(str_2, '\0'));
  ck_assert_pstr_eq(strchr(str_3, 'a'), _strchr(str_3, 'a'));
  ck_assert_pstr_eq(strchr(str_3, 'g'), _strchr(str_3, 'g'));
  ck_assert_pstr_eq(strchr(str_4, 'a'), _strchr(str_4, 'a'));
  ck_assert_pstr_eq(strchr(str_4, 'g'), _strchr(str_4, 'g'));
  ck_assert_pstr_eq(strchr(str_4, '\0'), _strchr(str_4, '\0'));
}
END_TEST

START_TEST(strcmp_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcdddefg";
  char str_3[LEN] = "a";
  char str_4[LEN] = "abcd\0ddefg";
  char str_5[LEN] = "\0";
  char str_6[LEN] = "\0";
  int res = 0, res_1 = 0;
  res = strcmp(str_1, str_2);
  res_1 = _strcmp(str_1, str_2);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strcmp(str_1, str_3);
  res_1 = _strcmp(str_1, str_3);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strcmp(str_1, str_4);
  res_1 = _strcmp(str_1, str_4);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strcmp(str_1, str_5);
  res_1 = _strcmp(str_1, str_5);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strcmp(str_5, str_6);
  res_1 = _strcmp(str_5, str_6);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strcmp(str_3, str_5);
  res_1 = _strcmp(str_3, str_5);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strcmp(str_4, str_6);
  res_1 = _strcmp(str_4, str_6);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
}
END_TEST

START_TEST(strncmp_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcdddefg";
  char str_3[LEN] = "a";
  char str_4[LEN] = "abcd\0ddefg";
  char str_5[LEN] = "\0";
  char str_6[LEN] = "\0";
  int res = 0, res_1 = 0;
  res = strncmp(str_1, str_2, 2);
  res_1 = _strncmp(str_1, str_2, 2);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_2, 4);
  res_1 = _strncmp(str_1, str_2, 4);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_2, 10);
  res_1 = _strncmp(str_1, str_2, 10);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_3, 1);
  res_1 = _strncmp(str_1, str_3, 1);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_3, 10);
  res_1 = _strncmp(str_1, str_3, 10);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_4, 2);
  res_1 = _strncmp(str_1, str_4, 2);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_4, 5);
  res_1 = _strncmp(str_1, str_4, 5);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_4, 10);
  res_1 = _strncmp(str_1, str_4, 10);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_5, 2);
  res_1 = _strncmp(str_1, str_5, 2);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_1, str_5, 5);
  res_1 = _strncmp(str_1, str_5, 5);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_5, str_6, 1);
  res_1 = _strncmp(str_5, str_6, 1);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_5, str_6, 10);
  res_1 = _strncmp(str_5, str_6, 10);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_3, str_5, 1);
  res_1 = _strncmp(str_3, str_5, 1);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
  res = strncmp(str_4, str_6, 1);
  res_1 = _strncmp(str_4, str_6, 1);
  if (res > 1) res = 1;
  if (res_1 > 1) res_1 = 1;
  if (res < -1) res = -1;
  if (res_1 < -1) res_1 = -1;
  ck_assert_int_eq(res, res_1);
}
END_TEST

START_TEST(strcpy_test) {
  char str_1[LEN] = "abcdddefg";
  char str_1_1[LEN] = "abcdddefg";
  char str_2[LEN] = "a";
  char str_2_1[LEN] = "a";
  char str_3[LEN] = "abcd\0ddefg";
  char str_3_1[LEN] = "abcd\0ddefg";
  char str_4[LEN] = "\0";
  char str_5[LEN] = "\0";
  char str_6[LEN] = "\0";
  ck_assert_str_eq(strcpy(str_1, str_2), _strcpy(str_1_1, str_2));
  ck_assert_str_eq(strcpy(str_2, str_1), _strcpy(str_2_1, str_1));
  ck_assert_str_eq(strcpy(str_1, str_3), _strcpy(str_1_1, str_3));
  ck_assert_str_eq(strcpy(str_3, str_1), _strcpy(str_3_1, str_1));
  ck_assert_str_eq(strcpy(str_1, str_4), _strcpy(str_1_1, str_4));
  ck_assert_str_eq(strcpy(str_4, str_1), _strcpy(str_5, str_1));
  ck_assert_str_eq(strcpy(str_6, str_5), _strcpy(str_6, str_5));
}
END_TEST

START_TEST(strncpy_test) {
  char str_1[LEN] = "abcdddefg";
  char str_1_1[LEN] = "abcdddefg";
  char str_2[LEN] = "a";
  char str_2_1[LEN] = "a";
  char str_3[LEN] = "abcd\0ddefg";
  char str_3_1[LEN] = "abcd\0ddefg";
  char str_4[LEN] = "\0";
  char str_5[LEN] = "\0";
  char str_6[LEN] = "\0";
  ck_assert_str_eq(strncpy(str_1, str_2, 1), _strncpy(str_1_1, str_2, 1));
  ck_assert_str_eq(strncpy(str_1, str_2, 5), _strncpy(str_1_1, str_2, 5));
  ck_assert_str_eq(strncpy(str_2, str_1, 1), _strncpy(str_2_1, str_1, 1));
  ck_assert_str_eq(strncpy(str_2, str_1, 5), _strncpy(str_2_1, str_1, 5));
  ck_assert_str_eq(strncpy(str_1, str_3, 1), _strncpy(str_1_1, str_3, 1));
  ck_assert_str_eq(strncpy(str_1, str_3, 10), _strncpy(str_1_1, str_3, 10));
  ck_assert_str_eq(strncpy(str_3, str_1, 1), _strncpy(str_3_1, str_1, 1));
  ck_assert_str_eq(strncpy(str_3, str_1, 10), _strncpy(str_3_1, str_1, 10));
  ck_assert_str_eq(strncpy(str_1, str_4, 1), _strncpy(str_1_1, str_4, 1));
  ck_assert_str_eq(strncpy(str_1, str_4, 10), _strncpy(str_1_1, str_4, 10));
  ck_assert_str_eq(strncpy(str_4, str_1, 1), _strncpy(str_5, str_1, 1));
  ck_assert_str_eq(strncpy(str_4, str_1, 5), _strncpy(str_5, str_1, 5));
  ck_assert_str_eq(strncpy(str_6, str_5, 1), _strncpy(str_6, str_5, 1));
}
END_TEST

START_TEST(strcspn_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "ad";
  char str_3[LEN] = "da";
  char str_4[LEN] = "hijk";
  char str_5[LEN] = "a";
  char str_6[LEN] = "h";
  char str_7[LEN] = "\0";
  ck_assert_int_eq(strcspn(str_1, str_2), _strcspn(str_1, str_2));
  ck_assert_int_eq(strcspn(str_1, str_3), _strcspn(str_1, str_3));
  ck_assert_int_eq(strcspn(str_1, str_4), _strcspn(str_1, str_4));
  ck_assert_int_eq(strcspn(str_1, str_5), _strcspn(str_1, str_5));
  ck_assert_int_eq(strcspn(str_1, str_6), _strcspn(str_1, str_6));
  ck_assert_int_eq(strcspn(str_1, str_7), _strcspn(str_1, str_7));
  ck_assert_int_eq(strcspn(str_2, str_1), _strcspn(str_2, str_1));
  ck_assert_int_eq(strcspn(str_4, str_1), _strcspn(str_4, str_1));
  ck_assert_int_eq(strcspn(str_7, str_1), _strcspn(str_7, str_1));
}
END_TEST

START_TEST(strlen_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "a";
  char str_3[LEN] = "\0";
  char str_4[LEN] = "abcd\0ddefg";
  ck_assert_int_eq(strlen(str_1), _strlen(str_1));
  ck_assert_int_eq(strlen(str_2), _strlen(str_2));
  ck_assert_int_eq(strlen(str_3), _strlen(str_3));
  ck_assert_int_eq(strlen(str_4), _strlen(str_4));
}
END_TEST

START_TEST(strpbrk_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abefg";
  char str_3[LEN] = "f1233";
  char str_4[LEN] = "nmop";
  char str_5[LEN] = "a";
  char str_6[LEN] = "\0";
  char str_7[LEN] = "abcd\0ddefg";
  ck_assert_str_eq(strpbrk(str_1, str_2), _strpbrk(str_1, str_2));
  ck_assert_str_eq(strpbrk(str_1, str_3), _strpbrk(str_1, str_3));
  ck_assert_pstr_eq(strpbrk(str_1, str_4), _strpbrk(str_1, str_4));
  ck_assert_str_eq(strpbrk(str_1, str_5), _strpbrk(str_1, str_5));
  ck_assert_str_eq(strpbrk(str_5, str_1), _strpbrk(str_5, str_1));
  ck_assert_pstr_eq(strpbrk(str_1, str_6), _strpbrk(str_1, str_6));
  ck_assert_str_eq(strpbrk(str_1, str_7), _strpbrk(str_1, str_7));
  ck_assert_pstr_eq(strpbrk(str_4, str_7), _strpbrk(str_4, str_7));
  ck_assert_pstr_eq(strpbrk(str_6, str_1), _strpbrk(str_6, str_1));
}
END_TEST

START_TEST(strrchr_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "e";
  char str_4[LEN] = "\0";
  ck_assert_ptr_eq(strrchr(str_1, 'e'), _strrchr(str_1, 'e'));
  ck_assert_ptr_eq(strrchr(str_1, 'h'), _strrchr(str_1, 'h'));
  ck_assert_ptr_eq(strrchr(str_2, 'e'), _strrchr(str_2, 'e'));
  ck_assert_ptr_eq(strrchr(str_3, 'e'), _strrchr(str_3, 'e'));
  ck_assert_ptr_eq(strrchr(str_3, 'a'), _strrchr(str_3, 'a'));
  ck_assert_ptr_eq(strrchr(str_4, 'e'), _strrchr(str_4, 'e'));
}
END_TEST

START_TEST(strspn_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "e";
  char str_4[LEN] = "\0";
  ck_assert_int_eq(strspn(str_1, str_2), _strspn(str_1, str_2));
  ck_assert_int_eq(strspn(str_1, str_3), _strspn(str_1, str_3));
  ck_assert_int_eq(strspn(str_1, str_4), _strspn(str_1, str_4));
  ck_assert_int_eq(strspn(str_3, str_1), _strspn(str_3, str_1));
  ck_assert_int_eq(strspn(str_3, str_4), _strspn(str_3, str_4));
}
END_TEST

START_TEST(strstr_test) {
  char str_1[LEN] = "abcdddefg";
  char str_2[LEN] = "abcd\0ddefg";
  char str_3[LEN] = "f";
  char str_4[LEN] = "\0";
  char str_5[LEN] = "cdd";
  ck_assert_ptr_eq(strstr(str_1, str_2), _strstr(str_1, str_2));
  ck_assert_ptr_eq(strstr(str_1, str_4), _strstr(str_1, str_4));
  ck_assert_ptr_eq(strstr(str_1, str_5), _strstr(str_1, str_5));
  ck_assert_ptr_eq(strstr(str_1, str_3), _strstr(str_1, str_3));
  ck_assert_ptr_eq(strstr(str_2, str_1), _strstr(str_2, str_1));
  ck_assert_ptr_eq(strstr(str_2, str_4), _strstr(str_2, str_4));
  ck_assert_ptr_eq(strstr(str_2, str_5), _strstr(str_2, str_5));
  ck_assert_ptr_eq(strstr(str_2, str_3), _strstr(str_2, str_3));
}
END_TEST

START_TEST(strtok_test_1) {
  char str_1[LEN] = "abc/def/ghi";
  char str_1_1[LEN] = "abc/def/ghi";
  char *res_1;
  char *res_2;
  res_1 = strtok(str_1, "/");
  res_2 = _strtok(str_1_1, "/");
  ck_assert_str_eq(res_1, res_2);
  while (res_1 != NULL && res_2 != _NULL) {
    res_1 = strtok(NULL, "/");
    res_2 = _strtok(_NULL, "/");
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(strtok_test_2) {
  char str_1[LEN] = "abcd\0ddefg";
  char str_1_1[LEN] = "abcd\0ddefg";
  char *res_1;
  char *res_2;
  res_1 = strtok(str_1, "bc");
  res_2 = _strtok(str_1_1, "bc");
  ck_assert_str_eq(res_1, res_2);
  while (res_1 != NULL && res_2 != _NULL) {
    res_1 = strtok(NULL, "/");
    res_2 = _strtok(_NULL, "/");
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(strtok_test_3) {
  char str_1[LEN] = "abcd\0ddefg";
  char str_1_1[LEN] = "abcd\0ddefg";
  char *res_1;
  char *res_2;
  res_1 = strtok(str_1, "ef");
  res_2 = _strtok(str_1_1, "ef");
  ck_assert_str_eq(res_1, res_2);
  while (res_1 != NULL && res_2 != _NULL) {
    res_1 = strtok(NULL, "/");
    res_2 = _strtok(_NULL, "/");
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(strtok_test_4) {
  char str_1[LEN] = "f";
  char str_1_1[LEN] = "f";
  char *res_1;
  char *res_2;
  res_1 = strtok(str_1, "a");
  res_2 = _strtok(str_1_1, "a");
  ck_assert_str_eq(res_1, res_2);
  while (res_1 != NULL && res_2 != _NULL) {
    res_1 = strtok(NULL, "/");
    res_2 = _strtok(_NULL, "/");
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(strtok_test_5) {
  char str_1[LEN] = "f";
  char str_1_1[LEN] = "f";
  char *res_1;
  char *res_2;
  res_1 = strtok(str_1, "f");
  res_2 = _strtok(str_1_1, "f");
  ck_assert_pstr_eq(res_1, res_2);
  while (res_1 != NULL && res_2 != _NULL) {
    res_1 = strtok(NULL, "/");
    res_2 = _strtok(_NULL, "/");
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(strtok_test_6) {
  char str_1[LEN] = "/0";
  char str_1_1[LEN] = "/0";
  char *res_1;
  char *res_2;
  res_1 = strtok(str_1, "a");
  res_2 = _strtok(str_1_1, "a");
  ck_assert_str_eq(res_1, res_2);
  while (res_1 != NULL && res_2 != _NULL) {
    res_1 = strtok(NULL, "/");
    res_2 = _strtok(_NULL, "/");
    ck_assert_pstr_eq(res_1, res_2);
  }
}
END_TEST

START_TEST(to_upper_test) {
  char *s1 = to_upper("abcdddefg");
  char *s2 = to_upper("abcd\0ddefg");
  char *s3 = to_upper("f");
  char *s4 = to_upper("\0");
  char *s5 = to_upper("&2rR");
  char *s6 = to_upper("&{");
  char *s7 = to_upper(_NULL);
  ck_assert_str_eq(s1, "ABCDDDEFG");
  ck_assert_str_eq(s2, "ABCD");
  ck_assert_str_eq(s3, "F");
  ck_assert_str_eq(s4, "\0");
  ck_assert_str_eq(s5, "&2RR");
  ck_assert_str_eq(s6, "&{");
  ck_assert_pstr_eq(s7, NULL);
  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(s5);
  free(s6);
  free(s7);
}
END_TEST

START_TEST(to_lower_test) {
  char *s1 = to_lower("1234567890");
  char *s2 = to_lower(
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$^&*()_"
      "+");
  char *s3 = to_lower("A");
  char *s4 = to_lower("AbCdEfJKHKGgg\0asdkasfkhuFFFF");
  char *s5 = to_lower("\0");
  char *s6 = to_lower(_NULL);
  ck_assert_str_eq(s1, "1234567890");
  ck_assert_str_eq(s2,
                   "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz1234567"
                   "890!@#$^&*()_+");
  ck_assert_str_eq(s3, "a");
  ck_assert_str_eq(s4, "abcdefjkhkggg");
  ck_assert_str_eq(s5, "\0");
  ck_assert_pstr_eq(s6, NULL);
  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(s5);
  free(s6);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = insert("abcdddefg", "123", 4);
  char *s2 = insert("abcdddefg", "123", 9);
  char *s3 = insert("f", "123", 0);
  char *s4 = insert("f", "123", 1);
  char *s5 = insert("\0", "123", 0);
  char *s6 = insert(_NULL, "123", 1);
  char *s7 = insert("f", _NULL, 1);
  ck_assert_str_eq(s1, "abcd123ddefg");
  ck_assert_str_eq(s2, "abcdddefg123");
  ck_assert_str_eq(s3, "123f");
  ck_assert_str_eq(s4, "f123");
  ck_assert_str_eq(s5, "123");
  ck_assert_pstr_eq(s6, NULL);
  ck_assert_pstr_eq(s7, NULL);
  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(s5);
  free(s6);
  free(s7);
}
END_TEST

START_TEST(trim_test) {
  char *s1 = trim("abcdddefgab", "a");
  char *s2 = trim("abcdddefgab", "ab");
  char *s3 = trim("abcdddefgab", "f");
  char *s4 = trim("f", "a");
  char *s5 = trim("f", "f");
  char *s6 = trim("\0", "f");
  char *s7 = trim("abcdd\0defgab", "a");
  char *s8 = trim(_NULL, "a");
  char *s9 = trim("abcdd\0defgab", _NULL);
  ck_assert_str_eq(s1, "bcdddefgab");
  ck_assert_str_eq(s2, "cdddefg");
  ck_assert_str_eq(s3, "abcdddefgab");
  ck_assert_str_eq(s4, "f");
  ck_assert_pstr_eq(s5, "");
  ck_assert_str_eq(s6, "\0");
  ck_assert_str_eq(s7, "bcdd");
  ck_assert_pstr_eq(s8, NULL);
  ck_assert_pstr_eq(s9, NULL);
  free(s1);
  free(s2);
  free(s3);
  free(s4);
  free(s5);
  free(s6);
  free(s7);
  free(s8);
  free(s9);
}
END_TEST

Suite *_string_suite(void) {
  Suite *suite = suite_create("_string");
  TCase *tcase_core = tcase_create("string");
  tcase_add_test(tcase_core, memchr_test);
  tcase_add_test(tcase_core, memcmp_test);
  tcase_add_test(tcase_core, memcpy_test);
  tcase_add_test(tcase_core, memmove_test);
  tcase_add_test(tcase_core, memset_test);
  tcase_add_test(tcase_core, strcat_test);
  tcase_add_test(tcase_core, strncat_test);
  tcase_add_test(tcase_core, strchr_test);
  tcase_add_test(tcase_core, strcmp_test);
  tcase_add_test(tcase_core, strncmp_test);
  tcase_add_test(tcase_core, strcpy_test);
  tcase_add_test(tcase_core, strncpy_test);
  tcase_add_test(tcase_core, strcspn_test);
  tcase_add_test(tcase_core, strlen_test);
  tcase_add_test(tcase_core, strpbrk_test);
  tcase_add_test(tcase_core, strrchr_test);
  tcase_add_test(tcase_core, strspn_test);
  tcase_add_test(tcase_core, strstr_test);
  tcase_add_test(tcase_core, strtok_test_1);
  tcase_add_test(tcase_core, strtok_test_2);
  tcase_add_test(tcase_core, strtok_test_3);
  tcase_add_test(tcase_core, strtok_test_4);
  tcase_add_test(tcase_core, strtok_test_5);
  tcase_add_test(tcase_core, strtok_test_6);
  tcase_add_test(tcase_core, to_upper_test);
  tcase_add_test(tcase_core, to_lower_test);
  tcase_add_test(tcase_core, insert_test);
  tcase_add_test(tcase_core, trim_test);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = _string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  srunner_free(suite_runner);
  return 0;
}
