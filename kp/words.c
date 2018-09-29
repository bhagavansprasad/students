<<<<<<< words.c
/* prints the num of words */
=======
/* prints the num of words a*/
>>>>>>> 1.7
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include<stdio.h>
main()
{
<<<<<<< words.c
	int f1 = 0,Read_Rtval = 0, nol = 0, i=0,now=0,noc=0;
	char buffer[1000];
=======
	int f1 = 0,Read_Rtval = 0, nol = 0, i=0,now=0,noc=0,j=0;
	char buffer[1000];
>>>>>>> 1.7

<<<<<<< words.c
<<<<<<< words.c
	f1 = open("1.txt",O_RDONLY);

	while(1)
=======
=======
<<<<<<< words.c
<<<<<<< words.c
<<<<<<< words.c
	f1 = open("2.txt",O_RDONLY);

	while(1)
=======
=======
<<<<<<< words.c
=======
>>>>>>> 1.6
	f1 = open("3.txt",O_RDONLY);
<<<<<<< words.c
	printf("rr value = %d",Read_Rtval)
=======
>>>>>>> 1.5
=======
	printf("rr value = %d",Read_Rtval);
>>>>>>> 1.6
>>>>>>> 1.7
	f1 = open("2.txt",O_RDONLY);
	while(Read_Rtval!=0)
>>>>>>> 1.4
	{
<<<<<<< words.c
		Read_Rtval = read(f1,buffer,4);
		Read_Rtval[buffer]='\0';
=======
		Read_Rtval = read(f1,buffer,100);
		Read_Rtval[buffer]='\0';
>>>>>>> 1.7

		for( i =0; i< Read_Rtval;i++)
		{
<<<<<<< words.c
<<<<<<< words.c
			if(buffer[i]==' ')
			{
				now++;
				printf("........%d\n",now);
			}
=======
=======
<<<<<<< words.c
				if(buffer[i]==' ' )
				{
					now++;
					printf("........%d\n",now);
				}
				else()
				{
				printf
				}
=======
>>>>>>> 1.7
		printf("buffer=%c\n",buffer[i]);
			count++;
			printf("output is%d\n",count);
>>>>>>> 1.4
		}

<<<<<<< words.c
		if(Read_Rtval<4)
			break;
			
=======
		if(Read_Rtval<100)
			break;
>>>>>>> 1.7
	}
<<<<<<< words.c
if(buffer[0]==' ')
{
now++;
}
if(buffer[i]=='\0')
{
now++;
}
	printf("no of words are = %d\n",now);
	close(f1);
=======
	printf("no of words are = %d\n",now);
	close(f1);
>>>>>>> 1.7
}
