#include<stdio.h>
#include<time.h>
#include<sys.resource.h>
struct data
{
int pid;
int giffies;
};
time_t now;
time(&now);
int ovc(int p)
{
struct data rc;
int r,cpu_occ;
char buff[100];
fd=open("txt.log",CREAT|ORDWR,0777);
printf("ovc fd is %d\n",fd);
for(;;)
{
r=read(p,&rc,sizeof(rc));
buff[r]='\0';
cpu_occ=store_into_db(rc.pid,rc.giffies);
printf("cpu occupancy :%d\n",cpu_occ);
sleep(1);
}
}
