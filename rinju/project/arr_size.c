#include<stdio.h>
main()
{
	int c=0,i,n;
	char arr[] = "rinju 10 20 30";
	for(i=0;i < sizeof(arr);i++)
	{
			n = sizeof(arr)/sizeof(arr[i]);
		c++;
	}
	
	printf("c=%d",c);
}


