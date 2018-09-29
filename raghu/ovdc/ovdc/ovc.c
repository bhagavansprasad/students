#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
int i,j;
int k,l;
int wfd;
int sum[5];
int var1,var2;
char str[20];
char buff[500];

int ovc(int p)
{
     
	time_t now ;
    time( &now);
	int pid[4]={3447,3455,3461,3467};
	int qid,fd;
	int sub;
	int wc;
	char log[500];

	fd = open("report.txt",O_RDWR|O_CREAT,0777);
	for(j=0;j<4;j++)
	{
		printf("\n");
		for(l=1;l<4;l++)
		{
			read(p,buff,500);
			k = 0;
			wc = 1;
			for(i=0;buff[i]!='\0';i++)
			{
				if(buff[i+1]!=' ' &&(buff[i]==' '||buff[i]=='\n'||buff[i]=='\0'))
					wc = wc+1;

				if(wc==14||wc==15)
				{
					str[k]=buff[i+1];
					k++;
				}
			}

			str[k]='\0';
			sscanf(str,"%d %d",&var1,&var2);
			sum[l] = var1+var2;
			printf("\n");
		}

		sub = sum[2]-sum[1];
		printf("the sub valu  is %d\n",sub);

		if(sub > 15)
		{
			sprintf(log,"pid = %d    cpu_occupancy space = %d   time = %s",pid[j],sub,ctime( &now));
			write(fd,log,sizeof(log));
		}
		if(sub > 20 && sub < 25)
		{
			int PRIO_PROCESS;
			int priority;
			priority = setpriority(PRIO_PROCESS,pid[j],19);
		}
		else if(sub > 30)
		{
			kill(pid[j],SIGSTOP);
			sleep(3);
			kill(pid[j],SIGCONT);
		}

		printf("\n");
	}
	return ;
}

