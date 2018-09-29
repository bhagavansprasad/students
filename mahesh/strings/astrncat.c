#include <stdio.h>
#include<string.h>

char* astrncat (char *p1,char *p2,int n)
{
	int j,i;
	j=strlen(p1);

	//printf("%d\n",j);
	for(i=0;i<n;i++)
	{
		p1[j]=p2[i];
		j++;
	}
	p1[j]='\0';
	return(p1);
}
