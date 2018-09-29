#include<stdio.h>
main()
{
	char buf[] = "sai prasad";
	int p[2], sum = 0, w;
	pipe(p);
	while(1)
	{
	if(w = write(p[1], buf, sizeof(buf)))
	{
	sum = sum + w;	
	printf("sum is : %d\n", sum);
	}
	else 
	break;
	}
}
