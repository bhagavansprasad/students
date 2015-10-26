#include <signal.h>
main()
{
signal(SIGHUP,SIG_IGN);
for(;;);
}
