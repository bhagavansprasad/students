#include <stdio.h>
#include <string.h>
int main()
{
	char str1[]="paidi kumar";
	char str2[]="kumar";
	int n=0,i,j=0,count=0;
	n=strlen(str2);
	char buffer[100];
	for(i=0;str1[i]!='\0';i++)
	{
		for(j=0;str2[j]!='\0';j++)
		{
			if(str1[i] == str2[j])
			{
			 break;
			}
			count++;
		}
		if(count == n)
		{
		 printf("     :%c\n",str1[i]);
		}
		count =0;

	}
}
