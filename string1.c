
/******************************************************************************
 string1.c

 String routines

 Copyright (C) 2016 Kishori Kasat. All rights reserved. 

  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU Lesser General Public License for more details.
 
  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, see <http://www.gnu.org/licences/> .
  
 ********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stddef.h>
#include"string1.h"

/*to calculate the length of the string*/
int strlength(char *str)
{
	int length = 0;
	if(str == NULL)
		return 0;
	while(str[length] != '\0' ){
		length++;
	}
	return length;
}

/* to copy str2 in str1  */
void strcopy(char *str1,char *str2) 
{
	int i = 0;
	while ((str1[i] = str2[i]) != '\0') 
	{
	         i++;
	}
}

/* concatenate str1 and str2 */
void strconcat(char *str1,char *str2)
{
	int i, j;
	i = 0; j = 0;
	while(str1[i] != '\0')
	{
		i++;
	}
	while(str2[j] != '\0')
	{
		str1[i] = str2[j];
		i++;
		j++;
	}
}

/* to compare str1 with str2  */
int strcomp(char *str1, char *str2)
{ 
	int i = 0,temp = 0; 
	int l1, l2;
	if(str1 == NULL)
		return -1;
	if(str2 == NULL)
		return 1;
	l1 = strlength(str1);
	l2 = strlength(str2);
		if(l1 > l2)
		return 1;
	else if(l1 < l2)
		return -1;
   	do
	{
	         if(str1[i] != str2[i])
		{
	             temp = 1;
	             break;	        
		}
        i++;
	}
	while(str1[i] != '\0' && str2[i] != '\0');
	return temp;
}

/* to compare first n bytes of str2 with str1  */
int strncomp(const char *str1, char *str2, size_t n)
{
	int l = strlength(str2);
	if(l < n)
		return -1;
	while(n--) 
	{
	        if(*str1 != *str2) 	
		{
	         	return *str1 - *str2;
        	}
        	else 
		{
			++str1;
                 	++str2;
        	}
    	}

    return 0;
}

/* to copy first n bytes of str2 in str1  */
char *strncopy(char *str1, char *str2, size_t n)
{
	int i = 0;
	while(i < n && str2[i] != '\0') 
	{
		str1[i] = str2[i];
	         i++;
	}
	str1[i] = '\0';
	return str1;	
}

/* to concatenate first n bytes of str2 and the string str1  */
char *strnconcat(char *str1 , char *str2, size_t n)
{
	char *tmp = str1; 
        if (n) 
	{
        	while (*str1)
                	str1++;
                while ((*str1++ = *str2++) != '\0')
		{
              		if (--n == 0) 
			{
                        	*str1 = '\0';
                                break;
                        }
                }
         }
         return tmp;
}

/* This function returns the number of characters in the initial segment of str1 which consist only of characters from str2. */
size_t strspn(const char *str1, const char *str2)
{    
	const char *p = str1;
        const char *q = str2;
        size_t count = 0;
 	for (p = str1; *p != '\0'; ++p)
 	{
 		for (q = str2; *q != '\0'; ++q)
 		{
                 	if (*p == *q)
                        	break;
                }
                if (*q == '\0')
                	return count;
                ++count;
         }
         return count;
}

/* This function returns the number of characters in the initial segment of string str1 which are not in the string str2. */
size_t strcspn(const char *str1, const char *str2)
{
       	const char *p;
        const char *q;
        size_t count = 0;
	for (p = str1; *p != '\0'; ++p)
	{
         	for (q = str2; *q != '\0'; ++q) 
         	{
                 	if (*p == *q)
                        	return count;
                 }
                 ++count;
        }
        return count;
}

/* returns pointer to the location of the first occurance of character c */
char *strchar(char *str, int c)
{
	char *p;
	int i = 0;
	p = str;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return p;
		i++;
		p++;
	}
	return NULL;
}

/* returns pointer to the location of the last occurance of character c */
char *strrchar(char *str, int c)
{
	char *p;
	int i = 0;
	p = NULL;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			p = str;
		i++;
	}
	return p;
}

/* this function copies n bytes from memory area str2 to memory area str1. The memory areas must not overlap. */
void *memcopy(void *str1, const void *str2, size_t n)
{
	char *src = (char *)str1;
   	char *dest = (char *)str2;
   	for (int i=0; i<n; i++)
      		dest[i] = src[i];
      	str1 = dest;
}

/* this function copies n bytes from memory area str2 to memory area str1.   */
void *memmov(void *str1, const void *str2,size_t n)
{
	char *tmp;
	const char *s;

	if (str1 <= str2) {
		tmp = str1;
		s = str2;
		while (n--)
			*tmp++ = *s++;
	}
	 else 
	{
		tmp = str1;
		tmp += n;
		s = str2;
		s += n;
		while (n--)
			*--tmp = *--s;
	}
}

