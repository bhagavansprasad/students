#include<stdio.h>
#include<string.h>

void main()
{
	int flag;
	char buff1[] = "AURA NET";
	char buff2[] = "ura Net";

	flag= astrcmp(buff1, buff2);

	if(flag == 0)
		printf("same\n");

	else

		printf("not same\n");
}

int astrcmp(char *p1, char *p2)
{
	int flag = 0, i = 0, d = 0, n = 7;

	for ( i = 0; i < n && *p1 != '\0' && *p2 !='\0' ; i++ )
	{

		if(*p1 >= *p2)
		{
			d = *p1 - *p2;
			printf("d1 is:%d\n", d);
		}

		else if(*p2 > *p1)
		{		
			d = p2[i] - p1[i];
			printf("d2 is:%d\n", d);
		}
		p1++, p2++;

		if(d = 32  && d != '\0')
		{
			flag = 1;
			break;
		}
	}
	return (flag);
}

