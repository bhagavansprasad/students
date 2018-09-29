

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctime> 
 
#include <sys/ipc.h>
#include <sys/shm.h>
 
#define N 4
#define D 5
#define XX 29		
 
int X = XX;
pid_t child_ids[N];
int W[N];
pid_t child_id;
int s_W = 0;		
 
void  USR1handler(int);
void  ALARMhandler(int);
 
int id;
key_t key = int(19200604);
int size = 65536;
int *shmaddr;			
 
void init_shm ()
{
	int flags = 0664 | IPC_CREAT;
	id = shmget (key, size, flags);
	shmaddr = (int *)shmat (id, 0, 0);
}
 
void work_give()
{
	printf(”[Master] All work: %dn”,X);
	for (int i=0; i<N; i++)
		if (X>0) {
			if (X<W[i]) {
				*(shmaddr+child_ids[i])=X;
				kill(child_ids[i],SIGUSR1);
				X=0;
			} else {
				*(shmaddr+child_ids[i])=W[i];
				kill(child_ids[i],SIGUSR1);
				X-=W[i];
			}
		}
}
 
#define WORK_FINISHED 0
#define WORK_FINISHED_AND_ACCEPTED -1
void work_accept(int sig)
{
	for (int i=0; i<N; i++) {		
 
		if (*(shmaddr+child_ids[i])==WORK_FINISHED) printf(”[Master] Child[%d] finished his work.n”,child_ids[i]);
		*(shmaddr+child_ids[i])=WORK_FINISHED_AND_ACCEPTED;
	}
}
 
void  ALARMhandler(int sig)
{
	signal(SIGALRM, SIG_IGN);
	work_give();
     	signal(SIGALRM, ALARMhandler);
     	alarm(D);              
 
}
#define ACCEPTED 0
void master_function ()
{
	signal(SIGUSR2, work_accept);
	srand((unsigned)time(0));
	for (int i=0; i<N; i++) {
		W[i] = rand()%(D-1)+1;
		*(shmaddr+child_ids[i])=W[i];
		kill(child_ids[i],SIGUSR1);
		while (*(shmaddr+child_ids[i])!=ACCEPTED) ;
		}
	work_give();
	signal(SIGALRM, ALARMhandler);
	alarm(D);
	while (X!=0) ;
	for (int i=0; i<N; i++)
		while ((*(shmaddr+child_ids[i])!=WORK_FINISHED_AND_ACCEPTED) && (*(shmaddr+child_ids[i])!=WORK_FINISHED));
	printf(”[Master] Finished!n”);
	shmdt(shmaddr);
	for (int i=0; i<N; i++)
		kill(child_ids[i],SIGTERM);
 
}
 
void child_shm ()
{
	id = shmget (key, 0, 004);
	shmaddr = (int *)shmat (id, 0, 0);
}
 
void  USR1handler(int sig)
{
	signal(SIGUSR1, SIG_IGN);
	if (s_W ==0) {
		printf (”Child[%d] Capacity: %d.n”, (int) getpid (), s_W=*(shmaddr+getpid()));
		*(shmaddr+getpid()) = ACCEPTED;
		}
	else {
		printf (”Child[%d] New work with length: %d.n”, (int) getpid (), *(shmaddr+getpid()));
		usleep(*(shmaddr+getpid())*1000*1000);	
 
		*(shmaddr+getpid())=WORK_FINISHED;
		kill(getppid(),SIGUSR2);
	     }
	signal(SIGUSR1, USR1handler);
}
 
void child_function ()
{
	child_shm ();
	signal(SIGUSR1, USR1handler);
	while (1);
}
 
#define CHILD 0
int main (void)
{
	init_shm ();				
 
	for (int i=0; i<N; i++) {
		child_id = child_ids[i] = fork ();
		if (child_id == CHILD) break;
	}					
 
	if (child_id == CHILD) child_function ();
	else  master_function ();
	return 0;
}


