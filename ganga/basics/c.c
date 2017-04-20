#include<stdio.h>
int get(char *p)
{
	int i;
	for(i=0;p[i]!='\0';i++)
	return(i);
}
main()
{
int len;
char arr[100]="jhsadkhd";
len=get(&arr);
printf("%d",len);
}

