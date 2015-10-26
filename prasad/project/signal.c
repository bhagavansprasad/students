#include"stdio.h"
#include"signal.h"

void sig()
{
sleep(5);
printf("now im in sig function\n");
signal(SIGALRM,SIG_IGN);
alarm(5);
pause();
}

main()
{
printf("pid of the process=%d\n",getpid());
signal(SIGINT,sig);
printf("before infinite for loop\n");
for(;;);
}
