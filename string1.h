#ifndef STRING__H
#define STRING__H
 

int strlength(char *str);
void strcopy(char *str1,char *str2);
void strconcat(char *str1,char *str2);
int strcomp( char *str1, char *str2);
int strncomp(const char *str1, const char *str2, size_t n);
char *strncopy(char *str1,char *str2, size_t n);
char *strnconcat(char *str1 , char *str2, size_t n);
char *stpcopy(char *str1, const char *str2);
char *strchar(char *str, int c);
int stringcoll (char *str1, char *str2);
size_t strcspn(const char *str1, const char *str2);
char *strrchar(const char *str, int c);
char *strdupl(char *str);
void *memcopy(void *dest, const void *src, size_t n);
void *memmov(void *dest, const void *src, size_t n);
char *strpbrk(const char *s, const char *accept);
 char *strsep(char **stringp, const char *delim);
char *strstr1(char *str1, char *str2);
char *strtok(char *s, const char *delim);
size_t strxfrm(char *dest, const char *src, size_t n);

#endif
