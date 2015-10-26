#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include "server_client.h"
void server_comm();
	struct fop_data_t;
//int server_read(struct fop_data_t *fop_data);
main()
{
	server_comm();
	/*while(1)
	{
		server_read(&fop_data);
	}*/

}
