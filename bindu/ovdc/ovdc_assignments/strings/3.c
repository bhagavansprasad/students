#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calculator(char *s)
{
	int i;
	char token[3][10];
	char temp[10];
	int index = 0,tkindex = 0;
	
	for(i = 0;i <= strlen(s);i++)
	{
		if(s[i] != ' ')
		{
			temp[index] = s[i];
			index++;

		}
		
		if(s[i] == ' '|| s[i] == '\0')
		{
			temp[index] = '\0';

			strcpy(token[tkindex],temp);
			tkindex++;
			index = 0;
			temp[0] = '\0';
		}
	}

	printf("token[0] : %s\n",token[0]);
	printf("token[1] : %s\n",token[1]);
	printf("token[2] : %s\n",token[2]);


	int a = atoi(token[1]);
	int b = atoi(token[2]);
	int c;
	printf("a : %d\n",a);
	printf("b : %d\n",b);
	
	if(strcmp(token[0],"add") == 0)
	{
		c = a + b;
	}
	else if(strcmp(token[0],"sub") == 0)
	{
		c = a - b;
	}
	else if(strcmp(token[0],"mul") == 0)
	{
		c = a * b;
	}
	else if(strcmp(token[0],"div") == 0)
	{
		c = a / b;
	}
	
	return c;
	
}
int main()
{

	char s[] = "add 50 40";
	int result;
	
	result = calculator(s);
	printf("%d\n",result);
	return 0;
}
