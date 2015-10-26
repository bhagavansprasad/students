#include "afun3.h"
#include "struct.h"
int rpc_fop(struct students *student)
{
	struct school sch;
	return send_data( student, &sch);
}

