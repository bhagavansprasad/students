#include"structrep.h"
#include"struct.h"
int dump_data_after_read(struct fds *data)
{
	printf("##>type :%d\n", data->type);

	printf("##>%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	switch (data->type)
	{
		case 1:
			printf("##>%s, %d, %d\n", data->a_uns.a_open_d1.pathname,
								data->a_uns.a_open_d1.flags,
								data->a_uns.a_open_d1.mode);
			break;

		case 2:
			printf("##>%d, %d", data->a_uns.a_read_d2.fd,
							data->a_uns.a_read_d2.count);
				break;
		case 3:
			//printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			printf("##>%d  %s  %d",data->a_uns.a_write_d3.fd,
					data->a_uns.a_write_d3.buff,data->a_uns.a_write_d3.count);

			//printf("-->fd_write :%d\n", fdw);
			//return fdw;
			break;

		case 4:
			//printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			printf("##>%d",data->a_uns.a_close_d4.fd);

			//printf("-->fd_close :%d\n", fdc);
			//return fdc;
			break;
		default:
			//printf("##>%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			printf("##>Invalid MODE\n");
	}
	return 0;
}
int sdump_data_before_write(struct server *data)
{

	printf("##>%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	printf("##>type :%d\n", data->type);

	switch (data->type)
	{
		case 1:
			printf("##> %d\n", data->a_uns.o.fd);
			printf("##>errno:%d\n", data->a_uns.o.erno);
			break;

		case 2:
			printf("##>%d,%s",data->a_uns.r.rval,data->a_uns.r.buff);
			printf("##>errno:%d\n", data->a_uns.r.erno);	
			break;

		case 3:
			//printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
		    printf("##> %d\n", data->a_uns.w.rval);
			printf("##>errno:%d\n", data->a_uns.w.erno);

			//printf("-->fd_write :%d\n", fdw);
			//return fdw;
			break;

		case 4:
			//printf("-->%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
	     	printf("##> %d\n", data->a_uns.c.rval);
			printf("##>errno:%d\n", data->a_uns.c.erno);	

			//printf("-->fd_close :%d\n", fdc);
			//return fdc;
			break;
		default:
			//printf("##>%d. %s. %s\n", __LINE__, __FUNCTION__, __FILE__);
			printf("##>Invalid MODE\n");
	}
	return 0;
}


