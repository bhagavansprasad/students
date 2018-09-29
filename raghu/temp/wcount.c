#include <stdio.h>
struct data_strings
{
	char string[100];
	int exp_res;
};
struct data_strings data[10] = {
{"welcome to aura networks",4},
{"welcome",1},
{" we l come",3},
{"hi   i   am",3},
{"    hiiiiiiiiiii     how  ",2},
{" ",0},
{"raghu",1},
{"               ",0},
{"near      btm",2},
{"h    e g h",4}
};
main()
{c
	int wc=0;
	int i=0;
	for(i=0;i<=9;i++)
	{
		wc=get_wcount(data[i].string);
		printf("->%d.wcount=%d==%d/%s\n",i+1,data[i].exp_res,wc,data[i].string);
	}
	return 0;
}

int get_wcount(char * s)
{
	int i,w=0;
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]!=' ')&&((s[i+1]==' ')||(s[i+1]=='\0')||(s[i+1]=='\n')))
		w++;
	}
	return w;
}
