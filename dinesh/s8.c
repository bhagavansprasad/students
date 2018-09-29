# include <stdio.h>
# include <fcntl.h>
main ()
{
	int i=0;
	int r=0;
	for (i = 4; i <= 6; i++)
	{
		r=fact(i);
		printf("%d\n",r);
	}
}
int fact (int num)
{
	int f=1;
	int i;
	for (i = 1; i <= num; i++)
		f=f*i;
	return f;	
}

