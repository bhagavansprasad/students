#include"stdio.h"
#include"rfuns.h"
#include"stdlib.h"
struct data
{
	char str[100];
	int nop;
};
struct data d[4]={{"121  121  madam",2},
	{"hah hello hai",1},
	{"ram mam ",1},
	{"131 chc ",2}};
int get_nof_pal(char *s)
{
	int i=0,count=0,m;
	char s1[20];
	for(i;s[i]!='\0';i++)
	{
		while(s[i]==' ')
		{
			i++;
		}
		for(i;s[i]!=' '&&s[i]!='\0';i++)
		{
			s1[i]=s[i];
		}
		s1[i]='\0';
		m=palin(s1);

printf("m =%d \n ",m);
                if(m==0){
			count++;
printf("count =%d \n ",count);
	}

}
	return count;

}
main()
{
	int i;
	for(i=0;i<=10;i++)
	{
		if(get_nof_pal(d[i].str)!=d[i].nop)
		{
			printf("MY PROGRAM IS WRONG");
			exit(1);
		}
		else  	if(get_nof_pal(d[i].str)==d[i].nop)

			printf("My program is correct");
	}
}

