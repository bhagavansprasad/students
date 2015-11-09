#include<stdio.h>
struct cmd
{
<<<<<<< HEAD
	char cmd[10];
	int (*p)(int,int);
=======
	char *q[10];
	int (*p[])(int,int)={add,sub,mul,div};
>>>>>>> cf910f9351b12602d46981bd3b7c9eb08fcb4592
	//char tcmd[10];
};
main()
{
<<<<<<< HEAD
int a,b,i,add,sub,div,mul;
char tcmd[10];
	struct cmd commands[4]={{"add",add},
=======
int a,b,i;

	struct cmd commands
	commands.q[10]={{"add",add},
>>>>>>> cf910f9351b12602d46981bd3b7c9eb08fcb4592
		{"sub",sub},
		{"mul",mul},
		{"div",div},
	};
	for(i=0;i<4;i++)
	{
<<<<<<< HEAD
	printf("%s",commands[i].cmd);
		if(strcasecmp(commands[i].cmd,tcmd)==0)
			printf("%d",commands[i].p(a,b));
=======
	//printf("%s",commands[i].cmd);
		if(strcasecmp(commands[i].cmd,commands.d[i])==0)
			printf("%d",commands[i],(*p[i])(a,b));
>>>>>>> cf910f9351b12602d46981bd3b7c9eb08fcb4592
	}
}
