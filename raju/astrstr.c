#include<stdio.h>
#include<string.h>
#include<fcntl.h>

char * astrstr(char *haystr, char *needle)
{
	int i,j=0,k=0;
	char r[100],*p=NULL;

	for(i=0; haystr[i]!='\0'; i++)
	{
		while(haystr[i]==needle[j]  &&  j<strlen(needle))
		{
			j++;
			i++;
			printf("i:%d\t j:%d\n", i, j);
			if(j==strlen(needle))
			{
				for(j=0; j<strlen(needle); j++,k++)
				{
					r[k] = needle[j];
				}  
				
				for(  ; haystr[i]!='\0'; i++,k++)
				{
					r[k] = haystr[i];
				}
				
			     p=&r;
			     printf("h:%s\n",*haystr);
			}
		}

		if(j<strlen(needle))
		{
			j=0;
		}

		if(j>=strlen(needle))
		    return p;
	}
}

main()
{
	char src[100] = "Aura Networks Bangalore India and dinesh";
	char needle[100] = "Bangalore";
	char *substr = NULL;

	substr = astrstr(&src, &needle);

	printf("substr: %p, %s\n", substr, substr);

	return 0;

}

