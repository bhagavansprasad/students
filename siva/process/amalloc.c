#include <stdio.h>
#include <stdlib.h>

void *amalloc(int);
int buff[1000],flag=0;
char *m,*f;
void *amalloc(int n)
{

	if(flag == 1)
	{
		printf("Memory is Not Allocated :\n");
		sleep(3);
	}
	else
	{
		flag=1;
		printf("Memnory is allocated Successfully :\n");
		return buff;
	}
}

void afree(char *m)
{
	flag=0;
	if(flag == 0)
	{
		printf("SUCCESSFULLY DEALLOCATED :\n");
	}
	else
	{
		printf("NOT DEALLOCATED\n");
	}

}

main()
{
	m=(char *)amalloc(10);
	m=(char *)amalloc(10);
	afree(m);
	
	}
