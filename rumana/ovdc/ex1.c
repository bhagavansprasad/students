#include<stdio.h>
#include<time.h>
main()
{
time_t now;
time(&now);
printf("%s",ctime(&now));

}
