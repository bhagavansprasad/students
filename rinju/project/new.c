pid_giff_db arr[SIZE]= {0};

int pid_count = 0;
int i=0 ;

int store_n_get_cpu_occpancy(int pid, int new_giffs)
{
    static int old_giffs = 0, j,diff = 0;
   
for(i = 0 ; i < pid_count ; i++)
{
    if (arr[i].pid == pid)
        {
            diff = new_giffs -arr[i].giffs;
            arr[i].giffs = new_giffs;
            printf(" diff = %d ",diff);
            return diff;
            //take the diff between old and new value
            //replace old giffs with current giffs
            //return diff
        }

  
    for( ;i<SIZE; i++)
    {
        arr[i].pid = pid;
        arr[i].giffs = new_giffs;
        pid_count++;
        printf("cpu occupancy =0");
        return 0;
    }
}    //Its a new pid
    //Make a new entry in db
    //increment pid_count
    //return cpu occpance as 0
}

