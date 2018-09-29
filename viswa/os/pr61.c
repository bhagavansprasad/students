#include <stdio.h>
#include <unistd.h>

main()
{
	printf("the cat jumped over the wall ");
	fflush(stdout);
	execl("/home/bhagavan/students/viswa/os/pr58","pr58",(char *)0);
}
