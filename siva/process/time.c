#include <time.h>
#include <stdio.h>
#include <sys/types.h>
main()
{
long t;
struct tm *p;
time(&t);
p=localtime(&t);
printf("time = %ld\n hours= %d\t minutes = %d \t Seconds =%d\n",t,p->tm_hour,p->tm_min,p->tm_sec);
printf("day of month :%d\n",p->tm_mday);
printf(" month :%d\n",p->tm_mon+1);
printf("year :%d\n",p->tm_year+1900);
printf("day of the week :%d\n",p->tm_wday+1);
printf("day of the year :%d\n",p->tm_yday+1);

char *ts;
ts=asctime(p);
printf("TIME IS :%s\n",ts);

}
