#include<stdio.h>
#include<sys/time.h>
#include<sys/resource.h>
main()
{
int t,n;
t=getpriority(PRIO_USER,3294);
printf("%d\n",t);
/*setpriority(3051,-10);
n=getpriority(3051);
printf("%d new priority",n);
*/
}
