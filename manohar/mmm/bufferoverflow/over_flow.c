#include <stdio.h>

//char arr[8] = "AuraNet";
//int a = 0xabcd1234;
//int b = 0xabcd1234;
//int c = 0xabcd1234;
int main()
{
	char arr1[8] = "AuraNet";
	char arr2[9] = "BuraNet";
	int i = 0;
for(i=0;i<8;i++)
{
	printf("arr1 :%u\n", &arr1[i]);
	}
for(i=0;i<8;i++)
{
	printf("arr2 :%u\n", &arr2[i]);
	}

   /*printf("arr1 :%u\n", &arr1[1]);
	printf("arr1 :%u\n", &arr1[2]);
	printf("arr1 :%u\n", &arr1[3]);
	printf("arr1 :%u\n", &arr1[4]);
	printf("arr1 :%u\n", &arr1[5]);
	printf("arr1 :%u\n", &arr1[6]);
	printf("arr1 :%u\n", &arr1[7]);
	printf("arr2 :%u\n", arr2);
	printf("arr2 :%u\n", &arr2[1]);
printf("arr2 :%u\n", &arr2[2]);
	printf("arr2 :%u\n", &arr2[3]);
	printf("arr2 :%u\n", &arr2[4]);
	printf("arr2 :%u\n", &arr2[5]);
	printf("arr2 :%u\n", &arr2[6]);
	printf("arr2 :%u\n", &arr2[7]);
*/
	printf("-->Before\n");
	printf("arr1 :%s\n", arr1);
	printf("arr2 :%s\n", arr2);
for (i = 0; i < 9; i++)
		arr2[i] = 'a';

	printf("-->After\n");
	printf("arr1 :%s\n", arr1);
	printf("arr2 :%s\n", arr2);

	return 0;
}
