#include "stuct.h"
#include <stdio.h>
int rpc_fop(struct student *stud)
{
	printf("op=%d",stud->op);
	switch (stud -> op)
	{
		case 1 : return open( stud->fin.ope.file ,stud->fin.ope.flag ,stud->fin.ope.mode);

		case 3 : return write( stud->fin.wri.fd ,  stud->fin.wri.buff ,  stud->fin.wri.len);

		case 2 : return read(stud->fin.rea.fd ,stud->fin.rea.buff ,stud->fin.rea.len );
	
		case 4 : return close(stud->fin.clo.fd );
		
		default : printf("no case is match here:");
				  break;
	}

}
