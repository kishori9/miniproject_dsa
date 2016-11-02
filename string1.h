#include<stdio.h>
#ifndef STRING__H
#define STRING__H


int strlength(char *str);

void strcopy(char *str1,char *str2);

void strconcat(char *str1,char *str2);

int strcomp( char *str1, char *str2);

int strncomp(const char *str1, char *str2, size_t n);

char *strncopy(char *str1,char *str2, size_t n);

char *strnconcat(char *str1 , char *str2, size_t n);

char *stpcopy(char *str1, const char *str2);

char *strchar(char *str, int c);

char *strrchar(char *str, int c);

int strcasecomp(char *str1, char *str2);

int strncasecomp(char *str1, char *str2, size_t n);

size_t strcspn(const char *str1, const char *str2);

size_t strspn(const char *str1, const char *str2);

char *strdupl(char *str);

void *memcopy(void *str1, const void *str2, size_t n);

void *memmov(void *str1, const void *str2,size_t n);

int memcomp(void* str1, void* str2, size_t n);

char *strpbrk1(char *str1, char *str2);

char *strstr1(char *str1, char *str2);

int stringcoll (char *str1, char *str2);          

char *strtoken(char *str, const char *tok);

char *stringfry(char *str);

char *strreverse(char *str);
#endif
