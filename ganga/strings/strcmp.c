#include<stdio.h>
#include<string.h>
void main()
{
	int flag;
	char buff1[100] = "AURA NET";
	char buff2[100] = "aura Net";

	flag= astrcmp(buff1, buff2);

	if(flag == 0)
		printf("same\n");

	else
		printf("not same\n");
}

int astrcmp(char *p1, char *p2)
{
	int flag = 0, i = 0, d = 0;

	for ( i = 0;  p1[i] != '\0' && p2[i] !='\0' ; i++ )
	{
		if(p1[i] >= p2[i])
		{
			d = p1[i] - p2[i];
			printf("d1 is:%d\n", d);
		}

		else if(p2[i] > p1[i])
		{		
			d = p2[i] - p1[i];
			printf("d2 is:%d\n", d);
		}

		if(d != 32  && d != '\0')
		{
			flag = 1;
			break;
		}
	}
	return (flag);
}

