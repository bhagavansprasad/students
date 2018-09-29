#include"struct_req.h"
#include"struct_rply.h"
void rpcs_recv_req(struct final *,struct S_final *);
void rpcs_send_req(struct final *c_req,struct S_final *s_rply)
{
	rpcs_recv_req(c_req,s_rply);
}
