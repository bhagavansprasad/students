#include<stdio.h>
main()
{
    int a=300;
//	char str[10] = "NUMIKL";
//	char *str="numlp";
	int i;
	unsigned char *p;
	p=&a;
	
//	printf("%x = %c \n %x = %c\n",str,*str,str+1,*(str+1));

	for(i=0;i<=3;i++)
	{
		printf("%d\t",*(p+i));	//this is little indian
		printf("%x\t",(p+i));

	}
	printf("\n");
}	
