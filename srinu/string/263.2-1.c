#include <stdio.h>
#include <string.h>
	char *combine(char *arr1,char *arr2);
int main()
{
	char *p;
	char str1[20],str2[20];
	strcpy(str1,"suresh");
	strcpy(str2,"kumar");
	p=combine(str1,str2);
	puts(p);
}
char *combine(char *arr1,char *arr2)
{
	char str[80];
	strcpy(str,arr1);
	strcat(str,arr2);
	return str;
}
