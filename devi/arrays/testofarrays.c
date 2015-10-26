#include <stdio.h>
main()
{
	unsigned int arr[10] = {10, 20, 30};

	printf("arr[2]-->%d\n",arr[2]);
	printf("arr[3]-->%d\n",arr[3]);
	printf("arr[1]-->%d\n",arr[1]);
	printf("*(arr+1)-->%d\n",*(arr + 1));
	printf("*(1+arr)-->%d\n",*(1 + arr));
	printf("1[arr]-->%d\n",1[arr]);
	//* In case of array base address is 500

	//				Type	Value
	printf("arr+1-->%u\n",arr + 1);
	printf("1+arr-->%u\n",1 + arr);
	printf("arr->%u\n",&arr);
	printf("&arr+1-->%u\n",&arr + 1);



	printf("*************\\n");
	printf("sizeof(arr)-->%d\n",sizeof(arr));
	printf("sizeof(&arr)-->%d\n",sizeof(&arr));
	printf("sizeof(*arr+1)-->%d\n",sizeof(*arr+1));
	printf("*************\\n");
}

//- Find the size of the array if the input is
// 'name of the array' and the 'data type'


