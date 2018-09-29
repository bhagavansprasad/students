#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
main()
{
	char *p1,*p2,*p3,*p4,*p5,*p6,*p7;
	int shmid1,shmid2,shmid3,shmid4,shmid5,shmid6,shmid7,pid,i;
	shmid1 = shmget((key_t)1,20,IPC_CREAT|0666);
	shmid2 = shmget((key_t)2,20,IPC_CREAT|0666);
	shmid3 = shmget((key_t)3,20,IPC_CREAT|0666);
	shmid4 = shmget((key_t)4,20,IPC_CREAT|0666);
	shmid5 = shmget((key_t)5,20,IPC_CREAT|0666);
	shmid6 = shmget((key_t)6,20,IPC_CREAT|0666);
	shmid7 = shmget((key_t)7,20,IPC_CREAT|0666);
	p1 = (char *)shmat(shmid1,0,0);
	p2 = (char *)shmat(shmid2,0,0);
	p3 = (char *)shmat(shmid3,0,0);
	p4 = (char *)shmat(shmid4,0,0);
	p5 = (char *)shmat(shmid5,0,0);
	p6 = (char *)shmat(shmid6,0,0);
	p7 = (char *)shmat(shmid7,0,0);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p1[i]='A';
	}
	printf("read from p1 : %s\n",p1);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p2[i]='B';
	}
	printf("read from p1 : %s\n",p1);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p3[i]='C';
	}
	printf("read from p1 : %s\n",p1);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p4[i]='D';
	}
	printf("read from p1 : %s\n",p1);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p5[i]='E';
	}
	printf("read from p1 : %s\n",p1);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p6[i]='F';
	}
	printf("read from p1 : %s\n",p1);
	printf("shimid1: %d\t p1 : %u\n",shmid1,p1);
	for(i=0;i<10;i++)
	{
		p7[i]='G';
	}
	printf("read from p1 : %s\n",p1);
}
