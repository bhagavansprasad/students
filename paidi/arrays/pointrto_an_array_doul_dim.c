#include <stdio.h>
int main()
{
	int arr[3][4]={
		{10,11,12,13},
		{20,21,22,23},
		{30,31,32,33}
	};

	int (*ptr) [4];
	ptr = arr;
	printf("%p   %p   %p\n",ptr,ptr+1,ptr+2);
	printf("%p   %p   %p\n",*ptr,*(ptr+1),*(ptr+2));
	printf("%d   %d   %d\n",**ptr,*(*(ptr+1)+2),*(*(ptr+2)+3));
	printf("%d   %d   %d\n",ptr[1][0],ptr[1][2],ptr[2][3]);

	printf("print last adress-1 %d\n",*((int*)(&arr+1)-1));
	printf("print last adress-1 %d\n",*((int*)(&arr+1)-2));
#if 0
	int (*p)[4] = &arr;/* wrong intialization*/
	printf("%p   %p   %p\n",p,p+1,p+2);
	printf("%p   %p   %p\n",*p,*(p+1),*(p+2));
	printf("%d   %d   %d\n",**p,*(*(p+1)+2),*(*(p+2)+3));
	printf("%d   %d   %d\n",p[0][0],p[1][2],p[2][3]);
#endif
}
