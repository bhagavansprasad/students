#include <stdio.h>
#include <fcntl.h>
#include"define.h"

int aura_fop_cmd_dispatcher(fop_data *pdata)
{
	int retval;
	switch(pdata->cmd)
	{
		case FILE_OPEN:
			retval = aopen(pdata->udata.opn.fname, pdata->udata.opn.mode);

			pdata->udata.opn.fd = retval;

			return retval;
			break;

		case FILE_READ:
			retval = aread( pdata->udata.rdwt.fd, pdata->udata.rdwt.buffer, pdata->udata.rdwt.count);

			pdata->udata.rdwt.count = retval;
			
			return retval;
			break;

		case FILE_WRITE:
			retval = awrite( pdata->udata.rdwt.fd, pdata->udata.rdwt.buffer, pdata->udata.rdwt.count);
			
			pdata->udata.rdwt.count = retval;
			
			return retval;
				break;

		case FILE_SEEK:
			retval = alseek(pdata->udata.seek.fd, pdata->udata.seek.offset, pdata->udata.seek.whence);
			
			pdata->udata.seek.offset=retval;
			
			return retval;
			break;

		case FILE_CLOSE:
			aclose(pdata->udata.cls.fd);
			break;

		default:
			printf("-->%s, %s, %d ***PANIC*** Received Invalid command :%d\n", __FILE__, __FUNCTION__, __LINE__, pdata->cmd);
			exit(1);
	}
}
