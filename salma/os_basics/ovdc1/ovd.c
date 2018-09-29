#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h>

struct node
{
	int pid;
	int giffies;
};


int read_list_of_processes(int *proc);
int get_giffs_by_pid(int);
//int send_gifss_to_ovc(int, int* , int );

int ovd(int wfd)
{
	int i,proc_count,giffs;
	int wretval;
	int proc_list[10] = {2213, 2227,2241,2255, -1};
	struct node data;

	proc_count = read_list_of_processes(proc_list);
	printf("process count: %d\n", proc_count);

	for (;;)
	{
		for (i=0; i < proc_count;i++)
		{
			data.pid = proc_list[i];
			data.giffies = get_giffs_by_pid(proc_list[i]);
		//	printf("return value of giffs :%d\n", data.giffies);

			wretval = write(wfd, &data, sizeof(data));
			printf("write retval :%d\n", wretval);
			if(wretval < 0)
			{
				perror("write failed");
				exit(0);
			}
			if(i==3)
			{
				sleep(1);
				i=-1;
			}
		}

	}
}

int read_list_of_processes(int *proc)
{
	int i;

	for(i=0; proc[i] != -1; i++);

	return i;
}

int get_giffs_by_pid(int pid)
{
	int fd, len=12, v1,v2,v3,r;
	char buff[2000], fname[20];

	sprintf(fname, "/proc/%d/stat", pid);
	//printf("-->fname :%s\n", fname);

	fd = open(fname, 0, O_RDONLY);
	printf("-->fname :%s, fd :%d\n\n", fname, fd);
	while(1)
	{
		r = read(fd, buff, 10);
		buff[r]='\0';
		printf("%s",buff);
		if(r<len)
			break;
	}

	lseek(fd, 59l, 0);
	r=read(fd,buff,len);
	buff[r]='\0';
	printf("\ngiffes changing :%s\n",buff);
	sscanf(buff,"%d %d", &v1, &v2);
	v3=v1+v2;
	printf("Sum of v1 v2:%d\n", v3);
	lseek(fd,0l,0);
	close(fd);
	return v3;
}

/*int send_gifss_to_ovc(int wfs, int *s, int len)
  {
  return (write(wfs,s,len));

  }*/
