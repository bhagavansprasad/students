#include <stdio.h>
#include <unistd.h>

char *env[] = {"HELLO ","mosad",(char *)0};

main()
{
	extern **environ;
	environ = env;
	printf("/home/bhagavan/students/viswa/os/pr78", "pr78", (char*)0);
	perror("what the error :::->");
}

