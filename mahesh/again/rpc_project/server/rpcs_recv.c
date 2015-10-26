#include "struct_req.h"
#include "struct_rply.h"
void rpcs_fop(struct final *);
void rpcs_recv_req(struct final *c_req)
{
	rpcs_fop(c_req);
}
