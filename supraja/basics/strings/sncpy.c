#include "stdio.h"

struct mystrings_t
{
	char s1[100];
	char s2[100];
	int size;
};

struct mystrings_t strings[] = {
	{"Aura Networks","",5},
	{"Bangalore","",6},
	{"Kadapa","",3},
	{"K","",2},
	{"k","",5},
	{"K","",4},
	{"BANGLORE","",3},
	{"hai","",3},
	{"ha","",2},
	{"aura networks","",2},
	{"aura networks","",3},
};
char *astrncpy(char *d,char *s,int size)
{
	int j;
	for(j=0;s[j]!='\0'&&j<size;j++)
	{
		d[j]=s[j];
	}
	d[j]='\0';
	return (d);
}
main()
{
	int i,j;
	for(i=0;i<sizeof(strings)/sizeof(struct mystrings_t);i++)
	{
		astrncpy(strings[i].s2,strings[i].s1,strings[i].size);
		printf("%s\n",strings[i].s2);
	}
}	
