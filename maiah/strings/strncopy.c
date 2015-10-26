#include<stdio.h>
char* astrncpy(char *s2,char *s1,int l)
{
	int i=0;
	while(i<l)
	{
		if(*s1!='\0')
		{
		*s2=*s1;
		i++;
		s1++;
		s2++;
		}
		else 
		//return s2;
		*s2='\0';
	}
	//return s2;
	*s2='\0';
}
main()
{
	char s1[25]="venkatesh",s2[20];
	int l=6;
	char *t=astrncpy(s2,s1,l);
	printf("%s\n",s2);
}

