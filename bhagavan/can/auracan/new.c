#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <poll.h>
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
#include "lib.h"

struct ifreq ifr;
int frame_len  = 8;
int mtu, maxdlen;
static struct canfd_frame frame;
struct sockaddr_can addr;
int nbytes = 0;
int sockfd = 0;

main()
{
	sockfd = socket(PF_CAN, SOCK_RAW, CAN_RAW);

	printf("socket :%d\n", sockfd);

	addr.can_family = AF_CAN;

	strcpy(ifr.ifr_name, "vcan0");

	ioctl(sockfd, SIOCGIFINDEX, &ifr);
	addr.can_ifindex = ifr.ifr_ifindex;

	bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	mtu = CAN_MTU;
	maxdlen = CAN_MAX_DLEN;

	frame.len = 8;
	frame.can_id = random();

	frame.can_id &= CAN_SFF_MASK;

	frame.can_id |= CAN_RTR_FLAG;

	*(unsigned long*)(&frame.data[0]) = random();
	*(unsigned long*)(&frame.data[4]) = random();

	printf("mtu :%d\n", mtu);
	nbytes = write(sockfd, &frame, mtu);
	printf("-->write retval :%d\n", nbytes);
}
