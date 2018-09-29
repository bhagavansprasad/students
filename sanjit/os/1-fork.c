#include "stdio.h"

main()
{
	int retval;

	printf("This is my first program pid :%d\n", getpid());

	retval = fork();

	if (retval == 0)
		printf("I am CHILD  my pid :%d, my parent pid :%d, retval :%d\n", getpid(), getppid(), retval);
	else
		printf("I am PARENT my pid :%d, my parent pid :%d, retval :%d\n", getpid(), getppid(), retval);


	sleep(50);
}


{
	socket;
	bind;
	listen;

	while(1)
	{
		newfd = accept;

		pid = fork();

		if (pid == 0)
		{
			while(1)
			{
				read(new_fd, ....);
				write(new_fd, ....);
			}

			close(new_fd);
			close(socket);
			exit(1);
		}
		else
		{
			close(new_fd)
		}
	}
	close;
}


