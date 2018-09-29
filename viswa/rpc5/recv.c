#include <stdio.h>
#include "struct.h"
#include "struct_reply.h"

int recv_request( struct student *stud , struct reply_final *rep )
{
	switch (stud -> op)
	{
		case 1 : rep->rey.r_ope.fd = open( stud->fin.ope.file , stud->fin.ope.mode ,stud->fin.ope.flag);
				 printf("rep->rey.r_ope.fd :%d\n",rep->rey.r_ope.fd);
				 return rep->rey.r_ope.fd;

		case 2 :   rep->rey.r_rea.fd = read(stud->fin.rea.fd ,stud->fin.rea.buff ,stud->fin.rea.len );
				   printf("\n");

				   printf(" rep->rey.r_rea.fd  :%d\n", rep->rey.r_rea.fd );
				   stud->fin.rea.buff[ rep->rey.r_rea.fd ]='\0';;
				   printf("buff:->%s\n",stud->fin.rea.buff);
				   return rep->rey.r_rea.fd;

		case 3 :  rep->rey.r_wri.fd = write( stud->fin.wri.fd ,  stud->fin.wri.buff ,  stud->fin.wri.len);
				  printf("\n");

				  printf("rep->rey.r_wri.fd :%d\n ", rep->rey.r_wri.fd );
				  printf("final buffer is  :%s\n ", stud->fin.wri.buff);
				  return rep->rey.r_wri.fd;

		case 4 :  rep->rey.r_clo.fd = close(stud->fin.clo.fd );
				  printf("\n");

				  printf("rep->rey.r_clo.fd :%d\n ", rep->rey.r_clo.fd );
				  return rep->rey.r_clo.fd ;

		default : printf("no case is match here:");
				  break;

	}
}



