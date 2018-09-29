#include <stdio.h>
main()
{
	int a[5]={2,3,7,4,9};
	int key=0 ;
	int i , n=5 , flag=0;
	for(i=0 ; i<n ; i++)
	{
		if(a[i]==key)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("%d is found\n",key);
	else
		printf("%d is not found\n",key);

}
