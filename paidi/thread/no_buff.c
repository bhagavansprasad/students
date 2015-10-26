#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char message1[]=" aura_networks";
char buffer[100][260];
int i=0,j=0;

void afree(void *p)
{
	printf("-->%s : got request :%p\n", __FUNCTION__, p);
	printf("-->header value :%d\n", *((char *)p - 4));
	*((char *)p - 4) = 0;
}


#if 0
void afree(void *p)
{
	if(i==100)
	{
		for(i=0;i<=100;i++)
		{
			if(buffer[i][0] == 1)
			{
				buffer[i][0]=0;
			}
		}
	}
}
#endif

void * amalloc(int x)
{
	printf("-->s% : got request for :%d bytes\n", __FUNCTION__, x);
	for(i=0;i<=100;i++)
	{
		if(buffer[i][0] == 0)
		{
			buffer[i][0] = 1;
			printf("-->%s : returning buff :%p, index :%d\n", __FUNCTION__, buffer[i]+4, i);
			return (buffer[i]+4);
		}		
	}
}

void *thread_functionj(void *arg)
{
	for( ; ;)
	{
		for(j=0;j<=50;j++)
		{
			char *p = amalloc(100);
			printf("-->\n",j);
			sleep(2);
			//printf(" thread is  %d                      FREE\n",j);
			afree(p);
			if(j==50)
			{
				j=0;
			}
		}
	}
}

int main()
{
	pthread_t a_thread;
	void *thread_result;
	int res;
	printf("-->buff     :%p\n", buffer);
	printf("-->buff[0]  :%p\n", buffer[0]);
	printf("-->buff[1]  :%p\n", buffer[1]);
	printf("-->buff[2]  :%p\n", buffer[2]);
	printf("-->buff[3]  :%p\n", buffer[3]);
	printf("-->buff[4]  :%p\n", buffer[4]);
	printf("main pid :%d\n", getpid());
	printf("waiting for thread to finsh \n");
	res = pthread_create(&a_thread,NULL,thread_functionj,NULL);	
	res = pthread_join(a_thread,&thread_result);
	printf("thread joined it returned %s\n",(char*)thread_result);
	printf("message is now message %s\n",message1);
}
