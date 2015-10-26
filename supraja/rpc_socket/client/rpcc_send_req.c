#include"struct_req.h"
#include"struct_replay.h"
#include<stdio.h>

int client_send_data(struct final *);

int rpcc_send_req(struct final *c_req)
{
	printf("%d %s \n ",__LINE__,__FILE__);

	return client_send_data(c_req);
}
int rpcc_read_req(struct final *prply)
{
	int retval = -1;
	printf("%d %s \n ",__LINE__,__FILE__);

	retval = client_read_reply(prply);
	printf("-->C. read socket retval :%d\n", retval);
}
