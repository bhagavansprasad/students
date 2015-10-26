#include<stdio.h>
#include<fcntl.h>
int main()
{
	int wc=0;
	char buff[100]=" k. s r a v a n i s r i n u r e d d y ";
	wc=get_word_count(buff);
	printf("%d\n",wc);
}
int get_word_count(char *sp)
{
	int i, wc = 0;

	for (i = 0; sp[i] == ' '; i++);

	for( ; sp[i]!='\0'; i++)
	{
		if(sp[i] == ' ')
		{
			if(sp[i-1] != ' ')
			{
				wc++;
			}
		}
	}

	if (sp[i] == '\0' && sp[i-1] != ' ')
		wc++;

	return wc;
}

