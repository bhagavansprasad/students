#include<stdio.h>
#include <stdlib.h>
#include<sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
main()
{
	char *ptr1,*ptr2,*ptr3,*ptr4,*ptr5,*ptr6,*ptr7;
	int shmid1,shmid2,shmid3,shmid4,shmid5,shmid6,shmid7,pid,i;
	shmid1=shmget((key_t)1,524488,IPC_CREAT|0666);
	shmid2=shmget((key_t)2,524488,IPC_CREAT|0666);
	shmid3=shmget((key_t)3,524488,IPC_CREAT|0666);
	shmid4=shmget((key_t)4,524488,IPC_CREAT|0666);
	shmid5=shmget((key_t)5,524488,IPC_CREAT|0666);
	shmid6=shmget((key_t)6,524488,IPC_CREAT|0666);
	shmid7=shmget((key_t)7,524488,IPC_CREAT|0666);

	ptr1=(char *)shmat(shmid1,0,0);
	ptr2=(char *)shmat(shmid2,0,0);
	ptr3=(char *)shmat(shmid3,0,0);
	ptr4=(char *)shmat(shmid4,0,0);
	ptr5=(char *)shmat(shmid5,0,0);
	ptr6=(char *)shmat(shmid6,0,0);
	ptr7=(char *)shmat(shmid7,0,0);

    printf("shmid1 is %d ptr1 :%u\n",shmid1,ptr);
	for(i=0;i<10;i++)
	{
		ptr1[i]=A;

	}
	printf("read from ptr1%s\n",ptr1);
	printf("shmid2 %d ptr2%s\n",ptr2);
	for(i=0;i<10;i++)
	{
		ptr2[i]=B;
	}
	printf("read from ptr2%s\n",ptr2);
}
