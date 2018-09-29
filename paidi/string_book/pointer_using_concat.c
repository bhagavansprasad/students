#include<stdio.h>
int main(){
	int i=0,j=0;
	char *str1="paidi";
	char *str2="kumar";
	char str3[10];

	while(*str1)
	{
		str3[i++]=*str1++;
	}
	while(*str2)
	{
		str3[i++]=*str2++;
	}
	str3[i]='\0';
	printf("str cat-->=%s\n",str3);
	return 0;
}
