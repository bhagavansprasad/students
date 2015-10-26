/*- Fill 'value' and 'types' columns for each notation
NOTE: Assume adress of variables a, pa, ppa, ppa are 500, 600, 700 and 800
respctively
 */
#include <stdio.h>
int  main()
{
	int a = 10;
	/*int *pa = &a;
	  int **ppa = &pa;
	  int ***pppa = &ppa;

	//Notation  Value    Type
	//.--------.-------.---------.
	printf("a=%d\n",a);
	printf("&a=%p\n",&a);
	printf("pa=%p\n",pa);
	printf("&pa=%p\n",&pa);
	printf("*pa=%d\n",*pa);
	printf("&*pa=%p\n",&*pa);
	printf("ppa=%p\n",ppa);
	printf("*ppa=%p\n",*ppa);
	printf("&*ppa=%p\n",&*ppa);
	printf("**ppa=%d\n",**ppa);
	printf("&**ppa=%p\n",&**ppa);
	printf("***pppa=%d\n",***pppa);
	printf("&***pppa=%p\n",&***pppa);
	printf("&pppa=%p\n",&pppa);
	printf("*pppa=%p\n",*pppa);                   
	printf("&*pppa=%p\n",&*pppa);
	printf("&**pppa=%p\n",&**pppa);

	//'--------'-------'---------'

	- Print each byte value of 4 bytes for variable 'a', if 
	int a = 300;

	- What is the output of the below program?
	address of a is 500*/

	// a = 20;
	int *po;
//	printf("\n\n\npo=%d\n",po);
	po	   = &a; 

	printf("\n\n\n\n*po=%d\n",*po);
	printf("(char *)po=%u\n",(char *)po);
	printf("po+1=%u\n",po + 1);
	printf("((char *)po)+1=%u\n",((char *)po) + 1);
	printf("(*(char *)Po)+1=%d\n",(*(char *)po) + 1);
	printf("*((char *)po+1)=%d\n",*((char *)po + 1));
	/*
	   - Is there a quick way to determine Endianness of your machine?
	   'Little Endian or Big Endian'

	   - Write a program to reverse the Endianness*/


	return 0;
}
