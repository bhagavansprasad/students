#include <stdio.h>
int astrcspn(char *s1,char *s2)
{
	int i,j,c = 0;
	for(i=0;s1[i];i++)
	{
		for(j=0;s2[j];j++)
		{
			if(s1[i] == s2[j])
				break;
		}
		if(s2[j]=='\0')
			c++;
		else 
		break;
	}
	return c;
}
main()
{
	int a,b,c;
	a = astrcspn("abcmnop","lmn");
	printf("a is %d\n",a);
	b = astrcspn("J P Nagar 6 phase","0123456789");
	printf("a is %d\n",b);
	c = astrcspn("structure","aeiou");
	printf("a is %d\n",c);
}
