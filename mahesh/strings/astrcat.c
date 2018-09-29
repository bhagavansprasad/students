#include<string.h>

char* astrcat (char *p1,char *p2)
{
	int j,i;
	j=strlen(p1);

	//printf("%d\n",j);
	for(i=0;p2[i]!='\0';i++)
	{
		p1[j]=p2[i];
		j++;
	}
	p1[j]='\0';
	return(p1);
}
