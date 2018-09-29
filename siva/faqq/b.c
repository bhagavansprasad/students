is_prime(int n)
{
int i;
for(i=2;i<n-1;i++)
{
	if(i%n==0)
	{
		printf("not prime\n");
	}
	if(i==n)
	{
		printf("prime number");
	}
}
}
