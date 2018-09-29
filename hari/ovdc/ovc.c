#include<fcntl.h>
#include<stdio.h>
#include<time.h>
#include <sys/time.h>
#include <signal.h>
#include <sys/resource.h>
struct student
{
	int pid;
	int giffies;
}rc;
void ovc(int p)
{
	int i, j, x, d, y = 0; 
	int r, ret, w, prior, kil;
	time_t now;
	time( &now );
	char buf[50];
	char buff[] = "ovdc"; 
	char wrng[100] = "using high cpu between 20 & 30";
	int fd = open("log.txt",O_CREAT|O_RDWR, 0777);
	printf("---->fd value %d\n", fd);
	ret = sprintf(buf, "user\t pid\t diffr\t\t   worng\t\t\t\t\t\t time\n");
	w = write(fd, buf, ret);

	for (j=0; ; j++)
	{
		for(i = 0;i<5  ; i++)
		{
			r=read(p,&rc,12);
			printf("%d\n",rc.giffies);
			x=rc.giffies;
			d=x-y;
			y=x;
			if(i>=1)
			{
				printf("pid :%d\t difference is :%d\n", rc.pid, d);
				prior = getpriority(PRIO_PROCESS, rc.pid);
				printf("priority: %d\n",prior);


				if(d<=20)
				{
					ret = sprintf(buf, "%s\t %d\t %d\t\t %55s\n", buff, rc.pid,d,ctime(&now));
					w = write(fd, buf, ret);
				}
				else if(d>20 && d<=30)
				{
					ret = sprintf(buf, "%s\t %d\t %d\t\t %s  %5s\n", buff, rc.pid, d, wrng, ctime(&now));
					w = write(fd, buf, ret);
				}
				else if(d>30 &&d <=40)
				{
					prior = getpriority(PRIO_PROCESS, rc.pid);
					//printf("priority: %d\n",prior);	
					int sprior = setpriority(PRIO_PROCESS, rc.pid,prior-5);
					printf("----->set priority: %d\n",sprior);
				}
				else
				{
					kil = kill(rc.pid, SIGSTOP);
					printf("---->kill return value: %d",kil);
					char worng[100] = "process is suspended";
					ret = sprintf(buf, "%s\t %d\t %d\t\t %s  %5s\n", buff, rc.pid, d, worng, ctime(&now));
					w = write(fd, buf, ret);
					/*sleep(2);
					  kil = kill(rc.pid, SIGCONT);
					  printf("---->kill return value: %d",kil);
					  ret = sprintf(buf, "%s\t %d\t %d\t\t %s  %5s\n", buff, rc.pid, d, worng, ctime(&now));
					  w = write(fd, buf, ret);*/

				}

			}


		}
		//sleep(1);
	}
	sleep(1);
}

