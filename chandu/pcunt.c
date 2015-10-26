#include<stdio.h>
#include<string.h>
int pair_cunt(char *p);
char a[50] = "ab ddee xyzz";

main()
{
	int t=0;
	t = pair_cunt(a);
	printf("%d\n",t);
}

int pair_cunt(char *p)
{
	int i=0, count =0;
	for(i=0;p[i]!='\0'; i++)
	{
		if(p[i]==p[i-1] )
		{
			count++;
		}
	}
	return(count);
}
