#include "stdio.h"

char strings[10][100] = {
	"add 10 20",
	"mul 345 20",
	"div 155 10",
	"mod 456 30",
	"sub 234 60"
	};

int parse_command_string(char *src, char *pcmd, int *pa, int *pb)
{
	printf("%s\n", src);


	...;
}

main()
{
	int i = 0, a = 0, b = 0;
	char cmd[10];


	for (i = 0; i < sizeof(strings)/ sizeof(strings[0]); i++)
	{
		//printf("%d. %s\n", i+1, strings[i]);

		parse_command_string(strings[i], cmd, &a, &b);
		printf("cmd :%s\n", cmd);
		printf("a   :%d\n", a);
		printf("b   :%d\n", b);
	}

}
