#include<stdio.h>
main()
{
int i,m='N';
char c[20]="AuraNetworks";
printf("before loop %s \n",c);
for(i=0;c[i]!='\0';i++)
{
	if(c[i]==m)
	{
	while(c[i]!='\0')
	{
	printf("%c",c[i]);
	i++;
	}
	break;
	}
}
printf("%dafter loop\n",i);
}
