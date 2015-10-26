#include "freebuffer5.h"

char *m;

void * thread_function1(void *arg)
{  	
	for (;;)
	{
     m= malloc(100);
	 printf("memory is allocated in 100 BYTES BUFFER: \n");
	 sleep(2);
	 free(m);
	 printf("memory is FREE 100 BYTES BUFFER: \n");

     m= malloc(200);
	 printf("memory is allocated in 200 BYTES BUFFER: \n");
	 sleep(2);
	 free(m);
	 printf("memory is FREE 200 BYTES BUFFER: \n");

     m= malloc(550);
	 printf("memory is allocated in 500 BYTES BUFFER: \n");
	 sleep(2);
	 free(m);
	 printf("memory is FREE 500 BYTES BUFFER: \n");
	 
     m= malloc(700);
	 printf("memory is allocated in 700 BYTES BUFFER: \n");
	 sleep(2);
	 free(m);
	 printf("memory is FREE 700 BYTES BUFFER: \n");

     m= malloc(300);
	 printf("memory is allocated in 300 BYTES BUFFER: \n");
	 sleep(2);
	 free(m);
	 printf("memory is FREE 300 BYTES BUFFER: \n");

	 	}
}

void * thread_function2(void *arg)
{
	for (;;)
	{
 m= malloc(100);
	 printf("memory is allocated in 100 BYTES BUFFER: \n");
	 sleep(4);
	 free(m);
	 printf("memory is FREE 100 BYTES BUFFER: \n");

     m= malloc(200);
	 printf("memory is allocated in 200 BYTES BUFFER: \n");
	 sleep(4);
	 free(m);
	 printf("memory is FREE 200 BYTES BUFFER: \n");

     m= malloc(550);
	 printf("memory is allocated in 500 BYTES BUFFER: \n");
	 sleep(4);
	 free(m);
	 printf("memory is FREE 500 BYTES BUFFER: \n");
	 
     m= malloc(700);
	 printf("memory is allocated in 700 BYTES BUFFER: \n");
	 sleep(4);
	 free(m);
	 printf("memory is FREE 700 BYTES BUFFER: \n");

     m= malloc(300);
	 printf("memory is allocated in 300 BYTES BUFFER: \n");
	 sleep(4);
	 free(m);
	 printf("memory is FREE 300 BYTES BUFFER: \n");

	}
}


void * thread_function3(void *arg)
{
  int i;
  node *temp;
	for (;;)
	{
		for(i=0;i<=4;i++)
		{
			for(temp=head[i];temp!=NULL;temp=temp->next)
			{
				printf("head %d |%d|\t",i,temp->flag);
			}
		}
	}

}
