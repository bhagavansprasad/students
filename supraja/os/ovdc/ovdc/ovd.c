#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
int read_list_of_processes(int p[])
{
	return (sizeof(p)/sizeof(int));
}
int get_giffs_by_pid(int pid)
{
	int fd,r,v3,v1,v2,l=10;
	char buf[20];
	fd=open("/proc/pid/stat",O_RDONLY);
	if(fd == -1)
	{
		printf("open failure\n");
		exit(1);
	}
	while(1)
	{
		r=read(fd,buf,12);
		buf[r]='\0';
		printf("%s",buf);
		if(r<l)
			break;
	}
	lseek(fd,59l,0);
	r=read(fd,buf,12);
	buf[r]='\0';
	printf("\n%s\n",buf);
	sscanf(buf,"%d %d",&v1,&v2);
	v3=v1+v2;
	printf("--> giffs : %d\n",v3);
	return v3;
}
int ovd(int wfd)
{
	int data_base[4][2];

	for (;;)
	{
		int proc_list[]={21286,21301,21365,21429};
		int i,proc_count,giffs;
		proc_count = read_list_of_processes(proc_list);
		for (i=0;i<proc_count;i++)
		{
			giffs = get_giffs_by_pid(proc_list[i]);
			data_base[i][0]=proc_list[i];
			data_base[i][1]=giffs;
			//send_gifss_to_ovc(wfd, proc_list[i], giffs);
		}
		write(wfd,data_base,sizeof(data_base));

		sleep(1);
	}
}
