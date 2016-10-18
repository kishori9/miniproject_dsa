#include<stdio.h>
#include<stdlib.h>
#include"string1.h"
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

int main()
{
	char *s1,ch;
	int l1,l2;
	int size1=1024,size2=1024, count1=0,count2=0;
	s1 = (char *)malloc(sizeof(char)*size1);
	printf("enter first string\n");
	do
	{	
		scanf("%c",&ch);
		s1[count1] = ch;
		count1++;
		if(count1 == size1) {
			size1 *= 2;
			s1 = (char *)realloc(s1, sizeof(char) * size1);
			if(s1 == NULL) {
				printf("Failed for %d\n", size1);
				exit(1);
			}
		}
	}
	while(ch != '\n');
	char *s2;
	printf("enter second string\n");
	s2= (char *)malloc(sizeof(char)*size2);
	do
	{
		scanf("%c", &ch);
		s2[count2] = ch;
		count2++;
		if(count2 == size2) {
			size2 *= 2;
			s2 = (char *)realloc(s2, sizeof(char) * size2);
			if(s2 == NULL) {
				printf("Failed for %d\n", size2);
				exit(1);
			}
		}
	}
	while(ch != '\n');
	
	//len
	l1 = strlength(s1);
	l2 = strlength(s2);
	printf("l1 = %d \n l2 = %d\n",l1,l2);
	
	//comp
	int k,n;	
	k = strcomp(s1,s2);
	
	//ncomp
	printf("enter the no of bytes to be compared\n");
	scanf("%d",&n);
	if(n>l2)
		printf("bad input\n");
	else
	{
		if(!strncomp(s1,s2,n))
			printf("first %d characters of both strings are same\n",n);
		else
			printf("first %d characters of the strings are not same\n",n);
	}

	//concat
	char *temp;
	temp = s1;
	strconcat(temp,s2);
	
	//cpy
	temp = s1;
	strcopy(temp,s2);
	
	//ncpy
	temp = s1;
	printf("enter the no of bytes to be copied\n");
	scanf("%d",&n);
	if(n>l2)
		printf("bad input\n");
	else
		printf("copied string is %s \n",strncopy(temp,s2,n));

	//ncat
	temp = s1;	
	printf("enter the no of bytes to be concatenated\n");
	scanf("%d",&n);
	if(n>l2)
		printf("bad input\n");
	else
		printf("concatenated string is %s \n",strnconcat(temp,s2,n));
	
	//strchr
/*	printf("enter the character to be searched\n");
	scanf("%c",&ch);
	int a = (int) ch;
	temp = strchar(s1,a);
	if(temp == NULL)
		printf("not found\n");         */

	//stpcpy
	stpcopy(s1,s2);   

	//strcoll
	n = stringcoll(s1,s2);
	if(n<0)
		printf("str1 is less than str2\n");
	else if(n>0)
		printf("str2 is less than str1\n");
	else
		printf("the strings are same\n");

	//strcspn
	n = strcspn(s1, s2);
	printf("%d\n",n);

	//strrchr
	
	//memcpy
	printf("enter the no of characters to be copied\n");
	scanf("%d",&n);
	memcopy(s1,s2,n);

	//memmove
	printf("enter the no of characters to be moved\n");
	scanf("%d",&n);
	memmov(s1,s2,n);

	//strdup
	temp = strdupl(s1);
	printf("duplicate string is %s",temp);
	
	//strstr
	temp = strstr1(s1,s2);
	

	free(s1);
	free (s2);
	return 0;	
}

