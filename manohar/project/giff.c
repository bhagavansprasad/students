#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<errno.h>
int array[1024];
int noofpids;
int giff=0;
main()
{
    int i;
    noofpids = listpids(array);
    for(i=0;i<noofpids;i++)
      {
	printf("\nno=%d \n pid= %d\n\r",i,array[i]);
        giff = giffies(array[i]);
        printf("giffies = %d\n\r",giff);
      }
}

