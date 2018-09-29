#include "stdio.h"
#include<string.h>
char buffs[10][100] =  {
	{"  how                   rrrrrrrrrrrrrr  u"},
	{"how rrrrrrrr uu"},
	{"how rrrrrrrr uu"},
	{" "},
	{"dsfksjd kjkdsf kdshkk "}, 
	{"a"},
	{"a b c d e f"},
	{"a b c d e f"},
	{"a b c d e f"},
	{"a b c d e f"}
};

main()
{
	int wc = 0, i = 0;

	for ( i = 0; i < 10; i++)
	{
		wc = get_word_count(buffs[i]);
		printf("wc :%d, for buff :%s\n", wc, buffs[i]);
	}

}

int get_word_count(const char *s)
{
	int i=0,wc;
	if(s[i]==' ')
		wc=0;
	else
		wc=1;

	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] == ' ' && s[i+1] != ' ' && s[i+1] != '\0')
			wc++;
	}
	return wc;
}


