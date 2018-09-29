#include "struct.h"
#include <stdio.h>
int  receive_data(struct students *student,struct school *sch)
{
	switch( student -> op)
	{
		case 1 : 
			sch -> fun.open.fd = open(student ->comb.open.file , student ->comb.open.mode , student ->comb.open.flag );
			return 	sch -> fun.open.fd ;

		case 2 :
			sch -> fun.read.fd = read( student -> comb.read.fd , student ->comb.read.buff ,	student->comb.read.len  );
			return  sch -> fun.open.fd ;

		case 3 :
			sch -> fun.write.fd = write(student -> comb.write.fd, student->comb.write.buff , student -> comb.write.len );
			return  	sch -> fun.write.fd;
		case 4 : 
			sch ->fun.close.fd = close ( student -> comb.close.fd );
			return  sch ->fun.close.fd ;
		default :
			printf("nothing shiuld match");
	}
	return 0;
}
