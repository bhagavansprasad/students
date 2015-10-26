#include "freebuffer5.h"

 char message2[] = "hi welcome to aura";
char message1[] = "aura welcomes u "; 

main()
{
    char *am;
	init_free_pool();
	pthread_t a_thread;
	pthread_t b_thread;
	pthread_t c_thread;
	int res;
	void *thread_result;


    
	res = pthread_create(&a_thread, NULL, thread_function1, (void*)message1);
	res = pthread_create(&b_thread, NULL, thread_function2, (void*)message2);
	res = pthread_create(&c_thread, NULL, thread_function2, (void*)message2);

	res = pthread_join(a_thread, &thread_result);
	res = pthread_join(b_thread,&thread_result);
	res = pthread_join(c_thread,&thread_result);

	printf("thread joined it returned %s\n",(char*)thread_result);
	printf("message is now message %s \n",message1);



}
