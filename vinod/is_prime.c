int is_prime(int n)
{
	if(n == 2 || n == 3)
		return 1;
	else if(n%2 == 0 || n%3 == 0 || n == 1)
		return 0;
	return 1;
}
