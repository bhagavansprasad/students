#include <stdio.h>
main()
{
	int x=0;
	char s1[15] = "bhaga Networks";
	char s2[15] = "theja Networks";
	char s3[15] = "Aura Networks";

	int i=2;
	x = astrcmp(s2,s3);
	if(x==1)
		printf("\nthe str is diff:, %s,%s\n\n",s2,s3);
	else
		printf("\nthe str is same:,%s,%s\n\n",s2,s3);
	x = astrncmp(s2,s3,i);
	if(x==1)
		printf("\nthe str is diff:, %s,%s,%d\n\n",s1,s2,i);
	else
		printf("\nthe str is same:,%s,%s,%d\n\n",s1,s2,i);
}
int astrcmp(char *s3, char *s2)
{
	int i=0;		
	for(i=0;  s2[i] != '\0'; i++)
		{
			if(s2[i] != s3[i])
			{
				return 1;
			}
		}
			return 0;
}
int astrncmp(char *s1, char *s2,int n)
{
	int i=0;		
	for(i=0;  i<=n && s1[i] != '\0'; i++)
		{
			if(s1[i] != s2[i])
			{
				return 1;
			}
		}
			return 0;
}
