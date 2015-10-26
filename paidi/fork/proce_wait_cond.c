#include <stdio.h>
/*main()
  {
  int pid;
  pid=fork();
  printf("%d\n",getpid());
  if(pid>0)
  {
  printf("parent\n");
  wait(1);
  }
  else
  {
  printf("chaild\n");
  }
  }*/

/*main()
  {
  int pid;
  pid=fork();
  if(pid==1)
  {
  printf("chald \n");
  }
  else
  {
  printf("parent\n");
  }
  }*/


/*
   main()
   {
   int pid;
   pid=fork();
   if(pid<0)
   printf("fork faild\n");
   else
   printf("fork succeeded\n");
   }
 */


main()
{
	int pid;
	pid=fork();
	if(pid==0)
	{
		printf("i am chaild,my process ID is %d\n",getpid());
		printf("i am chaild's,parent ID is %d\n",getpid());
	}
	else
	{
		printf("i am the parent,my process ID is %d\n",getpid());
		printf("the parents parent process ID is %d\n",getpid());
	}
}

