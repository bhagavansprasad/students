//#include"rpcc_send_data.h"
#include"struct_req.h"
#include"struct_replay.h"

int rpcs_fop(struct S_final *preply, struct final *c_req);

int rpcs_rec_req(struct final *c_req)
{
	struct S_final reply;
	int retval;
	rpcs_fop(&reply, c_req);

	//	printf("-->fd :%d\n", reply.s_uni.s_open.fd);

	retval = server_write_data(&reply);

	//	printf("-->S. writing reply retval :%d\n", retval);
}
