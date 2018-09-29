#include "struct_req.h"
#include "struct_rply.h"
//void client_send_data(struct final *,struct S_final *);
void client_send_data(struct final *);
void rpcc_send_req(struct final *c_req,struct S_final *s_rply)
{
	client_send_data(c_req);
}
