#include <stdio.h>
#include <string.h>
main()
{
	char s1[20]="placement section";
	char s2[10]="cement";
	char *s3;
	s3=strstr(s1,s2);
	if(s3!=NULL)
	printf("%s\n",s3);
	else
	printf("there is no sub string\n");

}
char *astrstr(char *s1,char *s2)
{
	int i=0,j=0,k;
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]=s2[0])
		{
			k=i;
			for(j=0;s2[j]!='\0';j++,k++)
			{
				if(s1[k]!=s2[j])
				break;
			}
			if(s1[i]=='\0')
			return &s1[i];
		}
	}
	return NULL;
}

