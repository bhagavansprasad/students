#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
int i,j;
int k,l;
int wfd;

int sum[5];
int var1,var2;
char log[500];
char str[20];
char buff[500];
void suspend();
int ovc(int p)
{
	int data_base[100][4] = {0,0,0,0};
	int pid[4]={3518,3527,3533,3539};
	int qid,fd;
	int sub;
	int wc;
	fd = open("report.txt",O_RDWR|O_CREAT|O_APPEND,0777);
	for(j=0;j<4;j++)
	{
		printf("THE PID VALUE IS = %d\n",pid[j]);
		printf("\n");
		for(l=1;l<4;l++)
		{
			read(p,buff,500);
			//printf("%s\n",buff);
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
			printf("the value in str is %s\n",str);
			sscanf(str,"%d %d",&var1,&var2);

			sum[l] = var1+var2;
			printf("sum[%d]-->%d\n",l,sum[l]);

			printf("\n");
			
			sleep(1);
		}

		sub = sum[2]-sum[1];
		printf("the sub valu  is %d\n",sub);

		if(sub > 20)
		{
			sprintf(log,"%d  %d ",pid[j],sub);
			write(p,log,sizeof(log));
		}
		if(sub > 30 && sub < 40)
		{
			int PRIO_PROCESS;
			int priority;
			priority = setpriority(PRIO_PROCESS,pid[j],19);
			return;
		}
		elseif(sub > 40 && sub < 50)
		{
			kill(pid[j],SIGSTOP);
			sleep(3);
			kill(pid[j],SIGCONT);
			return;
		}

		printf("\n");
	}
}

