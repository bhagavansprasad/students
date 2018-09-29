/*
   C ECHO client example using sockets
 */
#include <stdio.h> //printf
#include <string.h>    //strlen
#include "define.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "aura_openc.h"

int main(int argc , char *argv[])
{
	int rfd,wfd,read_retval,write_retval,pos;
	//int rfd,wfd,read_retval;
	char buf[1024];

	init_communication_channel(SRVR_IPADDR, SRVR_PORT);	

	rfd = aura_openc("2.txt", O_RDONLY);
	printf("-->Client: read  fd:%d\n", rfd);
/*
	wfd = aura_openc("1.txt", O_WRONLY);
	printf("-->C: write fd:%d\n", wfd);

	read_retval = aura_readc(rfd, buf, 10);
	printf("--->read retval:%d\n",read_retval);
	buf[read_retval]='\0';
	write_retval = aura_writec(wfd, buf, read_retval);

	pos = aura_lseekc(rfd, -20, SEEK_END);
	pos = aura_lseekc(rfd, pos, SEEK_SET);

	read_retval = aura_readc(rfd, buf, 20);
	buf[read_retval]='\0';

	write_retval = aura_writec(wfd, buf, read_retval);

	aura_closec(rfd);
	aura_closec(wfd);
//close(sock); 
*/
	
	return 0;
}




