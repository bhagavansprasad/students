main()
{
	int i,pid,exitstat,status,j=1;
	pid = fork();
	if(pid ==0)
	{
		printf("%d\n",j);
		i=10/j;
		printf("%d\n",i);
	}
	else
	{
		wait(&status);
		printf("%d ,%u \n",status,&status);
		if(status & 0x80)
			printf(" our core dumped \n");

	}

}
