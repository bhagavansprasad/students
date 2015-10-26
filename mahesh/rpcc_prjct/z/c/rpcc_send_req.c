#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "struct.h"
#include "string.h"

int client_send_data(struct fds *a_fds);

int rpcc_send_req(struct fds *a_fds)
{
	
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("Client type: %d\n",a_fds->type);
	return client_send_data(a_fds);
}

