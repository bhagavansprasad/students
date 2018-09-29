#include <stdio.h>
#include <string.h>

char * astrstr(char *phstack, char *pneedle)
{
	int i=0,j=0,k=0;
char r[100],*p=NULL;
	for( i=0 ; phstack[i]!='\0';i++ ) 
	{
		while( tolower(phstack[i])==tolower(pneedle[j]) && j<strlen(pneedle))
		{
			i++;
			j++;
			printf("i:%d\t  j:%d\n",i,j);
						if( j==strlen(pneedle))
			{
				for(j=0;j<strlen(pneedle);j++,k++)
				{
					r[k]=pneedle[j];
				}
				for( ;phstack[i]!='\0';i++,k++)
				{
					r[k]=phstack[i];
				}
				r[k]='\0';
 
				p=&r;
			printf("h:%s\n",phstack);
			}
		}
		if(j<strlen(pneedle))
		{
			j=0;
		}
		if(j>=strlen(pneedle))
			return p;
	}
}
char * astrcasestr(char *phstack, char *pneedle)
{

	return NULL;
}


int main()
{
	char haystack[200] = "Tutorials Classwork Srinivas Aura net";
	char needle[10] = "Aura";
	char *ret = NULL;

	ret = strstr(haystack, needle);
	printf("haystack :%p\n", haystack);
	printf("needle   :%p\n", needle);
	printf("ret      :%p\n", ret);
	printf("The substring is: %s\n\n", ret);

	ret = strstr(haystack, needle);
	printf("haystack :%p\n", haystack);
	printf("needle   :%p\n", needle);
	printf("ret      :%p\n", ret);
	printf("The substring is: %s\n\n", ret);

//return 0;
	ret = astrstr(haystack, needle);
	printf("haystack :%p\n", haystack);
	printf("needle   :%p\n", needle);
	printf("ret      :%p\n", ret);
	printf("The substring is: %s\n\n", ret);

	return(0);
}
