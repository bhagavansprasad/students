#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
struct ovdc_data
{
	int pid;
	int giffs;
};

	int ovd_entry_function(int wfd)
	{
	struct ovdc_data data;
	int pid[3]={3363,3357,3369};
	char fname[128];
	char buff[2048];
	int fd = 0, retval,i,sum;
	char pid_list[1000];

	buff[retval]='\0';
	int k=0,a=0,j=0,count=0;

	while(1)
	{
for(i=0;i<=2;i++)
	{
		sum = get_giffies_by_pid(pid[i]);
		data.pid = pid[i];
		data.giffs = sum;

		printf("-->OVD Before writing to OVC: pid :%d, giffs :%d\n", data.pid, data.giffs);
		write(wfd, &data, sizeof(struct ovdc_data));
		 close(fd);

	}
	}
}


int get_giffies_by_pid(int pid)
{
	char fname[100], buff[2000];
	int fd = 0,retval,sum=0;

		printf("-->pid :%d\n", pid);
	sprintf(fname,"/proc/%d/stat", pid);
	//	printf("-->fname :%s\n",fname);

	fd = open(fname,O_RDONLY);
	//	printf("-->fd :%d\n",fd);
	if (fd < 0)
	{
				perror("open failed");
		return 0;
	}	
	retval = read(fd, buff, 1000);
	printf("buff :%s\n",buff);
	buff[retval]='\0';

	sum = get_n_words_sum(buff, 13, 4);
	close(fd);
	return sum;
}
int get_n_words_sum(char *buff, int start_word, int num_words)
{ 
	int j, i = 0,sum,c,k,a;
	char b[100];

	for(j=1;j<=start_word;j++)
	{
		for( ;buff[i]!=' ';i++);
		i++;
	}
	sum=0; 
	for(c=1;c<=num_words;c++)
	{
		for(k=0  ;buff[i]!=' ';i++) 
		{
			b[k]=(buff[i]);
			k++;
		}
		b[k]='\0';
		i++;
		//printf("%s\n",b);
		a=atoi(b);
		sum=sum+a;

	}
	//		printf("-->sum:%d\n",sum);
	return sum;
}
#if 0
int get_giffies_by_pid(int pid)
{
	char fname[100], buff[2000];
	int fd = 0,retval,sum=0;

	//	printf("-->pid :%d\n", pid);
	sprintf(fname,"/proc/%d/stat", pid);
	//	printf("-->fname :%s\n",fname);

	fd = open(fname,O_RDONLY);
	//	printf("-->fd :%d\n",fd);
	if (fd < 0)
	{
		//		perror("open failed");
		return 0;
	}	
	retval = read(fd, buff, 1000);
	printf("buff :%s\n",buff);
	buff[retval]='\0';

	sum = get_n_words_sum(buff, 13, 4);
	close(fd);
	return sum;
}

//		sprintf(fname,"/proc/%d/stat", pid);
fd = open(fname, O_RDONLY);
//		printf("-->fd :%d\n",fd);
if (fd < 0)
{
	perror("open failed");
	continue;
}	
retval = read(fd, buff, 1000);
//		printf("buff :%s\n",buff);
buff[retval]='\0';
//		retval = get_n_words_sum(buff, 13, 4);

//		data.pid = pid;
data.giffs = retval;

//		printf("-->OVD Before writing to OVC: pid :%d, giffs :%d\n", data.pid, data.giffs);
write(wfd, &data, sizeof(struct ovdc_data));
close(fd);
//	return sum;

#endif	
//}
//}

