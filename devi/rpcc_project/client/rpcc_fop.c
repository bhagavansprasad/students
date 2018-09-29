#include "structure.h"
int client_write_to_server(fop_data_req *creq);

int rpcc_fop(fop_data_req *creq)
{
	int wetval = 0;

	wetval =client_write_to_server(creq);

	return wetval;
}
