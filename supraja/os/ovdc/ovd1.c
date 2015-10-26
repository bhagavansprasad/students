#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

main()
{
	struct
	{
		long mtype;
		int pid;
		int giffies;
	}send;
	int f,len = 10,rval,i,c=0,var1,var2=0,sum=0,y=0,x=0,diff=0,p = 0,l=0,qid,giffies;
	char buff[20],word[20];
	int fd[4];
	int spid [4] = {3345,3413,3482,3550};
//	for( i =0;i<4;i++)
//		fd[i] = open("/proc/spid[i]/stat",O_RDONLY);
	fd[0] = open("/proc/3345/stat",O_RDONLY);
	fd[1] = open("/proc/3413/stat",O_RDONLY);
	fd[2] = open("/proc/3482/stat",O_RDONLY);
	fd[3] = open("/proc/3550/stat",O_RDONLY);
	qid = msgget((key_t)60,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(1);
	}
	
		for(f=0; f < 4; f++)
		{
			for(i=0;i<5;i++)
			{
				while(1)
				{
					rval = read(fd[f],buff,len);
					buff[rval] = '\0';
					//printf("%s",buff);
					if(rval < len)
						break;
				}
				lseek(fd[f],58l,0);
				rval = read(fd[f],buff,20);
				buff[rval] = '\0';
				sscanf(buff,"%d   %d",&var1,&var2);
				//printf("var 1 : %d\t var 2 : %d\n",var1,var2);
				sum = var1+var2;
				//printf("sum of giffies:%d\n",sum);
				send.mtype = ++p;
				send.pid = spid[f];
				send.giffies = sum;
				printf("pid : %d\tsum of giffies:%d\n",send.pid,send.giffies);
				if(msgsnd(qid,&send,100,0)==-1)	
				{
					perror("msgsnd failed");
					exit(1);
				}
				sleep(2);
				lseek(fd[f],0l,0);
			}
			close(fd[f]);
		}
}
