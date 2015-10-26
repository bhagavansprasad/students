#include <stdio.h>
#include <string.h>
void reversestr(char str[]);
void reverse(char str[],int start,int end);
main()
{
	char str[50];
	strcpy(str,"i have many books");
	reversestr(str);
	puts(str);
	reverse(str,6,9);
	puts(str);
}
void reversestr(char str[])
{
	int i,j;
	char tmp;
	for(i=0,j=strlen(str)-1;i<=j;i++,j--)
	{
		tmp=str[i];
		str[i]=str[j];
		str[j]=tmp;
	}
}
void reverse(char str[],int start,int end)
{
	char tmp;
	while(start<=end)
	{
		tmp=str[start];
		str[start]=str[end];
		str[end]=tmp;
		start++;
		end--;
	}
}
