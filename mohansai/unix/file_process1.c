#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
int aatoi(char *name);
int list_of_numbers[500];
int j=0;
int parse_and_store(int *list_of_numbers, char *buffer);

main(int argc , char *argv[])
{
	int  fs;
	if (argc < 2)
	{
		printf("Invalid arguments\r\n");
		exit(1);
	}
	if((fs=open(argv[1], O_RDONLY, 0)) == -1)    
    {
        printf("error in opening a file for reading :%s\r\n", argv[1]);
        exit(1);
	}
	
	read_file("fs"); 

}

int read_file(char *file)
{
	int fs,retval=0;
	char buffer[1024];
	int list_of_numbers[500];
	int	tot_numbers;

	printf("-->file :%s\r\n", file);
	if((fs=open(file, O_RDONLY, 0))==-1)
	{
		printf("error in open a file\n");
		exit(1);
	}

	while(1)
	{
		retval = read(fs, buffer, 100);
		buffer[retval] = '\0';
		tot_numbers = parse_and_store(list_of_numbers, buffer);

		if(retval<100)
			break;
	}
	close(fs);
}
int parse_and_store(int *list_of_numbers, char *buffer)
{
	int  i=0,k=0;
	char temp[1024];
	int count=0;
	for( i = 0,k = 0; buffer[i] != '\0'; i++,k++ )
	{
		if(buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\r')
		{
			temp[k]=buffer[i];
		}
		else
		{
			for( ; buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] =='\r' ;i++);
			temp[k]='\0';

			if(k != 0)
			{
				list_of_numbers[j] = aatoi(temp);
				j++;
			}
			k = -1;
			i--;
		}
	}



	for( j = 13 ; j <=16 ; j++)	
	{
		count=	count+list_of_numbers[j] ;
	}
	printf("count-->%d\n",count);

}

int aatoi(char *name)
{
	int i,temp = 0, temp1 = 0 ;
	for(i=0 ; name[i] != '\0' ; i++)
	{
		if(name[i]>='0' && name[i]<='9')
		{
			temp=name[i]-48;
			temp1 = temp1 * 10 + temp;
		}
	}
	return(temp1);
}

