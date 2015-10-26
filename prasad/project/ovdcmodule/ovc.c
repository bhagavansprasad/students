#include"stdio.h"
#include"structure_pid_jifffe.h"
#include"stdlib.h"
#include"signal.h"
#define ROW 10
#define COLOUMN 4

int pids_jiffes[ROW][COLOUMN] = { {0, 0, 0, 0} };
int pid_count = 0;

int reset_pid_jiffe_flag()
{
    int j, i;

    for(j=0; j < pid_count; j++)
    {
	if(pids_jiffes[j][2] == 0)
	{
	    for(i=j; i < pid_count; i++)
	    {
		pids_jiffes[i][0] = pids_jiffes[i+1][0];
		pids_jiffes[i][1] = pids_jiffes[i+1][1];
		pids_jiffes[i][2] = pids_jiffes[i+1][2];
	        pids_jiffes[i][3] = pids_jiffes[i+1][3];
		pid_count --;
		j--;
	    }
	}
	else
	    pids_jiffes[j][2] = 0;
    }
}

int store_pid_jiffe(int pid, int jiffe)
{
    int k , flag1 =0;
    int occu_cpu=0;

    for(k= 0; k < pid_count; k++)
    {   
	if(pids_jiffes[k][0] == pid)
	    break;
    }

    if (k == pid_count)
    {
	pid_count++;
	flag1=1;
    }

    pids_jiffes[k][0] = pid;

    if(flag1 != 1)
    {
	if(pids_jiffes[k][3] <= 1)
	{
	    occu_cpu=jiffe-pids_jiffes[k][1];	
	    printf("-->pid:%d----->occupancy:%d\r\n", pids_jiffes[k][0],occu_cpu);
	    sus_kill(occu_cpu , pid);

	    if(occu_cpu >= 31 && occu_cpu <= 50)
		pids_jiffes[k][3] = 5;
	}
	else 
	{

	    printf("previous values pid---->%d----->resume flag--->%d\r\n",pid,pids_jiffes[k][3]);
	    pids_jiffes[k][3] = pids_jiffes[k][3]-1;
	    printf("pid---->%d----->resume flag--->%d\r\n",pid,pids_jiffes[k][3]);

	    if(pids_jiffes[k][3] == 1)
		kill(pid , SIGCONT);
	}	
    }	
    pids_jiffes[k][1] = jiffe; 
    pids_jiffes[k][2] = 1;

    if(pids_jiffes[k][3] <= 1)
	pids_jiffes[k][3] = 1;

#ifdef TEMP
    printf("pid and jiffe and flag's stored in array: %8d %4d %2d\r\n",
	pids_jiffes[k][0],pids_jiffes[k][1],pids_jiffes[k][2]);
#endif
    return 0;
}

void dump_db(void)
{
    int n;

    for(n = 0; n < pid_count; n++)
    {
	printf("-->ovc %5d:%3d:%2d:%2d\r\n", pids_jiffes[n][0], pids_jiffes[n][1], pids_jiffes[n][2],pids_jiffes[n][3]);
    }
}

void ovc(int fd)
{
    struct pid_jiffe pread;

    for(;;)
    {
	if((read(fd, &pread, sizeof(pread))) == -1)
	{
	    perror("read function failed to read from the pipe");
	    exit(1);
	}

	if (pread.pid == -1)
	{
	    dump_db();
	    reset_pid_jiffe_flag();
	    continue;
	}

#ifdef DEBUG
	printf("-->ovc %5d:%3d\r\n", pread.pid, pread.jiffe);
#endif
	store_pid_jiffe(pread.pid, pread.jiffe);
    }
}

