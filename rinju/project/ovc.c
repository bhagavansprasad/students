#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include"ovdc.h"
#define SIZE 10

int get_giff(int pid);
pid_giff_db arr};

int pid_count = 0;
int i=0 ;

int store_n_get_cpu_occpancy(int pid, int new_giffs)
{
    int diff = 0;

    for(i = 0 ; i < pid_count ; i++)
    {
        if (arr.pid == pid)
        {
            diff = new_giffs -arr.giffs;
            arr.giffs = new_giffs;
            return diff;
        }
    }

    for( ;i<SIZE; i++)
    {
        arr.pid = pid;
        arr.giffs = new_giffs;
        pid_count++;
        printf("cpu occupancy =0");
        return 0;
    }
}

int ovc(int rfd)

{ 
    int giffs, i,proc_count,cpu_occ;
    int pid[5]; 
    while(1)
    {

    for (; ; )
 
        {
			read(rfd, &arr, sizeof(arr));

            cpu_occ=store_n_get_cpu_occpancy( pid [i],  giffs);


            printf("cpu_occ= %d ",cpu_occ);

        }
    }  
}   
