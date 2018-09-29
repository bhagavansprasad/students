#include "stdio.h"
#include "arpc.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int rpcs_process_fop_request(fop_data_req *pcdata, fop_data_rep *psdata)
{
	printf("final operation:%d\n", pcdata->operation);

	switch(pcdata->operation)
	{
		case OPEN_REQUEST:
			psdata->sudata.sodata.fd = open(pcdata->data.odata.filename,pcdata->data.odata.mode,pcdata->data.odata.flags);
			if(psdata->sudata.sodata.fd == -1)
			{
				printf("----->file is not open");
			}
			printf("---->final path name is: %s\n",(pcdata->data.odata.filename));
			printf("-->%s. request is OPEN\n", __FUNCTION__);

			break;

#if 0
		case READ_REQUEST:
			server_data->sudata.srdata.retval =	read(client_data->data.rdata.fd,client_data->data.rdata.buff,client_data->data.rdata.len);
			client_data->data.rdata.buff[server_data->sudata.srdata.retval]='\0';
			printf("buff is ---->%s\n",client_data->data.rdata.buff);

			if(server_data->sudata.srdata.retval == -1)
			{
				printf("---->file reading is fail");
			}
			strcpy(server_data->sudata.srdata.buff,client_data->data.rdata.buff);
			printf("-->%s. request is READ\n", __FUNCTION__);
			return server_data->sudata.srdata.retval; 
			break;

		case WRITE_REQUEST:
			server_data->sudata.swdata.retval =	write(client_data->data.wdata.fd,client_data->data.wdata.buff,client_data->data.wdata.len);
			if(server_data->sudata.swdata.retval == -1)
			{
				printf("---->file warning is failed");
			}

			printf("-->%s. request is WRITE\n", __FUNCTION__);
			return server_data->sudata.swdata.retval;
			break;

		case LSEEK_REQUEST:
			server_data->sudata.sseekdata.offset = lseek(client_data->data.seekdata.fd,client_data->data.seekdata.offset,client_data->data.seekdata.whence);
			if(server_data->sudata.sseekdata.offset == -1)
			{
				printf("---->lseek is failed:");
			}

			printf("-->%s. request is LSEEK\n", __FUNCTION__);
			return server_data->sudata.sseekdata.offset;  
			break;

		case CLOSE_REQUEST:
			server_data->sudata.scdata.fd = close(client_data->data.cdata.fd);
			printf("server_data.sudat.scdata.fd=-->%s. request is CLOSE\n", __FUNCTION__);
			return server_data->sudata.scdata.fd;
			break;
#endif

		default:
			printf("-->%s. INVALID request type\n", __FUNCTION__);
			break;

	}

	return server_data->sudata.sodata.fd;
}


