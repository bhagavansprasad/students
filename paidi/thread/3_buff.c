#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

char message1[]="aura_networks";
char message2[]="bangalore";
char message3[]="bangalo";
char message4[]="banga";
char message5[]="bang";
char message6[]="ban";

char buff1[100];
char buff2[100];
char buff3[100];


int i = 1,j=1,k=1;

void afree(void *p)
{

       if(buff1 == p)
       {
               i=1;
               printf("-------------------the buff1 is free\n");
               sleep(1);
       }

       else if(buff2 == p)
       {
               j=1;
               printf("-------------------the buff2 is free\n");
               sleep(1);
       }

       else if(buff3 == p)
       {
               k=1;
               printf("-------------------the buff3 is free\n");
               sleep(1);
       }
}

void * amalloc(int x)
{

       if(i == 1)
       {
               i = 0;
               printf("..........buffer1 is return\n");
               return buff1;
       }
       else if(j == 1)
       {
               j = 0;
               printf("..........buffer2 is return\n");
               return buff2;
       }
       else if(k == 1)
      {
               k = 0;
               printf("..........buffer3 is return\n");
               return buff3;
       }

}



void *thread_function1(void *arg)
{
       for( ; ;)
       {
               char *p = amalloc(100);
               printf(" thread1 memory allocated\n");
               sleep(1);
               printf("------------------>:thread 1 is FREE\n");
               afree(p);
       }
}
u


void *thread_function2(void *arg)
{

       for( ; ;)
       {
               char *p = amalloc(100);
               printf(" thread2 memory allocated\n");
               sleep(4);
               printf("------------------>:thread 2 is FREE\n");
               afree(p);

       }

}



void *thread_function3(void *arg)
{
       for( ; ;)
       {
               char *p = amalloc(100);
               printf(" thread3 memory allocated\n");

               sleep(5);

               printf("---------------------->:thread 3is FREE\n");
               afree(p);
       }
}




void *thread_function4(void *arg)
{
       for( ; ;)
       {
               char *p = amalloc(100);
               printf(" thread4 memory allocated\n");
               sleep(6);

               printf("---------------------------------->:thread 4is FREE\n");
               afree(p);

       }
}



void *thread_function5(void *arg)
{
       for( ; ;)
       {
               char *p = amalloc(100);
               printf(" thread5 memory allocated\n");

               sleep(7);
               printf("------------------->:thread 5is FREE\n");

               afree(p);
       }
}


void *thread_function6(void *arg)
{
       for( ; ;)
       {
                               printf ("buff1 IS %s FREE \n", (i == 1 ? "    ": "NOT"));
                               printf ("buff2 IS %s FREE \n", (j == 1 ? "    ": "NOT"));
                               printf ("buff3 IS %s FREE \n", (k == 1 ? "    ": "NOT"));

               sleep(1);
       }
}

//==================================main=======================================
int main()
{
       pthread_t a_thread,b_thread,c_thread,d_thread,e_thread;

       void *thread_result;
       int res;

       printf("main pid :%d\n", getpid());
       printf("waiting for thread to finsh \n");

       res = pthread_create(&e_thread,NULL,thread_function6,(void*)message6);

       //sleep(2);

       res = pthread_create(&a_thread,NULL,thread_function1,(void*)message1);
       res = pthread_create(&b_thread,NULL,thread_function2,(void*)message2);
       res = pthread_create(&c_thread,NULL,thread_function3,(void*)message3);
       res = pthread_create(&d_thread,NULL,thread_function4,(void*)message4);
       res = pthread_create(&e_thread,NULL,thread_function5,(void*)message5);

       res = pthread_join(a_thread,&thread_result);
       res = pthread_join(b_thread,&thread_result);
       res = pthread_join(c_thread,&thread_result);
       res = pthread_join(d_thread,&thread_result);
       res = pthread_join(e_thread,&thread_result);

       printf("thread joined it returned %s\n",(char*)thread_result);
       printf("message is now message %s\n",message1);
}