/* function compares the first n characters of the object pointed to by str1 to the first n characters of the object pointed to by str2. */
int memcomp(void* str1, void* str2, size_t n)
{
	int l1 = strlength(str1);	
	int l2 = strlength(str2);
	if(l1 < n && l2 < n)
		return -1; 
    	char *p1 = str1, *p2 = str2;
    	while(n--)
    	{
        	if( *p1 != *p2 )
            		return *p1 - *p2;
        	else
        	{
            		p1++;
            		p2++;
            	}
	}
    	return 0;
}

/*  Returns a duplicate of the string str  in  memory  allocated  using malloc */
char *strdupl(char *str)
{
	char *dupl;
	dupl = (char *) malloc(sizeof(strlength(str)+1));
	strcopy(dupl , str);
	return dupl;
}

/* Returns a pointer to the first occurrence in the string str1 of one of the bytes in the string str2 */
char *strpbrk1(char *str1, char *str2)
{
	char *p = str1,*q = str2;
	while(*p != '\0')
	{
		while(*q != '\0')
		{
			if(*p == *q)
			{
				return (char *)p;
			}
			q++;
		}
		p++;
	}
	return NULL;
}

/* Compares the strings str1 and str2 ignoring case. */
int strcasecomp(char *str1, char *str2)
{
	int i = 0,temp = 0; 
	int l1 ,l2;
	l1 = strlength(str1);
	l2 = strlength(str2);
	if(l1 > l2)
		return 1;
	else if(l1 < l2)
		return -1;
   	do
	{
	        if(str1[i]>=65&&str1[i]<=90)
       			str1[i]=str1[i]+32;
       		if(str2[i]>=65&&str2[i]<=90)
       			str2[i]=str2[i]+32;
	        if(str1[i]!=str2[i])
		{
	             temp = 1;
	             break;	        
		}
        i++;
	}
	while(str1[i]!='\0' && str2[i]!='\0');
	return temp;
}

/* Compares the first n characters of the strings str1 and str2 ignoring case.  */
int strncasecomp(char *str1, char *str2, size_t n)
{
	int i = 0;	
	while(n--) 
	{
		if(str1[i]>=65&&str1[i]<=90)
       			str1[i]=str1[i]+32;
       		if(str2[i]>=65&&str2[i]<=90)
       			str2[i]=str2[i]+32;
	        if(*str1 != *str2) 	
		{
	         	return *str1 - *str2;
        	}
        	else 
		{
			++str1;
                 	++str2;
        	}
    	}

    return 0;
}

/* this function copies the string str1 (including the terminating null byte ('\0')) to the string str2. Returns a pointer to the end of the string str1 */
char *stpcopy(char *str1, const char *str2)
{
	while (*str1 = *str2)
	{
	 	++str1;
	 	++str2;
	}
	return str1;
}

/* This function returns a pointer to the first occurrence in str1 of any of the entire sequence of characters specified in str2, or a null pointer if the sequence is not present in str1. */
char *strstr1(char *str1, char *str2)
{
	while (*str1) 
	{
		char *Begin = str1;
		char *pattern = str2;
		while (*str1 && *pattern && *str1 == *pattern) 
		{
			str1++;
			pattern++;
		}
		if (!*pattern)
		    	  return Begin;
		str1 = Begin + 1;
	}
	printf("bad input\n");
	return NULL;
}

/* Extracts tokens from the string str that are delimited  by  one  of the bytes in string tok.  */
char *strtoken(char *str, const char *tok)
{   
	static char buffer[100];
    	static int pos = 0;
    	char *trav;
    	int i = 0;
    	if(str == NULL)
    	{
    	    return NULL;
    	}
    	if(pos != 0) {
        	pos++;
    	}
    	trav = str+pos;
    	while(*trav)
    	{
        	if(*trav != *tok)
        	{
         		buffer[i++] = *trav++;
            		pos++;
      		}
       		else
            		buffer[i++] = '\0';
   	}
	return buffer;    
}

/* This function randomizes the contents of string by using rand(3) to randomly swap characters in the string. The result is an anagram of string.   */
char *stringfry(char *str)
{
	if(str == NULL)
		return NULL;
	srand(time(NULL));
	int i = 0, l, m, n;
	char ch;
	l = strlength(str);
	while(i < l)
	{
		m = rand() % l;
		n = rand() % l;
		ch = str[m];
		str[m] = str[n];
		str[n] = ch;
		i++;
	}
	return str;
}

/* this function finds the first token in the string str1, where tokens are delimited by symbols in the string str2. */
//strsep

/* this function reverses the order of the contents of the string */ 
char *strreverse(char *str)
{
	char *tmp1 = str;
	char *tmp2 = str;
	char ch; 
	while (*str++);
	str -= 2;
	while (tmp2 < str) 
	{
    		ch = *tmp2;
    		*tmp2++ = *str;
		*str-- = ch;
	}
	return tmp1;
}

/* compares str1 and str2 using current locale  */
int stringcoll (char *str1, char *str2)
{
	return strcomp(str1, str2);
}

        
