#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "afop.h"
#include "struct_rply.h"
void tcp_client_init(void);
main()
{
	int fd1, fd2, rval, len = 10, wval, lval, first, last, prev, next, sum, node = 20, f1 = 2, f2 = 3, f3 = 4;
	char buff[50];
	tcp_client_init();
	fd1 = aopen ("t.txt",O_RDONLY,0);
	if(fd1 == -1)
	{
		printf("fd1 open unsuccessfull\n");
		printf("error no : %d\n",errno);
		perror("error is: ");
	}
	fd2 = aopen ("r.txt",O_CREAT|O_RDWR,0777);
	if(fd2 == -1)
	{
		printf("fd2 open unsuccessfull\n");
		printf("error no : %d\n",errno);
		perror("error is: \n");
	}
//	while(1)
	//{
		rval = aread(fd1,buff,len);
		printf("in main read rval is %d\n",rval);
		buff[rval]='\0';
		printf("in main buff is : %s\n",buff);
		wval = awrite(fd2,buff,rval);
		lval = alseek(fd1,-15l,2);
		rval = aread(fd1,buff,len);
		printf("in main read rval is %d\n",rval);
		buff[rval]='\0';
		printf("in main buff is : %s\n",buff);
		wval = awrite(fd2,buff,rval);
	//	if(rval < len)
	//		break;

	//}
	first = aget_first();
	prev = aget_prev(node);
	next = aget_next(node);
	last = aget_last();
	sum = aget_fact(2,3,4);
	printf("first : %d\n",first);
	printf("prev of %d : %d\n",node, prev);
	printf("next of %d : %d\n",node, next);
	printf("last : %d\n",last);
	printf("sum of %d,%d,%d : %d\n",f1,f2,f3,sum);
	aclose(fd1);
	aclose(fd2);
}
