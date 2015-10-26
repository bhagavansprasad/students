#include<stdio.h>
#include<string.h>

										

int add(int x,int y);

int prod(int x,int y);

int sub(int x,int y);

int div(int x,int y);

int mod(int x,int y);

void parse_command(char *str,char *tcmd,char *val1,char *val2);

//float fmod(float x,float y);


main()
{
	int i,res;
	char str[10][100] = {

						"add 10 20",
						"Add 200 2",
						"prod 10 5",
						"div 100 5",
						"sub 234 34",
						"mod 234 10"

						};


	for(i=0; i < 6; i++)
	{
		printf("%d. %s\n", i+1, str[i]);
		res=evoluate_string(str[i]);
		printf("res :%d\n", res);

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
		int (*p)(int ,int );
	};

	struct cmds commands[10]={
	{"add",add},{"sub",sub},{"prod",prod},{"div",div},{"mod",mod}};

									

	parse_command(str, tcmd,val1,val2);

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

 void parse_command(char *str,char *tcmd,char *val1,char *val2)
{
	int i,j;

	for(i=0;str[i]!=' ' && str[i]!='\0';i++)
	{
		tcmd[i]=str[i];
	}

	tcmd[i]='\0';

	for(  ;str[i]==' ';i++);

	for(j=0;str[i]!=' ';i++,j++)
	{
		val1[j]=str[i];
	
	}
	val1[j]='\0';

	for(  ;str[i]==' ';i++);

	for(j=0;str[i]!='\0';i++,j++)
	{
		val2[j]=str[i];
	}

	val2[j]='\0';

	printf("tcmd:%s\tval1:%s\t val2:%s\n",tcmd,val1,val2);

}



int add(int x,int y)
{
	int z;
	z=x+y;
	return z;
}	


int prod(int x,int y)
{
	int z;
	z=x*y;
	return z;
}

int sub(int x,int y)
{
	int z;
	z=x-y;
	return z;
}

int div(int x,int y)
{
	int z;
	z=x/y;
	return z;
}

int mod(int x,int y)
{
	int z;
	z=x%y;
	return z;
}	









