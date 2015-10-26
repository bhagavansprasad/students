#include <stdio.h>
struct data_string
{
	char string[100];
	int exp;
};
struct data_string data[5]={
{"hi how are",3},
{"hello",1},
{"what are you doing",4},
{"how old are you",4},
{"what else",2},
};
main()
{
	int i=0;
	for(i=0;i<5;i++)
	printf("string add:%u\n exp add:  %u\n",&data[i].string,&data[i].exp);
}
