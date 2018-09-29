#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
//int get_word(char i[],int, char);
char pidget(char *,int);

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

#if 0
main()
{
	while(1)
	{
		store pid list in a text file
			read all pids and convert them to ints and store in int array
			for (all pid list)
			{
				get giffies by pid
					print the diff between old giffies and new giffs
			}
		sleep(1);
	}
}
#endif

main()
{
	int sum, old=0, curent;
	int c[1000][3];
	int l;
	char pid_list[1000];
	int i;
	int b[1000];
	char buff[10000];
	system("ps --no-header -eo\"%p\" > t.txt");
	int fd = open("t.txt", O_RDONLY);
	int retval=read(fd, buff, 10000);

	buff[retval]='\0';
	int k=0,a=0,j=0,count=0;


	for(i=0; buff[i]!='\0';i++)
	{
		for(k=0; buff[i]!='\n';i++ ) 
		{

			pid_list[k]=(buff[i]);
			k++;
		}
		count ++;

		a=atoi(pid_list);
		b[j]=a;
		j++;
	}
	b[j]='\0';

//	while(1) 
//	{
//		printf("%d\n",count);
//        for(j=0;j<=1;j++)
//		{
		l=0;
		for (i = 0; i<= count ; i++)
		{
			sum = get_giffies_by_pid(b[i]);


			c[l][0]=b[i];

		printf("-->sum:%d \n",sum);			//	printf("-->pid:%d \n",c[l][0]);
			printf("old:%d \n",c[l][1]);
			c[l][2]=sum-c[l][1];

			c[l][1]=sum;
						       printf("curent:%d \n",c[l][2]);
			old=sum;
			l++;
		}   
		sleep(1);
//	}
}
#if 0
int	populate_pid_list_from_buffer(char *pid_list, char *buff)
{
	int k,i=0,count=0;
	char b[100];
	int a;
	for(i=0; buff[i]!='\0';i++)
	{
		//	printf("%s\n",buff);
		for(k=0; buff[i]!='\n';i++ ) 
		{
			//	printf("%d\n",i);
			pid_list[k]=(buff[i]);
			//		printf("%c\n", buff[i]);
			k++;
		}
		count++;
		//	printf("%d\n",count);
		//		printf("%s\n",b);

		a=atoi(pid_list);
		printf("%d\n",a);
	}
	pid_list[k]='\0';
	for (i = 0; i< pid_count; i++)
	{
		sum = get_giffies_by_pid(pid_list[i]);
		return sum;
	}


}	
#endif




