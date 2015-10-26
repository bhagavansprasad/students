#include<stdio.h>
#include<fcntl.h>
int main()
{
	int len=0;
	char buff[100]="Aura Networks Banglore";
	len=astrlen(buff);
	printf("%d\n",len);
}
int astrlen(char *pb)
{
	int i;
	for(i=0;pb[i]!='\0';i++);
	return i;
}
