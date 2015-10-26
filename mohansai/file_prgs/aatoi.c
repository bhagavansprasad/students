#include"stdio.h"

int aatoi(char *name)
{
	int i,temp = 0, temp1 = 0 ;
	for(i=0 ; name[i] != '\0' ; i++)
	{
		if(name[i]>='0' && name[i]<='9')
		{
			temp=name[i]-48;
			temp1 = temp1 * 10 + temp;
		}
	}
	return(temp1);
}


