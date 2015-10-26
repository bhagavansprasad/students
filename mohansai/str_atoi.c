#include "stdio.h"
#include "string.h"
int atoi(char *name);
main()
{
	int i;
	char name[]="123ed";

	i=atoi(name);

	printf("%d\n\n",i);
}


int atoi(char *name)

{
	int i,temp = 0, temp1 = 0 ;
	
	for(i=0 ; name[i] != '\0' ; i++)
	{
		if(name[i]>='0' && name[i]<='9')
		{
			temp=name[i]-48;
			temp1 = temp1 * 10 + temp;
		}
		else
		
			return(temp1);


		
	
	}
	
		
}
