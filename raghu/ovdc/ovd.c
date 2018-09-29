#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

struct data
{
	int pid;
	int giffe;
};	

struct data base;

int send_data(int fd);

int ovd(int p)
{
	int i=0;
	int fd;
	int pwd=0;
	int pid[4] = {23609,23628,23635,23641};
	char str[100];
	int retval;
	int j=0;
	for(i=0;;i++)
	{
		sprintf(str,"/proc/%d/stat",pid[i]);
		fd = open(str,O_RDONLY,0);
		if(fd == -1)
		{
			perror("opening process failed");
			exit(0);
		}
		//for(j=0;j<4;j++)
		//{
			retval = send_data(fd);
			base.pid = pid[i];
			base.giffe = retval;
			pwd=write(p,&base,sizeof(base));
			//printf("pwd = %d\n",pwd);
			printf("pid = %d\n",base.pid);
			//printf("giffe = %d\n",base.giffe);
		//}
	if(i == 3)
	{
		i = -1;
		sleep(1);
	}
		
	}

}

int send_data(int fd)
{
	int rfd;
	int wc;
	int a,b,c,d;
	int sum=0;
	int i=0,j=0,k=0;
	char buff[500];
	char str[100];
	wc =1;
	k = 0;
	rfd = read(fd,buff,400);
	buff[rfd] = '\0';
	//printf("%s\n",buff);
	if(rfd == -1)
	{
		perror("reading data failed\n");
		exit(0);
	}
	for(j=0;buff[j] != '\0';j++)
	{
		if(buff[j+1]!=' ' && (buff[j]==' '||buff[j]=='\n'||buff[j]=='\0'))
			wc = wc+1;
		if(wc == 14||wc == 15||wc == 16||wc == 17)
		{
			str[k]=buff[j+1];
			k++;
		}
	}
	str[k]='\0';
	//printf("str = %s\n",str);
	sscanf(str,"%d %d %d %d",&a,&b,&c,&d);
	sum = a+b+c+d;
	//printf("sum = %d\n",sum);
	lseek(fd,0l,0);
	//sleep(1);
	return sum;
}
