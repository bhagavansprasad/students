#include <stdio.h>
#include <time.h>
main()
{
	time_t now;
	time(&now);
	printf("present time: %s\n", ctime( &now ));
}

