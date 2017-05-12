#include <stdio.h>
int ins_ele (int *a,int n,int pos,int k);
int del_ele (int *a,int pos,int k);
//int sort(int *a,int k);

void dump_array(int *p, int size)
{
	int i = 0;

	for(i = 0; i < size; i++)
		printf("%3d", p[i]);
	
	printf("\n");
}

main()
{
	int arr[]={5,7,9,6,2,3};
	int num=7,pos=4;
	int i,a;
	int size = sizeof(arr)/sizeof(int);

	dump_array(arr, size);

	printf("Num :%d pos: %d\n", num,pos);
	for ( i = 0; i < a; i++)
		printf("%3d", arr[i]);

	ins_ele(arr,num,pos,a);

	printf("\n");

	printf("pos: %d\n",pos);
	for ( i = 0; i < a+1; i++)
		printf("%3d", arr[i]);

	printf("\n");
	printf("\n");

	printf("pos: %d\n",pos);
	for ( i = 0; i < a; i++)
		printf("%3d", arr[i]);
	printf("\n");


	size = del_ele(arr, pos, size);

	dump_array(arr, size);

	/*			
				sort(arr,a);

				printf("\n");
				for ( i = 0; i < sizeof(arr)/sizeof(int); i++)
				printf("%d",arr[i]);
	 */
}

