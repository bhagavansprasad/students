#include <stdio.h>
#include <string.h>
int main()
{
	int i;
	char arr[4][10]={"paidi",
 					 "Aura",
					 "Institute",
					 "Bangalore"
					};
	char *ptr[4];
	for(i=0;i<4;i++)
	{
		ptr[i] = arr[i];
		printf("ptr[%d]       = %s\n",i,*(ptr+i));
	}

}
