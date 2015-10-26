#include<stdio.h>
void func(int num,int b);
main(void)
{
	int num,ch;
	printf("enter a decimal number");
	scanf("%d",&num);
	printf("1.binary\n2.octal\n3.hexadecimal\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
case 1:
      printf("binary equivalent is :");
	  func(num,2);
	  break;
case 2:
      printf("octal equivalent is :");
	  func(num,8);
	  break;
case 3:
      printf("hexadecimal equivalent is :");
	  func(num,16);
	  break;
	}
	printf("\n");
}
void func(int num,int b)
{
	int rem,i=0,j;
	char arr[20];
	while(num>0)
	{
		rem=num%b;
		num=num/b;
		if(rem>9 && rem<16)
			arr[i++]=rem-10+'A';
		else
			arr[i++]=rem+'0';
	}
	for(j=i-1;j>=0;j--)
		printf("%c\n",arr[j]);
}
