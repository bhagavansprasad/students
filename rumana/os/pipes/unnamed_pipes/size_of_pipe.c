#include<stdio.h>
main()
{
	int pid,p[2],w,sum=0;
	char *buff="hello world";
	pipe(p);

	pid=fork();

	if(pid>0)
	{
		while(1)
		{
			w=write(p[1],buff,sizeof(buff))	;
			sum=sum+w;
			printf("sum is %d\n",sum);
		}
	}
	else
	{

	}

}
