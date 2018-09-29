#include<stdio.h>
void showbits(unsigned char m);

main()
{
	 static unsigned char n=170;
	int i;
	showbits(n);
	printf("\n");
 for (i=7;i>=0;i--)
 {
	n=n^(1<<i);
	showbits(n);
	printf("\n");
 }

}
void showbits(unsigned char m)
{
	unsigned char a;
	int i;
	for(i=7;i>=0;i--)
	{
		a=m&(1<<i);
		a==0?printf("0"):printf("1");
	}
}
