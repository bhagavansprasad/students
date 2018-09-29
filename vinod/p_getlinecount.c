#include "stdio.h"
int get_linecount(char *);
int main()
{
	char a[]=" #52/1 aura     \nnetworks bommanahalli\nindia  \n  bangalore";
	int c=get_linecount(a);
	printf("%s\n",a);
	printf("Line count : %d\n",c);
return 0;
}
