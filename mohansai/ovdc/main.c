#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "fcntl.h"
void ovc(int read_fd);
void ovd(int write_fd, int pid);
#define STAT_FILE_SIZE 5000
#define PID_COUNT 1000
//#define DEBUG 0

int get_pid_list(char *buffer, int *list_of_numbers)
{
	char temp[1024];
	int i=0, j=0, k=0, count=0;

	for(  ; buffer[i] != '\0'; i++, k++)
	{
		if(buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r')
		{
			temp[k]=buffer[i];
			count++;	
#ifdef DEBUG
		printf("temp[k] %c\n\r",temp[k]);
#endif
		}
		else
		{
			for( ; buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] =='\r' ;i++);

			if(k>0)
			{
				temp[k]='\0';
#ifdef DEBUG
				printf("temp--> %s \n\r",temp);
#endif

				list_of_numbers[j]=atoi(temp);
				
#ifdef DEBUG
				printf("list_of_numbers[%d]--> %d \n\r",j,list_of_numbers[j]);
#endif
				
				j++;
			}	
			i--;
			k=-1;
		}
	}
	
#ifdef DEBUG
	printf("j--> %d",j);
#endif
	return j;
}


int main()
{
	int fd[2], pid,i,j,k=0;
	int fs, retval=0; // thiis is for the file operation
	char buffer[STAT_FILE_SIZE];
	int pid_list[PID_COUNT], tot_pids=0;

	pipe(fd);
	pid = fork();

	//0 - read - parent
	//1 - write - child

	if(pid == 0)
	{
		
#ifdef DEBUG
		printf("-->main: I am child\n\r");
#endif
		close(fd[0]);

		for( i=0 ; ; i++ )
		{
			system("ps -A -o pid > pid.txt");

			fs = open("pid.txt", O_RDONLY);

			if(fs==-1)
			{
				perror("error in open the system pids");
				exit(1);
			}

			while(1)
			{
				retval = read(fs, buffer, STAT_FILE_SIZE);

				buffer[retval+1]='\0';
				tot_pids = get_pid_list(buffer, pid_list);

				if(retval < STAT_FILE_SIZE)
					break;
			}
			close(fs);

#ifdef DEBUG
			printf ("-->ovd tot_pids :%d\r\n", tot_pids);
#endif
			for( j =100 ; j < tot_pids ; j++)		
			{
			    if (pid_list[j] <= 10)
					continue;

#ifdef DEBUG
				printf("-->main: %d: %d", j, pid_list[j]);
#endif
				ovd(fd[1], pid_list[j]);
			}
			sleep(1);
		}
	}
	else
	{
		
#ifdef DEBUG
		printf("-->main: I am parent\n\r");
#endif
		close(fd[1]);
		//sleep(1);
		ovc(fd[0]);
	}
	return 0;
}

