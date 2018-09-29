#include "stdio.h"
void * thread_function1(void *arg)	//thread function 1
{
	int i;
	char *p1, *p2, *p3, *p4,*p5, *p6, *p7,*p8;

//	printf("I am in thread1 :%d\n", (int)pthread_self());

	for(i=1 ; i<=1 ;i++  )
	{
		p1 = amalloc(100);
		sleep(2);
	//	afree(p1);

		p2 = amalloc(95);
		sleep(1);
		p3 = amalloc(128);
		sleep(3);


		p4 = amalloc(200);
		sleep(2);
	//	afree(p4);
		p5 = amalloc(198);
	//	afree(p5);
		sleep(3);


		p6 = amalloc(350);
		sleep(2);
		p7 = amalloc(400);
		sleep(2);
		p8 = amalloc(444);
		sleep(2);

	}
}

void * thread_function2(void *arg)	//thread function 1
{
	int i;
	char *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8;

//	printf("I am in thread2 :%d\n", (int)pthread_self());

	for(i = 1 ; i<=1 ; i++ )
	{
		p1 = amalloc(110);
		sleep(1);
		p2 = amalloc(120);
	//	afree(p1);

		p3 = amalloc(230);
		sleep(3);
	//	afree(p2);
		p4 = amalloc(149);
		sleep(5);

		p5 = amalloc(220);
		sleep(4);
		p6 = amalloc(220);
	//	afree(p6);
		p7 = amalloc(220);
		sleep(6);
		p8 = amalloc(220);
		sleep(2);
	}
}

void * thread_function3(void *arg)	//thread function 1

{
	int i;

	char *p1, *p2, *p3, *p4;
//	printf("I am in thread3 :%d\n", (int)pthread_self());

	for(i = 1 ; i<=1 ; i++ )
	{
		p1 = amalloc(110);
		sleep(1);
	//	afree(p1);

		p2 = amalloc(250);
		sleep(3);
	//	afree(p2);

		p3 = amalloc(100);
		sleep(2);
	//	afree(p3);

		p4 = amalloc(449);
		sleep(2);
	//	afree(p4);
	}
}

void mmm_cli(void)
{
	int option = 0;
	for ( ; ;)
	{
		printf("1. Print statistics\n");
		printf("2. xxxxxxxx\n");
		printf("3. xxxxxxxx\n");
		printf("0. Exit\n");
		scanf("%d", option);
	}

	switch(option)
	{
	case 1:
		print_();
		break;

	case 2:
		break;
		
	case 3:
		break;

	case 0:
		break;

	default:
	}
}


