#include <stdio.h>
main()
{ 
 int a=10;
 printf("%d\n",a);
	printf("after the exec my process's id is %d\n",getpid());
	printf("my parent process id is %d\n",getppid());
	printf("exec ends\n");
}
