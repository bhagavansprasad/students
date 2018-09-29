#include <stdio.h>
main()
{
	int a = 0x12131415;
	int *c = &a,ch1;
	//	printf("%d\n",sizeof(c));
	printf("%x\n",a);
	//	printf("%d\n",sizeof(a));
	ch1=*c;
	*c=*(c+3);
	*(c+3)=ch1;
	//	printf("\n a val after swap %x\n",a);
	ch1=*(c+2);
	*(c+2)=*(c+1);
	*(c+1)=ch1;
	printf("a val after swap %x\n",a);
}
