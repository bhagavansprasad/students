#include <stdio.h>
#include <string.h>
int find_firstNR(char str[]);
main()
{
	char str[50]="sreenu reddy suresh";
	printf("--->the val is: %d\n",find_firstNR(str));
}
int find_firstNR(char str[])
{
	int i,j;
	int end=strlen(str)-1;
	for(i=0;i<end;i++)
	{
		for(j=0;j<=end;j++)
		if(str[i]==str[j] && i!=j)
		break;
		if(j==end+1)
		return i;
	}
	return -1;
}
