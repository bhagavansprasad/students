#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

main()
{
char pid_list[1000];
int i;
int b[1000];
	char buff[10000];
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


	for (i = 0; i< count ; i++)
	{
	printf("%d\n",b[i]);
	}

}
//int getpid_list(char *buff,int i)
//{
//int k,a=0;
//char pid_list[1000];
//printf("%s\n",buff);
//	printf("%d\n",i);
//	for(k=0; buff[i]!='\n';i++ ) 
//	{
//	printf("%d\n",i);
//		pid_list[k]=(buff[i]);
//		k++;
//	}
//		printf("%s\n", pid_list);
//	printf("%d\n",i);
//	a=atoi(pid_list);
//	printf("%d\n",a);
//	return a;
	
//	}
	

#if 0
{
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
		k++;
	}
	count++;
//	printf("%d\n",count);
	//		printf("%s\n",b);
	
	a=atoi(pid_list);
//	printf("%d\n",a);
	}
	return count;
	pid_list[k]='\0';
//		printf("%s\n", pid_list);

}	
#endif

