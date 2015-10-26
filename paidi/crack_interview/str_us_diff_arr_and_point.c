#include <stdio.h>
#include <string.h>
int main()
{
	char a[]= "paidi";
	char* p = "kumar";
	int i,j;
	for(i=0,j=0;i<strlen(a) || j<strlen(p);i++,j++)
	{
		printf("arr     :%c\n",a[i]);
		printf("pointer :%c\n",*(p+j));
	}
}
