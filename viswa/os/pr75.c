#include <stdio.h>
#include <unistd.h>

main()
{
	int i;
	char *env[5], *av[2];
	env[0] = "NAME = STEFF";
	env[1] = "COMPANY = PUMA";
	env[2] = "ADRESS = NEWYORK";
	env[3] = "TEL = 387-305-02";
	env[4] = (char *)0;
	av[0] = "pr76";
	av[1] = (char *)0;

	printf("executing pr76\n");
	execve("/home/bhagavan/students/viswa/os/pr76",av, env);
	perror("execve failed ");
}
