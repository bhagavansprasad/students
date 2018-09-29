#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include <error.h>

int get_giffs_by_pid(int );
int read_list_of_process(int arr[] );

struct process
{
	int pid;
	int gifs;
};

struct process s;
int i;
int w;

int ovd(int wfd)
{
	int proc_count; 
	int len = 12;
	int  proc_list[5] = {2380,2381,2382,2383};
	
	proc_count = read_list_of_process(proc_list);
	printf("proc_count :%d", proc_count);
	
	for(; ;)
	{

		for(i = 0; i<=proc_count;i++)
		{
			s.pid = proc_list[i];

			printf("pid is :%d\n", proc_list[i]);
			
			s.gifs = get_giffs_by_pid(proc_list[i]);
			
			w = write(wfd, &s, sizeof(struct process));
			printf("the write value of the pipe is %d\n",w);
			if(w == -1)
			{
				perror("writing failed into pipe");
				exit(0);
			}

			if(i == 3)
			{
				sleep(1);
				i = -1;
			}
		}
	}
}

/*function for count the numer of process */

int  read_list_of_process(int  proc_list[])     
{
	for(i = 0; proc_list[i] != '\0'; i++)            
		printf("in read_list of_process %d\n",proc_list[i]);
	return i;
}


/* function for geting the giffs of the process*/

int  get_giffs_by_pid( int pid)
{
	int fd;
	int r,len = 12,w; 
	char buf[100];
	int v1,v2;
	char str[100];
	int v3;

	printf("pid is: %d\n",pid);
	
	sprintf(str,"/proc/%d/stat",pid);
	
	fd = open(str,O_RDONLY);
	printf("  fd is: %d\n", fd);
	
	if(fd<0)
	{
		perror("open failes due to this error:");
		exit(1);
	}
	
	while(1)
	{
		r = read(fd, buf,len);
		buf[r] = '\0';
		//printf("%s", buf);
		if(r<len)
			break;
	}
	
	lseek(fd, 59l, 0);
	r = read(fd, buf, len);
	buf[r] = '\0';
	
	//printf("giffs of the process: %s\n", buf);
	
	sscanf(buf, "%d %d", &v1, &v2);
	
	v3 = v1+v2;
	printf("----> value of v3 is %d\n", v3);
	
	lseek(fd, 0l, 0);
	close(fd);
	return ( v3);
}

