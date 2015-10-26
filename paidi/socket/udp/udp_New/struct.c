#include <stdio.h>

int main()
{
char buff[1024];

struct header
{
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
};
struct header HEADER;

sprintf(buff,"short id-->%u%c",HEADER.id,HEADER.qr);

//sprinf(buff,"%u%c%c%c%c%c%c%c%c%c%c%u%u%u%u",HEADER.id,HEADER.qr,HEADER.opcode,HEADER.aa,HEADER.tc,HEADER.rd,HEADER.ra,HEADER.z,HEADER.rcode,HEADER.q_count,HEADER.ans_count,HEADER.auth_count,HEADER.add_count);

}

