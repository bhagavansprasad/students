#include<stdio.h>
int astrcmp(char *bat, char *bat2);
main()
{
	char bat [ ] = "A boy baby from Londan ";
	char bat2[ ] = "A boy baby from Delhi ";

	int i;
	int result;
        char a [ ] = "Successful";
        char b [ ] = "unsuccessful";

	result = astrcmp ( bat, bat2);

	if ( result == 0 )
        printf ("\n--> String is Successful\n");
	
        //      result =(char *) a ;
	else 
	//	result = (char *)b ;   
        printf ("\n--> String is Unsuccessful\n");
        
	//printf( "--> String is %s\n --> 1st String  is %s \n --> 2nd string is %s\n", result , bat, bat2 );
        printf ("\n--> 1st String is ==>> %s \n--> 2nd string is ==>> %s \n ", bat , bat2);


}
int astrcmp ( char *s1 , char *s2 )  
{
	int i;
	int c;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++ )
	{
		if ( s1[i] == s2[i] )
               {
			printf (" %c", s2[i]);
			c = 0 ;
		}
 	else 
        c = 1 ;
        
       
        }

         return c;
}
