#include<stdio.h>
#include<string.h>
#include<fcntl.h>

char str[20][50] = {
	{"hai hoe are you"},
	{"i am from andhra"},
	{"in aura networking "},
	{"banglore boomanahallii"},
	{"         banglore         boomanahallii      "},
	{"banglore         boomanahallii      "},
	{"banglore boomanahallii      "},
	{"          "},
	{"I"},
	{" I "},
	{" 1 "},
	{" how   "},
	{" x"},
	{"x   "},
	{" "}
};

int get_word_count(char *p);

main()
{
	int i = 0, retval = 0;

	for (i = 0; i <= 14; i++)
	{
		retval = get_word_count(str[i]);
		printf("%d. %s, wcount :%d\n", (i+1), str[i], retval);
	}
}
