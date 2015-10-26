#include "define.h"
main()
{
	int fd,read_retval,sum,i,prev_val=0,usage;
	char buff[300];
	char fname[20];
	int pid[2][4]={4478,4479, 4480, 4481};
	while(1)	
	{
		for(i=0;i<4;i++)
		{
		pid[0][i];
		sprintf(fname,"/proc/%d/stat",pid[0][i]);
		fd = open(fname,O_RDONLY);
		if(fd == -1)
		{
			printf("file open failed\n");
			exit(1);
		}

		read_retval = read(fd,buff,300);

		buff[read_retval]='\0';

		sum=get_giffys(buff);
		usage = sum - pid[1][i];
		pid[1][i] = sum;
		printf("pid---->%d usage---->%d\n",pid[0][i],usage);

		}
		sleep(1);
	}
}
int get_giffys(char *buff)
{
	int i=0,j=0,count =0,sum=0;
	char temp[]=" ";
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

