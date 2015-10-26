#include "stdio.h"
main()
{
	int p[2];
	pipe(p);	

	if(fork() == 0)
	{
		//Parent OVD
		close(p[0]);
		ovd(p[1]);
	}
	else
	{
		//Child OVC
		close(p[1]);
		ovc(p[0]);
	}
}

