#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<fcntl.h>
#include"ovdc.h"
#define SIZE 10

int get_giff(int pid);
pid_giff_db arr[SIZE]={{0,0}};

int pid_count = 0;
int i=0 ;

int store_n_get_cpu_occpancy(int pid, int new_giffs)
{
    int diff = 0;

    for(i = 0 ; i < pid_count ; i++)
    {
        if (arr[i].pid == pid)
        {
            diff = new_giffs -arr[i].giffs;
            arr[i].giffs = new_giffs;
            return diff;
        }
    }

    for( ;i<SIZE; i++)
    {
        arr[i].pid = pid;
        arr[i].giffs = new_giffs;
        pid_count++;
        printf("cpu occupancy =0");
        return 0;
    }
}
int get_pids_from_args(int *pids, int argc, char *argv[])
{
    for(i = 1; i < argc; i++)
        pids[i-1] = atoi(argv[i]);

    return argc-1;
}

int main(int argc,char *argv[])
{ 
    int giffs, i,proc_count,cpu_occ;
    int pid[5]; 
    while(1)
    {
   proc_count = get_pids_from_args(pid, argc, argv);

    for (i = 0; i < proc_count; i++)
    {
        printf ("-->%d. %d\n", i+1, pid[i]);
    }

    for (i = 0; i < proc_count; i++)
 
        {
            pid[i]=atoi(argv[i+1]);
            printf(" pid=%d ",pid[i]);
            giffs=get_giff(pid[i]);
            cpu_occ=store_n_get_cpu_occpancy( pid [i],  giffs);


            printf("cpu_occ= %d ",cpu_occ);

        }
    }  
}   
