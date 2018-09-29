#include<stdio.h>
#include<string.h>
int astrcasecmp(char arr1[],char arr2[])
{
	int i;
	for(i=0;arr1[i];i++)
	{
		if(arr1[i]==arr2[i]-32||arr1[i]==arr2[i]+32);
		else 
		{
			return 0;
		}
	}
	return 1;
}
main()
{
	char str1[20]="salmaMATEEN";
	char str2[20]="SALMAmateen";
	int t;
	t=astrcasecmp(str1,str2);
	if(t==1)
		printf("both strings r same\n");
	else
		printf("both stringd r different \n");
}
