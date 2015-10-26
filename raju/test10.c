#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

char *astrstr(char *source, char *needle);
int copy(char *url,char *source,char sch,char ech);

main()
{
	int fd, t,m;
	char string[1000], substr[100]="one";
	char *substr_ptr=NULL, url[1000] = " ";

	fd=open("my.txt", 0, O_RDONLY);
	t = read(fd, string, 1000);
	string[t]='\0';

	printf("strings :%s\n", string);

	

	substr_ptr=astrstr(string, substr);

	printf("substr_ptr: %s\n", substr_ptr);
	printf("substr_ptr: %p\n", substr_ptr);

	/*	printf("y:%s\n",substr_ptr+strlen(substr));
		printf("y:%d\n",substr_ptr+strlen(substr));*/

	copy(url, substr_ptr, 'T', '.');

	printf("url:%s\n",url);

}

char *astrstr(char *source, char *needle)
{
	int i, j=0, k=0;
	char r[100], *p=NULL;

	for(i=0; source[i]!='\0'; i++)
	{
		while(source[i]==needle[j]  &&  j<3)
		{
			j++;
			i++;
			printf("i:%d\t j:%d\n", i, j);
			if(j==3)
			{
			/*	for(j=0; j<3; j++,k++)
				{
					r[k] = needle[j];

				}  

				for(  ; source[i+1]!='\0'; i++,k++)
				{
					r[k] = source[i];
				}
				printf("R:%d\n",&r);
				p=&r;
				printf("p:%d\n",p);*/
				p=&source[i-strlen(needle)];
				printf("p:%p\n",p);
				printf("*p:%c\n",*p); //%s expects a pointer and prints upto \0.
				
				return p;

			}
		}

		if(j<3)
		{
			j=0;
		}
/*		if(j>=3)
			return p;*/

	}
}

int copy(char *url, char *source, char sch, char ech)
{
	int i,j;
	printf("source:%p\n",source);
	printf("sch:%c\n",sch);
	printf("ech:%c\n",ech);
	printf("source:%s\n",source);
	for(i=0; source[i]!=sch; i++);
/*	{
		printf("source[%d]=%s\n",i,source);
	}  */

	for(j=0;source[i]!=ech; j++, i++)
	{
		url[j] =source[i];
		printf("url[%d]:%c\t source[%d]:%c\n",j,url[j],i,source[i]);
	}
	//return url;


}		

