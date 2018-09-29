#include <stdio.h>
void fun(int num,int b);
main()
{
	int num=20,ch;
	printf("1.binary\n2.octal\n3.hexa\n");
	//printf("enter your choice:");
	ch =2;
	switch(ch)
	{
		case 1:
				printf("binary equivalent is :");
				fun(num,2);
				break;
		case 2:
				printf("octal equivalent is :");
				fun(num,8);
				break;
		case 3:
				printf("hexa equivalent is :");
				fun(num,16);
				break;
	}
	printf("\n");
	return 0;
}
void fun(int num,int b)
{
	int i=0,rem,j;
	char arr[20];
	while(num>0)
	{
		rem=num%8;
		num=num/8;
		if(rem>9 && rem<16)
		arr[i++]=rem-10+'A';
		else
		arr[i++]=rem+'0';
	}
	for(j=i-1;j>=0;j--)
	printf("%c",arr[j]);
}
