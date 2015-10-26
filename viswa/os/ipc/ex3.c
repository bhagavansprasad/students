#include <stdio.h>

main()
{
	int pid , p[2] , ret = 0 , retw = 0;
	char *buff1 = "your's name :";
	char *buff2 = "viswanath";
	char buff[10];
	int i =0 ;

	pipe(p);
	pid  = fork();
	
	if(pid == 0)
	{
		for( i = 0 ; i< 5 ; i++)
		{
			write(p[1], buff2, 10);
			sleep(1);
			ret = read(p[0] , buff , 10);
			buff[ret] = '\0';
			printf("ret :-> %d child :%s \n",ret ,buff );
			sleep(1);
		}
	}
	else
	{
		for(i = 0; i< 5 ; i++)
		{
			retw = read(p[0] , buff , 10);
			buff[retw] = '\0';
			printf("retw ->%d parent :-> %s\n",retw,buff);
		
			write(p[1] , buff1 , 10);
			sleep(2);
		}
	}
}
