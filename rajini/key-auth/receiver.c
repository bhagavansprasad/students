#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <ctype.h>
#include <libgen.h>
#include <time.h>
#include <errno.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/uio.h>
#include <net/if.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include "terminal.h"
#include "lib.h"

#define MAXSOCK 16    /* max. number of CAN interfaces given on the cmdline */
#define MAXIFNAMES 30 /* size of receive name index to omit ioctls */
#define MAXCOL 6      /* number of different colors for colorized output */
#define ANYDEV "any"  /* name of interface to receive from any CAN interface */
#define ANL "\r\n"    /* newline in ASC mode */

#define SILENT_INI 42 /* detect user setting on commandline */
#define SILENT_OFF 0  /* no silent mode */
#define SILENT_ANI 1  /* silent mode with animation */
#define SILENT_ON  2  /* silent mode (completely silent) */

#define BOLD    ATTBOLD
#define RED     ATTBOLD FGRED
#define GREEN   ATTBOLD FGGREEN
#define YELLOW  ATTBOLD FGYELLOW
#define BLUE    ATTBOLD FGBLUE
#define MAGENTA ATTBOLD FGMAGENTA
#define CYAN    ATTBOLD FGCYAN

const char col_on [MAXCOL][19] = {BLUE, RED, GREEN, BOLD, MAGENTA, CYAN};
const char col_off [] = ATTRESET;

static char devname[MAXIFNAMES][IFNAMSIZ+1];
static int  dindex[MAXIFNAMES];
static int  max_devname_len; /* to prevent frazzled device name output */ 
const int canfd_on = 1;
#define MAXANI 4
const char anichar[MAXANI] = {'|', '/', '-', '\\'};
const char extra_m_info[4][4] = {"- -", "B -", "- E", "B E"};
extern int optind, opterr, optopt;
static volatile int running = 1;
void sigterm(int signo)
{
	running = 0;
}

int idx2dindex(int ifidx, int socket) 
{
	int i;
	struct ifreq ifr;

	for (i=0; i < MAXIFNAMES; i++) 
	{
		if (dindex[i] == ifidx)
			return i;
	}

	for (i=0; i < MAXIFNAMES; i++) 
	{
		if (dindex[i]) 
		{
			ifr.ifr_ifindex = dindex[i];
			if (ioctl(socket, SIOCGIFNAME, &ifr) < 0)
				dindex[i] = 0;
		}
	}

	for (i=0; i < MAXIFNAMES; i++)
	{
		if (!dindex[i]) /* free entry */
			break;
	}
	if (i == MAXIFNAMES) 
	{
		fprintf(stderr, "Interface index cache only supports %d interfaces.\n",
				MAXIFNAMES);
		exit(1);
	}

	return 0;
}
int main(int argc, char **argv)
{
	int s = -1;
	unsigned char color = 0;
	unsigned char view = 0;
	struct sockaddr_can addr;
	char ctrlmsg[CMSG_SPACE(sizeof(struct timeval)) + CMSG_SPACE(sizeof(__u32))];
	struct iovec iov;
	struct msghdr msg;
	struct canfd_frame frame;
	int nbytes;
	struct ifreq ifr;

	s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
	addr.can_family = AF_CAN;
	memset(&ifr.ifr_name, 0, sizeof(ifr.ifr_name));
	strncpy(ifr.ifr_name, "vcan0", 5);

	addr.can_ifindex = ifr.ifr_ifindex;
	setsockopt(s, SOL_CAN_RAW, CAN_RAW_FD_FRAMES, &canfd_on, sizeof(canfd_on));

	if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) 
	{
		perror("bind");
		return 1;
	}
	/* these settings are static and can be held out of the hot path */
	iov.iov_base = &frame;
	msg.msg_name = &addr;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	msg.msg_control = &ctrlmsg;

	while(1)
	{
		int idx = 0;
		iov.iov_len = sizeof(frame);
		msg.msg_namelen = sizeof(addr);
		msg.msg_controllen = sizeof(ctrlmsg);  
		msg.msg_flags = 0;
		nbytes = recvmsg(s, &msg, 0);

		printf("nbytes :%d-->", nbytes);
  
		if (frame.can_id & CAN_EFF_FLAG)
			view |= CANLIB_VIEW_INDENT_SFF;

		fprint_long_canframe(stdout, &frame, NULL, view, nbytes);

		printf("\n");
   } 
	return 0;
}
