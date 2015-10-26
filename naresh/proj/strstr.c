#include<stdio.h>
char* astrstr(char *mm,char *ss)
{
	int i=0,j=0,k;
	for(i=0;mm[i];i++)
	{
		if(ss[0] == mm[i])
		{
			k=i;
			for(j=0;ss[j];j++,k++)
			{
				if(ss[j] != mm[k])
					break;
			}
			if(ss[j]=='\0')
				return &mm[i];
		}
		
	}
return NULL;
}	
main()
{
	char mm[]="excinment offer of d day";
	char ss[]="ments";

	char *t;
	t = astrstr(mm,ss);
	if(t != NULL)
		printf("---->%s\n",t);
	else 
		printf("there is no sub string in main string\n");

}
