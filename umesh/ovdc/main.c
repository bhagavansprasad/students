main()
{
	while(1)
	{
		int p[2];
		pipe(p);
		int pid;
		pid=fork();

		if(pid>0)
		{
			close(p[0]);
			ovd_entry_function(p[1]);

		}
		else
		{
			close(p[1]);
			ovc_entry_function(p[0]);
		}

		sleep(1);
	}

}		
