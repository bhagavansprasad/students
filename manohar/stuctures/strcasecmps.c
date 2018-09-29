#include<stdio.h>
#include<string.h>
main()
{
      int n=3;
    char s1[]="Manohar";
	char s2[]="MANUhar";
	int retval = astrncasecmp(s1, s2,n);
    if(retval==0)
		printf("both are same");
	else
		printf(" both are not same");
	printf("\n");
}

int astrncasecmp(char*s1, char*s2, int m)
{ 
	int i=0;
	for(i=0 ; i<3; i++)	
	{	
		if(s1[i] == s2[i])
		continue;
		if(s1[i] != (s2[i]+32) && s1[i] != (s2[i]-32))
		return 1;

	}
	return 0;
}


