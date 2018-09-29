#include <stdio.h>
#include<string.h>
int length(char *p);
main()
{
	int t=0;
	char a[15]= "How Are You";
		t=length(a);
	printf("%d",t);
}
int length(char *p)
{
	int i=0,n,sum=0;
	for(i=0;p[i]!='\0';i++)
	{
		if (p[i]>=65 && p[i]<=91)
		{
			sum=sum+1;
		}
	}
	return (sum);
}
