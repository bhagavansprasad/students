#include <stdio.h>

main()
{
	char *mess[] = { "some one loves you",
		"some thing went wrong",
		" i love you",
		" i  love one thing"
	};
	printf("%d %d \n", sizeof(mess), sizeof(mess[1]));
}

