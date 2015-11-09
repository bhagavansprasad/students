#include <stdio.h>
#include <time.h>
void getdatetime(void);
main()
{
//	printf("before the getdatetime()fun is called");
	getdatetime();
//	printf("after the getdatetime()fun is called");
	return 0;
}
void getdatetime(void)
{
	time_t now;
//	printf("with in getdatetime() \n");
	time(&now);
	printf("current date and time is :%s\n",asctime(localtime(&now)));
}
