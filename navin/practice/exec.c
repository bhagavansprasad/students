#include<stdio.h>
main()
{
	

		printf(" exec with  pid : %d \n", getpid());

		execl("/home/bhagavan/students/navin/practice/ex","ex",(char*)0);
		printf(" exec end ");

}  

