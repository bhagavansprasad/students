#include <stdio.h>
static int i = 10;
main()
{
	int pid;
	pid = fork();
	if(pid == 0)
	{
		printf("in the child value before change i  = %d\n",i);
		
		int i=20;
		printf("in the child value after change i  = %d\n",i);

	}
	else
	{
		//wait(0);
		printf("in the parent the value is = %d\n",i);
		int i =30;
		printf("in the parent value after change = %d\n",i);
	}
	printf("out of the value = %d\n",i);

}
