#include <stdio.h>
#include <string.h>
int reverse_fun(char *p,int size)
{
	int i,j=0;
	char temp[10];
	for(i=7;p[i]!='\0';i--)
	{
		printf("hai\n");
		temp[j]=p[i];
		j++;
	}
	temp[j]='\0';
	printf("string:%s\n",temp[j]);
}
main()
{
	char str[10]="manohar";
	int len=sizeof(str);
	reverse_fun(str,len);
}

