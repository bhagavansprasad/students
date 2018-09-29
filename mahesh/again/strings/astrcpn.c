#include <stdio.h>
#include <string.h>
int astrspn(char *s1,char *s2)
{
	int i, j,count = 0;
	for(i = 0; s1[i]; i++)
	{
		for(j = 0;s2[j];j++)
		{
			if(s1[i] == s2[j])
			{
				count++;
				break;
			}
		}
		if(s2[j] == '\0')
			break;
	}
	return count;
}
main()
{
	int n = 0, m = 0, l = 0;
	n = astrspn("c in depth","abcd");
	printf("first n is : %d\n",n);
	m = astrspn("2012 purva belmont","0123456789");
	printf("second n is : %d\n",m);
	l = astrspn("  	main"," \t");
	printf("third n is : %d\n",l);
}
