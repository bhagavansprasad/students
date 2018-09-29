#include <stdio.h>
int get_wordcount(char *);
int main()
{
	char p[] = "          a    4 aura net     works123  254       bangalore i 4 india       ";
	int count = 0;
	
	count = get_wordcount(" h ");

	printf("-->Word count : %d\n", count);

	return 0;
}
