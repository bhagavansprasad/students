main
{
	
	pipe(p[2]);

	pid = fork();
	if (pid == 0)
	{
		close(p[0]);
		ovd(p[1]);
	}
	else
	{
		close(p[1]);
		ovc(p[0]);
	}

}
