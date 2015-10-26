#include <stdio.h>
#include <string.h>

int astrcmp(char *p1, char *p2);

main()
{
	int t;
	char str[20] = "balachandra";
	char str1[20] = "balachadra";
	t = astrcmp(str1, str);
	if(t == 0)
	{
		printf("strings are equal\n");
	}
	else
	{
		printf("strings are not equal\n");
	}
}
int astrcmp(char *p1, char *p2)
{
	int flag=0,i,d;
	for(i=0;p1[i]!='\0'&&p2[i]!='\0';i++)
	{
	if(p1[i]>=p2[i])
	
		d=p1[i]-p2[i];
	else if(p2[i]>p1[i])
		d=p2[i]-p1[i];

		if(d!=32&&d!=0)
		{
			flag=1;
			break;
		}
	}
	return (flag);
}

