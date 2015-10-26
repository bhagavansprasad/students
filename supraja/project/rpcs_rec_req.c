#include"rpc1.h"
int rpcs_rec_req(struct rpcc *a)
{
int retval= rpcc_fop(a);
return retval;
}
