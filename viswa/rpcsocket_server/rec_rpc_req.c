#include <stdio.h>
#include "struct.h"
#include "second_struct.h"

int rpcs_fop( struct students *stud ,struct school *sch);


int rpc_recv_req(struct students *stud ,struct school *sch)
{
return rpcs_fop(stud , sch);

}

