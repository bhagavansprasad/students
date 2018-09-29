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
	int pid = 2266;
	char fname[128];
	char buff[2048];
	int fd = 0, retval;

	while(1)
	{
		printf("-->pid :%d\n", pid);
		sprintf(fname,"/proc/%d/stat", pid);
		fd = open(fname, O_RDONLY);
		printf("-->fd :%d\n",fd);
		if (fd < 0)
		{
			perror("open failed");
			continue;
		}	
		retval = read(fd, buff, 1000);
		printf("buff :%s\n",buff);
		buff[retval]='\0';
		retval = get_n_words_sum(buff, 13, 4);

		data.pid = pid;
		data.giffs = retval;

		printf("-->OVD Before writing to OVC: pid :%d, giffs :%d\n", data.pid, data.giffs);
		write(wfd, &data, sizeof(struct ovdc_data));
		 close(fd);
		//	return sum;

	}
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
	return sum;
}

