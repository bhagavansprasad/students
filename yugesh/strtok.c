#include <stdio.h>
#include <string.h>
main()
{
	char str[]="...why?but;not?oh! , where when";
	char seps[]="?...!,;  ..\t";
	char *t;
	t=strtok(str, seps);
	while(t!=NULL)
	{
		printf("%s ",t);
		t=strtok(NULL, seps);
	}
	return 0;
}

