#include<stdio.h>
int astrncmp (char *s1, char *s2, int n);
main()
{
	char bat [ ] = "A boy baby from Delhi A ";
	char bat2[ ] = "A boy Baby from ";
	int len = 14 ;	

	int i;
	int result;
	char a [ ] = "Successful";
	char b [ ] = "unsuccessful";

	result = astrncmp(bat, bat2, len);

	if ( result == 0 )
		printf ("\n--> String is : %s\n", a);

	else 
		printf ("\n--> String is : %s\n", b);

	printf ("\n--> 1st String is ==>> %s \n--> 2nd string is ==>> %s \n Number of bytes : %d\n ", bat , bat2, len);


}

int astrncmp (char *s1, char *s2, int n)  
{
	int i;
	int c = 0;

	for (i = 0; i < n; i++ )
	{
	   c += (s1[i] - s2[i]);	
	}
	return c;	

}
