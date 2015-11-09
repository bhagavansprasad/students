#include<stdio.h>
struct cmd
{
	char *q[10];
	int (*p[])(int,int)={add,sub,mul,div};
	//char tcmd[10];
};
main()
{
int a,b,i;

	struct cmd commands
	commands.q[10]={{"add",add},
		{"sub",sub},
		{"mul",mul},
		{"div",div},
	};
	for(i=0;i<4;i++)
	{
	//printf("%s",commands[i].cmd);
		if(strcasecmp(commands[i].cmd,commands.d[i])==0)
			printf("%d",commands[i],(*p[i])(a,b));
	}
}
