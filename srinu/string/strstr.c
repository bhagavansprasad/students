#include <stdio.h>
#include <string.h>

//char astrstr(char *s1,char *s2);

main()
{
	char s1[25]="placement section";
	char s2[10]="cement";
	char *s3;
	s3=strstr(s1,s2);
	printf("%s\n",s3);
}
char astrstr(char *s1,char *s2)
{
	char *s3;
	int i,j,k,l,p;
	for(i=0;s2[i]!='\0';i++)
		for(j=0;s1[j]!='\0';j++)
			if(s1[j]==s2[i])
			{
				for(k=i,l=j;s2[k]=s1[l];k++,l++)
				{
					for(p=0;s1[l]!='\0';p++)
						s3[p]=s1[l];
				}
				return s3[p];
			}
	return 0;
}
