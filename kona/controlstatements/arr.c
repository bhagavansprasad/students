#include <stdio.h>
main()
{
	int i,a[10]={12,5,14,87,6,3,16,58,14,8};
	int small,large;
	 small=large=a[0];
	for(i=1;i<10;i++)
	{
		if(small>a[i])
		small=a[i];
		if(large<a[i])
		large=a[i];
	}
	printf("small is %d large is %d\n",small,large);
}
