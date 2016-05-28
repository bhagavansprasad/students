#include<stdio.h>

struct strings
{
	char str[100];
};

struct strings  test_data[10] = {

	"hai this is hema",
	"      this   is hema",
	"  is          hema",
	"                hema",
	"                             ",
	" aura net a b c    ",
	"  a   ",
	"  a   ",
	"  a    b  "
};

main()
{
	int i, wcount=0;

	for(i=0; i < sizeof(test_data)/sizeof(test_data[0]); i++)
	{
		wcount = get_wcount(test_data[i].str);
		printf("%d.count %d - %s\n", i+1, wcount, test_data[i].str);
	}
}

int get_wcount(char *p)
{
	int i,wcount=0;

	for(i=0;p[i]!='\0';i++)
	{
		while(p[i]==' ')
			i++;

		if(p[i]!=' '&&p[i]!='\0')
			wcount++;

		while(p[i]!=' '  && p[i]!='\0' )
			i++;
	}

	return wcount;
}
