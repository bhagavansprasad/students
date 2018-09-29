#include<stdio.h>
main()
{
	int pid,a=10,i;
	printf("before fork :%p \n",&a);
	pid=fork();
	for(i=0;i<5;i++)
	{
		if(pid==0)
		{
			printf(" a in child :%d \n",a);
			printf("  in chid  a address  :%p \n",&a);
			a+=5;
			sleep(1);
		}
		else
		{
			printf("a in parent :%d \n",a);
			printf(" in parent  a address  :%p \n",&a);
			a+=10;
			sleep(1);
		}
	}
}
