#include<stdio.h>
#include"struct.h"
#include"strc.h"
void server_recev();
int server_read(struct ch *);
int rpcs_fop(struct ch *,struct server *);
int server_write(struct server *);
struct ch q;
struct server y;
main()
{
	int count=0;
	server_recev();
	while(1)
	{
		server_read(&q);
		rpcs_fop(&q,&y);
		server_write(&y);
		if(q.flag==4)
		{
			count++;
			if(count==2)
				break;
		}
	}
}
