#include<stdio.h>
#include<string.h> 

char b1[100]="Hello   how  are  you.  am";
char b2[100]= " hello every one";

void main()
{
	int wc = 0, i = 0;
	wc = get_word_count(b1);
	printf("wc :%d, for buff :%s\n", wc, b1);

	wc = get_word_count(b2);
	printf("wc :%d, for buff :%s\n", wc, b2);
}

int get_word_count(const char *s)
{
	int i = 0, wc;
	if(s[i] == ' ')
		wc=0;
	else
		wc=1;

	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]==' ' && s[i+1]!=' ' && s[i+1]!='\0')
			wc++;
	}

	return wc;
}

