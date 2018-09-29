#include <stdio.h>
#include <string.h>
char returnFirstNonRepeatedChar(char *);
main()
{
	char str[50]="abcdabccddddeeeeffgahaaa";
	char s=returnFirstNonRepeatedChar(str);
	printf("%c\n",s);
}
char returnFirstNonRepeatedChar(char *str)
{
    int i,j,repeated;
    int len = strlen(str);

    for( i = 0; i < len; i++ )
    {
        repeated = 0;
        for( j = 0; j < len; j++ )
        {
            if( i != j && str[i] == str[j] ) 
			{
                repeated = 1;
                break;
            }
        }         

        if( repeated == 0 ) 
		{  
			return str[i];
        }
    }

    return 0;
}
