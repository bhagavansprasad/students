#include <stdio.h>

main()
{
	int pp[2] , pc[2] , j , pid ;
	char msg1[20];
	char msg2[20];
	char msg3[20];
	
	pipe(pp);
	pipe(pc);
	pid = fork();

	if(pid == 0)
	{
		close(pp[1]);
		close(pc[0]);
		write(pc[1] , "Hello  Daddy", 12);
		read( pp[0] , msg2 ,12);
		printf("%s \n",msg2);
		write( pc[1] , "Thankyou papa", 12);
	}
	else
	{
		close(pp[0]);
		close(pc[1]);
		read( pc[0] , msg1 ,12);
		printf("%s \n",msg1);
		write(pp[1] , "Hello  baby", 12);
		read( pc[0] , msg3 ,12);
		printf("%s \n",msg3);

	}
}
