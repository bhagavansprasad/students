#include <stdio.h>
#include <unistd.h>

main(argc , argv)
int argc ;
char *argv[];
{
	printf("Before exec my ID is %d \n",getpid());
	printf("FILe-PermNO.of links Group Owner Size Date Name\n");
	printf("exec starts\n");
	execl(argv[1], argv[2],argv[3],argv[4],(char *)0);
	printf("this will not print\n");
}
