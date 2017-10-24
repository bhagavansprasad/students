int factorial(int num)
{
	int fact = 1;

	for( ; num > 1; num--)
	{
		fact = fact * num;
	}
	return fact;
}
