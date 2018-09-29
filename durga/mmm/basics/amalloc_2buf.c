#include <stdio.h>
char buf1[100];
char buf2[100];
int flag1 = 0;
int flag2 = 0;
void* amalloc(int );
void afree(void* );
main()
{

	int * ptr1[2]  , *ptr2[2];
	printf("buf1 retrn address %u\n",buf1);
	printf("buf2 return address %u\n",buf2);
<<<<<<< amalloc_2buf.c
	ptr1 = amalloc(100);
	printf("amalloc return address %u\n",ptr1);
	ptr1 = amalloc(100);
	printf("amalloc return address %u\n",ptr1);
	afree(ptr1);
	ptr2 = amalloc(100);
	printf("amalloc return address %u\n",ptr2);
	afree(ptr1);
	ptr2= amalloc(100);
	printf("amalloc return address %u\n",ptr2);
=======
	ptr1[0] = amalloc(100);
	printf("amalloc return address %u\n",ptr1[0]);
	ptr1[1] = amalloc(100);
	printf("amalloc return address %u\n",ptr1[1]);
	afree(ptr1[0]);
	ptr2[0] = amalloc(100);
	printf("amalloc return address %u\n",ptr2[0]);
>>>>>>> 1.2
}

void* amalloc(int size)
{
	if(flag1 == 0)
	{
		flag1 =1;
		return((void*)buf1);
	}
	else if(flag2 == 0)
	{
		flag2 = 1;
		return((void*)buf2);
	}
	else 
		return NULL;
}

void afree(void* p)
{
	if(p == buf1)
	{
		flag1 = 0;
	}
	else if(p == buf2)
	{
		flag2 = 0;
	}
	else
		printf("memory is not avlibule\n");
}


