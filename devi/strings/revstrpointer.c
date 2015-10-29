#include <stdio.h>
#include <string.h>
char* strreverse(char *ptr,int n);
int main()
{
	char str[30] = "string";
	char *ptr,*rptr;
	int n;
	ptr = str;
	printf("%s\n",ptr);
	n=strlen(str);
	//ptr+strlen(str)-1;
	//printf("%s\n",ptr);
	rptr = strreverse(ptr,n);
	printf("%s",*rptr);
	return 0;
}

char* strreverse(char *ptr,int n)
{
	/*while(*ptr!='\0')
	{
	printf("%c",*ptr);
	ptr++;
	}*/

	int i,k=0;
	char str[30];
	char *sptr;
	for(i=n-1;i>=0;i--)
	{
		str[k]=*(ptr+i);
		printf("%c",*(ptr+i));
		k++;
	}
	str[k]='\0';
	sptr = str;
	return sptr;
}
