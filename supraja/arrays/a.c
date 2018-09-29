#include <stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6};
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("--->a[0]:%d\n",a[0]);
    printf("--->&a[0]:%u\n",&a[0]);
    printf("--->&a[2]:%u\n",&a[2]);
    printf("--->a:%u\n",a);
    printf("--->&a:%u\n",&a);
    printf("---> a+1:%u\n", a+1);
	printf("---> &a+1:%u\n", &a+1);

 
}

