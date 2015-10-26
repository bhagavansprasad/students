#include </usr/include/pcap.h>
#include </usr/include/stdio.h>
#include </usr/include/time.h>
#include </usr/include/stdlib.h>
#include </usr/include/errno.h>
#define _USE_BSD
#define __FAVOR_BSD
#include </usr/include/memory.h>
#include </usr/include/netinet/ip.h>
#include </usr/include/netinet/tcp.h>
#include </usr/include/linux/udp.h>
#include </usr/include/dnet.h>

/* Offsets of fields in the DNS header. */
#define DNS_ID      0
#define DNS_FLAGS   2
#define DNS_QUEST   4
#define DNS_ANS     6
#define DNS_AUTH    8
#define DNS_ADD     10

/* Length of DNS header. */
#define DNS_HDRLEN  12

//Type field of Query and Answer
#define T_A 1 /* host address */
#define T_NS    2 /* authoritative server */
#define T_CNAME 5 /* canonical name */
#define T_SOA   6 /* start of authority zone */
#define T_PTR   12 /* domain name pointer */
#define T_MX    15 /* mail routing information */

/* I have to define the DNS header because I don't where the hell is!!!! */
//DNS header structure
struct DNS_HEADER
{
	unsigned short id; // identification number
	unsigned char rd :1; // recursion desired
	unsigned char tc :1; // truncated message
	unsigned char aa :1; // authoritive answer
	unsigned char opcode :4; // purpose of message
	unsigned char qr :1; // query/response flag

	unsigned char rcode :4; // response code
	unsigned char cd :1; // checking disabled
	unsigned char ad :1; // authenticated data
	unsigned char z :1; // its z! reserved
	unsigned char ra :1; // recursion available

	unsigned short q_count; // number of question entries
	unsigned short ans_count; // number of answer entries
	unsigned short auth_count; // number of authority entries
	unsigned short add_count; // number of resource entries
};

//Constant sized fields of query structure
struct QUESTION
{
	unsigned short qtype;
	unsigned short qclass;
};

//Constant sized fields of the resource record structure
struct R_DATA
{
	unsigned short type;
	unsigned short _class;
	unsigned int ttl;
	unsigned short data_len;
};

//Pointers to resource record contents
struct RES_RECORD
{
	unsigned char *name;
	struct R_DATA *resource;
	unsigned char *rdata;
};

//Structure of a Query
typedef struct
{
	unsigned char *name;
	struct QUESTION *ques;
} QUERY;



//Callback function, it will be called everytime a package is received
void my_callback(u_char *useless,const struct pcap_pkthdr* pkthdr,const u_char* packet)
{
	struct ether_header *eptr;
	struct tcphdr *tcphdr;
	struct udphdr *udphdr;
	struct DNS_HEADER *DNS_HEADER=&DNS_HEADER;
	struct QUESTION *QUESTION=&QUESTION;
	struct res_sym *res_sym;
	char TYPE;
	struct dns *dns;
	unsigned offset = 0;
	time_t t;
	struct tm *tstruct;
	t=time(NULL);
	tstruct=localtime(&t);
	char timer [80];
	strftime (timer,80,"%a %b %d %Y %T",tstruct);

	/* Buffer needed to store the DNS packet */

	struct RES_RECORD answers,auth,addit;
	struct QUERY name, ques;

	/* The pointer will point to the Ethernet header at the beggining of the packet */

	eptr = (struct ether_header *) packet;

	/* We extract the IP header, therefore we have to move the processed Ethernet header
	   in order to find the information we want */

	struct ip *ipc;

	offset += ETH_HDR_LEN;
	ipc = (struct ip *)(packet + offset);

	/* We check the TCP protocol, the value of "Protocol" in the IP frame is checked according to the
	   8 bit value */

	switch (ipc->ip_p)

	{
		case 1:
			printf ("ICMP\n");
			return; //ICMP protocol
		case 6:
			printf ("TCP\n");
			return; //TCP protocol
		case 17:
			printf ("UDP\n");
			break; //UDP Protocol
		default:
			printf ("Unknown\n");
			return; //Unknown protocol
	}

	//lenght of the ip header to be added to the ethernet header
	offset += (ipc->ip_hl)*4;
	udphdr = (struct udphdr *)(packet + offset);

	offset += UDP_HDR_LEN;

	/* pointing to the DNS */

	dns = (struct DNS_HEADER *)(packet + offset);

	offset += DNS_HDRLEN;

	/*Printing QR Code*/


	switch (DNS_HEADER->qr)
	{
		case 0:
			printf("QR Code is Query\t");
			break; 

		case 1:
			printf("QR Code is Answer\t");
			break;
	}

	//printf("%s%18s\t%d\t%18s\t%d\t%s\n",timer,inet_ntoa(ipc->ip_src),ntohs(udphdr->source),
	//inet_ntoa(ipc->ip_dst),ntohs(udphdr->dest));
}







I'm working on a DNS resolver in C++, constructing the DNS header is giving me problems. From what I've 
been able to gather, the header can be constructed through a struct.

typedef struct {
  unsigned short id;

  unsigned char qr :1; // 0 query, 1 response
  unsigned char opcode :4; // 0 standard query
  unsigned char aa :1; // authoritive answer
  unsigned char tc :1; // truncated message
  unsigned char rd :1; // recursion desired

  unsigned char ra :1; // recursion available
  unsigned char z :3; // reserved
  unsigned char rcode :4;  // response code

  unsigned q_count :16; // number of question entries
  unsigned ans_count :16; // number of answer entries
  unsigned auth_count :16; // number of authority entries
  unsigned add_count :16; // number of resource entries
} HEADER;

typedef union {
  HEADER header;
  unsigned char packet_data[1024];
} DNS_PACKET;

I set the header values, place the header in DNS_PACKET, cast as (void *) and send the packet using 
sendto().

Viewing one of the sent packets in Wireshark shows that the bits are not being set in the correct
locations. For example I set q_count to 1, but Wireshark displays the packet with 256 questions.

In all the documentation I've read, this appears to be a valid route to constructing a packet. Am I going 
about this incorrectly? Is there a better method to construct a packet?


=========================================================================

 	
I'm trying to build a DNS request with

 libnet_build_dnsv4(
 u_int16_t h_len, 
 u_int16_t id, 
 u_int16_t flags,
 u_int16_t num_q, 
 u_int16_t num_anws_rr, 
 u_int16_t num_auth_rr,
 u_int16_t num_addi_rr, 
 u_int8_t *payload, 
 u_int32_t payload_s, 
 libnet_t *l,
 libnet_ptag_t ptag) 

but I can not figure out how to build the payload/query of the DNS packet. So far I got this:

 char query[1024];
 u_short payload_s;

 payload_s = snprintf(query, sizeof(query),
 "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
 0x02, 0x36, 0x32, 0x01,0x31, 0x03, 0x31, 0x36, 0x38, 0x03, 0x31, 0x39,
 0x32, 0x07, 0x69, 0x6e, 0x2d, 0x61, 0x64, 0x64, 0x72, 0x04, 0x70, 0x61,
 0x00, 0x00, 0x0c, 0x00, 0x01);

Which should build the query 62.1.168.192.in-addr.arpa: type PTR, class IN but in wireshark it displays
Malformed packet: DNS?? Is there an easier/working way to build the query?

SOLVED I used res_querydomain instead works perfectly fine!



=====================================================================


