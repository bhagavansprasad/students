#include <stdio.h>
#include <unistd.h>

main()
{
	printf(" the cat jumped over the wall \n");
	execl("/home/bhagavan/students/viswa/os/pr64" ,"pr64", (char *)0);
}
