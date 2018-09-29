#include <stdio.h>
int astrstr(char * ms ,char * ss);
main()
{
	char ms[30] = "predetermination";
	char ss[20] = "term";
	char *p;
	p = astrstr(ms, ss);
	printf("%p\n", p);
	if(p != NULL)
		printf("   %s \n", p);
	else 
		printf("there is no substring\n");
}
int astrstr(char * ms, char * ss)
{
	int i = 0, j = 0, k = 0;
	for(i = 0; ms[i] != '\0'; i++)
	{
		if(ms[i] == ss[0])
		{
			k = i;
			for(j = 0; ss[j] != '\0'; j++, k++)
			{
				if(ms[k] != ss[j])
					break;
			}
			if(ss[j] == '\0')
			{
				printf("  %p\n", &ms[i]);
				return (&ms[i]);
			}
		}
	}
	return 0;
}

