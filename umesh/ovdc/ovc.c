#include "stdio.h"
#include<signal.h>
#include<sys/time.h>
#include <unistd.h>
#include<sys/resource.h>
#include<string.h>
struct ovdc_data
{
	int pid;
	int giffs;
};

void ovc_entry_function(int rfd)
{
	struct ovdc_data data;
	int sum,curent,old;
	int a[1000][3]={0};
	int l=0;
	int which=PRIO_PGRP;
int i=0;
while(1)
	{
		read(rfd, &data, sizeof(struct ovdc_data));
		//			sum = get_n_words_sum(b, 13, 4);
			printf("-->OVC : pid :%d, giffs :%d\n", data.pid, data.giffs);
		a[l][0]=data.pid;
int prio=14;	
			printf("sum:%d\n",data.giffs);
		a[l][2]=data.giffs - a[l][1];
		printf("curent:%d",a[l][2]);
	//	if(a[l][2]>=40 && a[l][2]<=50)
	//	{
	//		signal(d.pid,SIGSTOP);
			//	printf("error");
	//	}
		if(a[l][2]>=5 && a[l][2]<=20)
		{
//		  printf("enter nice");
int retval= getpriority(which, data.pid);
printf("retval:%d\n",retval);
int reval= setpriority(which,data.pid,prio);   
printf(":%d\n",reval);
}
//		}
//		if(a[l][2]>=60 && a[l][2]<=70)
//		{
//		 printf("enter stop");
//
///			signal(d.pid,SIGSTOP);
//			sleep(5);
//
//			signal(d.pid,SIGCONT);
//		}	
//			if(a[l][2]>=40)
//			{
//			printf("enter kill");
//
//				kill(data.pid,SIGQUIT);
//				sleep(5);
//			}



			a[l][1]=data.giffs;
			printf("old:%d \n",a[l][1]);
			l++;


		
	}
}
