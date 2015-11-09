#include<stdio.h>
struct cmd
{
	char cmd[10];
	int (*p)(int,int);
	//char tcmd[10];
};
main()
{
int a,b,i,add,sub,div,mul;
char tcmd[10];
	struct cmd commands[4]={{"add",add},
		{"sub",sub},
		{"mul",mul},
		{"div",div},
	};
	for(i=0;i<4;i++)
	{
	printf("%s",commands[i].cmd);
		if(strcasecmp(commands[i].cmd,tcmd)==0)
			printf("%d",commands[i].p(a,b));
	}
}
