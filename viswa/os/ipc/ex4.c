#include <stdio.h>


main()
{
	int pid ,p[2] , k = 91, retv = 0;
	char buff1 = 'G';
	char buff2 = (char )k;
	char buff[5];

	pipe(p);
	pid = fork();
	if( pid ==  0)
	{
		write(p[1] , &buff1 ,1);
		sleep(1);
		read(p[0] ,buff ,1);
		printf("child -->%s:\n",buff);

	}
	else
	{
		retv = read(p[0] , buff , 1);
		buff[retv] = '\0';
		printf("parent -->%s\n", buff);
		while(1)
		{
			if(buff[0] > 65)
			{
			 printf("buff[o]:->%s\n",buff[0]);
				buff[0]--;
				k--;
			}
		}
		write(p[1] , &buff2, 1);
		sleep(1);

	}
}
