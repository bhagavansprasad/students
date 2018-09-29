#include "stdio.h"
#include "signal.h"
#include "stdlib.h"

int size = 8;
//FILE *fp;
//char str[5];
/*void sig_handler()
  {
  printf("i rcvd signal\r\n");
  size = 7;
  }*/
#if 0
void dyn_handler()
{
    printf("signal caught enter value:\r\n");
    //getenv("CPU_OCCUPANCY");
    //size=1;
    fp = fopen("file.txt","r");

    if(fp == NULL)
    {
	printf("\r\nfile doesnt exists");
	exit(0);
    }
    fgets(str, 4, fp);
    //printf( " %s\r\n ", str);
    size = atoi(str);
    printf( " %d\r\n ", size);

    fclose(fp);	
}
#endif

main()
{
    unsigned long int n = 1, i;
    int x,y;
    //signal(SIGUSR1, sig_handler);
    //sleep(10);
    //signal(SIGUSR1, dyn_handler);
    printf("-->%d\r\n", getpid());

    for ( ; ; )
    {
	n = 1;
	for (i = 0; i < size; i++)
	    n = n  * 10;

	for ( i =0; i<= n; i++)
	{
	}
	sleep(1);
    }
}


