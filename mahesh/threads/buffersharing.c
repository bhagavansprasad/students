#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

int f = 0;
char buff[50];

void * amalloc(int a)
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

void *myThreadFun1(void *vargp)
{
	char s[15]="string";
	int myid = (int) (void *)vargp;
	char *p;
	int i = 0;
	printf("-->T1 :%d\n", myid);

	p=amalloc(sizeof(buff));
	printf("T1 :%p\n", p);

	while(p == NULL)
	{
		printf("-->T1 asking for bufffer for %d times\n", i++);
		sleep(1);
		p=amalloc(sizeof(buff));
	}
	strcpy(p,s);
	printf("fist thread1 string%s\n",p);
	sleep(3);
	printf("-->T1 freeing buffer\n");
	afree(p);
	strcpy(p,s);
	printf("in T1---%s\n",p);
	afree(p);


}

void *myThreadFun2(void *vargp)
{
	char s[15]="string";
	int myid = (int) vargp;
	char *p;
	int i = 0;
	printf("-->T2 :%d\n", myid);

	p=amalloc(sizeof(buff));
	printf("T2 :%p\n", p);

	while(p == NULL)
	{
		printf("-->T2 asking for bufffer for %d times\n", i++);
		sleep(1);
		p=amalloc(sizeof(buff));
	}
	strcpy(p,s);
	afree(p);
	printf("-->T2 freeing buffer\n");
	sleep(3);
	strcpy(p,s);
	printf("fist thread2 string%s\n",p);
	printf("in T2---%s\n",p);
	printf("2nd time free of p in Thread 2:\n");
	afree(p);

}

int main()
{
	int i;
	pthread_t tid;

	pthread_create(&tid, NULL, myThreadFun1, NULL);
	pthread_create(&tid, NULL, myThreadFun2, NULL);

	pthread_exit(NULL);
}
