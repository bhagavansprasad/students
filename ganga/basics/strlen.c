#include<stdio.h>
#include<string.h>
void main()
{
    char arr[100]="aura \n networks:";
	int length=astrlen(arr);
	printf("%d", length);
}
int astrlen(char *p)
{
	int i;
	for(i=0;p[i]!='\0';i++);
	return i;
}
