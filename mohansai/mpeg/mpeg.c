#include "stdio.h"
#include <sys/types.h>
#include <sys/stat.h>  
#include <fcntl.h>
#include <stdlib.h>
#include "classes.h"

char Pdata[Pval];
main()
{
	int Pfs,Pcount;
	if((Pfs = open("traian.mpg",O_RDONLY,0))==-1)
	{	
		perror ("error in open a file ");
			exit(1);
	}
	
	Pcount = read(Pfs, Pdata, Pval);

	printf("count---> %d\n",Pcount);
	
	printf("data %s",Pdata);

}




