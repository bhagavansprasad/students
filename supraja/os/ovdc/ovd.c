#include <stdio.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>

main()
{
	int fd,i,len=11,rval,pid,msqid,v1,v2,v3,x,y=0,d;
	char buff[12];
	struct{
		long mtype;
		char mtext[25];
	}message;
	pid=fork();
	if(pid==0)
	{
		fd=open("/proc/2149/stat",O_RDONLY);
		for(i=1;i<=5;i++)
		{
			while(1)
			{
				rval=read(fd,buff,len);
				buff[rval]='\0';
				//printf("%s",buff);
				if(rval<len)
					break;
				msqid=msgget((key_t)10,IPC_CREAT|0666);
				//message.mtype=1;
				msgsnd(msqid,&buff,10,0);
			}
			sleep(5);
			lseek(fd,59l,0);
			rval=read(fd,buff,len);
			buff[rval]='\0';
			sleep(5);
			lseek(fd,0l,0);
		}
	}
	else
	{
		wait(0);
		printf("iam in parent");
		for(i=1;i<=5;i++)
		{
			//struct{
			//	long mtype;
			//	char mtext[25];
			//	}buff;
			msqid=msgget((key_t)10,IPC_CREAT|0666);
			msgrcv(msqid,&buff,5,0,0);
			printf("%s",buff);
			sleep(5);
			printf("\n %s",buff);
			printf("\n");
			sleep(5);
			sscanf(buff,"%d %d ",&v1,&v2);
			v3=v1+v2;
			x=v3;
			d=x-y;
			y=x;
			printf("%d\n",v3);
			if(i>=1)
				printf(" difference :%d\n",d);
			sleep(2);
			printf("\n");
		}
	}
}



