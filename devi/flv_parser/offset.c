int offset_value(int n)
{
	int b = 0, d = 0;
	b = decimaltobinary(n);
	d = binarytodecimal(b);
	return d;
}

int decimaltobinary(int n)
{
	int rem, i = 1, binary=0;
	while (n!=0)
	{
		rem = n%2;
		n/=2;
		binary+=rem*i;
		i*=10;
	}
	return binary;
}

int binarytodecimal(int n)
{
	int rem, d, j,dec = 0;
	for(j = 1; n > 0; n/=10, j*=2)
	{
		rem = n%10;
		d = rem*j;
		dec+=d;
	}
	return dec;
}
