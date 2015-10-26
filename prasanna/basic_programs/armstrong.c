//WAP to check whether a number is armstrong or not

#include<stdio.h>
main()
{
	int n, temp, d, arm=0;
	printf("\nEnter any number: ");
	scanf("%d", &n);
	temp = n;
	while (temp > 0)
	{
		d = temp%10;
		temp = temp/10;
		arm = arm + (d*d*d);
	}
	if (arm == n)
		printf("\n\n%d is an Armstrong number\n", n);
	else
		printf("\n\n%d is not an Armstrong number\n", n);

}
