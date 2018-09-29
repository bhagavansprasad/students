#include<stdio.h>
main()
{
printf("%d\t" ,getpid());
for(;;)
printf("%d\t" ,getpid());
}
