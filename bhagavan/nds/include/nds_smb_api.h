#ifndef __NDS_SMB_API_H__
#define __NDS_SMB_API_H__
#include "mydefs.h"

int nds_smb_open(char *str, int mode);
int nds_smb_read(int fd, char *pbuff, int rlen);
int nds_smb_close(int fd);
int nds_smb_write(int fd, char *pbuff, int rlen);

#define OPEN_REQUEST 1
#define OPEN_REPLY  2
#define READ_REQUEST 3
#define READ_REPLY  4
#define WRITE_REQUEST 5
#define WRITE_REPLY  6
#define LSEEK_REQUEST 7
#define LSEEK_REPLY  8
#define CLOSE_REQUEST 9
#define CLOSE_REPLY  10

typedef struct client_request_t
{
	int cmd;
	char file_name[MAX_FILE_NAME_LEN];
	char file_path[MAX_FILE_NAME_LEN];
	int mode;
	int offset;
	int whence;
	int len;
	int ret_errno;
	int retval;
}client_request;

typedef struct server_reply_t
{
	int offset;
	int retval;
	int len;
	char buffer[1024];
}server_reply;

#if 0
typedef struct file_state_t
{
	int fd;
	char file_name[MAX_FILE_NAME_LEN];
	char file_path[MAX_FILE_NAME_LEN];
	int mode;
	int is_locked;
	int offset;
	//int retval;
	struct file_state_t *next;
	struct file_state_t *prev;
}file_state;
#endif

typedef union smb_data_t
{
	client_request request;
	server_reply   reply;
}smb_data;

typedef struct rpc_packet_t
{
	int command;
	smb_data data;
}rpc_packet;
#endif

