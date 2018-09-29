#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
//int get_word(char i[],int, char);

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
      
//	printf("sum :%d\n",sum);
	return sum;
}

int get_giffies_by_pid(int pid)
{
	char fname[100], buff[2000];
	int fd = 0,retval,sum=0;

	printf("-->pid :%d\n", pid);
	sprintf(fname,"/proc/%d/stat", pid);
//	printf("-->fname :%s\n",fname);

	fd = open(fname,O_RDONLY);
	printf("-->fd :%d\n",fd);
  	if (fd < 0)
	{
		perror("open failed");
		return 0;
	}	
	retval = read(fd, buff, 1000);
	printf("%d\n",retval);
	printf("buff :%s\n",buff);
	buff[retval]='\0';

	sum = get_n_words_sum(buff, 13, 4);
    close(fd);
	return sum;
}


main()
{
	int list[3] = {929,3418,1649 };
	int i, sum, old=0, curent,l;
	int a[3][3]={0};
	while(1) 
	{ 
		l=0;
		for(i=0;i<3;i++)
		{
			sum = get_giffies_by_pid(list[i]);
			a[l][0]=list[i];
		//	printf("%d \n",a[l][1]);
            a[l][2]=sum-a[l][1];

a[l][1]=sum;
printf("curent:%d \n",a[l][2]);
		   old=sum;
		   l++;
		}   
		sleep(1);
	}
}
#if 0
int get_giffies_by_pid(int pid)
{
	open file

		read file

		read_ 13 to 16 words

		close file;

	return sum
}


main()
{
	for ( ; total pids; )
	{
		get_giffies_by_pid(pid[0]);

		print pid and sum
	}
}
#endif
