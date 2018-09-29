#include<stdio.h>
#include<string.h>
//#pragma pack(1)
main()
{
	struct hole
	{
	    char ch;
        //double d;
		//double d1;
		//long int i;
		short sh1;
	    //float f;
		char ch1;
		//int a;
        //short sh;
		//char ch2;
		//int b;
		//short sh2;
		//int c;
	}hole;

	///struct hole holes;
	printf("size of hole is : %ld\n", sizeof(hole));
   //	printf("size  of d is : %d\n", sizeof(hole.d));

	//printf("address of ch is : %p\n", &hole.ch);
	//printf("address of d is : %p\n", &hole.d);
	//printf("address of d1 is : %p\n", &hole.d1);
	//printf("address of i is : %p\n", &hole.i);
	//printf("address of sh1 is : %p\n", &hole.sh1);
	//printf("address of f is : %p\n", &hole.f);
	//printf("address of ch1 is : %p\n", &hole.ch1);
	//printf("address of a is : %p\n", &hole.a);
	//printf("address of sh is : %p\n", &hole.sh);


}

