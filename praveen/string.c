#include <stdio.h>
#include <string.h>
struct data_string
{
	char string[100];
	int exp;
};
struct data_string data[5]={
{"Hi how are",3},
{" ",0},
{"Whatareyoudoing",4},
{"How     old are you   ",4},
{"   What else",2},
};
main()
{
	int i;
	//char s[100]="  aura networks bomanahalli";
//	char d[100]=" ";
	for(i=0;i<6;i++)
	{
	astr_toggle(data[i].string);
	printf("%s\n",data[i].string);
	}
}
