#include<stdio.h>
//#include"server_accept.h"
#include"server_structer.h"
#include"structer.h"

void server_accept();                         /*proto tyep for server_acept*/
int server_read( struct data *);              /*proto tyep for server_read*/      
int server_write( struct server *);            /*proto tyep for server_write*/
int rpcs_fop( struct data *, struct server *);  /*proto tyep for srpcs_fop*/

struct data p;
struct server s;

main()
{
	server_accept();
	while(1)
	{
		server_read(&p);
		rpcs_fop(&p, &s);
		server_write(&s);
	}
}
