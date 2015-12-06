#include<stdio.h>

main()
{
	

		char brr[]="bak";


	char arr[]={'A','u','r','a','\0'};


//	char crr[]="hey";

	char a='B';

	char arr2[]="Aura";

	char arr1[]="Hello";

	printf("arr:%s\t c:%p\t c1:%p\t c2:%p\t c3:%p\tc4:%daddrs:%p\n",arr,&arr[0],&arr[1],&arr[2],&arr[3],arr[4],arr);


	printf("arr:%s\t c:%c\t c1:%c\t c2:%c\t c3:%c\tc4:%caddrs:%p\n",arr,arr[0],arr[1],arr[2],arr[3],arr[4],arr);

	printf("brr adrs:%p\n",brr);

//	printf("crr addrs:%p\n",crr);

	printf("addes:%p\n",&a);


	printf("arr1:%s addrs:%p \t d:%c\t d1:%c\t d2:%c\t d3:%c\t	d4:%d\td5:%d\n",arr1,arr1,arr1[0],arr1[1],arr1[2],arr1[3],arr1[4],arr[5]);

	printf("arr:%d\t arr2:%d arr len:%d\n",sizeof(arr),sizeof(arr2),strlen(arr));


}	

