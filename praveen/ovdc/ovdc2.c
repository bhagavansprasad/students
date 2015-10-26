#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>

struct msg
{
	long type;
	char msge[500];
};

int i,j,rfd;
int fd1,fd2,fd3,fd4;
int k,l;
int sub;

int wc;
int sum[5];
int var1,var2;

char str[20];
char buff[500];

main()
{
	int qid,fd;
	struct msg que;
	qid = msgget((key_t)10,IPC_CREAT|0666);
	if(qid == -1)
	{
		perror("msgget failed");
		exit(0);
	}
	for(fd=3;fd<7;fd++)
	{
		for(l=1;l<4;l++)
		{
			if(msgrcv(qid,&que,283,0,0) == -1)
			{
				printf("msgrcv failed");
				exit(0);
			}

			strcpy(buff,que.msge);
			k =0;
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
			printf("sum[%d]-->%d\n",l,sum[l]);

			printf("\n");

			sleep(2);
		}

		sub = sum[2]-sum[1];
		printf("the sub valu of fd[%d] is %d\n",fd,sub);

	}

}

