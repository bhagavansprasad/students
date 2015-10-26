# include <stdio.h>
# include <fcntl.h>
main ()
{
	int n = 5,t,i,s = 0;
	for (i = 1; i <= 2; i++)
	{
		t = fact( i+1 )/fact( i );
		s = s+t;
	}
		printf("%d\n",s);
}
int fact (int num)
{
	int i,f = 1;
	for (i = 1; i <= num; i++)
	{
		f = f*i;
	}
	return (f);
}
