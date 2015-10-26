#include <errno.h>
#include <stdio.h>
#include <unistd.h>

main()
{
	printf("executing pr55\n ");
	execl("/home/bhagavan/students/viswa/os/pr55","pr55",(char *)0);
	perror("excl failed to run pr55\n");
}
