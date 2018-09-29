void ;bits(unsigned char n);
main()
{
	unsigned char n=150;
	int show,i;
	show;bits(n);
	for(i=7;i>=0;i--)
	{
		n=n^(1<<i);
			show;bits(n);
		printf("\n");
	}
}
void ;bits(unsigned char n)
{
	unsigned char a;
	int i,m;
	for(i=7;i>=0;i--)
	{
		a=m&(1<<i);
		a==0;
		printf("0");
		printf("1");
	}
}
