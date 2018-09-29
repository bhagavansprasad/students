#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include "rpc_calls.h"
#include "rpc_structs.h"
#include <stdio.h> //printf
#include <string.h>    //strlen
#include <sys/socket.h>    //socket
#include <arpa/inet.h> //inet_addr
#define MAX_READ_LEN 100

int c_sock = -1;
asuds d1;
st_dump dmp;
sgets s1;
int num;
#if 0
static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
char getche(void) 
{
  return getch_(1);
}
#endif
int main(int argc, char *argv[])
{
	char buff[MAX_READ_LEN];
	int rdval=0, wrval=0, flag=0;
	int fdt = -1, fds = -1;
	int ch;


	if((c_sock = c_comminit()) == -1)
	{
		printf("Failed to communicate\n");
		exit(1);
	}

	if(argc == 1)
	{
		printf("Array operations\n0->For exit\n1->get_first\n2->get_next\n3->get_prev\n4->get_last\nEnter ur choice : ");
		scanf("%d",&ch);
		while(1)
		{

			if(ch != 0)
			{
				repeat: 

				switch(ch)
				{
					case 1: get_first();
						 	 break;
					case 2: printf("\nEnter the no :");
							 scanf("%d", &ch);
							 get_next(ch);
							 break;
					case 3: printf("\nEnter the no :");
							 scanf("%d", &ch);
							 get_prev(ch);
							 break;
					case 4: get_last();
							 break;
					default:
							{
								printf("\nWrong choice\nEnter correct choice : ");
								scanf("%d", &ch);
								goto repeat;
							}
				}
				printf("\nThe array num is -> %d\n", num);
				printf("Go for another choice ->");
				scanf("%d", &ch);
			}
			else
				exit(0);
		}
		printf("you are exiting\n");
	}

	else if(argc == 3)
	{
		rpc_open( argv[1], O_RDONLY, 0644);
		fds = d1.asust.rp_open.o_fd;
		printf("\nfirst file fds : %d\n", fds);

		if( fds < 0)
		{
			perror("First file not opens ---> ");
			printf("errno --- >%d \n", d1.asust.rp_open.o_errno);
			exit(1);
		}

		rpc_open( argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
		fdt = d1.asust.rp_open.o_fd;
		printf("\nsecond file fdt : %d\n", fdt);

		if( fdt < 0)
		{
			perror("Second file not opens ---> ");
			printf("errno --- >%d \n", d1.asust.rp_open.o_errno);
			exit(1);
		}

		while(1)
		{
			rpc_read( fds, buff, MAX_READ_LEN);
			rdval = d1.asust.rp_read.rdval;

			if( rdval < 0)
			{
				perror("Error ");
				printf("errno->\n",d1.asust.rp_read.r_errno);
				exit(1);
			}

			strcpy(buff, d1.asust.rp_read.buff);

			rpc_write( fdt, buff, rdval);
			wrval = d1.asust.rp_write.wrval;

			if( wrval < 0)
			{
				perror("Error ");
				printf("errno->\n",d1.asust.rp_write.w_errno);
				exit(1);
			}

			if(rdval < MAX_READ_LEN)
				break;
		}

		rpc_close( fds );
		flag = d1.asust.rp_close.c_retval;

		if(flag == -1)
		{
			perror(" ---> Unable to close first file <---\n");
			printf("errno --- >%d\n",  d1.asust.rp_close.c_errno);
		}

		rpc_close( fdt );
		flag = d1.asust.rp_close.c_retval;

		if(flag == -1)
		{
			perror(" ---> Unable to close second file <---\n");
			printf("errno --- >%d\n",d1.asust.rp_close.c_errno);
		}

		printf("\n---> Task done and exiting client <---\n\n");
	}
	else
	{
		printf("Incorrect no of arguments\n");
		exit(1);
	}
	return 0;
}
