#include<stdio.h>
main()
{
	printf("File:%s\n",__FILE__);
	printf("date:%s\n",__DATE__);
	printf("time:%s\n",__TIME__);
	printf("line:%d\n",__LINE__);
	printf("ANSI:%d\n",__STDC__);
}