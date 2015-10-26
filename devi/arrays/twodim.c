#include <stdio.h>
void singlearr(int *ar)
{
int i;
for(i=0;i<10;i++)
printf("%d\n",ar[i]);
}
void doublearr(int **p)
{
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			printf("%d\n",p[i][j]);
}
main()
{
	int a[3][3] = {10,20,30,40,50,60};
	unsigned int arr1[10] = {-5,-4,-3,-2,-1,0,1,2,3,4};
	unsigned char arr[10] = {-5,-4,-3,-2,-1,0,1,2,3,4};
	int i,j;
	singlearr(arr1);
	//printf("%u\n",a);
	doublearr(a);
}
	/*for(i=0;i<11;i++)
	{
		printf("%d\n", arr1[i]);
		printf("%d\n", arr[i]);
	}
	//for(i=0;i<3;i++)
	//	for(j=0;j<3;j++)
	//		printf("arr[%d][%d]=%u\t%d\n", i,j,&a[i][j],a[i][j]);
	
	//printf("%u\n", &a);
	//printf("%u\n", &a+1);
	//printf("%u\n", a[2]);
	//printf("%u\n", &a[2]);
	//printf("%u\n", a[1]);*/
