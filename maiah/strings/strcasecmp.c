#include <stdio.h>
#include <string.h>
int astrcasecmp(char *s2,char *s1);
char to_lower(char s2);
main()
{
	int t=0; 
	char s1[25]="VEnkaTesA",s2[25]="venKATEsa";
	t=astrcasecmp(s2,s1);
	if(t==0)
		printf("same\n");
	else
		printf("not same\n");
}
int astrcasecmp(char *s2,char *s1)
{
	int i=0;
	while(to_lower(s2[i]) == to_lower(s1[i]))
	{
		if(s2[i]=='\0')
			return 0;
		i++;
	}
	return 1;
}
char to_lower(char s2)
{
	if(s2 >= 'A' && s2 <= 'Z')
		s2=s2+32;
	return s2;
}
