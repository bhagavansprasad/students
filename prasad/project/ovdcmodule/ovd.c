#include"stdio.h"
#include"fcntl.h"
#include"stdlib.h"
#include "structure_pid_jifffe.h"
#define DE 
int get_jiffies(int pid)
{
    int j, k, n, fd, space=0, jiffe=0;
    char fn[20];
    char giffe_temp[10];
    char pstat_content[1024];

    sprintf(fn, "/proc/%d/stat", pid);

#ifdef TEMP
    printf("fn = %s\r\n", fn);
#endif
    fd = open(fn,O_RDONLY);

    if(fd < 0)
    {
	//perror("failed to open stat  file");
	return -1;
    }

    if((read(fd,pstat_content,1000)) == -1)
    {
	perror("read failed to read process stat content from file");
	return -1;
    }


#ifdef D
    printf("%s \n",pstat_content);
#endif
    for(j= 0; pstat_content[j]!='\0' ; j++)
    {
	if(pstat_content[j]==' ')
	{
	    space++;
	}
	if(space == 13)
	{

	    for(j++, k = 0 ; space!=17 ; j++)
	    {
		if(pstat_content[j]!=' ')
		{
		    giffe_temp[k]=pstat_content[j];
		    k++; 
		}
		else
		{
		    giffe_temp[k]='\0';

#ifdef TEMP
		    printf("giffe_temp=%s \n",giffe_temp);
#endif
		    n=atoi(giffe_temp);

#ifdef TEMP
		    printf("n=%d \n",n);
#endif
		    jiffe=jiffe+n;

#ifdef TEMP
		    printf("jiffe=%d \n",jiffe);
#endif
		    space++;
		    k=0;
		}
	    }
	}
    }
    return jiffe;
}

int convert_n_store_pid(char *pids_content, int *pid_list)
{

    int i,k=0,j=0,lpid_count;
    char temp_buff[10];

    for(i=0;pids_content[i]!='\0';j++,i++)
    {
	for( ; pids_content[i]==' '; i++);

	if(pids_content[i]=='\r'||pids_content[i]=='\n')
	{
	    i++;
	    temp_buff[j]='\0';

#ifdef TEMP
	    printf("temp_buff=%s\n",temp_buff);
#endif
	    j=0;
	    pid_list[k] = atoi(temp_buff);

#ifdef TEMP
	    printf("pids=%d\n",pid_list[k]);
#endif
	    k++;
	    lpid_count++;
	}

	temp_buff[j] = pids_content[i];
    }
    return lpid_count;
}

void ovd(int fd, int argc, char *argv[])
{
    char pid_content[1024], ret_val_sys ;
    int fd1, i, pid_list[100], pid_count;
    struct pid_jiffe  stor;

    ret_val_sys = system("ps -A --no-headers -o pid>pids.txt");

    if(ret_val_sys < 0)
    {
	perror("system call failed");
	exit(1);
    }

    fd1 = open("pids.txt",O_RDONLY);

    if(fd<0)
    {
	perror("open systemcall failed to open a file");
	exit(1);
    }

    if((read(fd1, pid_content, 1024))==-1)
    {
	perror("read system call failed to read from the file");
	exit(1);
    }

    pid_count = convert_n_store_pid(pid_content, pid_list);

    for (i = 0; i < (argc-1); i++)
    {
	pid_list[i] = atoi(argv[i+1]);
	pid_count = argc-1;
    }

#ifdef TEMP
    printf("%d---->pid=%d \n",i, pid_list[i]);
#endif
    for(i = 0; i < pid_count; i++)
    {
	stor.pid = pid_list[i];
	stor.jiffe = get_jiffies(pid_list[i]);

	if (stor.jiffe == -1)
	    continue;

	//printf("-->ovd  %d:%d\r\n", stor.pid, stor.jiffe);

	write(fd, &stor, sizeof(stor));
    }

    stor.pid = -1;
    stor.jiffe = -1;
    write(fd, &stor, sizeof(stor));
    sleep(1);

#ifdef DEBUG
    printf("write into the pipe over");
#endif
}


