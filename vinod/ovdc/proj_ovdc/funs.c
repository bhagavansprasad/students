#include "defs.h"

int get_proc_list(int *ptr)
{
	DIR *d;
	struct dirent *dir;
	int index = 0;
	int count=0;

	d = opendir("/proc");

	if(d)
	{
		while((dir = readdir(d)) != NULL)
		{
			if(atoi(dir->d_name) != 0)
			{
				ptr[count] = atoi(dir->d_name);
				count++;
			}
		}
		#if 0
		while( index < count )
		{
			printf("The directory list is %d\r\n",ptr[index]);
			index++;
			//count--;
		}
		#endif
		closedir(d);
	}
	return count;
}

void ctrlmsg(int val, int pid)
{
	if(val>10 && val<=30)
		printf("--> Process with pid :%d is using limited cpu\n", pid);
	else if(val>30 && val<=60)
		printf("--> Process with pid :%d is using fine cpu\n", pid);
	else if(val>60 && val<=90)
	{	
		printf("--> Putting process with pid :%d in wait state\n", pid);
		change_priority(pid, 5);
	}
	else if(val>90 && val<=100)
	{
		printf("--> killing the pid :%d \n", pid);
		kill(pid, SIGKILL);
	}
}

void change_priority(int pid, int priority)
{
	int which = PRIO_PROCESS;
	int ret;
	ret = setpriority(which,pid,priority);
	if(ret < 0)
	{
		perror("Unable to set -> ");
		exit(1);
	}
	printf("Priority of pid :%d is changed\n", pid);
}

int get_jiffy(int fd)
{
	int count=0;
	int i=0,j=0;
	int rdval=0;
	int pos=13;
	char string[20];
	unsigned long int cpu1,cpu2;
	long int cpu3,cpu4;
	char buff[BUFF_SIZE];

	rdval = read(fd, buff, BUFF_SIZE);
	buff[rdval] = '\0';

	for(i=0 ; buff[i] ; i++)
	{
		if(buff[i] != ' ' && buff[i] != '\0')
		{
			count += 1;

			for( ; buff[i] != ' ' && buff[i+1] != '\0'; i++)
			{
				if(count >= pos && count <= (pos+3))
				{
					string[j] = buff[i];
					string[j+1] = '\0';
					j++;
				}
			}
			if(count >= pos && count <= (pos+3))
			{
				string[j] = ' ';
				j++;
			}
			if(count == (pos+3))
			{
				sscanf(string, "%lu %lu %ld %ld", &cpu1, &cpu2, &cpu3, &cpu4);
				//printf("cpu1 : %lu, cpu2 : %lu, cpu3 : %ld, cpu4 : %ld\n", cpu1, cpu2, cpu3, cpu4);   
				return (cpu1+cpu2+cpu3+cpu4);
			}
		}
	}
	close(fd);
	return 0;
}

int get_fd(int pid)
{
	char pathname[20];
	int fd=0;

	sprintf(pathname, "%s%d%s", "/proc/",pid,"/stat");
	//printf("--> pathname : %s\n",  pathname);
	if((fd = open(pathname, O_RDONLY, 0444)) < 0)
	{
		//perror(" unable to open file : ");
		return -1;
	}
	//printf("--> GET FD :%d\n", fd);
	return fd;
}
