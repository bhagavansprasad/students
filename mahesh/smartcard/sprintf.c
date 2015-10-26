#include <stdio.h>
main()
{
	char str[200];
	int i = 10;
	float d = 10.3;
	sprintf(str,"%d : %s :  %f",i,"hellow",d);
	printf("%s\n",str);
}
