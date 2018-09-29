#include <stdio.h>

struct cmds
{
	char cmd[100];
	int (*fp1)(int , int );
};
struct cmds c[4] = {
					{"add","addition"},
					{"dif","difference"},
					{"mul","multiplication"},
					{"div","division"}
					};
int addition(int a,int b)
{
	return (a+b);
}

int difference(int a, int b)
{
	return (a-b);
}

int multiplication(int a, int b)
{
	return (a*b);
}

int division(int a, int b)
{
	return (a/b);
}

int do_exce_cmd(char  *pcmd, int a, int b)
{
	int i,f;
	for(i=0;i<4;i++)
	{
		if(strcasecmp(pcmd,c[i].cmd)==0)
		{
			f=c[i].fp1(pcmd,a,b);
			printf("%d\n",f);
			return f;
		}
	}
}

main()
{
	int *ret;
	int *fp1;
	int (*fp1)(char ,int , int);
	int do_exce_cmd(char  *, int , int );
	fp1 = do_exce_cmd;
	ret = fp1("add",10,20);
	printf("--->ret = %ld\n",ret);
}
