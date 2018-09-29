#include"task_headre.h"

int getting_nth_word(char *buff,int num,int range)
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

int read_jiffs_by_pid(int pid)
{
	
	int fd,nread,fd1,result=0;
	char buff[101],path[20];
	sprintf(path,"/proc/%d/stat",pid);
	if((fd = open(path,O_RDONLY)) < 0)
	{
		printf("%d\n",fd);
		return -1;
	}
	nread = read(fd,buff,100);
	buff[nread] = '\0';
	close(fd);
//	printf("%s\n",buff);				
	fd1 = open("Proc_info.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	write(fd1,buff,100);
	//close(fd1);
	result = getting_nth_word(buff,14,4);
	return result;
}

int my_atoi(char *str)
{
	int i,n=0;
	for(i = 0;str[i] >='0' && str[i] <='9';i++)
		n = 10 * n + (str[i] - '0');
	return n;
}

int getting_all_pids()
{

 	int fd,nread,fd1;
	char buff[2001];
 	system("ps --no-headers -eo pid > pids.txt");

	if((fd = open("pids.txt",O_RDONLY)) < 0)
	{
		printf("%d\n",fd);
		return -1;
	}
	nread = read(fd,buff,2000);
	buff[nread] = '\0';
	close(fd);
	printf("%s\n",buff);				
	
	fd1 = open("pid_info.txt",O_RDWR|O_CREAT|O_APPEND,0666);
	write(fd1,buff,2000);
	printf(" pids :%d\n",getting_nth_word1(buff));
//	getting_nth_word1(buff);
}

int getting_nth_word1(char *buff)
{
	int count=0,temp=0,i=0;
	char word[10];
	for(;*buff!='\0';)
	{
		for(;*buff==' ';buff++);
		for(;*buff!=' ';buff++);
		count++;
		printf("%d\n",count);
		if(count >=100)
		{
			buff--;
			for(;*buff!=' ';buff--);
			buff++;
			for(i=0;*buff!=' ';i++)
				word[i]=*buff++;
			buff++;
			word[i]='\0';
			temp = my_atoi(word);
			return temp;
		}
		
	}
}	

