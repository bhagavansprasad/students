void showbits(unsigned int n)
{
	unsigned int c, mask;
	int i;
	static int statvar = 0;

	if (statvar == 0)
	{
		printf("%8s", "");
		//for(i = (sizeof(n) * 8 -1); i >= 0; i--)
		for(i = (31); i >= 0; i--)
		{
			printf("%3d", i);
		}
		printf("\n");
		statvar = 1;
	}

	printf("%5d-->", n);

	for(i = 31; i >= 0; i--)
	{
		mask = 1 << i;
		c = n & mask;
		printf("%3d", (c == 0 ? 0 : 1));
	}

	printf("\n");
}

