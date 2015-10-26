#include<stdio.h>
#include<fcntl.h>
struct node
{
int pid;
int giffies;
}s;
int ovd(int p)
{
int fd[4],v1,v2,v3,i,j,r,w;
char buff[100];
int a[4]={4794,4852,4910,4968};
fd[0]=open("/proc/4794/stat",O_RDONLY);
fd[1]=open("/proc/4852/stat",O_RDONLY);
fd[2]=open("/proc/4910/stat",O_RDONLY);
fd[3]=open("/proc/4968/stat",O_RDONLY);
printf("fd[0] is %d\n",fd[0]);
printf("fd[1] is %d\n",fd[1]);
printf("fd[2] is %d\n",fd[2]);
printf("fd[3] is %d\n",fd[3]);
for(i=0;;i++)
{
  for(j=0;j<5;j++)
   {
         while(1)
		 {
            r=read(fd[i],buff,12);
			buff[r]='\0';
			printf("%s",buff);
			if(r<12)
			break;
		 }
		 lseek(fd[i],59l,0);
		 r=read(fd[i],buff,12);
		 buff[r]='\0';
		printf("%s\n",buff); 
		 sscanf(buff,"%d %d",&v1,&v2);
		 		 v3=v1+v2;
         s.giffies=v3;
		 s.pid=a[i];
		 w=write(p,&s,12);
		 sleep(2);
		 lseek(fd[i],0l,0);
		 printf("\n");
  }
close(fd);
}
}
