#include <stdio.h>
#include <string.h>

int add(int x, int y);
int mul(int x, int y);
int sub(int x, int y);
int div(int x, int y);
int mod(int x, int y);
void parse_command(char *s, char *tcmd, char *val1, char *val2);

main ()
{
	int i, res;
	char s[100][100] = {
		               "add 10 20",
					   "mul 10 200",
		               "sub 200 100",
		               "div 200 150",
		               "mod 200 5"
                       };

	for (i=0; i<5; i++)
	{
		printf ("%d. %s\n",i+1, s[i]);
		res = evoluate_string(s[i]);
		printf ("%d",res);
	}
}

int evoluate_string(char *str)
{
	char tcmd[100];
	char val1[100], val2[100];
	int a,b,i,res;

	struct cmds
	{
		char cmd[10];
		int (*p)(int ,int);
	};

	struct cmds commands[10]={
		{"add",add},{"mul",mul},{"sub",sub},{"div",div},{"mod",mod}};



	parse_command(str,tcmd,val1,val2);

	a=atoi(val1);
	b=atoi(val2);

	printf("a:%d\t b:%d\n",a,b);

	for(i=0;i<=4;i++)
	{
		if (strcasecmp(commands[i].cmd,tcmd) == 0)
		{
			res=commands[i].p(a,b);
			return res;
		}
	}
}

void parse_command(char *s, char *tcmd, char *val1, char *val2)
{
	int i, j;
	for (i=0; s[i]!=' ' && s[i]!='\0'; i++)
	{
		tcmd[i] = s[i];
	}
	tcmd[i] = '\0';

	for (  ; s[i] == ' '; i++);

	for (j=0; s[i]!=' '; i++, j++)
	{
		val1[j] = s[i];
	}
	val1[j] = '\0';

	for (  ;s[i] == ' '; i++);

	for (j=0; s[i]!=' '; i++,j++)
	{
		val2[j] = s[i];
	}
	val2[j] = '\0';

	printf ("tcmd : %s\t val1 : %s\t val2 : %s\n", tcmd, val1, val2);
}

int add (int x,int y)
{
	int z;
	z = x+y;
	return z;
}

int mul (int x, int y)
{
	int z;
	z = x*y;
	return z;
}

int sub (int x, int y)
{
	int z;
	z = x-y;
	return z;
}

int div (int x, int y)
{
	int z;
	z = x/y;
	return z;
}

int mod (int x, int y)
{
	int z;
	z = x%y;
	return z;
}


