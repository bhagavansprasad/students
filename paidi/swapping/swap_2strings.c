#include<stdio.h>
int main()
{
	int i=0,j=0,k=0;
	char str1[20]="paidi";
	char str2[20]="kumar";
	char temp[20];

	while(str1[i]!='\0')
	{
		temp[j++]=str1[i++];
	}
	temp[j]='\0';

	i=0,j=0;
	while(str2[i]!='\0')
	{
		str1[j++]=str2[i++];
	}
	str1[j]='\0';

	i=0,j=0;
	while(temp[i]!='\0')
	{
		str2[j++]=temp[i++];
	}
	str2[j]='\0';
	printf("swaping string-->=%s\n",str2);

}
