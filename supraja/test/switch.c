#include <stdio.h>
main()
{
	char i=65;
		switch(i)
		{
			case 'a':printf(" iam in a :\n");
					 break;
					 {		 
						 case 'b':printf(" iam in b :\n");
								  break;
					 }		 
			default:printf("iam in default\n");
					break;
		}		 
}		
