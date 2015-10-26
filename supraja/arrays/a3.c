#include<stdio.h>
int main()
{
	int a[3][4]={
		{1,2,3,4},
		{5,6,7,8},
		{9,0,1,2}
	};
	int i;
	for(i=0;i<=3;i++)
	{
		printf("address of %d th 1-D array=%u\n",i,a[i]);
    }
	printf("--->a:%u\n",a);
    printf("--->a[0]:%u\n",a[0]);
    printf("--->a[0][0]:%d\n",a[0][0]);
    printf("--->&a[0][0]:%u\n",&a[0][0]);
    printf("--->&a[0]:%u\n",&a[0]);
    printf("--->&a:%u\n",&a);
	printf("--->a[1]:%u\n",a[1]);
    printf("--->&a+1:%u\n",&a+1);
}
