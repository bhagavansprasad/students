#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFLEN 512
#define PORT 53
#define SRV_IP "192.168.1.1"

void err(char *);
unsigned short int IDfier = 0x1234;
unsigned short int flags = 0;

#define DNS_TYPE_QUERY 0
#define DNS_TYPE_RESPONSE 1

#define DNS_TYPE_OPCODE 0

/*Set 0th bit*/
int set_bit_qr_value(unsigned char * pflag, int type)
{
	/* Position is Zero*/
	if(type == 0)
	 * pflag = * pflag & type;

}

/*Set 1-4 rd bit*/
set_bit_opcode_value(unsigned char *flag, int type) //&flags[0], DNS_TYPE_OPCODE)
{


}
/*Set 5th bit*/
set_bit_AA_value(unsigned char *flag, int val)   //&flags[0], 0)
{

/*Set 6th bit*/
set_bit_recursive_value(unsigned char *flag,int val )  //&flags[0], 1)
{
}
/*Set 7th bit*/
set_bit_reserved_value(unsigned char *flag, int val)  //&flags[0], 0)
{
}

char build_dnsc_query(char *query, char *dname)
{
	char *ptr = query;
	unsigned char flags[2] = {0};

	ptr += sprintf(ptr, "%x", IDfier);

	set_bit_qr_value(&flags[0], DNS_TYPE_QUERY);
	set_bit_opcode_value(&flags[0], DNS_TYPE_OPCODE);
	set_bit_AA_value(&flags[0], 0);
	set_bit_recursive_value(&flags[0], 1);
	set_bit_reserved_value(&flags[0], 0);
	flags[1] = 0;

	ptr += sprintf(ptr, "%d", (unsigned short int *)flags);
	ptr += sprintf(ptr, "%d", (unsigned short int)1);
	ptr += sprintf(ptr, "%d", (unsigned short int)0);
	ptr += sprintf(ptr, "%d", (unsigned short int)0);
	ptr += sprintf(ptr, "%d", (unsigned short int)0);

	ptr += sprintf(ptr, "%s", dname);

	ptr += sprintf(ptr, "%d", (unsigned short int)1);
	ptr += sprintf(ptr, "%d", (unsigned short int)1);
}



int main(int argc, char** argv)
{
	struct sockaddr_in serv_addr;
	int sockfd, i, slen=sizeof(serv_addr);
	char query[20]="";
	char buf[100];
	char dname[20]="yahoo.com";
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
		err("socket failed");

	printf("-->sockfd :%d\n", sockfd);
	printf("%d\n", __LINE__);

	bzero(&serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	printf("%d\n", __LINE__);

	if (inet_aton(SRV_IP , &serv_addr.sin_addr)==0)
	{
		fprintf(stderr, "inet_aton() failed\n");
		exit(1);
	}

	printf("%d\n", __LINE__);

	buf=build_dnsc_query(query,dname);

	if (sendto(sockfd, buf, 6, 0, (struct sockaddr*)&serv_addr, slen)==-1)
		perror("sendto()");

	printf("%d\n", __LINE__);


	close(sockfd);
	return 0;
}
void err(char *s)
{
	perror(s);
	exit(1);
}

