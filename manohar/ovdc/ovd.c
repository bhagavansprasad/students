#include "define.h"
#include "error.h"

int ovd(int wfd)
{
	int i = 0,read_retval, sum = -1, errno=0, fd;
	char buff[300];
	char fname[20];
	list data;
	int pid_list[4]={2345,2346,2347,2348};

	while(1)
	{
		for(i=0; i < 4; i++)
		{
			data.pid = pid_list[i];
			sum = -1;

			sprintf(fname, "/proc/%d/stat", pid_list[i]);

			fd = open(fname, O_RDONLY);
			if(fd == -1)
			{
				perror("-->Open failed");
				printf("   errno :%d", errno);
			}
			else
			{
				read_retval = read(fd,buff,300);
				buff[read_retval]='\0';
				sum=get_giffys(buff);
			}

			data.giffy = sum;
			write(wfd, (char *)&data, sizeof(data));

		}
		sleep(1);
	}

}

int get_giffys(char *buff)
{
	int i=0,j=0,count =0,sum=0;
	char temp[10];
	for(i = 0;buff[i] != '\0';i++)
	{
		temp[j] = buff[i];
		j++;
		if(buff[i+1]==' ')
		{
			temp[j]='\0';
			count ++;
			i = i + 1;
			j=0;
			if(count > 12 && count < 17)
				sum = sum + aatoi(temp);
		}
	}
	return sum;
}

int aatoi(char *str)
{
	int i=0,j=1,a,b,k=0,n;
	for(i = 0;str[i] != '\0'; i++)
	{
		b=str[i]-48;
		n = strlen(str);
		a=1;
		for(j = 1;j < n-i;j++)
		{
			a=a*10;
		}
		k = k + b * a;
	}
	return k;
}


