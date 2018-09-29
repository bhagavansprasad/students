#include <stdio.h>
#include <errno.h>
#include "struct_rply.h"
#include "struct_req.h"
void tcp_server_init();
void linked_list_init();
void close_socket();
void server_read_data(struct final *c_req);
//void rpcs_recv_req(struct final *c_req, struct S_final *s_rply);
void rpcs_recv_req(struct final *c_req);

int main()
{
	int c = 0;
	struct final c_req;
	struct S_final s_rply;
	tcp_server_init();
	linked_list_init();
	while(1)
	{
		server_read_data(&c_req);
		rpcs_recv_req(&c_req);
		if( c_req.op == 5)
			c++;
		if(c == 2)
			break;
	}
	close_socket();
	return 0;
}
#if 0 
fd1 = aopen ("t.txt",O_RDONLY,0);
if(fd1 == -1)
{
	printf("fd1 open unsuccessfull\n");
	printf("error no : %d\n",errno);
	perror("error is: ");
}
fd2 = aopen ("r.txt",O_CREAT|O_RDWR,0777);
if(fd2 == -1)
	{
		printf("fd2 open unsuccessfull\n");
		printf("error no : %d\n",errno);
		perror("error is: \n");
	}
	//while(1)
	//{
		rval = aread(fd1,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
		wval = awrite(fd2,buff,rval);
		lval = alseek(fd1,-10l,2);
		rval = aread(fd1,buff,len);
		buff[rval]='\0';
		printf("%s\n",buff);
		wval = awrite(fd2,buff,rval);
	//	if(rval < len)
	//		break;

	//}
	aclose(fd1);
	aclose(fd2);
}
#endif
