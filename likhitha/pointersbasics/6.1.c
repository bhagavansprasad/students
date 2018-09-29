#include <stdio.h>
main()
{
	int a=0x12131415;

//	printf("0x%x\n",a);
	
	//printing individual byte
	char *p=(char*)&a;
	int i;
	//printf("0x%x\n",*p);
	for(i=4 ; i>0 ; i--)
	{
		printf("0x%x\n",*p);
		p++;

	}
	/*
	   printf("0x%x\n",*p);
	   printf("0x%x\n ",*(p+1));
	   printf("0x%x\n ",*(p+2));
	   printf("0x%x\n ",*(p+3));
	 */






/*
	//printing short int
	short int *p=(short int*)&a;
	printf("0x%x\n",*p);
	printf("0x%x\n ",*(p+1));
*/



/*
	//printing individual byte
	char *p=(char*)&a;
	printf("0x%x\n ",*(p+3));
	printf("0x%x\n ",*(p+2));
	printf("0x%x\n ",*(p+1));
	printf("0x%x\n",*p);
*/
}
