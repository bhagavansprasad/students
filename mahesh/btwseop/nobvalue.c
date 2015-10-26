#include<stdio.h>
void showbits(unsigned char m);

main()
{
	unsigned char n=0xD9;
	unsigned char a;
	unsigned char b;
	int pos=4,nob=4;
	a=n<<(pos-(nob-1));
	b=a>>(8-nob);
	printf("%x\n",b);
		printf("%d\n",b);
		showbits(b);
}
void showbits(unsigned char m)
{ 
		int i;
		unsigned char a;
	for (i=7;i>=0;i--)
	{
		a=m&(1<<i);
		a==0?printf("0"):printf("1");
	}
}
