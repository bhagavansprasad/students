#include "stdio.h"
char * strstr(char * ms,char * ss);
main()
{
	char ms[20]="reddy vinay";
	char ss[20]="vinay";
	int *t;
	t=strstr(ms,ss);
	printf("%s\n",t);
}
char * strstr(char * ms,char * ss)
{
	int i=0,j=0,k=0;
	for(i=0;ms[i];i++)
	{
		if(ss[0]==ms[i])
		{
			k=i;
			for(j=0;ss[j];j++,k++)
			{
				if(ss[j]!=ms[i])
						break;
			}
						if(ss[j]!='\0')
						return &ms[i];
			}		
	}
	return NULL;
}
