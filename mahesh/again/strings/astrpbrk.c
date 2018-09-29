#include <stdio.h>
char *astrpbrk(char *s1, char *s2)
{
	int i,j;
	for(i=0;s1[i];i++)
	{
		for(j=0;s2[j];j++)
		{
			if(s1[i]==s2[j])
				return (&s1[i]);
		}
	}
}
main()
{
	char *p1,*p2,*p3;
	p1 = astrpbrk("abcmnop","lmn");
	p2 = astrpbrk("abcmnop","ln");
	p3 = astrpbrk("1234ABCD","COT");
	printf("%s\t%s\t%s\n",p1,p2,p3);
}
