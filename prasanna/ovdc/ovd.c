#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include"defn_ovdc.h"
int pid_list[1000];

int ovd(int fd)
{
	int j;
	int pid_count;
	ovdc_data w_data;
		
	pid_count = populate_pids_to_array(pid_list);
	
	for(j = 0;j < pid_count ;j++)
	{
		if(pid_list[j] > 1000)
		{
			w_data.jiffs = get_jiffs_by_pid(pid_list[j]);
			w_data.pid = pid_list[j];
			if(w_data.jiffs == -1)
				continue;
		}
		
		write(fd,&w_data,sizeof(ovdc_data));
	}
		
}	

static int populate_pids_to_array(int *pid_list)
{
	int nread,count,fd;
	char buff[2001];	

	system("ps --no-header -eo pid > pid.txt");
	
	fd = open("pid.txt",O_RDONLY);
	if(fd < 0)
	{
		perror("File open failed\n");
		return -1;
	}
	nread = read(fd,buff,2000);
	buff[nread] = '\0';
	close(fd);

	count = get_pid_separate(buff,pid_list);
	return count;
}

static int get_pid_separate(char *buff ,int *pid_list)
{
	int cnt = 0, i;	
	char mem[2000];

	for( ; *buff != '\0';)
	{
		for(;*buff == ' ';buff++);
		for(i=0;*buff != ' ' && *buff != '\0';buff++)
		{
			mem[i] = *buff;
			i++;
		}
		cnt++;
		mem[i-1] = '\0';
		pid_list[cnt] = my_atoi(mem);
	}
	cnt--;
	return cnt;
}

static int getting_nth_word(char *buff,int num,int range)
{
	int count=0,temp,sum=0,i=0,j;
	char word[10];
	for(;*buff!='\0';)
	{
		for(;*buff==' ';buff++);
		for(;*buff!=' ';buff++);
		count++;
		if(count==num)
		{
			buff--;
			for(;*buff!=' ';buff--);
			buff++;
			for(j=0;j<range;j++)
			{
				for(i=0;*buff!=' ';i++)
					word[i]=*buff++;
				buff++;
				word[i]='\0';
				temp=my_atoi(word);
				sum=sum+temp;
			}
			return sum;
		}
	}
}
static int get_jiffs_by_pid(int pid)
{
	
	int fd,nread,fd1;
	char buff[101],path[20];
	sprintf(path,"/proc/%d/stat",pid);
	if((fd = open(path,O_RDONLY)) < 0)
	{
		perror("open failed\n");
		return -1;
	}
	nread = read(fd,buff,100);
	buff[nread] = '\0';
	close(fd);
	
	return getting_nth_word(buff,14,4);
	
}
static int my_atoi(char *str)
{
	int i,n=0;
	for(i = 0;str[i] >='0' && str[i] <='9';i++)
		n = 10 * n + (str[i] - '0');
	return n;
}
