#include<stdio.h>
main()
{
	char s2[100]="sai umesh saketh ram klsajdflj";
	char s1[100]="sai umesh saketh ram klsajdflj";
	
	int rv = strcmp(s1, s2);

	if(rv==0)
	{
		printf("they are equal\n");
	}
	else 
		printf("they are not equal\n");
}		

int strcmp (char *s1, char *s2)
{
	int i = 0;

	for( ;(s1[i] == s2[i]); i++);
	return (s1[i] - s2[i]);
}
#if 0

	!= '\0' || s2[i] != '\0'; i++)
	for(i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if(s1[i]==s2[i])
		{
			continue;
		}
		else 
			return 1;
	}
	return 0;
}
#endif
