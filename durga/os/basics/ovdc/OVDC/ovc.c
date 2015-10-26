struct process
{
	int pid;
	int giffes;
};

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/time.h>
#include <signal.h>
#include <sys/resource.h>
char user[] = "OVDC";
char wrng[100];
static int i =0;
time_t now;

int w;

struct process rc;
int store_into_db(int , int  );
void take_action(int , int , int );

int ovc(rfd)
{
	printf("------> ovc is strat----->\n");
	int  r, ret;
	int cpu_occ;
	int fd;
	char buf[100];
	fd = open("log.txt", O_CREAT|O_RDWR, 0777);
	printf("fd return value: %d\n", fd);
	if(fd<0)
	{
		perror("creation faild due to:");
		exit(1);
	}
	ret = sprintf(buf, "user\t pid\t diffr\t\t   worng\t\t\t\t\t\t time\n");
	w = write(fd, buf, ret);

	/*infinte loop starts*/

	for( ; ;)
	{	
		r = read(rfd, &rc, sizeof(struct process));
		printf("read retrn value:%d\n",r);

		cpu_occ = store_into_db(rc.pid, rc.giffes);
		printf("cpu occupincy: %d\n", cpu_occ);

//		take_action(fd, rc.pid, cpu_occ);
	}
}

/*function for store_into_database*/

int arr[100][4] = {0};

int store_into_db(int pid, int giffes)
{
	int dif = 0;
	int j;
	if(i<4 && arr[i][2] == 0)
	{
		arr[i][0] = pid;
		arr[i][1] = giffes;
		printf(" pid arr[%d][0]:and gifs in arr[%d][1]: data base %d\t %d ",i,i, arr[i][0], arr[i][1]);
		arr[i][2] = 1;
		i++;
		return 0;
	}
	else 
	{
		for(j = 0; j<4; j++)
		{
			if(arr[j][0] == pid)
			{
				printf("gifs of the new %d\t and old %d\n", giffes,arr[j][1]);
				dif = giffes -arr[j][1];
				printf("----> cpu_ occupancy is : %d\n", dif);
				arr[j][1] = giffes;
				return dif;
			}
		}
		return -1;
	}

}

/*function for take action on pid*/

/*void take_action(int fd, int pid, int dif)
{
	time(&now);
	if(dif<=10)
	{
		sprintf(buf, "%s\t %d\t %d\t %s\t ", user, pid, dif,ctime(&now) );
		w = write(fd, buf, sizeof(buf));
		if(w < 0)
		{
			perror("writing is failed due to:");
			exit(0);
		}
	}
	if(dif>10 && dif<=15)
	{
		sprintf(wrng, "worning due tp cpu occupyincy in betwen the 10 & 15 ");
		sprintf(buf, "%s\t %")
	}
}*/
