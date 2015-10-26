int fact(int n)
{
	int retval=1;
	int i=0;
	for(i=n ; i>=1 ; i--)
		retval *= i;
	return retval;
}
