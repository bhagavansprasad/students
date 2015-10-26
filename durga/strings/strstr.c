#include<stdio.h>

main()
{
	char str1[] = "placemcemnt section";
	char str2[] = "cement";
	char str3[50] ;

	int i,j,k = 0;
	for ( i = 0; str2[i] != '\0'; i++)
	
		for (j = 0; str1[j] != '0'; j++)
		{
		if(str2[i] == str1[j])
		{
			str3[k] = str1[j];
				printf("----->str3 : %c\n",str3[k]);

			k++;
		}
		}
		i = 0; 
/*	while(str3[i] != '\0')
	{
		printf("----->str3 : %c\n",str3[i]);
		i++;
	}*/
}
