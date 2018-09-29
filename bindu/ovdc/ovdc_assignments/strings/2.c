#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int calculator(char *s)
{
	int i,j,k;
	int count = 0;
	char operator[4],operand1[4],operand2[4];

	for(i = 0;i < strlen(s);i++)
	{
		if(s[i] != ' ')
		{
			operator[i] = s[i];
		}
		
		if(s[i] == ' ')
		{
			operator[i+1]='\0';
			
			for(j = i + 1;s[j] != ' ';j++)
			{
				operand1[count] = s[j];
				count = count + 1;
			}
			
			if(s[j] == ' ')
			{
				operand1[count+1]='\0';
				count = 0;
				for(k = j +1;k <= strlen(s);k++)
				{
					operand2[count] = s[k];
					count++;
				}
				operand2[count+1]='\0';
				break;
			}
		}
	}

	int a = atoi(operand1);
	int b = atoi(operand2);
	int c;
	
	if(strcmp(operator,"add") == 0)

	{
		c = a + b;
	}
	else if(strcmp(operator,"sub") == 0)
	{
		c = a - b;
	}
	else if(strcmp(operator,"mul") == 0)
	{
		c = a * b;
	}
	else if(strcmp(operator,"div") == 0)
	{
		c = a / b;
	}
	
	return c;
	
}
int main()
{

	char s[] = "mul 50 40";
	int result;
	
	result = calculator(s);
	printf("%d\n",result);
	return 0;
}
