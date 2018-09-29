#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int f = 0;
char buff[50];

void * a_malloc()
{
	if(f==0)
	{
		f=1;
		return buff;
	}
	else
		return 0;
}

void afree(void *p)
{
	f=0;
}

void *thread1(void *vargp)
{
	int tid = (int)vargp;
	char *p;
	//int i = 0;
	printf("\n-->T1 TID:%d\n", tid+1);
	printf("-->T1 PID:%d\n", getpid());
	printf("-->T1 PPID:%d\n", getppid());
	p=a_malloc(sizeof(buff));
	
	while(p == NULL)
	{
		printf("-->T1 requesting buffer for %d times\n", tid+1);
		sleep(1);
		p=a_malloc(sizeof(buff));
	}
	strcpy(p,"T1 using Memory");
	printf("T1 Buff:%s\n", p);
	sleep(2);
	afree(p);
}

void *thread2(void *vargp)
{
	int tid = (int)vargp;
	char *p;
	int i = 0;
	printf("\n-->T2 TID:%d\n", tid+1);
	printf("-->T2 PID:%d\n", getpid());
	printf("-->T2 PPID:%d\n", getppid());
	p=a_malloc(sizeof(buff));

	while(p == NULL)
	{
		printf("-->T2 requesting buffer for %d times\n", tid+1);
		sleep(1);
		p=a_malloc(sizeof(buff));
	}
	strcpy(p,"T2 using memory");
	printf("T2 Buff:%s\n", p);
	afree(p);
	sleep(2);
}


int main()
{
	int i = 0;
	pthread_t tid;
	for( ; ;++i)
	{
		pthread_create(&tid, NULL, thread1, (void*)(unsigned long)i);
		pthread_join(tid, NULL);

		pthread_create(&tid, NULL, thread2, (void*)(unsigned long)i);
		pthread_join(tid, NULL);

	}
	return 0; 
}
