#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
int list_of_numbers[500];
int j=0;
void display(int *list_of_numbers,int n);
int parse_and_store(int *list_of_numbers, char *buffer);

void bubble(int *list_of_numbers, int x);

main()
{
	read_file("sort.txt");
}

int read_file(char *file)
{
	int fs,retval=0;
	char buffer[1024];
	int list_of_numbers[500];
	int	tot_numbers;

	if((fs=open(file, O_RDONLY, 0))==-1)
	{
		printf("error in open a file");
		exit(1);
	}

	while(1)
	{
		retval = read(fs, buffer, 100);
		buffer[retval] = '\0';
		//printf("%s\r\n", buffer);

		tot_numbers = parse_and_store(list_of_numbers, buffer);

		//display(list_of_numbers, j); // this is display function

		//bubble(list_of_numbers, j);// this is sorting function

		//printf("\n\n");

		display(list_of_numbers, j);
		if(retval<100)
			break;
	}
	close(fs);
}



int parse_and_store(int *list_of_numbers, char *buffer)
{
	int  i=0,k=0;
	char temp[1024];

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
}

// this is a display function to display the content of filr

void display(int *list_of_numbers,int n)
{
	int i; 
	for( i = 0; i < j  ; i++ )
	{
		printf(" list_of_numbers -->%d\n\r",list_of_numbers[i]);
	}
}




// this is a bubble sort function to sort the given array
void bubble(int *a, int x)
{
	int  i,j,temp=0;

	for(i=0;i<x;i++)
	{
		for(j=0;j<x-1;j++)
		{
			if(a[j]>=a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}





