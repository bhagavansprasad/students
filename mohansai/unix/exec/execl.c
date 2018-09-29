#include <unistd.h>
	main()
	{
	   execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0);
	}
