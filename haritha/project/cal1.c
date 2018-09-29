#include<stdio.h>
#include<string.h>

char strings[10][100] = {
	"add 10 20",
	"Add 200 2",
	"mul 30 3",
	"div 100 5",
	"sub 234 34",
	"mod 234 5"
};

int add(int x,int y);

int evoluate_string(char *str)
{
	char cmd[100];
	int res,val1 = 0, val2 = 0;

	parse_command(str, cmd);
	parse_arguments(str, &val1, val2);

//	if (strncasecmp(cmd, "add") == 0);
//	{
		res = add(val1, val2);
		print("res :%d\n", res);

		//else if (strncasecmp(cmd, "add") == 0);
//	}
}

main(int argc,char *argv[])
{
	int t,i;
	t = astr_atoi("234");
	for(i=0; i < 6; i++)
	{
		printf("%d. %s\n", i+1, strings[i]);
		evoluate_string(strings[i]);
	}
}
