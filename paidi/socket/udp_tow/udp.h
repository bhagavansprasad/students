#ifndef _UDP_H
#define  _UDP_H

#include"sys/types.h"
#include"sys/socket.h"
#include"netinet/in.h"
#include"arpa/inet.h"
#include"stdio.h"
#include"stdlib.h"
#include"unistd.h"
#include"string.h"


typedef struct context_blk
{
	int fd;
	int port;
	int root;
	int fd1;
	int fd2;
}udp_contex_blk;

#endif
