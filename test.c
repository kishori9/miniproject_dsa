#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include"string1.h"
enum function{STRLEN, STRCPY, STRCAT, STRCMP, STRNCMP, STRNCPY, STRNCAT, STPCPY, STRCHR, STRRCHR ,CASECMP, NCASECMP, CSPN, SPN, STRDUP, STRSTR, STRTOK, MEMCPY, MEMMOVE, STRPBRK, STRFRY, STRREV, STRCOLL};

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
			
			case STRTOK :
			{
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");

				fscanf (fp, "%s", a[i].s2);
				printf("s2 = %s\n", a[i].s2);
				char *r = strtoken( a[i].s2, "\t");
				
				fscanf (fp, "%s", a[i].result);
				printf("result = %s\n", a[i].result);

				char *y = strtoken(a[i].s1, a[i].s2);
				if(strcomp(y, r))
					printf("pass :)\n\n");
				else
					printf("fail :(\n\n");
			}
			break;
			
			case MEMCPY :
			{		
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
			case STRPBRK :
			{
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
				fscanf (fp, "%s", a[i].s1);
				printf("s1 = %s\n", a[i].s1);
				char *k = strtoken( a[i].s1, "\t");
				
				char *f = stringfry(a[i].s1);
				printf("result = %s\n\n", f);
			}
			break;
			case STRREV :
			{
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
