#include<stdio.h>
#include<string.h>

int get_word_count(char *s)
{
	int i,count = 0;

	for(i = 0;i < strlen(s);i++)
	{
		
		if(s[i] == ' ')
		{
			count++;
		}
	}
	count = count + 1;

	return count;
}

int main()
{
	char s[] = "add 10 20";
	int t;
	t = get_word_count(s);
	printf("%d\n",t);

	return 0;
}
