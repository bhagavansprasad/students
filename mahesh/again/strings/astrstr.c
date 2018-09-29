#include <stdio.h>
char *astrstr(char *s1,char *s2)
{
	int i, j,k,f=0;
	for(i=0;s1[i];i++)
	{
		k=i;
		if(s1[k] == s2[0])
		{
			for(j=0;s2[j];j++,k++)
			{
				if(s2[j] != s1[k])
				{
					f=1;
					break;
				}
			}
		}
		if(!s2[j])
			return (&s1[i]);
	}
	return NULL;
}
main()
{
	char *p;
	p = astrstr("placement section","cement");
	if(p == NULL)
		printf("there is no substring\n");
	else 
		printf("%s\n",p);
}
