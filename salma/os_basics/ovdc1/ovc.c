#include<stdio.h>
#include<time.h>
#include<sys/resource.h>
#include<signal.h>
#include<fcntl.h>
void take_action(int,int,int);
struct node
{
	int pid;
	int giffies;
}rc;

time_t now;
int fd;
//fd=open("txt1.log",O_CREAT|O_RDWR,0777);
int ovc(int rfd)
{
	printf("----->ovc start----->\n");
	int r,cpu_occ;
	char buff[100];
	fd=open("txt1.log",O_CREAT|O_RDWR,0777);
	for (;;)
	{
		r=read(rfd,&rc,sizeof( struct node));
		printf("read in ovc %d\n",r);
		printf("pid and gifs in ovc section  %d\t %d\n", rc.pid, rc.giffies);
		buff[r]='\0';
		cpu_occ= store_into_db(rc.pid, rc.giffies);
		printf("cpu occpuancy  :%d\n", cpu_occ);
		take_action(rc.pid, cpu_occ,fd);
		//clean_up_db();
	}
}

int data_base[100][3]={0},j;
static int count=0,i=0;
int cpu_occ,rval;
int store_into_db(int r,int g)
{ 
   int j;	
   if(i<4 && data_base[i][2]== 0)
	{


		data_base[i][0]=r;
		data_base[i][1]=g;
		data_base[i][2]=1;
		i++;
		//count++;
		return 0;
	}
	else
	{
		for(j=0;j<4;j++)
		{
			if(data_base[j][0]==r)
			{
				printf("---> new : %d\told:%d\n",g,data_base[j][1]);
				cpu_occ = g - data_base[j][1];
				printf("---> cpu occ: %d\n",cpu_occ);
				data_base[j][1]=g;
				return cpu_occ;
			}
		}
	}
}
void take_action(int pid,int cpu_occ,int fd)
{
	time(&now);
	char buff1[100];
	int t,setprior,getprior;
	if(cpu_occ >30)
	{
		t=sprintf(buff1,"pid=%d\tgiffies=%d\ttime=%s",rc.pid,rc.giffies,ctime(&now));
		write(fd,buff1,t);
	}
	else if(cpu_occ>30 && cpu_occ<40)
	{
		getprior=getpriority(PRIO_PROCESS,rc.pid);
		printf("priority of process is %d \n",getprior);
		setprior=setpriority(PRIO_PROCESS,rc.pid,getprior-5);
		printf("priority of process after reset %d \n",setprior);
		t=sprintf(buff1,"pid=%d\tgiffies=%d\ttime=%s",rc.pid,rc.giffies,ctime(&now));
		write(fd,buff1,t);
	}
	else if(cpu_occ>50)
	{
		kill(pid,SIGSTOP);
	}
}
