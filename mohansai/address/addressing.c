#include"stdio.h"
unsigned int data =1;
unsigned char array1[10];
unsigned int data2;
unsigned int data3 = 3;
unsigned int data4;
unsigned short sh1;
unsigned short sh2 = 2;
unsigned int array2[10]={1,2};
unsigned short sh3;
unsigned short sh4 = 4;
unsigned char ch1=1;
unsigned char ch2;
unsigned int array3[10]={5,6};
unsigned char ch3=3;

main()
{
unsigned int ldata1;
unsigned int ldata2 = 2;
unsigned int ldata3 ; 
unsigned static int sdata1;
unsigned static int sdata2=2;
	
//	int *p=malloc(10);
		
		printf("global unsigned\n\n\r"); 	
	
	printf("this data will be stored in  in  BSS  \n\n\n\n");
	
	printf("  array1-->  %u \n", &array1);
	printf("  data2--> 	 %u \n", &data2);
	printf("  data4--> 	 %u \n", &data4);
	printf("  sh1--> 	 %u \n", &sh1);
	printf("  sh3--> 	 %u \n", &sh3);
	printf("  ch2--> 	 %u \n\n", &ch2);
	
		printf("local unsigned\n\n"); 
	
	printf("this data will be stored in  in  stack  \n\n\n\n");
	
	printf("  ldata1-->  %u \n", &ldata1);
	printf("  ldata3-->  %u \n", &ldata3);
	printf("  sdata1-->  %u \n", &sdata1);
	printf("  sdata2-->  %u  \n\n",&sdata2);
	
	printf("global signed\n\n"); 	

	printf("this data will be stored in  in  data \n\n\n\n");
	
	printf("  data--> 	 %u \n", &data);
	printf("  data3--> 	 %u \n", &data3);
	printf("  sh2--> 	 %u \n", &sh2);
	printf("  array2-->	 %u \n", &array2);
	printf("  sh4--> 	 %u \n", &sh4);
	printf("  ch1--> 	 %u \n", &ch1);	
	printf("  array3-->  %u \n", &array3);
	printf("  ch3-->  	 %u \n\n\n", &ch3);

	printf("local signed\n\n\n");
	
	printf("this data will be stored in  in  stack  \n\n\n\n");
	
	printf("  ldata2-->  %u \n", &ldata2);
	printf("  sdata2-->  %u  \n\n",&sdata2);

}
