#include "a_string.h"
char *a_strstr(const char *dest,const char *src)
{
	int i,j,p;
	p=a_strlen(src)-1;
	for(i=0 ; dest[i] ; i++)
	{
		if(dest[i]==src[0])
		{
			for(j=1 ; src[j] ; j++)
			{
				if(dest[i+j]==src[j])
				{
					if(j==(p))
						return (char*)&dest[i];
				}	
			}
		}
	}
	return '\0';
}
