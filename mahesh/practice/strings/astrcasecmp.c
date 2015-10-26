#include <stdio.h>
char astrlwr(char ch)
{
	if(ch>=65&&ch<=90)
		ch += 32;
	return ch;
}
int astrcasecmp(char *s1,char *s2)
{
	int i=0,j=0,k=0;
	for(i=0;s1[i]||s2[i];i++)
	{
		j=astrlwr(s1[i]);
		k=astrlwr(s2[i]);
		if(j!=k)
			return (j-k);
	}
	return 0;
}
main()
{
	char s1[]="bangalore";
	char s2[]="bangalore ";
	int i=0;
	i=astrcasecmp(s1,s2);
	if(!i)
		printf("equal\n");
	else printf("not equal\n");
}
