
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
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include"string1.h"
enum function{STRLEN, STRCPY, STRCAT, STRCMP, STRNCMP, STRNCPY, STRNCAT, STPCPY, STRCHR, STRRCHR ,CASECMP, NCASECMP, CSPN, SPN, STRDUP, STRSTR, MEMCPY, MEMMOVE, MEMCMP, STRPBRK, STRFRY, STRREV, STRCOLL};

typedef struct data{
	int n;
	char s1[1024], s2[1024], result[1024], g;
}data;
data a[100];

int main(int argc, char *argv[])
{
	int i = 0, q, m, count, x;
	char line[128], c, u;
	char *l;
	FILE *fp;
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		perror("can't open file:");
		exit(errno);
	}
	if(argc != 2){
		errno = EINVAL;
		perror("usage: ./program filename");
		return errno;
	}
	fseek(fp, SEEK_SET, 0);		
	while(fscanf (fp, "%d", &(a[i].n)) != -1)
	{
		switch(a[i].n)
		{
			case STRLEN :	
			{
				printf("case : STRLEN\n");		
				fscanf (fp, "%s", a[i].s1);
				char *p = strtoken( a[i].s1, "\t");
				fscanf (fp, "%d", &m);				
				q = strlength(a[i].s1);
				printf("strlen of the string %s is %d\n", a[i].s1, q); 
				char *nl = strtoken(NULL, "\n");	
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}			
			break;
			case STRCPY :
			{	
				printf("case : STRCPY\n");			
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
							 
				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
					 
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result, "\t");
				
				strcopy(a[i].s1, a[i].s2);
				if(strcomp(a[i].s1, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}							
			break;
			case STRCAT :
			{
				printf("case : STRCAT\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
					 
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result, "\t");

				strconcat(a[i].s1, a[i].s2);
				char *s = strtoken( a[i].s1, "\t");
				if(strcomp(a[i].s1, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}						
			break;
			case STRCMP :
			{
				printf("case : STRCMP\n");			
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &m);
				printf("result = %d\n", m);				
				q = strcomp(a[i].s1, a[i].s2);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STRNCMP :
			{
				printf("case : STRNCMP\n");			
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");

				fscanf (fp, "%d", &x);		
				printf("no of bytes to be compared = %d\n", x);				
				fscanf (fp, "%d", &m);
				printf("result = %d\n", m);
												
				q = strncomp(a[i].s1, a[i].s2, x);
				printf("%d\n",q);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;	
			case STRNCPY :
			{
				printf("case : STRNCPY\n");			
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
							 
				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &x);		
				printf("no of bytes to be copied = %d\n", x);
					
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result, "\t");
				
				char *f = strncopy(a[i].s1, a[i].s2, x);
				if(strcomp(f, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STRNCAT :
			{
				printf("case : STRNCAT\n");			
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n",a[i].s1);
				char *k = strtoken( a[i].s1,"\t");
							 
				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n",a[i].s2);
				char *r = strtoken( a[i].s2,"\t");
				
				fscanf (fp, "%d", &x);		
				printf("no of bytes to be concatenated = %d\n",x);
					
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n",a[i].result);
				char *nl = strtoken( a[i].result,"\t");
				char *f = strnconcat(a[i].s1, a[i].s2, x);
				if(strcomp(f, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STPCPY :
			{
				printf("case : STPCPY\n");			
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
							 
				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				
				char *f = stpcopy(a[i].s1, a[i].s2);
				if(strcomp(a[i].result, f))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STRCHR : 
			{	
				printf("case : STRCHR\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
				
				fscanf (fp, "%c", &(u));				
				fscanf (fp, "%c", &(a[i].g));
				printf("ch = %c\n", a[i].g);
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				
				char *f = strchar(a[i].s1, a[i].g);
				if(strcomp(a[i].result, f))  
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STRRCHR :
			{
				printf("case : STRRCHR\n");						
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
				
				fscanf (fp, "%c", &(u));				
				fscanf (fp, "%c", &(a[i].g));
				printf("ch = %c\n", a[i].g);
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				
				char *f = strrchar(a[i].s1, a[i].g);
				if(strcomp(a[i].result, f))  
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case CASECMP :
			{
				printf("case : CASECMP\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &m);	
				printf("result = %d", m);			
				q = strcasecomp(a[i].s1, a[i].s2);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case NCASECMP :
			{
				printf("case : NCASECMP\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &x);		
				printf("no of bytes to be compared = %d\n", x);				
				fscanf (fp, "%d", &m);
				printf("result = %d\n", m);
												
				q = strncasecomp(a[i].s1, a[i].s2, x);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;	
			case CSPN :
			{
				printf("case : CSPN\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2,  "\t");
				
				fscanf (fp, "%d", &m);
				printf("result = %d\n", m);				
				q = strcspn(a[i].s1, a[i].s2);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
	
			case SPN :
			{
				printf("case : SPN\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				printf("result = %d\n", m);				
				fscanf (fp, "%d", &m);				
				q = strspn(a[i].s1, a[i].s2);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}	
			break;
			
			case STRDUP:
			{
				printf("case : STRDUP\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result,  "\t");
				
				char *f = strdupl(a[i].s1);
				if(strcomp(f, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			
			case STRSTR :
			{
				printf("case : STRSTR\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				
				char *b = strstr1(a[i].s1, a[i].s2);
				if(strcomp(b, a[i].result))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			
			case MEMCPY :
			{		
				printf("case : MEMCPY\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &m);
								 
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result, "\t");
								
				memcopy(a[i].s1, a[i].s2, m);
				if(strcomp(a[i].s1, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}							
			break;
			case MEMMOVE :
			{
				printf("case : MEMMOVE\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
							 
				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &x);		
				printf("no of bytes to be copied = %d\n", x);
					
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result, "\t");
				
				char *f = memmov(a[i].s1, a[i].s2, x);
				if(strcomp(f, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case MEMCMP :
			{
				printf("case : MEMCMP\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");

				fscanf (fp, "%d", &x);		
				printf("no of bytes to be compared = %d\n", x);				
				fscanf (fp, "%d", &m);
				printf("result = %d\n", m);
												
				q = memcomp(a[i].s1, a[i].s2, x);
				printf("%d\n",q);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			
			break;
			case STRPBRK :
			{
				printf("case : STRPBRK\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				
				char *b = strpbrk1(a[i].s1, a[i].s2);
				if(strcomp(b, a[i].result))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STRFRY :
			{
				printf("case : STRFRY\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
				
				char *f = stringfry(a[i].s1);
				printf("result = %s\n\n", f);
			}
			break;
			case STRREV :
			{
				printf("case : STRREV\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);
				char *nl = strtoken( a[i].result, "\t");
				
				char *f = strreverse(a[i].s1);
				if(strcomp(f, nl))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			case STRCOLL :
			{
				printf("case : STRCOLL\n");				
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%d", &m);
				printf("result = %d\n", m);				
				q = stringcoll(a[i].s1, a[i].s2);
				if(q == m)
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;									
			default : 
				printf("bad input\n");
			break;	
		}
		
		i++;
	}
	printf("end of test cases\n");
	return 0;
}
