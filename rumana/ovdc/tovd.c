#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
struct data
{
	int pid;
	int giffies;
};
int read_list_of_processes(int *proc);
int get_giffies_by_process(int pid);
int ovd(int p)
{
	struct data s;
		int i,proc_count,w;
	int proc_list[10]={-1};
	proc_count=read_list_of_processes(proc_list);
	printf("list of process is %d\n",proc_count);
	for(;;)
	{
		for(i=0;i<proc_count;i++)
		{
			s.pid=proc_list[i];
			s.giffies=get_giffies_by_process(proc_list[i]);
			printf("return value of giffies:%d\n",s.giffies);

			w=write(p,&s,sizeof(s));
			printf("writing in to ovc :%d\n",w);
			if(w<0)
			{
				perror("write is failed");
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

/* for list of process*/
int read_list_of_processes(int *proc)
{
int i;
for(i=0;proc[i]!=-1;i++);
return i;
}

/*getting giffies by a process*/
int get_giffies_by_process(int pid)
{
int fd,len=12,v1,v2,v3,r;
char buff[100],fname[100];
sprintf(fname,"/porc/%d/stat",pid);
printf("fname:%s\n",fname);
fd=open(fname,0,O_RDONLY);
printf("fd is :%d\n",fd);
while(1)
{
r=read(fd,buff,len);
buff[r]='\0';
printf("%s",buff);
if(r<len)
break;
}
lseek(fd,59l,0);
r=read(fd,buff,len);
buff[r]='\0';
printf("changing giffies is :%s \n",buff);
sscanf(buff,"%d %d",&v1,&v2);
v3=v1+v2;
printf("sum is %d",v3);
lseek(fd,0l,0);
close(fd);
return(v3);
}

