#include"stdio.h"
#include"signal.h"

void sigkey(int signo)
{
printf("you have killed with signal no=%d\n",signo);

}


main()
{
printf("the pid of the process=%d\n",getpid());
signal(SIGINT,sigkey);
signal(SIGQUIT,sigkey);
for(;;);
}
