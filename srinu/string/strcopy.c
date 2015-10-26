#include<stdio.h>
#include<fcntl.h>
int main()
{
	int t;
	char str1[100]="hai sravani";
	char str2[100]=" ";
	t=astrcpy(str2,str1);
	printf("%s\n",str2);
}
int astrcpy(char a[],char b[])
{
	int i;
	for(i=0;b[i]!='\0';i++)
	{
		a[i] = b[i];
	}
}
