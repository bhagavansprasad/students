#include <stdio.h>
main()
{
	int t,l=6;
	char s1[20]="venkatesamaiah",s2[20]="venkatesh";
	t=astrncmp(s1,s2,l);
	if(t==0)
	printf("same\n");
	else
	printf("not same\n");
}
int astrncmp(char *s1,char *s2,int l)
{
	int i=0;
	while(i<l)
	{
		if(*s1==*s2)
		{
			if(*s1=='\0')
			return 0;
			i++;
			s1++;
			s2++;
		}
		else 
		return 1;
	}
	return 0;
}
