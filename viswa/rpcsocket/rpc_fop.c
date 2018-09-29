//#include "prototypes.h"
#include "struct.h"
#include "second_struct.h"
int send_data(struct students * , 	struct school *);

int rpc_fop(struct students *student)
{
	struct school sch;
	return send_data( student, &sch);
}
