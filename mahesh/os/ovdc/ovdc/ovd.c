#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
struct ovd_struct
{
	int pid;
	int giffs;
}ovd;
int read_list_of_processes(int *p)
{
	printf("----> size of p : %d\n",sizeof(p));
	return (sizeof(p)/sizeof(int));
}
int get_giffs_by_pid(int pid)
{
	int fd,r,v3,v1,v2,l=10;
	char buf[20];
	char str[20];
	printf("---> pid is : %d\n",pid);
	sprintf(str,"/proc/%d/stat",pid);
	fd=open(str,O_RDONLY);
	printf("--> fd is : %d\n",fd);
	if(fd == -1)
	{
		printf("open failure\n");
		exit(1);
	}
	while(1)
	{
		r=read(fd,buf,10);
		buf[r]='\0';
		printf("%s",buf);
		if(r<l)
			break;
	}
	lseek(fd,64l,0);
	r=read(fd,buf,12);
	buf[r]='\0';
	printf("\n%s\n",buf);
	sscanf(buf,"%d %d",&v1,&v2);
	v3=v1+v2;
	printf("--> giffs : %d\n",v3);
	return v3;
}
int ovd_fun(int wfd)
{
//	int data_base[4][2];
	int k =0;
	for (;k<3;k++)
	{
		int proc_list[4]={23286,23352,23417,23481};
		int i,proc_count,giffs;
		//proc_count = read_list_of_processes(proc_list);
		proc_count = sizeof(proc_list)/sizeof(int);
		printf("---> proc count : %d\n",proc_count);
		for (i=0;i<proc_count;i++)
		{
			giffs = get_giffs_by_pid(proc_list[i]);
//			data_base[i][0]=proc_list[i];
//			data_base[i][1]=giffs;
			ovd.pid = proc_list[i];
			ovd.giffs = giffs;
			//send_gifss_to_ovc(wfd, proc_list[i], giffs);
			write(wfd,&ovd,sizeof(ovd));
		}
	//	write(wfd,data_base,sizeof(data_base));

		sleep(1);
	}
}
