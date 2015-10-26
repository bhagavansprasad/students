#ifndef __SYS_FOP_H__
#define __SYS_FOP_H__
#include "nds_smb_api.h"

int sys_open(client_request *creq, client_request *reply);
int sys_read(client_request *creq, char *out_buff);
//int sys_write(int fd, char *rbuff, int len);
//int sys_close(int fd);

#endif
