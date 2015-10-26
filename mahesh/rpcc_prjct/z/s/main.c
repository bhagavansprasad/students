#include "struct.h"
#include <stdio.h>
int tcp_server_init();
int server_read_req(struct fds *);
int server_read_data(struct fds *);

int main()
{
	struct fds data;
	printf("In Main\n");
	printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	tcp_server_init();
	while(1)
	{
	
		printf("________start_______________\n");
	
		printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
		
		server_read_req(&data);

		dump_data_after_read(&data);

		printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);

		server_read_data(&data);
		if(data.type>4)
		break;
	}

	
}

