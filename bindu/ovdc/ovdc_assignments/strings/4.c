#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calculator(char *s[])
{
	int result;

	if(strcmp(s[1],"add") == 0)
	{
		result = atoi(s[2]) + atoi(s[3]);
	}
	else if(strcmp(s[1],"sub") == 0)
	{
		result = atoi(s[2]) - atoi(s[3]);
	}
	else if(strcmp(s[1],"mul") == 0)
	{
		result = atoi(s[2]) * atoi(s[3]);
	}
	else if(strcmp(s[1],"div") == 0)
	{
		result = atoi(s[2]) / atoi(s[3]);
	}

	return result;
}

int main(int argc,char *argv[])
{
	int result;
	
	/*if(strcmp(argv[1],"add") == 0)
	{
		result = atoi(argv[2]) + atoi(argv[3]);
	}
	else if(strcmp(argv[1],"sub") == 0)
	{
		result = atoi(argv[2]) - atoi(argv[3]);
	}
	else if(strcmp(argv[1],"mul") == 0)
	{
		result = atoi(argv[2]) * atoi(argv[3]);
	}
	else if(strcmp(argv[1],"div") == 0)
	{
		result = atoi(argv[2]) / atoi(argv[3]);
	}*/

	result = calculator(argv);

	printf("Result : %d\n",result);
	return 0;
}

