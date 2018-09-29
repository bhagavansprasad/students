#include <stdio.h>
#include <string.h>
main()
{
	char arr[]="000000002050";
	char arr2[5],amount[10];
	int a[2],i=0,j=7;
	for(i=0;i<2;i++,j+=2)
	{
		strncpy(arr2,arr+j,2);
		arr2[2]='\0';
		a[i]=atoi(arr2);
	}
	sprintf(amount,"$%d.%d",a[0],a[1]);
	printf("%s\n",amount);
}
