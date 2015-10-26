#include "stdio.h"
#include "signal.h"

void sus_kill(int occu_cpu , int proc_pid)
{
    if(occu_cpu >= 20  && occu_cpu <= 30)
	printf("-->the occupency going to  increasing\r\n");
    else if(occu_cpu >= 31 && occu_cpu <= 50)
	kill(proc_pid, SIGSTOP);
    else if(occu_cpu >= 51)
	kill(proc_pid, SIGKILL);
}
