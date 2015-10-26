#include <stdio.h>
#include <string.h>
int length(char *p);
main()
{
	int t=0;
	char a[15]="HoW ArE You";
	t=length(a);
	printf("%d",t);
}
int length(char *p)
{
	int i,sum=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>=97 && p[i]<=122)
		{ 
			sum=sum+1;
		}
	}
	return (sum);
}
